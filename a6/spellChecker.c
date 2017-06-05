#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement **FIXED**
    
    //read dictionary words
    char *word = nextWord(file);

    //insert dictionary words into a hashtable (buckets)
    while(word != 0)
    {
	    hashMapPut(map, word, 1);
	    free(word); //mem leak management
	    word = nextWord(file);
    }

	free(word); //mem leak management
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement **attempted FIXED**
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
	
	if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
	    printf("Goodbye!\n");
        }
	//check if the input hashes to a bucket
	else if(hashMapContainsKey(map, inputBuffer))
	{
		/*calculate hashIndex*/
		int hashIndex = HASH_FUNCTION(inputBuffer) % hashMapCapacity(map);

		//handle negative values
		if(hashIndex < 0)
		{
			hashIndex += hashMapCapacity(map);
		}

		//bucket head
		HashLink *cur = map->table[hashIndex];
		/********************/

		printf("*****Did you mean?*****\n");
		//print entire bucket
		while(cur)
		{
			//print all keys in the bucket
			printf("%s\n", cur->key);
			cur = cur->next;
		}
	}
	else
	{
		printf("Word not found!\n");
	}
    }
    
    hashMapDelete(map);
    return 0;
}
