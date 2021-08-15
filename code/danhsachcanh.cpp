#include<iostream>
#define NMAX 100

int n,m;
FILE *fp;
using namespace std;

struct canh{
	int dinhdau;
	int dinhcuoi;
	canh *next;
};
struct listCanh{
	canh* head;
	canh* tail;
};
canh* initCanh(int d,int c){
	canh *p=new canh;
	p->dinhdau=d;
	p->dinhcuoi=c;
	p->next=NULL;
	return p;
}
void initListCanh(listCanh &l){
	l.head=NULL;
	l.tail=NULL;	
}
void addCanh(listCanh &l,canh *p){
	if(l.head==NULL){
		l.head=p;
		l.tail=p;
		return;
	}else{
		l.tail->next=p;
		l.tail=p;
		return;
	}
}

void inputDoThi(listCanh &l){
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&m);
	while(!feof(fp)){
		int d,c;
		fscanf(fp,"%d",&d);
		fscanf(fp,"%d",&c);
		canh *p=new canh;
		p=initCanh(d,c);
		addCanh(l,p);
	}
}
void outputDoThi(listCanh l){
	printf("%d dinh  %d canh\n",n,m);
	for(canh* i=l.head;i!=NULL;i=i->next){
		printf("%d -> %d\n",i->dinhdau,i->dinhcuoi);
	}
}
int main(){
	fp=fopen("danhsachcanh.txt","r");
	puts("Danh sach canh");
	listCanh l;
	initListCanh(l);
	inputDoThi(l);
	outputDoThi(l);
}
