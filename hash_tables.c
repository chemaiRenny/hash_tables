#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct{
    char name[MAX_NAME];
    int age;
    //add other stuff later
}person;

person* hash_table[TABLE_SIZE];
unsigned int hash(char *name)
{
    int length = strnlen(name,MAX_NAME);
    unsigned int  hash_value = 0;
    for (int i = 0; i < length ;i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void _init_hash_table()
{
    for (int i =0; i < TABLE_SIZE;i++)
    {
        hash_table[i] = NULL;        
    }
}

void print_table()
{
    printf("Start\n");
    for (int i = 0;i < TABLE_SIZE;i++)
    {
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }else{
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
    printf("End\n");
}
bool hash_table_insert(person *p)
{
    if (p == NULL) 
    {
        return false;
    }

    for (int index = hash(p ->name); index < TABLE_SIZE ; index++ )
    {
        if (hash_table[index] == NULL)
        {
            hash_table[index] = p;
            return true;
        }

    }
    return false;
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp(name,hash_table[index]->name,MAX_NAME) == 0)
    {
        return hash_table[index];
    }
    else return NULL;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp(name,hash_table[index]->name,MAX_NAME) == 0)
    {
        person * tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
    else return NULL;
}

int main()
{
    _init_hash_table();
    person test = {.name = "test",.age = 102 };
    person test1 = {.name = "test1",.age = 102 };
    person test2 = {.name = "test2",.age = 102 };
    person test3 = {.name = "test3",.age = 102 };
    person test4 = {.name = "test4",.age = 102 };
    person test5 = {.name = "test5",.age = 102 };
    person test6 = {.name = "test6",.age = 102 };
    person test7 = {.name = "test7",.age = 102 };
    person test8 = {.name = "test8",.age = 112 };

    hash_table_insert(&test);
    hash_table_insert(&test1);
    hash_table_insert(&test2);
    hash_table_insert(&test3);
    hash_table_insert(&test4);
    hash_table_insert(&test5);
    hash_table_insert(&test6);
    hash_table_insert(&test7);
    hash_table_insert(&test8);
    
    print_table();
    return 0;
}