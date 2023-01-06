// 1 Staircase Problem:
// same as Fibonacci but we need sum of three sums instead of 2




//2. Coin change Problem:
//1. Naive SOlution:
#include<bits/stdc++.h>
using namespace std;




int coin_change(int n, int *d, int numD){  //n= amount; d= array of Denominations, numD= number of Denominations
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(numD==0)
		return 0;
	int first = coin_change(n-d[0], d, numD);
	int second = coin_change(n-d[1], d+1, numD -1 );
	return first +second;

}

//Better Solution using the Dp approach:
// if 'n' & 'numD' are same , it means that we do actually have that solution:
// Thus, we'll use a 2D array:

int coin_changeDP(int n, int *d, int numD, int output[][3]){  //n= amount; d= array of Denominations, numD= number of Denominations
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(numD==0)
		return 0;

	if(output[n][numD] > -1)
		return output[n][numD];

	int first = coin_change(n-d[0], d, numD);
	int second = coin_change(n-d[1], d+1, numD -1 );
	output[n][numD] = first +second;
	return first +second;

}


int main(){
	int d[]={1,2};
	

	//Allocate a 2D array here:
	// put all values of this 2D array as -1
	// size: n+1 by numD+1

	int op[5][3];
	for(int i=0;i<5;i++)
	{
		for(int j=0; j<3; j++)
		{
			op[i][j]=-1;
		}
	}
	
	
	cout <<coin_changeDP(4,d,2,op)<<"\n";
	cout << coin_change(4,d,2);
}


