errors.c

#include "shell.h"

/**
 *_eputs -this  prints an input string
 * @str:this is  the string to be printed
 *
 * Return: 0
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - this writes the character c to  the stderr
 * @c: this is the character to printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is to be set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd -this writes the character c to a given fd
 * @c: this is  the character to printed
 * @fd:this is the filedescriptor to be written to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is to be set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - this prints an input string
 * @str: this is  the string to be printed
 * @fd: this is the filede scriptor to be  written to
 *
 * Return:this is  the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

