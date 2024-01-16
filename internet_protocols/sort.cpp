#include "sort.h"
#include <iostream>

using namespace std;

int time_difference_in_seconds(const internet_time& time1, const internet_time& time2)
{
    int seconds1 = time1.hour * 3600 + time1.minute * 60 + time1.second;
    int seconds2 = time2.hour * 3600 + time2.minute * 60 + time2.second;

    return seconds2 - seconds1;
}

int compare_by_time(internet_structure* first, internet_structure* second)
{
    if (time_difference_in_seconds(first->end_time, first->start_time) > time_difference_in_seconds(second->end_time, second->start_time)) {
        return 1;
    }
    else if (time_difference_in_seconds(first->end_time, first->start_time) == time_difference_in_seconds(second->end_time, second->start_time)) {
        return 0;
    }
    return -1;
}

int compare_by_program_name(internet_structure* first, internet_structure* second)
{
    if (strcmp(first->program_name, second->program_name) == 0) {
        if ((first->recieved + first->send) < (second->recieved + second->send)) {
            return 1;
        }
        else if ((first->recieved + first->send) == (second->recieved + second->send)) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else if (strcmp(first->program_name, second->program_name) > 0) {
        return 1;
    }
    return -1;
}

void insertion_sort(internet_structure* array[], int size, int (*check)(internet_structure* first, internet_structure* second)) {
    for (int i = 1; i < size; i++) {
        internet_structure* key = array[i];
        int j = i - 1;

        while (j >= 0 && check(array[j], key) > 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

void swap(internet_structure*& first, internet_structure*& second)
{
    internet_structure* temp = first;
    first = second;
    second = temp;
}

int partition(internet_structure* array[], int size, int (*check)(internet_structure* first, internet_structure* second))
{
    internet_structure* pivot = array[size - 1];
    int i = -1;

    for (int j = 0; j < size - 1; j++)
    {
        if (check(array[j], pivot) <= 0)
        {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[size - 1]);
    return i + 1;
}

void quick_sort(internet_structure* array[], int size, int (*check)(internet_structure* first, internet_structure* second))
{
    if (size > 1)
    {
        int pivotIndex = partition(array, size, check);

        quick_sort(array, pivotIndex, check);
        quick_sort(array + pivotIndex + 1, size - pivotIndex - 1, check);
    }
}