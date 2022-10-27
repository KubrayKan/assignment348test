#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "report.h"

//Global Variables
extern char keyword[100];
extern char newKeyword[100];
extern struct tracker track [20];

void replacing(char * path);
void capitalize(char * sentence);

#endif