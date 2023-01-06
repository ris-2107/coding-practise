//Live Question 2- sam and substrings:

//Its a Dynamic Programmin gQuestion becuase using the last resukt we are calulating the new
//result

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007


int substrings(string s){
	long long totalSum=s[0]-'0';
	long long lastValue=s[0]-'0';

	for(int i=1; i<s.length(); ++i){
		lastValue=lastValue*10 + (s[i]-'0')*(i+1);
		lastValue=lastValue%MOD;
		totalSum=(totalSum + lastValue)%MOD;
	}
	return totalSum;
}

int main(){
	cout << substrings("123");

}