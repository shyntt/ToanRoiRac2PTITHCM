#include<iostream>
#define NMAX 100
int a[NMAX+1][NMAX+1];
int n;
FILE *fp;
using namespace std;

void inputDoThi(){
	fscanf(fp,"%d",&n);
	for(int i=1;i<=n;i++){
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

int main(){
	fp=fopen("matranke.txt","r");
	puts("Ma tran ke");
	inputDoThi();
	outputDoThi();
}
