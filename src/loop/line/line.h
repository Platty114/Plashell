//line.h

/*
 * reads a line from standard input and returns it
 * expects : nothing
 * returns : char * to the string in memory 
 */
char * psh_read_line();


/*
 * takes a pointer to a line from stdin, and splits it into program and args
 * expects: a pointer to a valid string in format <program> <arg1> <arg2> ...
 * resturns: 2d array of arguments.
 */
char ** psh_split_line(const char * line);

