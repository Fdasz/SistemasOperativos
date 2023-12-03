#include <iostream>
#include <opencv2/opencv.hpp>
#include "tiempo.h"
#include <thread>
#include <vector>

using namespace cv;
using namespace std;

//se usa funcion para utilizar metodo de luminosidad en la imagen
void convertToGrayscaleSection(Mat& image, int start_row, int end_row) {
	for (int i = start_row; i < end_row; ++i) {
		for (int j = 0; j < image.cols; ++j) {
			Vec3b pixel = image.at<Vec3b>(i, j);
			uchar gray = 0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0];
			image.at<Vec3b>(i, j) = Vec3b(gray, gray, gray);
		}
	}
}
//se utiliza la clase threads para la conversion
void grayscaleWithThreads(Mat& image, int numThreads) {
	vector<thread> threads;
	int rows_per_thread = image.rows / numThreads;
	int start_row = 0;

	for (int i = 0; i < numThreads; ++i) {
		int end_row = (i == numThreads - 1) ? image.rows : start_row + rows_per_thread;
		threads.emplace_back(convertToGrayscaleSection, ref(image), start_row, end_row);
		start_row = end_row;
	}

	for (auto& t : threads) {
		t.join();
	}
}

int main() {
	//se lee la imagen a convertir por consola
	string originalImagePath, grayscaleImagePath;
	cout << "Ingrese el nombre del archivo de imagen original: ";
	cin >> originalImagePath;

	Mat originalImage = imread(originalImagePath, IMREAD_COLOR);

	int numThreads;
	//se lee la cantidad de hilos a usar
	cout << "Ingrese la cantidad de hilos: ";
	cin >> numThreads;

	Mat grayscaleImage = originalImage.clone();
	//inicia la medicion de tiempo de ejecucion
	Tiempo_ejec medicion;
	medicion.iniciarMedicion();

	grayscaleWithThreads(grayscaleImage, numThreads);
	medicion.finalizarMedicion();
	//muestra el tiempo de ejecucion
	cout << "Tiempo de ejecucion: " << medicion.obtenerDuracion() << " milisegundos" << endl;
	//solicita el nombre del archivo de salida 
	cout << "Ingrese el nombre del archivo de imagen en escala de grises: ";
	cin >> grayscaleImagePath;

	imwrite(grayscaleImagePath, grayscaleImage);

	return 0;
}
