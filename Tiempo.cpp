#include "Tiempo.h"

char cHora[24][20]={{"00:00 a.m."},{"01:00 a.m."},{"02:00 a.m."},{"03:00 a.m."},
                    {"04:00 a.m."},{"05:00 a.m."},{"06:00 a.m."},{"07:00 a.m."},
                    {"08:00 a.m."},{"09:00 a.m."},{"10:00 a.m."},{"11:00 a.m."},
                    {"12:00 m."},{"01:00 p.m."},{"02:00 p.m."},{"03:00 p.m."},
                    {"04:00 p.m."},{"05:00 p.m."},{"06:00 p.m."},{"07:00 a.m."},
                    {"08:00 p.m."},{"09:00 p.m."},{"10:00 p.m."},{"11:00 p.m."}};


char cDia[7][10]={{"DOMINGO"},{"LUNES"},{"MARTES"},{"MIERCOLES"},{"JUEVES"},
                  {"VIERNES"},{"SABADO"}};

/*----------------------------------------------------------------------------*/

THora::THora()
{
 Hora=hr00;
}

/*----------------------------------------------------------------------------*/

THora::THora(THora &a)
{
 Hora=a.Hora;
}

/*----------------------------------------------------------------------------*/

THora::~THora()
{
 Hora=hr00;
}

/*----------------------------------------------------------------------------*/

void THora::Set_Acarreo(int a)
{
 Acarreo=a;
}

/*----------------------------------------------------------------------------*/

void THora::Set_Hora(eHora h)
{
 Hora=h;
}

/*----------------------------------------------------------------------------*/

char THora::Get_Acarreo(void)
{
 return Acarreo;
}

/*----------------------------------------------------------------------------*/

eHora THora::Get_Hora(void)
{
 return Hora;
}

/*----------------------------------------------------------------------------*/

int THora::ToInt(void)
{
 return (int)Hora;
}

/*----------------------------------------------------------------------------*/

char* THora::to_str(void)
{
 return cHora[Hora];
}

/*----------------------------------------------------------------------------*/

THora& THora::operator =(const THora &a)
{
 Hora=a.Hora;
 return (*this);
}

/*----------------------------------------------------------------------------*/

THora& THora::operator=(const eHora &a)
{
 Hora=a;
 return (*this);
}

/*----------------------------------------------------------------------------*/

THora& THora::operator=(const int &a)
{
 int i;
 if(a<hr00)i=hr00;
 if(a>hr23)i=hr23;
 Hora=i;
 return (*this);
}


/*----------------------------------------------------------------------------*/

THora& THora::operator++ (int j)
{
 int i,l,k;
 i=Hora;
 i++;
 if(i>23)
   {
    l=i/24;
    k=i%24;
    i=k;
    Acarreo=l;
   }
 return (*this);
}

/*----------------------------------------------------------------------------*/

THora& THora::operator-- (int j)
{
 int i,l,k;
 i=Hora;
 i--;
 if(i<23)
   {
    l=i/24;
    k=i%24;
    i=k;
    Acarreo=l;
   }
 return (*this);
}

/*----------------------------------------------------------------------------*/

int operator==(const THora &a,const THora &b)
{
 return a.Hora==b.Hora;
}

/*----------------------------------------------------------------------------*/

int operator!=(const THora &a,const THora &b)
{
 return a.Hora!=b.Hora;
}

/*----------------------------------------------------------------------------*/

int operator<(const THora &a,const THora &b)
{
 return a.Hora<b.Hora;
}

/*----------------------------------------------------------------------------*/

int operator>(const THora &a,const THora &b)
{
 return a.Hora>b.Hora;
}

/*----------------------------------------------------------------------------*/

int operator<=(const THora &a,const THora &b)
{
 return a.Hora<=b.Hora;
}

/*----------------------------------------------------------------------------*/

int operator>=(const THora &a,const THora &b)
{
 return a.Hora>=b.Hora;
}

/*----------------------------------------------------------------------------*/

THora operator+(const THora &a,const THora &b)
{
 THora suma;
 int i,j,z,l,m;
 i=a.Hora;
 j=b.Hora;
 z=i+j;
 if(z>23)
   {
    l=z/24;
    m=z%24;
    z=m;
    suma.Acarreo=l;
   }
 suma.Hora=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

THora operator+(const THora &a,const int &b)
{
 THora suma;
 int i,j,z,l,m;
 i=a.Hora;
 j=b;
 z=i+j;
 if(z>23)
   {
    l=z/24;
    m=z%24;
    z=m;
    suma.Acarreo=l;
   }
 suma.Hora=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

THora operator+(const int &a,const THora &b)
{
 THora suma;
 int i,j,z,l,m;
 i=a;
 j=b.Hora;
 z=i+j;
 if(z>23)
   {
    l=z/24;
    m=z%24;
    z=m;
    suma.Acarreo=l;
   }
 suma.Hora=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

THora operator+(const THora &a,const eHora &b)
{
 THora suma;
 int i,j,z,l,m;
 i=a.Hora;
 j=b;
 z=i+j;
 if(z>23)
   {
    l=z/24;
    m=z%24;
    z=m;
    suma.Acarreo=l;
   }
 suma.Hora=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

THora operator+(const eHora &a,const THora &b)
{
 THora suma;
 int i,j,z,l,m;
 i=a;
 j=b.Hora;
 z=i+j;
 if(z>23)
   {
    l=z/24;
    m=z%24;
    z=m;
    suma.Acarreo=l;
   }
 suma.Hora=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

THora operator-(const THora &a,const THora &b)
{
 THora resta;
 int i,j,z,l,m;
 i=a.Hora;
 j=b.Hora;
 z=i-j;
 if(z<0)
   {
    l=z/24;
    m=z%24;
    z=m;
    resta.Acarreo=l;
   }
 return resta;
}

/*----------------------------------------------------------------------------*/

THora operator-(const THora &a,const int &b)
{
 THora resta;
 int i,j,z,l,m;
 i=a.Hora;
 j=b;
 z=i-j;
 if(z<0)
   {
    l=z/24;
    m=z%24;
    z=m;
    resta.Acarreo=l;
   }
 return resta;
}

/*----------------------------------------------------------------------------*/

THora operator-(const int &a,const THora &b)
{
 THora resta;
 int i,j,z,l,m;
 i=a;
 j=b.Hora;
 z=i-j;
 if(z<0)
   {
    l=z/24;
    m=z%24;
    z=m;
    resta.Acarreo=l;
   }
 return resta;
}

/*----------------------------------------------------------------------------*/

THora operator-(const THora &a,const eHora &b)
{
 THora resta;
 int i,j,z,l,m;
 i=a.Hora;
 j=b;
 z=i-j;
 if(z<0)
   {
    l=z/24;
    m=z%24;
    z=m;
    resta.Acarreo=l;
   }
 return resta;
}

/*----------------------------------------------------------------------------*/

THora operator-(const eHora &a,const THora &b)
{
 THora resta;
 int i,j,z,l,m;
 i=a;
 j=b.Hora;
 z=i-j;
 if(z<0)
   {
    l=z/24;
    m=z%24;
    z=m;
    resta.Acarreo=l;
   }
 return resta;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const THora &a)
{
 co << cHora[a.Hora];
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &ci,THora &a)
{
 int i;
 char s[20];
 ci >> s;
 for(a.Hora=hr00;a.Hora<hr23;a=a+hr01)
    {
     if(strcmp(s,cHora[a.Hora]))
       {
        return ci;
       }
    }
 a.Hora=hr00;
 return ci;
}

/*----------------------------------------------------------------------------*/

int Hamming(const THora &a,const THora &b)
{
 int acc;
 Bits_char tem_a,tem_b;
 tem_a=(char)a.Hora;
 tem_b=(char)b.Hora;
 acc=Hamming(tem_a,tem_b);
 return acc;
}

/*----------------------------------------------------------------------------*/

void random(THora &a)
{
 int i;
 randomize();
 i=random(24);
 a.Hora=i;
}

/******************************************************************************/

TDia::TDia()
{
 Dia=dDomingo;
}

/*----------------------------------------------------------------------------*/

TDia::TDia(TDia &a)
{
 Dia=a.Dia;
}

/*----------------------------------------------------------------------------*/

TDia::~TDia()
{
 Dia=dDomingo;
}

/*----------------------------------------------------------------------------*/

void TDia::Set_Acarreo(int a)
{
 Acarreo=a;
}   

/*----------------------------------------------------------------------------*/

void TDia::Set_Dia(eDia d)
{
 Dia=d;
}

/*----------------------------------------------------------------------------*/

int TDia::Get_Acarreo(void)
{
 return Acarreo;
}

/*----------------------------------------------------------------------------*/

eDia TDia::Get_Dia(void)
{
 return Dia;
}

/*----------------------------------------------------------------------------*/

int TDia::ToInt(void)
{
 return (int)Dia;
}

/*----------------------------------------------------------------------------*/

char* TDia::to_str(void)
{
 return cDia[Dia];
}

/*----------------------------------------------------------------------------*/

TDia& TDia::operator=(const TDia& a)
{
 Dia=a.Dia;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TDia& TDia::operator=(const eDia& a)
{
 Dia=a;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TDia& TDia::operator=(const int& a)
{
 int i;
 if(a<dDomingo)i=dDomingo;
 if(a>dSabado)i=dSabado;
 Dia=i;
 return (*this);
}


/*----------------------------------------------------------------------------*/

TDia& TDia::operator++ (int j)
{
 int i,l,k;
 i=Dia;
 i++;
 if(i>6)
   {
    l=i/6;
    k=i%6;
    Dia=k;
    Acarreo=l;
   }
 return (*this);
}

/*----------------------------------------------------------------------------*/

TDia& TDia::operator-- (int j)
{
 int i,l,k;
 i=Dia;
 i--;
 if(i>6)
   {
    l=i/6;
    k=i%6;
    Dia=k;
    Acarreo=l;
   }
 return (*this);
}

/*----------------------------------------------------------------------------*/

int operator==(const TDia &a,const TDia &b)
{
 return a.Dia==b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator!=(const TDia &a,const TDia &b)
{
 return a.Dia!=b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator<(const TDia &a,const TDia &b)
{
 return a.Dia<b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator>(const TDia &a,const TDia &b)
{
 return a.Dia>b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator>=(const TDia &a,const TDia &b)
{
 return a.Dia>=b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator<=(const TDia &a,const TDia &b)
{
 return a.Dia<=b.Dia;
}

/*----------------------------------------------------------------------------*/

TDia operator+(const TDia &a,const TDia &b)
{
 TDia suma;
 int i,j,z,l,m;
 i=a.Dia;
 j=b.Dia;
 z=i+j;
 if(z>6)
   {
    l=z/7;
    m=z%7;
    z=m;
    suma.Acarreo=l;
   }
 suma.Dia=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

TDia operator+(const TDia &a,const int &b)
{
 TDia suma;
 int i,j,z,l,m;
 i=a.Dia;
 j=b;
 z=i+j;
 if(z>6)
   {
    l=z/7;
    m=z%7;
    z=m;
    suma.Acarreo=l;
   }
 suma.Dia=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

TDia operator+(const int &a,const TDia &b)
{
 TDia suma;
 int i,j,z,l,m;
 i=a;
 j=b.Dia;
 z=i+j;
 if(z>6)
   {
    l=z/7;
    m=z%7;
    z=m;
    suma.Acarreo=l;
   }
 suma.Dia=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

TDia operator+(const TDia &a,const eDia &b)
{
 TDia suma;
 int i,j,z,l,m;
 i=a.Dia;
 j=b;
 z=i+j;
 if(z>6)
   {
    l=z/7;
    m=z%7;
    z=m;
    suma.Acarreo=l;
   }
 suma.Dia=z;
 return suma;
}

/*----------------------------------------------------------------------------*/

TDia operator+(const eDia &a,const TDia &b)
{
 TDia suma;
 int i,j,z,l,m;
 i=a;
 j=b.Dia;
 z=i+j;
 if(z>6)
   {
    l=z/7;
    m=z%7;
    z=m;
    suma.Acarreo=l;
   }
 suma.Dia=z;
 return suma;
}


/*----------------------------------------------------------------------------*/

TDia operator-(const TDia &a,const TDia &b)
{
 TDia resta;
 int i,j,z,l,m;
 i=a.Dia;
 j=b.Dia;
 z=i-j;
 if(z<0)
   {
    l=z/7;
    m=z%7;
    z=m;
    resta.Acarreo=l;
   }
 resta.Dia=z;
 return resta;
}

/*----------------------------------------------------------------------------*/

TDia operator-(const TDia &a,const int &b)
{
 TDia resta;
 int i,j,z,l,m;
 i=a.Dia;
 j=b;
 z=i-j;
 if(z<0)
   {
    l=z/7;
    m=z%7;
    z=m;
    resta.Acarreo=l;
   }
 resta.Dia=z;
 return resta;
}

/*----------------------------------------------------------------------------*/

TDia operator-(const int &a,const TDia &b)
{
 TDia resta;
 int i,j,z,l,m;
 i=a;
 j=b.Dia;
 z=i-j;
 if(z<0)
   {
    l=z/7;
    m=z%7;
    z=m;
    resta.Acarreo=l;
   }
 resta.Dia=z;
 return resta;
}

/*----------------------------------------------------------------------------*/

TDia operator-(const TDia &a,const eDia &b)
{
 TDia resta;
 int i,j,z,l,m;
 i=a.Dia;
 j=b;
 z=i-j;
 if(z<0)
   {
    l=z/7;
    m=z%7;
    z=m;
    resta.Acarreo=l;
   }
 resta.Dia=z;
 return resta;
}

/*----------------------------------------------------------------------------*/

TDia operator-(const eDia &a,const TDia &b)
{
 TDia resta;
 int i,j,z,l,m;
 i=a;
 j=b.Dia;
 z=i-j;
 if(z<0)
   {
    l=z/7;
    m=z%7;
    z=m;
    resta.Acarreo=l;
   }
 resta.Dia=z;
 return resta;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const TDia &a)
{
 co << cDia[a.Dia];
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &ci,TDia &a)
{
 int i;
 char s[20];
 ci >> s;
 for(a.Dia=dDomingo;a.Dia<dSabado;a.Dia=a.Dia+dLunes)
    {
     if(strcmp(s,cDia[a.Dia]))
       {
        return ci;
       }
    }
 a.Dia=dDomingo;
 return ci;
}

/*----------------------------------------------------------------------------*/

int Hamming(const TDia &a,const TDia &b)
{
 int acc;
 Bits_char tem_a,tem_b;
 tem_a=(char)a.Dia;
 tem_b=(char)b.Dia;
 acc=Hamming(tem_a,tem_b);
 return acc;
}

/*----------------------------------------------------------------------------*/

void random(TDia &a)
{
 int i;
 randomize();
 i=random(7);
 a.Dia=i;
}

/******************************************************************************/

TCita::TCita()
{
 Dia.Set_Dia(dDomingo);
 Hora.Set_Hora(hr00);
}

/*----------------------------------------------------------------------------*/

TCita::TCita(TCita &a)
{
 Dia=a.Dia;
 Hora=a.Hora;
}

/*----------------------------------------------------------------------------*/

TCita::~TCita()
{
 Dia.Set_Dia(dDomingo);
 Hora.Set_Hora(hr00);
}

/*----------------------------------------------------------------------------*/

char* TCita::to_str(void)
{
 char cadena[50];
 strcpy(cadena,Dia.to_str());
 strcat(cadena,"\t");
 strcat(cadena,Hora.to_str());
 return cadena;
}

/*----------------------------------------------------------------------------*/

TCita& TCita::operator=(const TCita &a)
{
 Dia=a.Dia;
 Hora=a.Hora;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TCita& TCita::operator=(const THora &a)
{
 Hora=a;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TCita& TCita::operator=(const eHora &a)
{
 Hora=a;
 return (*this);
}

/*----------------------------------------------------------------------------*/

TCita& TCita::operator=(const eDia &a)
{
 Dia=a;
 return (*this);
}

/*----------------------------------------------------------------------------*/

int operator==(const TCita &a,const TCita &b)
{
 if(a.Hora==b.Hora&&a.Dia==b.Dia)
   {
    return 0;
   }
 return 1;
}

/*----------------------------------------------------------------------------*/

int operator!=(const TCita &a,const TCita &b)
{
 if(a.Hora!=b.Hora&&a.Dia!=b.Dia)
   {
    return 0;
   }
 return 1;
}

/*----------------------------------------------------------------------------*/

int operator<(const TCita &a,const TCita &b)
{
 return a.Hora<b.Hora&&a.Dia<b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator>(const TCita &a,const TCita &b)
{
 return a.Hora>b.Hora&&a.Dia>b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator>=(const TCita &a,const TCita &b)
{
 return a.Hora>=b.Hora&&a.Dia>=b.Dia;
}

/*----------------------------------------------------------------------------*/

int operator<=(const TCita &a,const TCita &b)
{
 return a.Hora!=b.Hora&&a.Dia!=b.Dia;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TCita &a,const TCita &b)
{
 TCita suma;
 suma.Hora=a.Hora+b.Hora;
 suma.Dia=a.Dia+b.Dia;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TCita &a,const int &b)
{
 TCita suma;
 suma.Hora=a.Hora+b;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const int &a,const TCita &b)
{
 TCita suma;
 suma.Hora=a+b.Hora;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TCita &a,const TDia &b)
{
 TCita suma;
 suma.Hora=a.Hora;
 suma.Dia=a.Dia+b;
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TDia &a,const TCita &b)
{
 TCita suma;
 suma.Hora=b.Hora;
 suma.Dia=a+b.Dia;
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TCita &a,const THora &b)
{
 TCita suma;
 suma.Hora=a.Hora+b;
 suma.Dia=a.Dia;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const THora &a,const TCita &b)
{
 TCita suma;
 suma.Hora=a+b.Hora;
 suma.Dia=b.Dia;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TCita &a,const eDia &b)
{
 TCita suma;
 TDia tem;
 tem=b;
 suma.Hora=a.Hora;
 suma.Dia=a.Dia+tem;
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const eDia &a,const TCita &b)
{
 TCita suma;
 TDia tem;
 tem=a;
 suma.Hora=b.Hora;
 suma.Dia=tem+b.Dia;
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const TCita &a,const eHora &b)
{
 TCita suma;
 THora tem;
 tem=b;
 suma.Hora=a.Hora+tem;
 suma.Dia=a.Dia;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}

/*----------------------------------------------------------------------------*/

TCita operator+(const eHora &a,const TCita &b)
{
 TCita suma;
 THora tem;
 tem=a;
 suma.Hora=tem+b.Hora;
 suma.Dia=b.Dia;
 suma.Dia=suma.Dia+suma.Hora.Get_Acarreo();
 return suma;
}


/*----------------------------------------------------------------------------*/

TCita operator-(const TCita &a,const TCita &b)
{
 TCita resta;
 resta.Hora=a.Hora-b.Hora;
 resta.Dia=a.Dia-b.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const TCita &a,const int &b)
{
 TCita resta;
 resta.Hora=a.Hora-b;
 resta.Dia=a.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const int &a,const TCita &b)
{
 TCita resta;
 resta.Hora=a-b.Hora;
 resta.Dia=b.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const TCita &a,const TDia &b)
{
 TCita resta;
 resta.Hora=a.Hora;
 resta.Dia=a.Dia-b;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const TDia &a,const TCita &b)
{
 TCita resta;
 resta.Hora=b.Hora;
 resta.Dia=a-b.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const TCita &a,const THora &b)
{
 TCita resta;
 resta.Hora=a.Hora-b;
 resta.Dia=a.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const THora &a,const TCita &b)
{
 TCita resta;
 resta.Hora=a-b.Hora;
 resta.Dia=b.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const TCita &a,const eDia &b)
{
 TCita resta;
 TDia tem;
 tem=b;
 resta.Hora=a.Hora;
 resta.Dia=a.Dia-tem;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const eDia &a,const TCita &b)
{
 TCita resta;
 TDia tem;
 tem=a;
 resta.Hora=b.Hora;
 resta.Dia=tem-b.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const TCita &a,const eHora &b)
{
 TCita resta;
 THora tem;
 tem=b;
 resta.Hora=a.Hora-tem;
 resta.Dia=a.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

TCita operator-(const eHora &a,const TCita &b)
{
 TCita resta;
 THora tem;
 tem=a;
 resta.Hora=tem-b.Hora;
 resta.Dia=b.Dia;
 resta.Dia=resta.Dia+resta.Hora.Get_Acarreo();
 return resta;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const TCita &a)
{
 co << a.Dia << "\t" << a.Hora;
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &ci,TCita &a)
{
 ci >> a.Dia;
 ci >> a.Hora;
 return ci;
}

/*----------------------------------------------------------------------------*/

int Hamming(const TCita &a,const TCita &b)
{
 int acc;
 acc=Hamming(a.Hora,b.Hora);
 acc+=Hamming(a.Dia,b.Dia);
 return acc;
}

/*----------------------------------------------------------------------------*/

void random(TCita &a)
{
 random(a.Hora);
 random(a.Dia);
}