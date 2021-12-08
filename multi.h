#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elm_sales *adr_sales;
typedef struct elm_jual *adr_jual;

struct sales {
    string nama, gol;
};

struct elm_sales {
    sales info;
    adr_sales next;
    adr_jual nextJual;
};

struct elm_jual {
    int info;
    adr_jual next;
};

struct mll {
    adr_sales first;
};

adr_sales Search_Sales (mll List_Sales, string nama_Sales);
void insert_last_Sales(mll &List_Sales, adr_sales S);
adr_jual Delete_Last_Penjual (mll &List_Sales, adr_sales &S);
adr_jual Delete_after_Penjualan (mll &List_Sales, adr_sales &S, adr_jual prec) ;
void createList(mll &List_sales);
adr_sales newElm_Sales(sales info);
adr_jual newElm_Jual(int info);
void insertNew_Penjualan(mll &List_Sales, adr_sales s, adr_jual j);
adr_jual delete_First_Penjualan(mll &List_Sales, adr_sales s);
void showData_sales(mll List_Sales);
void delete_penjualan(mll &List_Sales);

#endif // MULTI_H_INCLUDED
