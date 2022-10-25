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

extern char keyword[100];

struct tracker{
    char pathName [100];
    int mods;
};

int comparator(const void * first, const void * second);

void generateReport();


extern struct tracker track [20];

#endif

