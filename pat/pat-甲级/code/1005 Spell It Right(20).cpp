#include<iostream>
#include<string>
using namespace std;

string key_val[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
	int sum = 0;
	string str,ans="";
	cin >> str;
	//求和sum
	for(char c : str){
		sum += c - '0';
	}
	//将sum转换成字符串
	ans = key_val[sum%10];
	sum = sum / 10;
	while(sum!=0){
		ans = key_val[sum%10] + " "+ ans;
		sum = sum / 10;
	}
	cout << ans << endl;
	return 0;
}
