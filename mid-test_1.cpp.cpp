/*
Program		: Soal 1
Nama		: Muhammad Risqullah Sudanta Gorau
NPM			: 140810180066
Tanggal		: 17/3/2019
*/


#include <iostream>
using namespace std;

struct ElemtList{
	char pemesan[30];
	char No[3];
	char nama[40];
	char harga[10];
	int jumlah;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;


void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void traversal(List First);
void bubbleSort(List First);
void search(List* &firstNode, int nomorKey, List* &pFound);
void update(List* firstNode, int nomorKey);


int main(){
	pointer p;
	List list;
	int pil,n;
	char loop='Y';
	do{
		cout<<"Banyak makanan : ";cin>>n;
		createList(list);
		for(int i=0; i<n; i++){
			cout<<"\nData ke-"<<i+1<<endl;
			createElmt(p);
			insertFirst(list,p);
		}
		do{
			system("CLS");
			cout<<"1. Tambah jumlah pesanan"<<endl;
			cout<<"2. Cetak Data \n";
			
			do{
				cin>>pil;
			}while(pil<1 || pil>3);
			switch(pil){
				case 1:
//					search();
					insertFirst(list,p);
					break;
				case 2:
					bubbleSort(list);
					traversal(list);
					cout<<"\nKembali ke menu? (Y/N) ";
					do{
						cin>>loop;
					}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
					break;
				case 4:
					loop='s';
					break;
			}
		}while(loop=='Y' || loop=='y');
	}while(loop=='s');
}

void createList(List& First){
	First=NULL;
}

void createElmt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"No\t\t: ";cin>>pBaru->No;
	cout<<"Nama Makanan\t: ";cin.ignore();cin.getline(pBaru->nama,20);
	cout<<"Harga\t: ";cin.getline(pBaru->harga,10);
	cout<<"Jumlah\t:";cin>>pBaru->jumlah;
	pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}else{
		pBaru->next=First;
		First=pBaru;
	}
}

void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
		do{
			cout<<"\nData ke-"<<i<<endl;
			cout<<"\nNo\t\t\t: "<<pBantu->No<<endl;
			cout<<"Nama Makanan\t\t: "<<pBantu->nama<<endl;
			cout<<"Harga\t\t\t: "<<pBantu->harga<<endl;
			cout<<"Jumlah\t\t\t:"<<pBantu->jumlah<<endl;
			pBantu=pBantu->next;
			i++;
		}while(pBantu!=NULL);
	}
	cout<<endl;
}

void bubbleSort(List First){
    int tukar, i;
    pointer pBantu;
    pointer last = NULL;

    if (First == NULL){
        return;
    }
    do{
        tukar = 0;
        pBantu = First;
        while (pBantu->next != last){
            if (pBantu->jumlah > pBantu->next->jumlah){
                swap(pBantu->jumlah, pBantu->next->jumlah);
                tukar = 1;
            }
            pBantu = pBantu->next;
        }
        last = pBantu;
    }
    while (tukar);
}


//void linearSearch (List First, int key, int& found, pointer& pCari){
//	found = 0;				
//	pCari = First;			
//	while (found == 0 && pCari != NULL){
//		if (pCari->jumlah == key){
//			found = 1;
//		}
//		else {
//			pCari = pCari->next;
//		}
//	}
//}
//
//void update (List& First, pointer& pUpdate, pointer pCari){
//    pUpdate = pCari;
//    cout << "Omelet Rendang: "; cin >> pUpdate->jumlah;
//    cout << "Nasi Gila: "; cin >> pUpdate->jumlah;
//    cout << "Chicken Katsu: "; cin >> pUpdate->jumlah;
//    cout << "Ayam Geprek: "; cin >> pUpdate->jumlah;
//    cout << "Nasi Goreng: "; cin >> pUpdate->jumlah;
//}
