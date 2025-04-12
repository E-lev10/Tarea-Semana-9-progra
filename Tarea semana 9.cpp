// Tarea semana 9.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Pilas Estáticas

#include <iostream> // Se incluye la biblioteca para realizar operaciones de entrada y salida (cout, cin, etc.)

using namespace std; // Se usa el espacio de nombres estándar para evitar escribir std:: antes de cout, endl, etc.

// Definición de la clase PilaEstatica
class PilaEstatica {
private:
	static const int MAX = 10; // Tamaño máximo de la pila (capacidad fija de 10 elementos)
	int arr[MAX]; // Arreglo que almacena los elementos de la pila
	int top; // Índice del último elemento insertado en la pila

public:
	// Constructor: inicializa la pila vacía con top en -1
	PilaEstatica() : top(-1) {}

	// Método para insertar (empujar) un valor en la pila
	bool push(int valor) {
		if (top >= MAX - 1) { // Verifica si la pila está llena
			cout << "Pila esta llena (overflow). " << endl; // Muestra mensaje de error si hay desbordamiento
			return false; // Retorna falso indicando que no se pudo insertar
		}
		arr[++top] = valor; // Incrementa top y luego inserta el valor en esa posición
		return true; // Retorna verdadero indicando que se insertó con éxito
	}

	// Método para eliminar (sacar) el valor de la cima de la pila
	int pop() {
		if (top < 0) { // Verifica si la pila está vacía
			cout << "Pila esta vacia (underflow). " << endl; // Muestra mensaje de error si hay subdesbordamiento
			return -1; // Retorna un valor de error
		}
		return arr[top--]; // Devuelve el valor en la cima y luego decrementa top
	}

	// Método para ver el valor en la cima de la pila sin eliminarlo
	int peek() const {
		if (top < 0) { // Verifica si la pila está vacía
			cout << "Pila vacia. " << endl; // Muestra mensaje si no hay elementos
			return -1; // Retorna un valor de error
		}
		return arr[top]; // Retorna el valor en la cima
	}
};

// Función principal del programa
int main() {
	PilaEstatica pila; // Se crea un objeto de tipo PilaEstatica

	pila.push(100); // Inserta 100 en la pila
	pila.push(200); // Inserta 200 en la pila
	pila.push(300); // Inserta 300 en la pila

	cout << "Elemento de la cima: " << pila.peek() << endl; // Muestra el elemento en la cima (300)
	cout << "Elemento eliminado: " << pila.pop() << endl; // Elimina y muestra el elemento en la cima (300)
	cout << "Elemento eliminado; " << pila.pop() << endl; // Elimina y muestra el siguiente elemento (200)

	return 0; // Fin del programa
}

