#include<stdio.h>

int n;
int m;
char map[10001][10001];
char ist[10001][10001];
char ok[10001];

void cal(int x){
	int i,j,cur,head=0,tail=0;
	char flag[10001];
	short que[10001];
	for(i=1;i<=n;i++) flag[i] = 0;
	flag[x] = 1;
	que[0] = x;
	while(head <= tail){
		cur = que[head++];
		//printf("cur:%d\n",cur);
		for(i=1;i<=n;i++){
			if(map[cur][i] == 1){
				if(flag[i] == 1) continue;
				ist[x][i] = 1;
				flag[i] = 1;
				if(ok[i] == 1){
					for(j=1;j<=n;j++){
						if(flag[j] == 0 && ist[i][j] == 1){
							ist[x][j] = 1;
							flag[j] = 1;
						}
					}
				}
				else{
					que[++tail] = i;
				}
			}
		}
	}
	ok[x] = 1;
}


int main(){
	int i,j,x,y,cnt=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		map[x][y] = 1;
	}
	for(i=1;i<=n;i++) cal(i);
	
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			printf("%d %d : %d %d\n",i,j,map[i][j],ist[i][j]);
//		}
//		printf("\n");
//	}
//	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(ist[i][j] == 1 && ist[j][i]==1){
				//printf("(%d,%d)\n",i,j);
				cnt += 1;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
