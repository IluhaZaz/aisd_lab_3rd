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


TEST(SortTests, MergeSortRightCheck) {
    vector<int> a = { 1,8,5,6 };
    vector<int> b = { 4, 2, 3, 7 };
    vector<int> c(10);
    c[0] = 10;
    c[1] = 10;

    merge_sort_right(a, b, c, c.size() - 1);

    vector<int> d = {10, 10, 1, 2, 3, 4, 5, 6, 7, 8 };

    EXPECT_EQ(d, c);
}


TEST(SortTests, ReverseCheck) {
    vector<int> a = { 1, 2, 3, 4 };
    vector<int> b = { 4, 3, 2, 1 };
    
    reverse(b);

    EXPECT_EQ(a, b);
}

TEST(SortTests, ReverseCheck2) {
    int* a = new int[4]{ 1, 2, 3, 4 };
    int* b = new int[4]{ 4, 3, 2, 1 };

    reverse(b, 4);

    for(int i = 0; i < 4; i++)
        EXPECT_EQ(a[i], b[i]);
}


TEST(SortTests, VectorToArrayCheck) {
    vector<int> a = { 1, 2, 3, 4 };
    int* b = new int[4] { 1, 2, 3, 4 };

    int* c = vector_to_array(a);

    for (int i = 0; i < 4; i++)
        EXPECT_EQ(c[i], b[i]);
}


TEST(SortTests, ArrayToVectorCheck) {
    vector<int> a = { 1, 2, 3, 4 };
    int* b = new int[4] { 1, 2, 3, 4 };

    vector<int> c = array_to_vector(b, 4);

    EXPECT_EQ(c, a);
}


TEST(SortTests, ArrByRangeCheck) {
    int* a = new int[7] { 1, 2, 3, 4, 5, 6 ,7 };
    int* b = arr_by_range(a + 2, a + 5);


    for (int i = 0; i < 4; i++)
        EXPECT_EQ(a[i + 2], b[i]);
}


