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
        str += temp.ch;
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

## 4. Number of substrings divisible by 6 in a string of integers


## INF. Big Integer Implementation