//lets construct a segment tree:

//The segment tree size should be : 4*N [N=size of the Array]

#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int*tree, int start, int end, int treeNode){

	if(start == end){
		tree[treeNode]=arr[start];
		return;

	}


	int mid=(start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode]= tree[2*treeNode] + tree[2*treeNode+1];

}


int main(){
	int arr[] ={1,2,3,4,5,6,7,8,9}; //N=9 size
	int* tree= new int[18]; //2*N size

	buildTree(arr,tree,0,8,1);
	for(int i=1;i<18;i++){
		cout <<tree[i] <<endl;
	}

}