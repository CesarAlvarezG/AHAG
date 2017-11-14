#include "ESPACIO.h"

TVector2d::TVector2d()
{
 x=y=0;
 return;
}

/*----------------------------------------------------------------------------*/

TVector2d::TVector2d(TVector2d &a)
{
 x=a.x;
 y=a.y;
 return;
}

/*----------------------------------------------------------------------------*/

TVector2d::~TVector2d()
{
 x=0;
 y=0;
 return;
}

/*----------------------------------------------------------------------------*/

void TVector2d::Set_x(double xp)
{
 x=xp;
 return;
}

/*----------------------------------------------------------------------------*/

void TVector2d::Set_y(double yp)
{
 y=yp;
 return;
}

/*----------------------------------------------------------------------------*/

double TVector2d::Get_x(void)
{
 return x;
}

/*----------------------------------------------------------------------------*/

double TVector2d::Get_y(void)
{
 return y;
}

/*----------------------------------------------------------------------------*/

double TVector2d::Mag(void)
{
 return sqrt((x*x)+(y*y));
}

/*----------------------------------------------------------------------------*/

TVector2d& TVector2d::operator=(const TVector2d &a)
{
 x=a.x;
 y=a.y;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TVector2d operator+(const TVector2d &a,const TVector2d &b)
{
 TVector2d Suma;
 Suma.x=a.x+b.x;
 Suma.y=a.y+b.y;
 return Suma;
}

/*----------------------------------------------------------------------------*/

TVector2d operator-(const TVector2d &a,const TVector2d &b)
{
 TVector2d Resta;
 Resta.x=a.x-b.x;
 Resta.y=a.y-b.y;
 return Resta;
}

/*----------------------------------------------------------------------------*/

TVector2d operator*(const int &a,const TVector2d &b)
{
 TVector2d Producto;
 Producto.x=a*b.x;
 Producto.y=a*b.y;
 return Producto;
}

/*----------------------------------------------------------------------------*/

TVector2d operator*(const TVector2d &a,const int &b)
{
 TVector2d Producto;
 Producto.x=a.x*b;
 Producto.y=a.y*b;
 return Producto;
}

/*----------------------------------------------------------------------------*/

int operator<(const TVector2d &a,const TVector2d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa<bb;
}

/*----------------------------------------------------------------------------*/

int operator>(const TVector2d &a,const TVector2d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa>bb;
}

/*----------------------------------------------------------------------------*/

int operator<=(const TVector2d &a,const TVector2d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa<=bb;
}

/*----------------------------------------------------------------------------*/

int operator>=(const TVector2d &a,const TVector2d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa>=bb;
}

/*----------------------------------------------------------------------------*/

int operator==(const TVector2d &a,const TVector2d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa==bb;
}

/*----------------------------------------------------------------------------*/

int operator!=(const TVector2d &a,const TVector2d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa==bb;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const TVector2d &a)
{
 co.setf(ios::showpos);
 co <<"x= " << a.x << " ";
 co.setf(ios::showpos);
 co << "y= "<< a.y;
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &ci,TVector2d &a)
{
 char s[10];
 ci >> s;
 ci >> a.x;
 ci >> s;
 ci >> a.y;
 return ci;
}

/******************************************************************************/

TVector3d::TVector3d()
{
 x=y=z=0;
 return;
}

/*----------------------------------------------------------------------------*/

TVector3d::TVector3d(TVector3d &a)
{
 x=a.x;
 y=a.y;
 z=a.z;
 return;
}

/*----------------------------------------------------------------------------*/

TVector3d::~TVector3d()
{
 x=y=z=0;
 return;
}

/*----------------------------------------------------------------------------*/

void TVector3d::Set_z(double zp)
{
 z=zp;
 return;
}

/*----------------------------------------------------------------------------*/

double TVector3d::Get_z(void)
{
 return z;
}

/*----------------------------------------------------------------------------*/

double TVector3d::Mag(void)
{
 return sqrt(x*x+y*y+z*z);
}

/*----------------------------------------------------------------------------*/

TVector2d& TVector3d::operator=(const TVector3d &a)
{
 x=a.x;
 y=a.y;
 z=a.z;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TVector3d operator+(const TVector3d &a,const TVector3d &b)
{
 TVector3d Suma;
 Suma.x=a.x+b.x;
 Suma.y=a.y+b.y;
 Suma.z=a.z+b.z;
 return Suma;
}

/*----------------------------------------------------------------------------*/

TVector3d operator-(const TVector3d &a,const TVector3d &b)
{
 TVector3d Resta;
 Resta.x=a.x-b.x;
 Resta.y=a.y-b.y;
 Resta.z=a.z-b.z;
 return Resta;
}

/*----------------------------------------------------------------------------*/

TVector3d operator*(const int &a,const TVector3d &b)
{
 TVector3d Producto;
 Producto.x=a*b.x;
 Producto.y=a*b.y;
 Producto.z=a*b.z;
 return Producto;
}

/*----------------------------------------------------------------------------*/

TVector3d operator*(const TVector3d &a,const int &b)
{
 TVector3d Producto;
 Producto.x=a.x*b;
 Producto.y=a.y*b;
 Producto.z=a.z*b;
 return Producto;
}

/*----------------------------------------------------------------------------*/

int operator<(const TVector3d &a,const TVector3d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa<bb;
}

/*----------------------------------------------------------------------------*/

int operator>(const TVector3d &a,const TVector3d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa>bb;
}

/*----------------------------------------------------------------------------*/

int operator<=(const TVector3d &a,const TVector3d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa<=bb;
}

/*----------------------------------------------------------------------------*/

int operator>=(const TVector3d &a,const TVector3d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa>=bb;
}

/*----------------------------------------------------------------------------*/

int operator==(const TVector3d &a,const TVector3d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa==bb;
}

/*----------------------------------------------------------------------------*/

int operator!=(const TVector3d &a,const TVector3d &b)
{
 double aa,bb;
 aa=a.Mag();
 bb=b.Mag();
 return aa==bb;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const TVector3d &a)
{
 co.setf(ios::showpos);
 co <<"x= " << a.x << " ";
 co.setf(ios::showpos);
 co << "y= "<< a.y;
 co.setf(ios::showpos);
 co << "z= "<< a.z;
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &ci,TVector3d &a)
{
 char s[10];
 ci >> s;
 ci >> a.x;
 ci >> s;
 ci >> a.y;
 ci >> s;
 ci >> a.z;
 return ci;
}

/*----------------------------------------------------------------------------*/


