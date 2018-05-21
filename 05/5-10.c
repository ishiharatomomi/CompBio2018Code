#include<stdio.h>
#include<math.h>
#define N 200
#define k 1

int main(int argc, char const *argv[]) {
int i;
double p,T;

//FILE *fp;
//fp=fopen("output_5-10(1).csv","w");

for (i = 1; i < 100; i++) {

p=(double)i/100;

T=-(1/p)*(2*N*(1-p)*log(1-p));

//fprintf(fp,"%f\n",T);

//}
printf("%f\n",T );
//fclose(fp);
}
  return 0;
}
