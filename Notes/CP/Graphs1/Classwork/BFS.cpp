#include<bits/stdc++.h>
using namespace std;

void print (int ** edges, int n , int sv, bool*visited){
cout << sv << endl;
visited[sv] = true;

for(int i= 0; i<n; i++){
	if(i==sv){
		continue;
	}

	if(i==sv) continue;

		if(edges[sv][i] ==1 ){
			if(visited[i]){
				continue;
			}
			print(edges, n, i, visited);
}
}



int main(){



	return 0;
}