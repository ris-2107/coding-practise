//SubsetSum.cpp
#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *val, int n, int sum){

	bool **dp=new bool*[n+1];
	for(int i=0; i<=n; i++){
		dp[i]=new bool[sum+1];
	}
	for(int i=0; i<=sum;i++){
		dp[0][i] = false;
	}

	for(int i=0; i<=n;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];

			if(j>=val[i-1]){
				dp[i][j]=dp[i][j] || dp[i-1][j-val[i-1]];
			}
		}
	}
	bool ans= dp[n][sum];
	//deleting the DP:



	return ans;
}







// SubsetSum using XOR operator:
// We'LL USE A 2*(SUM+1) sized Array


bool subsetSumx(int *val, int n, int sum){

	bool **dp=new bool*[2];
	for(int i=0; i<=1; i++){
		dp[i]=new bool[sum+1];
	}
	for(int i=0; i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0]=true;

	int flag=1;


	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			dp[flag][j]=dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j]=dp[flag][j] || dp[flag^1][j-val[i- 1]];
			}
		}
		flag=flag^1;
	}
	bool ans= dp[flag^1][sum];
	//deleting the DP:



	return ans;
}







int main(){
	int val[]={1,2,3,5,7,9};
	int sum=14;
	cout<< subsetSum(val,5,sum);

	cout<< subsetSumx(val,5,sum);


 

	return 0;
}
