#include "opener.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <pthread.h>

extern char linksFile[];
const char gimp[] = "\"C:/Program Files/GIMP 2/bin/gimp-2.10.exe\"";

int createLevel(char*, int);

void openLevelTextFile(int number){
    char path[100];
    char dirPath[100];
    sprintf(path, "Zest/%d/%d.txt", number, number);
    memcpy(dirPath, path, sizeof path);

    if(!isFolderExisting(dirname(dirPath))) {
        if(createLevel(dirPath, number) == 0)
            return;

    }

    //create .txt file if doesn't exist
    FILE *level = fopen(path, "a");
    fclose(level);

    char command[100];
    sprintf(command, "start notepad %s", path);
    system(command);

}

//1 - success
//0 - failure
int createLevel(char* dirPath, int number){
    char answer;
    printf("Are you sure you want to create folder for level %d? [Y/n] ", number);
    answer = getchar();
    if (answer == 'Y')
        mkdir(dirPath);
    else return 0;

    char *url = malloc(100 * sizeof(char));
    rewind(stdin);
    do {
        printf("Enter current level url\n");
        url = getURL();
    } while (strstr(url, ".htm") == NULL); //problem with regex, so very simple check

    FILE *links = fopen(linksFile, "a");
    fprintf(links, "%d %s\n", number, url);
    fclose(links);

    return 1;
}

void openCurrentLevelTextFile(){

    int current_level = currentLevel();

    if(current_level > 0) {
        char command[100];
        sprintf(command, "start notepad Zest/%d/%d.txt", current_level, current_level);
        system(command);
    }
    else{
        fprintf(stdout, "%s\n", "None of levels seems to appear in your directory.");
    }
}

void openLevelImage(int level){
    char path[100];
    char command[100];
    int counter = 0;

    if(level == 0)
        level = currentLevel();
    if(level > 0){
        sprintf(path, "Zest/%d/." , level);

        DIR *dir = opendir(path);
        struct dirent *entry;

        while((entry = readdir(dir)) != NULL){
            if(strstr(entry->d_name, ".jpg") != NULL){
                sprintf(path, "%s/%s", path, entry->d_name);
                sprintf(command, "start \"\" %s \"%s\"", gimp, path);
                system(command);
                sprintf(path, "Zest/%d/." , level);
                counter++;
            }
        }
    }
    if(counter == 0){
        printf("There are no images in %d level\n", level);
    }
}

void showLinks(){
    FILE *links = fopen(linksFile, "r");
    char ch;
    while((ch = getc(links)) != EOF)
        putc(ch, stdout);
    fclose(links);
}

//accepts only the first occurrence of the pattern
void openLevelInBrowser(int level){
    FILE *links = fopen(linksFile, "r");
    int counter = 0;

    if(level == 0)
        level = currentLevel();
    if(level > 0){
        char line[100];
        char substring[10];
        sprintf(substring, "%d ", level);
        while(fgets(line, 100, links)){
            if(strstr(line, substring) != NULL){
                char *token = strtok(line, " ");
                token = strtok(NULL, " ");

                char command[100];
                sprintf(command, "explorer \"%s\"", token);
                system(command);
                counter++;

                fclose(links);
                return;
            }
        }
    }


    if(counter == 0){
        printf("Couldn't open %d level in browser\n", level);
    }
}