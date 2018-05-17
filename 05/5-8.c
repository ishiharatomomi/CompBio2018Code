#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
#define k 10

int main(){
int a[N],aa[N],i,t,r1,r2,r,x,y=0,c,count=0;
double T,p;
srand(time(NULL));
p=(double)k/(double)N;

  for(c=0;c<500;c++){
    while (count<100) {
    for(i=0;i<N;i++){
      if(i<k){
        a[i]=1;
      }
  else{
    a[i]=0;
  }
  }

for(t=0;t<100;t++){
sum=0;
for(i=0;i<N;i++){
r1=rand()%N;
r2=rand()%N;
r=rand()%2;
if(r==0){
aa[i]=a[r1];
}
if(r==1){
aa[i]=a[r2];
}
}
for(i=0;i<N;i++){
a[i]=aa[i];
// printf("%d ",a[i]);
}
// printf("\n");
for(i=0;i<N;i++){
x=x+a[i];
}
if(sum==N){
count++;
y=y+(t+1);
printf("%d\n",t+1);
break;
}
}
}
}
T=(double)y/(double)count;
printf("%d %d %.3f\n",count,y,T);
printf("%f\n",p);
return 0;
}
