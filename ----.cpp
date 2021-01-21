#include <climits> //INT_MIN
#include <algorithm>
#include <map>
#include <numeric>
#include <bitset>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <sstream>
#include <list>
#include <queue>
#include<stack>
#include<numeric>
#include<utility> //pairs
#include<iomanip>
#include <random>
using namespace std;

const int MAX = 9;
int k;
int Heapsort[MAX];
// Arbol Parcialmente ordendo	
struct cola {
	int dato[MAX];
	int ult;
};
template<class T>
class heap{
public:
    void heapSort(vector<nodo<T>*> arr, int n){ 
        for (int i = n / 2 - 1; i >= 0; i--){
            heapify(arr, n, i); //cout<<"N: "<<i<<endl;
        }
        for (int i=n-1; i>=0; i--) { 
            swap(arr[0]->valor, arr[i]->valor); 
            heapify(arr, i, 0); 
        } 
    }
    void heapify(vector<nodo<T>*> arr, int n, int i) { 

        
        int largest = i; // Initialize largest as root 
        int l = 2*i + 1; // left = 2*i + 1 
        int r = 2*i + 2; // right = 2*i + 2  
        if (l < n && arr[l]->valor < arr[largest]->valor) 
            largest = l; 
        if (r < n && arr[r]->valor < arr[largest]->valor) 
            largest = r; 
        if (largest != i){ 
            swap(arr[i]->valor, arr[largest]->valor); 
            heapify(arr, n, largest); 
            } 
            for(int io=0; io<list.size(); io++)
                cout<<list[io]->valor<<" ";
            cout<<endl;
        } 
};
class HeapSort {
public:

    void heapSort(vector<int> &v, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(v, n, i);
        }
        cout << "Arun : ";
        for (auto &i : v)
            cout << i << " ";
        for (int i = n - 1; i >= 0; i--) {
            swap(v[0], v[i]);
            heapify(v, i, 0);
        }

    }
private:
    static void heapify(vector<int> &v, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && v[left] > v[largest]) largest = left;
        if (right < n && v[right] > v[largest]) largest = right;
        if (largest != i) {
            swap(v[i], v[largest]);
            heapify(v, n, largest);
        }
    }
/*
 for (auto &i : v)
        cout << i << " ";*/
};

cola Crea(cola A) {
	// Inicializamos la estructura de datos   
	int k;
	A.ult = 0;
	for (k = 0; k < MAX; k++)
		A.dato[k] = 0;
	return A;
};


cola Inserta(int x, cola A) {
	//Inserta un elemento al arbol y lo ordena de menor a mayor 
	int i, temp;
	if (A.ult >= MAX)
		printf("\nLa cola esta llena. \n");
	else {
		A.ult = A.ult + 1;
		A.dato[A.ult] = x;
		i = A.ult;

		while ((i > 1) && (A.dato[i] < A.dato[i / 2])) {
			temp = A.dato[i];
			A.dato[i] = A.dato[i / 2];
			A.dato[i / 2] = temp;
			i = i / 2;
		}
		return A;
	}
	return A;
};

/*

using namespace std;

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
void mostrar(nodo<T> *a,int x,int y){
	if(a!=nullptr){
		gotoxy(x,y);
		cout<<a->valor<<" "<<endl;
		x = x-2;
		y = y+3;
		mostrar(a->hijo[0],x-2,y);
		x = x+8;
		mostrar(a->hijo[1],x+2,y);
		y = y-3;
	}
}
void print(nodo<T>*root,int indent){
	if(root!=nullptr){
		if(root->hijo[1])print(root->hijo[1],indent+4);
			if(indent){
				for(int i=0; i<indent; i++)cout<<" ";
			}
		if(root->hijo[1]){
			cout<<"/"<<endl;
			for(int i=0; i<indent; i++) cout<<" ";
		}
	cout<<root->valor<<endl;
	if(root->hijo[0]){
		for(int i =0; i<indent; i++)cout<<" ";
			cout<<"\\"<<endl;
			print(root->hijo[0],indent+4);
		}
	}
}
*/

void Ver(cola A) {
	// Imprime el contenido del arbol

	int i;

	for (i = 0; i < MAX; i++)
		printf(" A[%d]= %d \n", i, A.dato[i]);
	printf("\n A.ult = %d ", A.ult);
	printf("\n\n");
}


cola Empuja(cola A, int primero, int ultimo) {
	// Reestable la propiedad del arbol parcialmente ordenado hundiendo el dato infractor a donde corresponde 
	int r, aux;
	r = primero;
	while (r <= (ultimo / 2)) {
		if (ultimo == 2 * r) {
			if (A.dato[r] > A.dato[2 * r]) {
				aux = A.dato[r];
				A.dato[r] = A.dato[2 * r];
				A.dato[2 * r] = aux;
				r = ultimo;
			}
			else
				r = ultimo;
		}
		else
			if (A.dato[r] > A.dato[2 * r] && A.dato[2 * r] <= A.dato[2 * r + 1]) {
				aux = A.dato[r];
				A.dato[r] = A.dato[2 * r];
				A.dato[2 * r] = aux;
				r = 2 * r;
			}
			else if (A.dato[r] > A.dato[2 * r + 1] && A.dato[2 * r + 1] < A.dato[2 * r]) {
				aux = A.dato[r];
				A.dato[r] = A.dato[2 * r + 1];
				A.dato[2 * r + 1] = aux;
				r = 2 * r + 1;
			}
			else
				r = ultimo;
	}
	return A;
}
/*
	void llenar(){
		int n,valor_=0,priori;
		cout<<"num nodo: ";cin>>n;
		for(int i=0; i<n; i++){
			cout<<"nodo: "<<i<<endl;
			//cout<<" valor: ";cin>>valor_;
			cout<<" prior: ";cin>>priori;
			nodo<T>*neo = new nodo<T>(valor_,priori);
			arr.push_back(neo);
		}

*/
int main()
{
	printf("\n\n");
	cola Arbol;
	// Inicializamos la estructura 
	Arbol = Crea(Arbol);
	//Asignamos valores entre 1 y 1000 a la esctructura y la mostramos.  
	int arr[] = { 8,3,1,6,4,7,10,14,13 };
	srand(clock());
	for (k = 0; k < MAX - 1; k++)
		Arbol = Inserta(arr[k], Arbol);
	// Vemos el resultado 
	Ver(Arbol);



	// Heapsort    

	for (k = 0; k < Arbol.ult; k++) {
		Heapsort[k] = Arbol.dato[1];         // Alamcenamos el dato que resulta ser el de menor valor entre todos.
		Arbol.dato[1] = Arbol.dato[Arbol.ult - k]; // Reemplazamos la raiz por la hoja mas a la izquierda del ultimo nivel quebrando la propiedad de los arboles parcialmente ordenados
		Arbol.dato[Arbol.ult - k] = 0;
		Arbol = Empuja(Arbol, 1, Arbol.ult - k - 1);  // Restablecemos la propiedad del arbol parcialmente ordenado.
	}

	printf("  El orden es el siguiente: \n\n ");
	for (k = 0; k < Arbol.ult; k++)
		printf(" %d", Heapsort[k]);

	printf("\n\n");
	printf("\n\n");
	system("pause");
	return 0;
}