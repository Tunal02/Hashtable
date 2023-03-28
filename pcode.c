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
#include "ht.h"
int main(int argc,char *argv[]){
    FILE *fp;
    char *city,*postalcode;
    char line[80];
    char user[20];

    fp = fopen(argv[1], "r");
    hashtable ht=ht_create();


    if(fp==NULL){
        printf("NO FILE EXIST!!!!");
    }

    while (fgets(line,80,fp)!=NULL)
    {
        city = strtok(line, ",");
        postalcode = strtok(NULL, "\n");
        ht_insert(ht,city,postalcode);
    }
    ht_print_dist(ht);
    printf("\nEnter a city name PLease!!: ");
    scanf("%s",user);


    char *value=ht_lookup(ht,(const char *)user);
    if(value!=NULL){
       printf("The value you are searching is %s!\n",value);
    }else
        printf("Key Is Not Found!!\n");

    ht_free(ht);
    fclose(fp);
    return 0;
}