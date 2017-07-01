#include<stdio.h>
#include<string.h>

typedef long long ll;
typedef struct cc{
	char isBuy;
	float p;
	ll num;
	char invalid;
} xx;

xx rec[5001];
short buy[5001];
short sell[5001];
short buy_n;
short sell_n;

ll getNum(float x){
	int i,ind;
	ll n1=0,n2=0;
	float val;
	for(i=0;i<buy_n;i++){
		ind = buy[i];
		if(rec[ind].p >= x) n1+=rec[ind].num;
	}
	for(i=0;i<sell_n;i++){
		ind = sell[i];
		if(rec[ind].p <= x) n2+=rec[ind].num;
	}
	if(n1 <= n2) return n1;
	else return n2;
}

int main(){
	int i,x,k=0;
	char buf[20];
	float cur_p;
	ll cur_num,max_num=0;
	while(scanf("%s",buf)!=EOF){
		if(strcmp(buf,"buy")==0){
			scanf("%f %d",&rec[k].p,&rec[k].num);
			rec[k].isBuy = 1;
			rec[k].invalid = 0;
		}
		else if(strcmp(buf,"sell")==0){
			scanf("%f %d",&rec[k].p,&rec[k].num);
			rec[k].isBuy = 0;
			rec[k].invalid = 0;
		}
		else{
			rec[k].invalid = 1;
			scanf("%d",&x);
			rec[x-1].invalid = 1;
		}
		k++;
	}
	
//	for(i=0;i<k;i++){
//		printf("%d:",i+1);
//		if(rec[i].invalid != 1){
//			printf("%d %.2f %d",rec[i].isBuy,rec[i].p,rec[i].num);
//		}
//		printf("\n");
//	}
	
	for(i=0;i<k;i++){
		if(rec[i].invalid != 1){
			if(rec[i].isBuy == 1){
				buy[buy_n] = i;
				buy_n ++ ;
			}
			else{
				sell[sell_n] = i;
				sell_n ++;
			}
		}
	}
	
	for(i=0;i<k;i++){
		if(rec[i].invalid != 1){
			cur_num = getNum(rec[i].p);
			if(cur_num > max_num ||(cur_num == max_num && rec[i].p > cur_p)){
				cur_p = rec[i].p;
				max_num = cur_num;
			}
		}
	}
	printf("%.2f %d\n",cur_p,max_num);
	return 0;
}



