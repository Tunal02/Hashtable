/*---------------------------------------
Students Name: Tarik unal
Assignment 2
Lab Section: cmpt-201-x02
Lab Instructors Name: DR. Mees
Lecture Instructors Name: Dr. Elmorsy
--------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ht_implement.h"
#include "ht.h"
#define START_SIZE 7
hashtable ht_create(void){
    int i;
    hashtable ht=malloc(sizeof(struct ht));
    if(ht==NULL){
        printf("Memory allocation  failed !");
        exit(EXIT_FAILURE);
    }
    ht->capacity=START_SIZE;
    ht->size=0;
    ht->entries=malloc(ht->capacity*sizeof(entry));
    if(ht->entries==NULL){
        printf("Memory allocation  failed !");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ht->capacity;i++){//intilize each slot, store null for each
        ht->entries[i].key=NULL;
        ht->entries[i].value=NULL;
        
    }
    return ht;
}

void ht_free(hashtable ht){
    int i;
    for(i=0;i<ht->capacity;i++){
        
        free(ht->entries[i].value);
        free(ht->entries[i].key);
        ht->entries[i].value=NULL;
        ht->entries[i].key=NULL;
            
        
    }
    free(ht->entries);
    free(ht);
}
void ht_insert(hashtable ht, char *key, char *value){
    unsigned long index=hash(key)%ht->capacity;//Calculates the hash, so it can store the index of key,value pair 
    float load_factor=(float)ht->size/(float)ht->capacity;
     if((load_factor)>=(0.66666667)){
        resize(ht,ht->capacity*2);
        load_factor=0;}

   while(ht->entries[index].key != NULL && strcmp(ht->entries[index].key, key) != 0) {
    index = (index + 1) % ht->capacity;
    if(index==ht->capacity)
        index=0;}
if (ht->entries[index].key == NULL) {
    ++ht->entries[index].count;
    // found an empty slot
    ht->entries[index].key = malloc(strlen(key) + 1);
    strcpy(ht->entries[index].key, key);
    ht->entries[index].value = malloc(strlen(value) + 1);
    strcpy(ht->entries[index].value, value);
    ++ht->size;
}
else if(strcmp(ht->entries[index].key,key)==0){
    ht->entries[index].value=malloc(strlen(value)*sizeof(ht->entries[index].value));
    strcpy(ht->entries[index].value, value);
    strcat(strcat(ht->entries[index].value, ","),ht->entries[index].value);
    }
}
void ht_remove(hashtable ht, const char *key){
        unsigned long index=hash(key)%ht->capacity;//Calculates the hash, so it can store the index of key,value pair 
       while (ht->entries[index].key != NULL) { // loop until an empty slot is found
        if (strcmp(ht->entries[index].key, key) == 0) { // if key is found
            free(ht->entries[index].key);
            free(ht->entries[index].value);
            strcpy(ht->entries[index].key,"DELETED"); // set key to "DELETED"
            strcpy(ht->entries[index].value,"NULL"); // set value to NULL
            --ht->size; // decrement the size of the hash table
            ht->entries[index].count=0;
            break;} // exit the loop
        else{printf("No key is found!!!");
	}
        index = (index + 1) % ht->capacity; // move to the next index
    }
    

}

   
 
void * ht_lookup(const hashtable ht, const char *key){
        unsigned int index=hash(key)%ht->capacity;//Calculates the hash, so it can store the index of key,value pair 
        int count=0;
        while(ht->entries[index].key!=key && count!=ht->capacity){
            index = (index + 1) % ht->capacity;
            count++;
        }
        if(strcmp(ht->entries[index].key,key)==0){
            return ht->entries[index].value;
        }
        else
            return NULL;
        
        
}

void ht_print_dist(const hashtable ht){
    int i;
    printf("PRINTING THE TABLE\n");
    printf("-----------------------------------");
    printf("\nIndex\tcount\tkey\tValues\t\n");
    for(i=0;i<ht->capacity;i++){
        
        if(ht->entries[i].key==NULL){
            printf("%d\t\tNULL\t\t\n",i);
        }
        else
            
            printf("%d\t%d    %s\t%s\t\n",i,ht->entries[i].count,ht->entries[i].key,ht->entries[i].value);
    }
    printf("-----------------------------------");
    
}
void ht_print(const hashtable ht){
    printf("\n");
    for(int i=0;i<ht->capacity;i++){
        if(ht->entries[i].key!=NULL){
            printf("%s\n%s\n\n",ht->entries[i].key,ht->entries[i].value);
        }

    }
    

        
}
        
        

