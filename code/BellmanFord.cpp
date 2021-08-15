#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stack>
#define max 100
#define INF 9999
using namespace std;
int arr[max][max], n;
int d[max], truoc[max];
int s, dinhcuoi=1;
bool chuaxet[max];
Init()
{
	ifstream filein;
	filein.open("bellman.txt",ios::in);
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
ReInit()
{
	for(int i=1;i<=n;i++)
		chuaxet[i]=true;
}
void BellmanFord(int s)
{
	// khoi tao
	for (int v=1;v<=n;v++)
	{
		d[v] = arr[s][v];
		truoc[v] = s;
	}
	truoc[s] = s;
	d[s] = 0;
	int k = 1;
	while (k <= n-2)
	{
		for (int v=1 ;v<=n;v++) //1 - > n v != s
		{
			if (v != s)
			{
				for (int u=1;u<=n;u++){
				if (d[v] > d[u] + arr[u][v])
					{
						d[v] = d[u] + arr[u][v];
						truoc[v] = u;
					}
				}
			}
			
		}
		k++;
	}
}
void print()
{
	printf("\n\nDo dai tu %d den V\\{ %d }: \n",s,s);
	for (;dinhcuoi<=n; dinhcuoi++)
	{
		if (d[dinhcuoi] < INF)
		{
			printf("\n%d => %d \t\tDuong di ngan nhat = %d\t\t", s, dinhcuoi, d[dinhcuoi]);
			int i= truoc[dinhcuoi];
			printf("%d <- ", dinhcuoi);
			while (i != s)
			{
				printf("%d <- ", i);
				i = truoc[i];
			}
			printf("%d", s);
		}
		else
			puts("\nKhong co duong di.");
	}
}

int main()
{
	Init();
	s=1;
	BellmanFord(s);
	print();
	ReInit();
	
	return 0;
}
