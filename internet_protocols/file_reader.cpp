#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

internet_time convert_time(char* str)
{
    internet_time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.second = atoi(str_number);
    return result;
}


void readFromFile(const char* file_name, internet_structure* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            internet_structure* item = new internet_structure;
            file >> tmp_buffer;
            item->start_time = convert_time(tmp_buffer);
            file >> tmp_buffer;
            item->end_time = convert_time(tmp_buffer);
            file >> item->recieved;
            file >> item->send;
            file.read(tmp_buffer, 1); 
            file.getline(item->program_name, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка чтения файла";
    }
}