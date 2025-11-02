#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // valor grande para representar que no hay conexion

// funcion recursiva con memoizacion (programacion dinamica)
int minCostPath(int i, int j, const vector<vector<int>>& cost, vector<vector<int>>& dp) {
    if (i == j) return 0; // costo cero si origen y destino son iguales
    if (dp[i][j] != -1) return dp[i][j];

    int n = cost.size();
    int ans = INF;
    for (int k = i + 1; k < n; ++k) {
        if (cost[i][k] != INF) {
            int sub = minCostPath(k, j, cost, dp);
            if (sub != INF)
                ans = min(ans, cost[i][k] + sub);
        }
    }
    return dp[i][j] = ans;
}

int main() {
    srand(time(0)); // semilla para numeros aleatorios
    int n;
    cout << "ingrese el numero de estaciones: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    // generar matriz de costos aleatoria
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) cost[i][j] = 0; // costo cero de una estacion a si misma
            else {
                int r = rand() % 20; // numero aleatorio entre 0 y 19
                if (r < 3) cost[i][j] = INF; // 15% de probabilidad de que no haya conexion
                else cost[i][j] = 1 + rand() % 15; // costo aleatorio entre 1 y 15
            }
        }
    }

    // mostrar la matriz generada con indices de estaciones
    cout << "\nmatriz de costos generada (inf = sin conexion):\n\n   ";
    for (int j = 0; j < n; ++j) cout << "E" << j << "\t";
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << "E" << i << " ";
        for (int j = 0; j < n; ++j) {
            if (cost[i][j] == INF) cout << "INF\t";
            else cout << cost[i][j] << "\t";
        }
        cout << "\n";
    }

    // matriz dp para guardar costos minimos entre estaciones
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // calcular los costos minimos para todos los pares (i, j)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            minCostPath(i, j, cost, dp);

    // mostrar la matriz de costos minimos
    cout << "\nmatriz de costos minimos entre todas las estaciones:\n\n   ";
    for (int j = 0; j < n; ++j) cout << "E" << j << "\t";
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << "E" << i << " ";
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == INF || dp[i][j] == -1) cout << "INF\t";
            else cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }

    // mostrar el costo minimo desde 0 hasta n-1
    cout << "\ncosto minimo desde la estacion 0 hasta " << n - 1 << " es: ";
    if (dp[0][n - 1] == INF || dp[0][n - 1] == -1)
        cout << "no hay camino posible.\n";
    else
        cout << dp[0][n - 1] << endl;

    return 0;
}
