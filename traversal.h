#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "report.h"


void listDirs(char * path);

#endif