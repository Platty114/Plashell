#include "line.h"
#include "string.h"
/*
* splits a line into a list of tokens
* ASSUMES tokens are split by spaces,
* no "" allowed (for now)
*/
char ** psh_split_line(const char * line) {

    int line_length = 0;
    int num_tokens = 0;
    char * line_copy;
    char ** tokenized_line;

    line_length = strlen(line);
    //debugging
    assert(line_length != 0);

    //error checking
    if(!line_length){
        printf("Error in splitline! Empty line\n");
        exit(EXIT_FAILURE);
    }

    line_copy = (char *) malloc(line_length * sizeof(char));

    //debugging
    assert(line_copy != NULL);    

    //replace all spaces with \0 to make for easy splitting

    for(int i = 0; i < line_length; i++){
        if(line_copy[i] == ' '){
            line_copy[i] = '\0';
            num_tokens++;
        }
    }

    //allocate space for strings
    tokenized_line = malloc(num_tokens * sizeof(char * ));

    //debugging
    assert(tokenized_line != NULL);

    //now create copies of tokens
    for(int i = 0, num_tokens_created = 0; i < line_length; i++){
        int j = i;
        while(line_copy[j] != '\0' && j < line_length){
            j++;
        }

        assert(j > i);

        tokenized_line[num_tokens_created] = malloc((j - i) *sizeof(char));  
        //debug
        assert(tokenized_line[num_tokens_created] != NULL);

        // TODO FINISH COPYING STRING TO tokenized_line
        while(i != j){
            tokenized_line[num_tokens_created][i] = 
        }
    } 
}
