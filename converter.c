// Lucas Yong
/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; ++i) {
    char *line = lines[i];
    quote_t num = 0;
    // While the next character (digit) is not empty, take `num` and multiply it (bitwise) by 10 (to make room for the next digit)
    // Add the next digit, which is obtained by subtracting the ASCII code of that character (digit) with the ASCII code for '0'
    // This way, the character '0' gives the number 0, '1' gives 1, and so on
    while (*line != '\0') {
        num = (num<<3) + (num <<1) + (*line - '0');
        ++line;
    }
    nums[i] = num;
  }
}