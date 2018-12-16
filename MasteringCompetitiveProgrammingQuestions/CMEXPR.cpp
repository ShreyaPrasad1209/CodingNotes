//https://www.spoj.com/problems/CMEXPR/
#include<bits/stdc++.h>
using namespace std;
 
struct et { char value; et* left, *right; }; 

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
    return false;
}

int prec(char c)
{
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void inorder(et *t, et *parent = NULL)
{
    if(t)
    {
        bool flag = false;
        if (parent != NULL && t->left != NULL && t->right != NULL && 
            prec(parent->value) > prec(t->value))
            flag = true;

        if (flag) printf("(");
        inorder(t->left, t);
        printf("%c", t->value);
        inorder(t->right, t);
        if (flag) printf(")");
    }
}

et* newNode(int v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

et* constructTree(string postfix)
{ 
    stack<et *> st;
    et *t, *t1, *t2;
    for (int i=0; i<postfix.length(); i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else
        {
            t = newNode(postfix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->right = t1;
            t->left = t2;
            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}

string infixToPostfix(string s)
{
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) ns+=s[i];
        else if(s[i] == '(') st.push('(');
        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        else
        {
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    } 
    return ns;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string exp;
        cin >> exp;
        et* expTree = constructTree(infixToPostfix(exp));
        inorder(expTree);
        cout << endl;
    }
    return 0;
}