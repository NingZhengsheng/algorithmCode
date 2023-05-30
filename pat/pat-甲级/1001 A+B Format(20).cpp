#include<iostream>
#include<string>
using namespace std;

int main(){
	long long a,b,sum;
	string ans = "";//保存最后输出的结果 
	int count = 0,flag=1;//count用来记录遍历到多少位了，因为每三位需要添加一个',' 
	
	cin >> a >> b;
	sum = a + b;
	if(sum==0){//和为0直接输出，结束 
		cout << '0' << endl;
		return 0;
	}else if(sum<0){//和sum为负数， flag标记正负 
		sum = -sum;
		flag=-1;
	}
	//将正数sum装成字符串，并每三位添加一个',' 
	while(sum!=0){
		if(count!=0 && count%3==0) ans = ',' + ans;
		ans = char(sum%10+'0') + ans;
		sum = sum / 10;
		count++;
	}
	//判断是否添加'-' 
	if(flag==-1) ans = '-' + ans;
	cout << ans << endl;
    return 0;
}
