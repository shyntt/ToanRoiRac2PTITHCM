#include<iostream>
#include <bits/stdc++.h> 
#define NMAX 100
int a[NMAX+1][NMAX+1];
bool chuaxet[NMAX+1];
int n;
FILE *fp;
int solt=0;
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
void DuyetTPLT(){

	for(int i=1;i<=n;i++){
		puts("\n");
		if(chuaxet[i]){
			solt++;
			DFS_dequi(i);
		}
	}
}
int main(){
	fp=fopen("DuyetTPLT.txt","r");
	puts("Ma tran ke");
	inputDoThi();
	outputDoThi();
	DuyetTPLT();
}
