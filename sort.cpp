#pragma once
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>


using namespace std;


struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};



template <typename T>
stats bubble_sort(vector<T>& a) {

    stats s;

    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                s.comparison_count += 1;
                swap(a[j], a[j + 1]);
            }
    return s;
}


template <typename T>
void reverse(vector<T>& a, stats& s) {
    for (int i = 0; i < a.size() / 2; i++) {
        s.comparison_count += 1;
        swap(a[i], a[a.size() - i - 1]);
    }
}


template <typename T>
void reverse(T* a, int len, stats& s) {
    for (int i = 0; i < len / 2; i++) {
        s.comparison_count += 1;
        swap(a[i], a[len - i - 1]);
    }
}


template <typename T>
stats shaker_sort(vector<T>& a, bool increase) {

    stats s;

    int left_num = 1;
    int right_num = a.size();
    while (left_num < right_num) {
        s.comparison_count += 1;
        for (int i = left_num - 1; i < right_num - 1; i++) {
            s.comparison_count += 1;
            if (a[i] > a[i + 1]) {
                s.comparison_count += 1;
                swap(a[i], a[i + 1]);
            }
        }
        right_num--;

        for (int i = right_num - 1; i > left_num - 1; i--) {
            s.comparison_count += 1;
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                s.comparison_count += 1;
            }
        }
        left_num++;
    }
    if (!increase) {
        s.comparison_count += 1;
        reverse(a, s);
    }
    return s;
}


template <typename T>
stats merge_sort_left(vector<T> a1, vector<T> a2, vector<T>& res_arr, int start_indx) {

    stats s;

    s.copy_count += 2;

    {
        stats s1 = shaker_sort(a1, 1);
        stats s2 = shaker_sort(a2, 1);

        s.comparison_count = s.comparison_count + s1.comparison_count + s2.comparison_count;
        s.copy_count = s.copy_count + s1.copy_count + s2.copy_count;
    }


    int i = 0;
    int j = 0;
    int k = start_indx;

    while (i < a1.size() && j < a2.size()) {
        s.comparison_count += 1;
        if (a1[i] <= a2[j]) {
            s.comparison_count += 1;
            res_arr[k] = a1[i];
            k++;
            i++;
        }
        else {
            s.comparison_count += 1;
            res_arr[k] = a2[j];
            k++;
            j++;
        }
    }
    while (i < a1.size()) {
        s.comparison_count += 1;
        res_arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < a2.size()) {
        s.comparison_count += 1;
        res_arr[k] = a2[j];
        j++;
        k++;
    }

    return s;
}


template <typename T>
stats merge_sort_right(vector<T> a1, vector<T> a2, vector<T>& res_arr, int start_indx) {
    
    stats s;

    s.copy_count += 2;


    {
        stats s1 = shaker_sort(a1, 0);
        stats s2 = shaker_sort(a2, 0);

        s.comparison_count = s.comparison_count + s1.comparison_count + s2.comparison_count;
        s.copy_count = s.copy_count + s1.copy_count + s2.copy_count;
    }


    int i = 0;
    int j = 0;
    int k = start_indx;

    while (i < a1.size() && j < a2.size()) {
        s.comparison_count += 1;
        if (a1[i] >= a2[j]) {
            s.comparison_count += 1;
            res_arr[k] = a1[i];
            k++;
            i++;
        }
        else {
            s.comparison_count += 1;
            res_arr[k] = a2[j];
            k++;
            j++;
        }
    }
    while (i < a1.size()) {
        s.comparison_count += 1;
        res_arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < a2.size()) {
        s.comparison_count += 1;
        res_arr[k] = a2[j];
        j++;
        k++;
    }

    return s;
}


template <typename T>
T* vector_to_array(const vector<T>& a, stats& s) {
    T* arr = new T[a.size()];
    for (int i = 0; i < a.size(); i++)
    {
        s.comparison_count += 1;
        arr[i] = a[i];
    }
    return arr;
}

template <typename T>
vector<T> array_to_vector(const T* a, int size, stats& s) {
    vector<T> v(size);
    for (int i = 0; i < size; i++)
    {
        s.comparison_count += 1;
        v[i] = a[i];
    }
    return v;
}

template <typename T>
T* arr_by_range(T* start, T* end, stats& s) {
    int len = end - start + 1;
    T* arr = new T[abs(len)];

    if (len > 0) {
        s.comparison_count == 1;
        for (int i = 0; i < len; i++) {
            s.comparison_count == 1;
            arr[i] = start[i];
        }
    }
    else {
        s.comparison_count == 1;
        for (int i = 0; i < abs(len); i++) {
            s.comparison_count == 1;
            arr[i] = end[i];
        }
        reverse(arr, abs(len), s);
    }
    return arr;
}


template <typename T>
vector<T> merge(vector<T> a, stats& s) {
    s.copy_count += 1;

    T* arr = vector_to_array(a, s);

    T* arr_left_start = arr;
    T* arr_left_end = arr_left_start;

    T* arr_right_start = arr + a.size() - 1;
    T* arr_right_end = arr_right_start;

    vector<T> help(a.size());

    int n = 0;

    while (arr_left_end < arr_right_end) {
        s.comparison_count += 1;
        while ((*arr_left_end < *(arr_left_end + 1)) && (arr_left_end + 1 != arr_right_end)) {
            s.comparison_count += 2;
            arr_left_end++;
        }
        while ((*arr_right_end < *(arr_right_end - 1)) && (arr_right_end - 1 != arr_left_end)) {
            s.comparison_count += 2;
            arr_right_end--;
        }

        if (n % 2 == 0)
        {
            s.comparison_count += 1;
            vector<T> v1 = array_to_vector(arr_by_range(arr_left_start, arr_left_end, s), arr_left_end - arr_left_start + 1, s);
            vector<T> v2 = array_to_vector(arr_by_range(arr_right_end, arr_right_start, s), arr_right_start - arr_right_end + 1, s);
            merge_sort_left(v1, v2, help, arr_left_start - arr);
        }
        else {
            s.comparison_count += 1;
            vector<T> v1 = array_to_vector(arr_by_range(arr_left_start, arr_left_end, s), arr_left_end - arr_left_start + 1, s);
            vector<T> v2 = array_to_vector(arr_by_range(arr_right_end, arr_right_start, s), arr_right_start - arr_right_end + 1, s);
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
stats natural_merge_sort(vector<T>& a) {

    stats s;

    vector<T> a_prev;
    do {
        a_prev = a;
        a = merge(a, s);
    } while (a != a_prev);

    return s;
}


std::uniform_int_distribution<int> getDice(std::true_type)
{
    return std::uniform_int_distribution<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}


int my_random()
{
    std::random_device randomDevice;
    std::mt19937_64 generator(randomDevice());
    auto dice = getDice(std::integral_constant<bool, std::numeric_limits<int>::is_integer>());
    return dice(generator);
}


void graph_for_rand_arr() {
    int* len = new int[13] {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};


    for (int i = 0; i < 13; i++) {
        double comparsions = 0;
        double copies = 0;
        for (int j = 0; j < 100; j++) {

            vector<int> arr(len[i]);
            for (int k = 0; k < len[i]; k++)
            {
                arr[k] = my_random();
            }

            stats s = natural_merge_sort(arr);
            comparsions += s.comparison_count/13;
            copies += s.copy_count/13;
        }
    }
}


void graph_for_sorted_arr() {
    int* len = new int[13] {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};


    for (int i = 0; i < 13; i++) {
        int comparsions = 0;
        int copies = 0;
        vector<int> arr(len[i]);
        for (int k = 0; k < len[i]; k++)
        {
            arr[k] = i;
        }

        stats s = natural_merge_sort(arr);
        comparsions += s.comparison_count;
        copies += s.copy_count;
    }
}


void graph_for_reverse_sorted_arr() {
    int* len = new int[13] {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};


    for (int i = 0; i < 13; i++) {
        int comparsions = 0;
        int copies = 0;
        vector<int> arr(len[i]);
        for (int k = 0; k < len[i]; k++)
        {
            arr[k] = len[i] - i;
        }

        stats s = natural_merge_sort(arr);
        comparsions += s.comparison_count;
        copies += s.copy_count;
    }
}