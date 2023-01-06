#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printData(int n, int f=INT_MAX){
	cout<< "First Data: " << n<<endl;
	cout<< "Second Data: " << f<< endl;
}


int  main(){
	int num1;
	cout<< "Enter 1st data" << endl;
	cin >> num1;
	printData(num1);
	return 0;
}

