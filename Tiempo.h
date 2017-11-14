#ifndef _Tiempo_h
#define _Tiempo_h

#include<iostream.h>
#include <string.h>
#include <String>
#include "Bits.h"

enum  eHora{hr00,hr01,hr02,hr03,hr04,hr05,hr06,hr07,hr08,hr09,hr10,hr11,hr12,
hr13,hr14,hr15,hr16,hr17,hr18,hr19,hr20,hr21,hr22,hr23};

enum eDia{dDomingo,dLunes,dMartes,dMiercoles,dJueves,dViernes,dSabado};

class THora
{
 private:
         eHora Hora;
         int Acarreo;
 public:
        //Constructores
        THora();//Contructor por defecto
        THora(THora &a);//Constructor de copia
        //Destructor
        ~THora();
        //Funciones Set
        void Set_Acarreo(int);
        void Set_Hora(eHora);
        //Funciones Get
        char Get_Acarreo(void);
        eHora Get_Hora(void);
        int ToInt(void);
        //Funciones String
        char* to_str(void);
        //Sobrecarga de los operadores
        friend int operator==(const THora&,const THora&);
        friend int operator!=(const THora&,const THora&);
        friend int operator<(const THora&,const THora&);
        friend int operator>(const THora&,const THora&);
        friend int operator<=(const THora&,const THora&);
        friend int operator>=(const THora&,const THora&);
        friend THora operator+(const THora&,const THora&);
        friend THora operator+(const THora&,const int&);
        friend THora operator+(const int&,const THora&);
        friend THora operator+(const THora&,const eHora&);
        friend THora operator+(const eHora&,const THora&);
        friend THora operator-(const THora&,const THora&);
        friend THora operator-(const THora&,const int&);
        friend THora operator-(const int&,const THora&);
        friend THora operator-(const THora&,const eHora&);
        friend THora operator-(const eHora&,const THora&);
        THora& operator=(const eHora&);
        THora& operator=(const int&);
        THora& operator=(const THora&);
        friend ostream& operator<< (ostream&,const THora&);
        friend istream& operator>> (istream&,THora&);
        THora& operator++ (int j);
        THora& operator-- (int j);
        friend int Hamming(const THora&,const THora&);
        friend void random(THora&);
};

//------------------------------------------------------------------------------

class TDia
{
 private:
         eDia Dia;
         int Acarreo;
 public:
        //Constructores
        TDia();//Contructor por defecto
        TDia(TDia &a);//Constructor de copia
        //Destructor
        ~TDia();
        //Funciones Set
        void Set_Acarreo(int);
        void Set_Dia(eDia);
        //Funciones Get
        int Get_Acarreo(void);
        eDia Get_Dia(void);
        int ToInt(void);
        char* to_str(void);
        //Sobrecarga de los operadores
        friend int operator==(const TDia&,const TDia&);
        friend int operator!=(const TDia&,const TDia&);
        friend int operator<(const TDia&,const TDia&);
        friend int operator>(const TDia&,const TDia&);
        friend int operator<=(const TDia&,const TDia&);
        friend int operator>=(const TDia&,const TDia&);
        friend TDia operator+(const TDia&,const TDia&);
        friend TDia operator+(const TDia&,const int&);
        friend TDia operator+(const int&,const TDia&);
        friend TDia operator+(const TDia&,const eDia&);
        friend TDia operator+(const eDia&,const TDia&);
        friend TDia operator-(const TDia&,const TDia&);
        friend TDia operator-(const TDia&,const int&);
        friend TDia operator-(const int&,const TDia&);
        friend TDia operator-(const TDia&,const eDia&);
        friend TDia operator-(const eDia&,const TDia&);
        friend ostream& operator<< (ostream&,const TDia&);
        friend istream& operator>> (istream&,TDia&);
        TDia& operator=(const TDia&);
        TDia& operator=(const eDia&);
        TDia& operator=(const int&);
        TDia& operator++ (int j);
        TDia& operator-- (int j);
        friend int Hamming(const TDia&,const TDia&);
        friend void random(TDia&);
};

//------------------------------------------------------------------------------

class TCita
{
 private:
 public:
        THora Hora;
        TDia Dia;
        //Constructores
        TCita();//Contructor por defecto
        TCita(TCita &a);//Constructor de copia
        //Destructor
        ~TCita();
        //Sobrecarga de los operadores
        char* to_str(void);
        TCita& operator=(const TCita&);
        TCita& operator=(const THora&);
        TCita& operator=(const TDia&);
        TCita& operator=(const eHora&);
        TCita& operator=(const eDia&);
        friend int operator==(const TCita&,const TCita&);
        friend int operator!=(const TCita&,const TCita&);
        friend int operator<(const TCita&,const TCita&);
        friend int operator>(const TCita&,const TCita&);
        friend int operator>=(const TCita&,const TCita&);
        friend int operator<=(const TCita&,const TCita&);
        friend TCita operator+(const TCita&,const TCita&);
        friend TCita operator+(const TCita&,const int&);
        friend TCita operator+(const int&,const TCita&);
        friend TCita operator+(const TCita&,const TDia&);
        friend TCita operator+(const TDia&,const TCita&);
        friend TCita operator+(const TCita&,const THora&);
        friend TCita operator+(const THora&,const TCita&);
        friend TCita operator+(const TCita&,const eDia&);
        friend TCita operator+(const eDia&,const TCita&);
        friend TCita operator+(const TCita&,const eHora&);
        friend TCita operator+(const eHora&,const TCita&);
        friend TCita operator-(const TCita&,const TCita&);
        friend TCita operator-(const TCita&,const int&);
        friend TCita operator-(const int&,const TCita&);
        friend TCita operator-(const TCita&,const eDia&);
        friend TCita operator-(const eDia&,const TCita&);
        friend TCita operator-(const TCita&,const eHora&);
        friend TCita operator-(const eHora&,const TCita&);
        friend TCita operator-(const TCita&,const TDia&);
        friend TCita operator-(const TDia&,const TCita&);
        friend TCita operator-(const TCita&,const THora&);
        friend TCita operator-(const THora&,const TCita&);
        friend ostream& operator<< (ostream&,const TCita&);
        friend istream& operator>> (istream&,TCita&);
        friend int Hamming(const TCita&,const TCita&);
        friend void random(TCita&);
};

#endif
