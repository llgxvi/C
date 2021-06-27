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
}
