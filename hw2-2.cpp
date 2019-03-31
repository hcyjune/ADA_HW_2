#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
struct point{
	int x;
	int y;
};
int main(){
	int N;
	cin>>N;	
	if (N<=1000){
		point a[N];
		for (int i=0;i<N;i++){
			scanf("%d %d",&a[i].x,&a[i].y);
		}
		for (int i=0;i<N;i++){
			unsigned long long time_sum=0,time;
			for (int j=0;j<N;j++){
				int dist_x=abs(a[i].x-a[j].x);
				int dist_y=abs(a[i].y-a[j].y);
				int gap=dist_x-dist_y;
				time=0;
				while(dist_x!=0 or dist_y!=0){
					if (gap>0){
						if (dist_y==0){	
							time+=dist_x;
							dist_x=0;
						}
						else if (gap<=dist_y){
							time+=2*gap;
							dist_x-=2*gap; 
							dist_y-=gap;	
						}
						else{
							time+=2*dist_y;
							dist_x-=2*dist_y;
							dist_y=0;
						}
					}
					else if (gap<0){
						if (dist_x==0){
							time+=dist_y;
							dist_y=0;
						}
						else if (-gap<=dist_x){
							time-=2*gap;
							dist_y+=2*gap;
							dist_x+=gap;	
						}
						else{
							time+=2*dist_x;
							dist_y-=2*dist_x;
							dist_x=0;
						}
					}
					else{
						int q=dist_x/3;
						if (q!=0){
							time+=4*q;
							dist_x-=3*q;
							dist_y-=3*q;
						}
						else{
							if (dist_x==2){	
								time+=3;
							}
							else{
								time+=2;
							}
							dist_x=0;
							dist_y=0;
						}
					}
					gap=dist_x-dist_y;
				}
				time_sum+=time;
			}	
			printf("%llu\n",time_sum);
		}
	}
	else{
		printf("0\n");
	}
	return 0;
}
