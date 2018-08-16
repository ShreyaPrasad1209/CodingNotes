#include <iostream>
#include <string.h>

using namespace std;

int counter = 0;

void fibonacci(int num, int* A)
{
    int j = 0;
    int i = 1;
    A[0] = 0;
    A[1] = 1;
    counter = 1;
    for (int x = 2; x <= num; x++)
    {
        counter++;
        int temp = j + i;
        j = i;
        i = temp;
        A[x] = i;
    }
}

int main()
{
    int num;
    cin >> num;
    int A[num + 1];
    memset(A, 0, sizeof(A));
    fibonacci(num, &A[0]);
    cout << "Fibonacci number sequence up to " << num << ":" << endl << A[0];
    for (int i = 1; i <= num; i++)
        cout << ", " << A[i];
    
    cout << endl << "Number of time the recursive function is called: " << counter;

    return 0;
}
