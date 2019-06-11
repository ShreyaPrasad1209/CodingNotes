# Greedy Algorithm
## 70. Bulbs
https://www.interviewbit.com/problems/bulbs/
```c++
int Solution::bulbs(vector<int> &A)
{
    int ans = 0;
    bool isFlipped = false;
    for (int i : A)
    {
        if ((i && isFlipped) || (!i && !isFlipped))
        {
            isFlipped = !isFlipped;
            ans++;
        }
    }
    return ans;
}
```

## 71. Distribute Candy
https://www.interviewbit.com/problems/distribute-candy/
```c++
int Solution::candy(vector<int> &ratings)
{
    vector<int> val(ratings.size(), 1);
    for (int i = 0; i < ratings.size(); ++i)
    {
        if (i == 0)
        {
            if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
        }
        else if (i == ratings.size()-1)
        {
            if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
        else
        {
            if (ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1])
                val[i] = max(val[i+1], val[i-1]) + 1;
            else if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
            else if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
    }
    for (int i = ratings.size()-1; i >= 0; --i)
    {
        if (i == 0)
        {
            if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
        }
        else if (i == ratings.size()-1)
        {
            if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
        else
        {
            if (ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1])
                val[i] = max(val[i+1], val[i-1]) + 1;
            else if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
            else if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
    }
    int ans = 0;
    for (int i : val) ans += i;
    return ans;
}
```

## 72. Gas Station
https://www.interviewbit.com/problems/gas-station/
```c++
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
{
    int fuel = 0, start_i = 0, sum = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        sum += (gas[i] - cost[i]);
        fuel += (gas[i] - cost[i]);
        if (fuel < 0) fuel = 0, start_i = i+1;
    }
    return (sum >= 0) ? start_i : -1;
}
```

# Dynamic Programming