#include "./huffman.h"

HNode::HNode(const string_t& sym) {
  _sym = sym;
}
string_t HNode::print() {
  fui32_t iHeight = height();
/*
               ___________a___________             
              |                       |               
         _____b_____             _____c_____          
        |           |           |           |        
      __d__       __e__       __f__       __g__      
     |     |     |     |     |     |     |     |      
    _h_   _i_   _j_   _k_   _l_   _m_   _n_   _o_    
   |   | |   | |   | |   | |   | |   | |   | |   |    
   p   q r   s t   u v   w x   y z   1 2   3 4   5
  
  You need to know how wide the tree will be at each level.
  widest row in names and spacing will dictate the minimum width of the tree.
  variable length names.
  
*/
  int maxw = iHeight * 4 + 1;
  std::vector<HNode*> vec;
  std::vector<HNode*> vec2;
  vec.push_back(this);
  while (vec.size()) {
    for (auto n : vec) {
      //op
      if (n->_left) {
        vec2.push_back(n->_left);
      }
      if (n->_right) {
        vec2.push_back(n->_right);
      }
    }
    vec = vec2;
    vec2.clear();
  }
}
fui32_t HNode::height() {
  fui32_t n = 0;
  std::function<void(const HNode*, fui32_t&, fui32_t)> search;
  search = [&](const HNode* parent, fui32_t& max_n, fui32_t n) {
    if (n > max_n) {
      max_n = n;
    }
    if (parent->_left) {
      search(parent->_left, max_n, n + 1);
    }
    else if (parent->_right) {
      search(parent->_right, max_n, n + 1);
    }
  };

  search(this, n, 0);

  return n;
}
void Huffman::compute_weights() {
  //Compute the initial symbol table with corresponding frequencies
  for (auto c : _data) {
    uint8_t c_c = static_cast<uint8_t>(c);
    auto it = _symbols.find(c_c);
    if (it == _symbols.end()) {
      _symbols.insert(std::make_pair(c_c,
                                     new HNode(string_t((char*)&c_c, (char*)&c_c + 1))));
      it = _symbols.find(c_c);
    }
    it->second->_weight++;
  }
}
void Huffman::combine_trees() {
  std::vector<HNode*> nodes;
  for (auto it : _symbols) {
    nodes.push_back(it.second);
  }
#define SORT_NODES(x) std::sort(x.begin(), x.end(), [](HNode* a, HNode* b) { return a > b; })

  SORT_NODES(nodes);

  while (nodes.size() > 1) {
    HNode* a = nodes[0];
    HNode* b = nodes[1];
    HNode* p = nullptr;

    if (a->_weight <= b->_weight) {
      p = new HNode(a->_sym + b->_sym);
      p->_left = a;
      p->_right = a;
    }
    else {
      p = new HNode(b->_sym + a->_sym);
      p->_left = b;
      p->_right = a;
    }

    p->_weight = p->_left->_weight + p->_right->_weight;
    nodes.erase(nodes.begin() + 0, nodes.begin() + 2);
    nodes.push_back(p);

    SORT_NODES(nodes);
  }

  if (nodes.size() == 1) {
    nodes[0]->print();
  }
}

void Huffman::write_file() {

}