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

unsigned long hash(const char *s) {
 unsigned long ret = 5381;
 char c;
 while ((c = *s++)) {
 ret = (unsigned char)(c) + (33 * ret);
 }
 /* TODO: ret needs to be on [0, TABLESIZE) so we can use it as an
 * index in the hash table. How shall we do this? */
 return ret;
}


int is_prime(int num){
    /*purpose: return 1 if number is prime and zero if its not prime
     parameter int num
     pre: none
     post: 1 when its prime otherwise zero*/
    int i,count=0;
    if(num<2)
      return 0;
      else{
      for(i=2;i<num;i++){
          if (num%i==0){/*if number has modulus of 0 when divided by lower numbers, its not prime */
          count++;
          break;}}
    if(count==0)/*when number is not divisable by other numbers except itself, than count should remain zero*/
        return 1;/*thus it returns 1, True */
    else
       return 0;/*otherwise number is not prime*/
      }
}

void resize(hashtable ht,int start){
    entry *old_entries = ht->entries;
    int old_capacity=ht->capacity;


    while(!is_prime(start)){
        start++;
    }
    ht->capacity=start;
    ht->entries = calloc(ht->capacity,sizeof(entry));
    if(ht->entries==NULL){
        printf("Memory allocation  failed !");
        exit(EXIT_FAILURE);
    }
    ht->size=1;

    for (int i = 0; i < old_capacity; i++) {
        if (old_entries[i].key != NULL) {
            ht_insert(ht, old_entries[i].key, old_entries[i].value);
            free(old_entries[i].key);
            free(old_entries[i].value);
        }
        
    }
    
    free(old_entries);
}
