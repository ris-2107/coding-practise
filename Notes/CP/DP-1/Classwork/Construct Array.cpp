//Construct an Array- HackerRank
//PDF is attached in the same folder  

//Your goal is to find the number of ways to construct an array such that consecutive positions contain different values.

//Specifically, we want to construct an array with  elements such that each element between 1 and k, inclusive. We also want the first and last elements of the array to be 1 and x.

// Given n,k  and x, find the number of ways to construct such an array. Since the answer may be large, only find it modulo .

// For example, for , , , there are  ways, as shown here:



// Complete the function countArray which takes input ,  and . Return the number of ways to construct the array such that consecutive elements are distinct.

// Constraints

// Subtasks

// For  of the maximum score,  and 
// Sample Input
 

// Sample Output


//Code:

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


long countArray(int n, int k, int x){

	long oneCount=1;
	long nonOneCount=0;

	for(int i=1;i<n;i++){

		long previousOneCount = oneCount;
		oneCount = (nonOneCount*(k-1))%MOD;
		nonOneCount= (previousOneCount + ((nonOneCount)*(k-2))%MOD)%MOD;


	}
	if(x==1)
		return oneCount;
	else
		return nonOneCount;
}
int main(){


	cout <<countArray(4,3,2) << " ";
	return 0;
}