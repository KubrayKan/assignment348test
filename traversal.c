#include "traversal.h"
#include "text.h"

//Iterates through the files starting on the current directory
void listDirs(char * path){
    DIR * d = opendir(path);
    if(d == NULL){
        printf("System was not able to print directory %s \n", path);
        return;
    } 

    char temp[255] = {0};
    struct dirent * dir;
    while((dir = readdir(d)) != NULL){
        //If it is not a directory and it is a file that ends with .txt it will call the replacing method to replace the word
        if(dir->d_type != DT_DIR){
            char * suffix = strrchr(dir->d_name, '.');
            if(suffix && !strcmp(suffix, ".txt")){
                
                strcat(temp, path);
                strcat(temp, dir->d_name);
                replacing(temp);
                temp[0] = '\0';
            }
        }
        //If it is a directory then it calls itself recursively using the path of such directory
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