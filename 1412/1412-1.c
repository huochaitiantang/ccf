#include<stdio.h>

int n;
int nn[1001];
int ss[1001];

int main(){
	int i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&nn[i]);
	}
	for(i=0;i<n;i++){
		ss[nn[i]]++;
		printf("%d ",ss[nn[i]]);
	}
	return 0;
}
