#ifndef INTERNET_STRUCTURE_H
#define INTERNET_STRUCTURE_H

#include <string>

#include "constants.h"

struct internet_time
{
    int hour;
    int minute;
    int second;
};

struct internet_structure
{
    internet_time start_time;
    internet_time end_time;
    int recieved;
    int send;
    char program_name[MAX_STRING_SIZE];
};

#endif