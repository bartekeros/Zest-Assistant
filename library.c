#include "library.h"
#include <ctype.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <malloc.h>

#define Max_Url_Size 100

bool isNumber(char number[]){
    int i = 0;
    while(number[i]){
        if(!isdigit((int)number[i]))
            return false;
        i++;
    }
    return true;
}

bool isFolderExisting(char filename[]){
    DIR *dir = opendir(filename);
    if(dir == 0){
        closedir(dir);
        return false;
    }
    closedir(dir);
    return true;
}

char* getURL(){
    char *url = malloc(Max_Url_Size * sizeof (char));
    fgets(url, Max_Url_Size, stdin);
    url[strcspn(url, "\n")] = 0;
    return url;
}