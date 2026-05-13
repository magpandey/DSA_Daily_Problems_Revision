#include <iostream>
#include <vector>
#include <map>
#include <set>
// I am going to create function for basic all the sorting algorithms

// Insertion sort
using namespace std;

void InsertionSort(vector<int> arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev == 0 && arr[prev] > arr[curr])
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}
// Selection sort
void SelectionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int SmallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[SmallestIdx])
            {
                SmallestIdx = j;
            }
        }
        swap(arr[i], arr[SmallestIdx]);
    }
}
// Bubble sort

void BubbleSort(vector<int> arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            return;
        }
    }
}
int main()
{
    vector<int> arr = {4, 1, 3, 5, 2};
    BubbleSort(arr, 5);
    InsertionSort(arr, 5);
    SelectionSort(arr, 5);
    return 0;
}