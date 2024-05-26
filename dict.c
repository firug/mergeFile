#include <stdio.h>
#include "dict.h"

void initDictionary(struct Node *dictionary) {
  char letter = 'a';

  for (int i = 0; letter <= 'z'; letter++) {
    dictionary[i].letter = letter;
    dictionary[i].counter = 0;
    i++;
  }
}

void fillDictionary(struct Node *dictionary) {
  char *filename = "example.txt";

  FILE *fp = fopen(filename, "r");

  if (fp) {
    char c;

    while ((c = fgetc(fp)) != EOF) {
      dictionary[c - 'a'].counter++;
    }

    fclose(fp);
  }
}

void SortDictionary(struct Node *dictionary) {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25 - i; j++) {
      if (dictionary[j].counter < dictionary[j + 1].counter) {
        SwapNodes(&dictionary[j], &dictionary[j + 1]); 
      }
    }
  }
}

void SwapNodes(struct Node *A, struct Node *B) {
  struct Node temp = *A;
  *A = *B;
  *B = temp;
}

void printDictionary(struct Node *dictionary) {
  for (size_t i = 0; i < 26; i++) {
    printf("%c | %d\n", dictionary[i].letter, dictionary[i].counter);
  }
}
