#include<stdio.h>

int sm[5][5];
int map[16][11];
int ind;
int low;

int cango(int x){
	int i,j;
	for(j=x;j>=1 && j>x-low;j--){
		for(i=ind;i<ind+4;i++){
			if(sm[low-x+j][i-ind+1]==1 && map[j][i] == 1) {
				//printf("%d %d\n",ind,i-ind+1);
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int i,j,k;
	for(i=1;i<=15;i++)
		for(j=1;j<=10;j++)
			scanf("%d",&map[i][j]);
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			scanf("%d",&sm[i][j]);
	scanf("%d",&ind);
	for(low=4;low>=1;low--){
		for(i=1;i<=4;i++){
			if(sm[low][i]>0) break;
		}
		if(i<=4) break;
	}
	//printf("%d\n",low);
	for(i=1;i<=15;i++){
		if(!cango(i)) break;
	}
	i -= 1;
	for(j=i;j>i-low;j--){
		for(k=ind;k<ind+4;k++){
		//	printf("%d %d %d %d\n",j,k,low-i+j,k-ind+1);
			if(sm[low-i+j][k-ind+1] == 1)
				map[j][k] = 1;
		}
	}
	for(i=1;i<=15;i++){
		for(j=1;j<=10;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
} 
