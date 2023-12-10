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

    shaker_sort(a, 1);

    EXPECT_EQ(a, b);
}


TEST(SortTests, ShakerSortCheck2) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 1, 2, 3, 4 };

    shaker_sort(a, 1);

    EXPECT_EQ(a, b);
}


TEST(SortTests, ShakerSortCheck3) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 4, 3, 2, 1 };

    shaker_sort(a, 0);

    EXPECT_EQ(a, b);
}


TEST(SortTests, ReverseCheck) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 4, 3, 2, 1 };
    stats s;

    reverse(b, s);

    EXPECT_EQ(a, b);
}

TEST(SortTests, ReverseCheck2) {
    int* a = new int[4] { 1, 2, 3, 4 };
    int* b = new int[4] { 4, 3, 2, 1 };
    stats s;

    reverse(b, 4, s);

    for (int i = 0; i < 4; i++)
        EXPECT_EQ(a[i], b[i]);
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