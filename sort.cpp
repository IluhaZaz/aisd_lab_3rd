#pragma once
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
void bubble_sort(vector<T>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}


template <typename T>
void shaker_sort(vector<T>& a) {
    int left_num = 1;
    int right_num = a.size();
    while (left_num < right_num) {
        for (int i = left_num - 1; i < right_num - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        right_num--;

        for (int i = right_num - 1; i > left_num - 1; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }
        }
        left_num++;
    }
}