#include<iostream>
#include <bits/stdc++.h> 
#define NMAX 100
int a[NMAX+1][NMAX+1];
bool chuaxet[NMAX+1];
int n;
FILE *fp;
using namespace std;

void inputDoThi(){
	fscanf(fp,"%d",&n);
	for(int i=1;i<=n;i++){
		chuaxet[i]=true;
		for(int j=1;j<=n;j++){
			fscanf(fp,"%d",&a[i][j]);
			
		}
	}
}
void outputDoThi(){
	printf("Do thi ma tran %d dinh: \n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void DFS_dequi(int v){
	printf("%d->",v);
	chuaxet[v]=false;
	int i=1;
	for(i;i<=n;i++){
		if(a[v][i]&&chuaxet[i]){
			DFS_dequi(i);
		}
	}
}
void DFS_stack(int v){
	stack <int> s;
	s.push(v);
	chuaxet[v]=false;
	printf("%d->",v);
	while(!s.empty()){
		int u=s.top();
		s.pop();
		for(int i=1;i<=n;i++){
			if(a[u][i]==1&&chuaxet[i]){
				printf("%d->",i);
				chuaxet[i]=false;
				s.push(u);
				s.push(i);
				break;
			}
		}
	}
}
int main(){
	fp=fopen("matranke.txt","r");
	puts("Ma tran ke");
	inputDoThi();
	outputDoThi();
	DFS_dequi(1);
	puts("\n");
	DFS_stack(2);
}
