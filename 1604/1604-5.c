#include<stdio.h>
int T;
int n;
int m;
int p;
int map_pre[1000][10];
int map_bac[1000][10];
char flag[1000];
int set[1000];
long long ans[10];
int set_n;

int main(){
	int i,j,k,ind,cur,cur_n,u,v,w;
	long long cnt;
	char buf[1000];
	scanf("%d",&T);
	for(i=0;i<T;i++){
		cnt = 0;
		scanf("%d %d %d",&n,&m,&p);
		for(j=1;j<=n;j++){
			for(k=1;k<=p;k++){
				map_pre[j][k] = -1;
				map_bac[j][k] = -1;
			}
		}
		scanf("%s",buf);
		for(j=0;j<m;j++){
			scanf("%d %d %d",&u,&v,&w);
			map_bac[u][v-u] = w;
			map_pre[v][v-u] = w;
		}
		for(j=2;j<=n;j++) flag[j] = 0;
		flag[1] =1;
		set[0] = 1;
		set_n = 1;
		while(set_n<n){
			cur = -1;
			cur_n = -1;
			for(j=0;j<set_n;j++){
				ind = set[j];
				for(k=1;k<=p;k++){
					if(map_bac[ind][k] >= 0 && flag[ind+k] == 0 && (cur==-1 || cur > map_bac[ind][k])){
						cur = map_bac[ind][k]; cur_n = ind+k;
					}
					if(map_pre[ind][k] >= 0 && flag[ind-k] == 0 && (cur==-1 || cur > map_pre[ind][k])){
						cur = map_pre[ind][k]; cur_n = ind-k;
					}
				}
			}
			cnt += cur;
			flag[cur_n] = 1;
			set[set_n] = cur_n;
			set_n ++;
		}
		ans[i] = cnt;
	}
	for(i=0;i<T;i++) printf("%d\n",ans[i]);
	return 0;
}
 
