#include<stdio.h>

int main(int argc, char const *argv[]) {

int i;
double t,dt;
double x[3];
double xx[3];
double a,b;

FILE *fp;
fp=fopen("6-8.csv","w");

dt=0.0001;
a=0.0002;
b=0.2;

t=0.0;
x[0]=1500;   //今後、感染しうる人数
x[1]=5;     //現在感染しており、他者を感染させうる人
x[2]=0;     //今後感染せず、他者を感染させることのない人

fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);


for (i=1;i<=1000000;i++) {
t=dt*i;
xx[0]=x[0]+dt*(-a*x[0]*x[1]); //
xx[1]=x[1]+dt*(a*x[0]*x[1]-b*x[1]); //
xx[2]=x[2]+dt*(b*x[1]);
x[0]=xx[0];
x[1]=xx[1];
x[2]=xx[2];

if (i%1000==0) {   //100回に一回出力している
  fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);
}
}
fclose(fp);

  return 0;
}
