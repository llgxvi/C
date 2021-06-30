Platform
```
Ubuntu 20.04.1 LTS 
GNU/Linux 5.4.0-47-generic x86_64
```

simple.c
```
int main()
{
    int a = 5;
    int b = a + 6;
    return 0;
}
```

```
CFLAGS="-g -O0" make simple
gdb simple
(gdb) break main
(gdb) run
(gdb) next 2
(gdb) disassemble
```

Dump of assembler code for function main:
```
endbr64

// 10
push   %rbp
mov    %rsp,%rbp

movl   $0x5,-0x8(%rbp) // 1
mov    -0x8(%rbp),%eax // 2
add    $0x6,%eax       // 3
mov    %eax,-0x4(%rbp) // 4
mov    $0x0,%eax       // 5

// 11
pop    %rbp
retq
```
   
10. function prologue 
11. function epilogue

```
// b: rbp
// addr: b-[displacement]

1. b-8 = 5       // a = 5
2. eax = b-8     // 
3. eax = 6 + eax // a + 6
4. b-4 = eax     // b = 
5. eax = 0       // return 0
```
