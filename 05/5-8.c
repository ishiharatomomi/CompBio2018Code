#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50
#define k 15

int main(){
int a[N],aa[N],i,t,r1,r2,r,sum,tsum=0,c,count=0;
double ave;
srand(time(NULL));

  for(c=0;c<100;c++){
    for(i=0;i<N;i++){
      if(i<k){
        a[i]=1;
      }
  else{
    a[i]=0;
  }
  }
  for(i=0;i<N;i++){
// printf("%d ",a[i]);
}
// printf("\n");

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
sum=sum+a[i];
}
if(sum==N){
count++;
tsum=tsum+(t+1);
printf("%d\n",t+1);
break;
}
}
}
ave=(double)tsum/(double)count;
printf("%d %d %.3f\n",count,tsum,ave);
return 0;
}
