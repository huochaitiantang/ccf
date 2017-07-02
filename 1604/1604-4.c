#include<stdio.h>
typedef struct ss{
	char x;
	char y;
} cord;

typedef struct cc{
	char start;
	char end;
	char flag;
} time;

typedef struct xx{
	cord loc;
	int deep;
} queu;

int n;
int m;
int t;
time tim[101][101];
queu que[100000000];

int danger(int x,int y, int deep){
	if(tim[x][y].flag == 1 && deep >= tim[x][y].start && deep <= tim[x][y].end) return 1;
	else return 0;
}



int getdis(cord p1,cord p2){
	int i,j,head=0,tail=0;

	queu cur;
//	char flag[101][101];
//	for(i=1;i<=n;i++) for(j=1;j<=m;j++) flag[i][j] = 0;
//	flag[p1.x][p1.y] = 1; 
	que[0].loc.x = 1;
	que[0].loc.y = 1;
	que[0].deep = 0;
	while(head<=tail){
		cur.loc.x = que[head].loc.x;
		cur.loc.y = que[head].loc.y;
		cur.deep = que[head].deep;
		head ++;
		//printf("(%d,%d)[%d]\n",cur.loc.x,cur.loc.y,cur.deep);
		if(cur.loc.x == p2.x && cur.loc.y == p2.y) return cur.deep;
		if(cur.loc.x > 1 && !danger(cur.loc.x-1,cur.loc.y,cur.deep+1)){
			que[++tail].loc.x = cur.loc.x-1;
			que[tail].loc.y = cur.loc.y;
			que[tail].deep = cur.deep + 1;
		}
		if(cur.loc.y > 1 && !danger(cur.loc.x,cur.loc.y-1,cur.deep+1)){
			que[++tail].loc.x = cur.loc.x;
			que[tail].loc.y = cur.loc.y-1;
			que[tail].deep = cur.deep + 1;
		}
		if(cur.loc.x < n && !danger(cur.loc.x+1,cur.loc.y,cur.deep+1)){
			que[++tail].loc.x = cur.loc.x+1;
			que[tail].loc.y = cur.loc.y;
			que[tail].deep = cur.deep + 1;
		}
		if(cur.loc.y < m && !danger(cur.loc.x,cur.loc.y+1,cur.deep+1)){
			que[++tail].loc.x = cur.loc.x;
			que[tail].loc.y = cur.loc.y+1;
			que[tail].deep = cur.deep + 1;
		}
	}
	return 0;
}

int main(){
	int i,j,x,y,s,e;
	cord src,des;
	scanf("%d%d%d",&n,&m,&t);
	for(i=0;i<t;i++) {
		scanf("%d %d %d %d",&x,&y,&s,&e);
		tim[x][y].start = s;
		tim[x][y].end = e;
		tim[x][y].flag = 1;
	}
	src.x=1;src.y=1;
	des.x=n;des.y=m;
	printf("%d\n",getdis(src,des));
	
	return 0;
} 
