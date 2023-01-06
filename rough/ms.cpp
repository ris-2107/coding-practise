#include <bits/stdc++.h>
using namespace std;
//Merge Sort:
void merge(int arr[],int s, int e)
{

	int  mid=(s+e)/2;

	int len1=mid-s+1;
	int len2=e-mid;

	int *first=new int[len1];
	int *second = new int [len2];
	int mainArrayIndex=s;


	for(int i=0;i<len1;i++){
		first[i]=arr[mainArrayIndex++];
	}

	 mainArrayIndex  = mid+1;
	for(int i=0;i<len2;i++){
		second[i]=arr[mainArrayIndex++];
	}

	// merge the arrays:
	int index1=0;
	int index2=0;
	mainArrayIndex=s;

	while(index1<len1 && index2 < len2){
		if(first[index1] < second[index2]){
			arr[mainArrayIndex++]= first[index1++];

		}else{
			arr[mainArrayIndex++]=second[index2++];
		}
	}
	while(index1<len1){
		arr[mainArrayIndex++]=first[index1++];

	}
	while(index2<len2){
		arr[mainArrayIndex++]=second[index2++];
		
	}
}


void merge2(int arr [], int s, int e){
	int mid=(s+ e )/2;

	int len1=mid-s+1;
	int len2 = e-mid;

	int *first= new int[len1];
	int * second = new int [len2];

	int mainArrayIndex=s;

	for(int i=0;i<=len1; i++){
		first[i]= arr[mainArrayIndex++];
	}
	mainArrayIndex=mid+1;
	for(int i=0;i<=len2;i++){
		second[i]=arr[mainArrayIndex++];
	}

	int index1=0;
	int index2=0;
	mainArrayIndex=s;


	while(index1 < len1 && index2 < len2){
		if(first[index1] < second[index2]){
			arr[mainArrayIndex++]=first[index1++];
		}else{
			arr[mainArrayIndex++]=second[index2++];
		}

	}
	while(index1< len1){
		arr[mainArrayIndex++]=first[index1++];
	}
	while(index2 < len2){
		arr[mainArrayIndex++]=second[index2++];
	}}


void mergeSort(int arr [], int s, int e){
	if(s>=e){
		return ;
	}

	int mid=(s+ e )/2;
	// left part Sort:
	mergeSort(arr,s,mid);

	// Right part sort:
	mergeSort(arr, mid+1, e);
 
	//merge:
	merge2(arr,s,e);
}

int main(){

	int arr[6]={11,4,12,3,1,7};
	int n=6;
	mergeSort(arr,0,n);

	for(auto ele :arr){
		cout << ele <<", ";
	}

	return 0;
}