#include <stdio.h>
#include <stdbool.h>


typedef struct {
	int x;
	float y;
	char z;
} mystruct;

typedef union {
	int   x;
	float y;
	char  z;
} myunion;

typedef struct {
	char *name;
	bool isrobot;
	union {
		char *personality;
		int firmware_version;
	};
} character;

int main( ) {
	
	printf("size of struct %lu\n", sizeof(mystruct));
	printf("size of union %lu\n", sizeof(myunion));

	mystruct s={0};
	mystruct u={0};
	u.x = 45454545;
	u.y = 9.87777777;
	u.z = 'H';

	s.x = 45;
	s.y = 9.87;
	s.z = 'H';
	printf("%d, %f, %c struct\n", s.x, s.y, s.z);
	printf("%d, %f, %c union\n",u.x, u.y, u.z);
}
