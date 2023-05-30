#include<stdio.h>
int main(){
	int n,m;
	int a[21],c[21],b[21]; 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//³õÊ¼»¯
	c[0]=1,a[0]=1;
	for(int i=1;i<=n;i++){
		c[i] = c[i-1] * a[i];
		b[i] = ((m%c[i]) - (m%c[i-1]))/c[i-1];
	}
	//Êä³ö
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	} 
	return 0;
} 
