/* Code replicating the UNIX tee command

For Exercise 3 of Head First C

Question 3: The part that slowed me down the most was grabbing the input
 correctly and making sure that the correct arguments were being used.
 
Question 4: The professional code has better checking for errors, and uses a
 struct to store the file pointers. They also store their files differently
 than my interpretation.

Author: Deniz Celik
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Entry point for tee command */
int main(int argc, char *argv[]){
    //Append flag variable
    int aFlag = 0;
    //Option variable for getopt output
    int c;
    //Index for iterating through files
    int index;
    //Storage for input string
    char input[64];
    //Pointer for output file
    FILE *outputFile;

    //Get the append flag
    while ((c = getopt(argc, argv, "a?")) != -1){
        switch (c){
            case 'a':
                //Append flag passed in
                aFlag = 1;
                break;
            case '?':
                //Un-expected argument passed in
                fprintf(stderr, "Usage: %s [ -a ] [FILE]...\n", argv[0]);
                //Exit and don't run anything else
                exit(EXIT_FAILURE);
            default:
                //Default case is just break
                break;   
            
        }
    }
    
    //Check if they passed in file arguments
    if (optind >= argc) {
        //Print the error and exit
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }
    
    //Read our input piece by piece
    while (fscanf(stdin, "%s", input) == 1){
        //print the input to stdout as well
        fprintf(stdout, "%s\n", input);
        //Iterate over the files passed, starting from the options
        for (index = optind; index < argc; index++){
            //Clear the file if we aren't appending
            if (aFlag == 0) fclose(fopen(argv[index], "w"));
            //Open our file
            outputFile = fopen(argv[index], "a");
            //"Write" to our file
            fprintf(outputFile, "%s\n", input);
            //Close the file
            fclose(outputFile);
        }
    }

    return 0;
}
