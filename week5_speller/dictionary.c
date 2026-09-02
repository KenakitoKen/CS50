// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "dictionary.h"

//KC TODO (from walkthrough)
// Open dictionary file
    // fopen dictionary. check if return value is null
// read strings from file one at a time
    // fscanf for each word until fscanf returns EOF
// create a new node for each word
    // use malloc to create new node for each word
    // check if return value is null
    // copy word into node using strcpy
// hash word to obtain a hash value
    // hash function takes string and returns int, used as index
// insery node into hash table at that location
    // once determined which linked list to use, insert word into LL
    // take new node and set it's pointer to 1st element of LL
    // reset head to be new node just created
// create variable to keep track of words added to dictionary
unsigned int word_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 125;

// Create hash table: an array of N pointers, each pointing to the first node in a linked list
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int length = strlen (word);
    char lowercase_word[length + 1];
    for (int i = 0; i < length; i++)
        {
            lowercase_word[i] = tolower(word[i]);
        }
    lowercase_word[length] = '\0';
    int index = hash(lowercase_word);
    //Initialize cursor to the pointer stored in this bucket.
    //If the bucket is empty, the pointer is NULL and the loop ends immediately.
    //Otherwise, walk through the linked list by repeatedly updating cursor to
    //cursor->next until you reach NULL.”
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
        {
            // check cursor->word
            if (strcasecmp(cursor->word, lowercase_word) == 0)
            {
                //word found in dictionary
                return true;
            }
        }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    int string_length = strlen(word);
    for (int i = 0; i < string_length && i < 5; i++)
    {
        if (isalpha(word[i])) {
            hash_value += toupper(word[i]) - 'A';
        }
    }
    hash_value = hash_value % N;
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    // check if file loaded correctly
    if (source == NULL) {
        printf("Error!\n");
        return false;
    }
    //define word length -- to be used as buffer
    char word[LENGTH + 1];
    // loop through source, for words less than 45 chars, add to the word variable, until output is no longer 1
    while (fscanf (source, "%45s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // copy word from dictionary into word field of node
        strcpy(n->word, word);
        // call hash function returns integer, which is hash value
        unsigned int index = hash(word);
        // insert node into hash table defined above (node *table[N];)
        // the next pointer to take the head of linked list (set by hash function)
        n->next = table[index];
        // update the head of the linked list to point to the new node
        table[index] = n;
        // count number of words added to dictionary
        word_count += 1;
    }
    //close source file after words added to in memory data structure
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // return number of words added to dictioary, variable defined globally, value calculated in load function
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //N is a global variable, number of buckets in the array
    for (int i = 0; i < N; i++)
        {
            // access element at index i: -- table[i] stores a pointer to the head of the linked list
            node *cursor = table[i];
            while (cursor != NULL)
                {
                    // create temp variable
                    node *temp = cursor;
                    // point cursor to next struct
                    cursor = cursor->next;
                    // free temp of memory
                    free(temp);
                }
        }
        return true;
}
