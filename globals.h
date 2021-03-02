#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdlib>
#include <math.h>

class HNode;
class Huffman;

typedef std::string string_t;
typedef uint_fast32_t fui32_t;
typedef int_fast32_t fi32_t;

class Globals {
public:
  static int dct(std::vector<float> in, std::vector<float> out) {
    if(in.size()<3) {
      return 1;
    }
    float in_0 = in[0];
    float in_N = in[in.size()-1];
    for(auto f_in : in) {
      float f_out = 0.5 * (in_0 + powf(-1,2));
    }
    return 0;
  }

  static bool read_file(const string_t& file, string_t& out_str) {
    std::fstream fs;
    fs.open(file.c_str(), std::ios::in | std::ios::binary);
    if (!fs.good()) {
      fs.close();
      return false;
    }
    fs.seekg(0, std::ios::end);
    size_t siz = (size_t)fs.tellg();

    char* b = new char[siz + 1];
    b[siz] = 0;

    fs.seekg(0, std::ios::beg);
    fs.read(b, siz);
    fs.close();

    out_str = b;
    delete[] b;
    return true;
  }
  static void errorExit(const string_t st) {
    std::cout << st << std::endl;
    exit(1);
  }
};