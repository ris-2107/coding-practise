//Minimum cost:

// You have been given a matrix of ‘N’ rows and ‘M’ columns filled up with integers. Find the minimum sum that can be obtained from a path which from cell (x,y) and ends at the top left corner (1,1).
// From any cell in a row, we can move to the right, down or the down right diagonal cell. So from a particular cell (row, col), we can move to the following three cells:

//the number present at that position of the matrix is actually the cost of the matrix path.


// Down: (row+1,col)
// Right: (row, col+1)
// Down right diagonal: (row+1, col+1)


// code:
// 1. Naive solution:
// every function calls three functions, thus for height 'm', we get 3^m t/c(exponential solution)


#include<bits/stdc++.h>
using namespace std;


//Using DP Approach:
int minCost2(int input[][3], int m, int n ){
	int dp[m][n];

	//we'll fill the lowermost right side box:
	dp[m-1][n-1]=input[m-1][n-1];

	for(int i=m-2; i>=0; i--){
		dp[i][n-1]=dp[i+1][n-1] + input[i][n-1]; //column fixed
	}

	for(int j=n-2; j>=0; j--){
		dp[m-1][j]= dp[m-1][j+1]+ input[m-1][j] ; 	//Row is fixed... 
	}

	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0; j--){
			dp[i][j]= input[i][j] + min(dp[i+1][j], min( dp[i+1][j+1], dp[i][j+1] ));
		}
	}
int op=dp[0][0];
delete []dp;
return op;

}


int min_cost(int input[][3], int si, int sj, int ei, int ej){
	if (si == ei && sj == ej) {
		return input[ei][ej];
	}

	if(si>ei || sj>ej)
		return INT_MAX;


	//left:
	int option1 = min_cost(input, si + 1, sj, ei, ej);

	//diagonally:
	int option2 = min_cost(input, si + 1, sj + 1, ei, ej);

	//right
	int option3 = min_cost(input, si, sj + 1, ei, ej);

	return input[si][sj] + min(option1, min(option2, option3));
	
}



int main(){
	int input [3][3] = { {4,3,2}, {1,8,3}, {1,1,8}};
	
	cout << min_cost(input, 0, 0, 2,2) << endl;
	cout << minCost2(input, 3,3) << endl;

}

