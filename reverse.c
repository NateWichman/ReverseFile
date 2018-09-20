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
	char* input_filename = argv[1];
	char* output_filename = argv[2];
	
	//Checking if user did not enter input
	if(output_filename == NULL){
	    fprintf(stderr, "REVIECED NO OUTPUT FILE NAME\n");
	    return -1; //Terminating program if they did not
	}
	/** Will hold the size of the file in charachters **/
	int size;

	/** A "String" to hold the text from the file **/
	char* buffer;

	/** Another "String" that holds the reverse text **/
	char* reverseBuf;

	//This function reads the file into the buffer "string"
        size = read_file(input_filename, &buffer); //it also sets the size as a return

	//Terminating program if the file cannot be found
	if(size == -1){ //read_file returns -1 to size if there is no file found
		fprintf(stderr, "TERMINATING FAILED PROGRAM DUE TO NO FILE FOUND\n");
		return -1; 
	}
	reverseBuf = (char*) malloc(sizeof(char) * size);
	//Setting reverseBuf equal to the reverse of buffer's charachters
	for(int i = 0; i < size; i++){
		reverseBuf[i] = buffer[size - i - 1];
	}

	//Writing the reversed "string" to the same filename
	write_file(output_filename, reverseBuf, size);

	//Freeing up memeory as to not cause a memory leak
	free(buffer);
	free(reverseBuf);
	return 0;
}
