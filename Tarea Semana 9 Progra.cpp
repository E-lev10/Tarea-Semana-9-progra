#include <iostream>
using namespace std;
struct Nodo {  //Definición de la estructura Nodo que forma la base de la pila
	int dato;  //Almacena el valor del elemento en la pila
	Nodo* siguiente;  // Puntero al siguiente nodo en la pila

};
class PilaDinamica { //Clase que implemenenta una pila usando memoria dinámica
private: //Indica que es de calase privada, que solo pocos tienen acceso a ello
	Nodo* cima; //Apunta al nodo en la cima de la pila

public: //Contrario a la privada, es una clase publica, casi todos tiene acceso a ella
	// Constructor - inicializa una pila vacía
	PilaDinamica() :cima(nullptr) {}  //Esto nos indica que no hay nodos inicialmente

	~PilaDinamica() {  // Destructor - libera toda la memoria de los nodos al destruir la pila
		while (cima != nullptr) {  // Funciona mientras queden nodos
			pop(); //Esto nos ayuda a eliminar nodos uno por uno
		}
	}

	void push(int valor) { // Método para insertar un elemento en la cima de la pila llamado "push"
		Nodo* nuevo = new Nodo;  //Crea un nuevo nodo
		nuevo->dato = valor;  //Asigna el valor al nodo
		nuevo->siguiente = cima; //El nuevo nodo apunta a la antigua cima
		cima = nuevo;            //Actualiza la cima a este nuevo nodo
	}

	int pop() {  // Método para eliminar y devolver el elemento de la cima llamada "pop"
		if (cima == nullptr) {  //Encargada de verifica si la pila está vacía
			cout << "Pila vacia (underflow)." << endl; //Tira este mensaje en caso de pila vacia
			return -1; //Retorna el valor de error

		}
		Nodo* temp = cima;  //Esto guarda referencia al nodo a eliminar
		int valor = temp->dato;  //Guarda el valor antes de eliminar
		cima = cima->siguiente; //La nueva cima es el siguiente nodo
		delete temp;            //Libera la memoria del nodo removido
		return valor;  //Devuelve el valor guardado
	}

	//Método para observar el elemento en la cima sin eliminarlo (peek/top)
	int peek()const {  //El const nos indica que no modifica la pila
		if (cima == nullptr) { //Verifica si la pila está vacía
			cout << "Pila vacia." << endl; //Mensaje en caso de que la pila este vacia
			return -1; //Retorna valor de error
		}
		return cima->dato;  //Devuelve el dato en la cima
	}
};

//Este int main es la función principal para demostrar el uso de la pila
int main() {
	PilaDinamica pila;  //Crea una instancia para la pila
	pila.push(100);  //Inserta 100 en la pila
	pila.push(200);  //Insertar 200 en la pila
	pila.push(300);  //Insertar 300 en la pila
	cout << "Elemento en la cima:" << pila.peek() << endl; //Debería mostrar 300
	cout << "Elemento eliminado:" << pila.pop() << endl; //Debería mostrar 300
	cout << "Elemento eliminado:" << pila.pop() << endl; //Debería mostrar 200
	return 0; //Returna un valor de 0 XD
}