# Welcome to \_printf! :pencil2:
|\_printf|
|----------------------------------|
|\_printf is the function for c language to make formatted prints. This document explains how printf works and how to design the right format specification for any occasion|
## How is it used?

```c
    #include "holberton.h"
    /**
    * Filename: main.c
    * main - Entry point
    *
    * Return: Always 0
    */
    int main(void)
    {
        /* Print strings */
        _printf("Hello %s\n", "World");
        /* Print integers */
        _printf("%d\n", 1024);
        /* Print a single char */
        _printf("%c\n", 'H');
        return (0);
    }
```
## How is it structured?

<img align="center" src="https://raw.githubusercontent.com/JuanDAC/printf/main/img/printf.jpg" alt="My structure project"/>

## NAME: PRINTF
This function receives a formatted string and concatenates and formats each of the attributes passed to the function to print each of these parse types for any specific result in any context.
## SYNOPSIS
 LIBRARY: #include "Holberton.h"
int _printf(const char *format, ...);
##
## DESCRIPTION
At the moment of entering the arguments in the function it goes to the lexical analysis **LEXER :** which is in charge of giving sense to the string and differentiating the percentages, from there it goes to the parse **PARSE:** it looks for the formats and differentiates them from the rest of the string and gives them sense, so it will tell to which group it belongs according to its format, for example if its format is string and it applies the format, then it goes to the evaluator **EVALUATOR:** This brings the function that handles the format, i.e. calls the handlers, i.e. brings the function that sets the format and now passes to the printf **PRINTF :** prints the burfer that was previously selected and finally clears the memory with **FREE:** clears the memory.
**Simple Print:**
Printf takes only one argument at a time in order to print, it is the basis of prinft one-at-a-time printing.
**Special character printing:**
backslash is used for printing a special character, which changes the meaning of the following character into a special one, to print quotes you need "double" to print "double", without backslash the characters have a special meaning with backslash it takes them for what they are.
**EXAMPLE:**
\ escape the next character
\\ print a backslash " start or end of string
 \" print a double quote
  ’ start or end a character constant
 \’ print a single quote
  % start a format specification
 \% print a percent sign
**Characters that are commonly printed:**
In the opposite case, characters that are commonly printed are taken and the backslash is added and converted to space characters:
**EXAMPLE:**
**\ a** audible alert (bell).
**\b** backspace.
**\f** form feed.
**\n** newline (linefeed).
**\r** carriage return.
**\t** tab.
**\v** vertical tab.
**FORMAT SPECIFICATIONS**
**The argument list**
When printf processes its arguments, it starts printing the characters it finds in the first argument one by one. When it finds a percentage, it knows that it has a format specification. It moves on to the next argument and uses its value, printing according to that format specification. It then prints again
one character at a time (from the first argument).
**Percentage**
Every format specification begins with a percent sign and ends with a letter.
and ends with a letter. The letters are chosen to have some mnemonic
some mnemonic meaning. Here is a partial list:
**EXAMPLE:**
**%c** print a single character.
**%d** print a decimal (base 10) number.
**%e** print an exponential floating-point number.
**%f** print a floating-point number.
**%g** print a general-format floating-point number.
**%i** print an integer in base 10 %o print a number in octal (base 8).
**%s** print a string of characters
**%u** print an unsigned decimal (base 10) number
**%x** print a number in hexidecimal (base 16).
**%%** print a percent sign (\% also works).
**WIDTH OPTION**
To print a number with a certain (minimum) width, say 5 spaces wide, the format specifier is %5d:
**EXAMPLE:**
**printf**                             ** produces**
 ("%5d",0):                                       0
("%5d",-7):                                    -7
("%5d",1560133635):           1560133635
("%5d",-2035065302):         -2035065302
it is not suitable for large numbers, only for small numbers of 3 digits maximum.
**The justification option**
Using printf, numbers can be left-justified (printed on the left side of the field) or right-justified (printed on the right side of the field).
To print a number 5 spaces wide and left justified (left aligned) the format specifier is %-5d. Here are some example cases:
**EXAMPLE**
**printf**                          **produces**
 ("%05d",0):                            00000
 ("%05d",-7):                         -0007
 ("%05d",1560133635):       1560133635
 ("%05d",-2035065302):     -2035065302
**Fun With Plus Signs**
**EXAMPLE:**
**printf** : **produces**
 ("%+5d",0) :                             +0
  ("%+5d",-7):                           -7
  ("%+5d",1560133635):       +1560133635
   ("%+5d",-2035065302):    -2035065302
**Printing Strings**
 The %s option allows us to print a string inside a string. Here is an example.
**EXAMPLE:**
**printf**                        **produces **
("%5s","")     :
("%5s","a")   :                            a
("%5s","ab")  :                         ab
("%5s","abcdefg") :            abcdefg
("%-5s","")              :
("%-5s","a")             :               a
("%-5s","ab")            :            ab
("%-5s","abcdefg")   :        abcdefg
**Floating Point**
Floating point numbers are those like 3.1415 that have a decimal point someplace inside. This is in contrast to ordinary integers like 27 that have no decimal point.
**EXAMPLE:**
**printf**              **produces**
("%.0f",e)      :                 3
("%.0f.",e)      :                3.
("%.1f",e)       :             2.7
("%.2f",e)        :           2.72
("%.6f",e)         :      2.718282
("%f",e)            :      2.718282
("%.7f",e)          :   2.7182818
# Return value
Upon successful return, these functions return the number of characters
printed (excluding the null byte used to end output to strings).

|Requirements|
|----------------|
|General|
|Allowed editors: vi, vim, emacs|
|All your files will be compiled on Ubuntu 14.04 LTS|
|Your programs and functions will be compiled with gcc 4.8.4 using the flags ``gcc -Wall -Werror -Wextra -pedantic -Wno-format --std=c90 *.c ``|
|All your files should end with a new line|
|A README.md file, at the root of the folder of the project is mandatory|
|Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl|
|You are not allowed to use global variables|
|No more than 5 functions per file|
|In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you dont have to push them to your repo (if you do we wont take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples|
|The prototypes of all your functions should be included in your header file called holberton.h|
|Dont forget to push your header file|
|All your header files should be include guarded                     |
|Note that we will not provide the _putchar function for this project|
|																|

|Compilation|
|---------------------------------------------------------------------------------------------------------|
|Your code will be compiled this way:																	  |
|First Tab:																								  |
|$ gcc -Wall -Werror -Wextra -pedantic *.c																  |
|As a consequence, be careful not to push any c file containing a main function in the root directory of  | |your project (you could have a test folder containing all your tests files including main functions)     |
|Our main files will include your main header file (holberton.h): #include holberton.h|
|You might want to look at the gcc flag -Wno-format when testing with your _printf and the standard printf| |Example of test file that you could use:|
|This function prints strings with a specified format.|


| Formats |
|--------------------------------------------------|
|  %c print a single character|
|  %d print a decimal (base 10) number|
|  %e print an exponential floating-point number   |
|  %f print a floating-point number|
|  %g print a general-format floating-point number |
|  %i print an integer in base 10|
|  %o print a number in octal (base 8)|
|  %s print a string of characters|
|  %u print an unsigned decimal (base 10) number   |
|  %x print a number in hexidecimal (base 16)|
|  %% print a percent sign (\% also works)|
|                                                  |

# Contributors
* Samuel Trujillo
<img align="center" src="https://github-readme-stats.vercel.app/api/top-langs/?username=samutrujillo&layout=compact&theme=vue&langs_count=6" alt="My github stats"/>
* Juan david avila
<img align="center" src="https://github-readme-stats.vercel.app/api/top-langs/?username=JuanDAC&layout=compact&theme=vue&langs_count=6" alt="My github stats"/>
* Julio Cesar Areas
<img align="center" src="https://github-readme-stats.vercel.app/api/top-langs/?username=jihuder&layout=compact&theme=vue&langs_count=6" alt="My github stats"/>

