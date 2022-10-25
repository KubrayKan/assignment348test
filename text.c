#include "text.h"

static int numTrackers = 0;

void replacing(char * path){
    printf("Inside: %s\n", path);
    char c;
    char buffer[1000] = {0};

    FILE *fp;
    FILE *fTemp;

    fp = fopen(path, "r");
    //fp = fopen("file.txt", "r");
    
    fTemp = fopen("replace.tmp", "w");

    //./secondary/secondaryTry.txt
    
    if(fp == NULL || fTemp == NULL){
        printf("\nCan't to open file.\n");
        printf("Please make sure you have permissions in this directory or that you have the right path.\n");
        exit(0);
    }

    strcpy(track[numTrackers].pathName, path);

    while ((fgets(buffer, 1000, fp)) != NULL){

        capitalize(buffer);

        fputs(buffer, fTemp);
    }

    // c = fgetc(fp);
    // while(c != EOF){
    //     printf("%c", c);
    //     c = fgetc(fp);
    // }

    printf("\n");
    fclose(fp);
    fclose(fTemp);

    remove(path);
    //remove("file.txt");
    rename("replace.tmp", path);
    //rename("replace.tmp", "file.txt");
    numTrackers++;
}

void capitalize(char * sentence){
    
    char * position;
    char temp[1000] = {0};
    int index = 0;
    int length = strlen(keyword);

    while((position = strstr(sentence, keyword)) != NULL){
        track[numTrackers].mods = track[numTrackers].mods + 1;

        strcpy(temp, sentence);

        index = position - sentence;
        
        sentence[index] = '\0';

        strcat(sentence, newKeyword);

        strcat(sentence, temp + index + length);
    }
}