#include<stdio.h>

int n;
int m;
short map[1001][1001];
char isi[1001];
char flag[1001];

int main(){
	int i,j,x,y,c,cur,mine,cnt=0,num;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&c);
		map[x][y] = c;
		map[y][x] = c;
	}
	isi[0] = 1;
	flag[1] = 1;
	num = 1;
	while(num < n){
		mine = 20000;
		for(i=0;i<num;i++){
			cur = isi[i];
			for(j=1;j<=n;j++){
				//printf("  (%d %d) %d %d\n",cur,j,map[cur][j],mine);
				if(flag[j] == 0 && map[cur][j] > 0 && map[cur][j] < mine){
					
					mine = map[cur][j];
					x = cur;y = j;
				}
			}
		}
		printf("  %d (%d %d) %d\n",num,x,y,map[x][y]);
		flag[y] = 1;
		isi[num] = y;
		num ++;
		cnt += map[x][y];
	}
	printf("%d\n",cnt);
	
	
	return 0;
} 
