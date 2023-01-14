#include "stack.h"

Stack createStack()
{
    Stack S;
    S.top = -1;
    return S;
};
bool isEmpty(Stack S)
{
    if(S.top == -1)
    {
        return true;
    }else
    {
        return false;
    }
};
bool isFull(Stack S)
{
    if(S.top == MaksimalKata){
        return true;
    }else
    {
        return false;
    }
};
void push(Stack &S, infotype p)
{
    if(!isFull(S))
    {
        S.top = S.top + 1;
        S.info[S.top] = p;
    }
};
void pop(Stack &S, infotype &p)
{
    if(!isEmpty(S))
    {
        p = S.info[S.top];
        S.top = S.top - 1;
    }else
    {
        p = "";
    }
};
void show(Stack S)
{
    if(!isEmpty(S)){
        int n = S.top;
        int i;
        for(i = n; i >= 0; i--)
        {
            cout<<S.info[i]<<endl;
        }
    }else
    {
        cout<<"Stack kosong"<<endl;
    }
};
bool Abjad(string Karakter)
{
    if((Karakter >= "a" && Karakter <= "z") || (Karakter >= "A" && Karakter <= "Z"))
    {
        return true;
    }else
    {
        return false;
    }
};
int Operator(string opr)
{
    if(opr == "+" || opr == "-")
    {
        return 1;
    }else if(opr == "*" || opr == "/")
    {
        return 2;
    }else if(opr == "^")
    {
        return 3;
    }
    return 0;
};
string InflixToPostFlix(string Inflix)
{
    Stack S;
    S = createStack();
    string PostFlix = "";
    int n = Inflix.length();
    int i;
    string KarakterInflix;
    for(i=0;i<n;i++)
    {
        KarakterInflix = Inflix[i];
        if(Abjad(KarakterInflix)){
            PostFlix = PostFlix + KarakterInflix;
        }else if(KarakterInflix == "(")
        {
            push(S, KarakterInflix);
        }else if(KarakterInflix == ")")
        {
            string KarakterTopStack;
            pop(S, KarakterTopStack);
            while(KarakterTopStack != "(")
            {
                PostFlix = PostFlix + KarakterTopStack;
                pop(S, KarakterTopStack);
            }
        }else
        {
            while(!isEmpty(S) && Operator(KarakterInflix) <= Operator(S.info[S.top]))
            {
                pop(S, KarakterInflix);
                PostFlix = PostFlix + KarakterInflix;
            }
            push(S, string(1, Inflix[i]));
        }
    }
    while(!isEmpty(S))
    {
        pop(S, KarakterInflix);
        PostFlix = PostFlix + KarakterInflix;
    }
    return PostFlix;
};
bool Validasi(string Teks)
{
    bool cek = false;
    Stack SValidasi;
    SValidasi = createStack();
    int n = Teks.length();
    int i;
    for(i = 0; i < n; i++){
        string Karakter = string(1, Teks[i]);
        if(Karakter == "(" || Karakter == "{" || Karakter == "[")
        {
            cek = true;
            push(SValidasi, Karakter);
        }else if(Karakter == ")")
        {
            if(isEmpty(SValidasi) || SValidasi.info[SValidasi.top] != "(")
            {
                return false;
            }
            pop(SValidasi, Karakter);
        }else if(Karakter == "}")
        {
            if(isEmpty(SValidasi) || SValidasi.info[SValidasi.top] != "{")
            {
                return false;
            }
            pop(SValidasi, Karakter);
        }else if(Karakter == "]")
        {
            if(isEmpty(SValidasi) || SValidasi.info[SValidasi.top] != "[")
            {
                return false;
            }
            pop(SValidasi, Karakter);
        }
    }
    return isEmpty(SValidasi) && cek;
};
int Menu()
{
    int pilih;

    cout<<"===================MENU==================="<<endl;
    cout<<"1. Menambahkan Data"<<endl;
    cout<<"2. Menghapus Data"<<endl;
    cout<<"3. Menampilkan Data"<<endl;
    cout<<"4. Mengubah infix menjadi postfix"<<endl;
    cout<<"5. Validasi Bracket"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"Pilih: ";
    cin>>pilih;
    cout<<"=========================================="<<endl;

    return pilih;
};
