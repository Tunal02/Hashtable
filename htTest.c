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

int main(){
    hashtable ht=ht_create();
    printf("Testing ht_create:\n");
    printf("Hash table created (ht_create)\n\n");
    printf("Testing ht_insert:\nEdmonton inserted\n");
    ht_insert( ht,"Edmonton", "T6V");
    ht_print_dist(ht);
    printf("\n");
    printf("Ottawa inserted\n");
    ht_insert( ht,"ottawa", "BXN");
    ht_print_dist(ht);
    printf("\n");
    printf("Testing ht_remove:\n");
    printf("Lookup Edmonton\n ");
    
    

    char *value=(char*)ht_lookup(ht,"Edmonton");
    if(value!=NULL){
       printf("The value you are searching is %s!\n",value);
    }else
        printf("Key Is Not Found!!\n");
    printf("Inserting 3 more cities\n");
    ht_insert(ht,"Calgary","C3V");
    ht_insert(ht,"Jasper","Q3C");
    ht_insert(ht,"YellowKnife","YE3");
    ht_print(ht);
    printf("\nToronto inserted\n");
    ht_insert(ht,"Toronto","ER2");
    ht_print_dist(ht);
    printf("\nJasper is removed\n");
    ht_remove(ht,"Jasper");
    ht_print_dist(ht);
    //ht_print(ht);
    ht_free(ht);
    return 0;
}
