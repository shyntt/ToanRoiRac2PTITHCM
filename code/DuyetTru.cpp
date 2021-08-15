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
int dem=0;
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
int DFS_dequi(int v){
	printf("%d->",v);
	chuaxet[v]=false;
	int i=1;
	for(i;i<=n;i++){
		if(a[v][i]&&chuaxet[i]){
			DFS_dequi(i);
		}
	}
	return dem;
}
void Reinit(){

	for(int i=1;i<=n;i++){
		chuaxet[i]=true;
	}
}
bool check(){
	for(int i=1;i<=n;i++){
		if(chuaxet[i]==true){
			return false;
		}
	}
	return true;
}

void DuyetTru(){
	
	for(int i=1;i<=n;i++){
		printf("\n");
		chuaxet[i]=false;
		int v=i+1; if(v>n) v=1; 
		DFS_dequi(v);
		if(!check()){
			printf("\n%d la dinh tru",i);
		}
		Reinit();
	}
}

int main(){
	fp=fopen("dinhtru.txt","r");
	inputDoThi();
	outputDoThi();
	DuyetTru();
}
