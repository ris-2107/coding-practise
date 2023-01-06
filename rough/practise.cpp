#include <bits/stdc++.h>
using namespace std;

int noOfWays(int src, int n){
	if(n==0) return 1;
	
}

int main(){
	int arr[] = {1,2,78,50,23,40,42,34,36,8,9,340, 289,286,299, 190,178,179,4};
	int sz=sizeof(arr)/sizeof(arr[0]);
	sortArray(arr,sz);
	for(auto ele:arr){ cout << ele << ", ";}
	cout << endl;
	return 0;
}