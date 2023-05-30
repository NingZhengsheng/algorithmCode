# PAT甲级真题与题解



# **1001 A+B Format** 分数 20

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













