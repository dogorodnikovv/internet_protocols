#ifndef FILTER_H
#define FILTER_H

#include "internet_structure.h"

internet_structure** filter(internet_structure* array[], int size, bool (*check)(internet_structure* element), int& result_size);

bool filter_protocol_by_program_name(internet_structure* element);

bool filter_protocol_by_time(internet_structure* element);

#endif