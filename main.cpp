#include <iostream>
#include "SocioClub.h"

template<class T>
class LDLLSE;

template<class T>
class nodo{
private:
    T data;
    nodo<T>* sig;
    nodo<T>* ant;
public:
    nodo():sig(nullptr), ant(nullptr){};
    T getData(){
        return data;
    }
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
private:
    nodo<T>* ancla;
public:
    LDLLSE(): ancla(nullptr){};
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(nodo<T>* pos, T elem);
    void elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(nodo<T>* pos, T elem){
    nodo<T>* aux=new nodo<T>;
    aux->data=elem;

    if(pos==nullptr){
        aux->ant=nullptr;
        aux->sig=ancla;
        if(ancla!=nullptr)
            ancla->ant=aux;
        ancla=aux;
    }else{
        aux->ant=pos;
        aux->sig=pos->sig;
        if(pos->sig!=nullptr)
            pos->sig->ant=aux;
        pos->sig=aux;
    }
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos){
    if(!vacia() || pos!=nullptr){
        if(pos->ant!=nullptr){
            pos->ant->sig=pos->sig;
        }
        if(pos->sig!=nullptr){
            pos->sig->ant=pos->ant;
        }
        if(pos==ancla)
            ancla=ancla->sig;

        delete pos;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia()){
        return ancla;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
        nodo<T>* aux=ancla;
        while(aux!=nullptr && aux->data!=elem){
            aux=aux->sig;
        }
        return aux;
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){

    }
    else{
        return pos->data;
    }
}


template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==nullptr){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux=ancla;
        while(aux!=nullptr){
            std::cout<<aux->data<<std::endl;
            aux=aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}

int main()
{
    int opc;
    LDLLSE<SocioClub> milista;
    SocioClub elem,X;
    std::string temp;
    do{
        system("cls");
        std::cout<<"\n\t***MENU DE OPCIONES***"<<std::endl<<std::endl;
        std::cout<<" 1. Registrar nuevo socio."<<std::endl;
        std::cout<<" 2. Dar de baja un socio."<<std::endl;
        std::cout<<" 3. Generar reporte de todos los socios."<<std::endl;
        std::cout<<" 4. Buscar socio."<<std::endl;
        std::cout<<" 5. Salir."<<std::endl;
        std::cout<<"Ingresa la opcion: ";
        std::cin>>opc;

        switch(opc){
            case 1: system("cls");
                    std::cout<<"\n\tIngrese los datos del nuevo socio: "<<std::endl;
                    std::cin>>X;
                    milista.inserta(milista.ultimo(),SocioClub(X));
                    std::cout<<"Socio agregado exitosamente!"<<std::endl<<std::endl;
                    system("pause");
                    break;

             case 2: system("cls");
                    if(!milista.vacia()){
                        std::cout<<"Ingresa los datos del socio que deseas eliminar: "<<std::endl;
                        std::cin>>elem;
                        milista.elimina(milista.localiza(elem));
                        std::cout<<"Socio eliminado correctamente!"<<std::endl;
                    }else{
                        std::cout<<"La lista esta vacia!"<<std::endl;
                    }
                    system("pause");
                    break;

            case 3: system("cls");
                    if(!milista.vacia()){
                        milista.imprime();
                    }else{
                        std::cout<<"La lista esta vacia!"<<std::endl;
                    }
                    system("pause");
                    break;

            case 4: system("cls");
                    if(!milista.vacia()){
                        std::cout<<"\n\tIngresa los datos a buscar"<<std::endl;
                        std::cout<<"Nombre: ";
                        std::cin>>temp;
                        elem.setNombre(temp);
                        std::cout<<"Domicilio: ";
                        std::cin>>temp;
                        elem.setDomicilio(temp);
                        if(!milista.localiza(elem)){
                            std::cout<<"Socio no encontrado!"<<std::endl;
                        }
                        else{
                            elem=milista.localiza(elem)->getData();
                            std::cout<<"\n\tSocio encontrado"<<elem<<std::endl;
                        }
                    }else{
                        std::cout<<"La lista esta vacia!"<<std::endl;
                    }
                    system("pause");
                    break;
        }
    }while(opc!=5);

    return 0;
}
