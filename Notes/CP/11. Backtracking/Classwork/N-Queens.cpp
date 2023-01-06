// N-Queen Problem:

//We proceed through a row and then proceed further row, if all the options
// in that row is not posssible then t means that we had taken wrong choices earlier..

//Code:

#include<bits/stdc++.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int column){

	//check for same column:
	for(int i=row-1; i>=0; i++){
		if(board[row][column]==1)
			return false;
	}

	//Upper Left Diagonal:
	for(int i= row-1, j=column-1;i>=0 && j>=0; i--,j--){
		if(board[i][j]==1)
			return false;
	}

	//Upper Right Diagonal:
	for(int i=row-1, j=column-1; i>=0 && j<n; j++, i--){
		if(board[i][j]==1)
			return false;
	}
return true;
}



void nQueenHelper(int n, int row) {
	if(row==n){
		//We ahve reached some solution
		//Print the board matrix
		//return

		for(int i=0; i<n;i++){
			for(int j=0; j<n; j++){
				cout << board[i][j]<< " ";
			}
		}
		cout << endl;
		return; 

	}
	//Place At All possible positions and move to smaller problem.
	for(int j=0; j<n; j++){
		if(isPossible(n, row, j)){
			board[row][j]=1;
			nQueenHelper(n,row+1);
			board[row][j]=0;
		}

	}
	return;


}

int placeNQueens(int n){

memset(board,0,11*11*sizeof(int));
nQueenHelper(n,0);

}

int main(){
	freopen("output.txt", "w", stdout);
	placeNQueens(9);
}
