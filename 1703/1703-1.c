#include<stdio.h>
int n;
int k;
int xx[2000];

int main(){
	int i,j,tmp,cnt=0,cur=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&xx[i]);
		//xx[tmp] ++;
	} 
	
//	for(i=0;i<n;i++){
//		for(j=i+1;j<n;j++){
//			if(xx[i]>xx[j]){
//				tmp = xx[i];
//				xx[i] = xx[j];
//				xx[j] = tmp;
//			}
//		}
//	}
	
//	for(i=0;i<n;i++) printf("%d ",xx[i]);
//	printf("\n");
	
//	for(i=1;i<2000;i++){
//		for(j=0;j<xx[i];j++){
//			cur += i;
//			if (cur >= k){
//				//printf(":: %d %d %d %d\n",cnt,cur,i,j);
//				cnt ++;
//				cur  = 0;
//			}
//		}
//	}
	
	for(i=0;i<n;i++){
		if(cur >= k){
			cnt ++; cur = 0;
		}
		cur += xx[i];
	}
	
	cnt = (cur > 0)?(cnt+1):cnt;
	printf("%d",cnt);
	
	return 0;
} 
