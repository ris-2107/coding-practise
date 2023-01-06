// Graphs:


// We'll majorly use the concept of Adjacency Matrix.:


#include<bits/stdc++.h>
using namespace std;


// Its called a DFS because we go into a particular direction until there's no further 
// connection 

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



//Lets construct a BFS search:

void printBFS(int ** edges, int n, int sv){
	queue<int> pendingVertices;

	bool *visited = new bool[n];
	for(int i=0; i<n;i++){
		visited[i]=false;
	}

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
	delete [] visited;
}



int main(){
	freopen("input.txt", "r",stdin);


	int n=6; 				// No of vertices
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

	bool * visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]= false;
	}
	cout<< "DFS: " ;

	printDFS(edges, n, 0, visited);

	cout<< "\n\nBFS: ";
	
	printBFS(edges, n,0);

	//Delete All Memory (visited AND 2D Array):
	delete [] visited;
	for(int i=0; i<n;i++){
		delete[]edges[i];	
	}
	delete [] edges;

	return 0;
}