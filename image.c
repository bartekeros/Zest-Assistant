#include <stdio.h>
#include "image.h"
#include "library.h"
#include <stdlib.h>
#include <libgen.h>

//Kind of overloading
void importImage(char *path, int level) {
    char command[100];
    if (level > 0) {
        if(!isLevelExisting(level)){
            printf("level %d doesn't exist in your directory", level);
            return;
        }
        sprintf(command, "move %s Zest/%d/%s", path, level, basename(path));
        system(command);
    }
    else if(level == 0){
        sprintf(command, "move %s Zest/%d/%s", path, currentLevel(), basename(path));
        system(command);
    }
}