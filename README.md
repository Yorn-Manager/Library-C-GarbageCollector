# Library-C-GarbageCollector
Sample C Garbage Collector

---

If you want the fg_cleanup function to be automaticly executed at the end of your program, use
```c
#define FGC_SELF_CLEAN
```
**BEFORE** including `f_garbage_collector.h`.

If you are not using GNU, you will get an error.

If you call `fgc_cleanup` while running under valgrind (or if it's called automaticly using the above define), you will have a summary of the "usable" allocated data :

The garbage collector uses heap to store allocations references, so valgrind output will not represent the amount of heap you are manually using.
