#include <stdio.h>
int main(void) {
  int t,k,x;
  double r;
 FILE *fp;

t=0;
r=1.0;
k=100;
x=1;
x=x+r*(1-x/k)*x;
fp=fopen("output.dat","w");
fprintf(fp,"%d %d\n",t,x);
fclose(fp);
fp=fopen("output.dat","a");

for(t=0;t<30;t++){
  x=x+r*(1-x/k)*x;
fprintf(fp,"%d\n",x);
}
fclose(fp);
  return 0;
}
