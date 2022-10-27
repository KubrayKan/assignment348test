#ifndef REPORT_H
#define REPORT_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

//Lets this file know of the global variable keyword
extern char keyword[100];

//Tracker struct that tracks the filename in terms of relative path and the number of modification done to it
struct tracker{
    char pathName [100];
    int mods;
};

//Provides a way to compare tracker objects
int comparator(const void * first, const void * second);

void generateReport();


extern struct tracker track [20];

#endif

