#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	int alen, elen;
	char c = 'z';
	char *str = NULL;

	len = _printf("_Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence. \n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("_Length:[%d, %i]\n", 2, 2);
	printf("Length:[%d, %i]\n", 2, 2);
	_printf("_Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("_Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("_Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("_Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("_Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("_Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("_String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("_Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("_Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("_Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("_Unknown:[%r]\n");
	printf("Unknown:[%r]\n");

	printf("START OF TEST\n");

	printf("=====================\n");
	printf("printf(NULL)  : %d\n", printf(str));
	printf("_printf(NULL) : %d\n", _printf(str));
	printf("printf(\"%\") : %d\n", printf("%"));
	printf("_printf(\"%\"): %d\n", _printf("%"));
	str = "hello, world";
	printf("=====================\n");
	printf("*****CHAR*****\n");
	printf("=====================\n");
	printf("Expected   : %c\n", 'a');
	_printf("_Actual     : %c\n", 'a');
	elen = printf("Expected   : %c\n", c);
	alen = _printf("_Actual     : %c\n", c);
	printf("Expected   : %i\n", elen);
	printf("_Actual     : %i\n", alen);
	printf("Expected   : %cc\n", 'a');
	_printf("_Actual     : %cc\n", 'a');
	printf("Expected   : %c\n", 53);
	_printf("_Actual     : %c\n", 53);
	printf("Expected   : %c.\n", '\0');
	_printf("_Actual     : %c.\n", '\0');
	printf("Expected   : %%%c\n", 'y');
	_printf("_Actual     : %%%c\n", 'y');
	printf("Expected   : %\n");
	_printf("_Actual     : %\n");
	printf("=====================\n");
	printf("*****STRINGS*****\n");
	printf("=====================\n");
	alen = elen = 0;
	printf("Expected   : %s\n", "holberton");
	_printf("_Actual     : %s\n", "holberton");
	printf("Expected   : %s$\n", "");
	_printf("_Actual     : %s$\n", "");
	elen = printf("Expected   : %s\n", str);
	alen = _printf("_Actual     : %s\n", str);
	elen = printf("%s", "");
	alen = _printf("%s", "");
	printf("Expected   : %i\n", elen);
	printf("_Actual     : %i\n", elen);
	printf("Expected   : %sschool\n", "holberton");
	_printf("_Actual     : %sschool\n", "holberton");
	elen = printf("Expected: %c%%%c%%%%%s%c%s%s\n", INT_MAX, INT_MIN, "hello", 0, "holberton", 0);
	alen = _printf("Expected: %c%%%c%%%%%s%c%s%s\n", INT_MAX, INT_MIN, "hello", 0, "holberton", 0);
	printf("Expected: %d\n", elen);
	printf("_Actual  : %d\n", alen);
	
	
	len = _printf("_%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	len2 = printf(" %c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("diference %d, %d\n", len, len2);
	len = _printf("%s", "_This sentence is retrieved from va_args!\n");
	len2 = printf("%s", " This sentence is retrieved from va_args!\n");
	printf("diference %d, %d\n", len, len2);
	len = 0;
	len2 = 0;
	len = _printf("_Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	len2 = printf(" Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	elen = (int)length_str("_Complete the sentence: You (null) nothing, Jon Snow.\n", false);
	printf("diference %d, %d, %d\n", len, len2, elen);
	len = _printf("_css%ccs%scscscs\n", 'T', "Test");
	len2 = printf(" css%ccs%scscscs\n", 'T', "Test");
	printf("diference %d, %d\n", len, len2);
	len = _printf("_%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	len2 = printf(" %s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("diference %d, %d\n", len, len2);
	str = "When you invoke GCC , it normally does preprocessing, compilation, assembly and linking. The \"overall options\" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler.\n\nOther options are passed on to one stage of processing. Some options control the preprocessor and others the compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them.\n\nMost of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C ++ ), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages.\n\nThe gcc program accepts options and file names as operands. Many options have multi-letter names; therefore multiple single-letter options may not be grouped: -dv is very different from -d -v.\n\nYou can mix options and other arguments. For the most part, the order you use doesn't matter. Order does matter when you use several options of the same kind; for example, if you specify -L more than once, the directories are searched in the order specified. Also, the placement of the -l option is significant.\n\nMany options have long names starting with -f or with -W---for example, -fmove-loop-invariants, -Wformat and so on. Most of these have both positive and negative forms; the negative form of -ffoo would be -fno-foo. This manual documents only one of these two forms, whichever one is not the default.\n";

	/* len2 = length_str(str, false); */
	len = _printf(str);
	len2 = printf(str);
	printf("diference %d, %d\n", len, len2);

	//len = _printf("man gcc:\n%s", str);
	//len2 = printf("man gcc:\n%s", str);
	//printf("diference %d, %d\n", len, len2);

	len = _printf("%c", '\0');
	len2 = printf("%c", '\0');
	printf("diference %d, %d\n", len, len2);


	return (0);
}
