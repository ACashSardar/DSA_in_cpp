#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];

    while (i <= mid and j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int myArr[] = {60, 40, 80, 10, 50, 70, 90, 20, 30};

    int n = sizeof(myArr) / sizeof(myArr[0]);
    mergeSort(myArr, 0, n - 1);
    for (auto it : myArr)
    {
        cout << it << " ";
    }
    return 0;
}