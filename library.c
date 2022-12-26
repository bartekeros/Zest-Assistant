#include "library.h"
#include <ctype.h>
#include <stdbool.h>

bool isNumber(char *number[]){
    int i = 0;
    while(number[i]){
        if(!isdigit((int)number[i]))
            return false;
        i++;
    }
    return true;
}