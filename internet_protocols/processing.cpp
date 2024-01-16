#include <iostream>

#include "processing.h"

internet_time get_longest_time_program_name(internet_structure* array[], int size, std::string program_name)
{
    internet_time total_time = { 0, 0, 0 };

    for (int i = 0; i < size; ++i)
    {
        if (array[i]->program_name == program_name)
        {
            int hours_diff = array[i]->end_time.hour - array[i]->start_time.hour;
            int minutes_diff = array[i]->end_time.minute - array[i]->start_time.minute;
            int seconds_diff = array[i]->end_time.second - array[i]->start_time.second;

            total_time.hour += hours_diff;
            total_time.minute += minutes_diff;
            total_time.second += seconds_diff;

            if (total_time.second >= 60)
            {
                total_time.second -= 60;
                total_time.minute++;
            }

            if (total_time.minute >= 60)
            {
                total_time.minute -= 60;
                total_time.hour++;
            }
        }
    }

    return total_time;
}