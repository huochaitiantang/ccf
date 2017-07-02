#include<stdio.h>
int n;
int val[2000];
int main(){
	int i,max=0,cur;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&val[i]);
	for(i=1;i<n;i++){
		cur = val[i]-val[i-1];
		if(cur < 0) cur = -cur;
		if(cur > max) max = cur;
	}
	printf("%d",max);
	
	return 0;
}
 
