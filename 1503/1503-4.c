#include<stdio.h>

int n;
int m; 
int mm[10001];
short dis[10001][10001];

int main(){
	int i,j,tmp,max_c=0,cur_c;
	scanf("%d %d",&n,&m);
	dis[1][1] = 0;
	for(i=2;i<=n;i++){
		scanf("%d",&tmp);
		dis[i][i] = 0;
		for(j=1;j<i;j++){
			dis[i][j] = dis[tmp][j]+1;
			dis[j][i] = dis[i][j];
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d",&tmp);
		mm[i] = tmp; 
	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(dis[i][j]>max_c) max_c = dis[i][j];
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cur_c = dis[mm[i]][j]+1;
			if(cur_c > max_c) max_c = cur_c;
		}
	}
	for(i=1;i<=m;i++){
		for(j=i+1;j<=m;j++){
			cur_c = dis[mm[i]][mm[j]] +2;
			if(cur_c > max_c) max_c = cur_c;
		}
	}
	printf("%d\n",max_c);
	return 0;
}
