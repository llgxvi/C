#include <stdio.h>

#define pr printf

void main()
{
  char a[] = "geeks";
  // print the same addr, but diff types of addr
  pr("%p\n", a);    // 0x7ffd6d06ac22
  pr("%p\n", &a);   // 0x7ffd6d06ac22
  pr("%p\n", a+1);  // 0x7ffd6d06ac23 1️⃣
  pr("%p\n", &a+1); // 0x7ffd6d06ac28 6️⃣

  // warning: format ‘%d’ expects argument of
  // type ‘int’, but argument 2 has type ‘char *’ ⬅️
  // a points to the 1st ele 1️⃣
  // a + 1 results in addr increment of 1
  // pr("%d", a);

  // warning: format ‘%d’ expects argument of
  // type ‘int’, but argument 2 has type ‘char (*)[6]’ ⬅️
  // &a points to the whole arr 6️⃣
  // &a + 1 results in addr increment of 1 * 6
  // pr("%d", &a);

  // warning: comparison of distinct pointer types
  // lacks a cast
  // pr("%d\n", a==&a);

  pr("%d\n", a==&a[0]);    // 1
  pr("%d\n", (char*)a==a); // 1

  // warning: format ‘%d’ expects argument of
  // type ‘int’, but argument 2 has type ‘long int’
  // pr("%d\n", 0x7ffcbc5f5362);

  // pr("%d\n", (❓)a==&a);
  // pr("%d\n", (char*[6])a == &a);   // error: cast specifies array type
  // pr("%d\n", (char*[])a == &a);    // error: cast specifies array type
  // pr("%d\n", (char(*)[6])a == &a); // 1
  // pr("%d\n", (char(*)[])a == &a);  // 1

  // char*     - a pointer type (is actually the type of arr)
  // char*[]   - an array type
  // char(*)[] - a pointer type (is the type of &arr)

  // [] operator
  // https://stackoverflow.com/questions/19782111/does-the-bracket-operator-only-have-a-single-use
}
