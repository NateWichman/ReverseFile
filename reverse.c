/***************************************************************
Reverses the text inside of a file.

@author Nathan Wichman
@version September 2018
****************************************************************/

#include "file_utils.h"
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char** argv){
	/** command line input of the file's name that is to be reversed **/
	char* filename = argv[1];
	
	/** this code block was provided by Prof. Woodring **/
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	/** A "String" to hold the text from the file **/
	char* buffer = (char*) malloc(sizeof(char) * size);

	/** Another "String" that holds the reverse text **/
	char* reverseBuf = (char*) malloc(sizeof(char) * size);

	//This function reads the file into the buffer "string"
	read_file(filename, &buffer); //included from file_utils.h

	//Setting reverseBuf equal to the reverse of buffer's charachters
	for(int i = 0; i < size; i++){
		reverseBuf[i] = buffer[size - i];
	}

	//Writing the reversed "string" to the same filename
	file_write(filename, reverseBuf, size);

	//Freeing up memeory as to not cause a memory leak
	free(buffer);
	free(reverseBuf);
	return 0;
}
