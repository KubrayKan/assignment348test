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

char keyword [100] = {0};
char newKeyword [100] = {0};
struct tracker track [20];

int main(int argc, char* argv[]){
    
    // for(int i =0; i < argc; i++){
    //     printf("%s\n", argv[i]);
    // }

    // printf("%s", argv[argc-1]);

    int n = strlen(argv[argc-1]);

    if(n > 98){
        printf("The keyword you entered exceed the length of 100, this is most likely a mistake and the program won't execute");
        return 0;
    }

    // printf("%d", argc);

    if (argc > 1)
    {
        strcpy(keyword, argv[argc-1]);
        for(int i = 0; i < strlen(keyword); i++){
            newKeyword[i] = toupper(keyword[i]);
        }
    }
    
    // char filename[100];
    // char c;

    // FILE *fp;
    // fp = fopen("./secondary/secondaryTry.txt", "r");

    // if(fp == NULL){
    //     printf(" error");
    //     printf("%d\n", errno);
    //     exit(0);
    // }

    // c = fgetc(fp);
    // while(c != EOF){
    //     printf("%c", c);
    //     c = fgetc(fp);
    // }

    // // fclose(fp);
    // printf("%s\n", keyword);
    if(keyword[0] != '\0'){
        listDirs("./");
    }

    // struct tracker track [8] = {0};
    // track[8].mods = 0;
    // strcpy(track[0].pathName, "Jeff");
    // track[0].mods = 3;
    
    // strcpy(track[1].pathName, "Todd");
    // track[1].mods = 6;
    
    // strcpy(track[2].pathName, "Lucas");
    // track[2].mods = 8;

    // for(int i = 0; i < 20; i++){
    //     printf("this is : %s\n With %d mods\n", track[i].pathName, track[i].mods);
    // }

    int size = sizeof(track)/sizeof(track[0]);
    qsort((void*) track, size, sizeof(track[0]), comparator);
    
    // for(int i = 0; i < 6; i++){
    //     printf("After this is : %s\n With %d mods\n", track[i].pathName, track[i].mods);
    // }

    generateReport();

    return 0;
}