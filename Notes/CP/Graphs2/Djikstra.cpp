//Djiskstra Algo: for shortest Path
// Complexity:=> 



#include <bits/stdc++.h>
using namespace std;


int getMinVertex(int * dist, bool* visited, int n){
	int minVertex = -1;

	for(int i=0; i<n; i++){
		if(!visited[i] && ( minVertex ==-1 || dist[i] < dist[minVertex]))
		{
			minVertex=i;
		}
	}
	return minVertex;
}


void djikstra(int** edges, int n){
	bool* visited= new bool[n]();
	int * dist= new int [n];

	for (int j = 0; j < n; j++)
	{
		
		dist[j]=INT_MAX;
		
	}
	dist[0]=0;

	for(int i=0; i<n-1; i++){

		//gives the minimun=m vertex and not visited:

		int minVertex= getMinVertex(dist, visited, n);
		visited[minVertex]=true;	



		//Explore all the neighbours of Minvertex which 
		// are unvisited and update the distance array:

		for(int j=0; j<n;j++){
			if(edges[minVertex][j] && !visited[j] ){
				int currD= dist[minVertex] + edges[minVertex][j];
				if(dist[j] >currD){
					dist[j] = currD;
				}
			}
		}

	}

	for(int i=0; i<n;i++){
		cout << i << dist[i] << endl;

	}
	delete[] visited;
	delete[] dist;
}


int main(){

	freopen("input.txt", "r", stdin);
	

	int n, e;
	cin >> n >> e;
	//cout <<n<<" ";
	int ** edges= new int*[n];
	for (int i = 0; i < n; ++i)
	{
		
		edges[i]= new int[n];
		for(int j=0; j<n; j++){
			edges[i][j] =0;
		}
	}


	for(int i=0; i<= e-1;i++)
	{
		int f,s,weight;
		cin >> f >> s >> weight;
		edges[f][s]=weight;
		edges[s][f]=weight;
		
	}
	
	
	cout << endl;

	djikstra(edges, n); 

	for(int i=0; i<n;i++){
		delete[]edges[i];
	}
	delete[]edges;
	
		
}