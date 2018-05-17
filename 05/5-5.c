#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

int r,M,N,x,i,a;
double b,c;
srand(time(NULL));
M=1;
N=6;
b=0;

for (a = 0; a < 1000; a++) {
  x=0;
for (i = 0; i < 100 ; i++) {
  r=rand()%(N-M+1)+M;
  x=x+r;
  if (x>=100) {
    //printf("%d\n",i);
    b=b+i;
    break;
}
}
}
c=b/1000;
printf("average=%.1f\n",c);

  return 0;
}
