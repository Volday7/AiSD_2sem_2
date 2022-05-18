#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

template<typename T>
void Swap(T& i, T& j) {
    T temp = i;
    i = j;
    j = temp;
}

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};

template<typename T>
stats BubbleSort(vector<T>& a) {
    stats res;
    for (size_t i = 0; i < a.size() - 1; i++)
    {
        for (size_t j = 0; j < a.size() - i - 1; j++)
        {
            res.comparison_count++;
            if (a[j] > a[j + 1])
            {
                
                res.copy_count++;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return res;
}

template<typename T>
stats quick_sort_(vector<T>& vec, size_t left, size_t right) {
    stats stat;
    long long i = left, j = right;
    T pivot = vec[left];
    stat.copy_count++;

    while (i < j) // ���� ������� �� ���������
    {
        stat.comparison_count++;
        while ((vec[j] >= pivot) && (i < j)) {
            stat.comparison_count++;
            j--; // �������� ������ ������� ���� ������� [j] ������ [pivot]
        }
        stat.comparison_count++; //+1 ��������� ��� ������ �� �����

        stat.comparison_count++;
        if (i != j) // ���� ������� �� ����������
        {
            stat.copy_count++;
            vec[i] = vec[j]; // ���������� ������� [j] �� ����� ������������
            i++; // �������� ����� ������� ������
        }

        while ((vec[i] <= pivot) && (i < j)) {
            stat.comparison_count++; //+1
            i++; // �������� ����� ������� ���� ������� [i] ������ [pivot]
        }
        stat.comparison_count++; //+1 ��������� ��� ������ �� �����

        stat.comparison_count++;
        if (i != j) // ���� ������� �� ����������
        {
            stat.copy_count++;
            vec[j] = vec[i]; // ���������� ������� [i] �� ����� [j]
            j--; // �������� ������ ������� �����
        }
    }
    stat.comparison_count++;//+1 ��������� ��� ������ �� �����

    stat.copy_count++;
    vec[i] = pivot; // ������ ����������� ������� �� �����
    pivot = i;

    stat.comparison_count++;
    if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
        quick_sort_(vec, left, pivot - 1);

    stat.comparison_count++; //+1 ��������� ��� ������ �� �����
    if (right > pivot)
        quick_sort_(vec, pivot + 1, right);

    return stat;
}

template<typename T>
stats quick_sort(vector<T>& data) { if (!data.empty()) return quick_sort_(data, 0, data.size() - 1); };

template<typename T>
stats comb_sort(vector<T>& data)
{
    const double factor = 1.2473309; // ������ ����������
    stats stat;
    int step = data.size() - 1; // ��� ����������

    //��������� �������� �����, ����� step==1 ������������ ������ ������� ���������� ���������
    while (step >= 1) {
        for (int i = 0; i + step < data.size(); i++) {

            stat.comparison_count++;
            if (data[i] > data[i + step]) {

                stat.copy_count++;
                Swap(data[i], data[i + step]);
            }
        }
        step /= factor;
    }
    return stat;
};

template<typename T>
void print(vector<T>& data) {
    for (auto i = data.begin(); i != data.end(); ++i) cout << *i << " ";
    cout << endl;
};
