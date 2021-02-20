//SUDOKU SOLVER Backtraking technique

#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n, int number){

	//checking for rows and column of the current element
	for(int x=0;x<n;x++){
		if(mat[x][j]==number || mat[i][x]==number){
			return false;
		} 
	}

	//checking for the subgrid 
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;
	for(int x=sx ; x<sx+rn ; x++){
		for(int y=sy ; y<sy+rn ; y++){
			if(mat[x][y]==number){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
	//base case
	if(i==n){
		//print the matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}
	if(j==n){
		//reached end of the row , go to different row
		return solveSudoku(mat,i+1,0,n);
	}
	if(mat[i][j]!=0){
		//already filled 
		//skip it
		return solveSudoku(mat,i,j+1,n);
	}


	//recursive case
	//now fill the current cell if possible 
	for(int number=1;number<=n;number++){
		if(canPlace(mat,i,j,n,number)){
			mat[i][j]=number;
			bool couldWeSolve = solveSudoku(mat,i,j+1,n);
			if(couldWeSolve){
				return true;
			}
			else{
				continue;
			}
		}
	}
	//backtracking
	mat[i][j]=0;
	return false;


}

int main()
{
	int mat[9][9]={
					 {5,3,0,0,7,0,0,0,0}, 
					 {6,0,0,1,9,5,0,0,0}, 
					 {0,9,8,0,0,0,0,6,0},
					 {8,0,0,0,6,0,0,0,3},
					 {4,0,0,8,0,3,0,0,1}, 
					 {7,0,0,0,2,0,0,0,6}, 
					 {0,6,0,0,0,0,2,8,0}, 
					 {0,0,0,4,1,9,0,0,5}, 
					 {0,0,0,0,8,0,0,7,9}
					 						};
	int n;
	cin>>n;
	solveSudoku(mat,0,0,n);
	return 0;	
}
