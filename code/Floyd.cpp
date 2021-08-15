#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stack>
#define max 100
#define INF 9999
using namespace std;
int arr[max][max], n;
int d[max][max], truoc[max][max];
int dinhdau, dinhcuoi=1;
bool chuaxet[max];
Init()
{
	ifstream filein;
	filein.open("Floyd.txt",ios::in);
	filein>>n;
	cout<<"So dinh: "<<n<<"\n";
	for(int i=1;i<=n;i++){
		chuaxet[i]=true;
		for(int j=1;j<=n;j++){
			filein>>arr[i][j];
			if (!arr[i][j])
			{
				arr[i][j] = INF;
				cout<<"oo ";
			}
			else printf("%02d ", arr[i][j]);	
		}
		puts("");
	}
	filein.close();
}
void Floyd()
{
	int i, j, k;
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			if (i != j)
			{
				d[i][j] = arr[i][j];
				truoc[i][j] = i;
			}
			else
			{
				d[i][j] = 0;
				truoc[i][j] = i;	
			}
		}
	}
	for (k=1; k<=n; k++)
	{
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					truoc[i][j] = truoc[k][j];
				}
			}
		}
	}
}

void print()
{
	for (int i=1; i<=n; i++)
	{
		printf("\n\nDo dai tu %d den V\\{ %d }: \n",i,i);
		for (int j=1; j<=n;j++)
		{
			printf("\n%d => %d\t\t", i, j);
			if (d[i][j] < INF)
			{	
				int tmp= truoc[i][j];
				printf("%d <= ", j);
				while (tmp != i)
				{
					printf("%d <= ", tmp);
					tmp = truoc[i][tmp];
				}
				printf("%d", i);
				
				printf("\t\tDuong di ngan nhat = %d\t\t",d[i][j]);
			}
			else printf("Khong co duong di!");
		}
	}
}
int main()
{
	Init();
	Floyd();
	print();
	return 0;
}
