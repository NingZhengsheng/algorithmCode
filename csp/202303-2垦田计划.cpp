#include<stdio.h>
#include<math.h>
# include <iostream>
# include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;

//int main(){
//	long long n,m,k,t,c,max_val=0;
//	long long flag[maxn]={0};
//	scanf("%lld %lld %lld",&n,&m,&k);
//	for(int i=0;i<n;i++){
//		scanf("%lld %lld",&t,&c);
//		max_val=max(max_val,t);
//		flag[t] += c;//表示从t天减少一天需要消耗的资源数
//	}
//	
//	for(int i=max_val;i>k;i--){
//		if(m>=flag[i]){//说明资源能够支持减少一天 
//			m -= flag[i];
//			flag[i-1] += flag[i];//i-1天 减少一天的代价增加 
//		}else{
//			printf("%d\n",i);
//			return 0;
//		}
//	}
//	printf("%d\n",k);
//	return 0;
//}



////////////////【flag数组数据太大，超出long long】/////////////////////////
long long flag[maxn]={0};
int main(){
	long long n,m,k,t,c,max_val=0;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&t,&c);
		max_val=fmax(max_val,t);
		for(int j=t;j>=k;j--){
			flag[j]+=(t-j)*c;
//			printf("%d\n",flag[j]);
		}
//		printf("\n");
	}
	for(int i=k;i<=max_val;i++){
		if(flag[i]!=0 && m>=flag[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",max_val);
	return 0;
}





