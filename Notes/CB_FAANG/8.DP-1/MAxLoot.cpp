#include <bits/stdc++.h>
using namespace std;



int Robber(int *a, int n){

	// 

	int *loot= new int[n]();

	loot[0]=a[0];
	loot[1]=a[1];

	for(int i=2;i<n;i++){
		loot[i]= max(loot[i-2]+a[i],loot[i-1]);
	}

	



}




int main(){
	freopen("input.txt","r",stdin);
	int n; 		     				 // The number of houses
	
	cin >> n;

	int *a= new int[n];

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	cout<< Robber(a,n) <<endl;

	return 0;
}