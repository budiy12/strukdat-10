/**
 * Tanggal  : 14 Mei 2019
 * Nama     : Asep Budiyana M
 * NPM      : 140810180029
 * Kelas    : A
 * Program  : Queue dengan Linked List
 */
#include <iostream>
using namespace std;

struct ElemenQueue {
    int isi;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List head;
    List tail;
};
Queue Q;

void createQueue(Queue& Q){
    Q.head = NULL;
    Q.tail = NULL;
}

void createElemen(pointer& p){
    p = new ElemenQueue;
    cout<<"Angka: ";cin>>p->isi;
    p->next = NULL;
}

void push(Queue& Q, pointer pBaru){
    if (Q.head==NULL&&Q.tail==NULL){ // Stack kosong
        Q.head = pBaru;
        Q.tail = pBaru;
    }
    else { // Stack ada isi
        Q.tail->next = pBaru;
        Q.tail = pBaru;
    }
}

void pop(Queue& Q, pointer& pHapus){
    if (Q.head==NULL&&Q.tail==NULL){
        cout<<"Stack kosong "<<endl;
        pHapus=NULL;
    }
    else if (Q.head->next==NULL){
        pHapus=Q.head;
        Q.head=NULL;
        Q.tail=NULL;
    }
    else {
        pHapus=Q.head;
        Q.head=Q.head->next;
        pHapus->next=NULL;
    }
}

int main(){
    pointer p,h;
    int n;
    createQueue(Q);
    cout<<"Banyak Data: ";cin>>n;
    for (int i=0;i<n;i++){
        createElemen(p);
        push(Q,p);
    }
    cout<<"\nIsi Queue: Q = Keluar<--";
    while(Q.head!=NULL){
        cout<<" "<<Q.head->isi<<" ";
        pop(Q,h);
    }
    cout<<"<--Masuk";
    return 0;
}