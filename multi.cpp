#include "multi.h"

adr_sales Search_Sales (mll List_Sales, string nama_Sales) {
    /*
    Fungsi ini akan mencari nama sales pada list sales,
    jika ditemukan maka akan dikembalikan alamatnya, jika tidak ditemukan maka akan dikembalikan NIL
    */
    adr_sales P = List_Sales.first;
    while (P = NULL) {
        if (P->info.nama == nama_Sales) {
            return P;
        }
        P= P->next;
    }
    return NULL;
}

void insert_last_Sales(mll &List_Sales, adr_sales S){
    /*
    I.S. Terdefinisi list sales yang mungkin kosong, dan elemen sales baru yang disimpan oleh pointer S,
     yang akan diinsertkan menjadi elemen sales paling akhir pada list sales
    F.S. elemen baru menjadi elemen sales paling akhir pada list sales
    */
    if (List_Sales.first == NULL) {
        List_Sales.first = S;
    }else{
        adr_sales P = List_Sales.first;
        while (P->next != NULL){
            P = P->next;
        }
        P->next = S;
    }
}

adr_jual Delete_Last_Penjual (mll &List_Sales, adr_sales &S) {
    /*
    I.S. Terdefinisi list sales yang tidak kosong, dan elemen sales yang akan dihapus elemen penjualannya
    yang berada di posisi paling akhir
    F.S. Elemen penjualan paling akhir dari sales S dihapus dan alamatnya disimpan di pointer J.
    CLUE : Konsep delete last
    */
    adr_jual P = S->nextJual;
    adr_jual J;
    while((P->next)->next != NULL){
        P = P->next ;
    }
    J = P->next ;
    P->next = J->next;
    J->next = NULL;
    return J;
}

adr_jual Delete_after_Penjualan (mll &List_Sales, adr_sales &S, adr_jual prec) {
    /*
    I.S. Terdefinisi list sales yang tidak kosong, pointer prec
    F.S. Elemen penjualan yang berada setelah pointer prec  dihapus. CLUE : Konsepdelete after
    */
    adr_jual J = prec->next;
    prec->next = J->next;
    J->next = NULL;
    return J;
}

void createList(mll &List_sales){
    /*
    IS.–
    FS.Terbentuksebuahlistdimana,firstdariLbernilaiNIL.
    */
    List_sales.first = NULL;
};

adr_sales newElm_Sales(sales info){
    /* I.S. terdefinisi data sales dan  pointer yang akan menyimpan alamat elemen dari data sales yang baru
    F.S. data sales baru sudah menjadi elemen dan alamatnya disimpan oleh pointer S*/

    adr_sales p = new elm_sales;
    p->next = NULL;
    p->nextJual = NULL;
    p->info = info;
    return p;
}

adr_jual newElm_Jual(int info){
    /* I.S. terdefinisi data jumlah penjualan dan  pointer yang akan menyimpan alamat elemen dari data penjualan yang baru
    F.S. data sales baru sudah menjadi elemen dan alamatnya disimpan oleh pointer S*/

    adr_jual j = new elm_jual;
    j->next = NULL;
    j->info = info;
    return j;
}

void insertNew_Penjualan(mll &List_Sales, adr_sales s, adr_jual j){
    //I.S. Terdefinisi list sales yang tidak kosong, dan elemen penjualan baru yang akan disisipkan menjadi data penjualan pada sales S. Data penjualan pada sales S tidak kosong.F.S. Elemen penjualan baru akan disisipkan menjadi data penjualan paling akhirdi sales pada elemen S. CLUE : Konsep Insert Last}

    if(s->nextJual == NULL){
        s->nextJual = j;
    } else {
        adr_jual q = s->nextJual;
        while( q->next != NULL){
            q = q->next;
        }
        q->next = j;
    }
}

adr_jual delete_First_Penjualan(mll &List_Sales, adr_sales s){
    /*
    I.S. Terdefinisi list sales yang tidak kosong, dan elemen sales yang akan dihapus elemen penjualannya yang berada di posisi paling pertamaF.S. Elemen penjualan pertama dari sales S dihapus dan alamatnay disimpan di pointer J. CLUE : Konsep delete first }
    */
    adr_jual P;

    P = s->nextJual;
    if((s->nextJual)->next == NULL){
        s->nextJual = NULL;
    } else {
        s->nextJual = (s->nextJual)->next;
        P->next = NULL;
    };
    return P;
};

void showData_sales(mll List_Sales){
/*
    I.S. Terdefinisi list sales yang tidak kosong
    F.S. Data penjualan setiap sales tampil ke layar}

    HINT :Anda membutuhkan 2 pointer, pointer yang akan menelusuri elemen sales satu persatu,
    dan setiap kali pointer itu mengunjungi sebuah elemen sales, ada pointer kedua yang akan
    menelusuri elemen data penjualan dari sales tsb. Setelah selesai penelusuran elemen penjualan
    di sebuah elemen sales, maka pointer pertama tadi bergeser
    ke sales selanjutnya, dna mengulangi Langkah yang sama, hingga semua sales terkunjungi.
*/

    adr_sales ps = List_Sales.first;
    adr_jual pj;

    while(ps != NULL){
        cout<<ps->info.nama<<endl;
        pj=ps->nextJual;

        while(pj != NULL){
            cout<<pj->info<<" ";
            pj = pj->next;
        }
        cout<<endl;
        ps=ps->next;
    }
}

void delete_penjualan(mll &List_Sales){
/*I.S. Terdefinisi list sales yang tidak kosongF.S. Data penjualan kurang dari 3 dihapus dari elemen penjualan}*/

    adr_sales p1 = List_Sales.first;
    adr_jual p2,temp;
    while(p1 != NULL){
        p2 = p1->nextJual;
        while(p2 != NULL){
            temp = p2->next;
            if( p2->info < 3){
                if(p2 == p1->nextJual){
                    delete_First_Penjualan(List_Sales, p1);
                } else if ( p2->next == NULL){
                    Delete_Last_Penjual(List_Sales, p1);
                } else {
                    temp = temp->next;
                    Delete_after_Penjualan(List_Sales, p1, p2);
                }
            }
            p2 = temp;
        }
        p1 = p1->next;
    }
}
