

/*
			          	 PROBLEM STATEMENT

Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies 
(between 1 and 1000000000). 
Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students.

 He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. 
Help Shaky in finding out what is the maximum number of candies which a student can get.



Input:
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. 
First line of each test case contains N and K. Next line contains N integers, 
ith of which is the number of candies in ith box.

Output:
For each test case print the required answer in a seperate line.



Sample Input:

2
3 2 
3 1 4
4 1
3 2 3 9


Sample Output:

3
9


*/


//Code:

#include<bits/stdc++.h>
using namespace std;


int go(int* arr, int k,int n){

	sort(arr,arr+n);
	
	int max_candies = arr[n-1];
	int min_candies = 0;
	int mid ;
	int ans = 1;
	
    
	while(max_candies>=min_candies){
       mid = (min_candies+max_candies)/2;
        int given=0;
        for(int i=0;i<n;i++)
        {
            given+=arr[i]/mid;
        }
        
        if(given>=k){
            ans=max(ans,mid);
            min_candies=mid+1;
            }
        else{
            max_candies=mid-1;
        }
               
        }
	
	return ans;

}




int main( )
{
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	
	

	while(t--){
		int n, k;
		cin>>n>>k;
		int* arr=new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
		cout << go(arr,k,n) <<endl;
	}
	
	return 0 ; 

}
