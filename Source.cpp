#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include "Header.h"

using namespace std;

int getKey() noexcept {
    int key = _getch();
    if ((key == 0) || (key == 224)) key = _getch();
    return key;
}

void randinit(std::vector<int>& v)
{
    srand(time(NULL));
    unsigned max = rand() % 15;
    std::vector<int> vect(max);
    for (auto it = vect.begin(); it < vect.end(); it++)
    {
        *it = rand() % 201 - 100;
    }
    v = vect;
}
int getInt()
{
    int value;
    char str[256];
    while (true)
    {
        system("cls");
        std::cout << "Enter a value: ";

        try
        {
            gets_s(str, 256);
            value = std::stoi(str);
            break;
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid argument" << std::endl;
            system("pause");
        }

    }
    return value;
}
unsigned getIndex(const unsigned& max)
{
    int value;
    char str[256];
    while (true)
    {
        system("cls");
        std::cout << "Enter an Index: ";

        try
        {
            gets_s(str, 256);
            value = std::stoi(str);
            if (value < 0)
                throw - 1;
            else if (value > max - 1)
                throw 1;
            break;
        }
        catch (int error)
        {
            if (error == -1)
                std::cout << "Index can not be less than 0" << std::endl;
            else if (error == 1)
                std::cout << "Index is out of range" << std::endl;
            system("pause");
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid argument" << std::endl;
            system("pause");
        }

    }
    return static_cast<unsigned>(value);
}
stats sort(std::vector<int>& vect, stats(*f)(std::vector<int>&))
{
    stats result = f(vect);
    return result;
}

int vectorMenu(std::vector<int>& vect, const size_t& arrow, const stats& statistic)
{
    std::cout << "Vector menu" << std::endl;
    for (auto it = vect.begin(); it != vect.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "1 - Add element" << std::endl;
    std::cout << "2 - Delete element" << std::endl;
    std::cout << "3 - Randomize" << std::endl;
    std::cout << "4 - Bubble sort" << std::endl;
    std::cout << "5 - Quick sort" << std::endl;
    std::cout << "6 - Comb sort" << std::endl;
    std::cout << "7 - Exit" << std::endl;

    std::cout << std::endl;

    if (statistic.comparison_count != 0)
    {
        std::cout << "Statistic: " << statistic.comparison_count << " : " << statistic.copy_count << std::endl;
    }

    return getKey();
}

void process()
{
    std::vector<int> main_vector;
    stats statistic = { 0, 0 };
    size_t arrow = 0;
    while (true)
    {
        system("cls");
        int action = vectorMenu(main_vector, arrow, statistic);
        if (action == 49) {
            main_vector.push_back(getInt());
        }
        if (action == 50) {
            if (main_vector.size() != 0)
            {
                unsigned index = getIndex(main_vector.size());
                main_vector.erase(main_vector.begin() + index);
            }
        }
        if (action == 51) {
            randinit(main_vector);
            statistic = { 0,0 };
        }
        if (action == 52) {
            statistic = sort(main_vector, BubbleSort);
        }
        if (action == 53) {
            statistic = sort(main_vector, quick_sort);
        }
        if (action == 54) {
            statistic = sort(main_vector, comb_sort);
        }
        if (action == 55) break;
    }
    return;
}

int main()
{
    process();
    return 0;
}