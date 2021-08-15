#include <iostream>
#include <algorithm>
#include <vector>
#define Max 100
using namespace std;
FILE *fp;
struct edge
{
    int dinhdau, dinhcuoi, trongso;
};
// n dinh, m canh  d tong trong so
int n, m, D = 0;

vector<edge> edges;
vector<edge> T;
int Vh[14],V[14];
void init(){
	Vh[1]=1;
	V[1]=0;
	for(int i=2;i<=n;i++){
		Vh[i]=0;
		V[i]=1;
	}
}
void inputDoThi()
{

	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
    edges.resize(m);
    for(int i=0;i<m;i++)
	{
		fscanf(fp,"%d",&edges[i].dinhdau);
		fscanf(fp,"%d",&edges[i].dinhcuoi);
		fscanf(fp,"%d",&edges[i].trongso);
	}
	init();
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
bool V_empty(){
	for(int i=1;i<=n;i++){
		if(V[i]==1){
			return false;
		}
	}
	return true;
}

bool checkV_Vh(int dinhdau,int dinhcuoi){
	if(Vh[dinhcuoi]==1&&Vh[dinhdau]==1){
		return false;
	}
	return true;
}

void Prim1()
{
    sort(edges.begin(), edges.end(), cmp); 
    puts("Danh sach canh sau khi sap xep\n");
	outputDoThi();
	while(!V_empty()){
		edge e=edges.front();
		edges.erase(edges.begin());
		if(checkV_Vh(e.dinhdau,e.dinhcuoi)){
			D=D+e.trongso;
			T.push_back(e);
			V[e.dinhdau]=0;
			V[e.dinhcuoi]=0;
			Vh[e.dinhcuoi]=1;
			Vh[e.dinhdau]=1;
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
	fp=fopen("Prim1.txt","r");
	puts("Danh sach canh");
    inputDoThi();
    outputDoThi();
    Prim1();
    printResults();
    return 0;
}


















