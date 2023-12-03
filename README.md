# SistemasOperativos
Tarea 2 Sistemas Operativos
# Version secuencial
*De momento la version secuencial no funciona a través del comando make, si se intenta compilar no produce nada de salida, se adjunta archivo para su revisión por si acaso.

Para el correcto funcionamiento del codigo debe compilarse el archivo "cambio.cpp" con la siguiente linea de codigo: g++ -o cambio cambio.cpp `pkg-config --libs opencv`, luego es necesario ejecutarla de manera directa con ./cambio

Luego de esto se pregunta por el nombre de la imagen a la cual se le quieren cambiar los colores.

El formato para introducir la imagen es: "imagen.jpg", asegurandose que la imagen esté en la misma carpeta que el archivo del codigo.

# Version paralelo threads
Para esta versión al igual que la anterior no logramos hacer funcionar la función make, por tanto habrá que compilar desde la terminal el archivo "paralelo1.cpp" con la linea: g++ -o paralelo1 paralelo1.cpp `pkg-config --libs opencv` -pthread

Ya que se usa la clase threads esta vez es necesario agregarle la función pthread.

Luego de esto pregunta por el nombre de la imagen a la cual se le quieren cambiar los colores.

El formato para introducir la imagen es: "imagen.jpg", asegurandose que la imagen esté en la misma carpeta que el archivo del codigo.

Luego pide ingresar la cantidad de hilos que desea usar para la conversión, usar números enteros y no mayores a la cantidad que posee su equipo.

Finalmente pide ingresar nombre para la imagen de salida, ingresar nombre con extensión al final por ejemplo: "imagen_gris.jpg"

# Version paralelo openMP
Esta version tampoco funciona a traves del comando make, tambien se debe ejecutar de manera directa con ./openmp, al ejecutar se pedira el nombre del archivo a transformar, y se debe introducir con el formato "nombre_de_archivo.formato_de_archivo"

Ej: imagen.jpg

luego el programa pedira la cantidad de hilos que se usaran para realizar la conversion de la imagen en el cual se debe introducir un numero entero, para luego pedir el nombre con el que quedara el archivo de la foto ya transformado el cual debe seguir el mismo formato que al momento de introducir una imagen, es decir, el nombre y el formato de la imagen. Una vez se terminen de introducir los datos esta mostrara el tiempo de ejecucion en segundos y se guardara el nuevo archivo en escala de grises.

*Cabe destacar que para las versiones paralelas si se ingresa el mismo nombre para entrada y salida, esta reemplazará la imagen original por la conversión.
