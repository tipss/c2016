#include <stdio.h>
#include <stdlib.h>

typedef struct person {
  char name[10];
  int  id;
} p_t;

int main(void) {
	FILE *out, *data_fp= fopen("person.dat", "w");

	if (data_fp == NULL) {
		printf("Not able to open file");
		return 0;
	}
  
	p_t p1 = {"Ram", 10};
	p_t p2 = {"Sham", 2};
	p_t pr;

	fwrite(&p1, sizeof(struct person), 1, data_fp);
	fwrite(&p2, sizeof(struct person), 1, data_fp);
	printf("Done Writing\n");
	fclose(data_fp);

	/* Open and read now */
	out = fopen("person.dat", "r");
	if (!out) {
		printf("Failed to open fileout");
		return 0;
	}  
	while(fread (&pr, sizeof(struct person), 1, out)) {
		printf("name %s, id %d\n",pr.name, pr.id);
	}
	fclose(out);
}
