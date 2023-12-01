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

    shaker_sort(a);

    EXPECT_EQ(a, b);
}

TEST(SortTests, ShakerSortCheck2) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 1, 2, 3, 4 };

    shaker_sort(a);

    EXPECT_EQ(a, b);
}



