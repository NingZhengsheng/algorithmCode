#include<stdio.h>
int main(){
	int m,n;
	int preNode[101]={0},needTime[101],startTime[101],endTime[101];
	//初始化数据 
	scanf("%d %d",&m,&n);
	preNode[0]=0,needTime[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&preNode[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&needTime[i]);
	}
	//计算最早开始时间 
	startTime[0]=1;
	for(int i=1;i<=n;i++){
		startTime[i] = startTime[preNode[i]] + needTime[preNode[i]];
		endTime[i] = m - needTime[i] + 1;
	}
	//计算最晚开始时间
	bool flag = true;
	for(int i=n;i>0;i--){
		if(preNode[i]!=0 && endTime[preNode[i]] > endTime[i] - needTime[preNode[i]]){
			endTime[preNode[i]] = endTime[i] - needTime[preNode[i]];
			if(endTime[preNode[i]]<1){
				flag = false;
				break;
			}
		}
	}
	//输出结果
	for(int i=1;i<=n;i++){
		printf("%d ",startTime[i]);
	}
	printf("\n");
	if(flag){
		for(int i=1;i<=n;i++){
			printf("%d ",endTime[i]);
		}
		printf("\n");
	}
	return 0;
}
