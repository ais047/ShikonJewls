#include "base64.h"
#include <iostream>
#include <fstream>

int main() {
  const std::string s =
    "René Nyffenegger\n"
    "http://www.renenyffenegger.ch\n"
    "passion for data\n";

  std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
  std::string decoded = base64_decode(encoded);

  std::cout << "encoded: " << std::endl << encoded << std::endl << std::endl;
  std::cout << "decoded: " << std::endl << decoded << std::endl;

  std::ofstream encodefile;
  encodefile.open ("encoded.txt");
  encodefile << encoded + "\n";
  encodefile.close();

  // Test all possibilites of fill bytes (none, one =, two ==)
  // References calculated with: https://www.base64encode.org/

  std::string rest0_original = "abc";
  std::string rest0_reference = "YWJj";

  std::string rest0_encoded = base64_encode(reinterpret_cast<const unsigned char*>(rest0_original.c_str()),
    rest0_original.length());
  std::string rest0_decoded = base64_decode(rest0_encoded);

  std::cout << "encoded:   " << rest0_encoded << std::endl;
  std::cout << "reference: " << rest0_reference << std::endl;
  std::cout << "decoded:   " << rest0_decoded << std::endl << std::endl;

  return 0;
}

