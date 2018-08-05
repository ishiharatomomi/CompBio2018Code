#include <stdio.h>
#include <math.h>
int main(void){
  int i;
  double x0,x,xx,y0,y,yy,z0,z,zz;
  double r,k;
  double a,b,d1,d2;
  double dt;

  x0=;
  y0=;
  z0=;

  x=x0;
  y=y0;
  z=z0;
  r=1;
  k=100;
  a=;
  b=;
  d1=;
  d2=;
  dt=0.1;

  FILE *fp;
  fp=fopen(".csv","w");
  fprintf(fp,"%f,%f,%f,%f\n",0.0,x,y,z);

  for(i=1;i<1000;i++){

    xx=x+dt*r*(1-x/k)*x-a*x*y;
    yy=y+dt*(a*x-b*z-d1)*y;
    zz=z+dt*(b*z-d2)*z;

    x=xx;
    y=yy;
    z=zz;

    fprintf(fp,"%f,%f,%f,%f\n",dt*i,x,y,z);
  }
  fclose(fp);
  return 0;
}
