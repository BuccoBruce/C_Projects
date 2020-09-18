// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <unistd.h> //Used for sleep for debug, remove

extern char* strdup(const char*);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Create Hash table
node *hash_table[N];

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned hashval;
    for (hashval = 0; *word != '\0'; word++)
      hashval = *word + 31 * hashval;
    return hashval % N;
}

bool hash_table_insert(node *n){
    if (n == NULL)
        return false;

    int index = hash(n->word);

    if (hash_table[index] == NULL)
    {
        hash_table[index] = n;
    }
    else
    {
        n->next = hash_table[index];
        hash_table[index] = n;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //unsigned int hash_value = 0;

    //Create a table of nodes and set the initial values to NULL
    //for (int i = 0; i < N; i++)
    //{
    //    node *n = malloc(sizeof(node));
    //    hash_table[i] = n = NULL;
    //}

    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
        return false;

    //Iterate over dictionary and hash each word, look at speller.c for grabbing words from loop
    //Then store each hashed word in its appropriate array value, adding to linked list if a collision occurs

    //Initialize word array to store words from dictionary
    char dicword[LENGTH + 1];
    int index = 0;

    //while (fgets(dicword, LENGTH+1, dic) != NULL){
    while (fscanf(dic, "%s", dicword) != EOF){
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL){
            return false;
        }

        //Store string into node
        strcpy(tmp->word, dicword);

        //tmp->next = NULL;

        // Hash the word and insert at hashed value in array
        int hash_value = hash(tmp->word);
        node *head = hash_table[hash_value];

        //hash_table_insert(tmp);

        if (head == NULL)
        {
            hash_table[hash_value] = tmp;
        }
        else
        {
            tmp->next = hash_table[hash_value];
            hash_table[hash_value] = tmp;
        }

        //Print the word and its hash for troubleshooting
        //printf("%s %i\n", tmp->word, hash_value);
    }

    fclose(dic);
    return true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    //if (word == NULL){
    //    return false;
    //}
    //
    ////Initialize new array for lowercase word
    int n = strlen(word);
    char lower_word[LENGTH + 1];
    //
    ////Set word to lowercase
    for (int i = 0; i < n; i++){
        lower_word[i] = tolower(word[i]);
    }

    lower_word[n] = '\0';

    //Hash the word to get the hash value and store in an int
    int h = hash(lower_word);
    printf("hash index = %i\n", h);
    node *cursor = hash_table[h];
    printf("check function word: %s | hash value: %i\n", lower_word, h);
    //node *head = malloc(sizeof(node));
    //head = hash_table[hashed_word];
    printf("Cursor->word: %s\n", cursor->word);

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, lower_word) == 0)
        {
            printf("Match %s found", cursor->word);
            return true;
        }
        else
        {
            printf("No match found yet, searching next");
            cursor = cursor->next;
        }
    }

    //Check if hashed value exists in hash table and if so, iterate over linked list to see if word is in the list
    //if (hash_table[hashed_word] != NULL){
    //
    //for (; head != NULL; head = head->next){
    //    char *tmp = head->word;
    //
    //    //printf("Current word is: %s", tmp);
    //
    //    if (strcasecmp(tmp, word) == 0)
    //    {
    //        //("Match found with %s!\n",tmp);
    //        return true;
    //    }
    //}
    //
    //}
    //else
    //{
    //    //printf("Value at %i is null!\n", hashed_word);
    //    return false;
    //}
    return false;
}


void print_table(){
    printf("Start hash table\n");
    for (int i = 0; i < N; i++){
        if (hash_table[i] == NULL){
            printf("\n\t%i\t---\n", i);
        } else {
        printf("\n\t%i\t", i);
        while (hash_table[i] != NULL){
            printf("%s|%p->", hash_table[i]->word, &hash_table[i]);
            hash_table[i] = hash_table[i]->next;
        }
        }
    }
    printf("\nEnd hash table\n");
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int count = 0;

    for (int i = 0; i < N; i++){
        if (hash_table[i] != NULL){

            //Entry found at hash table head, therefore increase counter by 1
            count++;

            //Increase counter by 1 for each extra entry in the linked list
            while (hash_table[i]->next != NULL){
                count++;
                hash_table[i] = hash_table[i]->next;
            }
        }
    }

    //printf("Number of dictionary words is %i", count);
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    node *tmp = NULL;

    //Iterate over hash table
    for (int i = 0; i < N; i++)
    {
        for (node *head = hash_table[i]; head != NULL; head = head->next)
        {
            cursor = head;
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (node *head = hash_table[i]; head != NULL; head = head->next)
        {
            if (head != NULL)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}