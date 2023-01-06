#include<bits/stdc++.h>
using namespace std;

#define N 4

void printSolution (int** solution, int n){

	for (int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			cout << solution[i][j] << " ";
		}
		cout<<endl;
	}
	
}


void mazeHelp(int maze[][N], int n, int** solution, int x, int y){


if(x==n-1 && y== n-1){
	solution[x][y] =1;
	printSolution(solution, n);
	solution[x][y]=0;		//not neccessary
	return;
}

if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1 )
	return;

solution[x][y]=1;
mazeHelp(maze, n, solution, x-1,y); 	 // for upward movement
mazeHelp(maze, n, solution, x+1,y );	 // for downward movement
mazeHelp(maze, n, solution, x, y-1);	 // for left movement
mazeHelp(maze, n, solution, x, y+1);	 // for right mvement
solution[x][y]=0;						 //explored, now resusable for others
}



void ratInAMaze(int maze[][N], int n){

	
	int** solution=new int*[n];
	for(int i=0; i<n; i++)
	{
		solution[i] = new int[n];
		 
	}

	for (int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			 solution[i][j]=0; 
		}
	}
	mazeHelp(maze,n,solution, 0,0);

}

int main(){
	

    
    int maze[N][N] = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };

    ratInAMaze(maze, N);
	return 0;
}