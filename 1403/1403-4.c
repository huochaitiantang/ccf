#include<stdio.h>
#include<math.h>

typedef struct cor{
	int x;
	int y;
} cord;

typedef struct qu{
	int d;
	int deep;
} queu;

int n;
int m;
int k;
int r;
cord nn[100];
cord mm[100];
int map[200][200];

int getdis2(cord p1,cord p2){
	return ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int getNumT(int N){
	int i,head=0,tail=0;
	queu cur;
	queu que[200];
	int flag[200];
	for(i=0;i<N;i++) flag[i] = 0;
	que[0].d = 0;
	que[0].deep = -1;
	flag[0] = 1;
	while(tail >= head){
		cur.deep = que[head].deep;
		cur.d = que[head++].d;
		if(cur.d == 1) break;
		for(i=0;i<N;i++){
			if(i != cur.d && flag[i] != 1 && map[cur.d][i] == 1){
				que[++tail].d = i;
				que[tail].deep = cur.deep + 1;
				flag[i] = 1;
			}
		}
	}
	return cur.deep;
}


void getmap(){
	int i,j;
	int dis;
	for(i=0;i<n+m;i++){
		for(j=0;j<n+m;j++){
			if(i<n && j<n) dis = getdis2(nn[i],nn[j]);
			else if(i<n && j>=n) dis = getdis2(nn[i],mm[j-n]);
			else if(i>=n && j<n) dis = getdis2(mm[i-n],nn[j]);
			else dis = getdis2(mm[i-n],mm[j-n]);
			//printf("%d ",dis);
			if(dis <= (r*r)) map[i][j] = 1;
		}
		//printf("\n");
	}

}


int main(){
	int i,j;
	scanf("%d %d %d %d",&n,&m,&k,&r);
	for(i=0;i<n;i++) scanf("%d %d",&nn[i].x,&nn[i].y);
	for(i=0;i<m;i++) scanf("%d %d",&mm[i].x,&mm[i].y);
	getmap();
	/*
	for(i=0;i<m+n;i++){
		for(j=0;j<m+n;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}*/
	printf("%d\n",getNumT(n+m));
	

		
	return 0;
}
