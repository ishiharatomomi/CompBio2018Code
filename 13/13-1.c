#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int main(void){

    FILE *fp;
    fp=fopen("13-1-1.csv","w");

int i;
double t,tt;
double x[2],xx[2];
double a,b;
double e[3];
double ran,ran2;

a=0.00055;
b=0.0006;
x[0]=100;
x[1]=100;
t=0;

fprintf(fp,"%f,%f,%f\n",t,x[0],x[1]);
srand((unsigned)time(NULL));

//各イベントの確率を設定
for (i=0; i<100000; i++){
     e[1]=a*x[0]*x[1];
     e[2]=b*x[0]*x[1];
     e[0]=e[1]+e[2];

//次のイベントまでのタイムステップを設定
     ran=(double)rand()/RAND_MAX;
     while (ran==0||ran==1) {
       ran=(double)rand()/RAND_MAX;
     }
     tt=t+log(1/ran)/e[0];
     t=tt;

//確率に応じてイベントを設定
     ran2=(double)rand()/RAND_MAX;

     if (0<=ran2 && ran2<=e[1]/e[0]) {
       xx[0]=x[0]-1;
       x[0]=xx[0];
     }
         else{
            xx[1]=x[1]-1;
            x[1]=xx[1];
         }

         if (x[0]==0 || x[1]==0)
         break;

        fprintf(fp,"%f,%f,%f\n",t,x[0],x[1]);
}
    fclose(fp);
  return 0;
}
