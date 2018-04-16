#include <stdio.h>
int main(void) {
 FILE *fp;
fp=fopen("hello.dat","w");
  fprintf(fp,"Hello,World!\n");
fclose(fp);
  return 0;
}
