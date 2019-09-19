#include <string>
#include <iostream>

using namespace std;

class TelefonoMovil
{

public:
	//Constructores
	TelefonoMovil();
	TelefonoMovil(string ma, string mo, string p, string i);
	TelefonoMovil(string ma, string mo, double p, int i);
	// Getters y Setters
	string getMarca();
	void setMarca(string ma);
	string getModelo();
	void setModelo(string mo);
	double getPrecio();
	void setPrecio(double p);
	int getInventario();
	void setInventario(int i);

	// Return attributes
	string getAttributes();

private:
	//Propiedades
	string marca, modelo;
	double precio;
	int inventario;
};

TelefonoMovil::TelefonoMovil()
{
	marca = "Generica";
	modelo = "basico";
	precio = 50.00;
	inventario = 0;
}

TelefonoMovil::TelefonoMovil(string ma, string mo, string p, string i)
{
	marca = ma;
	modelo = mo;
	precio = stod(p);
	inventario = stoi(i);
}

TelefonoMovil::TelefonoMovil(string ma, string mo, double p, int i)
{
	marca = ma;
	modelo = mo;
	precio = p;
	inventario = i;
}

string TelefonoMovil::getMarca()
{
	return this->marca;
}

void TelefonoMovil::setMarca(string ma)
{
	this->marca = ma;
}

string TelefonoMovil::getModelo()
{
	return this->modelo;
}

void TelefonoMovil::setModelo(string mo)
{
	this->modelo = mo;
}

double TelefonoMovil::getPrecio()
{
	return this->precio;
}

void TelefonoMovil::setPrecio(double p)
{
	this->precio = p;
}

int TelefonoMovil::getInventario()
{
	return this->inventario;
}

void TelefonoMovil::setInventario(int i)
{
	this->inventario = i;
}


string TelefonoMovil::getAttributes() 
{

	string temp; // precio
  
	temp = marca + "\n";

      return temp;
}