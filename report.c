#include "report.h"


int comparator(const void * first, const void * second){
    int i = ((struct tracker*)first)->mods;
    int p = ((struct tracker*)second)->mods;
    return p - i;
}

void generateReport(){
    char cwd[255] = {0};
    printf("***************Generating report***************\n\n");

    printf("Target string: %s\nSearch begins in the currect folder %s\n\n", keyword, getcwd(cwd, sizeof(cwd)));

    int length = sizeof(track)/sizeof(track[0]);

    printf("** Search Report **\n\n");

    printf("Updates          File Name\n\n");
    for(int i = 0; i < length; i++){
        if(track[i].mods == 0){
            return;
        }
        printf("%d                %s\n\n", track[i].mods, track[i].pathName);
    }
}