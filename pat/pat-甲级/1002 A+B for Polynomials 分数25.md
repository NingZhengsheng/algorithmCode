# **1002 A+B for Polynomials** 分数25

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805526272000000

**<font color="#dd0000">题目：1002 A+B for Polynomials</font>**

<font color="#0000dd">This time, you are supposed to find *A*+*B* where *A* and *B* are two polynomials.</font>  

**<font color="#dd0000">Input Specification:</font>**

<font color="#0000dd">Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:*K* *N*1 *a**N*1 *N*2 *a**N*2 ... *N**K* *a**N**K* where *K* is the number of nonzero terms in the polynomial, *N**i* and *a**N**i* (*i*=1,2,⋯,*K*) are the exponents and coefficients, respectively. It is given that 1≤*K*≤10，0≤*N**K*<⋯<*N*2<*N*1≤1000.</font>

**<font color="#dd0000">Output Specification:</font>**

<font color="#0000dd">For each test case you should output the sum of *A* and *B* in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.</font>

**<font color="#dd0000">Sample Input:</font>**

```c++
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

**<font color="#dd0000">Sample Output:</font>**

```C++
3 2 1.5 1 2.9 0 3.2
```



## 2. 题意

> <font color="#00dddd">将两个多项式进行相加合并，就是将相同次方的系数进行相加，输入有两行，每行表示一个多项式，每行的内容（k项 x次方 x次方的系数a ......）</font>

## 3. 思路

><font color="#dd00dd">1. 思路：创建一个数组来保存多项式，数组的下标i表示x^i，s[i]表示x^i的系数ai； 将两个多项式进行合并，只需要将相同的x^i的系数进行相加即可；最后对多项式数组s进行遍历，如果s[i]不为0则进行输出。</font>
>
><font color="#dd00dd">2. 优化：使用max_x来记录最大的次方，这样就不用遍历整个数组，只需要遍历0~max_x即可。</font>
>
><font color="#dd00dd">3. 知识点：设置保留几位小数cout<<setiosflags(ios::fixed)<<setprecision(1)<<sum;
> 需要为头文件#include<iomanip></font>

## 4. 代码

```c++
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
```



