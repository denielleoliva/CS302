What is the program?

This program establishes basic stack functionality. This includes stack
manipulation functionality like pushing to a stack and popping values from the
a stack. Using these functions, the program utilizes them in two different
practices. One being a postfix evalutation process. The other a balanced 
delimiter check.

The postfix evaluation portion of the project evaluates a postfix expression
and return the correct result. This section uses the linked stack 
implementation in order to find the correct result of a postfix expression.

For example, the postfix expression 34+52/* should evaluate to 17.5.

Test cases for this program are in the attached logs.

The delimiters portion of this project checks if the delimiters in a given 
string has a balanced and legal amount of delimiters. This means that there are
there are only pairs of delimiters and none are left open.

For example, a balanced delimiter can be "()" or "{}[()]."

Test cases for this program are in the attached logs.

Development:

Initially I was unclear as to what I needed to get done and fill out with 
respect to the coding package provided. When I figured out that I needed to 
create the implementation for StackArray.h and StackLinked.h, I went on to 
create the cpp files that would be attached to the headers.

When making the implementation for the two methods of stack functionality, I
figured out that I would want to be able to keep track of how many items were 
in my stacks. This was easy in the array based implementation, but I was unable
to fashion a way to do in the linked list based implementation. I was also 
unable to figure out why the stack for the array based implementation would
display backwards. When the pop function is called, the 0th element would not 
be the one popped but the highest index would be.

Another problem that I came across was how to use the operations that I would be
reading from a string. I wasn't sure how to convert a char data type to one that 
would do math so I made a switch statement that would just do the specific 
operations when a operation character was encountered in the string. 

I also realized that I needed to account for white space when reading in the a
postfix expression. Instead of using getline(), I ended up using another stack
for white space. This white space stack was purely meant to ignore whitespaces.

