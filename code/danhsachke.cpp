#include<iostream>
#define NMAX 100

int n;
FILE *fp;
using namespace std;

struct ke{
	int dinh;
	ke *next;
};
struct listKe{
	int size;
	ke* head;
	ke* tail;
};
ke* initKe(int d){
	ke *p=new ke;
	p->dinh=d;
	p->next=NULL;
	return p;
}
void initListKe(listKe &l){
	l.size=0;
	l.head=NULL;
	l.tail=NULL;
}
void addKe(listKe &l, ke* p){
	if(l.head==NULL){
		l.head=l.tail=p;
		return;
	}else{
//		printf(", ");
		l.tail->next=p;
		l.tail=p;
		return;
	}
}
void inputDoThi(listKe *l){
	for(int j=1;j<=n;j++){
		initListKe(l[j]);
//		printf("K(%d)={",j);
		fscanf(fp,"%d",&l[j].size);
		for(int i=0;i<l[j].size;i++){
			int d;
			fscanf(fp,"%d",&d);
			ke *p=new ke;
			p=initKe(d);
			addKe(l[j],p);
//			printf("%d",p->dinh);
//			printf("%d",l[j].tail->dinh);
		}
//		printf("}\n");
	}
		
}
void outputDoThi(listKe l[]){
	printf("So dinh: %d\n",n);
	for(int j=1;j<=n;j++){
		printf("K(%d)={",j);
		for(ke* i=l[j].head;i!=NULL;i=i->next){
			printf("%d",i->dinh);
			if(i->next!=NULL){
				printf(", ");
			}
		}
		printf("}\n");
	}
	
}
int main(){
	fp=fopen("danhsachke.txt","r");
	puts("Danh sach ke");
	fscanf(fp,"%d",&n);
	listKe *l=new listKe[n];
	inputDoThi(l);
	outputDoThi(l);
}
