# x86-tso-demonstration

Imagine a program with two threads executing the following.
`x` and `y` are shared variables.

```text
            x = 0;
            y = 0;
Thread 1:           Thread 2:
x = 1;              y = 1;
r = y;              s = x;
```

Obvious possible results, depending on the interleaving of the threads, are:  
r = 0, s = 1  
r = 1, s = 0  
r = 1, s = 1  

But what about r = 0, s = 0?
Intuitively, this should not be possible. But as this program shows, it is. At least one some processor architectures, like x86.

An x86 processor core remembers what is to be written to memory in a so-called write buffer. And this will be written at some point (flushed) but until then the program can continue to run. So it is faster. But leads however to such strange things.

More information: <https://en.wikipedia.org/wiki/Processor_consistency>
