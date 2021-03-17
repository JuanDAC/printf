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

