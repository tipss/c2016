
#include <stdio.h>
#include <stdlib.h>

int main() {

// Swap endian (big to little) or (little to big)
uint32_t num = 9;
uint32_t b0, b1, b2, b3;
uint32_t res;

b0 = (num & 0x000000ff) << 24u;
b1 = (num & 0x0000ff00) << 8u;
b2 = (num & 0x00ff0000) >> 8u;
b3 = (num & 0xff000000) >> 24u;

res = b0 | b1 | b2 | b3;

printf("%" PRIX32 "\n", res);
/*
https://stackoverflow.com/questions/19275955/convert-little-endian-to-big-endian/19276193
*/
}
