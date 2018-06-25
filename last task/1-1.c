#include<stdio.h>

int main(int argc, char const *argv[]) {

int i,j,k;
double t,dt;
double x[3];
double xx[3];
double a,b,c,d,e,f,g,h;

FILE *fp;
fp=fopen("output_1-1.4.csv","w");

dt=0.01;
a=2.5; //生産者の成長率
b=5.0; //産者の収容力K
c=1.0; //m1
d=2.0;//a1
e=1.0;//m2
f=2.0;//a2
g=0.05;//d1(一次消費者の死亡率)
h=0.5;//d2（二次消費者の死亡率）


t=0.0;
x[0]=5;
x[1]=0.5;
x[2]=0.1;

fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);


for (i=1;i<=100000;i++) {
t=dt*i;
xx[0]=x[0]+dt*(a*x[0]*(1-x[0]/b)-c*x[0]*x[1]/(d+x[0])); //被食者の式
xx[1]=x[1]+dt*((c*x[0]/(d+x[0])-g)*x[1]-e*x[1]*x[2]/(f+x[1])); //捕食者の式
xx[2]=x[2]+dt*((e*x[1]/(f+x[1])-h)*x[2]);
x[0]=xx[0];
x[1]=xx[1];
x[2]=xx[2];

if (i%100==0) {   //100回に一回出力している
  fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);
}
}
fclose(fp);

  return 0;
}
