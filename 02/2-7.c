#include <stdio.h>
int main(void) {
  int t;
  double r,k,x,xx;
 FILE *fp;

t=0;
r=2.0;
k=100;
x=10.0;
x=x+r*(1-x/k)*x;
fp=fopen("output.dat","w");
fprintf(fp,"%f\n",x);
fclose(fp);
fp=fopen("output.dat","a");

for(t=0;t<300;t++){
  xx=x+r*(1-x/k)*x;
  x=xx;
fprintf(fp,"%f\n",x);
}
fclose(fp);
  return 0;
}
