#include<stdio.h>

int n;
int nn[2001];

int main(){
	int i,pre=-1,cur,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&cur);
		if(cur!=pre) ans++;
		pre = cur;
	}
	printf("%d\n",ans);
	
	return 0;
}
