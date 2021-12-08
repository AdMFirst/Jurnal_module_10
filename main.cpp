#include "multi.h"


int main(){
    int ctrl = 1;
    int jualbaru;
    mll L;
    sales salesbaru;
    adr_sales adrsalesbaru;
    createList(L);
    cout<<"menambah data"<<endl;
    while(ctrl != 0){

        cout << "masukan nama sales:";
        cin>>salesbaru.nama;
        cout << "masukan goloangan sales:";
        cin>>salesbaru.gol;
        adrsalesbaru = newElm_Sales(salesbaru);
        insert_last_Sales(L, adrsalesbaru);
        cout<<"masukan penjualan (akhiri dengan menginputkan -1):";
        cin>>jualbaru;
        while(jualbaru != -1){
            insertNew_Penjualan(L, adrsalesbaru,  newElm_Jual(jualbaru));
            cout<<"masukan penjualan (akhiri dengan menginputkan -1):";
            cin>>jualbaru;
        }
        cout<<"jika selesai menambah sales, ketik 0"<<endl;

        cout<<"jika lanjut menambah sales, ketik 1"<<endl;
        cin>>ctrl;
    }
    cout<<"sebelum delete penjualan"<<endl;
    showData_sales(L);
    cout<<"setelah delete penjualan"<<endl;
    delete_penjualan(L);
    showData_sales(L);



    return 0;
}
