#ifndef SORT_H
#define SORT_H

#include "internet_structure.h"

int compare_by_time(internet_structure* first, internet_structure* second);

int compare_by_program_name(internet_structure* first, internet_structure* second);

void insertion_sort(internet_structure* array[], int size, int (*check)(internet_structure* first, internet_structure* second));

void quick_sort(internet_structure* array[], int size, int (*check)(internet_structure* first, internet_structure* second));

#endif