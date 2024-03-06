# Library-C-GarbageCollector
Sample C Garbage Collector

---

If you want the fg_cleanup function to be automaticly executed at the end of your program, write
```c
#define FGC_SELF_CLEAN
```
**BEFORE** including `f_garbage_collector.h`.

If you are not using GNU, you will get an error.