#include "library.h"
#include <ctype.h>
#include <stdbool.h>
#include <dirent.h>
#include <errno.h>

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