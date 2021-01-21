/*algoritmo de simular crear curva de nivel */
#include<iostream>
using namespace std;
#define COLUMNAS 8
#define FILAS 8
char matriz[FILAS][COLUMNAS];

void llenar(){
    int i,j;
    for( i = 0; i < FILAS; i++){
        for(j = 0; j < COLUMNAS; j++){
                matriz[i][j]='-';
            }
       }
    }
void print(){
    int i,j;
    cout << "[x] 0  1  2  3  4  5  6  7  " << endl;
    for( i = 0; i < FILAS; i++){
        cout <<" "<<i<<" ";
        for(j = 0; j < COLUMNAS; j++){
                cout<<" "<<matriz[i][j]<<" ";
            }
            cout<<endl;
        }
        cout << endl;
    }
void insert(){// candidato para el paralelismo
    int x,y;
    cout<<"x: ";cin>>x;
    cout<<"y: ";cin>>y;
    for(int i=x-1; i<x+2;i++){
        for(int j=y-1; j<y+2; j++){
            if(i==x && j==y){
                matriz[i][j]='0';
            }
            else if(matriz[i][j]!='0'){//error en las posicines en x y=0
                matriz[i][j]='1';
            }
        }
    }
}
int main(){
    int opcion;llenar();
    do{
    print();
    cout<<"INSERT[1] PRINT[2] SALIR[3]"<<endl;
    cout<<"OPCION: ";cin>>opcion;
    if(opcion==1){
        insert();
        system("cls");
    }
    else if(opcion ==2){
        print();
         }
    }while(opcion!=3);
    
    return 0;
}