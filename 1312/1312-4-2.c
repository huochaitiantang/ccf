#include<stdio.h>

unsigned int MAX = 1000000007;
long jie[1000];
long vvv[1000];

void getjie(){
	int i;
	jie[0] = jie[1] = 1;
	for(i=2;i<1000;i++){
		jie[i] = jie[i-1] * i % MAX;
	}
}

int quickmi(int a,int b){
     	long ans=1;
	long base=a;
     	while(b!=0){
         	if(b&1!=0)
         		ans= (ans*base)%MAX;
         	base=(base*base)%MAX;
         	b>>=1;
	}
     	return ans;
}

void get_vvv(){
	int i;
	jie[0] = 1;
	for(i=1;i<1000;i++) jie[i] = (long)jie[i-1] * i % MAX;
	vvv[998] = quickmi(jie[998],MAX-2);
	for(i=997;i>=0;i--) vvv[i] = (long)vvv[i+1] * (i+1) % MAX;
	//vvv[0] = vvv[1] = 1;
	//for(i=2;i<=998;i++){
	//	vvv[i] = quickmi(jie[i],MAX-2);	
		//vvv[i] = vvv[i-1]*val[i]%MAX;
	//}
}

int main(){
	int m,N,i;
	long cnt = 0;
	long x;

	scanf("%d",&N);
	getjie();
	get_vvv();
/*
	for(i=2;i<998;i++){
		printf("%d %d %d\n",jie[i],vvv[i],vvv[i]*jie[i]%MAX);
	}
*/	//printf("%d %d %d %d %d\n",vvv[2]*2%MAX,vvv[3]*6%MAX,vvv[4]*24%MAX,vvv[5]*120%MAX,vvv[6]*720%MAX);
	for(m=2;m<=N-2;m++){
		x = (long)(vvv[N-m-2]*(m-1))%MAX;
		for(i=m+1;i<=N-1;i++){
			x = (long)(x * i)%MAX;
		}
//		printf("%d %d %d \n",N-m-2,vvv[N-m-2],x);
		cnt = (cnt + x)%MAX;
	}
	printf("%ld\n",cnt);
	return 0;
}


