#include<stdio.h>
#include<string.h>

int n,m;
char temp[200][200];
char val_name[200][200];
char val[200][200];

int getval(char s[],int ind){
	int i,j,siz;
	for(j=0;j<m;j++){
		siz = strlen(val_name[j]);
		for(i=ind;i<ind+siz;i++){
			if(s[i] != val_name[j][i-ind]) break;
		}
		if(i == ind+siz) return j;
	}
	return -1;
}

int main(){
	int i,j,siz,ind;
	char buf[200];
	char c;
	scanf("%d%d\n",&n,&m);
	for(i=0;i<n;i++) gets(temp[i]);
	for(i=0;i<m;i++){
		scanf("%s",val_name[i]);
		c = getchar();
		c = getchar();
		c = getchar();
		j = 0;
		while(c!='\n' && c!='"'){
			val[i][j++] = c;
			c = getchar();
		}
		val[i][j] = '\0';
	}
	
	//for(i=0;i<m;i++) printf("%s : %s\n",val_name[i],val[i]);
	for(i=0;i<n;i++){
		siz = strlen(temp[i]);
		for(j=0;j<siz;j++){
			if(temp[i][j] == '{'&&j<siz-1&&temp[i][j+1]=='{'){
				j += 3;
				ind = getval(temp[i],j);
				if(ind<0){
					while(temp[i][j]!=' ') j++;
					j += 2;
				}
				else{
					printf("%s",val[ind]);
					j += strlen(val_name[ind]);
					j += 2;
				}
			}
			else{
				printf("%c",temp[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
