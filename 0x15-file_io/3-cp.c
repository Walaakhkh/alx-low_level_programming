#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_error(int exit_code, const char *message, const char *filename) {
    dprintf(STDERR_FILENO, message, filename);
    exit(exit_code);
}

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        handle_error(97, "Usage: cp file_from file_to\n", NULL);

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1)
        handle_error(98, "Error: Can't read from file %s\n", argv[1]);

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (dest_fd == -1) {
        close(src_fd);
        handle_error(99, "Error: Can't write to %s\n", argv[2]);
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            close(src_fd);
            close(dest_fd);
            handle_error(99, "Error: Can't write to %s\n", argv[2]);
        }
    }

    if (bytes_read == -1) {
        close(src_fd);
        close(dest_fd);
        handle_error(98, "Error: Can't read from file %s\n", argv[1]);
    }

    if (close(src_fd) == -1 || close(dest_fd) == -1)
        handle_error(100, "Error: Can't close fd %d\n", src_fd);

    return 0;
}
