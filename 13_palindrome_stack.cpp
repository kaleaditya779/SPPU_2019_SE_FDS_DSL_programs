/*
A palindrome is a string of character that‘s the same forward and backward. Typically, 
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a 
palindrome, as can be seen by examining the characters “poor danisina droop” and observing that 
they are the same forward and backward. One way to check for a palindrome is to reverse the 
characters in the string and then compare with them the original-in a palindrome, the sequence 
will be identical. Write C++ program with functionsa) To print original string followed by 
reversed string using stack b) To check whether given string is palindrome or not.
*/



#include<iostream>
#include<stack>
using namespace std;

void convertString(char str[], char str1[]){
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str1[j++] = str[i];
        }
        
    }
    str1[j] = '\0';
}

int main()
{
    char str[50],str1[50];
    stack<char> s1;
    cout<<"Enter the string : ";
    cin.getline(str,50);
    cout<<str<<endl;
    convertString(str,str1);
    cout<<str1<<endl;
	int count = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        s1.push(str1[i]);
		count++;
    }
    int flag = 1;
	int i = 0;
    while (!s1.empty())
    {
		cout<<i<<endl;
        if (str1[i] != s1.top())
        {
            flag = 0;
            break;
        }else
		{
			s1.pop();
		}
		i++;
    }
    if (flag == 0)
    {
        cout<<"Not palin"<<endl;
    }else{
        cout<<"Palin"<<endl;
    }
    
    
    return 0;
}