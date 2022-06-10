#include<bits/stdc++.h>
using namespace std;

void Merge(){

}
void MergeSort(int Arr[],int L,int Mid,int H){
	int n1=Mid-L+1;
	int n2=H-Mid;
	int Lsa[n1];
	int Rsa[n2];

	//Spliting the elements into Lsa and Rsa
	for(int i=0;i<=Mid;i++){
		Lsa[i]=Arr[i];
	}
	for(int j=Mid+1;j<=H;j++){
		Rsa[j-Mid-1]=Arr[j];
	}
	int i=0,j=0;k=0;
	while()
	if(Lsa[i]<Rsa[j]){
		Arr[]
	}
}

int main(){
	int A[6]={6,8,3,1,9,4};
	int n=(sizeof(A)/sizeof(int));
	MergeSort(A,0,5);
	return 0;
}