#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 500; 
    int b = 50; 

    cout << "Matriz: " << n << "x" << n << " Bloque: " << b << "x" << b << "\n";

    vector<vector<double>> A(n, vector<double>(n, 1.5));
    vector<vector<double>> B(n, vector<double>(n, 2.0));
    vector<vector<double>> C_clasica(n, vector<double>(n, 0.0));
    vector<vector<double>> C_bloques(n, vector<double>(n, 0.0));

    // Multiplicacion clasica (3 bucles)
    auto start_clasica = high_resolution_clock::now();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C_clasica[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    auto stop_clasica = high_resolution_clock::now();
    auto duracion_clasica = duration_cast<milliseconds>(stop_clasica - start_clasica);
    cout << "Clasica: " << duracion_clasica.count() << " ms\n";

    // Multiplicacion por bloques (6 bucles)
    auto start_bloques = high_resolution_clock::now();
    
    for (int ii = 0; ii < n; ii += b) {
        for (int jj = 0; jj < n; jj += b) {
            for (int kk = 0; kk < n; kk += b) {
                
                for (int i = ii; i < min(n, ii + b); i++) {
                    for (int j = jj; j < min(n, jj + b); j++) {
                        for (int k = kk; k < min(n, kk + b); k++) {
                            C_bloques[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
                
            }
        }
    }
    
    auto stop_bloques = high_resolution_clock::now();
    auto duracion_bloques = duration_cast<milliseconds>(stop_bloques - start_bloques);
    cout << "Bloques: " << duracion_bloques.count() << " ms\n";

    return 0;
}