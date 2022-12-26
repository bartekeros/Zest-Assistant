#include "initializePaths.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

void Initialize(){
    CreateZestFolder();
    CreateLinksFile();
}

void CreateZestFolder(){
    DIR *dir = opendir("Zest");
    if(dir == 0){
        mkdir("Zest");
        closedir(dir);
    }
    else if(ENOENT == errno){
        closedir(dir);
    }
    closedir(dir);
}

void CreateLinksFile(){
    FILE *file = fopen("Zest/links.txt", "w");
    fclose(file);
}