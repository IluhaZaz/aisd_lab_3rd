#pragma once
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>


using namespace std;


struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
	friend void operator += (stats& s1, const stats& s2);
};

void operator += (stats& s1, const stats& s2) {
	s1.comparison_count += s2.comparison_count;
	s1.copy_count += s2.copy_count;
}


ostream& operator << (ostream& out, stats& s) {
	cout << "Comparsions: " << s.comparison_count << "  Copies: " << s.copy_count << " ";
	return out;
}


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
stats shaker_sort(vector<T>& a) {

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
    return s;
}


template<typename T>
stats merge_sort_left(vector<T>& a1, vector<T>& a2, vector<T>& temp, int start_index) {
	stats s;
	int i = 0;
	int j = 0;
	int k = start_index;
	while (i < a1.size() && j < a2.size()) {
		s.comparison_count += 3;
		s.copy_count += 1;
		if (a1[i] <= a2[j]) {
			temp[k] = a1[i];
			i++;
		}
		else {
			temp[k] = a2[j];
			j++;
		}
		k++;
	}
	while (i < a1.size()) {
		s.copy_count += 1;
		s.comparison_count++;
		temp[k] = a1[i];
		i++;
		k++;
	}
	while (j < a2.size()) {
		s.copy_count += 1;
		s.comparison_count++;
		temp[k] = a2[j];
		j++;
		k++;
	}
	return s;
}
template<typename T>
stats merge_sort_right(vector<T>& a1, vector<T>& a2, vector<T>& temp, int start_index) {
	stats s;
	int i = 0;
	int j = 0;
	int k = start_index + a1.size() + a2.size() - 1;
	while (i < a1.size() && j < a2.size()) {
		s.comparison_count += 3;
		s.copy_count += 1;
		if (a1[i] <= a2[j]) {
			temp[k] = a1[i];
			i++;
		}
		else {
			temp[k] = a2[j];
			j++;
		}
		k--;
	}
	while (i < a1.size()) {
		s.copy_count += 1;
		temp[k] = a1[i];
		s.comparison_count++;
		i++;
		k--;
	}
	while (j < a2.size()) {
		s.copy_count += 1;
		temp[k] = a2[j];
		s.comparison_count++;
		j++;
		k--;
	}
	return s;
}
template<typename T>
vector<T> merge(vector<T>& a, stats& stat) {
	vector<int> temp(a.size());
	size_t left_start = 0;
	size_t left_end = 0;

	size_t left = 0;
	size_t right = a.size();
	size_t right_start = a.size() - 1;
	size_t right_end = right_start;

	size_t n = 0;
	while (left_end < right_end) {
		while (a[left_end] <= a[left_end + 1] && left_end + 1 != right_end) {
			stat.comparison_count++;
			left_end++;
		}
		while (a[right_end] <= a[right_end - 1] && right_end - 1 != left_end) {
			stat.comparison_count++;
			right_end--;
		}
		if (left_end == right_end) {
			break;
		}
		vector<int> subvector1(a.begin() + left_start, a.begin() + left_end + 1);
		vector<int> subvector2(a.begin() + right_end, a.begin() + right_start + 1);
		reverse(subvector2.begin(), subvector2.end());
		if (n % 2 == 0) {
			merge_sort_left(subvector1, subvector2, temp, left);
			left += subvector1.size() + subvector2.size();
		}
		else {
			right -= subvector1.size() + subvector2.size();
			merge_sort_right(subvector1, subvector2, temp, right);
		}
		left_end++;
		right_end--;
		left_start = left_end;
		right_start = right_end;
		n++;
	}
	return temp;
}


template<typename T>
stats natural_merge_sort(vector<T>& a) {
	vector<int> a_prev;
	stats s;
	do {
		a_prev = a;
		a = merge(a, s);
	} while (a != a_prev);
	return s;
}


template <typename T>
void graph_for_rand_arr(unsigned int seed, stats (&sort_func)(vector<T>&)) {

	srand(seed);

    int* len = new int[13] {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};


    for (int i = 0; i < 13; i++) {
		
		stats s;

        for (int j = 0; j < 100; j++) {

            vector<int> arr(len[i]);
            for (int k = 0; k < len[i]; k++)
            {
                arr[k] = rand();
            }
            s += sort_func(arr);
        }

		s.comparison_count /= 100;
		s.copy_count /= 100;

		cout << s;
    }
}


template <typename T>
void graph_for_sorted_arr(stats(&sort_func)(vector<T>&)) {
    int* len = new int[13] {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};


    for (int i = 0; i < 13; i++) {
        vector<int> arr(len[i]);
        for (int k = 0; k < len[i]; k++)
        {
            arr[k] = i;
        }

        stats s = sort_func(arr);
		cout << s;
    }
}


template <typename T>
void graph_for_reverse_sorted_arr(stats(&sort_func)(vector<T>&)) {
    int* len = new int[13] {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};


    for (int i = 0; i < 13; i++) {
        vector<int> arr(len[i]);
        for (int k = 0; k < len[i]; k++)
        {
            arr[k] = len[i] - i;
        }

        stats s = sort_func(arr);
		cout << s;
    }
}
