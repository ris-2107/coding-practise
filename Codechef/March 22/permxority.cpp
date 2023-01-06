//PERMXORITY :- Codechef

#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n==2)
			cout << "-1\n";

		else if(n%2){
			for(int i=1; i<=n ; i++)
				cout << i << " ";
			cout << "\n";
		}
		else{
			cout << "2 3 1 4 " ;
			for(int i=5; i<=n; i++)
				cout << i << " ";
			cout << "\n";
		}

	}
	return 0; 
}