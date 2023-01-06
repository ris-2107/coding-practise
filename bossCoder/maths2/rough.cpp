
#include <bits/stdc++.h>
using namespace std;

// void findReverse(int i, int j, string &str){
// 	if (i>j){
// 		return;
// 	}

// 	swap(str[i],str[j]);
// 	i++;j--;
// 	findReverse(i,j,str);

// }


bool checkPalindrome(int s, int e, string str){
	
	if(s>e)
		return true;

	if(str[s] != str[e]) 
		return false;
	
	else

		return checkPalindrome (++s,--e,str);
}



int calcPow(int a, int b){
	if(b<=0) 
		return 1;

	if( b==1) 
		return a;

	int ans= calcPow(a,b/2);

	if(b%2 ==0){
		cout << "Even: " << b << endl;
		return ans * ans;
	}
	else{
		cout << "Odd: " <<b <<endl;
		return a * ans * ans;
	}

	

}


int main(){

	int a =2;
	int b=19;

	
	int ans=calcPow(a,b);
	cout << "Answer is: " << ans << endl;
	return 0;
}