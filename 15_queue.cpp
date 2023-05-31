/*
Queues are frequently used in computer programming, and a typical example is the creation of a 
job queue by an operating system. If the operating system does not use priorities, then the jobs 
are processed in the order they enter the system. Write C++ program for simulating job queue. 
Write functions to add job and delete job from queue.
*/


#include<iostream>
#include<string>
using namespace std;

#define MAX 10

class jqueue{
    public : 
    int f,r;
    string arr[MAX];
    jqueue(){
        f=-1;
        r=-1;
    }
    void insert(string a);
    void display();
    void deleteq();
};
void jqueue :: insert(string a){
    if (r == MAX - 1 || f>r)
    {
        cout<<"OverFlow"<<endl;
        return;
    }
    r++;
    arr[r] = a;
    if (f== -1)
    {
        f++;
    }
}
void jqueue :: display(){
    if (f==-1)
    {
        cout<<"Empty"<<endl;
    }
    cout<<endl<<"*****Jobs*****"<<endl;
    for (int i = f; i <= r; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void jqueue :: deleteq(){
    if (f==-1)
    {
        cout<<"UnderFlow"<<endl;
        return;
    }
    cout<<"Job deleted : "<<arr[f]<<endl;
    f++;
}

int main(int argc, char const *argv[])
{
    jqueue q1;
    bool temp = 1;
    int choice;
    while (temp)
    {
        cout<<"*************************************"<<endl
            <<"1.Add Job to Queue : "<<endl
            <<"2.Delete Job from Queue : "<<endl
            <<"3.Display the Job Queue : "<<endl
            <<"4.Exit"<<endl;
        cout<<" => ";
        cin>>choice;
        switch (choice)
        {
        case 1:{
            string a;
            cout<<"Enter the Job Title With no spaces : ";
            cin>>a;
            q1.insert(a);
            break;
        }
        case 2:{
            q1.deleteq();
            break;
        }
        case 3:{
            q1.display();
            break;
        }
        case 4:{
            temp = 0;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}