#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

int r,i,t;
t=time(NULL);
srand(t);

for (i = 0; i < 100 ; i++) {
  r=rand();
  printf("%d\n",r);
}
  return 0;
}
