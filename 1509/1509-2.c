#include<stdio.h>

int y,d;

int isLeap(int x){
	if(x%400 == 0) return 1;
	if(x%100 == 0) return 0;
	if(x%4 == 0) return 1;
	return 0;
}

int main(){
	int i,j;
	int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d",&y,&d);
	mon[2] += isLeap(y);
	for(i=1;i<=12;i++){
		if(d > mon[i]) d -= mon[i];
		else break;
	}
	printf("%d\n%d\n",i,d);
	
	
	
	return 0;
}
