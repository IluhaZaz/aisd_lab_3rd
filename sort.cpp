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
void reverse(vector<T>& a) {
    for (int i = 0; i < a.size() / 2; i++) {
        swap(a[i], a[a.size() - i - 1]);
    }
}


template <typename T>
void shaker_sort(vector<T>& a, bool increase) {
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
    if(!increase) {
        reverse(a);
    }
}


template <typename T>
void merge_sort_left(vector<T> a1, vector<T> a2, vector<T>& res_arr, int start_indx) {
    shaker_sort(a1, 1);
    shaker_sort(a2, 1);


    int i = 0;
    int j = 0;
    int k = start_indx;

    while (i < a1.size() && j < a2.size()) {
        if (a1[i] <= a2[j]) {
            res_arr[k] = a1[i];
            k++;
            i++;
        }
        else {
            res_arr[k] = a2[j];
            k++;
            j++;
        }
    }
    while (i < a1.size()) {
        res_arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < a2.size()) {
        res_arr[k] = a2[j];
        j++;
        k++;
    }
}


template <typename T>
void merge_sort_right(vector<T> a1, vector<T> a2, vector<T>& res_arr, int end_indx) {
    shaker_sort(a1, 0);
    shaker_sort(a2, 0);


    int i = 0;
    int j = 0;
    int k = end_indx;

    while (i < a1.size() && j < a2.size()) {
        if (a1[i] >= a2[j]) {
            res_arr[k] = a1[i];
            k--;
            i++;
        }
        else {
            res_arr[k] = a2[j];
            k--;
            j++;
        }
    }
    while (i < a1.size()) {
        res_arr[k] = a1[i];
        i++;
        k--;
    }
    while (j < a2.size()) {
        res_arr[k] = a2[j];
        j++;
        k--;
    }
}


template <typename T>
void natural_merge_sort(vector<T> a) {
    vector<T>b(a.size());

    int a_start_indx = 0;
    int a_end_indx = a.size() - 1;

    int b_start_indx = 0;
    int b_end_indx = b.size() - 1;
    
    while (a_start_indx < a_end_indx) {

    }
}