#ifndef _Espacio_h
#define _Espacio_h

#include<iostream.h>
#include <string.h>


class TVector2d
{
 protected:
           double x,y;
 public:
        //Constructores
        TVector2d();//Contructor por defecto
        TVector2d(TVector2d &a);//Constructor de copia
        //Destructor
        ~TVector2d();
        //Funciones Set
        void Set_x(double xp);
        void Set_y(double yp);
        //Funciones Get
        double Get_x(void);
        double Get_y(void);
        //Funciones
        double Mag(void);//Magnitud del vector
        //Sobrecarga de los operadores
        TVector2d& operator=(const TVector2d&);
        friend TVector2d operator+(const TVector2d&,const TVector2d&);
        friend TVector2d operator-(const TVector2d&,const TVector2d&);
        friend TVector2d operator*(const int&,const TVector2d&);
        friend TVector2d operator*(const TVector2d&,const int&);
        friend int operator<(const TVector2d&,const TVector2d&);
        friend int operator>(const TVector2d&,const TVector2d&);
        friend int operator<=(const TVector2d&,const TVector2d&);
        friend int operator>=(const TVector2d&,const TVector2d&);
        friend int operator==(const TVector2d&,const TVector2d&);
        friend int operator!=(const TVector2d&,const TVector2d&);
        friend ostream& operator<< (ostream&,const TVector2d&);
        friend istream& operator>> (istream&,TVector2d&);
};

class TVector3d:public TVector2d
{
 protected:
         double z;
 public:
        //Constructores
        TVector3d();//Contructor por defecto
        TVector3d(TVector3d &a);//Constructor de copia
        //Destructor
        ~TVector3d();
        //Funciones Set
        void Set_z(double zp);
        //Funciones Get
        double Get_z(void);
        //Funciones
        double Mag(void);//Magnitud del vector
        //Sobrecarga de los operadores
        TVector2d& operator=(const TVector3d&);
        friend TVector3d operator+(const TVector3d&,const TVector3d&);
        friend TVector3d operator-(const TVector3d&,const TVector3d&);
        friend TVector3d operator*(const int&,const TVector3d&);
        friend TVector3d operator*(const TVector3d&,const int&);
        friend int operator<(const TVector3d&,const TVector3d&);
        friend int operator>(const TVector3d&,const TVector3d&);
        friend int operator<=(const TVector3d&,const TVector3d&);
        friend int operator>=(const TVector3d&,const TVector3d&);
        friend int operator==(const TVector3d&,const TVector3d&);
        friend int operator!=(const TVector3d&,const TVector3d&);
        friend ostream& operator<< (ostream&,const TVector3d&);
        friend istream& operator>> (istream&,TVector3d&);
};

#endif
