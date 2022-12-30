#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "help.h"
#include "initializePaths.h"
#include "library.h"
#include "opener.h"

const char linksFile[] = "Zest/links.txt";

int main(int argc, char *argv[]){
    Initialize();
    if(argc == 2){
        if(!strcmp(argv[1],"-h")){
            PrintHelp();
        }
        else if(!strcmp(argv[1], "-E"))
        {
            openCurrentLevelTextFile();
        }
    }
    else if(argc == 3){
        if(!strcmp(argv[1],"-E") && isNumber(argv[2])){
            openLevelTextFile(atoi(argv[2]));
        }
    }

    return 0;
}