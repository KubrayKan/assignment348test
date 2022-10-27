#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "text.h"
#include "traversal.h"
#include "report.h"

//Global variables that store the words to be replaced in order to avoid passing arguments
char keyword [100] = {0};
char newKeyword [100] = {0};

//Global variable to track the files modified and modifications of them. It is set to maximum 20 files because I judged that it was a fair quantity. If needed more, just change the number
struct tracker track [20];

int main(int argc, char* argv[]){
    
    int n = strlen(argv[argc-1]);

    if(n > 98){
        printf("The keyword you entered exceed the length of 100, this is most likely a mistake and the program won't execute");
        return 0;
    }

    //Stores the argument. This code assumes that the word that we want to replace is the last argument passed to the command
    if (argc > 1)
    {
        strcpy(keyword, argv[argc-1]);
        for(int i = 0; i < strlen(keyword); i++){
            newKeyword[i] = toupper(keyword[i]);
        }
    }
    
    //If the word entered was already capitalized there is no point on running the code
    if (!strcmp(keyword, newKeyword)) {
        printf("The word you entered is already in capital form, the code has no objective then\n");
        return 0;
    }

    //If there is a keyword that's not empty, start executing the code
    if(keyword[0] != '\0'){
        listDirs("./");
    }else{
        printf("Your word is empty\n");
        return 0;
    }

    //Sorts the list of modified files in descending order
    int size = sizeof(track)/sizeof(track[0]);
    qsort((void*) track, size, sizeof(track[0]), comparator);
    
    generateReport();

    return 0;
}