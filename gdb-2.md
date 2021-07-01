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

```
// -s: display full content of section requested 
// -j: section name
objdump -s -j .data a.out 

a.out:     file format elf64-x86-64

Contents of section .data:
 4000 00000000 00000000 08400000 00000000  .........@......
 4010 ffffffff                             ....
```

```
// -S: Display source code intermixed
with disassembly
// -r: Print the relocation entries of the
file
objdump -Sr a.out

0000000000001149 <natural_generator>:
    1149:       f3 0f 1e fa             endbr64 
    114d:       55                      push   %rbp
    114e:       48 89 e5                mov    %rsp,%rbp
    1151:       c7 45 fc 01 00 00 00    movl   $0x1,-0x4(%rbp)
    1158:       8b 05 b2 2e 00 00       mov    0x2eb2(%rip),%eax        # 4010 <b.2316>
    115e:       83 c0 01                add    $0x1,%eax
    1161:       89 05 a9 2e 00 00       mov    %eax,0x2ea9(%rip)        # 4010 <b.2316>
    1167:       8b 15 a3 2e 00 00       mov    0x2ea3(%rip),%edx        # 4010 <b.2316>
    116d:       8b 45 fc                mov    -0x4(%rbp),%eax
    1170:       01 d0                   add    %edx,%eax
    1172:       5d                      pop    %rbp
    1173:       c3                      retq
```

```
Dump of assembler code for function natural_generator:
=> 0x0000555555555149 <+0>:     endbr64 
   0x000055555555514d <+4>:     push   %rbp
   0x000055555555514e <+5>:     mov    %rsp,%rbp
   0x0000555555555151 <+8>:     movl   $0x1,-0x4(%rbp)
   0x0000555555555158 <+15>:    mov    0x2eb2(%rip),%eax        # 0x555555558010 <b.2316>
   0x000055555555515e <+21>:    add    $0x1,%eax
   0x0000555555555161 <+24>:    mov    %eax,0x2ea9(%rip)        # 0x555555558010 <b.2316>
   0x0000555555555167 <+30>:    mov    0x2ea3(%rip),%edx        # 0x555555558010 <b.2316>
   0x000055555555516d <+36>:    mov    -0x4(%rbp),%eax
   0x0000555555555170 <+39>:    add    %edx,%eax
   0x0000555555555172 <+41>:    pop    %rbp
   0x0000555555555173 <+42>:    retq   
End of assembler dump.
```

### 0x555555558010 vs 4010
- https://stackoverflow.com/questions/60235105/why-does-memory-address-change-in-ubuntu-and-not-in-redhat
- https://en.wikipedia.org/wiki/Position-independent_code

