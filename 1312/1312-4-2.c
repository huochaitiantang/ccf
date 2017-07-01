#include<stdio.h>

typedef long long ll;

ll mod = 1000000007;
ll fac[2000];
ll rev[1000];
ll n;

ll quickmod(int a,int b){
	ll ans=1;
	ll base = (ll)a;
	while(b!=0){
		if(b&1==1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		b >>= 1;
	}
	return ans;
}

ll C(int n,int m){
	ll ans;
	ans = fac[n];
	ans = (ans*rev[m])%mod;
	ans = (ans*rev[n-m])%mod;
	return ans;
}

int main(){
	int m,n,i;
	ll cnt = 0;
	ll x;
	scanf("%d",&n);
	fac[0] = 1;	
	for(i=1;i<n;i++){
		fac[i]=(i*fac[i-1])%mod;
		rev[i]=quickmod(fac[i],mod-2);
	}

	for(i=2;i<=n-2;i++){
		x = ((i-1)*(n-i-1))%mod;
		cnt = (cnt+((x*C(n-1,i))%mod))%mod;
	}
	printf("%d\n",cnt);
	return 0;
}


