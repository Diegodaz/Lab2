#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int MAX = 2000; 

    cout << MAX << "x" << MAX << "\n";

    vector<vector<double>> A(MAX, vector<double>(MAX, 1.0));
    vector<double> x(MAX, 2.0);
    vector<double> y1(MAX, 0.0);
    vector<double> y2(MAX, 0.0);

    // Primer par de bucles (Filas)
    auto start1 = high_resolution_clock::now();
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y1[i] += A[i][j] * x[j];
        }
    }
    
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Filas: " << duration1.count() << " ms\n";

    // Segundo par de bucles (Columnas)
    auto start2 = high_resolution_clock::now();
    
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y2[i] += A[i][j] * x[j];
        }
    }
    
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Columnas: " << duration2.count() << " ms\n";

    return 0;
}