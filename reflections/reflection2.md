###Sprint Reflection

During our retrospective last spring, the kaizen was to better share the information and knowledge we obtained through our independent exploit work. I mainly contributed by researching and contributing video and write-up sources for how the basic dirtyC0W exploit works. Sawyer and Chris worked through the Nebula exercises independently and provided the team with small summaries of the basic technique expected in each challenge. They also took a crack at the stack protostar exercises and wrote up the solutions that acted as a refresher for the basic exploits we had done earlier. 

This sprint, we identified our kaizen to be keeping velocity. With the snow day and holidays, our inclass time has been more limited than expected and did not provide our usual time for keeping each other accountable for deadlines and assigning new tasks. As such we essentially lost days of productivity.

For me, I had a blast working on the dirtyC0W exploit and find it to be a very interesting as both an exploit I don't have too much experience with (race condition) and the way it works on even relatively modern operating systems (Ubuntu Kernels). In addition, working through the exploits-exercises website has given me a much better understanding of UNIX vulnerabilities that I had otherwise not thought of exploring. I hope to continue along this path and use some of the more difficult Protostar exercises as a larger part of my learning experience. Another benefit has been my reintroduction to 'gdb' and its insane usefulness in debugging code. While the majority of the time has been spent gathering buffer addresses, return addresses or function addresses using the dissassemble feature, it has been a good learning experience.

###Headfirst C Excercises

[Excercise 3](../exercises/ex03/)

[Excercise 4](../exercises/ex04/)

#Think OS Reading Questions

I completed the questions for Chapters 4 and 5. I wrote my answers inline in the ThinkOS.md file linked below:

[ThinkOS Reading Questions](../reading_questions/thinkos.md)

###Exam Question

Q: Bob has a program with a directory structure like so:

```
Directory
  |---> main.c
  |---> helper.c
  |---> helper.h
  |---> Makefile
```
main.c and helper.c have a 
```
#include "helper.h"
```
at the beginning of their files.

The Makefile for his C code  looks like so:
```
main: main.c helper.c
    gcc -g main.c helper.c helper.h -output-file-name main -turn-all-warnings-on
```

1. Find and fix the errors in Bob's makefile.

2. After fixing his errors, Bob finds that whenever he changes helper.h it doesn't recompile his main file. Modify the makefile to use intermediary gcc calls to fix Bob's issues (hint: gcc -c will compile but not link a file!). Your final directory should look like so:

```
Directory
  |---> main.c
  |---> main.o
  |---> helper.c
  |---> helper.h
  |---> helper.o
  |---> main
  |---> Makefile
``` 

A: This question checks to see how much students remember about very common gcc flags and how Makefiles are structured:

1. "-output-file-name" should be "-o", and "-all-warnings-on" should be "-Wall". The header file also does not need to be in the call. Additionally the -g flag could be dropped since it just adds debugging symbols. (BONUS)
2. The issue here is that the make file does not check to see if helper.h has been changed when recompiling. One fix could be to add it to the main: header as so:

```
main: main.c helper.c helper.h
    gcc -g main.c helper.c helper.h -output-file-name main -turn-all-warnings-on
```

However, the question asks for them to show that they understand that compiling and linking are different tasks. Creating a seperate header for each intermediary object file should do the trick:

```
main: main.o helper.o helper.h
  gcc main.o helper.o -o main -Wall
  
helper.o: helper.c helper.h
	gcc -c helper.c -Wall

main.o: main.c helper.o
	gcc -c main.c -Wall
```

Since ```make``` calls just the first line, we place our object files and our helper.h to make sure we don't miss any changes that need to be compiled. By making our main.o and helper.o seperately, we do not have to recompile helper.o if we change main.c.
