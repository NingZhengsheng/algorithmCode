#include<iostream>
using namespace std;

bool checkPrime(int x){
	if(x<2) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true; 
}

//Reversible函数：将10进制的x转成d进制后，然后反转，最后再转回十进制返回
//下面直接同时转，一步到位
int Reversible(int x,int d){
//	int ans = 0;
//	while(x!=0){
//		ans = ans*d + x%d;
//		x = x/d;
//	}
	int product=1,ans=0,z[40],len=0;
	do
	{
		z[len++]=x%d;
		x/=d;
	}while(x);
	for(int i=len-1;i>=0;--i)
	{
		ans+=z[i]*product;
		product*=d;
	}
	return ans;
//	cout << "x= " << x <<" ans=" <<ans << endl;
//	return ans;
}


int main(){
	int N,D;
	while(true){
		cin >> N;
		if(N<0) break;
		cin >> D;
		if(checkPrime(N)&&checkPrime(Reversible(N,D))){
			cout << "Yse" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
