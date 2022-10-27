#include "text.h"

static int numTrackers = 0;

void replacing(char * path){
    //Buffer where the lines will be stored before being analyzed
    char buffer[1000] = {0};

    //Opens the file to be inspected and creates a temp file that will later replace the original one with the modifications
    FILE *fp;
    FILE *fTemp;

    fp = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w");
    
    if(fp == NULL || fTemp == NULL){
        printf("\nCan't to open file.\n");
        printf("Please make sure you have permissions in this directory or that you have the right path.\n");
        exit(0);
    }

    //Stores the file in the tracker
    strcpy(track[numTrackers].pathName, path);

    //Iterates through the file
    while ((fgets(buffer, 1000, fp)) != NULL){

        //Capializes the instances of the word found in the sentence/buffer
        capitalize(buffer);

        //Copies the new sentece into the temp file
        fputs(buffer, fTemp);
    }

    //Closes the files
    fclose(fp);
    fclose(fTemp);

    //Removes the origianl file
    remove(path);

    //Makes the temporary file become the file to be replaced
    rename("replace.tmp", path);

    //Increases the static variable to move indexes in the tracker array
    numTrackers++;
}

void capitalize(char * sentence){
    
    //Position will store a pointer to the beginning of the keywords in the sentence
    char * position;

    char temp[1000] = {0};
    int index = 0;
    int length = strlen(keyword);

    while((position = strstr(sentence, keyword)) != NULL){
        //Increases the modifications to the file when word is found
        track[numTrackers].mods = track[numTrackers].mods + 1;

        //Temporarly stores the original sentence
        strcpy(temp, sentence);

        //Terminates the sentence at the word
        index = position - sentence;
        sentence[index] = '\0';

        //Appends the new capitalized word to the cut off sentence
        strcat(sentence, newKeyword);

        //Appends the rest of the sentence after the cut off sentence + newkeyword
        strcat(sentence, temp + index + length);
    }
}