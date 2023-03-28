/*---------------------------------------
Students Name: Tarik unal
Assignment 2
Lab Section: cmpt-201-x02
Lab Instructors Name: DR. Mees
Lecture Instructors Name: Dr. Elmorsy
--------------------------------------------*/
#ifndef HT_IMPLEMENT
#define _HT_IMPLEMENT

typedef struct {
    char *value;
    char *key;
    int count;

}entry;

struct ht
{   entry* entries;

    int size;
    int capacity;
};
typedef struct ht* hashtable;

unsigned long hash(const char *s);
int is_prime(int num);
void resize(hashtable ht,int start);

#endif
