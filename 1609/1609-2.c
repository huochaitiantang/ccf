#include<stdio.h>

int n;
int nn[100];
char flag[21][6];

int enough(int r,int n){
	int i,j;
	for(i=1;i<=6-n;i++){
		for(j=i;j<i+n;j++){
			if(flag[r][j]!=0) break;
		}
		if(j == i+n) return i;
	}
	return 0;
}

int main(){
	int i,j,k,ee,less;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&nn[i]);
	for(i=0;i<n;i++){
		for(j=1;j<=20;j++){
			ee = enough(j,nn[i]);
			if(ee) break;  
		}
		if(j<=20){
			for(k=0;k<nn[i];k++){
				flag[j][ee+k] = 1;
				printf("%d ",ee+k+(j-1)*5);
			}
			printf("\n");
		}
		else{
			less = nn[i];
			for(j=1;j<=20;j++){
				for(k=1;k<=5;k++){
					if(flag[j][k] == 0){
						less-=1;
						flag[j][k] = 1;
						printf("%d ",k+(j-1)*5);
					}
					if(less == 0) break;
				}
				if(less==0) break;
			}
			printf("\n"); 
		}
		
	}
	return 0;
	
}
