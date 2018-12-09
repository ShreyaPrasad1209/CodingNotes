# Strings
## 1. Rearrange characters in a string such that no two adjacent are same - Amazon
```c++
Struct Key
{
    int freq;
    char ch;
    bool operator< (const Key& _key) const { return freq < _key.freq; }
};
int main()
{
    string str;
    cin >> str;
    unordered_map<char, int> frequency;
    for (int i = 0; i < str.size(); ++i) ++frequency[str[i]];

    priority_queue<Key> prioQue;
    for (auto it:frequency) prioQue.push(Key {it.second, it.first});

    string res = "";
    Key prev {-1, '0'};
    while(!prioQue.empty())
    {
        Key temp = prioQue.top();
        prioQue.pop();
        res += temp.ch;
        if (prev.freq > 0) prioQue.push(prev);
        --(temp.frq);
        prev = temp;
    }
    if (res != str.length) cout << "Invalid!" << endl;
    else cout << res << endl;
    return 0;
}
```

## 2. Find One Extra Character In a String
Str1 = "abcd" & Str2 = "cbdae" ans = e<br>
**Way 1:** Using hashmap <u>O(N) O(N)</u><br>
**Way 2:** Using Bitwise <u>O(N) O(1)</u>: Traverse one string then other keep XORing in the end it's the ans.

## 3. Minimum sum of squares of character counts in a given string after removing k characters - Amazon
str = abccc, K = 1<br>
we will remove c to get: 1<sup>2</sup> + 1<sup>2</sup> + 2<sup>2</sup> = 6 as the value<br>
It's a clear observation, that we should remove max frequency element.<br>
**Way 1:** Using sorting <u>O(NlogN)</u><br>
**Way 2:** Using Prioirity Queue <u>O(N)</u><br> Add every frequency to the priority queue.

## 5. Find next smallest palindrom (greater then given number) - Amazon, Microsoft

## 6. Find the smallest window in a string containing all characters of another string
```
Input :  string = "this is a test string"
         pattern = "tist"
Output :  Minimum window is "t stri"
Explanation: "t stri" contains all the characters
              of pattern.
```

## INF. Big Integer Implementation

```c++  
/*
A number 5189 is stored in res[] as following.
res[] = {9, 8, 1, 5}
x = 10

Initialize carry = 0;

i = 0, prod = res[0]*x + carry = 9*10 + 0 = 90.
res[0] = 0, carry = 9

i = 1, prod = res[1]*x + carry = 8*10 + 9 = 89
res[1] = 9, carry = 8

i = 2, prod = res[2]*x + carry = 1*10 + 8 = 18
res[2] = 8, carry = 1

i = 3, prod = res[3]*x + carry = 5*10 + 1 = 51
res[3] = 1, carry = 5

res[4] = carry = 5

res[] = {0, 9, 8, 1, 5} 
*/

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  
        carry  = prod/10;    
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
void factorial(int n)
{
    int res[500];   //500 is MAXSIZE
    res[0] = 1;
    int res_size = 1;
    for (int x=2; x<=n; x++) res_size = multiply(x, res, res_size);
    for (int i=res_size-1; i>=0; i--) cout << res[i];
    cout << endl;
}
```

```c++
bool isStr1Smaller(string str1, string str2) 
{
    int n1 = str1.length(), n2 = str2.length();
    if (n1 < n2) return true;
    if (n2 > n1) return false;
    for (int i=0; i<n1; i++)
    {
        if (str1[i] < str2[i]) return true;
        else if (str1[i] > str2[i]) return false;
    }
    return false;
}

string bigSum(string str1, string str2) 
{
    if (str1.length() > str2.length()) swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
    int carry = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry) str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}

string bigDiff(string str1, string str2)
{
    if (isStr1Smaller(str1, str2)) swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;
    int carry = 0;
    for (int i=n2-1; i>=0; i--)
    {
        int sub = ((str1[i+diff]-'0') - (str2[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub+10;
            carry = 1;
        }
        else carry = 0;
        str.push_back(sub + '0');
    }
    for (int i=n1-n2-1; i>=0; i--)
    {
        if (str1[i]=='0' && carry)
        {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i]-'0') - carry);
        if (i>0 || sub>0) str.push_back(sub+'0');
        carry = 0;
    }
    reverse(str.begin(), str.end());
    return str;
}

string bigMultiply(string num1, string num2) 
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0) return "0";
    vector<int> result(n1 + n2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=n2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0) result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1) return "0";
    string s = "";
    while (i >= 0) s += std::to_string(result[i--]);
    return s;
}

string bigDivision(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) 
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0) return "0";
    return ans;
}
```