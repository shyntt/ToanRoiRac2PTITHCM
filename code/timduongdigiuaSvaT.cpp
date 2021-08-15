#include<iostream>
#include <bits/stdc++.h> 
#define NMAX 100
int a[NMAX+1][NMAX+1];
bool chuaxet[NMAX+1];
int n;
FILE *fp;
int solt=0;
int truoc[NMAX+1];
using namespace std;

void inputDoThi(){
	fscanf(fp,"%d",&n);
	for(int i=1;i<=n;i++){
		chuaxet[i]=true;
		truoc[i]=0;
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
			truoc[i]=v;
			DFS_dequi(i);
		}
	}
}
void GhiNhanDuongDi(int s,int t){
	if(truoc[t]==0){
		puts("Khong co duong di");
	}else{
		printf("\n\nDUONG DI TU %d->%d:\n%d->",s,t,t);
		int i=truoc[t];
		while(i!=s){
			printf("%d->",i);
			i=truoc[i];
		}
		printf("%d",s);
	}
}

int main(){
	fp=fopen("timduongdigiuasvat.txt","r");
	inputDoThi();
	outputDoThi();
	DFS_dequi(1);
	GhiNhanDuongDi(1,13);
}
