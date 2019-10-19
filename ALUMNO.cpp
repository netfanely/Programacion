/* LISTA LINEAL SIMPLE EN C++  
Los alumnos de la  FISC son registrados en una lista lineal simple y 
se pide que implemente la operación de eliminar un alumno según su ubicación en la lista.
SOLUCIÓN */

#include <iostream>
#include <conio.h>
#include "stdio.h"
#include <string>
using namespace std;

class ALUMNO{
  int codigo;
  char nombre[100];
  public:
    ALUMNO(){ }
    void IngAlumno(){
       cout<<"\n Ing codigo: ";cin>>codigo;
       cout<<"\n Ing nombre: ";cin>>nombre;     
    }  
    void MosAlumno(){
      cout<<"\n "<<codigo<<"    "<<nombre;   
    }       
};

class LISTAALUMNO{
    ALUMNO a;
    LISTAALUMNO *sgte,*raiz;
  public:
    LISTAALUMNO(){ raiz=NULL; }
    void IngLista(ALUMNO x){
         LISTAALUMNO *n=new LISTAALUMNO;
         n->a=x;
         if(raiz==NULL){ raiz=n; n->sgte=NULL; }
         else {
              n->sgte=raiz;
              raiz=n;
         } 
    }
    void VisLista(){
       LISTAALUMNO *q=raiz;
       while(q!=NULL){
         q->a.MosAlumno();
         q=q->sgte;               
         }             
    }  
    bool EliminarPorPosicion(int posicion){
       LISTAALUMNO *r,*q=raiz;
       bool RETORNAR =false;
       int i=0;
       while(!(q == NULL) && (!RETORNAR)){
          if(posicion == i){
            if(raiz==q){
               q=q->sgte;
               delete raiz;
               raiz=q;
            }
            else {
               r->sgte=q->sgte;
               delete q;
            }
            RETORNAR =true;
          }
         else{
            r=q;
            q=q->sgte;
            i++;
         }
      }
      return RETORNAR;
    }
};
 int main(int argc, char *argv[]){
  char op;
  ALUMNO a;  int posicion;
  LISTAALUMNO list; 
  for(;;){
     cout<<"\n Ingresar <1>\n Mosrar <2>\n Eliminar <3>\n Salir <4>";
     op=getch();
     switch(op){
     case '1':a.IngAlumno();
              list.IngLista(a);
              break;
     case '2':list.VisLista();break;
     case '3':cout<<"\n Ingrese posicion de alumno a eliminar: ";cin>>posicion;
              if(list.EliminarPorPosicion(posicion)) cout<<"\n Se elimino alumno";
              else cout<<"\n no se elimino alumno";
              getch();
              break;
     case '4':return 0;
     }
  }
}
