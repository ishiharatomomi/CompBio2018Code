#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

  FILE *fp;
  fp=fopen("output_5-6(5).csv","w");

int r,x,i;
srand(time(NULL));
x=0;

for (i = 0; i < 100 ; i++) {
  r=rand()%2;
  if (r==0) {
    x=x+1;
}
else{
  x=x-1;
}
fprintf(fp,"%d\n",x);
}


  return 0;
}
