#include <stdlib.h>
#include <stdio.h>

int wordCount(const char* filename) {
  // Declare file pointer
  FILE* fp;
  char ch;

  // Open the file in read mode.
  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error in opening file.\n");
    return(EXIT_FAILURE);
  }

  int count = 0;
  char prevChar;

  while ((ch = getc(fp)) != EOF) {
    if (ch != ' ' && count == 0) {
      count++;
    } else if (ch == ' ' && prevChar != ' ' && prevChar != '\n') {
        count++;
    }
    prevChar = ch;
  }

  // Close the file.
  fclose(fp);

  printf("Total words: %d\n", count);

  return count;
}
