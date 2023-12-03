#include <iostream>
#include <opencv2/opencv.hpp>
#include "tiempo.h"

using namespace cv;
using namespace std;

//se crea una funcion utilizando el metodo de luminosidad
Mat cambiarGrises(const Mat& image) {
	Mat result = image.clone();

	for (int y = 0; y < result.rows; ++y) {
		for (int x = 0; x < result.cols; ++x) {
			Vec3b color = result.at<Vec3b>(y, x);
			float luminosity = 0.3 * color[2] + 0.59 * color[1] + 0.11 * color[0];

			color[0] = color[1] = color[2] = static_cast<uchar>(luminosity);
			result.at<Vec3b>(y, x) = color;
		}
	}

	return result;
}


int main(){
	//se crea la variable para leer la imagen a cambiar
	string imgOriginal;
	cout << "Ingrese nombre de la imagen original: ";
	cin >> imgOriginal;
	//se lee la imagen
	Mat image = imread(imgOriginal, IMREAD_COLOR);

	cout << "Imagen cargada correctamente." << endl;
	//se inicia la meidicon de tiempo
	Tiempo_ejec medicion;

	medicion.iniciarMedicion();

	Mat resultImage = cambiarGrises(image);

	medicion.finalizarMedicion();
	//se muestra por consola el tiempo de ejecucion
	cout << "Tiempo de ejecucion: " << medicion.obtenerDuracion() << "milliseconds" << std::endl;

	//se muestra la imagen en gris
	imshow("Imagen en escala de grises", resultImage);
	waitKey(0);
	waitKey(5000);
	return 0;
}
