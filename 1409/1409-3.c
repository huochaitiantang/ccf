#include<stdio.h>
#include<string.h>

char tar[100];
char input[100][100];
char output[100][100];
int F;
int n;

void hadstr(char s[]){
	int i;
	for(i=0;i<strlen(s);i++)
		if(s[i]>='A' && s[i]<='Z') s[i] = s[i]+'a'-'A';
}

int hasstr(char s[]){
	int i,j,sub,flag;
	sub = strlen(tar);
//	printf("judge: %s\n",s);
	for(i=0;i<=strlen(s)-sub;i++){
		flag = 1;
		for(j=i;j<i+sub;j++){
			if(s[j] != tar[j-i]){
//				printf("Not:%s %s %c %c\n",s,tar,s[j],tar[j-i]);
				flag = 0 ;
				break;
			}
		}
		if (flag) return 1;
	}
	return 0;
}

int main(){
	int i;
	
	scanf("%s",tar);
	scanf("%d\n%d",&F,&n);	
	for(i=0;i<n;i++) {
		scanf("%s",input[i]);
		strcpy(output[i],input[i]);
	}
	if(F == 0) {
		hadstr(tar);
		for(i=0;i<n;i++) hadstr(input[i]);
	}
	for(i=0;i<n;i++){
		if(hasstr(input[i])) printf("%s\n",output[i]);
	}

	return 0;
}
