#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

typedef struct s_wordFreq {
    char * word;
    int count;
} wordFreq;

void printWord(void *key, void *value, void *data){
        printf("%s :::: %d \n", (char *)key, *(int *)value);
}


int main (int argc, char **argv){
    if (argc <=1){
        printf("A file was not specified. Please enter a file to read\n.");
        return -1;
    }
    
    char *filename = argv[1];
    gchar **contents = malloc(sizeof(char**));

    gboolean success = g_file_get_contents(filename, contents, NULL, NULL);
    if (!success){
        return -1;
    }

    //Strips out any punctuation
    g_strdelimit(*contents, "_-+=.,;:/?'\"()[]|%$#!&", ' ');

    //Split on whitespace delimiters (\n\t\r)
    gchar ** words = g_strsplit_set(*contents, "\n\t\r ", -1);

    GHashTable *word_count = g_hash_table_new(g_str_hash, g_str_equal);
    int index = 0;
    char * word = words[index];

    while (word != NULL){
        if (word[0] != '\0'){
            int * lookup = (int *)g_hash_table_lookup(word_count, word);
            int * result = malloc(sizeof(int));
            if (lookup == NULL){
                *result = 1;
            }
            else{
                *result = *lookup + 1;
            }
            g_hash_table_insert(word_count,word, result);
        }
        index++;
        word = words[index];
    }

    g_hash_table_foreach(word_count, printWord, NULL);
}
