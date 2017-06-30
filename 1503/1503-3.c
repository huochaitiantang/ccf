#include<stdio.h>

int a;
int b;
int c;
int y1;
int y2;
int fd[300];
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int isLeap(int y){
	if(y%400==0) return 1;
	if(y%100==0) return 0;
	if(y%4==0) return 1;
	return 0;
}

int getWeek(int y,int m){
	int i,ans=0;
	for(i=1;i<m;i++){
		ans += mon[i];
		if(i==2) ans += isLeap(y);
	}
	return (ans+fd[y-1850])%7;
}

int getFd(){
	int i;
	fd[0] = 2;
	for(i=1;i<=200;i++){
		fd[i] = (fd[i-1]+365+isLeap(i+1849))%7;
	}
}

int main(){
	int i,fdw,mnu,cur;
	scanf("%d %d %d %d %d",&a,&b,&c,&y1,&y2);
	getFd();
	//for(i=2017;i<=2022;i++) printf("%d\n",fd[i-1850]);
	c = c%7;
	for(i=y1;i<=y2;i++){
		fdw = getWeek(i,a);
		//printf("%d\n",fdw);
		mnu = mon[a]+isLeap(i);
		cur = (c-fdw)+7*(b-1) +1;
		if(fdw>c) cur+=7;
		if(cur <= mnu){
			printf("%d/%02d/%02d\n",i,a,cur);
		}
		else{
			printf("none\n");
		}
	}

	return  0;
}



