#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>   

// Estructura para almacenar cada objeto junto con su ratio
struct Objeto {
    int id;
    int peso;
    int valor;
    double ratio; // valor / peso

    Objeto(int id, int p, int v) : id(id), peso(p), valor(v) {
        if (peso > 0) {
            ratio = (double)valor / peso;
        } 
        else {
            ratio = 0; // Manejar división por cero si el peso es 0
        }
    }
};

// Comparador para ordenar los objetos por su ratio (de mayor a menor).
bool compararObjetos(const Objeto& a, const Objeto& b) {
    return a.ratio > b.ratio;
}

double mochilaFraccional(int W, const std::vector<int>& w, const std::vector<int>& v) {
    int n = w.size();
    std::vector<Objeto> objetos;

    // 1. Calcular la relación valor/peso para cada objeto
    for (int i = 0; i < n; ++i) {
        objetos.push_back(Objeto(i, w[i], v[i]));
    }

    // 2. Ordenar los objetos por ratio (de mayor a menor)
    std::sort(objetos.begin(), objetos.end(), compararObjetos);

    double valorTotal = 0.0;
    int pesoActual = 0;

    std::cout << "\n--- Proceso de llenado de la mochila ---" << std::endl;

    // 3. Llenar la mochila
    for (int i = 0; i < n; ++i) {
        // Si la mochila ya está llena, salir del bucle
        if (pesoActual == W) {
            break;
        }

        // Opción A: El objeto cabe completamente
        if (pesoActual + objetos[i].peso <= W) {
            pesoActual += objetos[i].peso;
            valorTotal += objetos[i].valor;
            std::cout << "Tomando objeto " << objetos[i].id + 1 << " (Peso: " << objetos[i].peso << ", Valor: " << objetos[i].valor << ") [COMPLETO]" << std::endl;
        } 
        // Opción B: El objeto no cabe, se toma una fracción
        else {
            int pesoRestante = W - pesoActual;
            
            // Calcular la fracción del objeto que podemos tomar
            double fraccion = (double)pesoRestante / objetos[i].peso;
            
            // Se añade el valor de esa fracción
            valorTotal += objetos[i].valor * fraccion;
            
            // Marcar el peso actual como lleno
            pesoActual = W; 

            std::cout << "Tomando objeto " << objetos[i].id + 1 << " (Peso: " << pesoRestante << ", Valor: " << (objetos[i].valor * fraccion) << ") [FRACCION]" << std::endl;
        }
    }

    return valorTotal;
}

int main() {
    // Mismos datos del ejemplo anterior
    std::vector<int> valores = {60, 100, 120};
    std::vector<int> pesos = {10, 20, 30};
    int W = 50; // Capacidad máxima de la mochila

    std::cout << "Datos de los objetos:" << std::endl;
    std::cout << "Objeto 1: Peso = 10, Valor = 60  (Ratio: " << (60.0/10.0) << ")" << std::endl;
    std::cout << "Objeto 2: Peso = 20, Valor = 100 (Ratio: " << (100.0/20.0) << ")" << std::endl;
    std::cout << "Objeto 3: Peso = 30, Valor = 120 (Ratio: " << (120.0/30.0) << ")" << std::endl;
    std::cout << "Capacidad de la mochila: " << W << std::endl;

    std::cout << std::fixed << std::setprecision(2); // Formateo para mostrar dos decimales

    double valorMaximo = mochilaFraccional(W, pesos, valores); // Llamada a la función de mochila fraccional

    std::cout << "--------------------------------" << std::endl;
    std::cout << "El valor máximo que se puede robar es: " << valorMaximo << std::endl;

    // El resultado debería ser 240
    // Orden de ratios: Obj 1 (6.0), Obj 2 (5.0), Obj 3 (4.0)
    // 1. Tomar Obj 1 (Peso 10, Valor 60). Mochila: 10/50. Valor: 60.
    // 2. Tomar Obj 2 (Peso 20, Valor 100). Mochila: 30/50. Valor: 160.
    // 3. Tomar Obj 3 (Peso 30, no cabe). Quedan 20 de capacidad.
    //    Tomar 20/30 = 2/3 del Obj 3.
    //    Valor = (2/3) * 120 = 80.
    //    Mochila: 50/50. Valor: 160 + 80 = 240.
    
    return 0;
}