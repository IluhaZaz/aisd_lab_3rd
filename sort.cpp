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
void reverse(T* a, int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(a[i], a[len - i - 1]);
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
    if (!increase) {
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
void merge_sort_right(vector<T> a1, vector<T> a2, vector<T>& res_arr, int start_indx) {
    shaker_sort(a1, 0);
    shaker_sort(a2, 0);


    int i = 0;
    int j = 0;
    int k = start_indx;

    while (i < a1.size() && j < a2.size()) {
        if (a1[i] >= a2[j]) {
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
T* vector_to_array(const vector<T>& a) {
    T* arr = new T[a.size()];
    for (int i = 0; i < a.size(); i++)
        arr[i] = a[i];
    return arr;
}

template <typename T>
vector<T> array_to_vector(const T* a, int size) {
    vector<T> v(size);
    for (int i = 0; i < size; i++)
        v[i] = a[i];
    return v;
}

template <typename T>
T* arr_by_range(T* start, T* end) {
    int len = end - start + 1;
    T* arr = new T[abs(len)];

    if (len > 0) {
        for (int i = 0; i < len; i++) {
            arr[i] = start[i];
        }
    }
    else {
        for (int i = 0; i < abs(len); i++) {
            arr[i] = end[i];
        }
        reverse(arr, abs(len));
    }
    return arr;
}


template <typename T>
vector<T> merge(vector<T> a) {

    T* arr = vector_to_array(a);

    T* arr_left_start = arr;
    T* arr_left_end = arr_left_start;

    T* arr_right_start = arr + a.size() - 1;
    T* arr_right_end = arr_right_start;

    vector<T> help(a.size());

    int n = 0;

    while (arr_left_end < arr_right_end) {
        while ((*arr_left_end < *(arr_left_end + 1)) && (arr_left_end + 1 != arr_right_end)) {
            arr_left_end++;
        }
        while ((*arr_right_end < *(arr_right_end - 1)) && (arr_right_end - 1 != arr_left_end)) {
            arr_right_end--;
        }

        if (n % 2 == 0)
        {
            vector<T> v1 = array_to_vector(arr_by_range(arr_left_start, arr_left_end), arr_left_end - arr_left_start + 1);
            vector<T> v2 = array_to_vector(arr_by_range(arr_right_end, arr_right_start), arr_right_start - arr_right_end + 1);
            merge_sort_left(v1, v2, help, arr_left_start - arr);
        }
        else {
            vector<T> v1 = array_to_vector(arr_by_range(arr_left_start, arr_left_end), arr_left_end - arr_left_start + 1);
            vector<T> v2 = array_to_vector(arr_by_range(arr_right_end, arr_right_start), arr_right_start - arr_right_end + 1);
            merge_sort_right(v1, v2, help, help.size() - v1.size() - v2.size());
        }

        arr_left_end += 1;
        arr_right_end -= 1;

        arr_left_start = arr_left_end;
        arr_right_start = arr_right_end;

        n++;
    }
    return help;
}


template <typename T>
void natural_merge_sort(vector<T>& a) {
    vector<T> a_prev;
    do {
        a_prev = a;
        a = merge(a);
    } while (a != a_prev);
}