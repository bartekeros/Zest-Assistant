#include "initializePaths.h"
#include "library.h"
#include <stdio.h>
#include <dirent.h>

extern char linksFile[];

void Initialize(){
    CreateZestFolder();
    CreateLinksFile();
}

void CreateZestFolder(){
    if(isFolderExisting("Zest") == false){
        mkdir("Zest");
    }
}

void CreateLinksFile(){
    FILE *file = fopen(linksFile, "a");
    fclose(file);
}