### Stack frame in assembly

https://www.recurse.com/blog/7-understanding-c-by-learning-assembly

https://stackoverflow.com/questions/3699283/what-is-stack-frame-in-assembly/3700219#3700219

<pre>
rsp: stack pointer 
rbp: stack base pointer

instruction src, dest

routine f (a, b, c)
</pre>

```
push c
push b
push a
push ret addr of caller of f    // 1️⃣

// function prologue/preamble
push %rbp (of prev stack frame) // 2️⃣
mov  %rsp, %rbp

mov  $0x0, %eax (store ret val of f in eax)
movl $0x0,   -0x4(%rbp) ❓
movl $0xXXX, -0x8(%rbp) // local var
movl $0xXXX, -0xc(%rbp) // local var

// function epilogue
pop %rbp // restore 2️⃣ in rbp
retq     // ret to  1️⃣
```

```
[rbp + 0]  - return address
[rbp + 4]  - parameter a
[rbp + 8]  - parameter b
[rbp + 12] - parameter c
```

```
[rbp - 4] - local var
[rbp - 8] - local var
```

```
[rsp + 0] - local var
[rsp + 4] - local var
```
