#include<stdio.h>
#include<math.h>

 int main(void) {
int i;
double x0,xa,x,xx,k,r;
double dt;
x0=10.0;
x=x0;
xa=x0;
k=100.0;
dt=1.0;
r=1.0;

FILE *fp;
fp=fopen("3-7.dat","w");
fprintf(fp,"%f,%f,%f\n",0.0,xa,x);

for (i=1;i<10;i++){
xa=k/(1+(k/x0-1)*exp(-r*dt*i));
xx=x+dt*r*(1-x/k)*x;
x=xx;

fprintf(fp,"%f,%f,%f\n",dt*i,xa,x);
  }
fclose(fp);
return 0;
}
