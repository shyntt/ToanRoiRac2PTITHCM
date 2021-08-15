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

void DuyetCau(){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]==1){
				a[i][j]=a[j][i]=0;
				puts("\n");
				DFS_dequi(1);
				if(!check()){
					printf("Canh cau: %d->%d\n",i,j);
				}
				a[i][j]=a[j][i]=1;
				Reinit();
			}
		}
	}
}

int main(){
	fp=fopen("canhcau.txt","r");
	inputDoThi();
	outputDoThi();
	DuyetCau();
}
