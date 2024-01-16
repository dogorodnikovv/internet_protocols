#include <iostream>
#include <set>

#include "internet_structure.h"
#include "file_reader.h"
#include "filter.h"
#include "sort.h"
#include "processing.h"

using namespace std;

void output(internet_structure* item)
{
    cout << item->start_time.hour << ':';
    cout << item->start_time.minute << ':';
    cout << item->start_time.second << ' ';
    cout << item->end_time.hour << ':';
    cout << item->end_time.minute << ':';
    cout << item->end_time.second << ' ';
    cout << item->recieved << ' ';
    cout << item->send << ' ';
    cout << item->program_name;
    cout << '\n';
}

void show_menu()
{
    cout << "------Меню------" << '\n';
    cout << "1. Вывод всех результатов" << '\n';
    cout << "2. Вывести протокол использования сети Интернет программой Skype." << '\n';
    cout << "3. Вывести протокол использования сети Интернет после 8:00:00." << '\n';
    cout << "4. Сортировка вставками по убыванию времени использования сети Интернет." << '\n';
    cout << "5. Сортировка вставками по возрастанию названия программы." << '\n';
    cout << "6. Быстрая сортировка по убыванию времени использования сети Интернет." << '\n';
    cout << "7. Быстрая сортировка по возрастанию названия программы." << '\n';
    cout << "8. Вывести суммарное время использования сети Интернет заданной программой (вводится пользователем)." << '\n';
    cout << "Для завершения введите -1" << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #5. Протокол работы в Интернет\n";
    cout << "Огородников Дмитрий Олегович\n";
    cout << '\n';
    internet_structure* protocols[MAX_FILE_ROWS_COUNT];
    internet_structure** protocol_filter = new internet_structure * [0];
    set<string> program_names;
    internet_time longest_time_element;
    int size;
    int filter_size = 0;
    string program_name = "";
    try {
        readFromFile("data.txt", protocols, size);
        show_menu();
        int choise;
        cin >> choise;
        while (choise != -1)
        {
            switch (choise) {
            case 1:
                system("cls");
                cout << "----------Вывод всех результатов----------" << '\n';
                for (int i = 0; i < size; i++)
                {
                    output(protocols[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 2:
                system("cls");
                cout << "----------Вывести протокол использования сети Интернет программой Skype.----------" << '\n';
                protocol_filter = filter(protocols, size, filter_protocol_by_program_name, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(protocol_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 3:
                system("cls");
                cout << "----------Вывести протокол использования сети Интернет после 8:00:00.----------" << '\n';
                protocol_filter = filter(protocols, size, filter_protocol_by_time, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(protocol_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 4:
                system("cls");
                cout << "----------Сортировка вставками по убыванию времени использования сети Интернет----------" << '\n';
                insertion_sort(protocols, size, compare_by_time);
                for (int i = 0; i < size; i++)
                {
                    output(protocols[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 5:
                system("cls");
                cout << "----------Сортировка вставками по возрастанию названия программы----------" << '\n';
                insertion_sort(protocols, size, compare_by_program_name);
                for (int i = 0; i < size; i++)
                {
                    output(protocols[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 6:
                system("cls");
                cout << "----------Быстрая сортировка по убыванию времени использования сети Интернет----------" << '\n';
                quick_sort(protocols, size, compare_by_time);
                for (int i = 0; i < size; i++)
                {
                    output(protocols[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 7:
                system("cls");
                cout << "----------Быстрая сортировка по возрастанию названия программы----------" << '\n';
                quick_sort(protocols, size, compare_by_program_name);
                for (int i = 0; i < size; i++)
                {
                    output(protocols[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 8:
                system("cls");
                cout << "----------Вывод сумарного времени----------" << '\n';
                cout << "Введите название программы с учётом регистра" << '\n';
                for (int i = 0; i < size; i++) {
                    program_names.insert(protocols[i]->program_name);
                }
                for (string name : program_names)
                {
                    cout << name << '\n';
                }
                cin >> program_name;
                longest_time_element = get_longest_time_program_name(protocols, size, program_name);
                cout << longest_time_element.hour << ":" << longest_time_element.minute << ":" << longest_time_element.second;
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            default:
                cout << "Нет такого пункта!" << '\n';
                show_menu();
                cin >> choise;
                break;
            }
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
