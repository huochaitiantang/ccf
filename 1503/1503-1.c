#include<stdio.h>

int n,m;
int val[2000][2000];

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",&val[i][j]);
	
	for(j=m-1;j>=0;j--){
		for(i=0;i<n;i++)
			printf("%d ",val[i][j]);
		printf("\n");
	}
	
	return  0;
}
 
