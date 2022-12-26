#include <stdio.h>
#include <string.h>
#include "help.h"
#include "initializePaths.h"
#include "library.h"

int main(int argc, char *argv[]){
    Initialize();
    if(argc == 2){
        if(!strcmp(argv[1],"-h")){
            PrintHelp();
        }
        else if(!strcmp(argv[1], "-E"))
        {

        }
    }
    else if(argc == 3){
        if(!strcmp(argv[1],"-E") && isNumber(argv[2])){

        }
    }

    return 0;
}