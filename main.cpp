//Simple Huffman tree example
#include "./globals.h"
#include "./huffman.h"

int main(int, char**) {
  string_t data = "";
  if (!Globals::read_file("./Spinoza_Ethics", data)) {
    Globals::errorExit("Could not read file.");
  }
  std::cout << "File Size pre-compression:" << data.length() << std::endl;

  Huffman h;
  string_t data_comp = "";
  if (!h.compress(data, data_comp)) {
    Globals::errorExit("Compression function failed with error.");
  }
  std::cout << "File size post-compression:" << data_comp.length() << std::endl;

  return 0;
}
