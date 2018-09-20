/*************************************************************
Header file for the file_utils.c file

@author Nate Wichman
@version September 2018
*************************************************************/

#ifndef File_Utils
#define File Utils

#include <stdio.h>
#include <stdlib.h>

/** Reads a file into a charachter array **/
int read_file(char* filename, char** buffer);

/** writes a charachter array into a file **/
int write_file(char* filename, char* buffer, int size);


#endif /* defined(File_Utils) */
