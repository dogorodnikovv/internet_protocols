#include "filter.h"
#include <cstring>
#include <iostream>

internet_structure** filter(internet_structure* array[], int size, bool (*check)(internet_structure* element), int& result_size) {
	internet_structure** result = new internet_structure * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool filter_protocol_by_program_name(internet_structure* element)
{
	return strcmp(element->program_name, "Skype") == 0;
}

bool filter_protocol_by_time(internet_structure* element)
{
	return element->start_time.hour > 8 ? true : false;
}