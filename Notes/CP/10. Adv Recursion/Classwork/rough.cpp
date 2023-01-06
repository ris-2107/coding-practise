#include<bits/stdc++.h>
using namespace std;

int c=0;
string dial(int key){
	unordered_map<int, string>m;
	m[0]="";
	m[1]="";
	m[2]="abc";
	m[3]="def";
	m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    return m[key];
}


void pK(long long num, string out){


if(num==0){
	cout << out<< endl;
	return;
	}
	string temp=dial(num%10);
	for(int i=0; i<temp.size(); i++){
		pK(num/10,temp[i]+out);
	}
}


//Subsequences of a string:

int subsequences(string input, string output[]){

	//Base Case:
	if(input.empty())
	{
		output[0]="";
		return 1;
	}

	string smallSubstring= input.substr(1);
	int smallOp=subsequences(smallSubstring, output);
	for(int i=0; i<smallOp; i++){
		output[i+smallOp]= input[0]+output[i];
	}
	return 2*smallOp;

}

int main(){

	freopen("input.txt", "r", stdin);

	long long n; 
	string inp;
	//cin >> n;
	cin >> inp;
	string *op = new string[1000];

	int a=subsequences(inp, op);
	for (int i = 0; i < a; ++i)
	{
		/* code */
		cout << op[i] << endl;


	}
	
	//pK(n,""); //Here, out=""
	
	return 0;
}