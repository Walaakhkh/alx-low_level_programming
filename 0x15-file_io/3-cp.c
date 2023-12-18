#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO_stat(int stat, int fd, char *filename, char mode);

/**
 * main - the main function
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 1 when success otherwise exit
 */
int main(int argc, char *argv[])
{
	int s, d, n = 1024, w, cs, cd;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char b[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	s = open(argv[1], O_RDONLY);
	check_IO_stat(s, -1, argv[1], 'O');
	d = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(d, -1, argv[2], 'W');
	while (n == 1024)
	{
		n = read(s, b, sizeof(b));
		if (n == -1)
			check_IO_stat(-1, -1, argv[1], 'O');
		w = write(d, b, n);
		if (w == -1)
			check_IO_stat(-1, -1, argv[2], 'W');
	}
	cs = close(s);
	check_IO_stat(cs, s, NULL, 'C');
	cd = close(d);
	check_IO_stat(cd, d, NULL, 'C');
	return (0);
}

/**
 * check_IO_stat - check if the file can be opened or closed
 * @stat: file descriptoer of file to be opened
 * @filename: name of the file
 * @mode: closing mode
 * @fd: file descriptor
 * Return: void
 */

void check_IO_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", filename);
exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", filename);
		exit(99);
	}
}
