#include <stdio.h>

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

    printf("%ld\n", my_sizeof(y));
    getchar();

    // If Little indian, it will print 1,
    // LSB in Lowest Address = Little Endian
    // MSB in Lowest Address = Big Endian(N/W Byte Order)
    printf ("%d\n", (int) (((char *)&x)[0]));
    printf("Must print 1 if you have machine which is Little Endian\n");


    printf("size of struct t %ld\n",sizeof(struct t));
    return 0;
}
