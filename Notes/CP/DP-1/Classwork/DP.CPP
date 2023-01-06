//Lecture 1 - Fibonacci:

#include <bits/stdc++.h>
using namespace std;
#define mod 19;


int fib(int n){
	if(n==1 || n==0){
		return n;
	}
	

	return fib(n-1) + fib(n-2);
}



// now lets Use DP to solve and optimise the code:

int fib2(int n, int* arr){

if(n ==0 || n==1)
	return n;

if(arr[n] >0)
	return arr[n];

int opt= fib2(n-1, arr) + fib2(n-2, arr);


arr[n]=opt;
return opt; 


}

//lets construct an iterative approach:

int fibi(long n){
	long * arr= new long [n+1];
	arr[0]=0;
	arr[1]=1;
	for(long i=2; i<=n ;i++){
		arr[i]=arr[i-1] +arr[i-2];
	}
	long output=arr[n];
	delete[] arr;
	return output;
}


int main(){
	freopen ("input.txt", "r", stdin);
	int n;
	cin >>n;
	int *arr= new int[n+1]();
	

	cout << fib2 (n, arr) << " :Done using DP approach\n" <<endl;

	for (int i = 0; i < n+1; ++i)
	{
		cout << arr[i] <<" "<<endl;
	}


	//cout << fib (n) << " :Done using Normal approach" <<endl;


	
	return 0;
}