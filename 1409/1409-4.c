#include<stdio.h>
typedef struct cc{
	int x;
	int y;
} cord;

typedef struct cu{
	cord loc;
	int num;
} cust;

typedef struct qq{
	cord loc;
	int deep;
} queu;

int n;
int sto_n;
int cus_n;
int neg_n;
int map[1001][1001];
cord sto[500001];
cust cus[500001];
cord neg[500001];
int flag[1001][1001];
queu que[1000001];

int isNeg(int x,int y){
	int i;
	for(i=0;i<neg_n;i++)
		if(neg[i].x == x && neg[i].y == y) return 1;
	return 0; 
}

int dfs(cord src,cord des){
	int head=0,tail=0,i,j;
	queu cur;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) flag[i][j] = 0;
	que[0].loc.x = src.x;
	que[0].loc.y = src.y;
	que[0].deep = 0;
	flag[src.x][src.y] = 1;
	while(head <= tail){
		cur.loc.x = que[head].loc.x;
		cur.loc.y = que[head].loc.y;
		cur.deep = que[head++].deep;
		//printf("(%d,%d)(%d)",cur.loc.x,cur.loc.y,cur.deep);
		if(cur.loc.x == des.x && cur.loc.y == des.y) return cur.deep;
		if(cur.loc.x>1 && flag[cur.loc.x-1][cur.loc.y] == 0 && isNeg(cur.loc.x-1,cur.loc.y) != 1){
			que[++tail].loc.x = cur.loc.x-1;
			que[tail].loc.y = cur.loc.y;
			que[tail].deep = cur.deep + 1;
			flag[cur.loc.x-1][cur.loc.y] = 1;
		}		
		if(cur.loc.y>1 && flag[cur.loc.x][cur.loc.y-1] == 0 && isNeg(cur.loc.x,cur.loc.y-1) != 1){
			que[++tail].loc.x = cur.loc.x;
			que[tail].loc.y = cur.loc.y-1;
			que[tail].deep = cur.deep + 1;
			flag[cur.loc.x][cur.loc.y-1] = 1;
		}
		if(cur.loc.x<n && flag[cur.loc.x+1][cur.loc.y] == 0 && isNeg(cur.loc.x+1,cur.loc.y) != 1){
			que[++tail].loc.x = cur.loc.x+1;
			que[tail].loc.y = cur.loc.y;
			que[tail].deep = cur.deep + 1;
			flag[cur.loc.x+1][cur.loc.y] = 1;
		}
		if(cur.loc.y<n && flag[cur.loc.x][cur.loc.y+1] == 0 && isNeg(cur.loc.x,cur.loc.y+1) != 1){
			que[++tail].loc.x = cur.loc.x;
			que[tail].loc.y = cur.loc.y+1;
			que[tail].deep = cur.deep + 1;
			flag[cur.loc.x][cur.loc.y+1] = 1;
		}
		
	}
	return 0;
}

int main(){
	int i,j,cur,x,ind;
	int cnt = 0;
	scanf("%d %d %d %d",&n,&sto_n,&cus_n,&neg_n);
	for(i=0;i<sto_n;i++) scanf("%d %d",&sto[i].x,&sto[i].y);
	for(i=0;i<cus_n;i++) scanf("%d %d %d",&cus[i].loc.x,&cus[i].loc.y,&cus[i].num);
	for(i=0;i<neg_n;i++) scanf("%d %d",&neg[i].x,&neg[i].y);
/*	
	printf("%d %d %d %d\n",n,sto_n,cus_n,neg_n);
	for(i=0;i<sto_n;i++) printf("(%d %d)\n",sto[i].x,sto[i].y);
	for(i=0;i<cus_n;i++) printf("(%d,%d) [%d]\n",cus[i].loc.x,cus[i].loc.y,cus[i].num);
	for(i=0;i<neg_n;i++) printf("(%d,%d)\n",neg[i].x,neg[i].y);
*/
	for(i=0;i<cus_n;i++){	
//		printf("Handle cus (%d,%d) [%d]\n",cus[i].loc.x,cus[i].loc.y,cus[i].num);
		cur = -1;
		for(j=0;j<sto_n;j++){
			x = dfs(sto[j],cus[i].loc);	
			if(cur <0 || x < cur){ cur = x; ind = j;}
		}
		if(cur >= 0) {
			printf("Cus(%d,%d) By Sto(%d,%d) [%d]\n",cus[i].loc.x,cus[i].loc.y,sto[ind].x,sto[ind].y,cur);
			cnt += cur*cus[i].num;
		}
	}
	printf("%d\n",cnt);
	return 0;		


}
