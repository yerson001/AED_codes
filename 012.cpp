#include <iostream>
#include <stdlib.h>
using namespace std;

/*                Estructura de los nodos de la cola       
------------------------------------------------------------------------*/
struct nodo
{
    char dato;
    int priori;        // prioridad del nodo
    struct nodo *sgte;
};

/*                      Estructura de la cola      
------------------------------------------------------------------------*/
struct cola
{
    nodo *delante;
    nodo *atras  ;
};

/*                         Crear Nodo     
------------------------------------------------------------------------*/
struct nodo *crearNodo( char x, int pr)
{
    struct nodo *nuevoNodo = new(struct nodo);
    nuevoNodo->dato = x;
    nuevoNodo->priori = pr;
    return nuevoNodo;
    
};

/*                        Encolar cacarter con prioridad      
------------------------------------------------------------------------*/
void encolar( struct cola &q, char valor, int priori )
{
     
     struct nodo *aux = crearNodo(valor, priori);
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;

     q.atras = aux;        // puntero que siempre apunta al ultimo elemento 
}

/*                        Mostrar Cola       
------------------------------------------------------------------------*/
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
     
     cout << " Caracter  Prioridad " << endl;
     cout << " ------------------- " << endl;
          
     while( aux != NULL )
     {
            cout<<"    "<< aux->dato << "     |   " << aux->priori << endl;
            aux = aux->sgte;
     }    
}

/*         Ordenar  por prioridad( criterio de O. por Burbuja)    
------------------------------------------------------------------------*/
void ordenarPrioridad( struct cola &q )
{
     struct nodo *aux1, *aux2;
     int p_aux;
     char c_aux;
     
     aux1 = q.delante;
     
     while( aux1->sgte != NULL)
     {
            aux2 = aux1->sgte;
            
            while( aux2 != NULL)
            {
                   if( aux1->priori > aux2->priori )
                   {
                       p_aux = aux1->priori;
                       c_aux = aux1->dato;
                       
                       aux1->priori = aux2->priori;
                       aux1->dato   = aux2->dato;
                       
                       aux2->priori = p_aux;
                       aux2->dato   = c_aux;
                   }
                   
                   aux2 = aux2->sgte;
            }
            
            aux1 = aux1->sgte;
     }
}
/*                Inserta cacacteres en una cola     
------------------------------------------------------------------------*/
void insertar( struct cola &q, char c, int pr )
{
     /* Encolando caracteres */
     encolar( q, c, pr );
     
     /* Ordenando por prioridad */
     ordenarPrioridad( q ); 
}

/*                        Menu de opciones     
------------------------------------------------------------------------*/
void menu()
{
    cout<<"\n\t COLAS CON PRIORIDAD EN C++ \n\n";
    cout<<" 1. ENCOLAR                           "<<endl;
    cout<<" 2. MOSTRAR                           "<<endl;
    cout<<" 3. SALIR                             "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Principal        
------------------------------------------------------------------------*/
int main()
{
    struct cola q;
    
    q.delante = NULL;
    q.atras   = NULL;

    char c ;     // caracter a encolar
    int pr;      // prioridad del caracter
    int op;      // opcion del menu
    int x ;      // numero que devuelve la funcon pop
    
    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:

                 cout<< "\n Ingrese caracter: ";
                 cin>> c;
                 
                 cout<< "\n Ingrese prioridad: ";   
                 cin>> pr;
                 
                 insertar( q, c, pr );
                 
                 cout<<"\n\n\t\tCaracter '" << c << "' encolado...\n\n";
            break; 
                  
            case 2:

                 cout << "\n\n MOSTRANDO COLA DE PRIORIDAD\n\n";
                 
                 if(q.delante!=NULL)
                     muestraCola( q );
                 else   
                    cout<<"\n\n\tCola vacia...!"<<endl;
            break;
            
            default:
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                    system("pause");
                    exit(0);
         }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=3);
    
    return 0;
}