#include <iostream>
#include <fstream>
#include <array>
#include "TelefonoMovil.cpp"
using namespace std;

// Funcion utilizada para evaluar si la opcion escogida es valida
bool rangoCorrecto(int valor) {
	return 0 <= valor && valor <= 9;
}

// Function used to represent the Menu Section of the program
// Returns users choice
int menuSelection(int& option)
{
		cout << "1. Cargar datos de archivo\n"
			<< "2. Almacenar datos en archivo\n"
			<< "3. Valor de inventario\n"
			<< "4. Valor de inventario para marca modelo particular\n"
			<< "5. Mostrar cantidad disponible para marca-modelo particular\n"
			<< "6. Añadir a inventario\n"
			<< "7. Vender Telefono\n"
			<< "8. Mostrar inventario en orden alfabetico marca modelo\n"
			<< "0. Salir\n"
			<< endl;
		cout << "Escoja una opción ";

	do {
		cin >> option;

		if (!rangoCorrecto(option)) {
			cout << "La opción debe ser un numero entero entre 0 y 8" << endl;
		}

	} while (!rangoCorrecto(option));
	return option; //------------- Need to understand why we return option?
}

// Reads file, extracts data for variables, then creates a new phone and adds it to the array
void opcion1(string& fileName, ifstream& input, int& index, TelefonoMovil telefono[], bool& flag)
{

	// Temp values to facilitate Telefono creation
	string marca;
	string modelo;
	string precio;
	string inventario;
	cout << "Provea el numbre del archivo junto con su extension. \'.dat\'" << endl;
	cin >> fileName;
	input.open(fileName); // Metele Try-Catch para cuando el file no exista
	while (getline(input, marca))
	{
		getline(input, modelo);
		getline(input, precio);
		getline(input, inventario);
		telefono[index] = TelefonoMovil(marca, modelo, precio, inventario);
		index++;
	}
	flag = true; // Explain flag
	input.close();
}

// Writes telefono data into same file ase read (?) with data separated by space
void opcion2(string fileName, ofstream& output, int index, TelefonoMovil telefono[]) {
	output.open(fileName); // Wrong. Actualizar contenido en el mismo archivo
	for (int i = 0; i <= index; i++) {
		output << telefono[i].getMarca() << " " << telefono[i].getModelo()
			<< " " << telefono[i].getPrecio() << " " << telefono[i].getInventario() << endl;
	}
	output.close();
}

// Returns the value of the amount of phones in the inventory
double opcion3(int index, TelefonoMovil telefono[]) {
	double suma = 0;
	for (int i = 0; i <= index; i++) {
		suma = suma + telefono[i].getInventario() * telefono[i].getPrecio();
	}
	return suma;
}

//Busca el valor del inventario en una marca en particular
double opcion4(int& index, TelefonoMovil telefono[])
{
	double total = 0.0; 
	string marca,
		modelo;

	cout << "Ingrese la marca que busca";
	cin >> marca;
	cout << "Ingrese el modelo que busca";
	cin >> modelo;


	for (int i = 0; i <= index; i++) //Aqui nos vamos a mover por el arreglo 
	{

		if (!(marca.compare(telefono[i].getMarca()) && modelo.compare(telefono[i].getModelo()))) //Compara si lo que esta en ese indice es igual a lo que el usuario escribio
		{

			cout << telefono[i].getAttributes() << endl;
			total = telefono[i].getInventario() * telefono[i].getPrecio();
		
			cout << "El precio total del inventario del " + marca + " " + modelo + "es " << total << endl;
		}

	}
    return total;
}



int opcion5(int index, TelefonoMovil telefono[]) {
	// opcion5(index, telefono);
	string marcaBuscar;
	string modeloBuscar;
	int suma = 0;
	cout << "Por favor provee la Marca y el Modelo del telefono"
		<< " que desea buscar. Cada entrada separada por un pulso al \'enter\'." << endl;
	cin >> marcaBuscar;
	cin >> modeloBuscar;

	for (int i = 0; i <= index; i++) {
		if (telefono[index].getMarca().compare(marcaBuscar)
			&& telefono[index].getModelo().compare(modeloBuscar)) {
			suma++;
		}
	}
	cout << "La cantidad de " << marcaBuscar << " " << modeloBuscar << "es: " << endl;
	return suma;
}
//Pregunta por una marca, modelo de teléfono y cuántos se desean añadir al inventario.
//Si la marca y modelo ya existen entonces se añade a la cantidad previa. De lo contrario, pregunta por el precio.
//Se crea un objeto nuevo con estos valores para sus propiedadesy se añade al arreglo
TelefonoMovil opcion6(int& index, TelefonoMovil telefono[])
{
	string marca,
		temp,
		modelo;
	int inventario;
	double precio;

	cout << "Cual es la marca que desea anadir?";
	cin >> marca;
	cout << "Cual es el modelo que desea añadir?";
	cin >> modelo;
	cout << "Cuantos desea anadir?";
	cin >> inventario;

	for (int i = 0; i <= index; i++) // Para verficar si alguno de los elementos esta a la par con los datos ingresados
	{
		if (marca.compare(telefono[i].getMarca()) && modelo.compare(telefono[i].getModelo()))
		{
			telefono[i].setInventario(telefono[i].getInventario() + inventario);
			cout << "Se añadieron " << inventario << " al inventrario de " + marca + modelo;
			return telefono[i];
		}	// No utilice un Else porque si no, no verificaria el arreglo completo.
	}

	cout << "Ingrese el precio";
	cin >> precio;

	telefono[index] = TelefonoMovil(marca, modelo, precio, inventario);
	index++;
	cout << "Se añadieron " << inventario << " al inventrario de " + marca + modelo;
	return telefono[index];

}

//Indica los valores de las propiedades del dispositivo y resta uno a la cantidad en inventario.  
//Si el inventario está en 0 entonces indica queno hay unidades disponible
void opcion7(int& index, TelefonoMovil telefono[])
{


	cout << "Ingrese en que lugar en el arreglo se encuentra el dispositivo que busca: " << endl;
	cin >> index;
	cout << telefono[index].getAttributes() << endl; //Imprime las propiedades

	telefono[index].setInventario(telefono[index].getInventario() - 1);

	cout << "El inventario del dispositivo que escogio es: " << telefono[index].getInventario() << endl;

}


//La opcion 8 nos muestra primero en orden alfabetico de acuerdo a la marca,
//luego de acuerdo al modelo. enviamos como argumento el largo del arreglo y 
// y el arreglo de los telefonos y hacemos el sort con un bubble sort
//@Ramon A Alvarez
void opcion8(int& index, TelefonoMovil telefono[])
{
	//esta variable la utilizamos para guardar el objeto que vamos a mover
	//para no perderlo
	TelefonoMovil temp,
		          temp2;
	//estas variables son para poder comparar las marcas y los modelos
	//poniendolo en lower case
	string marcaInicial,
		   marcaProxima,
		   modeloInicial,
		   modeloProximo;

	//
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < index - 1- i; j++)
		{
			//ponenmos el string en el de la marcas que queremos comparar para poner en minusculas
			marcaInicial = telefono[j].getMarca();
			for_each(marcaInicial.begin(), marcaInicial.end(), [](char& c) {c = ::tolower(c);});
			marcaProxima = telefono[j+1].getMarca();
			for_each(marcaProxima.begin(), marcaProxima.end(), [](char& c) {c = ::tolower(c); });

			//ponenmos el string en el de la modelos que queremos comparar para poner en minusculas
            modeloInicial = telefono[j].getModelo();
			for_each(modeloInicial.begin(), modeloInicial.end(), [](char& c) {c = ::tolower(c); });
			modeloProximo = telefono[j + 1].getModelo();
			for_each(modeloProximo.begin(), modeloProximo.end(), [](char& c) {c = ::tolower(c); });
			
			// en este condicional hacemos la comparacion y cambiamos el orden de acuerdo al alfabeto
			if (marcaInicial.compare(marcaProxima) > 0)
			{
				temp = telefono[j];
				telefono[j] = telefono[j + 1];
				telefono[j + 1] = temp;
			}
			//este condicional si las marcas son iguales compara los modelos y los sortea en orden alfabetico
			else if (marcaInicial.compare(marcaProxima) == 0)
			{
				if (modeloInicial.compare(modeloProximo) > 0)
				{
					temp = telefono[j];
					telefono[j] = telefono[j + 1];
					telefono[j + 1] = temp;
				}
			}
		}
	}

	//imprime el arreglo de objetos de acuerdo a su ya en orden alfabetico 
	for (int i = 0; i < index; i++) {
		cout << telefono[i].getMarca() << " " << telefono[i].getModelo() << ": " << telefono[i].getInventario() << " \t|\t Precio: $" << telefono[i].getPrecio() << endl;
	}


}



int main()
{


	TelefonoMovil telefono[100];
	int index = 0; // Index used for telefono array
	int option; // used for menu
	bool flag = false; // Used to allow option 2. If option 1 was already accessed
	string fileName;
	ifstream input; // File to read from
	ofstream output; // File to write to

	
	do
	{
		menuSelection(option);
		switch (option)
		{
			// Preguntar al profe que hacer si el archivo no existe
		case 1: // Cargar datos
			opcion1(fileName, input, index, telefono, flag);
			break;

		case 2: // Almacenar datos
			if (!flag) cout << "Option 1 has not been used." << endl;
			else opcion2(fileName, output, index, telefono);
			break;

		case 3: // Suma de Inventario
			cout << opcion3(index, telefono) << endl;
			break;

		case 4: // Valor de Inventario para marca-modelo particular
			// Multiplica inventorio por precio de marca-modelo
			opcion4(index, telefono);
			break;

		case 5: //Mostrar cantidad disponible para marca-modelo particular
			cout << opcion5(index, telefono) << endl;
			break;

		case 6: // Añadir a Inventario
		  //  opcion6(index, telefono);
			break;

		case 7: // Vender telefono
			opcion7(index, telefono);
			break;

		case 8:
			opcion8(index, telefono);
			break;

		case 0:

			break;
		}
	} while (option != 0);

	return 0;
}