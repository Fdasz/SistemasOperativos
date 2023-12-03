#ifndef tiempoh
#define tiempoh

#include <chrono>

class Tiempo_ejec{
public:
	void iniciarMedicion(){
		start = std::chrono::high_resolution_clock::now();
	}

	void finalizarMedicion(){
		stop = std::chrono::high_resolution_clock::now();
	}

	long obtenerDuracion(){
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		return duration.count();
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
};

#endif
