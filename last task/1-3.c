#include <stdio.h>
#include <math.h>
int main(void){
  int i;
  double x0,x,xx,y0,y,yy,z0,z,zz;
  double r,k;
  double a,b,d1,d2;
  double dt;

  x0=10000.0;
  y0=20.0;
  z0=1.0;

  x=x0;
  y=y0;
  z=z0;
  r=0.01;
  k=100000;
  a=0.00001;
  b=0.0005;
  d1=0.1;
  d2=0.05;
  dt=0.01;

  FILE *fp;
  fp=fopen("1-3-1.csv","w");
  fprintf(fp,"%f,%f,%f,%f\n",0.0,x,y,z);

  for(i=1;i<100000;i++){

    xx=x+dt*(r*(1-x/k)*x-a*x*y);
    yy=y+dt*(a*x-b*z-d1)*y;
    zz=z+dt*(b*z-d2)*z;

    x=xx;
    y=yy;
    z=zz;
    if (i%100==0) {   //100回に一回出力している
    fprintf(fp,"%f,%f,%f,%f\n",dt*i,x,y,z);
  }
  }
  fclose(fp);
  return 0;
}
