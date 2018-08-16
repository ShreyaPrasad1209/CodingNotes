//Stack implementation
//Push (Insert at the entry of stack), Pop (Remove from entery) & Top (Gets entry element)
//All stack operations are performed in constant time
//Applications: Undo operation, paranthesis are balanced by compiler using stack

//Queue is where last in and front out happens
//Used in case where requests are sent like to a printer for print requests
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Reversing()
{
    stack<char> words;
    string word;
    getline(cin, word);
    for(int i=0; i<word.size(); i++)
        words.push(word[i]);

    int n = words.size();
    for(int i = 0; i < n; i++)
    {
        cout << words.top();
        words.pop();
    }
    cout << endl;
}

void BalancingParanthesis()
{
    string expression;
    getline(cin, expression);
    stack<int> paranthesis;
    for(int i = 0; i < expression.size(); i++)
    {
        switch (expression[i])
        {
            case '(':
                paranthesis.push(0);
                break;
            case '{':
                paranthesis.push(1);
                break;
            case '[':
                paranthesis.push(2);
                break;
            case ')':
            {
                if (paranthesis.top() == 0)
                    paranthesis.pop();
                else
                {
                    cout << "Not Balanced!" << endl;
                    return;
                }
                break;
            }
            case '}':
            {
                if (paranthesis.top() == 1)
                    paranthesis.pop();
                else
                {
                    cout << "Not Balanced!" << endl;
                    return;
                }
                break;
            }
            case ']':
            {
                if (paranthesis.top() == 2)
                    paranthesis.pop();
                else
                {
                    cout << "Not Balanced!" << endl;
                    return;
                }
                break;
            }
        }
    }

    cout << "Balanced!" << endl;
}

//BODMAS
int getOperatorRank(char oper)
{
    switch(oper)
    {
        case '+':
            return 2;
        case '-':
            return 1;
        case '*':
            return 3;
        case '/':
            return 4;
    }
}

char getOperatorChar(int rank)
{
    switch(rank)
    {
        case 2:
            return '+';
        case 1:
            return '-';
        case 3:
            return '*';
        case 4:
            return '/';
    }
}

void PostfixToCalculation()
{
    //Infix notation
    //Operand-Operator-Operand
    //A+B or A+B*C
    //Prefix notation
    //Operator-Operand-Operand
    //+AB or +A*BC
    //Postfix notation
    //AB+ or ABC*+
    //These notation helps in parsing algebric expressions

    //example: A * B + C + D - E = {(A * B) + (C * D)} - E
    //{(AB*) + (CD+)} - E = {(AB*)(CD*)+} - E = {(AB*)(CD*)+}E- = AB*CD*+E-
    string problem;
    string expression = "";
    stack<int> operStack;
    getline(cin, problem);
    for(int i=0; i<problem.size(); i++)
    {
        char oper = problem[i];
        if(oper == '+' || oper == '-' || oper == '*' || oper == '/')
        {
            expression.erase(expression.find_last_not_of(" ") + 1);
            int stackVal = getOperatorRank(oper);
            while (!operStack.empty())
            {
                if(operStack.top() >= stackVal)
                {
                    expression = expression + " " + getOperatorChar(operStack.top());
                    operStack.pop();
                }
                else
                    break;
            }
            operStack.push(stackVal);
        }
        else
            expression = expression + oper;
    }

    while (!operStack.empty())
    {
        expression = expression + " " + getOperatorChar(operStack.top());
        operStack.pop();
    }

    //Code to exaluate postfix notation
    stack<int> valStack;    
    string tempVal = "";
    for(int i = 0; i < expression.size(); i++)
    {
        char oper = expression[i];
        int a, b = 0;
        if(oper == '+' || oper == '-' || oper == '*' || oper == '/')
        {
            a = valStack.top();
            valStack.pop();
            b = valStack.top();
            valStack.pop();

            switch(oper)
            {
                case '+':
                    valStack.push(b + a);
                    break;
                case '-':
                    valStack.push(b - a);
                    break;
                case '*':
                    valStack.push(b * a);
                    break;
                case '/':
                    valStack.push(b / a);
                    break;
            }
        }
        else if (oper == ' ')
        {
            try
            {
                valStack.push(stoi(tempVal));
                tempVal = "";
            }
            catch (...) { }
        }
        else
            tempVal += expression[i];
    }

    cout << valStack.top() << endl;
}

int main()
{
    Reversing();
    BalancingParanthesis();
    PostfixToCalculation();
    
    return 0;
}