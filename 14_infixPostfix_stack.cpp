/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using 
stack based on given conditions: 
    1. Operands and operator, both must be single character. 
    2. Input Postfix expression must be in a desired format. 
    3. Only '+', '-', '*' and '/ ' operators are expected.
*/


#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

int evaluate(string postFix){
    stack<int> s1;
    for(int i =0; i < postFix.length(); i++){
        if (postFix[i] >= '0' && postFix[i] <= '9')
        {
            s1.push(postFix[i] - '0');
        }else{
            int a = s1.top();
            s1.pop();
            int b = s1.top();
            s1.pop();
            switch (postFix[i])
            {
            case '+':{
                s1.push(b+a);
                break;
            }
            case '-':{
                s1.push(b-a);
                break;
            }
            case '*':{
                s1.push(b*a);
                break;
            }
            case '/':{
                s1.push(b/a);
                break;
            }
            case '^':{
                s1.push(pow(b,a));
                break;
            }
            default:
                break;
            }
        }
    }
    return s1.top();
}

bool IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

// IsOperand() function is used to validate whether the character is operand.
bool IsOperand(char c)
{
    if (c >= 'A' && c <= 'Z') /* Define the character in between A to Z. If not, it returns False.*/
        return true;
    if (c >= 'a' && c <= 'z') // Define the character in between a to z. If not, it returns False. */
        return true;
    if (c >= '0' && c <= '9') // Define the character in between 0 to 9. If not, it returns False. */
        return true;
    return false;
}
// here, precedence() function is used to define the precedence to the operator.
int precedence(char op)
{
    if (op == '+' || op == '-') /* it defines the lowest precedence */
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^') /* exponent operator has the highest precedence */
        return 3;
    return 0;
}
/* The eqlOrhigher() function is used to check the higher or equal precedence of the two operators in infix expression. */
bool eqlOrhigher(char top_stack, char incoming)
{
    int p1 = precedence(top_stack);
    int p2 = precedence(incoming);
    if (p1 == p2)
    {
        if (incoming == '^')
            return false;
        return true;
    }
    return (p1 > p2 ? true : false);
}
string convert(string infix)
{
    stack<char> S;
    string postfix = "";
    char ch;

    S.push('(');
    infix += ')';

    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;
        else if (ch == '(')
            S.push(ch);
        else if (IsOperand(ch))
            postfix += ch;
        else if (IsOperator(ch))
        {
            while (!S.empty() && eqlOrhigher(S.top(), ch))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(ch);
        }
        else if (ch == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    return postfix;
}


int main(int argc, char const *argv[])
{
    string b;
    string post;
    cout<<"Enter : ";
    cin>>b;
    post = convert(b);
    cout<<"PostFix : "<<post<<endl;
    cout<<"Ans : "<<evaluate(post);
    return 0;
}