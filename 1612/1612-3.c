#include<stdio.h>
#include<string.h>
typedef struct cc{
	char name[100];
	int level;
} preveil;

typedef struct ss{
	char name[100];
	int p[100];
	int l[100];
	int num;
} role_s;

typedef struct xx{
	char name[100];
	int num;
	int r[100];
} user_s;

int prev_n;
int role_n;
int user_n;
int q_n;
preveil prev[1000];
role_s role[1000];
user_s user[1000];
int find_prev(char s[]){
	int i,siz,k=0;
	char buf[64];
	siz = strlen(s);
	if(siz > 1 && s[siz-2]==':'){
		for(i=0;i<siz-2;i++) buf[k++] = s[i];
	}
	else strcpy(buf,s);
	for(i=0;i<prev_n;i++){
		if(strcmp(buf,prev[i].name)==0) return i;
	}
	return -1;
}
int find_role(char s[]){
	int i;
	for(i=0;i<role_n;i++)
	if(strcmp(s,role[i].name)==0) return i;
	return -1;
}
int find_user(char s[]){
	int i;
	for(i=0;i<user_n;i++)
	if(strcmp(s,user[i].name)==0) return i;
	return -1;
}
int main(){
	int i,j,k,siz,tmp,cur_l,ind,flag,q_l,cur_q,sp,role_ind,prev_ind;
	char buf[100];
	char buf2[100];
	scanf("%d",&prev_n);
	for(i=0;i<prev_n;i++){
		scanf("%s",buf);
		siz = strlen(buf);
		k = 0;
		if(siz > 1 && buf[siz-2]==':'){
			for(j=0;j<siz-2;j++) prev[i].name[k++] = buf[j];
			prev[i].name[k] = '\0';
			prev[i].level = buf[siz-1]-'0';	
		}
		else{
			strcpy(prev[i].name,buf);
			prev[i].level = -1;
		}
	}
//	for(i=0;i<prev_n;i++) 	printf("%s %d\n",prev[i].name,prev[i].level);
	scanf("%d",&role_n);
	for(i=0;i<role_n;i++){
		scanf("%s %d",role[i].name,&tmp);
		role[i].num = 0;
		for(j=0;j<tmp;j++){
			scanf("%s",buf);
			siz = strlen(buf);
			ind = find_prev(buf);
			//printf("%s %d %d %d\n",buf,ind,role[i].num,k);
			if(ind>=0){
				for(k=0;k<role[i].num;k++){
			//		printf("\t%d %d\n",ind,role[i].p[k]);
					if(ind == role[i].p[k]) break;
				}
			//	printf("%d %d\n",k,role[i].num);
				if(k==role[i].num){
					role[i].p[role[i].num] = ind;
					if(prev[ind].level >= 0){
						role[i].l[role[i].num] = buf[siz-1]-'0';
					}
					else{
						role[i].l[role[i].num] = -1;
					}
					role[i].num ++;
				}
				else{
					if(prev[ind].level>=0){
						cur_l = buf[siz-1]-'0';
						if(cur_l > role[i].l[k]){
							role[i].l[k] = cur_l;
						}
					}
				}
			}
		} 
	}
	
//	for(i=0;i<role_n;i++){
//		printf("%s %d\n",role[i].name,role[i].num);
//		for(j=0;j<role[i].num;j++){
//			printf("\t%s %d\n",prev[role[i].p[j]].name,role[i].l[j]);
//		}
//	}
	
	scanf("%d",&user_n);
	for(i=0;i<user_n;i++){
		scanf("%s",user[i].name);
		scanf("%d",&tmp);
		user[i].num = 0;
		for(j=0;j<tmp;j++){
			scanf("%s",buf);
			ind = find_role(buf);
		//	printf("* %s %d *\n",buf,ind);
			if(ind>=0){
				for(k=0;k<user[i].num;k++){
					if(ind == user[i].r[k]) break;
				}
				if(k == user[i].num){
					user[i].r[user[i].num] = ind;
					user[i].num ++;
				}
			}
		}
	}
//	for(i=0;i<user_n;i++){
//		printf("%s %d\n",user[i].name,user[i].num);
//		for(j=0;j<user[i].num;j++){
//			printf("\t%s\n",role[user[i].r[j]].name);
//		}
//	}
	scanf("%d",&q_n);
	for(i=0;i<q_n;i++){
		scanf("%s %s",buf,buf2);
		ind = find_user(buf);
		if(ind<0){
			printf("false\n");
			continue;
		}
		flag = 0;
		siz = strlen(buf2);
		q_l = -1;
		cur_l = -1;
		sp = 0;
		if(siz >1 && buf2[siz-2] == ':'){
			q_l = buf2[siz-1]-'0';
			buf2[siz-2]='\0';
		}
		for(j=0;j<user[ind].num;j++){
			role_ind = user[ind].r[j];
			for(k=0;k<role[role_ind].num;k++){
				prev_ind = role[role_ind].p[k];
				if(strcmp(buf2,prev[prev_ind].name)==0){
					if(prev[prev_ind].level < 0){
						printf("true\n");
						flag = 1;
					}
					else{
						if(q_l < 0){
							sp = 1;
							if	(role[role_ind].l[k] > cur_l) cur_l = role[role_ind].l[k];
						}
						else{
							if(q_l <= role[role_ind].l[k]){
								flag = 1;
								printf("true\n");
							}
						}
							
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(q_l < 0 && sp > 0){
			if(cur_l <0 ) printf("false\n");
			else printf("%d\n",cur_l);
		}
		else if(!flag) printf("false\n");
		
		
	}
	return 0;
}
