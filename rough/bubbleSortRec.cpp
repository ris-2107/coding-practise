#include <bits/stdc++.h>
using namespace std;

void sortArray(int arr[], int size){

	//base case:
	if(size==0 || size ==1 ) return ;

	// we have solved one case: 
	for(int i=0;i<size-1;i++){
		if(arr[i] > arr[i+1]) swap (arr[i], arr[i+1]);

	}

	sortArray(arr, size-1);
}

int main(){
	int arr[] = {1,2,78,50,23,40,42,34,36,8,9,340, 289,286,299, 190,178,179,4};
	int sz=sizeof(arr)/sizeof(arr[0]);
	sortArray(arr,sz);
	for(auto ele:arr){ cout << ele << ", ";}
	cout << endl;
	return 0;
}