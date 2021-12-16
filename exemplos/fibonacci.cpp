#include <iostream>

using std::cout; using std::cin;
using std::endl; using std::string;

void generateFibonacci(unsigned long long n)
{
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long c;

    cout << a << " " << b;

    for (unsigned long long i = 3; i <= n; i++)
    {
        c = a + b;
        cout << " " << c;
        a = b;
        b = c;
    }
}

int main()
{
    unsigned long long num;

    cout << "Enter the number of items to generate Fibonacci series: ";
    cin >> num;

    generateFibonacci(num);

    return EXIT_SUCCESS;
}
