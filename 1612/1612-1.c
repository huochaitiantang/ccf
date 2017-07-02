#include<stdio.h>
int n;
int val[2000];
int book[1001];

int getnum(int x){
	int i,cnt = 0;;
	for(i=1;i<x;i++){
		cnt += book[i];
	}
	if(cnt == n-book[x]-cnt) return 1;
	else return 0;
}

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&val[i]);
		book[val[i]] ++;
	}
	for(i=1;i<=1000;i++){
		if(book[i]>0 && getnum(i)==1){
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	
	return 0;
} 
