#include "traversal.h"
#include "text.h"

void listDirs(char * path){
    DIR * d = opendir(path);
    if(d == NULL){
        printf("System was not able to print directory %s \n", path);
        return;
    } 

    char temp[255] = {0};
    struct dirent * dir;
    while((dir = readdir(d)) != NULL){
        if(dir->d_type != DT_DIR){
            char * suffix = strrchr(dir->d_name, '.');
            if(suffix && !strcmp(suffix, ".txt")){
                
                strcat(temp, path);
                strcat(temp, dir->d_name);
                replacing(temp);
                temp[0] = '\0';
            }
        }
        else if(dir->d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0){
            char new_path[255] = {0};
            strcat(new_path, path);
            strcat(new_path, dir->d_name);
            strcat(new_path, "/");
            listDirs(new_path);
        }
        
    }
    closedir(d);
}