#include "opener.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <ctype.h>

extern char linksFile[];
const char gimp[] = "\"C:/Program Files/GIMP 2/bin/gimp-2.10.exe\"";

void openLevelTextFile(int number){
    char path[100];
    char dirPath[100];
    sprintf(path, "Zest/%d/%d.txt", number, number);
    memcpy(dirPath, path, sizeof path);


    if(!isFolderExisting(dirname(dirPath))) {
        char answer;
        printf("Are you sure you want create folder for level %d? [Y/n] ", number);
        answer = getchar();
        if (answer == 'Y')
            mkdir(dirPath);
        else return;

        char *url = malloc(100 * sizeof(char));
        rewind(stdin);
        do {
            printf("Enter current level url\n");
            url = getURL();
        } while (strstr(url, ".htm") == NULL); //problem with regex, so very simple check

        FILE *links = fopen(linksFile, "a");
        fprintf(links, "%d %s\n", number, url);
        fclose(links);
    }
    FILE *level = fopen(path, "a");
    fclose(level);

    char command[100];
    sprintf(command, "notepad %s", path);
    system(command);

}

void openCurrentLevelTextFile(){

    int current_level = currentLevel();

    if(current_level > 0) {
        char command[100];
        sprintf(command, "notepad Zest/%d/%d.txt", current_level, current_level);
        system(command);
    }
    else{
        fprintf(stdout, "%s\n", "None of level seems to appear in your directory.");
    }
}

void openLevelImage(int level){
    char path[100];
    char command[100];

    if(level > 0){
        sprintf(path, "Zest/%d/." , level);

        DIR *dir = opendir(path);
        struct dirent *entry;

        while((entry = readdir(dir)) != NULL){
            if(strstr(entry->d_name, ".jpg") != NULL){
                sprintf(path, "%s/%s", path, entry->d_name);
                sprintf(command, "%s %s", gimp, path);
                system(command);
            }
        }
    }
    else if(level == 0){
        sprintf(path, "Zest/%d/." , currentLevel());

        DIR *dir = opendir(path);
        struct dirent *entry;

        while((entry = readdir(dir)) != NULL){
            if(strstr(entry->d_name, ".jpg") != NULL){
                sprintf(path, "%s/%s", path, entry->d_name);
                sprintf(command, "%s %s", gimp, path);
                system(command);
            }
        }
    }
}