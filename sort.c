#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 150

struct Level{
    int level;
    char url[MAX_SIZE];
    struct Level *next;
};

struct Level* createList();
void addEntry(struct Level**, int, char*);
void display(struct Level*);
extern char linksFile[];

//structs was used only for educational purposes -> not efficient
void sortLinksFile(){
    struct Level *log = createList();

    FILE *links = fopen(linksFile, "w");

    while(log != 0)
    {
        fprintf(links, "%d %s", log->level, log->url);
        log = log->next;
    }

    fclose(links);
}

struct Level* createList(){
    FILE *links = fopen(linksFile, "r");

    struct Level *l1;
    l1 = malloc(sizeof (struct Level));
    l1->level = 1;
    l1->next = 0;

    char* token;
    char line[MAX_SIZE];
    while((fgets(line, MAX_SIZE, links)) != NULL){
        char* lvl = strtok(line, " ");
        char* url = strtok(NULL, " ");
        if(atoi(lvl) == 1)
        {
            strcpy(l1->url, url);
        }
        else{
            addEntry(&l1, atoi(lvl), url);
        }
    }
    //display(l1);
    fclose(links);

    return l1;
}

//Double pointer is needed when setting a new beginning of linked list
void addEntry(struct Level **l1, int level, char *url){
    struct Level *new, *temp = *l1, *previous = temp;
    new = malloc(sizeof (struct Level));
    new->level = level;
    strcpy(new->url, url);
    new->next = 0;

    if(new->level < temp->level){
        new->next = temp;
        *l1 = new;
    }
    else if(new->level > temp->level && temp->next == 0){
        (*l1)->next = new;
    }
    else if(new->level > temp->level){
        while(temp != 0 && temp->level < new->level){
            previous = temp;
            temp = temp->next;
        }
        new->next = temp;
        previous->next = new;
    }
}

//For testing
void display(struct Level *l1){
    while(l1 != 0){
        printf("%d %s", l1->level, l1->url);
        l1 = l1->next;
    }
}