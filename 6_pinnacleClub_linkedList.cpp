/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of second, third and final year of department can be granted membership on request. 
Similarly one may cancel the membership of club. First node is reserved for president of club and 
last node is reserved for secretary of club. Write C++ program to maintain club member‘s 
information using singly linked list. Store student PRN and Name. Write functions to: 
    a) Add and delete the members as well as president or even secretary. 
    b) Compute total number of members of club 
    c) Display members 
    d) Two linked lists exists for two divisions. 
Concatenate two lists
*/


#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    string PRN;
    string name;
    Node* next;
    Node(string a, string b){
        PRN = a;
        name = b;
        next = NULL;
    };
};

void insertAtEnd(Node* &head,string a, string b){
    Node *n = new Node(a,b);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

int count(Node* &head){
    Node* temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteAtEnd(Node* &head,string a){
    Node* temp = head;
    while (temp->next->name != a)
    {
        temp=temp->next;
    }
    Node* todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

void insertAtHead(Node* &head,string a, string b){
    Node *n = new Node(a,b);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
}

void deletion(Node* &head,string a){
    
}

void display(Node* &head){
    if (head == NULL)
    {
        cout<<"No elements"<<endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->name<<"("<<temp->PRN<<")"<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(int argc, char const *argv[])
{
    int temp = 1,choice;
    string name1,PRN1;
    Node *head = NULL;
    while (temp)
    {
        cout<<"1.Insert at Head"<<endl
            <<"2.Insert at End"<<endl
            <<"3.Total Number of Members"<<endl
            <<"4.Display"<<endl
            <<"5.Deletion"<<endl
            <<"6.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:{
                cout<<"Name : ";
                cin>>name1;
                cout<<"PRN :";
                cin>>PRN1;
                insertAtHead(head,PRN1,name1);
                break;
            }
            case 2:{
                cout<<"Name : ";
                cin>>name1;
                cout<<"PRN :";
                cin>>PRN1;
                insertAtEnd(head,PRN1,name1);
                break;
            }
            case 3:{
                cout<<"Total number of members : "<<count(head)<<endl;
                break;
            }
            case 4:{
                display(head);
                break;
            }
            case 5:{
                string name2;
                cout<<"Enter the name :";
                cin>>name2;
                break;
            }
            case 6:{
                temp = 0;
            }
        }
    }
    return 0;
}
