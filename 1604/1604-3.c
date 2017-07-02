#include<stdio.h>
#include<string.h>
int p;
char stack[20][2000];
char cur[1000][1000];
int cur_n;
char buf[1000][1000];
int buf_n;

void split_by(char s[],char c){
	buf_n = 0;
	int i=0,k=0,siz;
	siz = strlen(s);
	while(i<siz && s[i] == '/') {
		i++;
	}
	if(i == siz) return;
	for(;i<siz;i++){
		while(i<siz && s[i]!='/'){
			buf[buf_n][k++] = s[i++];
		}
		buf[buf_n][k] = '\0';
		buf_n++;
		k=0; 
		while(i<siz && s[i]=='/') i++;
		i-=1;
	}
}


void abso_path(char s[]){
	int i;
	int top=-1;
	split_by(s,'/');
	for(i=0;i<buf_n;i++){
		//puts(buf[i]);
		if(strcmp(buf[i],".")==0) continue;
		if(strcmp(buf[i],"..")==0) {
			if(top>=0) top--;
		}
		else strcpy(stack[++top],buf[i]);
	}
	for(i=0;i<=top;i++){
		printf("/%s",stack[i]);
	}
	if(top<0) printf("/");
	printf("\n");
}

void rela_path(char s[]){
	int i;
	int top=-1;
	for(i=0;i<cur_n;i++){
		strcpy(stack[++top],cur[i]);
	}
	split_by(s,'/');
	for(i=0;i<buf_n;i++){
		if(strcmp(buf[i],".")==0) continue;
		if(strcmp(buf[i],"..")==0) {
			if(top >=0 )
				top--;
		}
		else strcpy(stack[++top],buf[i]);
	}
	for(i=0;i<=top;i++){
		printf("/%s",stack[i]);
	}
	if(top<0) printf("/");
	printf("\n");
}

int main(){
	int i,j;
	char ss[1000];
	scanf("%d\n",&p);
	gets(ss);
	split_by(ss,'/');
	for(i=0;i<buf_n;i++){
		strcpy(cur[cur_n++],buf[i]);
	}
	for(i=0;i<p;i++){
		gets(ss);
		if(strcmp(ss,"")==0) printf("/\n");
		else if(ss[0]=='/'){
			abso_path(ss);
		}
		else{
			rela_path(ss);
		}
	}
	return 0;
	
	
	
}
