#include<stdio.h>

int n;
int val[2000];

int main(){
	int i,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&val[i]);
	for(i=1;i<n-1;i++){
		if((val[i]>val[i-1] && val[i]>val[i+1])||(val[i]<val[i-1]&&val[i]<val[i+1])) cnt+=1;
	} 
	printf("%d",cnt);
	return 0;
	
} 
