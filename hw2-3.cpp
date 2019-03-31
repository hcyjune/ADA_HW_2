#include <iostream>
using namespace std;
int main(){
	int n,m,N=1000000007;
	unsigned long long tmp;
	scanf("%d %d",&n,&m);
	int a[2][m];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			scanf("%llu",&tmp);
			if (tmp%33==0){
				int digit_3=0,digit_6=0,digit_9=0,digit;
				while(tmp!=0){
					digit=tmp%10;
					if (digit==3){
						digit_3+=1;
					}
					else if (digit==6){
						digit_6+=1;
					}
					else if (digit==9){
						digit_9+=1;
					}
					tmp=tmp/10;
				}
				if (digit_3%3==0 and digit_6%3==0 and digit_9%3==0){
					a[i%2][j]=0;	
				}
				else{
					if (i==0 and j==0){
						a[0][0]=1;
					}
					else if (i==0){
						a[i%2][j]=a[i%2][j-1];
					}
					else if (j==0){
						a[i%2][j]=a[1-i%2][j];
					}
					else{
						a[i%2][j]=(a[1-i%2][j]+a[i%2][j-1])%N;
					}
				}
			}
			else{
				if (i==0 and j==0){
					a[0][0]=1;
				}
				else if (i==0){
					a[i%2][j]=a[i%2][j-1];
				}
				else if (j==0){
					a[i%2][j]=a[1-i%2][j];
				}
				else{
					a[i%2][j]=(a[1-i%2][j]+a[i%2][j-1])%N;
				}
			}
			//cout<<a[i%2][j]<<endl;
		}
	}
	printf("%llu",a[(n-1)%2][m-1]);
	return 0;
}
