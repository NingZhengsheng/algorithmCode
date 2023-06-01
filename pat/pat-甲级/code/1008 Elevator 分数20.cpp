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
