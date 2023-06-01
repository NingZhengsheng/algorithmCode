# **1015 Reversible Primes**分数 20

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805495863296000

**<font color="#dd0000">题目：1008 Elevator</font>**

<font color="#0000dd">A **reversible prime** in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.</font>  

<font color="#0000dd">Now given any two positive integers *N* (<10^5) and *D* (1<*D*≤10), you are supposed to tell if *N* is a reversible prime with radix *D*.</font>  

**<font color="#dd0000">Input Specification:</font>**

<font color="#0000dd">The input file consists of several test cases. Each case occupies a line which contains two integers *N* and *D*. The input is finished by a negative *N*.</font>

**<font color="#dd0000">Output Specification:</font>**

<font color="#0000dd">For each test case, print in one line `Yes` if *N* is a reversible prime with radix *D*, or `No` if not.</font>

**<font color="#dd0000">Sample Input:</font>**

```c++
73 10
23 2
23 10
-2
```

**<font color="#dd0000">Sample Output:</font>**

```C++
Yes
Yes
No
```

## 2. 题意

> <font color="#00dddd">判断一个数N是否在给出的基数D下是可逆素数，如果N本身是一个素数，在D基数体系下反向还是素数（将N转成D进制后，再反向转成十进制后还是素数），这样的数称为 **reversible prime** ，输出Yes</font>
>
> <font color="#00dddd">输入：输入文件由多个测试用例组成。每个案例占用一行，其中包含两个整数*N*和*D*.输入由负数完成*N*.</font>
>
> <font color="#00dddd">输出：对于每个测试用例，如果*N*是基数*D*的可逆素数输出`Yes`，否则输出`No`。</font>

## 3. 思路

><font color="#dd00dd">使用index来表示当前的所处的位置，然后每次读入一个x，将index到x的代价累加到ans中，并更新当前位置index的值。</font>

## 4. 代码

```c++
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
	int ans = 0;
	while(x!=0){
		ans = ans*d + x%d;
		x = x/d;
	}
//	cout << "x= " << x <<" ans=" <<ans << endl;
	return ans;
}

int main(){
	int N,D;
	while(true){
		cin >> N;
		if(N<0) break;
		cin >> D;
		if(checkPrime(N)&&checkPrime(Reversible(N,D))){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
```



