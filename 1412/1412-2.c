#include<stdio.h>
#define Right 0
#define Down 1
#define LeftDown 2
#define RightUp 3
short n;
short nn[500][500];
int main(){
	int i,j,dir=Right;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&nn[i][j]);
		}
	}
	i=0;j=0;
	while(1){
		printf("%d ",nn[i][j]);
		if(i==n-1 && j==n-1) break;
		if(dir==Right){
			j++;
			if(i==0) dir = LeftDown;
			else dir = RightUp;
		}
		else if(dir==Down){
			i++;
			if(j==0) dir = RightUp;
			else dir = LeftDown;
		}
		else if(dir==LeftDown){
			i++;j--;
			if(j==0 && i<n-1) dir = Down;
			else if(i>=n-1 && j<n-1) dir = Right;
		}
		else if(dir==RightUp){
			i--;j++;
			if(i==0 && j<n-1) dir = Right;
			else if(j>=n-1 && i<n-1) dir= Down;
		}
	}
	
	
	return 0;
}
