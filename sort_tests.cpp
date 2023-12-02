#include "sort.cpp"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;



TEST(SortTests, BubbleSortCheck) {
    vector<int> a = { 1, 4, 3, 2 };
    vector<int> b = { 1, 2, 3, 4 };

    bubble_sort(a);

    EXPECT_EQ(a,  b);
    
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


TEST(SortTests, MergeSortLeftCheck) {
    vector<int> a = { 1,8,5,6 };
    vector<int> b = { 4, 2, 3, 7 };
    vector<int> c(10);
    c[0] = 10;
    c[1] = 10;

    merge_sort_left(a, b, c, 2);

    vector<int> d = {10, 10, 1, 2, 3, 4, 5, 6, 7, 8 };
    
    EXPECT_EQ(d, c);
    EXPECT_EQ(*b.data(), 4);
}


TEST(SortTests, MErgeSortRightCheck) {
    vector<int> a = { 1,8,5,6 };
    vector<int> b = { 4, 2, 3, 7 };
    vector<int> c(10);
    c[0] = 10;
    c[1] = 10;

    merge_sort_right(a, b, c, c.size() - 1);

    vector<int> d = {10, 10, 1, 2, 3, 4, 5, 6, 7, 8 };

    EXPECT_EQ(d, c);
}