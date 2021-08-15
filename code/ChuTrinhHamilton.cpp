#include<iostream>
#include <bits/stdc++.h> 
#define NMAX 100
#define Max 5
int a[NMAX+1][NMAX+1];
bool chuaxet[NMAX+1];
int n;
FILE *fp;
int truoc[Max+1];
using namespace std;
int dem=0;
int sce=0;
int ce[Max+2];
int v0=1;
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
void GhiNhan(){
	if (sce == 0)
	        cout<<"\nCac chu trinh Hamiltom co:\n";
	cout<<"\n";
	for (int i=1; i<=Max+1; i++)
	        {
	        	cout<<ce[i]<<"  ";
			}
	sce++;
}
void Hamilton(int k){
	for(int y=1;y<=n;y++){
		if(a[ce[k-1]][y]==1 && chuaxet[y]==true){
			ce[k]=y;
			chuaxet[y]=false;
			if(k<n+1){
				Hamilton(k+1);
			}
			else if(ce[k]==v0){// neu dinh cuoi ce=v0 & k=n+1=> xuat chu trinh
				GhiNhan();
			}
			chuaxet[y]=true;
		}
	}
}

int main(){
	fp=fopen("ChuTrinhHamilton.txt","r");
	puts("Do thi");
	inputDoThi();
	outputDoThi();
	ce[1]=1;
//	chuaxet[1]=false;
	Hamilton(2);
	if(sce==0){
		puts("Khong co chu trinh hamilton");
	}
}
