#include <stdio.h>
#include <unistd.h>
#include "line.h"

#define BUFFER_SIZE 1024

char * psh_read_line() {

    int buffer_size = BUFFER_SIZE; 
    char * buffer = malloc(buffer_size * sizeof(char));
    int posistion = 0;
    int nextChar;

    if(!buffer){
        printf("Error allocating buffer memory in during line read");
        exit(EXIT_FAILURE);
    }
    
    while(1){
        
        nextChar = getchar();
        
        //check for end of line,
        //if end of line finsih reading
        if(nextChar == '\n' || nextChar == EOF){
            buffer[posistion] = '\0';
            break;
        }
         
        buffer[posistion] = nextChar;
        posistion++; 

        //resize buffer if it gets too small 
        if(posistion == buffer_size -1){
            buffer_size += BUFFER_SIZE;
            if(
                !realloc(buffer, buffer_size * sizeof(char))
            ){
                printf("Error during buffer resize in read line");
                exit(EXIT_FAILURE);
            }
        }
    }
}
