# DS Algorithms - Others
## 1. Number Theory:
**<u>Bernauli Trial:</u>** A dice thrown n times and we want probability for 6 exactly x times. so: <sup>n</sup>C<sub>x</sub> (1/6)<sup>x</sup> (5/6)<sup>n - x</sup>

In a room of 23 peoples if all of them handshakes with everyone. <sup>22</sup>C<sub>2</sub> 22 because no one will handshake to himself.

Unsigned long long int can store max till 18 places so we can Big Integers in java for C++ we can use arrays.
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

void multiply(int* a, int& n, int num)
{
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int product = a[i] * num + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    while (carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void big_factorial(int number)
{
    int* a = new int[1000];
    a[0] = 1;
    int n = 1;
    for (int i = 2; i < number; i++)
        multiply(a, n, i);
    for (int i = n-1; i >= 0; i--)
        cout << a[i];
    cout << endl;
}
```

**<u>SEQUENCE FINDER</u>** https://oeis.org/

**<u>Catalan Numbers:</u> 1, 1, 2, 5, 14, 42**<br> Cat(n) = <sup>2n</sup>C<sub>n</sub>/(n+1) And Cat(0) = 1<br>
1) Number of possible BST with n keys
2) {a, b, c, d} can be parenthesized with Cat(4) ways: (ab)(cd), a(b(cd)), ((ab)c)d, (a(bc)(d)), a((bc)d)
3) A polygon with n + 2 sides can split into Cat(n + 2) triangles
4) No of ways to form mountain ranges with n upstrokes<br>
<br>![](res/mountain.png)<br>

**<u>Pigeonhole Principle:</u>**<br>
If there are (Kn + 1) pigeons and n pigeon holes then 1 pigeonhole will have 2 pigeons.

>**#1:** **Prove that if 6 ints are selected {3, 4, 5, 6, 7, 8, 9, 10, 11, 12} there must be 2 ints whose sum is 15.**<br>
3-12, 4-11, 5-10, 6-9, 7-8 These are pigeon holes.<br>
Now we wil select 6 ints from our list those 6 will be pigeons. So by two will lie on same group hence proved.

>**#2:** **Prove that if 10 points are placed in a 3x3 cm square then 2 points must be less than or equal to √2 cm apart.**

>**#3:** **At a buisness meeting no one shakes their own hand and no one shakes another person's hand more than once. Prove that there are 2 people who have shaken hands same number of times.**<br>
If there are n peoples then one person can have 0 handshakes or 1, 2... n-1 since no one shakes own hand. now if there's a person with n-1 handshakes (he has shaken hands with everyone) then a person with no handshake will not exist. So there will be n-1 total cases. They are pigeonholes. so two persons will have same number of handshakes.

Divisible Subset Problem (https://www.codechef.com/problems/DIVSUBS)<br>
Example: 3 4 3 5 2 3<br>
Naive approach is by exponential time finding pairs with 1 element only then 2 element only and so on.<br>
Any such problem can be illustrated as (1+x<sup>3</sup>)(1+x<sup>4</sup>)(1+x<sup>3</sup>)(1+x<sup>5</sup>)(1+x<sup>2</sup>)(1+x<sup>3</sup>) solving this will give terms having powers of all subsets we just need to apply % N = 0.<br>
It can be solved in O(NlogN) by Fast Fourier Transform or simply in O(N<sup>2</sup>)
```
Itterate all array elements and apply % N and record it in the array of vector below.
0   1   2   3   4   5
            0
Then 4
0   1   2   3   4   5
                1
Then in 4 to 3 so 4 + 3 % N
0   1   2   3   4   5
    0,1     0   1
and so on.

a[]     =      3    4    3    5    2    3
b[]     = 0    3    7    10   15   17   20
b[]     = 0    3    1    4    3    5    2
temp[]  =      2    6    1,4  3    5  
This is pigeonhole senerio in every case any temp arr will have two element. end - start i.e. 4 - 1 = 3 so 3 elements that are 2nd 3rd and 4th (4 + 3 + 5) % 6 = 0
```

**2 ) Find all prime factors:**<br>
If a number is divisible by 2 divide it by 2 and show 2. Then loop from <u>3 to √n</u> Since n is odd (n % 2 != 0 so we can skip an element i.e. <u>i+=2</u>). Last check is if n > 2 otherwise n can be 1 then we just show.<br>
Time: O(√n)<br>
A check till √n is sufficient because prime numbers lie in pairs (1, 100) (2, 50) (4, 25)...
```c++
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    if (n > 2)
        cout << n << " ";
}
```
Find all divisors of a number n from 1. We will itterate from 1 to n checking modulo O(n) a better way is see pattern.<br>
For 100: 1 2 4 5 10 20 25 50 100<br>
(1, 100) (2, 50) (4, 25) (5, 20) they form pairs with product n. Now O(√n).<br>
Proper divisors are all divisors except number itself.

Politeness of a number i.e. number of ways a number can be expressed as consecutive numbers sum.<br>
15 : 1 + 2 + 3 + 4 + 5, 4 + 5 + 6, 7 + 8 hence 3<br>
It is equivalent to number of all odd prime factors excluding 1. 15 : 1, 3, 5, 15 (so 3)

**3) Find All Prime Numbers**
Naive approach is to itterate from 2 to n and for each number call isPrime() this function will find all prime factors and see if it is more than 2 then true. Time: O(n√n)

Sieve Of Eratosthanese: Time: O(nloglogn)
```c++
void printPrimes(int n)
{
    int primes[n+1];
    fill(primes, primes + n + 1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i*2; j <= n; j+=i)
                primes[j] = 0;
        }
    }
}
```

**4) Prime Factorization using Sieve Of Erastosthanese O(logn)**

## 2. Bit Manipulation:
N = 6163<sub>10</sub> = (6×10<sup>3</sup>) + (1×10<sup>2</sup>) + (6×10<sup>1</sup>) + (3×10<sup>0</sup>)<br>
In base 2 (binary) instead of 10's power we represent in 2's power. To convert keep dividing number by two and append remainder to a string. In the end reverse the string.

AND = A.B<br>
OR = A + B<br>
NOT = 1 - A = !A<br>
XOR = A!B + !AB<br>

Moore's Law: <br>
!(A + B) = A!.B!<br>
!(A.B) = A! + B!

XNOR = !XOR = (A + B!).(A! + B)<br>
NOR = !OR = A!.B!<br>
NAND = !AND = A! + B!<br>

If XOR of two numbers/string/any data is 0 then both are same.

If between two number there's a bit difference of exactly one by XOR then it is called Gray Code. It is used in signal detection to check if there's any wrong signal.
<center>

| Type          | Size (bit)   | Range                              |
| ------------- |:-------------|:-----------------------------------|
| Bit           | 1            | 0 or 1                             |
| Nibble        | 4            | 0 to 2<sup>4</sup>-1               |
| Byte          | 8            | 0 to 2<sup>8</sup>-1               |
| Word          | 16           | 0 to 2<sup>16</sup>-1              |
| Double        | 32           | 0 to 2<sup>32</sup>-1              |
| Qword         | 64           | 0 to 2<sup>64</sup>-1              |

</center>

Gb (Gigabits), GB (Gigabytes), Gib (10<sup>3</sup> bits), GiB (10<sup>3</sup> bytes)

Hexadecimals: **0x<span style="color:blue">AA</span><span style="color:red">BB</span><span style="color:green">CC</span><span style="color:orange">DD</span>**<br>
Different colors represent a byte (AA 1 byte). Nibble has 4 bits i.e. 2<sup>4</sup> so a hexadecimal value which is from 0-15 (10 - A, B, C, D, E, F)

Least Significant Bit (LSB) & Most Significant Bit (MSB): 99 in binary (MSB part)01100011(LSB part) so in MSB 01100011 in LSB 11000110<br>
Endiness (Storing data in memory) : Little Endian (LSB), Big Endian (MSB)

Finding i<sup>th</sup> bit:<br>
```c++
X(1<<4) >> 4
output:
010x00
000100
000x00
x
```

2's Complement:<br>
-X = !X + 1<br>
X = !(-X-1)

<center>

| Decimal       | Binary       | Hexadecimal  | Decimal       | Binary       | Hexadecimal  |
| ------------- |:-------------|:-------------| :------------ |:-------------|:-------------|
| 0             | 0000         | 0x0          | 0             | 0000         | 0x9          |
| 1             | 0001         | 0x1          | -1            | 1111         | 0xA          |
| 2             | 0010         | 0x2          | -2            | 1110         | 0xB          |
| 3             | 0011         | 0x3          | -3            | 1101         | 0xC          |
| 4             | 0100         | 0x4          | -4            | 1011         | 0xD          |
| 5             | 0101         | 0x5          | -5            | 1011         | 0xE          |
| 6             | 0110         | 0x6          | -6            | 1010         | 0xF          |
| 7             | 0111         | 0x7          | -7            | 1001         | 0x7          |
| 8             | 1000         | 0x8          | -8            | 1000         | 0x8          |

1 in 8th first value means it's a negative number which is not true so range is -8 to 7 only
</center>

```c++
0000111110110011
// << 3 yields:
0111110110011000
// >> 3 yields:
0000000111110110

// Multiplication
i * 8; // normal
i << 3; // bitwise [8 = 2^3, so use 3]
 
// Division
i / 16; // normal
i >> 4; // bitwise [16 = 2^4, so use 4]
 
// Modulus
i % 4; // normal
i & 3; // bitwise [4 = 1 << 2, apply ((1 << 2) - 1), so use 3]
```
```c
/*
Booth's Multiplication Algo: (01011 x 01011)
   01011 x 1 =    01011
  010110 x 1 =   010110
 0101100 x 0 =  0000000
01011000 x 1 = 01011000
                1111001
*/

int mul(int a, int b)
{
    int ans = 0;
    for (int i = 0 ; i < 32; i++)
    {
        if (b & 1) ans += a;
        b = b>>1;
        a = a<<1;
    }
    return ans;
}
```