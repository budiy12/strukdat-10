/**
 * Tanggal  : 14 Mei 2019
 * Nama     : Asep Budiyana M
 * NPM      : 140810180029
 * Kelas    : A
 * Program  : Tree (menu)
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul(pointer& pBaru, int angka){
    pBaru = new Simpul;
    pBaru->info = angka;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST(Tree& Root, pointer pBaru){
    if (Root==NULL)
        Root = pBaru;
    else if(pBaru->info < Root->info)
        insertBST(Root->left, pBaru);
    else if(pBaru->info > Root->info)
        insertBST(Root->right, pBaru);
    else{
        cout<<"sudah ada";
    }
}

void notasiKurung(Tree Root){
    if(Root!=NULL){
        cout<<"(";
        cout<<Root->info<<" ";
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout<<")";
    }
}

void preOrder(Tree Root){
    if(Root!=NULL){
        cout<<Root->info<<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder(Tree Root){
    if(Root!=NULL){
        inOrder(Root->left);
        cout<<Root->info<<endl;
        inOrder(Root->right);
    }
}

void postOrder(Tree Root){
    if (Root!=NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<<Root->info<<endl;
    }
}

int main()
{
    Tree R = NULL;
    pointer p;
    //sample data:
    // int no[] = {5,3,7,1,4,6,8,2,9};
    //menu
    char repeat;
    int menu,number;
    //sample program:
    // for (int i=0;i<9;i++){
    //     createSimpul(p,no[i]);
    //     insertBST(R,p);
    // }

    do{
        system("cls");
        notasiKurung(R);
        cout<<"\nMenu:"
        <<"\n1. Input Data"
        <<"\n2. Pre Order"
        <<"\n3. In Order"
        <<"\n4. Last Order"
        <<"\n5. Exit";
        cout<<"\nChoose (1-4): ";cin>>menu;
        switch(menu){
            case 1:
            cout<<"Number: ";cin>>number;
            createSimpul(p,number);
            insertBST(R,p);
            break;
            case 2:
            cout<<"Pre Order\n";
            preOrder(R);
            break;
            case 3:
            cout<<"In Order\n";
            inOrder(R);
            break;
            case 4:
            cout<<"Post Order\n";
            postOrder(R);
            break;
            case 5:
            return 0;
            break;
            default:
            break;
        }
        cout<<"\nWant to Repeat(y/n)?";cin>>repeat;
    }while(repeat=='y'||repeat=='Y');
    return 0;
}
