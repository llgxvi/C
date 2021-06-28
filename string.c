#include <stdio.h>
#include <string.h> // strlen

#define pr printf

void main()
{
  // STR is defined as an ARR of CHARs
  // DIFF between CHAR ARR and STR is the trailing '\0'

  char s[] = "geeks";     // '\0' is implied
  pr("%ld\n", sizeof(s)); // 6
  pr("%ld\n", strlen(s)); // 5
  puts(s);                // geeks

  // ZERO BYTE as STR terminator
  // bin 0000 0000
  // dec 0
  // hex 00

  // below are the same
  s[3] = 0;    // NUM 0 is ASCII for NULL
  s[3] = '\0'; // notice the SINGLE quote

  pr("%ld\n", sizeof(s)); // 6
  pr("%ld\n", strlen(s)); // 3
  puts(s);                // gee

  // '\0' IS the NULL character
  // str len is found by searching for
  // the first NULL byte
  // https://stackoverflow.com/a/14462305
  // https://stackoverflow.com/a/14461757
  // https://en.wikipedia.org/wiki/Null-terminated_string
  // https://en.wikipedia.org/wiki/Null_character

  // char s[] = "geeks\0geeks\0";
  // sizeof    ARR s is 13 (not 12)
  // strlen of STR s is 5
  // STR can't store null

  // https://stackoverflow.com/a/8732449

  const char *s1 = "xxx";
  s1 = "geeks";
  pr("%c %c\n", *s1, *(s1++)); // e g ❓

  char s2[] = "geeks";
  pr("%c %c\n", *s2, *(s2+1)); // g e

  // s++
  // https://stackoverflow.com/a/3364548
  // https://stackoverflow.com/a/15028431
  // https://www.geeksforgeeks.org/execution-printf-operators/
  // https://www.programiz.com/article/increment-decrement-operator-difference-prefix-postfix
  // https://www.geeksforgeeks.org/whats-difference-between-char-s-and-char-s-in-c/

  // Strings (and why there is no such thing)
  // https://boredzo.org/pointers/
}
