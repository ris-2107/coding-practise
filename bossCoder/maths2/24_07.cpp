//Q.5:
//Given an array non-negative integers and an integer 'm'.
//count #pair(i,j) such that a[i]+a[j]is divisble by 'm'.


//Optimal solution:

#include <bits/stdc++.h>
using namespace std;
int findReqPairs(int arr[],int size, int m){
	int modArray[size];
	for(int i=0;i<size;i++){
			modArray[i]=arr[i]%m;


	}

	//consider the condition: a[i]+a[j]%m==0
	multimap <int,int>freq_map;
	
	for(int i=0;i<size;i++){
		freq_map.insert(make_pair(modArray[i],arr[i]));

	//freq_map[modArray[i]]=arr[i];
	}
	 for (auto x : freq_map)
      cout <<"Printed here  "<< x.first << " " << x.second << endl;


 


  

  return 1;


}
int main(){
	int arr[]={2,2,1,7,5,3,0,4,8,13,5,6};
	int z= findReqPairs(arr,12,4);
	cout << z << endl;

}