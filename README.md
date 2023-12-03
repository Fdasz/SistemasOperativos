# SistemasOperativos
Tarea 2 Sistemas Operativos
# Version secuencial
De momento la version secuencial no funciona a través del comando make, si se intenta compilar no produce nada de salida.
Para hacer funcionar el codigo debe compilarse de manera directa utilizando el comando ./cambio en la terminal, esto ejecuta el cambio de colores a escala de grises y además muestra en terminal el tiempo de ejecucion.

# Version paralelo openMP
Esta version tampoco funciona a traves del comando make, tambien se debe ejecutar de manera directa con ./openmp, al ejecutar se pedira el nombre del archivo a transformar, y se debe introducir con el formato "nombre_de_archivo.formato_de_archivo"

Ej: imagen.jpg

luego el programa pedira la cantidad de hilos que se usaran para realizar la conversion de la imagen en el cual se debe introducir un numero entero, para luego pedir el nombre con el que quedara el archivo de la foto ya transformado el cual debe seguir el mismo formato que al momento de introducir una imagen, es decir, el nombre y el formato de la imagen. Una vez se terminen de introducir los datos esta mostrara el tiempo de ejecucion en segundos y se guardara el nuevo archivo en escala de grises.

# Version paralelo threads
Seguir las mismas instrucciones que la otra version paralelo, ya que es el mismo funcionamiento solo cambia el el metodo con el que se realiza
