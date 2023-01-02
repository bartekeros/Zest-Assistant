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

bool isLevelExisting(int level){
    char combinePath[100];
    sprintf(combinePath, "Zest/%d", level);
    if(isFolderExisting(combinePath))
        return true;
    return false;
}

char* getURL(){
    char *url = malloc(Max_Url_Size * sizeof (char));
    fgets(url, Max_Url_Size, stdin);
    url[strcspn(url, "\n")] = 0;
    return url;
}

//assumption: %d.txt without letters
int currentLevel(){
    DIR *dir = opendir("Zest/.");
    struct dirent *entry;
    int current_level = 0;

    if(dir == NULL)
    {
        printf("Couldn't find current level text file");
        closedir(dir);
        return 0;
    }

    char level_num[4];
    while((entry = readdir(dir)) != NULL){
        int i = 0;
        while(isdigit(entry->d_name[i]) > 0){
            level_num[i] = entry->d_name[i];
            i++;
        }
        if(atoi(level_num) > current_level) current_level = atoi(level_num);
    }
    closedir(dir);
    return current_level;
}