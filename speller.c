// Implements a dictionary's functionality
// Credit goes to  Anvea on youtube & Jospeh on medium. This was really hard for me.


#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Declare variables for later
unsigned int word_count;
unsigned int hash_val;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    //If File does not open return NULL
    if (file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    //Create new variable called word
    char word[LENGTH + 1];
    //Scan word list till EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        //Use malloc to allocate memory
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }
        //Copy into node
        strcpy(n->word, word);
        hash_val = hash(word);
        n->next = table[hash_val];
        table[hash_val] = n;
        word_count++;
    }
    fclose(file);
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total_sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        total_sum += tolower(word[i]);
    }
    return total_sum % N;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    for (int i = 0; i < N; i++)
    {
        hash_val = hash(word);
        node *cursor = table[i];

        while (cursor != 0)
        {
            if (strcasecmp(word, cursor->word) == 0)
            {
                return true;
            }
            cursor = cursor->next;
        }
    }
    return false;
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
