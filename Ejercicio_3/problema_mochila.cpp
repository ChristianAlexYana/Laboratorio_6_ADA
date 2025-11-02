#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>   


// Función auxiliar para imprimir la tabla de DP.
void printTable(const std::vector<std::vector<int>>& dp, int n, int W) {
    std::cout << "\n--- Tabla de Programación Dinámica (dp[i][j]) ---" << std::endl;
    std::cout << "i: objetos, j: capacidad" << std::endl;
    std::cout << std::setw(5) << "i\\j |";
    for (int j = 0; j <= W; ++j) {
        std::cout << std::setw(4) << j;
    }
    std::cout << "\n------";
    for (int j = 0; j <= W; ++j) {
        std::cout << "----";
    }
    std::cout << std::endl;
    for (int i = 0; i <= n; ++i) {
        std::cout << std::setw(5) << i << " |";
        for (int j = 0; j <= W; ++j) {
            std::cout << std::setw(4) << dp[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl;
}

int knapsack(int W, const std::vector<int>& w, const std::vector<int>& v) {
    int n = w.size(); // Número de objetos

    // dp[i][j] almacenará el valor máximo usando los primeros 'i' objetos
    // con una capacidad de peso máxima de 'j'.
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0)); // Creación de la tabla DP inicializada a 0

    // Llenado de la tabla DP iterativamente
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            
            // Los pesos y valores están en los índices i-1 del vector
            int pesoActual = w[i - 1];
            int valorActual = v[i - 1]; 

            // Opción 1: No incluir el objeto 'i'.
            int valorSinObjeto = dp[i - 1][j];

            if (pesoActual <= j) { // El objeto actual cabe en la mochila
                // Opción 2: Incluir el objeto 'i'.
                int valorConObjeto = valorActual + dp[i - 1][j - pesoActual]; // Valor si incluimos el objeto actual
                
                // Elegimos la mejor de las dos opciones
                dp[i][j] = std::max(valorConObjeto, valorSinObjeto);
            } 
            else {
                // El objeto actual no cabe, tomamos la Opción 1.
                dp[i][j] = valorSinObjeto;
            }
        }
    }

    printTable(dp, n, W);
    return dp[n][W]; // El valor máximo que se puede obtener con 'n' objetos y capacidad 'W'
}

int main() {
    // Ejemplo de uso
    std::vector<int> valores = {60, 100, 120};
    std::vector<int> pesos = {10, 20, 30};
    int W = 50; // Capacidad máxima de la mochila

    std::cout << "Datos de los objetos:" << std::endl;
    std::cout << "Objeto 1: Peso = 10, Valor = 60" << std::endl;
    std::cout << "Objeto 2: Peso = 20, Valor = 100" << std::endl;
    std::cout << "Objeto 3: Peso = 30, Valor = 120" << std::endl;
    std::cout << "Capacidad de la mochila: " << W << std::endl;

    int valorMaximo = knapsack(W, pesos, valores);

    std::cout << "El valor máximo que se puede robar es: " << valorMaximo << std::endl;
    
    return 0;
}