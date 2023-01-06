//PERMXORITY :- Codechef

#include<bits/stdc++.h>
using namespace std;

int main (){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n==2 || n==1)
			cout << "-1\n";

		else if(n%2){
			for(int i=1; i<n ; i++)
				cout << i;
			cout << "\n";
		}
		else{
			cout << "1 2 3 4" ;
			for(int i=5; i<=n; i++)
				cout << i << " ";
			cout << "\n";
		}

	}
	return 0; 
}