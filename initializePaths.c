#include "initializePaths.h"
#include "library.h"
#include <stdio.h>
#include <dirent.h>

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
    FILE *file = fopen("Zest/links.txt", "a");
    fclose(file);
}