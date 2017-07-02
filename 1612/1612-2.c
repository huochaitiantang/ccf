#include<stdio.h>
int sta[7];
int x[7] = {3500,5000,8000,12500,38500,58500,83500};
int xx[7] = {0,1500*0.03,3000*0.1,4500*0.2,26000*0.25,20000*0.3,25000*0.35};
float rai[7] = {0.03,0.1,0.2,0.25,0.3,0.35,0.45};
int n;

int main(){
	int i,cur=0;
	scanf("%d",&n);
	sta[0] = 3500;
	for(i=0;i<=6;i++){
		cur += xx[i];
		sta[i] = x[i] - cur; 
	}
	for(i=0;i<7;i++){
		if(n<sta[i]) break;
	}
	if(i==0) printf("%d",n);
	else if(i<=7){
		//printf("%d %d %d\n",i,n-sta[i-1],x[i-1]);
		printf("%d",x[i-1]+(int)((float)(n - sta[i-1])/(1-rai[i-1])));
	}
	
	return 0;
} 
