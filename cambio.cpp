#include <iostream>
#include <opencv2/opencv.hpp>
#include "tiempo.h"

using namespace cv;
using namespace std;

Mat  convertToGrayscale(const Mat& image) {
	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);
	return grayImage;
}

int main(){
	Mat image = imread("/home/u0_a187/Desktop/tarea2/imagenacolor.jpg", IMREAD_COLOR);
	if (image.empty()) {
		cout << "No se pudo cargar la imagen." << endl;
		return -1;
}

	cout << "Imagen cargada correctamente." << endl;
	//se inicia la meidicon de tiempo
	Tiempo_ejec medicion;

	medicion.iniciarMedicion();

	Mat grayScaleImage = convertToGrayscale(image);

	medicion.finalizarMedicion();

	cout << "Tiempo de ejecucion: " << medicion.obtenerDuracion() << "milliseconds" << std::endl;


	imshow("Grayscale image", grayScaleImage);
	waitKey(0);
	waitKey(5000);
	return 0;
}
