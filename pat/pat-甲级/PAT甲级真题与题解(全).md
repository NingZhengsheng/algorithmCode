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

# 1006





---------------------------



# 1007







# **1008 Elevator**分数 20

## 1. 原题

**<font color="#dd0000">原题链接：</font>**https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805511923286016

**<font color="#dd0000">题目：1008 Elevator</font>**

<font color="#0000dd">The highest building in our city has only one elevator. A request list is made up with *N* positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.</font>  

<font color="#0000dd">For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.</font>  

**<font color="#dd0000">Input Specification:</font>**

<font color="#0000dd">Each input file contains one test case. Each case contains a positive integer *N*, followed by *N* positive numbers. All the numbers in the input are less than 100.</font>

**<font color="#dd0000">Output Specification:</font>**

<font color="#0000dd">For each test case, print the total time on a single line.</font>

**<font color="#dd0000">Sample Input:</font>**

```c++
3 2 3 1
```

**<font color="#dd0000">Sample Output:</font>**

```C++
41
```

## 2. 题意

> <font color="#00dddd">我们城市最高的建筑只有一部电梯。请求列表由*N*正数。数字表示电梯将按指定顺序在哪些楼层停止。将电梯向上移动一层需要 6 秒，向下移动一层需要 4 秒。电梯将在每站停留5秒钟。对于给定的请求列表，您将计算完成列表上的请求所花费的总时间。电梯在开始时位于0楼，在满足要求后不必返回一楼。</font>
>
> <font color="#00dddd">输入：每个输入文件包含一个测试用例。每个事例都包含一个正整数*N*其次*N*正数。输入中的所有数字都小于 100。</font>
>
> <font color="#00dddd">输出：对于每个测试用例，在一行上打印总时间。</font>

## 3. 思路

><font color="#dd00dd">使用index来表示当前的所处的位置，然后每次读入一个x，将index到x的代价累加到ans中，并更新当前位置index的值。</font>

## 4. 代码

```c++
#include<iostream>
using namespace std;

int main(){
	/*
	  思路：使用index来表示当前的所处的位置，然后每次读入一个x，
			将index到x的代价累加到ans中，并更新当前位置index的值；
	 */
	int n,x,index=0,ans=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		if(x>=index) ans += (x-index)*6 + 5;
		else ans += (index-x)*4 + 5;
		index = x;
	}
	cout << ans << endl;
	return 0;
}
```

-----------------------





-------------------

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















