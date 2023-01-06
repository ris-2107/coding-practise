//Return Subsequences of a String:
#include<bits/stdc++.h>
using namespace std;



int subs(string input , string output[]){
	
	if(input.empty()){
		output[0]="";
		return 1;
	}

	string smallString= input.substr(1);
	int smallOutputSize = subs(smallString, output);

	for(int i=0;i<smallOutputSize;i++){
		output[i+smallOutputSize] = input[0] + output[i];
	}
	return 2*smallOutputSize;
}



//Driver Code:
int main(){
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string input;
	cin >> input;
	
	string* output = new string[1000];
	int count = subs(input, output);
	for(int i=0;i<count;i++)
		cout << output[i] << "\t•\n";
	cout << "\nThe number of Subsequnces possible are:\t" << count<<endl; 
}