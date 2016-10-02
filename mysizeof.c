#include <stdio.h>
#include <stdlib.h>
/* Remember this:
int       *      mutable_pointer_to_mutable_int;
int const *      mutable_pointer_to_constant_int;
int       *const constant_pointer_to_mutable_int;
int const *const constant_pointer_to_constant_int;
*/

//Remember this macro
//Remember how to find endian below
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)


int main()
{
    double y;
    unsigned int x = 1;
    struct t {
      char c;
    };
    //How to initialized multidimensional array
    int a[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
    //This also works int a[3][4]={{0,1,2,3,4,5,6,7,8,9,10,11};
    int rows    = 1;
    int columns = 2;
    int start   = 1;
    int i, j;
    // Try remember this,, sizeof(**b) means sizeof(int) in this case
    int **b= NULL;
    b = malloc(sizeof(*b) * rows + (rows * columns * sizeof(**b)));
    printf("sizeof(*b)=%ld sizeof(**b)=%ld total size %ld\n", sizeof(*b), sizeof(**b),
	   (sizeof(*b) * rows + (rows * columns * sizeof(**b))));
    printf("%ld\n", my_sizeof(y));
    getchar();
    //Copy value into 2D array to test
    for(i=0; i<rows; i++) {
      for(j=0; j<columns; j++) {
	printf("Copying b[%d][%d]\n",i,j);
	b[i][j] = start++; //Getting Segmentation fault here, need more work
      } 
      start +=10;
    }
    printf("Printing Two Dimensional array with %d rows and %d columns\n",rows, columns);
    //Print 2D array to verify
    for(i=0; i<rows; i++) {
      for(j=0; j<columns; j++) {
	printf("%d ", b[i][j]);
      }
      printf("\n");
      start +=10;
    }
    // If Little indian, it will print 1,
    // LSB in Lowest Address = Little Endian
    // MSB in Lowest Address = Big Endian(N/W Byte Order)
    printf ("%d\n", (int) (((char *)&x)[0]));
    printf("Must print 1 if you have machine which is Little Endian\n");


    printf("size of struct t %ld\n",sizeof(struct t));
    return 0;
}
