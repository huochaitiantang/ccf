#include<stdio.h>

typedef struct cor{
	int x;
	int y;
} cord;

char map[50][50];
int R,C;
int cross[50][50];

void print_cord(cord p){
	printf("(%d,%d)",p.x,p.y);
}

int isT(cord p1,cord p2){
	int flag[50][50];
	int i,j;
	cord p;
	cord que[2500];
	int head = 0;
	int tail = 0;
	int ans = 0;
	for(i=0;i<R;i++)
	for(j=0;j<C;j++)
		flag[i][j] = 0;
	que[tail] = p1;
	flag[p1.x][p1.y] = 1;
	while(head <= tail){
		p.x = que[head].x;
		p.y = que[head].y;
		head++;
		if(p.x == p2.x && p.y == p2.y){
			ans = 1;
			break;
		}
		if(map[p.x][p.y] == '+' || map[p.x][p.y] == 'S' || map[p.x][p.y] == 'T'){
			if(p.x > 0 && map[p.x-1][p.y]!='#' && flag[p.x-1][p.y] == 0 ){
				flag[p.x-1][p.y] = 1;
				que[++tail].x = p.x - 1;
				que[tail].y = p.y;
			}
			if(p.y > 0 && map[p.x][p.y-1]!='#' && flag[p.x][p.y-1] == 0 ){
				flag[p.x][p.y-1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y - 1;
			}
			if(p.x < R-1 && map[p.x+1][p.y]!='#' && flag[p.x+1][p.y] == 0 ){
				flag[p.x+1][p.y] = 1;
				que[++tail].x = p.x + 1;
				que[tail].y = p.y;
			}
			if(p.y < C-1 && map[p.x][p.y+1]!='#' && flag[p.x][p.y+1] == 0 ){
				flag[p.x][p.y+1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y + 1;
			}
		}
		else if(map[p.x][p.y] == '|'){
			if(p.x > 0 && map[p.x-1][p.y]!='#' && flag[p.x-1][p.y] == 0 ){
				flag[p.x-1][p.y] = 1;
				que[++tail].x = p.x - 1;
				que[tail].y = p.y;
			}
			if(p.x < R-1 && map[p.x+1][p.y]!='#' && flag[p.x+1][p.y] == 0 ){
				flag[p.x+1][p.y] = 1;
				que[++tail].x = p.x + 1;
				que[tail].y = p.y;
			}
		}
		else if(map[p.x][p.y] == '-'){
			if(p.y > 0 && map[p.x][p.y-1]!='#' && flag[p.x][p.y-1] == 0 ){
				flag[p.x][p.y-1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y - 1;
			}
			if(p.y < C-1 && map[p.x][p.y+1]!='#' && flag[p.x][p.y+1] == 0 ){
				flag[p.x][p.y+1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y + 1;
			}
		}
		else if(map[p.x][p.y] == '.'){
			if(p.x < R-1 && map[p.x+1][p.y]!='#' && flag[p.x+1][p.y] == 0 ){
				flag[p.x+1][p.y] = 1;
				que[++tail].x = p.x + 1;
				que[tail].y = p.y;
			}
		}
	}	
	return ans;
}

void getCross(cord p1){
	int i,j;
	cord p;
	cord que[2500];
	int head = 0;
	int tail = 0;
	for(i=0;i<R;i++)
	for(j=0;j<C;j++)
		cross[i][j] = 0;
	que[tail] = p1;
	cross[p1.x][p1.y] = 1;
	while(head <= tail){
		p.x = que[head].x;
		p.y = que[head].y;
		head++;
		if(map[p.x][p.y] == '+' || map[p.x][p.y] == 'S' || map[p.x][p.y] == 'T'){
			if(p.x > 0 && map[p.x-1][p.y]!='#' && cross[p.x-1][p.y] == 0 ){
				cross[p.x-1][p.y] = 1;
				que[++tail].x = p.x - 1;
				que[tail].y = p.y;
			}
			if(p.y > 0 && map[p.x][p.y-1]!='#' && cross[p.x][p.y-1] == 0 ){
				cross[p.x][p.y-1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y - 1;
			}
			if(p.x < R-1 && map[p.x+1][p.y]!='#' && cross[p.x+1][p.y] == 0 ){
				cross[p.x+1][p.y] = 1;
				que[++tail].x = p.x + 1;
				que[tail].y = p.y;
			}
			if(p.y < C-1 && map[p.x][p.y+1]!='#' && cross[p.x][p.y+1] == 0 ){
				cross[p.x][p.y+1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y + 1;
			}
		}
		else if(map[p.x][p.y] == '|'){
			if(p.x > 0 && map[p.x-1][p.y]!='#' && cross[p.x-1][p.y] == 0 ){
				cross[p.x-1][p.y] = 1;
				que[++tail].x = p.x - 1;
				que[tail].y = p.y;
			}
			if(p.x < R-1 && map[p.x+1][p.y]!='#' && cross[p.x+1][p.y] == 0 ){
				cross[p.x+1][p.y] = 1;
				que[++tail].x = p.x + 1;
				que[tail].y = p.y;
			}
		}
		else if(map[p.x][p.y] == '-'){
			if(p.y > 0 && map[p.x][p.y-1]!='#' && cross[p.x][p.y-1] == 0 ){
				cross[p.x][p.y-1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y - 1;
			}
			if(p.y < C-1 && map[p.x][p.y+1]!='#' && cross[p.x][p.y+1] == 0 ){
				cross[p.x][p.y+1] = 1;
				que[++tail].x = p.x;
				que[tail].y = p.y + 1;
			}
		}
		else if(map[p.x][p.y] == '.'){
			if(p.x < R-1 && map[p.x+1][p.y]!='#' && cross[p.x+1][p.y] == 0 ){
				cross[p.x+1][p.y] = 1;
				que[++tail].x = p.x + 1;
				que[tail].y = p.y;
			}
		}
	}	
}
int main(){
	cord src;
	cord des;
	cord p;
	int i,j;
	int cnt = 0;
	
	scanf("%d %d",&R,&C);
	for(i=0;i<R;i++){
		scanf("%s",map[i]);
	}
	
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(map[i][j] == 'S'){
				src.x = i; src.y = j;
			}
			else if(map[i][j] == 'T'){
				des.x = i; des.y = j;
			}
			//printf("%c",map[i][j]);
		}
		//printf("\n");
	}
	
	//printf("%d %d >> %d %d \n",src.x,src.y,des.x,des.y);
	if(isT(src,des) == 1){
		//printf("Not stuck\n");
		getCross(src);
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				
				if(cross[i][j] == 1) {
					p.x = i;
					p.y = j;
					if(isT(p,des) == 0){
						cnt += 1;
						//printf("(%d,%d)\n",i,j);
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	else{
		printf("I'm stuck!");

	}
	return 0;
	
	

}
