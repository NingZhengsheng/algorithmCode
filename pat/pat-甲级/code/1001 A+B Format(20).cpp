#include<iostream>
#include<string>
using namespace std;

int main(){
	long long a,b,sum;
	string ans = "";//�����������Ľ�� 
	int count = 0,flag=1;//count������¼����������λ�ˣ���Ϊÿ��λ��Ҫ���һ��',' 
	
	cin >> a >> b;
	sum = a + b;
	if(sum==0){//��Ϊ0ֱ����������� 
		cout << '0' << endl;
		return 0;
	}else if(sum<0){//��sumΪ������ flag������� 
		sum = -sum;
		flag=-1;
	}
	//������sumװ���ַ�������ÿ��λ���һ��',' 
	while(sum!=0){
		if(count!=0 && count%3==0) ans = ',' + ans;
		ans = char(sum%10+'0') + ans;
		sum = sum / 10;
		count++;
	}
	//�ж��Ƿ����'-' 
	if(flag==-1) ans = '-' + ans;
	cout << ans << endl;
    return 0;
}
