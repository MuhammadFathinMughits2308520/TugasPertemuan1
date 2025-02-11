#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list{
	char barang[20];
	int id;
	struct list *next;
	struct list *prev;
}List;

List *buatList (int a,char b[]){
	List *New;
	New=(List*)malloc(sizeof(List));
	New->id=a;
	strcpy(New->barang,b);
	New->next=NULL;
	New->prev=NULL;
	return New;
}

void tambahAwal(int a, char b[], List **data){
	List *New=buatList(a,b);
	if(*data==NULL){
		*data=New;
		return;
	}
	(*data)->prev=New;
	New->next=*data;
	*data=New;
}

void tambahAfter(int a, char b[],int x, List **data){
	List *New=buatList(a,b);
	if(*data==NULL){
		*data=New;
		return;
	}
	List *temp=*data;
	while(temp->next!=NULL&&temp->id!=x){
		temp=temp->next;
	}
	if(temp->id==x){
		if(temp->next==NULL){
			temp->next=New;
			New->prev=temp;
			return;
		}
		New->next=temp->next;
		New->prev=temp;
		temp->next->prev=New;
		temp->next=New;
	}
}

void cetakList(List *data){
	List *temp=data;
	if(data!=NULL){
		while(temp->next!=NULL){
		temp=temp->next;
		}
		while(temp!=NULL){
			printf("%d. %s\n",temp->id,temp->barang);
			temp=temp->prev;
		}
	}else{
		printf("Kosong\n");
	}
	
}

void hapus(int x, List **list){
    if((*list) == NULL){
    	return;
	}
    if((*list)->id==x){//delet untuk diawal list
    	*list = (*list)->next;
    	(*list)->prev=NULL;
    	free(((*list)->prev));
    	return;
	}
	List *del=*list;
    while(del->next != NULL &&del->id!=x){
        del = del->next;
    }
    if(del->id==x){
    	if(del->next==NULL){//delet diakhir list
    		del->prev->next=NULL;
    		del = NULL;
    		free(del);
    		return;
		}
		//delet ditengah list
		del->prev->next=del->next;
		del = NULL;
		free(del);
	}else{
		printf("data tidak ditemukan\n");
	}
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p,id,tab,tabB=0;
    char nama[20];
    List *data=NULL;
    do{
    	scanf("%d",&p);
    	switch(p){
    		case 1:
				scanf("%d",&id);
				scanf("%s", nama);
				tambahAwal(id,nama,&data);break;
			case 2: 
				scanf("%d",&id);
				scanf("%s", nama);
				int x;
				scanf("%d",&x);
				tambahAfter(id,nama,x,&data);break;
			case 3: 
				scanf("%d",&id);
				hapus(id,&data);break;
			case 4: 
				cetakList(data);break;
		}
	}while(p!=4);
    return 0;
}

