#include<stdio.h>
#include<math.h>
//#include <algorithm>
//using namespace std;
int main(){
	int n,a,b,res=0;
	int x1,y1,x2,y2;
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		//判断是否有交集 
		if(x1>a || x2<0 || y1>b || y2<0){
			continue;
		}else{
			x1 = fmax(x1,0);
			x2 = fmin(x2,a);
			y1 = fmax(y1,0);
			y2 = fmin(y2,b);
			res+= (x2-x1)*(y2-y1);
		}
	}
	printf("%d\n",res);
	return 0;
}
