/* Code for ThinkOS Chapter 5 Reading Questions

Author: Deniz Celik
*/
#include <stdio.h>
#include <string.h>

#define STR_LEN 64

/* Returns the uppercase equivalent of a lowercase ASCII letter

Returns character between 65('A') and 90('Z') if given a lowercase letter,
	Otherwise, returns the passed character

c: character to convert to uppercase
*/
char toUpper(char c){
	//Check if the passed character is an ASCII lowercase letter
	if ((c>96) && (c<123)){
		return (c&~(1<<5));
	}
	return c;
}

/* Entry point for entering uppercasing code */
int main (int argc, char *argv[])
{	
	//Setup our variables
	char input[STR_LEN];
	char output[STR_LEN];
	int i;
	
	//Ask the user for a string
	printf("Pass a string of max length %d to be upper-cased: ", STR_LEN);
	
	//Check if fgets returns an error when reading the string
	//This also helps prevent a buffer overflow by specifying STR_LEN
    if( fgets(input, STR_LEN, stdin) != NULL){
		//Loop through the given string
		for (i=0; i< STR_LEN; i++) {
			//Uppercase the character
			output[i]  = toUpper(input[i]);
		}
		printf(output);
	} else {
		printf("Error taking in the given string");
	}
	return 0;
}