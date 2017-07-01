#include<stdio.h>
typedef long long ll;
ll mod = 10e9+7;
ll n;
int m;

ll quickmod(int a,int b){
	ll base=a,ans=1;
	while(b){
		if(b&1==1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	int i;
	scanf("%ld %d",&n,&m);
	if(m==2 || m==3 || m==4){	
		printf("%d\n",quickmod(2,(m*n)/6));
	}
	else if(m==5){
		printf("%d\n",(quickmod(2,(m*n)/6)*quickmod(2,(m*n)/30))%mod);
	}
	else{
		printf("1");
	}
	return 0;
}
