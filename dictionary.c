// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 400;

// Hash table
node *table[N];

// Dictionary wordcount
int wordcount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char *lowerword = malloc(strlen(word));             // Create lower word
    int wordlen = (strlen(word) + 1);                   // Make wordlength + 1 for \0
    if (lowerword == NULL)
    {
        return 1;                               // Check for NULL
    }
    for (int i = 0; i < wordlen; i++)
    {
        lowerword[i] = tolower(word[i]);            // Convert word to lowercase
    }
    node *cursor = NULL;                        // Cursor used to traverse linked list
    int wordbucket = hash(lowerword);               // Hash word to find bucket/index
    cursor = table[wordbucket];                    // Set cursor to first value

    while ((strcasecmp(cursor->word, word)) != 0)   // If word doesn't match
    {
        cursor = cursor->next;                      // Set cursor to next
        if (cursor == NULL)
        {
            free(lowerword);                        // If at last node free memory and return false
            free(cursor);
            return false;
        }
    }
    free(lowerword);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    int wordlen = strlen(word);
    for (int i = 0; i < wordlen; i++)
    {
        sum += word[i];
    }
    return (sum % N);             // Sum mod Number of buckets
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary to read
    FILE *dict = fopen(dictionary, "r");
    // Check for presence of data
    if (dict == NULL)
    {
        return 1;
    }
    else
    {
        char word[47];
        while (fscanf(dict, "%s", word) == 1)
        {
            node *n = malloc(sizeof(node));         // Allocate memory for node   (This is staying the same address for everyword, crashing program later)
            if (n != NULL)                          // Check if memory is available
            {
                strcpy(n->word, word);                  // Copy dictionary word to node
                n->next = NULL;                         // Set node pointer to null

                int bucket = hash(word);                // Hash word to find index
                if (table[bucket] != NULL)
                {
                    node *tmp = NULL;       // Create temp node
                    tmp = table[bucket];                    // Copy table to tmp
                    n->next = tmp;                // Point n at whats next in table
                    table[bucket]= n;              // Point table at n
                    wordcount += 1;

                }
                else
                {
                    table[bucket] = n;
                    wordcount += 1;
                }
            }
        }
        fclose(dict);
        return true;
    }

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = NULL;            // Cursor used to traverse linked list
        node *tmp = NULL;
        cursor = table[i];                           // Set cursor to first value
        tmp = cursor;
        while (cursor != NULL)
            {
                cursor = cursor->next;
                free(tmp);
                tmp = cursor;
            }
        free(tmp);
        free(cursor);
    }
    return true;
}
