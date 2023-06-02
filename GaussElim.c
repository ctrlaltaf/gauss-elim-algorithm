#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void swap(double m[20][20], int rowA, int rowB, int n ){
  for(int col = 1; col <= n + 1; col++){
    double temp = m[rowA][col];
    m[rowA][col] = m[rowB][col];
    m[rowB][col] = temp;
  }

}

int largestCoeff(double m[20][20], int row, int col, int n){
  double largest = fabs(m[row][col]);
  int rowNumber = row;

  for(int i = row + 1; i <= n; i++){
    if(largest < fabs(m[i][col])){
      largest = fabs(m[i][col]);
      rowNumber = i;
    }
  }

  return rowNumber;
}


int main()
{
  char fname[100] ;
  FILE *f ;
  double m[20][20] ;
  int n ;
  int r,c ;

printf("enter the name of the file to be read : ") ;
  if(scanf("%s", fname)){};
  f = fopen(fname, "r") ;
  if (f == NULL) {
    printf("can't read file\n") ;
    exit(0) ;
  }
  
  if(fscanf(f,"%d",&n)){};
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      if(fscanf(f,"%lf", &m[r][c])){};
    }
  }

  printf("\n") ;
  printf("Matrix to solve\n") ;  
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      printf("%10.5lf", m[r][c]) ;
    }
    printf("\n") ;
  }  
  printf("\n") ;

  

  double solutions[100];

  //given n number of systems of equations,
  //we have to eliminate each column at a time
  for(int col = 1, row = 1; col < n; col++,row++){

    //we want to find the equation with the largest abs of leading coeff
    int rowSwap = largestCoeff(m, row, col, n);

    swap(m, row, rowSwap, n);

    //we store the coefficient of the diagonal at i
    double coeff = m[row][col];

    //we perform gauss elimination on each of the equations

    for(int nextRow = row + 1; nextRow <= n; nextRow++){
      //must scale all variables in each equation
      if(m[nextRow][col] != 0 ){
        double scaleFactor = coeff/m[nextRow][col];

        for(int j = 1; j <= n + 1; j++){
          m[nextRow][j] = m[nextRow][j] * scaleFactor;
        }

        //must also add two equations together w/ their corresponding pairs
        for(int j = 1; j <= n + 1; j++){

          m[nextRow][j] = m[row][j] - (m[nextRow][j]);

        }
      }

    }

  }

  printf("Upper Trriangular Matrix \n") ;  
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      printf("%10.5lf", m[r][c]) ;
    }
    printf("\n") ;
  }  
  printf("\n") ;


  //must check if the system is consistent or not
  int indicator = 1;
  for(int i = 1; i <= n; i++){

      if(m[i][i] == 0.0){
      printf("inconsistent System\n");
      indicator = 0;
      return(0);
    }
  }
  
  
  //we do back substitution starting from the bottom equation
  printf("SOLUTION MATRIX\n");
  if(indicator == 1){
    for(int r = n ; r >= 1; r--){
      double sum = 0;

      for(int c = r + 1; c <= n; c++){
        sum += solutions[c] * m[r][c];
      }

      solutions[r] = (m[r][n+1] - sum)/(m[r][r]);
      printf("[%lf]\n", solutions[r]);
    }
  }


}
