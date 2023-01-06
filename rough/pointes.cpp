#include <bits/stdc++.h>
using namespace std;

bool check(string exp){
	stack <char> stk;

	for(int i=0;i< exp.length();i++){
		if(exp[i]=='(' || exp[i]=='{' || exp [i] == '['){
			stk.push(exp[i]);
			continue;
		}
		if(stk.empty()) return false;
		if(exp[i] ==')'){
			if(stk.top() == '{' || stk.top() == '['){ return false;}
			stk.pop();
		}
		if(exp[i] =='}'){
			if(stk.top() == '(' || stk.top() == '['){ return false;}
			stk.pop();
		}
		if(exp[i] ==']'){
			if(stk.top() == '(' || stk.top() == '{'){ return false;}
			stk.pop();
		}

	}
	return true;
}
int main(){
	string s=" ";
	cout << (check(s) == true? "Yes balanced" :"Not balanced")<< endl;
	return 0;
}
