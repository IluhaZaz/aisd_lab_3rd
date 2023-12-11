#include "sort.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;



TEST(SortTests, BubbleSortCheck) {
    vector<int> a = { 1, 4, 3, 2 };
    vector<int> b = { 1, 2, 3, 4 };

    bubble_sort(a);

    EXPECT_EQ(a, b);

}

TEST(SortTests, BubbleSortCheck2) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 1, 2, 3, 4 };

    bubble_sort(a);

    EXPECT_EQ(a, b);

}

TEST(SortTests, ShakerSortCheck) {
    vector<int> a = { 1, 4, 3, 2 };
    vector<int> b = { 1, 2, 3, 4 };

    shaker_sort(a);

    EXPECT_EQ(a, b);
}


TEST(SortTests, ShakerSortCheck2) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 1, 2, 3, 4 };

    shaker_sort(a);

    EXPECT_EQ(a, b);
}



TEST(SortTests, MergeCheck) {
    vector<int> a = { 5, 3, 2, 7, 1, 8, 4, 6 };
    vector<int> b = { 5, 6, 1, 2, 7, 8, 4, 3 };
    stats s;


    a = merge(a, s);
    EXPECT_EQ(a, b);
}

TEST(SortTests, MergeCheck2) {
    vector<int> a = { 5, 6, 1, 2, 7, 8, 4, 3 };
    vector<int> b = { 3, 4, 5, 6, 8, 7, 2, 1 };
    stats s;


    a = merge(a, s);
    EXPECT_EQ(a, b);
}


TEST(SortTests, MergeCheck3) {
    vector<int> a = { 2, 4, 5, 1, 6, 3, 7 };
    vector<int> b = { 2, 4, 5, 7, 6, 3, 1 };
    stats s;


    a = merge(a, s);
    EXPECT_EQ(a, b);
}


TEST(SortTests, NaturalMergeSortCheck) {
    vector<int> a = { 2, 4, 5, 1, 6, 3, 7 };
    vector<int> b = { 1, 2, 3, 4, 5, 6, 7 };


    natural_merge_sort(a);
    EXPECT_EQ(a, b);
}


TEST(SortTests, NaturalMergeSortCheck2) {
    vector<int> a = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> b = { 1, 2, 3, 4, 5, 6, 7 };


    natural_merge_sort(a);
    EXPECT_EQ(a, b);
}


TEST(SortTests, GraphForRandArrCheck) {
    graph_for_rand_arr(10, bubble_sort<int>);
    cout << endl;
    graph_for_rand_arr(10, shaker_sort<int>);
    cout << endl;
    graph_for_rand_arr(10, natural_merge_sort<int>);
}


TEST(SortTests, GraphForSotredArrCheck) {
    graph_for_sorted_arr(bubble_sort<int>);
    cout << endl;
    graph_for_sorted_arr(shaker_sort<int>);
    cout << endl;
    graph_for_sorted_arr(natural_merge_sort<int>);
}


TEST(SortTests, GraphForReverseSotredArrCheck) {
    graph_for_reverse_sorted_arr(bubble_sort<int>);
    cout << endl;
    graph_for_reverse_sorted_arr(shaker_sort<int>);
    cout << endl;
    graph_for_reverse_sorted_arr(natural_merge_sort<int>);
}