//Sergio Díaz

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int distmin = 111111111;
int matCosto[21][21];
int m, n;

struct Nodo {
	int acum;
	int id;
	int distPosible;
	bool bVisitados[21];
	vector <int> camino;
};

bool menor(const Nodo& N1, const Nodo& N2) {
	return N1.distPosible < N2.distPosible;
}

void Inicializa() {
	for(int i = 0; i < 21; i++) {
		for(int j = 0; j < 21; j++) {
			if (i == j) matCosto[i][j] = 0;
			else matCosto[i][j] = 111111111;
		}
	}
}

// calcular el mínimo valor posible de los nodos que tienen aún más de un vecino por visitar
int calcularDist(Nodo n1) {
	int dist = n1.acum;

	// calcular el mínimo valor posible del último nodo en el camino a todos los que faltan por visitar
	int minimo = 111111111;
	for (int i=0; i < n; i++) {
		if (!n1.bVisitados[i]) {
			minimo = min(minimo, matCosto[n1.camino[n1.camino.size() - 1]][i]);
		}
	}
	dist += minimo;

	// calcular el mínimo valor de cada uno de los no visitados hacia los demás no visitados y hacia el inicio del camino
	for (int i=0; i < n; i++) {
		minimo = 111111111;
		if (!n1.bVisitados[i]) {
			for (int j=0; j < n; j++) {
				if (j != i && j != n1.id && (!n1.bVisitados[j] || j == n1.camino[0])) {
					minimo = min(minimo, matCosto[i][j]);
				}
			}
			dist += minimo;
		}
	}

	return dist;
}

// calcular el costo de los nodos que ya tienen un ciclo hamiltoniano completo
int calcularCosto(Nodo n1) {
	int missing = 0;
	for (int i=0; i < n; i++) {
		if (n1.bVisitados[i] == false) missing = i;
	}
	int costo = 0;
	for (int i=0; i < n1.camino.size() - 1; i++) {
		costo += matCosto[n1.camino[i]][n1.camino[i+1]];
	}
	costo += matCosto[n1.camino[n1.camino.size()-1]][missing];
	costo += matCosto[missing][n1.camino[0]];
	return costo;
}

void print(Nodo n1) {
	cout << "ID: "<< n1.id << endl;
	cout << "Visitados: ";
	for (int i = 0; i < n;  i++) {
		cout << n1.bVisitados[i] << " ";
	}
	cout << endl;
	cout << "Camino: ";
	for (int i = 0; i < n1.camino.size();  i++) {
		cout << n1.camino[i];
		if (i != n1.camino.size()-1) cout << " -> ";
	}
	cout << endl;
	cout << "Distancia posible: " << n1.distPosible << endl;
	cout <<"Acumulado: " << n1.acum << endl << endl;
}

int main() {
	// crear la priority queue de los nodos, que los oredenará en base a la función "menor"
	priority_queue<Nodo, vector<Nodo>, function<bool(Nodo, Nodo)> > Fila(menor);
	int costo;
	char c1, c2;
	cin >> n >> m;

	// inicializa la matriz
	Inicializa();

	for(int i = 0; i < m; i++) {
		cin >> c1 >> c2 >> costo;
		matCosto[c1 - 'A'][c2 - 'A'] = costo;
		matCosto[c2 - 'A'][c1 - 'A'] = costo;
	}

	// crear el primer nodo #0 con sus atributos iniciales
	Nodo nodo1;
	nodo1.id = 0;
	nodo1.acum = 0;
	for (int i = 0; i < n; i++) {
		nodo1.bVisitados[i] = false;
	}
	nodo1.bVisitados[nodo1.id] = true;
	nodo1.camino.push_back(nodo1.id);
	nodo1.distPosible = calcularDist(nodo1);

//	print(nodo1);

	// insertar el primer nodo a la fila
	Fila.push(nodo1);

	// BFS
	while(!Fila.empty()) {
		Nodo temp = Fila.top();
		Fila.pop();

		// llamar a todos los vecinos del nodo 'temp' que no se han visitado
		for(int i = 0; i < n; i++) {
			if(!temp.bVisitados[i]) {
				// crear el nodo vecino en base a los atributos del nodo que lo llamó
				Nodo n2;
				n2.id = i;
				n2.acum = temp.acum + matCosto[temp.id][n2.id];
				for(int i = 0; i < n; i++) {
					n2.bVisitados[i] = temp.bVisitados[i];
				}
				n2.bVisitados[n2.id] = true;

				n2.camino = temp.camino;
				n2.camino.push_back(n2.id);

				// calcular cuántos vecinos no visitados faltan
				int porVisitar = 0;
				for (int i=0; i < n; i++) {
					if (!n2.bVisitados[i]) {
						porVisitar++;
					}
				}

				// si solo falta visitar un vecino, ya se puede deducir el resto del camino
				if (porVisitar == 1) {
					distmin = min(distmin, calcularCosto(n2));
				} else {
					n2.distPosible = calcularDist(n2);

					// si la distancia posible del nodo es mayor a la mínima, ya no se toma en cuenta
					if (n2.distPosible < distmin) {
//						print(n2);
						Fila.push(n2);
					}
				}
			}
		}
	}

	cout << distmin << endl;

	return 0;
}
