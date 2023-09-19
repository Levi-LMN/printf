#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
int main() {
    /* Define a buffer size */
    char buffer[1024];
    
    /* Open a file descriptor (e.g., STDOUT_FILENO for standard output) */
    int fd = STDOUT_FILENO;

    /* Generate some data to write (for example, a long string) */
    const char *data_to_write = "This is a long string that will be written to the file repeatedly.";

    /* Calculate the length of the data */
    size_t data_length = strlen(data_to_write);

    /* Initialize variables for tracking the current position in the data and bytes written */
    size_t data_position = 0;
    ssize_t bytes_written = 0;

    /* Write data in chunks using a buffer */
    while (data_position < data_length) {
        /* Copy a chunk of data into the buffer */
        size_t chunk_size = (data_length - data_position > sizeof(buffer)) ? sizeof(buffer) : data_length - data_position;
        memcpy(buffer, data_to_write + data_position, chunk_size);

        /* Write the chunk to the file descriptor */
        ssize_t bytes = write(fd, buffer, chunk_size);

        /* Check for write errors */
        if (bytes == -1) {
            perror("write");
            return 1;
        }

        /* Update the position and bytes written */
        data_position += chunk_size;
        bytes_written += bytes;
    }

    /* Close the file descriptor if necessary */
    /* close(fd); */

    printf("Total bytes written: %zd\n", bytes_written);

    return 0;
}

