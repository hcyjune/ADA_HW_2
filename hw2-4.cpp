#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string l,r;
	getline(cin,l,' ');
	getline(cin,r);
	int L[l.size()],R[r.size()];
	for (int i=0;i<l.size();i++){
		L[i]=l[i]-'0';
	}
	for (int i=0;i<r.size();i++){
		R[i]=r[i]-'0';
	}
	int one=1;
	/*int******* M=new int****** [r.size()];//dynamic allocation
	for (int a=0;a<r.size();a++){
		M[a]=new int***** [10];
		for (int b=0;b<10;b++){
			M[a][b]=new int**** [3];
			for (int c=0;c<3;c++){
				M[a][b][c]=new int*** [3];
				for (int d=0;d<3;d++){
					M[a][b][c][d]=new int** [3];
					for (int e=0;e<3;e++){
						M[a][b][c][d][e]=new int* [3];
						for (int f=0;f<3;f++){
							M[a][b][c][d][e][f]=new int [11];
						}
					}
				}
			}
		}
	}
	for (int a=0;a<r.size();a++){		
		for (int b=0;b<10;b++){
			for (int c=0;c<3;c++){
				for (int d=0;d<3;d++){
					for (int e=0;e<3;e++){
						for (int f=0;f<3;f++){
							for (int g=0;g<11;g++){
								M[a][b][c][d][e][f][g]=0;
							}
						}
					}
				}
			}
		}
	}*/
	int M[r.size()][10][3][3][3][3][11];
	fill(&M[0][0][0][0][0][0][0],&M[0][0][0][0][0][0][0]+sizeof(M)/sizeof(one),0);
	M[0][0][0][0][0][0][0]=1;M[0][5][0][0][0][2][5]=1;
	M[0][1][0][0][0][1][1]=1;M[0][6][0][1][0][0][6]=1;
	M[0][2][0][0][0][2][2]=1;M[0][7][0][0][0][1][7]=1;
	M[0][3][1][0][0][0][3]=1;M[0][8][0][0][0][2][8]=1;
	M[0][4][0][0][0][1][4]=1;M[0][9][0][0][1][0][9]=1;
	int A,B,C,D,E,F,G,N=1000000007;	
	for (int a=0;a<r.size()-1;a++){
		for (int B=0;B<10;B++){
			for (int b=0;b<10;b++){
				for (int c=0;c<3;c++){
					for (int d=0;d<3;d++){
						for (int e=0;e<3;e++){
							for (int f=0;f<3;f++){
								for (int g=0;g<11;g++){
									int tmp=M[a][b][c][d][e][f][g];
									if (tmp!=0){
										A=a+1;C=c;D=d;E=e;
										if (B==3){C+=1;C%=3;}
										else if (B==6){D+=1;D%=3;}
										else if (B==9){E+=1;E%=3;}
										F=(B+f)%3;
										if (A%2==1){
											G=(-B+g)%11;
											if (G<0){
												G+=11;
											}
										}
										else{
											G=(B+g)%11;
										}
										M[A][B][C][D][E][F][G]+=tmp;M[A][B][C][D][E][F][G]%=N;
									}
								}								
							}
						}
					}
				}
			}
		}
	}	
	int l_ans=1;//0 is illuminate
	if (l.size()!=1){
		for (int i=1;i<l.size()-1;i++){
			for (int j=1;j<10;j++){
				l_ans+=M[i][j][0][0][0][0][0];l_ans%=N;
			}	
		}
		for (int j=1;j<L[0];j++){
			l_ans+=M[l.size()-1][j][0][0][0][0][0];l_ans%=N;
		}	
		C=0;D=0;E=0;F=0;G=0;
		for (int i=1;i<l.size();i++){
			if (L[i-1]==3){C-=1;}
			else if (L[i-1]==6){D-=1;}
			else if (L[i-1]==9){E-=1;}
			F-=L[i-1];
			if ((l.size()-i)%2==1){G+=L[i-1];}
			else{G-=L[i-1];}
			if (C<0){C+=3;}
			if (D<0){D+=3;}
			if (E<0){E+=3;}
			if (F<0){F+=9;}
			if (G<0){G+=11;}
			C%=3;D%=3;E%=3;F%=3;G%=11;
			for (int j=0;j<L[i];j++){
				l_ans+=M[l.size()-1-i][j][C][D][E][F][G];l_ans%=N;
			}
		}
	}
	int r_ans=1;//0 is illuminate
	if (r.size()!=1){
		for (int i=1;i<r.size()-1;i++){
			for (int j=1;j<10;j++){
				r_ans+=M[i][j][0][0][0][0][0];r_ans%=N;
			}	
		}
		for (int j=1;j<R[0];j++){
			r_ans+=M[r.size()-1][j][0][0][0][0][0];r_ans%=N;
		}	
		C=0;D=0;E=0;F=0;G=0;
		for (int i=1;i<r.size();i++){
			if (R[i-1]==3){C-=1;}
			else if (R[i-1]==6){D-=1;}
			else if (R[i-1]==9){E-=1;}
			F-=R[i-1];
			if ((r.size()-i)%2==1){G+=R[i-1];}
			else{G-=R[i-1];}
			if (C<0){C+=3;}
			if (D<0){D+=3;}
			if (E<0){E+=3;}
			if (F<0){F+=9;}
			if (G<0){G+=11;}
			C%=3;D%=3;E%=3;F%=3;G%=11;
			for (int j=0;j<R[i];j++){
				r_ans+=M[r.size()-1-i][j][C][D][E][F][G];r_ans%=N;
			}		
		}
		r_ans+=M[0][R[r.size()-1]][C][D][E][F][G];r_ans%=N;
	}
	int ans=r_ans-l_ans;
	if (ans<0){
		ans+=N;
	}
	printf("%d",ans);
	return 0;
} 
