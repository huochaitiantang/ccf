#include<stdio.h>
#include<string.h>
typedef struct cc{
	int blood;
	int attack;
} sui;

sui sc[2][8];
int sc_n[2];
int blood[2];
int n; 

void add_sc(int cur,int p,int a,int h){
	int i;
	for(i=sc_n[cur]+1;i>p;i--){
		sc[cur][i].blood = sc[cur][i-1].blood;
		sc[cur][i].attack = sc[cur][i-1].attack;
	}
	sc[cur][p].blood = h;
	sc[cur][p].attack = a;
	sc_n[cur]++;
}

void sub_sc(int cur,int p){
	int i;
	for(i=p;i<sc_n[cur];i++){
		sc[cur][i].blood = sc[cur][i+1].blood;
		sc[cur][i].attack = sc[cur][i+1].attack;
	}
	sc_n[cur]--;
}

int main(){
	int i,j,cur=0,pos,heal,att,p1,p2,em;
	char buf[20];
	scanf("%d",&n);
	sc[0][0].blood = 30;
	sc[1][0].blood = 30;
	sc[0][0].attack = 0;
	sc[1][0].attack = 0;
	for(i=0;i<n;i++){
		scanf("%s",buf);
		if(strcmp(buf,"end")==0) cur = 1-cur;
		else if(strcmp(buf,"summon")==0){
			scanf("%d %d %d",&pos,&att,&heal);
			add_sc(cur,pos,att,heal);
		}
		else if(strcmp(buf,"attack")==0){
			scanf("%d %d",&p1,&p2);
			sc[cur][p1].blood -= sc[1-cur][p2].attack;
			sc[1-cur][p2].blood -= sc[cur][p1].attack;
			if(sc[cur][p1].blood<=0 && p1>0) sub_sc(cur,p1);
			if(sc[1-cur][p2].blood<=0 && p2>0) sub_sc(1-cur,p2);
		}
	}
	if(sc[0][0].blood<=0) printf("1\n");
	else if(sc[1][0].blood<=0) printf("-1\n");
	else printf("0\n");
	for(i=0;i<=1;i++){
		printf("%d\n",sc[i][0].blood);
		printf("%d ",sc_n[i]);
		for(j=1;j<=sc_n[i];j++){
			printf("%d ",sc[i][j].blood);
		}
		printf("\n");
	}
	
	return 0;
}
