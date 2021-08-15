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
bool check(){
	for(int i=1;i<=n;i++){
		if(chuaxet[i]==true){
			return false;
		}
	}
	return true;
}

bool DoThiEuler(){
	DFS_dequi(1);
	if(check()){
		for(int i=1;i<=n;i++){
			int s=0;
			for(int j=1;j<=n;j++){
				if(a[i][j]==1){
					s++;
				}
			}
			if(s%2!=0){
				printf("Khong phai do thi euler");
				return false;
			}
		}
	}else{
		printf("Khong phai do thi euler");
		return false;
	}
	printf("\nLa do thi euler\n");
	return true;
}
void ChuTrinhEuler(int u){
	stack <int> s,v;
	s.push(u);
	while(!s.empty()){
		int i=s.top();
		int dem=0;
		for(int k=1;k<=n;k++){
			if(a[i][k]==0){
				dem++;
			}
		}
		if(dem!=n){// neu ke(i) kh rong xoa canh 
			for(int j=1;j<=n;j++){
				if(a[i][j]==1){
					s.push(j);
					a[i][j]=a[j][i]=0;
					break;
				}
			}
		}else{ // neu rong = n
			v.push(i);
			s.pop();
		}
	}
	puts("Chu trinh euler:");
	while(!v.empty()){
		printf("%d->",v.top());
		v.pop();
	}
}
int main(){
	fp=fopen("eulervohuong.txt","r");
	puts("Do thi vo huong");
	inputDoThi();
	outputDoThi();
	if(DoThiEuler()){
		ChuTrinhEuler(1);
	}else{
		puts("Khong co chu trinh euler");
	}
}
