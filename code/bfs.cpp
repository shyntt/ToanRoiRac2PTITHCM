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

void BFS_queue(int v){
	queue <int> q;
	q.push(v);
	chuaxet[v]=false;
	printf("%d->",v);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(a[u][i]==1&&chuaxet[i]){
				printf("%d->",i);
				chuaxet[i]=false;
				q.push(i);
			}
		}
	}
}
int main(){
	fp=fopen("matranke.txt","r");
	puts("Ma tran ke");
	inputDoThi();
	outputDoThi();
	BFS_queue(1);
}
