#include <stdio.h>
#include "loop.h"

void psh_loop() {
    char * stdin_line;
    char ** args;
    int status;

    do {
        printf("$: ");
        stdin_line = psh_read_line();
        args = psh_split_line(line);
        status = lsh_execute(args);
    

    free(line);
    free(args);

    } while(status);
} 
