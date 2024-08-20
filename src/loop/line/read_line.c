#include <stdio.h>
#include <unistd.h>
#include "line.h"

#define BUFFER_SIZE 1024

char * psh_read_line() {

    int buffer_size = BUFFER_SIZE; 
    char * buffer = malloc(buffer_size * sizeof(char));

    int index = 0;

    ssize_t bytes_read = 0;
    
    while(1) {

        //malloc error
        if(buffer == NULL){
            printf("Memory error during line parse\n");
            exit(1);
        }

        bytes_read = read(STDIN_FILENO, &buffer[index], BUFFER_SIZE);

        index += bytes_read;

        //make buffer bigger, keep reading
        if(bytes_read == BUFFER_SIZE){
            buffer_size += BUFFER_SIZE;
            buffer = realloc(buffer, sizeof(char) * buffer_size);
            continue;
        }
        else if(feof(stdin)){
            //WARNING
            //this may be an issue in the future
            printf("successfully reached end of file");
            exit(0);
        }
        else if(bytes_read == -1) {
            printf("Error parsing line \n");
            exit(1);
        }

        //success
        buffer[index] = '\0';

        return buffer; 

    }

}
