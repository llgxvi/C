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

> Doesn't make a huge difference, but it's worth noting that accessing array elements by pointer (I.e. *arr = x; arr++) is slightly faster than by subscription (I.e. arr[]) in loops, even though it can look a lot more confusing. Check out the assembly! Without optimization there's no contest, but even with -O3 or -O4 (using GCC) subscription requires a few slower computations

> It is a lie that C can not do arrays, or even your lie #4 that you can't pass by value. If you want to have an array type, than make it so. pass arrays around (by value, or copying, etc...). Hopefully we all know that generally isn't a good idea, but sometimes, especially for small arrays it can be... All you have to do is define it as such.
`typedef struct { int arr[5]; } array5;`

> I've been asked why the index doesn't matter in a function prototype, and you explain that very well. It doesn't matter if you use any of these, because the argument decays to a pointer-to-int (the first element in the array:
```
int arr[ ]
int arr[5]
int * arr
```
---

http://patshaughnessy.net/2017/1/20/pointers-in-c-and-x86-assembly-language
