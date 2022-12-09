#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>

//BRIAN ALEJANDRO VIANA CLAVIJO --

using namespace std;

void llenarNodo(vector<int> *vec, int tam){
    if(vec->size()==0){
        vec->push_back(-1);
        vec->push_back(tam);
    }else{
        vec->push_back(tam);
    }
}
void llenarNodoAle(vector<int> *vec){
    int tam =rand()%100;
    if(vec->size()==0){
        vec->push_back(-1);
        vec->push_back(tam);
    }else{
        vec->push_back(tam);
    }
}
void DescenderMax(vector<int> *vec, int tam){
    int aux,PR,HI,HD;
    int r;
    if(tam>((vec->size()-1)/2)||vec->size()-1<=2){
        return;
    }else{
        PR = vec-> at(tam);
        HI = vec-> at(2*tam);
        HD = vec-> at((2*tam)+1);
        r = tam;
        if(HI>PR&&HI>HD){
        aux= vec -> at(2*tam);
        vec->at(2*tam) = vec->at(tam);
        vec->at(tam)=aux;
        tam =2*r;
        }else if(HD>PR&&HD>HI) {
            aux= vec -> at((2*tam)+1);
            vec->at((2*tam)+1) = vec->at(tam);
            vec->at(tam)=aux;
            tam =(2*r)+1;
        }
        DescenderMax(vec,tam);
    }
}
void EliminarNodo(vector<int> *vec, int num){
    vector<int>::iterator ite;
    bool b=true;
    int i;
    for(ite=vec->begin()+1,i=1;ite!=vec->end();ite++,i++){
        if((*ite)==num){
            vec->erase(ite);
            vec->insert(vec->begin()+i,vec->back());
            vec->pop_back();
            DescenderMax(vec,i);
            cout <<"NUMERO "<<num<<" ELIMINADO "<< endl;
            b=false;
        }
    }
    if(b==true){
        cout <<"NUMERO "<<num<<" NO ENCONTRADO"<< endl;
    }
}
void AscenderMax(vector<int> *vec, int tam){
    int r, aux;
    r = tam/2;
    if(r==0){
        return;
    }else{
      if(vec->at(tam)>vec->at(r)){
        aux= vec -> at(tam/2);
        vec->at(tam/2) = vec->at(tam);
        vec->at(tam)=aux;
        tam =tam/2;
        AscenderMax(vec,tam);
      }
    }
}

int main()
{
    setlocale(LC_CTYPE,"spanish");
    int opcion, opc, n;
    vector<int> arbol;
    srand(time(0));
  do
    {
        cout<<"\n  ||ARBOL BALANCEADO||MONTICULO MAXIMO||";
        cout<<"\n  ||\t   1. AGREGAR VALOR           ||";
        cout<<"\n  ||\t   2. MOSTRAR ARBOL           ||";
        cout<<"\n  ||\t   3. ELIMINAR VALR           ||";
        cout<<"\n  ||\t   4. SALIR                   ||";
        cout<<"\n  ||ARBOL BALANCEADO||MONTICULO MAXIMO||";
        cout<<"\n\n   OPCIÓN: ";
        cin>>opcion;

       switch (opcion){
            case 1:
                {
                 cout<<( "\n |AGREGAR VALOR|\n");
                 do{
                   cout<< "\n   1. A ELECCIÓN";
                   cout<< "\n   2. ALEATORIO";
                   cout<< "\n   3. REGRESAR";
                   cout<< "\n\n   opción: ";
                   cin>>(opc);
                   switch(opc){
                        case 1:
                            cout<<"\n  A ELECCION:\n";
                            cout<<( "\n AGREGAR UN VALOR ENTERO: ");
                            cin>>n;
                            llenarNodo(&arbol, n);
                            AscenderMax(&arbol, arbol.size()-1);
                            cout<<"\n VALOR AGREGADO\n";
                        break;
                        case 2:
                            cout<<"\n  ALEATORIO\n";
                            llenarNodoAle(&arbol);
                            AscenderMax(&arbol, arbol.size()-1);
                            cout<<"\n VALOR AGREGADO\n";
                        break;
                        case 3:
                        break;
                        default: cout<<"INVALIDO\n\n";
                      }
                   }while(opc!=3);
                }
            break;
            case 2:
                {
                 cout<<( "\n  |MOSTAR ARBOL|\n");
                 int nivel=1;
                 int pos, potencia;
                 potencia=pow(2,nivel);
                 cout<<"Nivel "<<nivel<<endl;
                 for(pos=1;pos<arbol.size();pos++){
                    cout<<"Nodo "<<pos<<": "<<arbol[pos]<<" ";
                    if(pos==potencia-1){
                     nivel++;
                     cout<<"\nNivel "<<nivel<<endl;
                     potencia=pow(2,nivel);
                     }
                   }
                }
            break;
            case 3:
                {
                 cout<<( "\n  |ELIMINAR VALOR|\n");
                 cout<<( "\n ELIMINAR UN VALOR ENTERO: ");
                 cin>>n;
                 EliminarNodo(&arbol, n);
                 cout<<( "\n  |ELIMINADO|\n");

                }
            break;
            case 4:
            break;
           default: cout<<( "\nINVALIDO\n");
         }

   }while(opcion!=4);
    return 0;
}
