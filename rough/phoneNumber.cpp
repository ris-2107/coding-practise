#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
	// base case:
	if(n== 0 || n== 1) return true;

	if(arr[0] > arr[1])
		return false;
	
	// recursive relation
	bool ans=isSorted(arr+1,n-1);
	return ans;


}
void printArr(int arr[],int s,int e){
for(int i=s;i<=e;i++) cout << arr[i] <<" ";
}

// bool isPresent(int arr[],int n, int x){
// 	printArr(arr,n);
// 	cout << "    size : " << n;
// 	cout << endl;

// 	if(n==0) return false;

// 	if(  x== arr[0]) return true;

// 	return isPresent(arr+1,n-1,x);

// }

bool binarySearch(int arr[], int s,int e, int k){

	printArr(arr,s,e);
	cout << endl ;

	// base case:
	if(s>e){
		return false;
	}

	int mid=s+(e-s)/2;

	if (arr[mid] == k){
		return true;
	}

	if(arr[mid] <k){
		return binarySearch(arr,mid+1,e,k);
	}else{
		return binarySearch(arr,s,mid-1,k);
	}

}


int main(){
		int arr[]={91,220,386,409,508,517,518,519,520,521};
		int size=10;
		
		int x=01;

		bool is_present=binarySearch(arr,0,4,x);
		if(is_present) cout<< "Element Found " << endl;
		else cout << "Element not found " << endl;
		return 0;

}

	
