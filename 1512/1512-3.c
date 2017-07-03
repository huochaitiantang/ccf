#include<stdio.h>
typedef struct cc{
	int x,y;
}cord;

int m;
int n;
int p;
char map[101][101];
char flag[101][101];
cord que[10001];

void draw_line(int x1,int y1,int x2,int y2){
	int i,j,min_,max_;
	if(x1==x2){
		min_ = y1>y2?y2:y1;
		max_ = y1>y2?y1:y2;
		for(i=min_;i<=max_;i++){
			if(map[i][x1]!= '-' && map[i][x1]!= '+') map[i][x1] = '|';
			else map[i][x1] = '+';
		}
	}
	else{
		min_ = x1>x2?x2:x1;
		max_ = x1>x2?x1:x2;
		for(i=min_;i<=max_;i++){
			if(map[y1][i]!='|' && map[y1][i]!='+') map[y1][i] = '-';
			else map[y1][i] = '+';
		}
	}
}

void pool(int x,int y,char c){
	int i,j,head=0,tail=0;
	cord cur;
	for(i=0;i<n;i++) for(j=0;j<m;j++) flag[i][j] = 0;
	flag[y][x] = 1;
	que[0].x = x;
	que[0].y = y;
	while(head <= tail){
		cur.x = que[head].x;
		cur.y = que[head++].y;
		if(map[cur.y][cur.x]=='+' || map[cur.y][cur.x]=='|' || map[cur.y][cur.x]=='-') continue;
		map[cur.y][cur.x] = c;
		if(cur.x>0 && flag[cur.y][cur.x-1]==0){
			que[++tail].x = cur.x-1;
			que[tail].y = cur.y;
			flag[cur.y][cur.x-1] = 1;
		}
		if(cur.x<m-1 && flag[cur.y][cur.x+1]==0){ 
			que[++tail].x = cur.x+1;
			que[tail].y = cur.y;
			flag[cur.y][cur.x+1] = 1;
		}
		if(cur.y>0 && flag[cur.y-1][cur.x]==0){
			que[++tail].x = cur.x;
			que[tail].y = cur.y-1;
			flag[cur.y-1][cur.x] = 1;
		}
		if(cur.y<n-1 && flag[cur.y+1][cur.x]==0){ 
			que[++tail].x = cur.x;
			que[tail].y = cur.y+1;
			flag[cur.y+1][cur.x] = 1;
		}	
	}
}

int main(){
	int i,j,k,sw,x,y,c,x1,y1,x2,y2;
	scanf("%d %d %d",&m,&n,&p);
	for(i=0;i<n;i++) for(j=0;j<m;j++) map[i][j]='.';
	for(i=0;i<p;i++){
		scanf("%d",&sw);
		if(sw==0){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			draw_line(x1,y1,x2,y2);
		}
		else{
			scanf("%d %d %c",&x,&y,&c);
			pool(x,y,c);
		}
	}
	for(j=n-1;j>=0;j--){
		for(k=0;k<m;k++) printf("%c",map[j][k]);
		printf("\n");
	}
	
	return 0;
} 
