#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i]; 
        hash_value *= name[i];
        hash_value = hash_value % 10;
    }
    return hash_value;
}

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    //table is empty
}

bool hash_table_insert(person *p){
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL){
        return false;
    } 
    hash_table[index] = p;
    return true;
}

void print_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL && 
        strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0){
            return hash_table[index];
    }
    return NULL;
}

int main(void)
{
    init_hash_table();
    print_table();

    person chris = {.name="Chris", .age=33};
    person peter = {.name="Peter", .age=592};
    person zelda = {.name="Zelda", .age=2};
    person melody = {.name="Melody", .age=32};

    hash_table_insert(&chris);
    hash_table_insert(&peter);
    hash_table_insert(&zelda);
    hash_table_insert(&melody);

    printf("\n");
    print_table();

    person *tmp = hash_table_lookup("Chris");

    if (tmp == NULL){
        printf("Not found.\n");
    } else{
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("Eric");

    if (tmp == NULL){
        printf("Not found.\n");
    } else{
        printf("Found %s.\n", tmp->name);
    }

    /*printf("Chris => %u\n", hash("Chris"));
    printf("Peter => %u\n", hash("Peter"));
    printf("Alex => %u\n", hash("Alex"));
    printf("Dylan => %u\n", hash("Dylan"));
    printf("Zelda => %u\n", hash("Zelda"));
    printf("Lucas => %u\n", hash("Lucas"));
    printf("Melody => %u\n", hash("Melody"));
    printf("Candy => %u\n", hash("Candy"));*/
}