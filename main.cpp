#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;
typedef struct Item{
    string name ;
    int stat ;
}item ;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    item  loot1;
    loot1.name = "pisau";
    loot1.stat = 2;
    item  loot2;
    loot2.name = "pedang";
    loot2.stat = 5;
    item  loot3;
    loot3.name = "panci";
    loot3.stat = 8;
    item  loot4;
    loot4.name = "pistol";
    loot4.stat = 5;

    int jml, max_inventory, menu, hapus, n , i ;
    int jml_inventory = 0 ;
    vector<item> loot{loot1,loot2,loot3,loot4};
    vector<item>::iterator penunjuk ;
    vector<item> inventory;

    jml = 4;
    cout << "Input max inventory : ";
    cin >> max_inventory;

    menus:
        cout<<"Menu : " << endl;
        cout<<"1. Tampilkan inventory" << endl;
        cout<<"2. Hapus inventory" << endl;
        cout<<"3. Tambah inventory" << endl;
        cout<<"4. Keluar" << endl;
        cout << "Inventory slot = " <<jml_inventory<<"/"<<max_inventory<<"\n";
        cout << "input pilihan menu : ";
        cin >> menu ;
        switch(menu){
        case 1 :
            if(inventory.empty()){
                cout << "\ninventory kosong" << endl;
                goto  menus ;
            }else{
                cout << "\nitem list : \n";
                for(i = 0 ; i<inventory.size();i++){
                    cout << i+1 << " item name = " << inventory[i].name << "\n";
                    cout << "item stat = " << inventory[i].stat << "\n" ;
                }
                goto menus ;
            }
            break ;
        case 2 :
                if(inventory.empty()){
                    cout << "\ninventory kosong" << endl;
                    goto  menus ;
                }else{
                    cout << "\nItem List :\n";
                    for(i = 0 ; i< inventory.size();i++){
                        cout << i+1 << " Item name = " << inventory[i].name << "\n" ;
                        cout << "item stat = " << inventory[i].stat << "\n";
                    }
                    cout << "0 = cancel\n";
                    del:
                    cout << "Pilih item yg ingin di hapus = ";
                    cin >> hapus ;
                    if(hapus>jml_inventory){
                        cout << "item tidak ada" << endl;
                        goto del ;
                    }else if(hapus == 0 ){
                        goto menus ;
                    }else{
                        inventory.erase(inventory.begin()+(hapus-1));
                        cout << "item sudah dihapus" << endl ;
                        jml_inventory--;
                        goto menus;
                    }
                }
            break ;
        case 3 :
            if(jml_inventory == max_inventory){
                cout << "inventory anda penuh" << endl ;
                goto menus ;
            }else{
                n = rand() % jml ;
                inventory.push_back(loot[n]);
                cout << "\nanda mendapatkan = " << endl ;
                cout << "item name : " << loot[n].name << "\n" ;
                cout << "item stat : " << loot[n].stat << "\n";
                jml_inventory++;
                goto menus ;
            }
            break ;

        case 4 :
            system("pause");
            exit(0);
        default:
            goto menus;
        }
    return 0;
}
