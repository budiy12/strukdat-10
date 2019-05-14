/**
 * Tanggal  : 14 Mei 2019
 * Nama     : Asep Budiyana M
 * NPM      : 140810180029
 * Kelas    : A
 * Program  : Queue dengan Array
 */
#include <iostream>
using namespace std;

const int maxElemen = 255;
struct Queue {
    int isi[maxElemen];
    int head;
    int tail;
};
Queue Q;

int empty(Queue Q){
    return Q.head && Q.tail == -1;
}

void enqueue(Queue& Q, int elemen) {
    int posisiTemp;
    if (empty(Q)) { 
        Q.head=0;
        Q.tail=0;
        Q.isi[Q.tail] = elemen;
    }
    else {
        posisiTemp=Q.tail; 
        if (Q.tail< maxElemen-1 ) { 
            Q.tail=Q.tail+1;
        }
        else { 
            Q.tail=0;
        }
        if (Q.tail==Q.head){
            cout<<"Antrian sudah penuh"<<endl;
            Q.tail=posisiTemp; 
        }
        else {
            Q.isi[Q.tail] = elemen;
        }
    }
}

void dequeue(Queue& Q, int& elemenHapus){
    if (empty(Q)) { 
        cout<<"Antrian kosong"<<endl;
    }
    else if (Q.head==Q.tail){ 
        elemenHapus= Q.isi[Q.head];
        Q.isi[Q.head]=' ';
        Q.head=-1; 
        Q.tail=-1;
    }
    else { 
        elemenHapus= Q.isi[Q.head];
        Q.isi[Q.head]=' ';
        if (Q.head<maxElemen-1) {
            Q.head=Q.head+1;
        }
        else { 
            Q.head=0;
        }
    }
}

int main()
{
    int n,angka;
    Q.head = -1;
    Q.tail = -1; 

    cout<<"Banyak Data: ";cin>>n;
    for (int i=0;i<n;i++){
        cout<<"Angka : ";cin>>angka;
        enqueue(Q,angka);
    }
    cout<<"\nIsi Queue: Q = Keluar<--";
    for(int i=0;i<n;i++){
        cout<<" "<<Q.isi[i]<<" ";
    }
    cout<<"<--Masuk";
    return 0;
}
