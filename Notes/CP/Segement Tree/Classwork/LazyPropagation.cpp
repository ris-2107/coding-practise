//LazyPropagation:
// lazy propagation is a kind of propagation in 
// which the value is propagated only when required.

//*Its used when its required to upadte the values in a given range.*


//we are considering the minimum of value, as 
// shown in the video.

#include <bits/stdc++.h>
using namespace std;


// for Building a tree:

void buildtree(int*arr, node*tree, int treeIndex, int start, int end){
if(start == end){
		tree[treeNode]=arr[start];
		return;

	}


	int mid=(start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode]= tree[2*treeNode] + tree[2*treeNode+1];


}




//Update Segment Tree:

void updateSegmentTreeLazy(int * tree, int* lazy,int low, int high, int startR, int endR, int currPos, int inc ){

	if(low>high){
	return;
	}

if(lazy[currPos]!=0){
	tree[currPos]+=lazy[currPos];

	// If not a leaf Node:
	if(low!=high){
		lazy[2*currPos]+=lazy[currPos];
		lazy[2*currPos]+=lazy[currPos];
	}
	lazy[currPos]=0;
}

//No Overlap condition:
if(startR > high || endR <low){
	return;
}


//Complete Overlap Condition:
if(startR <= low || high<=endR){
tree[currPos] += inc;
} 


}




int main(){

	int arr[]={1,3,-2,4};
	int tree=new int[12]();
	buildTree(arr,tree,0,3,1);
	int* lazy=new int[12]();



	return 0;
}