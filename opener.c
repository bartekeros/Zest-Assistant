#include "opener.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>

void openLevelTextFile(int number){
    char path[100];
    char dirPath[100];
    sprintf(path, "Zest/%d/%d.txt", number, number);
    memcpy(dirPath, path, sizeof path);


    if(!isFolderExisting(dirname(dirPath))){
        mkdir(dirPath);
    }

    FILE *level = fopen(path, "a");
    fclose(level);

    char command[100];
    sprintf(command, "notepad %s", path);
    system(command);

}

void openCurrentLevelTextFile(){

}

void openLevelImage(int number){

}

void openCurrentLevelImage(){

}