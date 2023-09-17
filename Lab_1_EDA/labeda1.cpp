#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    // Aqui usaremos una semilla para la generación de números aleatorios
    srand(time(nullptr));

    // Las dimensiones requeridad para hallar las distancias 
    std::vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};

    // ingresamos los puntos aleatorios, en este caso 100
    int num_points = 100;

    for (int dim : dimensions) {
        // Creamos un archivo txt para cada histograma donde se escribirán los datos obtenidos 
        std::ofstream dist_file("distances_" + std::to_string(dim) + ".txt");

        // En esta parte generamos los puntos aleatorios y hallamos las distancias 
        for (int i = 0; i < num_points; ++i) {
            for (int j = 0; j < num_points; ++j) {
                // Se generan coordenadas aleatorias en la Dimensión d
                std::vector<double> point1(dim);
                std::vector<double> point2(dim);

                for (int k = 0; k < dim; ++k) {
                    point1[k] = (double)rand() / RAND_MAX;
                    point2[k] = (double)rand() / RAND_MAX;
                }

                // Calcula la distancia euclidiana entre los puntos
                double distance = 0.0;
                for (int k = 0; k < dim; ++k) {
                    distance += (point1[k] - point2[k]) * (point1[k] - point2[k]);
                }
                distance = sqrt(distance);

                // Guardar la distancia en el archivo txt
                dist_file << distance << std::endl;
            }
        }

        // Cierra el archivo txt
        dist_file.close();
    }

    return 0;
}

//el output deberia ser 7 archivos txt con todas las dimensiones 
