#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

const int MaksimalKata = 10;
typedef string infotype;

struct Stack{
    infotype info[MaksimalKata];
    int top;
};

Stack createStack();
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype p);
void pop(Stack &S, infotype &p);
void show(Stack S);
bool Abjad(string Karakter);
int Operator(string opr);
string InflixToPostFlix(string Inflix);
bool Validasi(string Teks);
int Menu();

#endif // STACK_H_INCLUDED
