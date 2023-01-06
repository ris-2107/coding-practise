// Longest Increasing Subsequence:
// Given an array, there might be subsequnces that are increasing,
// we have to find the length of the longest increasing subsequnce.  

// This question is not using recursion, still its a DP Question, 

// because we look to the previous solution array...

#include <bits/stdc++.h>
using namespace std;


int lis(int * input, int n){

	// int *output= new int[n];
	// output[0]=1;

	// for(int i=0;i<n;i++){
	// 	output[i]=0;

	// 	for(int j=i-1; j>=0; j--){
	// 		if(input[i] <input[j])
	// 			continue;

	// 		int possibleAns=output[j]+1;

	// 		if(possibleAns > output [j])
	// 			output[j]=possibleAns;
	// 	}
	// }


	int *output= new int[n];
	output[0]=1;

	for(int i=1;i<n;i++){
		output[i]=1;

		for(int j=i-1;j>=0;j--){

			if(input[i]<input[j])
				continue;

			int possibleAns=output[j]+1;

			if(possibleAns>output[j])
				output[j]=possibleAns;

		}
	}

	int best=0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(best<output[i])
			best=output[i];
	}

	delete[] output;
	return best;




}





int main(){
	freopen("input.txt", "r", stdin);
	int t;cin >> t;

	while(t--)
		{
			int n;
			cin >> n;
			int * input=new int [n];
			
			for(int i=0; i<n;i++){
				cin >> input [i];
			}

			int ans=lis(input, n);
			cout << ans << endl;
			delete[] input;
		}
	
}