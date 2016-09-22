#include <stdio.h>
#include <stdlib.h>
/* Write an algorithm, where given a matrix with mxn rows and columns, if there exist
* an element whose value is zero, then its entire row and colum will be set to zero
* 2 3 4 5       2 3 0 5
* 4 5 0 7   =>  0 0 0 0
* 9 2 1 3       9 2 0 3 
*
*/



//1. make a copy of elements whose values are zero, in a single dimension array,
//2. walk each array, zero respecitve row or column.

void matrix_zero(int rows, int columns, int m[][columns]) {
  int zero_rows[rows];
  int zero_columns[columns];

  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      printf(" %-2d",m[i][j]);
      if (m[i][j] == 0) {
	zero_rows[i]    = 1;
	zero_columns[j] = 1;
      }
    }
    printf("\n");
  }
  //Walk rows and zero columns
  for (int i=0;i<rows;i++) {
    if(zero_rows[i] == 1){
      for(int j=0; j<columns; j++){
	m[i][j]=0;
      }
    }

  }
  //Walk column and zero rows
  for (int i=0;i<columns;i++) {
    if(zero_columns[i] == 1){
      for(int j=0; j < rows; j++){
	m[j][i]=0;
      }
    }

  }

  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      printf(" %-2d",m[i][j]);
    }
    printf("\n");
  }

}

int main(int argc, char *argv[]){
   int m[][4] = { {1,2,3,4}, {5,0,0,8}, {9,10,11,12}}; 
   matrix_zero(3,4 ,m);
 }
