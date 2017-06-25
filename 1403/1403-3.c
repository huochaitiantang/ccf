#include<stdio.h>
#include<string.h>

int arg[26];
char sans[128][128];

int split_(char s[]){
	int i,k;
	int num;
	for(i=0,num=0,k=0;i<strlen(s);i++){
		if(s[i] != ' ' && s[i] != '\n' && s[i] != '\0'){
			sans[num][k++] = s[i];
		} 	
		else{
			sans[num][k] = '\0';
			num ++;
			k = 0;
		}
	}
	sans[num][k] = '\0';
	return num+1;

}

void ana(char s[],int hh){
	int siz;
	int i,ind;
	int flag[26];
	char val[26][250];
	printf("Case %d:",hh);
	siz = split_(s);
	for(i=0;i<26;i++) flag[i] = 0;
	for(i=1;i<siz;i++){
		if(sans[i][0] != '-' || strlen(sans[i]) != 2) break;
		ind = sans[i][1] - 'a';
		if(arg[ind] < 0) break;
		if(arg[ind] == 0) flag[ind] = 1;
		else{
			if(i + 1 >= siz) break; 
			flag[ind] = 1;
			strcpy(val[ind],sans[++i]);
		}	
	}
	for(i=0;i<26;i++){
		if(flag[i] == 1){
			printf(" -%c",'a'+i);
			if(arg[i] == 1) printf(" %s",val[i]);
		}
	}
	printf("\n");
}

int main(){
	char form[52];
	char order[20][256];
	int i,j,size;
	int N;

	scanf("%s",form);
	scanf("%d\n",&N);
	for(i=0;i<N;i++){
		gets(order[i]);
	}
	size = strlen(form);
	for(i=0;i<26;i++) arg[i] = -1;
	for(i=0;i<size;i++){
		arg[form[i]-'a'] += 1;
		if(i<size-1 && form[i+1] == ':'){
			arg[form[i]-'a'] += 1;
			i++;
		}
	}
	for(i=0;i<N;i++){
		ana(order[i],i+1);
	}
	return 0;
}


