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
vector<vector<int> > T;
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

bool check(){
	for(int i=1;i<=n;i++){
		if(chuaxet[i]==true){
			return false;
		}
	}
	return true;
}
void CayKhung_DFS(int u){
	chuaxet[u]=false;
	for(int v=1;v<=n;v++){
		if(a[u][v]==1&&chuaxet[v]){
				vector<int> canh;
				canh.push_back(u);
				canh.push_back(v);
				T.push_back(canh);
				CayKhung_DFS(v);
		}
	}
}
void CayKhung_BFS(int u){
	queue <int> q;
	q.push(u);
	chuaxet[u]=false;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int t=1;t<=n;t++){
			if(a[s][t]==1&&chuaxet[t]){
				vector<int> canh;
				canh.push_back(s);
				canh.push_back(t); 
				T.push_back(canh);
				chuaxet[t]=false;
				q.push(t);
			}
		}
	}
}

int main(){
	fp=fopen("caykhung.txt","r");
	puts("Do thi vo huong");
	inputDoThi();
	outputDoThi();
	CayKhung_DFS(1);
//	CayKhung_BFS(1);
	if(T.size()<n-1){
		puts("Do thi khong lien thong\n");
	}else{
		for(int i=0;i<T.size();i++){
			printf("canh [%d]: ",i+1);
			for(int j=0;j<T[i].size();j++){
				printf("%d ",T[i][j]);
			}
			puts("\n");
		}
	}
}
