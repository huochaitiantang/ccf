#include<stdio.h>

int n;
int val[2000];
int book[2000];

int main(){
	int i,j,cur,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&cur);
		book[cur] ++;
	}
	for(i=1;i<=1000;i++) val[i] = i;
	for(i=1;i<=1000;i++){
		for(j=i+1;j<=1000;j++){
			if( (book[val[i]] < book[val[j]])||
				(book[val[i]] == book[val[j]] && val[i] > val[j])){
				tmp = val[i];
				val[i] = val[j];
				val[j] = tmp;
			}
		}
	}
	
	for(i=1;i<=1000;i++){
		if(book[val[i]] > 0){
			printf("%d %d\n",val[i],book[val[i]]);
		}
	}
	
	return 0;
}
