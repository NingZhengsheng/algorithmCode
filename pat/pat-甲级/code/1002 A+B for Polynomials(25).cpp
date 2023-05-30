#include<iostream>
#include<iomanip>          // 用于调用setprecision(n)
using namespace std;

int main(){
	/* ①思路：创建一个数组来保存多项式，数组的下标i表示x^i，s[i]表示x^i的系数ai；
		  将两个多项式进行合并，只需要将相同的x^i的系数进行相加即可。
	   ②优化：使用max_x来记录最大的次方，这样就不用遍历整个数组，只需要遍历0~max_x即可。
	   ③知识点：设置保留几位小数cout<<setiosflags(ios::fixed)<<setprecision(1)<<sum;
			  需要为头文件#include<iomanip>
	*/
	double s[1001]={0},a;
	int k,x,count=0,max_x=0;
	cin>>k;
	for(int i=0;i<k;i++){
		cin >> x >> a;
		s[x] = a;
		if(x > max_x) max_x = x;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		cin >> x >> a;
		s[x] += a;
		if(x > max_x) max_x = x;
	}
	for(int i=max_x;i>=0;i--){
		if(s[i]!=0) count++;
	}
	//对结果数组s进行输出
	cout << count;
	for(int i=max_x;i>=0;i--){
		//cout<<setiosflags(ios::fixed)<<setprecision(1)<<sum;
		if(s[i]!=0) cout << setiosflags(ios::fixed)<<setprecision(1)<< " " << i << " " << s[i];
	}
	cout << endl;
	return 0;
}
