#include<stdio.h>

typedef struct cc{
	int x1;
	int y1;
	int x2;
	int y2;
} rect;

int isIn(int x,int y,rect re){
	if(x>=re.x1 && x<re.x2 && y>=re.y1 && y<re.y2) return 1;
	else return 0;
}

int main(){
	int i,j,k,n,cnt=0;
	rect nn[100];
	rect mr;
	mr.x1 = mr.y1 = 100;
	mr.x2 = mr.y2 = 0;	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d %d %d %d",&nn[i].x1,&nn[i].y1,&nn[i].x2,&nn[i].y2);
	for(i=0;i<=100;i++){
		for(j=0;j<=100;j++){
			for(k=0;k<n;k++){
				if(isIn(i,j,nn[k])){
					//printf("(%d,%d)\n",i,j);
					cnt += 1;
					break;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
