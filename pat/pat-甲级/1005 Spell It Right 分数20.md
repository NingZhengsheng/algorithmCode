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



