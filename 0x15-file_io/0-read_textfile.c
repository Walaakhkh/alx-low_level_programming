#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * read_textfile - function that reads a text file and prints it
 * to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 * @Return: the actual number of letters it could read and print,
 * 0 if filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int d;
	ssize_t r, w;
	char *b;

	if (filename == NULL)
		return (0);

	d = open(filename, O_RDONLY);
	if (d == -1)
		return (0);
	b = malloc(sizeof(char) * letters);
	if (b == NULL)
	{
		close(d);
		return (0);
	}
	r = read(d, b, letters);
	close(d);
	if (r == -1)
	{
		free(b);
		return (0);
	}
	w = write(STDOUT_FILENO, b, r);
	free(b);
	if (r != w)
		return (0);
	return (w);
}
