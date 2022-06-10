#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int Partition(int Arr[],int L,int H){
	int pivot=Arr[L];
	int i=L;
	int j=H;
	while(i<j){
		// Increase i until Arr[i] becomes greater than pivot
		while(Arr[i]<=pivot){
			i++;
		}
		// decrease j until Arr[i] becomes smaller than pivot
		while(Arr[j]>pivot){
			j--;
		}
		// Swap the elements Arr[i] and Arr[j]
		if (i<j)
		{
			swap(Arr[i],Arr[j]);
		}
	}
	swap(Arr[L],Arr[j]);
	return j;
}

void QuickSort(int Arr[],int L,int H){
	if(L<H){
		//Element at location j is sorted
		int j=Partition(Arr,L,H);
		//Recursive approach to solve two unsorted subarrays on either side of pivot element
		QuickSort(Arr,L,j-1);
		QuickSort(Arr,j+1,H);
	}
}
int main()
{
	int A[6]={6,8,3,1,9,4};
	int n=(sizeof(A)/sizeof(int));
	QuickSort(A,0,n-1);
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}