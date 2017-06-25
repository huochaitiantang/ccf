#include<stdio.h>

int main(){
	int n;
	int nn[1000];
	int mm[10001];
	int i;
	int cnt=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&nn[i]);
	
	for(i=0;i<10001;i++) mm[i] = 0;
	for(i=0;i<n;i++) mm[nn[i]] += 1;
	for(i=1;i<10000;i++){
		cnt += mm[i]*mm[i+1];
	}
	printf("%d\n",cnt);

	return 0;


}
