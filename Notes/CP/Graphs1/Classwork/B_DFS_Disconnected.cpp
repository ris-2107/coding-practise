//BFS And DFS for DisConnected Graph: 

#include <bits/stdc++.h>
using namespace std;


printBFS(int ** edges, int n, int sv, bool* visited){
	queue<int> pendingVertices;

	
	pendingVertices.push(sv);
	visited[sv]= true;

	while(!pendingVertices.empty()){
		int currentVertex= pendingVertices.front();
		pendingVertices.pop();
		cout<< currentVertex << "  ";
		for(int i =0;i<n; i++){
			if(i == currentVertex)
				continue;
			if(edges[currentVertex][i]==1 && !visited[i]){
				pendingVertices.push(i);
				visited[i]=true;
			}
		}
	}
	
}

void BFS(int ** edges, int n){
	bool * visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i]= false;
	}
	for(int i=0; i<n; i++){
		if(!visited[i])
			printBFS(edges, n,i, visited);
	}
	delete[] visited;
}



void printDFS(int ** edges, int n, int sv, bool* visited){
	cout << sv << "  ";
	visited[sv]=true;

	for(int i=0; i<n; i++){

		if(i==sv) continue;

		if(edges[sv][i] ==1 ){
			if(visited[i]){
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}


}



void DFS(int ** edges, int n){
	bool * visited = new bool[n];
	for(int i=0; i<n; i++){
		visited[i]= false;
	}
	for(int i=0; i<n; i++){
		if(!visited[i])
			printDFS(edges, n,i, visited);
	}
	delete[] visited;
	
}


int main(){
	freopen("input.txt", "r",stdin);


	int n; 				    // No of vertices
	int e; 					// No. of edges
	cin >> n >>e;

	int ** edges= new int*[n]();

	for(int i=0;i<n;i++){
		edges[i]= new int[n]();
	}


	for(int i=0; i<e;i++){
		int f,s;
		cin >> f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}

	
	cout<< "DFS: " ;
	DFS(edges, n);


	cout<< "\n\nBFS: ";
	BFS(edges, n);


	return 0;
}