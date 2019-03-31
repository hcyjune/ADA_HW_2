#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int T,N;
	cin>>T;
	for (int i=0;i<T;i++){
		scanf("%d",&N);
		int x=ceil(log(N+1)/log(2));
		if(pow(2,x)==N+1){
			printf("%d\n",x);
		}
		else{
			int y=N+1-pow(2,x-1);
			int day=x-1;
			for (int j=x-2;j>=0;j--){
				int money=pow(2,j);
				if(y!=0 and y>=money){
					day+=y/money;
					y=y%money;
				}		
			}
			printf("%d\n",day);
		}
	}
	return 0;
} 
