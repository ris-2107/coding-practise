//SumoFSquares:



/*Given an Array arr[] of positive integers of size n. We are required to perform following 3 queries on given array –

1) Given L and R, we have to find the sum of squares of all element lying in range [L,R]

2) Given L, R and X, we have to set all element lying in range [L,R] to X

3) Given L, R and X, we have to increment the value of all element lying in range [L,R] by X

Input Format : First line contains the number of test cases T

Next line contains two positive integers – N (Size of Array ) and Q (Number of queries to be asked).

The next line contains N integers of array

Each of the next Q lines contains the Q queries to be asked. Each line starts with a number, which indicates the  type of query followed by required input arguments. Input format for all 3 queries will look like –

0 L R X : Set all numbers in Range [L, R] to “X”

1 L R X : ADD “X” to all numbers in Range [L, R]

2 L R :  Return the sum of the squares of the numbers in Range {L, R]

Output Format : For each test case, output “Case <TestCaseNo>:” in first line and then output the sum of squares for each queries of type 2 in separate lines.

Input:
1
3 3
1 2 3
0 1 2 2
1 1 3 3
2 1 3

Output : Case 1:
         86
Explanation : With 1st query (type 0), array elements from range [1,2] will set as 2. Updated array will become [2,2,3]
              With 2nd query (type 1), array elements from range [1,3] will be incremented by 3. Updated array will become [5,5,6]
              With 3rd query (type 2), Sum of Squares for range [1,3] will be 5^2+5^2+6^2 =86
Input:              
1
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
Output : Case 1:
         30
         7
         13
*/



// We will use 1 based indexing
// type 0 = Set
// type 1 = increment


#include<bits/stdc++.h>
using namespace std;
class segmenttree{
	public:
	int sum_of_squares;
	int sum_of_element;
};
class lazytree{
	public:
	int change;
	int type;
};

// Query On segment Tree


int query(segmenttree*tree,lazytree*lazy,int start,int end,int low,int high,int treeindex){
	if(lazy[treeindex].change!=0){
		int change=lazy[treeindex].change;
		int type=lazy[treeindex].type;
		if(lazy[treeindex].type==0){
			tree[treeindex].sum_of_squares=(end-start+1)*change*change;
			tree[treeindex].sum_of_element=(end-start+1)*change;
			if(start!=end){
				lazy[2*treeindex].change=change;
				lazy[2*treeindex].type=type;
				lazy[2*treeindex+1].change=change;
				lazy[2*treeindex+1].type=type;
			}
		}
		else{
			tree[treeindex].sum_of_squares+=((end-start+1)*change*change)+(2*change*tree[treeindex].sum_of_element);
			tree[treeindex].sum_of_element+=(end-start+1)*change;
			if(start!=end){
				if(lazy[2*treeindex].change==0 || lazy[2*treeindex].type==1){
					lazy[2*treeindex].change+=change;
					lazy[2*treeindex].type=type;
				}else{
					lazy[2*treeindex].change+=change;
				}
				if(lazy[2*treeindex+1].change==0 || lazy[2*treeindex+1].type==1){
					lazy[2*treeindex+1].change+=change;
					lazy[2*treeindex+1].type=type;
				}else{
					lazy[2*treeindex+1].change+=change;
				}
			}
		}
		lazy[treeindex].change=0;
	}
	if(start>high || end<low){
		return 0;
	}
	if(start>=low && high>=end){
		return tree[treeindex].sum_of_squares;
	}
	int mid=(start+end)/2;
	int ans=query(tree,lazy,start,mid,low,high,2*treeindex);
	int ans1=query(tree,lazy,mid+1,end,low,high,2*treeindex+1);
	return ans+ans1;
}

// Update on Segment Tree

void update(int*arr,segmenttree*tree,lazytree*lazy,int start,int end,int low,int high,int change,int type,int treeindex){
	if(lazy[treeindex].change!=0){
		int change=lazy[treeindex].change;
		int type=lazy[treeindex].type;
		if(lazy[treeindex].type==0){
			tree[treeindex].sum_of_squares=(end-start+1)*change*change;
			tree[treeindex].sum_of_element=(end-start+1)*change;
			if(start!=end){
				lazy[2*treeindex].change=change;
				lazy[2*treeindex].type=type;
				lazy[2*treeindex+1].change=change;
				lazy[2*treeindex+1].type=type;
			}
		}
		else{
			tree[treeindex].sum_of_squares+=((end-start+1)*change*change)+(2*change*tree[treeindex].sum_of_element);
			tree[treeindex].sum_of_element+=(end-start+1)*change;
			if(start!=end){
				if(lazy[2*treeindex].change==0 || lazy[2*treeindex].type==1){
					lazy[2*treeindex].change+=change;
					lazy[2*treeindex].type=type;
				}else{
					lazy[2*treeindex].change+=change;
				}
				if(lazy[2*treeindex+1].change==0 || lazy[2*treeindex+1].type==1){
					lazy[2*treeindex+1].change+=change;
					lazy[2*treeindex+1].type=type;
				}else{
					lazy[2*treeindex+1].change+=change;
				}
			}
		}
		lazy[treeindex].change=0;
	}
	if(start>high || end<low){
		return;
	}
	if(start>=low && high>=end){
		if(type==0){
			tree[treeindex].sum_of_squares=(end-start+1)*change*change;
			tree[treeindex].sum_of_element=(end-start+1)*change;
			if(start!=end){
				lazy[2*treeindex].change=change;
				lazy[2*treeindex].type=type;
				lazy[2*treeindex+1].change=change;
				lazy[2*treeindex+1].type=type;
			}
		}else{
			tree[treeindex].sum_of_squares+=((end-start+1)*change*change)+(2*change*tree[treeindex].sum_of_element);
			tree[treeindex].sum_of_element+=(end-start+1)*change;
			if(start!=end){
				if(lazy[2*treeindex].change==0 || lazy[2*treeindex].type==1){
					lazy[2*treeindex].change+=change;
					lazy[2*treeindex].type=type;
				}else{
					lazy[2*treeindex].change+=change;
				}
				if(lazy[2*treeindex+1].change==0 || lazy[2*treeindex+1].type==1){
					lazy[2*treeindex+1].change+=change;
					lazy[2*treeindex+1].type=type;
				}else{
					lazy[2*treeindex+1].change+=change;
				}
			}
		}
		return;
	}
	int mid=(start+end)/2;
	update(arr,tree,lazy,start,mid,low,high,change,type,2*treeindex);
	update(arr,tree,lazy,mid+1,end,low,high,change,type,2*treeindex+1);
	tree[treeindex].sum_of_squares=tree[2*treeindex].sum_of_squares+tree[2*treeindex+1].sum_of_squares;
	tree[treeindex].sum_of_element=tree[2*treeindex].sum_of_element+tree[2*treeindex+1].sum_of_element;
}


// creation of segment tree


void create(int*arr,segmenttree*tree,int start,int end,int treeindex){
	if(start==end){
		tree[treeindex].sum_of_squares=start*start;
		tree[treeindex].sum_of_element=start;
		return;
	}
	int mid=(start+end)/2;
	create(arr,tree,start,mid,treeindex*2);
	create(arr,tree,mid+1,end,2*treeindex+1);
	tree[treeindex].sum_of_squares=tree[treeindex*2].sum_of_squares+tree[2*treeindex+1].sum_of_squares;
	tree[treeindex].sum_of_element=tree[treeindex*2].sum_of_element+tree[2*treeindex+1].sum_of_element;
}
int main() {
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	int case1=1;
	while(t--){
		cout<<"Case "<<case1++<<":"<<endl;
		int n,q;
		cin>>n>>q;
		int*arr=new int[n+1];
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		segmenttree*tree=new segmenttree[2*n];
		lazytree*lazy=new lazytree[2*n]();
		create(arr,tree,1,n,1);
		while(q--){
			int type;
			cin>>type;
			if(type==2){
				int start,end;
				cin>>start>>end;
				cout<<query(tree,lazy,1,n,start,end,1)<<endl;
			}else{
				int start,end,change;
				cin>>start>>end>>change;
				update(arr,tree,lazy,1,n,start,end,change,type,1);
			}
		}
	}
}
