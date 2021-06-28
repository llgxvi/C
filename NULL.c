#include <stdio.h>

#define pr printf

void main()
{
  char a[] = "geeks";

  // if (NULL==0)    // 0x7ffdaec02a22
  // if ('\0'==0)    // 0x7ffdaec02a22
  // if (NULL=='\0') // warning: comparison between pointer and zero character constant
    pr("%p\n", a);

}
