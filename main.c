#include "dict.h"

int main() {

  struct Node dictionary[26];
  
  initDictionary(dictionary);
  fillDictionary(dictionary);
  SortDictionary(dictionary);
  printDictionary(dictionary);
}
