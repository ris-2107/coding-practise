//lets  Update a segment tree:
 



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


void updateTree(int*arr, int*tree, int start, int end, int treeNode, int idx, int value){


	if(start == end){
		arr[idx]= value;
		tree[treeNode]=value;
		return;
	}


	int mid=(start + end)/2;
	if(idx> mid){
		//Right Side:
		updateTree(arr, tree, mid+1,end, 2*treeNode+1, idx, value);


	}else{
		//Left side:
		updateTree(arr, tree, start, mid, 2*treeNode, idx, value);

	}
	tree[treeNode]=tree[2*treeNode] +tree[2*treeNode+1];
}

// query:



int query(int *tree, int start, int end, int treeNode, int left, int right){

	int mid=(start+end)/2;



	//completrly outside the given Range:
	if(start>right || end <left){
		return 0;
	}



	//Completely inside the given Range:
	if(start>=left && end <=right){
		return tree[treeNode];
	}

	int ans1=query(tree,start, mid, 2*treeNode, left, right);
	int ans2=query(tree, mid+1, end, 2*treeNode+1, left, right);
	return ans1+ans2;



	// Partially inside and partially outside the GIVEN range

}


int main(){

	int arr[] ={1,2,3,4,5}; //N=5 size
	int* tree= new int[10]; //2*N size

	buildTree(arr,tree,0,4,1);

	updateTree(arr,tree,0,4,1,2,10);
	for(int i=1;i<10;i++){
		cout <<tree[i] <<endl;
	}

	int ans=query(tree, 0,4,1,2,4);
	cout <<"Sum betwen the interval [2] and [4] is:" << ans<<endl;

}