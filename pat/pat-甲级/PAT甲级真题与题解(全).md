# PAT甲级真题与题解



# **1001 A+B Format** 分数20

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805528788582400

**<font color="#dd0000">题目：1001 A+B Format</font>**

<font color="#0000dd">Calculate *a*+*b* and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).</font>  

**<font color="#dd0000">Input Specification:</font>**

<font color="#0000dd">Each input file contains one test case. Each case contains a pair of integers *a* and *b* where −$10^6 ≤*a*,*b*≤10^6. The numbers are separated by a space.</font>

**<font color="#dd0000">Output Specification:</font>**

<font color="#0000dd">For each test case, you should output the sum of *a* and *b* in one line. The sum must be written in the standard format.</font>

**<font color="#dd0000">Sample Input:</font>**

<font color="#00dd00">-1000000 9</font>

**<font color="#dd0000">Sample Output:</font>**

<font color="#00dd00">-999,991</font>

## 2. 题意

> <font color="#00dddd">计算a+b的和，将最后的结果以一种标准格式进行输出（数字必须用逗号分隔成三组（除非少于四位数字））。也就是说，最后将最后的结果每三位数字之间添加一个逗号进行隔开</font>

## 3. 思路

><font color="#dd00dd">1. 先将读入的a 和 b进行相加为 sum；</font>
>
><font color="#dd00dd">2. 判断sum是否为0（为0则直接输出结束）；判断sum是否为负数，用flag进行标记，如果sum为负数，将sum取反；</font>
>
><font color="#dd00dd">3. 对sum进行字符串转换，并在转换过程中，每三位在字符串中插入一个逗号，使用count来计数当前多少位了；</font>
>
><font color="#dd00dd">4. flag标识为负数时，则在结果字符串前面添加一个负号；</font>

## 4. 代码

```c++
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
```



------------------



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



--------------------

# 1003



---------------------------

# 1004





-----------------



# **1005 Spell It Right**分数 20

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805519074574336

**<font color="#dd0000">题目：1005 Spell It Right</font>**

<font color="#0000dd">Given a non-negative integer *N*, your task is to compute the sum of all the digits of *N*, and output every digit of the sum in English.</font>  

**<font color="#dd0000">Input Specification:</font>**

<font color="#0000dd">Each input file contains one test case. Each case occupies one line which contains an *N* (≤10^100）</font>

**<font color="#dd0000">Output Specification:</font>**

<font color="#0000dd">For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.</font>

**<font color="#dd0000">Sample Input:</font>**

```c++
12345
```

**<font color="#dd0000">Sample Output:</font>**

```C++
one five
```

## 2. 题意

> <font color="#00dddd">输入一个非负数整数N（长度<=100位），题目需要将N的每位数组进行相加，最后将相加的结果sum按位进行输出，输出时需要将数字用其英语单词表示，两两之间用空格分开。</font>

## 3. 思路

><font color="#dd00dd">1. 使用字符串string读入整数N，然后按位相加，得到sum。</font>
>
><font color="#dd00dd">2. 然后对sum进行按位转换（使用key_val数组），保存在ans中。</font>

## 4. 代码

```c++
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
```

---------------------------















