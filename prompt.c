#include "shell.h"
/**
* my_prompt - print a string text to stdout
*
* Return: 0
*/

void my_prompt(void)
{
	write(STDOUT_FILENO, "fujiwara ", 9);
}
