#include	<stdio.h>

int	main(){
int	i,j;
int	t;
double	dt=0.01;
double	u[100][100];
double  v[100][100];
double	utemp[100][100];
double  vtemp[100][100];
double	Du=0.4;
double  Dv=0.8;

FILE	*fp;
fp=fopen("11-2.csv","w");// 書き込みファイル

//初期化（すべての格子を1にする）
for(i = 0; i < 100; i++) {
for( j = 0; j < 100; j++) {
      u[i][j]=1.005;
      v[i][j]=1.01;
  }
}

u[49][49]=0.05;
u[49][50]=1.001;
u[50][49]=1;
u[50][50]=1;
v[49][49]=1;
v[49][50]=1;
v[50][49]=0.97;
v[50][50]=0.79;
u[5][5]=0.5;
u[5][6]=0.5;
u[6][5]=0.5;
u[6][6]=0.5;
u[11][11]=0.5;
u[57][59]=1.01;
u[10][30]=0.77;
u[70][30]=0.33;



//初期値出力
 for(i=0;i<100;i++){
    for(j=0;j<100;j++){
        fprintf(fp,"%f",u[i][j]);
          if(j!=99){
            fprintf(fp,"	,");
          }
          }
    fprintf(fp,"\n");
  }

 for(t=1;t<100000;t++){//tをもっと大きくすると、濃度が全体で均一になるまでいく
  // 境界条件１  (i=0,j=0)　　周期境界条件になっている
    i=0;
    j=0;
    utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(v[99][j]+v[i+1][j]+v[i][99]+v[i][j+1]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
  // 境界条件２ （i=0,j=99）
    i=0;
    j=99;
    utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(v[99][j]+v[i+1][j]+v[i][j-1]+v[i][0]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
  // 境界条件３（i=99,j=0）
    i=99;
    j=0;
    utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][99]+u[i][j+1]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[0][j]+v[i][99]+v[i][j+1]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);

  // 境界条件４(i=99,j=99)
    i=99;
    j=99;
    utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][0]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[0][j]+v[i][j-1]+v[i][0]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
  //　境界条件５　(i=0)
    i=0;
    for(j=1;j<99;j++){
        utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
        vtemp[i][j]=v[i][j]+dt*(Dv*(v[99][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

  // 境界条件6（i=99）
    i=99;
    for(j=1;j<99;j++){
        utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
        vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[0][j]+v[i][j-1]+v[i][j+1]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

  //境界条件７（j=0）
    j=0;
    for(i=1;i<99;i++){
        utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
        vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[i+1][j]+v[i][99]+v[i][j+1]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }

  // 境界条件８(j=99)
    j=99;
    for(i=1;i<99;i++){
        utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
        vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][0]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
    }
  //その他
    for(i=1;i<99;i++){
        for(j=1;j<99;j++){
          utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+(u[i][j]*u[i][j])/(v[i][j])-u[i][j]);
          vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-4*v[i][j])+u[i][j]*u[i][j]-v[i][j]);
        }
    }
  //更新
  for(i=0;i<100;i++){
      for(j=0;j<100;j++){
          u[i][j]=utemp[i][j];
          v[i][j]=vtemp[i][j];
        }
      }
    //出力（500ループに一回）
if(t%1000==0){
      for(i=0;i<100;i++){
for(j=0;j<100;j++){
  fprintf(fp,"%f",u[i][j]);
    if(j!=99){
      fprintf(fp,"	,");
      }
}
fprintf(fp,"\n");
       }
     }
}
fclose(fp);
return	0;
}
