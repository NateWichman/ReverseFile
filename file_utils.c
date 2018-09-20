/*******************************************************************
     This program allows for the use of two functions. One to read a 
file into a charachter array, and one to write a charachter array
into a file.

@author Nate Wichman
@version September 2018
*******************************************************************/
#include "file_utils.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/******************************************************************
Reads text from a file into a "string" (charachter array)

@param the file's name to be read, and a string to be read into
@return -1 for errors, otherwise the size of the file
******************************************************************/
int read_file(char* filename, char** buffer){
	/** File Pointer **/
	FILE *fp;
	
	//Opening the file to read
	fp = fopen(filename, "r");

	//checking if the file exists, if not throwing an error
	if(fp == NULL){
		return -1; 
		fprintf(stderr, "FILE NOT FOUND");
	}

	//This code block was provided by Prof. Woodring, finds the size of the file
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	

	//Now we must dynamically allocate the file's size in memory to the
	//output string. (Character array)
	*buffer = (char*) malloc(sizeof(char) * size);

	//Reading in text from the file into the string at **buffer's location
	//(Actuall another pointer, but can be treated like a charachter array
	fread(*buffer, size, 1, fp);
	
	//returning the size of the file
	return size;
}

/**************************************************************
This function writes a string to a file.

@param A file's name, text to write to the file, and the size
     of the text.
@return an error code
**************************************************************/
int write_file(char* filename, char* buffer, int size){
	/** File Pointer **/
	FILE* fp;
	
	//opening file with the intent to write
	fp = fopen(filename, "w");

	//writing the string to the file.
	fwrite(buffer, size, 1, fp);
	
	return 0;
}
