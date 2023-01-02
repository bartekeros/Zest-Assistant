#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "help.h"
#include "initializePaths.h"
#include "library.h"
#include "opener.h"
#include "image.h"
#include "sort.h"

const char linksFile[] = "Zest/links.txt";

int main(int argc, char *argv[]){
    Initialize();
    sortLinksFile();
    if(argc == 1){
        PrintHelp();
    }
    else if(argc == 2){
        if(!strcmp(argv[1],"-h")){
            PrintHelp();
        }
        else if(!strcmp(argv[1], "-E"))
        {
            openCurrentLevelTextFile();
        }
        else if(!strcmp(argv[1], "-I"))
        {
            openLevelImage(0);
        }
        else if(!strcmp(argv[1], "-IE"))
        {
            openCurrentLevelTextFile();
            openLevelImage(0);
        }
        else if(!strcmp(argv[1], "-L")){
            showLinks();
        }
        else if(!strcmp(argv[1], "-O")){
            openLevelInBrowser(0);
        }
    }
    else if(argc == 3){
        if(!strcmp(argv[1],"-E") && isNumber(argv[2])){
            openLevelTextFile(atoi(argv[2]));
        }
        else if(!strcmp(argv[1], "-A") && !access(argv[2], F_OK)){
            importImage(argv[2], 0);
        }
        else if(!strcmp(argv[1], "-I") && isNumber(argv[2]))
        {
            openLevelImage(atoi(argv[2]));
        }
        else if(!strcmp(argv[1], "-IE") && isNumber(argv[2])){
            openLevelTextFile(atoi(argv[2]));
            openLevelImage(atoi(argv[2]));
        }
        else if(!strcmp(argv[1], "-O") && isNumber(argv[2])){
            openLevelInBrowser(atoi(argv[2]));
        }
    }
    else if(argc == 4){
        if(!strcmp(argv[1], "-A") && !access(argv[2], F_OK) && isNumber(argv[3])){
            importImage(argv[2], atoi(argv[3]));
        }
    }
    return 0;
}