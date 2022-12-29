#include "opener.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <ctype.h>

void openLevelTextFile(int number){
    char path[100];
    char dirPath[100];
    sprintf(path, "Zest/%d/%d.txt", number, number);
    memcpy(dirPath, path, sizeof path);


    if(!isFolderExisting(dirname(dirPath))){
        char answer;
        printf("Are you sure you want create folder for level %d? [Y/n] ", number);
        answer = getchar();
        if(answer == 'Y')
            mkdir(dirPath);
        else return;
    }

    FILE *level = fopen(path, "a");
    fclose(level);

    char command[100];
    sprintf(command, "notepad %s", path);
    system(command);

}

//assumption: %d.txt without letters
void openCurrentLevelTextFile(){
    DIR *dir = opendir("Zest/.");
    struct dirent *entry;
    int current_level = 1;

    if(dir == NULL)
    {
        printf("Couldn't find current level text file");
        return;
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

    char command[100];
    sprintf(command, "notepad Zest/%d/%d.txt", current_level, current_level);
    system(command);

    closedir(dir);
}

void openLevelImage(int number){

}

void openCurrentLevelImage(){

}