#include<stdio.h>
#include<stdlib.h>

int N;
int MAX = 1000000007;

int getNum(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x0 = x0 + x2;
		_x0_3 = x3 + x0_3 + x3_3;
		_x1 = x0 + x2;
		_x1_1 = x1 + x1_1 + x2_1;
		_x1_3 = x3 + x0_3 + x3_3;
		_x1_13 = x1_3 + x1_13 + x3_1 + x3_13;
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		_x3 = x0 + x2;
		_x3_1 = x1 + x1_1 + x2_1;
		_x3_3 = x0_3 + x3 + x3_3;
		_x3_13 = x1_3 + x1_13 + x3_1 + x3_13;
		x0 = _x0%MAX;
		x0_3 = _x0_3%MAX;
		x1 = _x1%MAX;
		x1_1 = _x1_1%MAX;
		x1_3 = _x1_3%MAX;
		x1_13 = _x1_13%MAX;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
		x3 = _x3%MAX;
		x3_1 = _x3_1%MAX;
		x3_3 = _x3_3%MAX;
		x3_13 = _x3_13%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}

int getNum_0(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x1 = x0 + x2;
		_x1_1 = x1 + x1_1 + x2_1;
		_x1_3 = x3 + x0_3 + x3_3;
		_x1_13 = x1_3 + x1_13 + x3_1 + x3_13;
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		_x3 = x0 + x2;
		_x3_1 = x1 + x1_1 + x2_1;
		_x3_3 = x0_3 + x3 + x3_3;
		_x3_13 = x1_3 + x1_13 + x3_1 + x3_13;
		x1 = _x1%MAX;
		x1_1 = _x1_1%MAX;
		x1_3 = _x1_3%MAX;
		x1_13 = _x1_13%MAX;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
		x3 = _x3%MAX;
		x3_1 = _x3_1%MAX;
		x3_3 = _x3_3%MAX;
		x3_13 = _x3_13%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}
int getNum_1(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x0 = x0 + x2;
		_x0_3 = x3 + x0_3 + x3_3;
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		_x3 = x0 + x2;
		_x3_1 = x1 + x1_1 + x2_1;
		_x3_3 = x0_3 + x3 + x3_3;
		_x3_13 = x1_3 + x1_13 + x3_1 + x3_13;
		x0 = _x0%MAX;
		x0_3 = _x0_3%MAX;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
		x3 = _x3%MAX;
		x3_1 = _x3_1%MAX;
		x3_3 = _x3_3%MAX;
		x3_13 = _x3_13%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}
int getNum_3(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x0 = x0 + x2;
		_x0_3 = x3 + x0_3 + x3_3;
		_x1 = x0 + x2;
		_x1_1 = x1 + x1_1 + x2_1;
		_x1_3 = x3 + x0_3 + x3_3;
		_x1_13 = x1_3 + x1_13 + x3_1 + x3_13;
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		x0 = _x0%MAX;
		x0_3 = _x0_3%MAX;
		x1 = _x1%MAX;
		x1_1 = _x1_1%MAX;
		x1_3 = _x1_3%MAX;
		x1_13 = _x1_13%MAX;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}
int getNum_01(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		_x3 = x0 + x2;
		_x3_1 = x1 + x1_1 + x2_1;
		_x3_3 = x0_3 + x3 + x3_3;
		_x3_13 = x1_3 + x1_13 + x3_1 + x3_13;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
		x3 = _x3%MAX;
		x3_1 = _x3_1%MAX;
		x3_3 = _x3_3%MAX;
		x3_13 = _x3_13%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}
int getNum_03(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x1 = x0 + x2;
		_x1_1 = x1 + x1_1 + x2_1;
		_x1_3 = x3 + x0_3 + x3_3;
		_x1_13 = x1_3 + x1_13 + x3_1 + x3_13;
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		x1 = _x1%MAX;
		x1_1 = _x1_1%MAX;
		x1_3 = _x1_3%MAX;
		x1_13 = _x1_13%MAX;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}
int getNum_13(){
	unsigned int x0=0,x0_3=0;
	unsigned int x1=0,x1_1=0,x1_3=0,x1_13=0;
	unsigned int x2=1,x2_1=0;
	unsigned int x3=0,x3_1=0,x3_3=0,x3_13=0;
	unsigned int i,cnt=1;
	unsigned int _x0,_x0_3,_x1,_x1_1,_x1_3,_x1_13,_x2,_x2_1,_x3,_x3_1,_x3_3,_x3_13;
	for(i=1;i<N;i++){
		_x0 = x0 + x2;
		_x0_3 = x3 + x0_3 + x3_3;
		_x2 = x0 + x2;
		_x2_1 = x1 + x1_1 + x2_1;
		x0 = _x0%MAX;
		x0_3 = _x0_3%MAX;
		x2 = _x2%MAX;
		x2_1 = _x2_1%MAX;
	}
	cnt = x0 + x0_3 + x1 + x1_1 + x1_3 + x1_13 + x2 + x2_1 + x3 + x3_1 + x3_3 + x3_13;
	return (cnt+MAX)%MAX;
}
int getNum_013(){
	return 1;
}

int main(){

	unsigned int neg;
	unsigned int ans;
	scanf("%d",&N);
	//printf("%d \n%d %d %d %d %d %d %d\n",getNum(),getNum_0(),getNum_1(),getNum_3(),getNum_01(),getNum_03(),getNum_13(),getNum_013());
	neg = (((((getNum_0()+getNum_1())%MAX+getNum_3())%MAX-getNum_01())%MAX-getNum_03())%MAX-getNum_13())%MAX + 1;
	ans = (getNum() - neg)%MAX;
	printf("%d\n",ans);
	return 0;
	
}

