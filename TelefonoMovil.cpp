//Autor: Timothy Mendez  creo toda la clase de telefono movil
//todos los comentarios fueron echos por Ramon Alvarez

#include <string>
#include <iostream>

using namespace std;

//Esta es la clase de telefono movil que manejara todo referente a los datos de los telfonos

class TelefonoMovil
{

public:
	//estos son los constructores de los metodos
	//descripcion de cada metodo esta sobre la funcion 
	TelefonoMovil();
	TelefonoMovil(string ma, string mo, string p, string i);
	TelefonoMovil(string ma, string mo, double p, int i);
	// Getters y Setters de la clase TelefonoMovil
	//descripcion de cada metodo esta sobre la funcion
	string getMarca();
	void setMarca(string ma);
	string getModelo();
	void setModelo(string mo);
	double getPrecio();
	void setPrecio(double p);
	int getInventario();
	void setInventario(int i);

	// Return attributes para imprir todos los atributos
	//descripcion del metodo esta sobre la funcion del mismo
	string getAttributes();

private:
	//Atributos de la clase telefono movil 
	//los atributos tipo string son para la marca y el modelo 
	//el double es para el precio y el integer para inventario
	//estos sonprivados pra que solo mediante setters se cambie el valor ygetters para obtenerlas
	string marca, modelo;
	double precio;
	int inventario;
};

//este constructor crea un objeto generico en el arreglo 
TelefonoMovil::TelefonoMovil()
{
	marca = "Generico";
	modelo = "basico";
	precio = 50.00;
	inventario = 0;
}

//este constructor crea un objeto con todos los argumentos tipo string para hacer 
//los objetos mas facil de leer
TelefonoMovil::TelefonoMovil(string ma, string mo, string p, string i)
{
	marca = ma;
	modelo = mo;
	precio = stod(p);
	inventario = stoi(i);
}

//este constructor crea un objeto con la marca y el modelo tipo string, el precio 
//va ser tipo double y la cantidad en el inventario tipo integer 
TelefonoMovil::TelefonoMovil(string ma, string mo, double p, int i)
{
	marca = ma;
	modelo = mo;
	precio = p;
	inventario = i;
}

//este getter en la la marca del telefono movil 
string TelefonoMovil::getMarca()
{
	return this->marca;
}

//este setter tiene como argumento un string que va a dar el nombre que se le va a asignar a la marca
void TelefonoMovil::setMarca(string ma)
{
	this->marca = ma;
}

//este getter en la la modelo del telefono movil
string TelefonoMovil::getModelo()
{
	return this->modelo;
}

//el setter tiene como argumento un string que va a dar el modelo que se le va a asignar 
void TelefonoMovil::setModelo(string mo)
{
	this->modelo = mo;
}

//este getter en la la precio del telefono movil
double TelefonoMovil::getPrecio()
{
	return this->precio;
}

//el setter tiene como argumento un double que se le va a asignar a el precio del objecto 
void TelefonoMovil::setPrecio(double p)
{
	this->precio = p;
}
//este getter en la la inventario del telefono movil
int TelefonoMovil::getInventario()
{
	return this->inventario;
}

//el setter tiene como argumento un numero tipo integer que se le va a asignar a la cantidad del inventario del objeto 
void TelefonoMovil::setInventario(int i)
{
	this->inventario = i;
}

//este getter envia un string con los atributos de el objeto seleccionado
//tiene la marca con su modelo, precio e inventario. 
string TelefonoMovil::getAttributes() 
{

	string temp;
  
	temp = marca + "\n" + modelo + "\n" + to_string(precio) + "\n"  + to_string(inventario);

      return temp;
}
