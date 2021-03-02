#include "./globals.h"

class Huffman {
public:
  bool compress(const string_t& data, string_t& out) {
    _data = data;
    compute_weights();
    combine_trees();
    write_file();
    return true;
  }

private:
  string_t _data = "";
  std::map<uint8_t, HNode*> _symbols;
  void compute_weights();
  void combine_trees();
  void write_file();
};
class HNode {
public:
  typedef fui32_t size_type;

  HNode* _left = nullptr;
  HNode* _right = nullptr;
  size_type _weight = 0;
  string_t _sym = "";

  HNode(const string_t& sym);
  fui32_t height();
  string_t print();
};
