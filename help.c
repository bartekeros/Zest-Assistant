#include <stdio.h>
#include "help.h"

void PrintHelp(){
FILE *file = fopen("help.txt", "r");

char ch;
while((ch = getc(file)) != EOF){
    printf("%c", ch);
}

fclose(file);
}