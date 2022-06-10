#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int myArr[] = {20, 10, 50, 30, 60, 90, 80, 70, 40};
    int n = sizeof(myArr) / sizeof(myArr[0]);
    bubbleSort(myArr, n);
    for (auto it : myArr)
    {
        cout << it << " ";
    }
}