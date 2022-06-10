#include <bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int l = low;
    int r = high;
    while (l < r)
    {
        while (arr[l] <= pivot && l < high)
        {
            l++;
        }
        while (arr[r] >= pivot && r > low)
        {
            r--;
        }
        // cout << arr[l] << "&" << arr[r] << " swapped" << endl;
        if (l < r)
            Swap(arr[l], arr[r]);
    }
    Swap(arr[low], arr[r]);
    return r;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    int piv_loc;
    if (low < high)
    {
        piv_loc = partition(arr, low, high);

        // Since the pivot element is already in the correct position
        // low-> pivLoc-1 & pivLoc+1->high
        QuickSort(arr, low, piv_loc - 1);
        QuickSort(arr, piv_loc + 1, high);
    }
}

int main()
{
    vector<int> v{50, 40, 10, 60, 20, 70, 30};
    QuickSort(v, 0, v.size() - 1);
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}