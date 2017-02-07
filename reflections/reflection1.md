###Reflection 1

##Sprint Reflection

I think that our sprint went pertty well. We did a good job of setting deliverable goals for each class period and kept our Trello board updated appropriately. Unfortunately we had some trouble getting our deliverables done in a timely manner. While we did complete the tasks we had set out to complete by the end of the sprint, our internal deliverable deadlines were a bit shakey. In terms of our sprint review, I think our research into exploits (especially buffer overflows and the such) provided us with an alternative path of understanding the inner workings of the stack, compared to reading Head First C. At first our focus was on jumping into iOS exploits immediately but as we progressed we found that taking a step back and concentrating on finish foundational exercises (HeadFirst C, ThinkOS, simple C exploits) was a better use of our work time. Now that we have a better foundational grasp, we are moving towards working on more complicated C and Unix exploits while simultaneously preparing our working environment for iOS exploits.


##Head First C Exercises

I completed Exercises 1, 2, and 2.5. All of the supporting code and Markdown notes can be found at the links below:

[Exercise 1](../exercises/ex01/)

[Exercise 2](../exercises/ex02/)

[Exercise 2.5](../exercises/ex02.5/)

##Think OS Reading Questions

I completed the questions for Chapters 1,2 and 3. I wrote my answers inline in the ThinkOS.md file linked below:

[ThinkOS Reading Questions](../reading_questions/thinkos.md)

The changes to aspace.c in Chapter 3 can be found here:

[ThinkOS Reading Questions](../reading_questions/aspace/aspace.c)

##Exam Question and Solution

This question is designed to test basic knowlegde of compilation and some differences from interpreted languages. (ThinkOS Chapter 1)

Q: In which step of the compilation process does type checking occur. Hows does the timing of this check differ from interpreted languages such as Python. 

A: After preprocessing and parsing comes the static checking step in which the compiler checks to make sure that variables and values have the right type along with function calls being correct. In interpreted languages, this is done at runtime instead of compile time. 
