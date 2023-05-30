#include<stdio.h>
int main(){
   int n,m;
   double r,sum=0,t=1;
   scanf("%d %lf",&n,&r);
   for(int i=0;i<n+1;i++){
   		scanf("%d",&m);
   		sum += (1.0*m)/t;
   		t = t * (1+r);
   }
   printf("%.3f\n",sum);
   return 0;
}
