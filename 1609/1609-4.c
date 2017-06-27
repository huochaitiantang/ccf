#include<stdio.h>

int n;
int m;
short map[10001][10001];
int dis[10001];
int pre[10001];
short que[100000];
char flag[10001];

//shortest path to s
void spfa(int s){
	int i,cur,head=0,tail=0;

	for(i=1;i<=n;i++) {
		flag[i] = 0;
		dis[i] = -1;
		pre[i] = -1;
	}
	que[0] = s; flag[s] = 1; dis[s] = 0;
	while(head <= tail){
		printf("*\n");
		cur = que[head++];
		flag[cur] = 0;
		for(i=1;i<=n;i++){
			if(map[cur][i] <= 0 || i == cur) continue;
			if(	(dis[i] < 0 )|| 
				(dis[i] >0 && map[cur][i]+dis[cur] < dis[i]) ||
				(dis[i] >0 && map[cur][i]+dis[cur] == dis[i] && map[cur][i] < map[pre[i]][i]) ){
				pre[i] = cur;
				dis[i] = map[cur][i] + dis[cur];
				if(flag[i] == 0){
					que[++tail] = i;
					flag[i] = 1;
				}
			}
		}
	}
}

int main(){
	int i,j,x,y,c,cnt=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++) map[i][j] = -1;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&c);
		map[x][y] = c;
		map[y][x] = c;
	}
	spfa(1);
	for(i=1;i<=n;i++){
		//printf("%d >> %d\n",pre[i],i);
		if(pre[i]>=1) cnt += map[i][pre[i]];
	}
	printf("%d\n",cnt);
}

