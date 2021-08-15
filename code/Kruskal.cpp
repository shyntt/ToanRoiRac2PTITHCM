#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
FILE *fp;
struct edge
{
    int dinhdau, dinhcuoi, trongso;
};
// n dinh, m canh  d tong trong so
int n, m, D = 0;
vector<int> parent;
vector<edge> edges;
vector<edge> T;

void inputDoThi()
{

	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
	parent.resize(n);
    edges.resize(m);
    for(int i=0;i<m;i++)
	{
		fscanf(fp,"%d",&edges[i].dinhdau);
		fscanf(fp,"%d",&edges[i].dinhcuoi);
		fscanf(fp,"%d",&edges[i].trongso);
	}
}
void outputDoThi(){
	printf("%d dinh  %d canh\n",n,m);
	for(int i=0;i<m;i++){
		printf("(%d,%d) = %d\n",edges[i].dinhdau,edges[i].dinhcuoi,edges[i].trongso);
	}
}
bool cmp(const edge &a, const edge &b)
{
    return a.trongso < b.trongso;
}

void Kruskal()
{
    for(int v = 1; v <= n; v++)
        parent[v] = v;
	// B1 sapxep
    sort(edges.begin(), edges.end(), cmp); 
    puts("Danh sach canh sau khi sap xep\n");
	outputDoThi();

    for(int i=0;i<m;i++)
    {
        if(parent[edges[i].dinhdau] != parent[edges[i].dinhcuoi])// khong tao chu trinh
        {
            D += edges[i].trongso;
            T.push_back(edges[i]);

            int old_par = parent[edges[i].dinhcuoi];
            int new_par = parent[edges[i].dinhdau];
            for(int j = 1; j <= n; j++)
            {
                if(parent[j] == old_par)
                    parent[j] = new_par;
            }
        }
    }
}

void printResults()
{
    puts("Canh cua cay khung nho nhat: \n");
    for(int i = 0; i < T.size(); i++)
        printf("(%d,%d) = %d\n",T[i].dinhdau,T[i].dinhcuoi,T[i].trongso);
    printf("Gia tri cua cay khung nho nhat: %d",D);
}
int main()
{
	fp=fopen("Kruskal.txt","r");
	puts("Danh sach canh");
    inputDoThi();
    outputDoThi();
    simpleKruskal();
    printResults();
    return 0;
}


















