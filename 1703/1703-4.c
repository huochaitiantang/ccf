#include<stdio.h>
typedef struct cc{
	int n1;
	int n2;
	int t;
} tur;

typedef struct xx{
	int n1;
	int val;
} nod;

int n;
int m;
tur mm[200000];
int flag[100001];
int tim[100001];
nod node[100001];
int node_n;

void swap(i,j){
	nod p;
	p.n1 = node[i].n1;
	p.val = node[i].val;
	node[i].n1 = node[j].n1;
	node[i].val = node[j].val;
	node[j].n1 = p.n1;
	node[j].val = p.val;	
}

void push(int n1,val){
	int i;
	nod p;
	node_n ++;
	node[node_n].n1 = n1;
	node[node_n].val = val;
	i = node_n;
	while(i!=1){
		if(node[i] < node[i/2]){
			swap(i,i/2);
			i /= 2;
			continue;	
		}
		break;
	}
}

void pop(){
	int i,j;
	node[1].n1 = node[node_n].n1;
	node[1].val = node[node_n].va;
	node_n--;
	i = 1;
	while( i*2<=node_n){
		j = i*2;
		if(j<(node_n-1) && node[j+1].val<node[j].val) j++;
		if(node[i].val > node[j].val){
			swap(i,j);
			i = j;
			continue;
		}
		break;
	}
}

:q
wq
int getmint(){
	int ind,i;
	int mint=0;
	for(i=2;i<=n;i++){
		if(flag[i] == 0 && tim[i] > 0 && (mint == 0 || mint > tim[i])){
			mint = tim[i];
			ind = i;
		}
	}
	return ind;
}

int max(int a,int b){
	return a>=b?a:b;
}

int main(){
	int i,ind,nd,new;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) scanf("%d %d %d",&mm[i].n1,&mm[i].n2,&mm[i].t);
	for(i=0;i<m;i++){
		if(mm[i].n1 == 1) tim[mm[i].n2] = mm[i].t;
	}
	flag[1] = 1;
	while(flag[n] == 0){
		ind = getmint();
		//printf("%d %d\n",ind,tim[ind]);
		flag[ind] = 1;
		for(i=0;i<m;i++){
			if(mm[i].n1 == ind || mm[i].n2 == ind){
				nd = mm[i].n1==ind?mm[i].n2:mm[i].n1;
				new = max(tim[ind],mm[i].t);
				if(tim[nd] == 0 || tim[nd] > new){
					tim[nd] = new;
				}
			}

		}
	}
	printf("%d\n",tim[n]);
	return 0;	
}
