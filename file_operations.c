#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "file_operations.h"

int create_and_write_file(const char *filename, const char *content) {
    // TODO: Declare an integer 'fd' for the file descriptor.
    // TODO: Declare a variable 'bytes_written' of type ssize_t to store how many bytes are written.
    int fd;
    ssize_t bytes_written;

    // TODO: Print a message showing which file is being created.
    // TODO: Print a message showing what content will be written.
    printf("File %s to be created\n", filename);
    printf("Content to be written: %s\n", content);

    // TODO: Open or create the file for writing using the open() system call.
    // TODO: Use flags O_CREAT | O_WRONLY | O_TRUNC and permissions 0644.
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
    {
      perror("Error: failed to open/create file");
      return -1;
    }

    // TODO: Print the file descriptor value.
    printf("File descriptor: %d\n",fd);
    // TODO: Write the content to the file using the write() system call.
    // TODO: Use the length of 'content' as the size to write.
    // TODO: Check if write() failed (bytes_written == -1). If so, print an error using perror, close the file, and return -1.
    bytes_written = write(fd, content, strlen(content));
    if (bytes_written == -1)
    {
      perror("Error: content couldn't be written");
      close(fd);
      return -1;
    }

    // TODO: Print a success message with the number of bytes written and the filename.
    printf("%zd bytes written into %s\n", bytes_written, filename);
    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.
    if (close(fd) == -1)
    {
      perror("Error: failed to close the file");
      return -1;
    }
    // TODO: Print a message that the file was closed successfully.
    printf("file %s closed successfully\n", filename);
    return 0;
}

int read_file_contents(const char *filename) {
    // TODO: Declare an integer 'fd' for the file descriptor.
    // TODO: Create a buffer array of size 1024 to store the file data.
    // TODO: Declare a variable 'bytes_read' of type ssize_t to store how many bytes are read.
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    // TODO: Print a message showing which file is being read.
    printf("file %s being read\n", filename);
    // TODO: Open the file for reading using the open() system call.
    // TODO: Use the O_RDONLY flag.
    // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.
     fd = open(filename, O_RDONLY);
     if (fd == -1)
     {
      perror("Failed to open the file");
      return -1;
     }

    // TODO: Print the file descriptor value.
    // TODO: Print a header for the file contents.
    printf("File descriptor: %d\n", fd);
    printf("---File start---\n");

    // TODO: Read the file contents using the read() system call in a loop.
    // TODO: Use sizeof(buffer) - 1 for the buffer size.
    // TODO: Null-terminate the buffer after each read.
    // TODO: Print the contents of the buffer.
    // TODO: Continue reading until read() returns 0.
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) != 0)
    {
      buffer[bytes_read] = '\0';
      printf("%s\n", buffer);
    }

    // TODO: Check if read() failed (bytes_read == -1). If so, print an error using perror, close the file, and return -1.
    if (bytes_read == -1)
    {
      perror("Error: file couldn't be read");
      close(fd);
      return -1;
    }
    // TODO: Print a footer for the end of the file.
    printf("---File end---\n");
    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.
    if (close(fd) == -1)
    {
      perror("Error: file couldn't be closed");
      return -1;
    }

    // TODO: Print a message that the file was closed successfully.
    printf("File closed successfully\n");
    return 0;
}
