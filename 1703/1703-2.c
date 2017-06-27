#include<stdio.h>
typedef struct cc{
	int num;
	int mov;
} oo;

int n;
int m;
oo mm[2000];
int loc[2000];
int st[2000];

void backmov(int s,int dis){
	int i,ori_loc,new_loc;
	if(dis > n - st[s]) dis = n - st[s];
	ori_loc = st[s];
	new_loc = ori_loc + dis;
	for(i=ori_loc;i<new_loc;i++){
		loc[i] = loc[i+1];
		st[loc[i]]--;
	}
	st[s] = new_loc;
	loc[new_loc] = s;
}

void headmov(int s,int dis){
	int i,ori_loc,new_loc;
	if(dis > st[s]-1) dis = st[s]-1;
	ori_loc = st[s];
	new_loc = st[s] - dis;
	for(i=ori_loc;i>new_loc;i--){
		loc[i] = loc[i-1];
		st[loc[i]]++;
	}
	st[s] = new_loc;
	loc[new_loc] = s;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) {

		scanf("%d %d",&mm[i].num,&mm[i].mov);
	}
	
	for(i=1;i<=n;i++){
		st[i] = i;
		loc[i] = i;
	}
	
	for(i=0;i<m;i++){
		//for(j=1;j<=n;j++) printf("%d ",loc[j]);	
		//printf("\n");
		if(mm[i].mov > 0){
			backmov(mm[i].num,mm[i].mov);
		}
		else{
			headmov(mm[i].num,-mm[i].mov);
		}
	}
	for(i=1;i<=n;i++) printf("%d ",loc[i]);	
	return 0;
}

