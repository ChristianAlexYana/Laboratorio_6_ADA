#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    if (n < 0) {
        cout << "Error: la posicion no puede ser negativa." << endl;
        return -1;
    }

    if (n <= 1) {
        return n;
    }

    vector<int> tabla(n + 1);
    tabla[0] = 0;
    tabla[1] = 1;

    for (int i = 2; i <= n; i++) {
        tabla[i] = tabla[i - 1] + tabla[i - 2];
    }

    return tabla[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci de la posicion " << n << " es: " << fibonacci(n) << endl;
    return 0;
}
