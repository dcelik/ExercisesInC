## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

> Dynamic types are very common in interpreted languages but very rare in compiled languages.

2) Name two advantages of static typing over dynamic typing.

> Static typing saves time for run-time type checking and also requires less space to save dynamic variable lists.

3) Give an example of a static semantic error.

> int array[1.5] would be a static semantic error since its a logical error due to the static type check failing.

4) What are two reasons you might want to turn off code optimization?

> Code optimization can hide bugs in your code and it can take much longer to compile.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

> gcc -S generates the assembly code, which changes from computer to computer as the assembler is specific to machine CPU.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

> Variable names will usually be grabbed by the compiler's syntax handler while a function name can be grabbed by the linker instead, generating a different error message.

7) What is a segmentation fault?

> When the code tries to read or write an incorrect location in memory.


## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

> A real world example of virtualization is cellphone service. It seems that we are connected wirelessly to every single other phone whlie instead we are connected via routing of many different cell towers and cables. This abstracts away the need to select a tower and the cables and instead make it seem like everybody is connected.

2) What is the difference between a program and a process?

> A process is what runs a program and keeps track of the instructions and memory locations. The program defines what is to be done instead.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

> The primary purpose of process abstraction is to make it easier for programmers to write code without having to think about how it works under the hood. The illusion it creates is of a single dedicated processor running our code, when in reality there are many process and interruptions that are being abstracted away.

4) What is the kernel?

> The kernel is the part of the operating system responsible for core operations. These include thread creation.

5) What is a daemon?

> A daemon is an OS process designed to run in the background and provide some services such as process creation or system logging.
 

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

> 2^5 = 32 and 2^6 = 64 so we would require 5 bits to specify a Georgian letter

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

> For 32 bits, we would be able to represent 2^32 characters, so 4,294,967,296 different characters (without an encoding scheme) could be represented.

3) What is the difference between "memory" and "storage" as defined in Think OS?

> Memory is used to describe the volatile RAM while storage is used to define read-write memory such as HDD's and SDD's. 

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

> GiB is the binary unit for gibibyte while a GB is the decimal unit gigabyte: GiB is 1024^3 and GB is 1000^3.  GiB is 6.87% larger than GB.

5) How does the virtual memory system help isolate processes from each other?

> Each process manages its own memory (virtual) as if it is the only thing using it. So each process will write to its own virtual addresses which the OS can map to physical addresses. This allows the OS to distinguish memory between processes without the processes needing to do this manually.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

> I think this is done such that they can grow independently with low risk of collision and also prevents the OS from having to impose a hard limit on each one. If they grew from the same side, the heap or stack would have to have a hard start location as to not cause errors.

7) What Python data structure would you use to represent a sparse array?

> I would use a dictionary to represent a sparse array.

8) What is a context switch?

> A context switch is when a process is interrupted, the state is saved and then another process is started up instead of it.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.

> Results:
>  main is 0x40057d
>  global is 0x60104c
>  local is 0x7fffffffde94
>  p is 0x602010
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

> Results:

>  main is 0x40057d

>  global is 0x60104c

>  local is 0x7fffffffde8c

>  new_malloc is 0x602010

>  p is 0x6020a0

> The heap did indead grow, towards larger addresses: 0x602010 -> 0x6020a0.

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

> Results:

>  main is 0x4005a4

>  global is 0x60104c

>  local is 0x7fffffffde8c

>  new_malloc is 0x602010

>  p is 0x6020a0

>  to_print is 0x7fffffffde6c

> The fact that to_print is located on the stack along with the growith seen in main indicates that the stack has indeed grown down: 0x7fffffffde8c -> 0x7fffffffde6c.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

> I choose the number 13. I allocate them using malloc(13) at the beginning and end of main.

> Results:

>  main is 0x4005a4

>  global is 0x60104c

>  local is 0x7fffffffde7c

>  new_malloc is 0x602030

>  p is 0x6020c0

>  to_print is 0x7fffffffde5c

>  chunk1 is 0x602010

>  chunk2 is 0x602150

> The space between them is 0x602150 - 0x602010 = 0x140, which is 320 in decimal.


## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

> File systems abstract away the location and ordering of files and instead provide just a mapping of keys that allow us to find the contents as values. It also maps these locations (which represent streams of bytes) to file names that the sees. Logically file systems are just a collection of bytes that represents a file while the implementation actually collects the blocks as the minimum size rather than the bytes.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

> I imagine that OpenFileTableEntry contains the location that it is pulling data from (the file), the next byte to read (cursor location), and the position in memory in which it is loading the file (RAM).

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

> Operating systems deal with the relative slow down in performance by switching to another process while waiting for the data to be retrieved from disk. Other ways of dealing with this slowdown include transfering multiple blocks at the same time (prefetching) and saving the block to the cache in order to modify it several times without reloading (buffering/caching).

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

> The file may have only been written to the buffer and not yet been written to the persistent storage yet. Since this difference is abstracted away, the file being printed does not necessarily mean the file has been written.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

> FAT does not have a max size while inode does, in addition the FAT table stores the file info in a single area rather than loading into every file's location. This is critical because the advantage inodes have over FAT is that that data is stored with the file rather than a central location. This back and forth gives inode a slight disadvantage when moving or enlarging files, since more info has to be moved and carried around, rather than just changing the pointer in the FAT table.

6) What is overhead?  What is fragmentation?

> Overhead is the extra space used by the allocator that cannot be used for data and also includes any performance hits that is taken due to this extra data usage. Fragmentation is when some blocks are used and some are unused. This makes it such that you cannot fill this space with file blocks that exceed the empty area.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

> The everything is a file is useful since it allows for processes to read and write very easily and operate with each other using a single API, that of a stream of bytes. This can be a bad idea because it provides a way to move strings and other objects into files that could be used malicioulsy to modify parts of the file system that should not be changed.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

> The unsigned 8 bit number is 128, which is 1111 1111, converting this to a 16-bit number and applying sign extension would lead to 1111 1111 1111 1111. This makes it seem like its a negative number when it is actually just a positive number that has been incorrectly sign extended due to the 16-bit conversion.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

> ((1100^1111) & 0001) << 1 -> (0011 & 0001) << 1 -> 0010 << 1 -> 1 0100; the 1 is the sign bit

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

> This is so that it can be compared more easily. Instead of having to use two's complement or a sign bit, we can bias it such that the value is "unsigned". This makes it much easier to compare.

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

> 1 1101 -> Sign: 1 ; Exponent: 130 ; Coef: 0x500000 -> 1 10000010 101 0000 0000 0000 0000 0000
 
> If this was interpreted as an integer, it would be equal to 3243245568. 

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

> See the file string_upper.c . It contains the un-optimized version of the code that reads a single character at a time and converts it to uppercase if it is a lowercase letter, otherwise it does not modify the character.


## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

> When a new program is written, the program will jump to another location in the program.

2) What is the fundamental problem caches are meant to solve?

> Caches are meant to solve the speed disparity between CPU clock cycles and data/memory reading/writing.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

> 5ns for 50%, 1.9ns for 90%.

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

> Some other examples of improved locality might be seperating commonly used functions into distinct methods. This allows the data to be seperated in the stack and makes it easier for caching. Other examples would be using data types that fit in the cache, such as restricting arrays to be within the cache size.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

> No. Locality is not the only part required to be cache aware. In order to be cache aware, we have to modify the code to take into acocunt the size of the cache, the block size and other hardware features.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

> Based on Intel chips with varying levels of cache, I estimate that the cache will cost around $3-4K per GB.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

> At the bottom of the hierarchy we have more time to make decisions and our decisions can make large impacts in speed.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

> Thrashing could be avoided by not allowing users to open more processes that could page data, or blocks processes until paging has slowed down.

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?

I can infer from the data that our block size is around 1024B and a cache size of 838860B.

## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

> It's most basic task is to handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

> The registers and the current program counter are saved.

3) What is the difference between an interrupt and a context switch?

> On an interupt, only the registers are saved and then the program is restored and continued. In a context switch, the memory is cleared to make way for a new program to run and save data.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

> An even that might cause a process to move from the blocked to the ready state would be an IO disk read to return data.

5) Why might a scheduler want to give higher priority to an I/O bound process?

> A scheduler would want to give higher priority since the IO part is going to be the slowest portion of the call. In addition, the CPU can do other operations while the IO bound process is blocked waiting for a response.

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)

> Cook 8 on one side for 5 min. Remove 4 of the half cooked, flip the other 4, put 4 fresh on and cook for another 5 min. Take the completely cooked ones off and put the half cooked back on the ohter side. Cook for 5 more min and be done.


## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

> So that they can call functions and local variables wihtout interfering with each other.

2) What does the `gcc flag -lpthread` do?

> It compiles the file with the Pthread library linked in GCC.

3) What does the argument of `pthread_exit` do?

> It allows the passing of a value to the thread that joined this thread.

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

> Any thread can join any other thread, so this is fine.  

5) What goes wrong if several threads try to increment a shared integer at the same time?

> Synchronization errors can occur where another thread can increment the previous value at the same time another thread attempts to increment. THis can result in one of the increments being lost.

6) What does it mean to "lock a mutex"?

> Locking a mtuex prevents other threads from continuing execution until they can obtain the unlocked mutex.

## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

> A thread safe data structure means the multiple threads can access the data structure at the same time.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

> In the circular buffer, we require a start element that tells us when the buffer is "empty".

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

> Thread 1 pushes the value 2 to the Queue. Thread 2 pops the 2 and puts in 3. Thread 3 pops thinking that the top value in the queue is from Thread 1.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

> If it does not unlock the mutex, no other thread would be able to obtain the mutex.

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

> We think it is probably true, as something might have changed between the condition variable changing and us waking up.

6) What happens if you signal a condition variable when there are no waiting threads?

> If there are no waiting threads, the signal has no effect.

7) Do you have to lock the mutex to signal a condition variable?

> Yes, you must lock the mutex, signal the condition variable and then unlock the mutex.

8) Does the condition have to be true when you signal a condition variable?

> Yes, you must signal the condition variable.
 
## Chapter 11


### Semaphores in C
