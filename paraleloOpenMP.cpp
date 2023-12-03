#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

// Función para convertir una imagen a escala de grises (versión paralela con OpenMP)
void grayscaleParallelOpenMP(Mat& image, int numThreads) {
    #pragma omp parallel for num_threads(numThreads)
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            Vec3b pixel = image.at<Vec3b>(i, j);
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            image.at<Vec3b>(i, j) = Vec3b(gray, gray, gray);
        }
    }
}

int main() {
    string originalImagePath, grayscaleImagePath;

    cout << "Ingrese el nombre del archivo de imagen original: ";
    cin >> originalImagePath;

    Mat originalImage = imread(originalImagePath, IMREAD_COLOR);

    int numThreads;
    cout << "Ingrese la cantidad de hilos: ";
    cin >> numThreads;

    // Clonar la imagen original antes de la conversión a escala de grises
    Mat grayscaleImage = originalImage.clone();

    // Medición de tiempo
    auto start = high_resolution_clock::now();

    // Versión paralela con OpenMP
    grayscaleParallelOpenMP(grayscaleImage, numThreads);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;

    cout << "Ingrese el nombre del archivo de imagen en escala de grises: ";
    cin >> grayscaleImagePath;

    imwrite(grayscaleImagePath, grayscaleImage);

    return 0;
}

