/*
Write a C++ program to search key element in array using linear search & binary search.
*/



#include <iostream>
using namespace std;

void getArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "=>";
        cin >> arr[i];
    }
}

void linearS(int a[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == key)
        {
            cout << "Found !!" << endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}

void binaryS(int a[], int start, int end, int key)
{
    int m = (start + end) / 2;
    if (start < end)
    {
        if (a[m] == key)
        {
            cout << "Found" << endl;
        }
        else if (a[m] > key)
        {
            binaryS(a, start, m - 1, key);
        }
        else
        {
            binaryS(a, m + 1, end, key);
        }
    }else{
        cout<<"Not Found"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    bool temp = 1;
    while (temp)
    {
        int choice;
        cout << "1.Linear Search" << endl
             << "2.Binary Search" << endl
             << "3.Exit" << endl;
        cout << "=>";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "****Linear Search****" << endl;
            int size, key;
            cout << "Enter the number of elements : ";
            cin >> size;
            int arr[size];
            getArray(arr, size);
            cout << "Enter the key : ";
            cin >> key;
            linearS(arr, size, key);
            break;
        }
        case 2:
        {
            cout << "****Binary Search****" << endl;
            int size, key;
            cout << "Enter the number of elements : ";
            cin >> size;
            int arr[size];
            getArray(arr, size);
            cout << "Enter the key : ";
            cin >> key;
            binaryS(arr,0,size,key);
            break;
        }
        case 3:
        {
            temp = 0;
            cout << "Thank You !!" << endl;
            break;
        }
        }
    }

    return 0;
}