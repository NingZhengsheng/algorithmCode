#include<stdio.h>
int main(){
	int n,m,prev[102],val[102];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&prev[i]);
	}
	int start[101],end[101];
	bool flag=true;
	start[0]=1;
	for(int i=1;i<=m;i++){
		scanf("%d",&val[i]);
		start[i] = start[prev[i]] + val[prev[i]];
		if(start[i]+val[i]>n+1) flag=false;
	}
	
	for(int i=m;i>=1;i--){
		if(end[i]==0){
			end[i] = n - val[i] +1;
		}
		if(prev[i]!=0){
			if(end[prev[i]]==0){
				end[prev[i]] = end[i]-val[prev[i]];
			}
			else if(end[i]-val[prev[i]]<end[prev[i]]){
				end[prev[i]] = end[i]-val[prev[i]];
			}
		}
	}
	//Êä³ö½á¹û 
	for(int i=1;i<=m;i++){
		if(i==1) printf("%d",start[i]);
		else printf(" %d",start[i]);
	}
	printf("\n");
	if(flag){
		for(int i=1;i<=m;i++){
			if(i==1) printf("%d",end[i]);
			else printf(" %d",end[i]);
		}
		printf("\n");
	}
	return 0;
}
