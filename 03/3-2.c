#include<stdio.h>

 int main(void) {
int i;
for (i=0;i<10;i++){
printf("%d: ",i);
  if(i>5){
 printf("iは5よりおおきい,");
  }
  if (i==3) {
    printf("iは３と等しい,");
  }
if ((i>=3)&&(i<=6)){
  printf("iは3以上6以下,");
}
if (!(i==1||i==2)){
printf("iは1でも2でもない,");
}
printf("\n");
}
     return 0;
}
