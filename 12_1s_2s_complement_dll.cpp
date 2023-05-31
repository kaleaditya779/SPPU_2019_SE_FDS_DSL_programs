/*
Write C++ program for storing binary number using doubly linked lists. Write functions
    a) To compute 1‘s and 2‘s complement 
    b) Add two binary numbers
*/




#include<iostream>
using namespace std;

class Node
{
    public:
    Node* next;
    Node* prev;
    bool n;
    Node(){
        next = prev = NULL;
    }
    Node(bool a){
        next = NULL;
        prev = NULL;
        n = a;
    }
    friend class Binary;
};

class Binary
{
    Node* temp;
    public:
    Binary(){
     temp = NULL;
    }
    void generateB(int no);
    void displayB();
    void oneScomplement();
    void twoScomplement();
    Binary operator+(Binary n1);
    bool addBitAtBegin(bool val){
        Node *p = new Node(val);
        if (temp == NULL)
        {
            temp = p;
        }else
        {
            p->next = temp;
            temp->prev = p;
            temp = p;
        }
        return 1;
    }
};

void Binary :: generateB(int no){
    bool m = no%2;
    Node* p;
    temp = p;
    no = no/2;
    temp = new Node(m);
    while (no!=0)
    {
        m = no%2;
        no = no/2;
        p = new Node(m);
        p->next = temp;
        temp->prev = p;
        temp = p;
    }   
}

void Binary :: displayB(){
    Node* p1 = temp;
    cout<<"Binary : ";
    while (p1 != NULL)
    {
        cout<<p1->n;
        p1 = p1->next;
    }
}

void Binary :: oneScomplement(){
    Node* p = temp;
    while (p != NULL)
    {
        p->n == 0 ? p->n = 1 : p->n = 0;
        p = p->next;
    }
}

void Binary :: twoScomplement(){
    oneScomplement();
    bool carry = 1;
    Node *p = temp;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        if (p->n == 1 && carry == 1)
        {
            p->n = 0;
            carry = 1;
        }else if (p->n == 0 && carry == 1)
        {
            p->n = 1;
            carry = 0;
        }else if (carry == 0)
        {
            break;
        }
        p = p->prev;
    }
}

Binary Binary :: operator+(Binary n1){
    Binary sum;
    Node* a = temp;
    Node* b = n1.temp;
    bool carry = 0;
    while (a->next != NULL)
    {
        a = a->next;
    }
    while (b->next != NULL)
    {
        b = b->next;
    }
    while (a != NULL && b != NULL)
    {
        sum.addBitAtBegin((a->n) ^ (b->n) ^ carry);
        carry = ((a->n && b->n) || (a->n && carry) || (b->n && carry));
        a = a->prev;
        b = b->prev;
    }
    while (a!=NULL)
    {
        sum.addBitAtBegin(a->n ^ carry);
        a = a->prev;
    }
    while (b!=NULL)
    {
        sum.addBitAtBegin(b->n ^ carry);
        b = b->prev;
    }
    sum.addBitAtBegin(carry);
    return sum;
}

int main(int argc, char const *argv[])
{
    Binary a,b,c;
    a.generateB(2);
    a.displayB();
    cout<<endl;
    b.generateB(5);
    b.displayB();
    cout<<endl;
    c = a + b;
    c.displayB();
    cout<<endl;
    return 0;
}