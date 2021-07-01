Platform
```
Ubuntu 20.04.1 LTS
GNU/Linux 5.4.0-47-generic x86_64
```

static.c
```
#include <stdio.h>

int natural_generator()
{
   int a = 1;
   static int b = -1;
   b += 1;
   return a + b;
}

int main()
{
  printf("%d\n", natural_generator());
  printf("%d\n", natural_generator());
  printf("%d\n", natural_generator());

  return 0;
}
```

```
CFLAGS="-g -O0" make static
./static
gdb static

(gdb) break natural_generator
(gdb) run
(gdb) next
(gdb) next
(gdb) display/i $pc
(gdb) next
(gdb) x $rip + 0x2eb2
(gdb) disassemble
```

Dump of assembler code for function  natural_generator:
```
movl   $0x1,-0x4(%rbp)   // 1
mov    0x2eb2(%rip),%eax // 2
add    $0x1,%eax         // 3
mov    %eax,0x2ea9(%rip) // 4
mov    0x2ea3(%rip),%edx // 5
mov    -0x4(%rbp),%eax   // 6
add    %edx,%eax         // 7
```

```
1. rbp-4 = 1         // a = 1
2. eax = rip(0x2eb2) // static b = -1
3. eax = 1 + eax     // b += 1
4. rip(0x2ea9) = eax // store new val of b
5. edx = rip(0x2ea3) // b
6. eax = rbp-4       // a
7. eax = edx + eax   // return a + b
```

```
// static b

rip(0x2eb2) // retrieve
rip(0x2ea9) // store
rip(0x2ea3) // retrieve
```
