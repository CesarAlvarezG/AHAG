#ifndef _Cadenas_h
#define _Cadenas_h

enum Orden{Min_Max,Max_Min};

template <class T> int indice(T *cadena,T &elemento,int &n);
                                /*Funcion encargada de encontrar el indice un
                                elemento en una cadena*/

template <class T> int agregar(T *cadena,T &elemento,int &n);
                                /*Funcion encargada de ingresar un elemento a
                                una cadena retorna el indice en el cual queda
                                el elemento*/

template <class T> int quitar(T *cadena,T &elemento,int &n);
                                /*Funcion encargada de retirar un elemento de
                                una cadena retorna el indice al cual pertenecia
                                el elemento*/

template <class T> int agregar(T *cadena,T &elemento,int &n,int ind);
                                /*Funcion encargada de ingresar un elemento
                                en la posicion inidica por el ultimo argumento
                                a una cadena retorna el indice en el cual queda
                                el elemento*/

template <class T> int quitar(T *cadena,T &elemento,int &n,int ind);
                                /*Funcion encargada de retirar un elemento
                                en la posicion inidica por el ultimo argumento
                                a una cadena retorna el indice en el cual queda
                                el elemento*/

template <class T> void permutar(T &a,T &b);
                                /*Funcion encargada de permutar dos elementos*/

template <class T> void ordenar(T *cadena,Orden orden,int n,int i);
                                /*Funcion encargada de ordenar una cadena desde
                                el elemento i hasta el elemento n*/

#endif 
