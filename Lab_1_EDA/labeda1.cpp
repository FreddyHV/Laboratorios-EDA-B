#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    // Semilla para la generación de números aleatorios
    srand(time(nullptr));

    // Dimensiones de los conjuntos de datos
    std::vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};

    // Número de puntos aleatorios
    int num_points = 100;

    for (int dim : dimensions) {
        // Crear y abrir un archivo para guardar las distancias
        std::ofstream dist_file("distances_" + std::to_string(dim) + ".txt");

        // Generar puntos aleatorios y calcular distancias
        for (int i = 0; i < num_points; ++i) {
            for (int j = 0; j < num_points; ++j) {
                // Generar coordenadas aleatorias en la dimensión d
                std::vector<double> point1(dim);
                std::vector<double> point2(dim);

                for (int k = 0; k < dim; ++k) {
                    point1[k] = (double)rand() / RAND_MAX;
                    point2[k] = (double)rand() / RAND_MAX;
                }

                // Calcular la distancia euclidiana entre los puntos
                double distance = 0.0;
                for (int k = 0; k < dim; ++k) {
                    distance += (point1[k] - point2[k]) * (point1[k] - point2[k]);
                }
                distance = sqrt(distance);

                // Guardar la distancia en el archivo
                dist_file << distance << std::endl;
            }
        }

        // Cerrar el archivo
        dist_file.close();
    }

    return 0;
}


