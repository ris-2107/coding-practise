

// Kruskal's Algorithm
// Gives Minimum spanning Tree


// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.


// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)


// Output Format :
// Print the MST, as described in the task.
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec


// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8


// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5

// CODE:


// Complexity: E*logE + e*V




#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src;
	int dest;
	int weight;

};
int getParent(int v, int* parent){
	if(parent[v] == v){
		return v;
	}
	return getParent(parent[v], parent);

}

bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

Edge * kruskals(Edge* edges, int n, int E){
	//Sorted Edges array in ascending order

sort(edges, edges+E, compare);


Edge* output = new Edge[n-1];
int * parent  = new int [n];
for (int i = 0; i < n; ++i)
{
	parent[i]=i;
}

int count =0;int i=0;
while(count < (n-1)){
	// Check the topmost parent of v1 and v2. v1 and v2 are vertices of
	// current edge

	Edge currentEdge = edges[i];
	int srcParent = getParent(currentEdge.src, parent);
	int destParent = getParent(currentEdge.dest, parent);

	if(srcParent != destParent){
		output[count]= currentEdge;
		count+=1;
		parent[srcParent]=destParent;
	}  
	i+=1;
}
return output;


}


int main(){
	freopen("input.txt", "r", stdin);

	int n, E;
	cin >> n >> E;
	Edge* edges = new Edge[E];

	for(int i=0; i<E; i++){
		int s,d,w;
		cin >> s >> d >> w;
		edges[i].src=s;
		edges[i].dest=d;
		edges[i].weight=w;
	}

	Edge* output = kruskals(edges, n, E);



	for(int i=0; i<n-1; i++){
		if(output[i].src < output [i].dest){
			cout << output [i].src << " " << output[i].dest <<" "<< output[i].weight << endl;
		}else{
			cout << output [i].dest << " " << output[i].src <<" "<< output[i].weight << endl;
		}
	}


	return 0; 
}
