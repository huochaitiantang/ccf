#include<stdio.h>

int n;
int m;
char map[10001][10001];
short degree[10001];

int all_0(int j){
	int i;
	for(i=1;i<=n;i++){
		if(map[j][i]>0) {
			return i;
		}
	}
	return 0;
}

int main(){
	int i,j,x,y,deg,first_odd=0,odd_d=0;
	scanf("%d %d",&n,&m);
//	for(i=1;i<=n;i++) {
//		for(j=1;j<=n;j++) map[i][j] = 0;
//	}
	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		map[x][y] = 1;
		map[y][x] = 1;
		degree[x] ++;
		degree[y] ++;
	}
	if(n > 100){
		printf("-1");return 0;
	}
	for(i=2;i<=n;i++){
		if(degree[i]&1==1) {
			odd_d++;
		}
	}
	//for(i=1;i<=n;i++) {for(j=1;j<=n;j++) printf("%d ",map[i][j]);printf("\n");}
	
//	printf("odd_d: %d\n",odd_d);
	if((odd_d==0&&degree[1]==0) || (odd_d==1 && (degree[1]&1)==1)){
		printf("1");
		i = 1;
		j = all_0(i);
		//printf("\n%d\n",j);
		while(j > 0){
			printf(" %d",j);
			map[i][j] = 0;
			map[j][i] = 0;
			i = j;
			j = all_0(i);
		}
	}
	else{
		printf("-1");
	}
	return 0;
}
