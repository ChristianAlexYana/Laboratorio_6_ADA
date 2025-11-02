#include <iostream>
#include <vector>
using namespace std;

int escalones(int n) {
    if (n < 0) {
        cout << "No se puede subir escalones negativos" << endl;
        return -1;
    }
    if (n == 0) {
        return 0;
    }

    vector<int> tabla(n + 1);
    tabla[0] = 1; // ya está en la cima
    if (n >= 1) tabla[1] = 1;
    if (n >= 2) tabla[2] = 2;

    for (int i = 3; i <= n; i++) {
        tabla[i] = tabla[i - 1] + tabla[i - 2] + tabla[i - 3];
    }

    return tabla[n];
}

int main() {
    int n = 5;
    cout << "Numero de formas de subir " << n << " escalones: " << escalones(n) << endl;
    return 0;
}