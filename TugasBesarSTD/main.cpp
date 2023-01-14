#include "stack.h"

int main()
{
    Stack DataStack;
    int pilih;
    string infix, postfix;
    string hapus;
    DataStack = createStack();

    pilih = Menu();
    while(pilih != 6){
        if(pilih == 1){
            cout<<"Infix: ";
            cin>>infix;
            push(DataStack, infix);
        }else if(pilih == 2){
            pop(DataStack, hapus);
            cout<<"Data dihapus: "<<hapus<<endl;
        }else if(pilih == 3){
            show(DataStack);
        }else if(pilih == 4){
            pop(DataStack, hapus);
            if(hapus != ""){
                postfix = InflixToPostFlix(hapus);
                cout<<"Postfix: "<<postfix<<endl;
            }else
            {
                cout<<"Stack kosong"<<endl;
            }
        }else if(pilih == 5){
            pop(DataStack, hapus);
            if(Validasi(hapus))
            {
                cout<<"true"<<endl;
            }else
            {
                cout<<"false"<<endl;
            }
        }
        pilih = Menu();
    }
    return 0;
}
