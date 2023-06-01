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



