https://stackoverflow.com/a/4955297

> It's usually good enough - unless you're programming assembly - to envisage a pointer containing a numeric memory address, with 1 referring to the second byte in the process's memory, 2 the third, 3 the fourth and so on....

> What happened to 0 and the first byte? 

> Further, when you assign 0, NULL and nullptr to a pointer the bits in the pointer are not necessarily all reset: the pointer may not contain "0" at the hardware level, or refer to address 0 in your virtual address space. The compiler is allowed to store something else there if it has reason to, but whatever it does - if you come along and compare the pointer to 0, NULL, nullptr or another pointer that was assigned any of those, the comparison must work as expected. So, below the source code at the compiler level, "NULL" is potentially a bit "magical" in the C and C++ languages...

---

https://blog.feabhas.com/2016/12/a-convenient-untruth/

> When you write `arr[0]`
The compiler is re-writing your code as 
`*(arr + 0)`
array name, 
as an expression, 
yields a pointer; 

---

http://patshaughnessy.net/2017/1/20/pointers-in-c-and-x86-assembly-language
