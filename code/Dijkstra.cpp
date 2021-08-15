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
	filein.open("Dijkstra.txt",ios::in);
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
bool check(){
	for(int i=1;i<=n;i++){
		if(chuaxet[i]==true){
			return true;
		}
	}
	return false;
}
void Dijkstra(int s)
{
	// khoi tao
	int minValue, minNode;
	d[s] = 0;
	for (int v=1;v<=n;v++)
	{
		d[v] = arr[s][v];
		truoc[v] = s;
		chuaxet[v] = true;
	}
	truoc[s] = s;
	chuaxet[s] = false;
	while (check())
	{
		minValue = INF;
		for (int u=1; u<=n; u++)
		{
			if (chuaxet[u] && minValue > d[u])
			{
				minValue = d[u];
				minNode = u;
			}
		}
		
		if (minValue >= INF) break;
		chuaxet[minNode] = false;
		for (int v=1; v<=n; v++)
		{
			if (d[v] > d[minNode] + arr[minNode][v] && chuaxet[v])
			{
				d[v] = d[minNode] + arr[minNode][v];
				truoc[v] = minNode;
			}
		}
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
//		else
//			puts("\nKhong co duong di.");
	}
}

int main()
{
	Init();
	s =1;
	Dijkstra(s);
	print();
	return 0;
}
