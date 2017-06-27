#include<stdio.h>
#include<string.h>
#define BUF_SS 101

char ss[101][200];
int s_n;

void handle(char s[],int sta,int end){
	int i,j;
	int flag1=0,flag2=0,flag3=0;
	for(i=sta;i<end;i++){
		if(s[i] != '\n'){
			if(s[i] == '_'){
				if(flag1 == 0) { printf("<em>"); flag1 = 1; }
				else{ printf("</em>");flag1 = 0; }
			}
			else if(s[i] == '['){
				//pass 1
				if(flag2 == 0){
					printf("<a href=\"");
					j = i;
					while(s[++i] != ']');
				//	printf("\nhere:%d %c\n",i,s[i]);
					flag2 = 1;
				}
				else{
					flag2 = 0;
				}			
			}
			else if(s[i] == '('){
			//	printf("\nYes\n");
				if(flag3==0){
					while(s[++i] != ')') printf("%c",s[i]);
					printf("\">");
					flag3 = 1;
					i = j;
				}
				else{
					while(s[++i] != ')');
					printf("</a>");
					flag3 = 0;
				}
			}
			else if(s[i]!=']' && s[i]!=')') printf("%c",s[i]);
			
		}
	}
}


int main(){
	int i,j,siz;
	char title_deep;
	while(fgets(ss[s_n++], BUF_SS, stdin)) ;
	
//	for(i=0;i<s_n;i++){
//		printf("%s",ss[i]);
//	}
	
	
	for(j=0;j<s_n;j++){
		siz = strlen(ss[j]);
		if(ss[j][0] == '#'){
			title_deep = 1;
			while(title_deep < siz && ss[j][title_deep] == '#') title_deep++;
			printf("<h%d>",title_deep);
			for(i=title_deep;i<siz;i++){
				if(ss[j][i] == ' ') continue;
				break;
			}
			handle(ss[j],i,siz);
			printf("</h%d>\n",title_deep);
		}
		else if(ss[j][0] == '*'){
			printf("<ul>\n");
			while(siz > 0 &&ss[j][0] != '\n'){
				printf("<li>");
				for(i=1;i<siz;i++){
					if(ss[j][i] == ' ') continue;
					break;
				}
				handle(ss[j],i,siz);
				printf("</li>\n");
				j ++ ;
				if(j >= s_n) break;
				siz = strlen(ss[j]);
			}	
			printf("</ul>\n");
		}
		else if(siz > 0 && ss[j][0]!='\n'){
			printf("<p>");
			while(siz > 0 && ss[j][0]!='\n'){
				handle(ss[j],0,siz);
				j++;
				if(j>=s_n || ss[j][0] == '\n' ||ss[j][0] == 0) break;
				siz = strlen(ss[j]);
				printf("\nYes %d %d %d\n",j,(int)ss[j][0],s_n);
				printf("\n");
			}
			printf("</p>\n");
		}
	}
	return 0;
}


