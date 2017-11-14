#ifndef _Bits_h
#define _Bits_h

#include<iostream.h>

struct Bits_en_char
{
 unsigned char bit0:1;
 unsigned char bit1:1;
 unsigned char bit2:1;
 unsigned char bit3:1;
 unsigned char bit4:1;
 unsigned char bit5:1;
 unsigned char bit6:1;
 unsigned char bit7:1;
};

struct Nible_en_char
{
 unsigned char nible0:4;
 unsigned char nible1:4;
};

union Bit_char
{
 Bits_en_char bin;
 Nible_en_char nib;
 char cha;
};

class Bits_char
{
        Bit_char bits;
 public:
        Bits_char();//Construtor por defecto
        Bits_char(Bits_char &);//Contructor por copia
        //Funciones Set
        void Set_bit(char,int);
        void Set_nible(char,int);
        void Set_char(char);
        //Funciones Get
        char Get_bit(int);
        char Get_nible(int);
        char Get_char(void);
        //Funcion en bit
        void neg_bit(int);
        void neg_nib(int);
        void neg(void);
        //Funciones entre bits
        friend int Hamming(const Bits_char&,const Bits_char&);
        //Sobrecarga de operadores
        friend Bits_char operator+(const Bits_char&,const Bits_char&);
        friend Bits_char operator-(const Bits_char&,const Bits_char&);
        friend Bits_char operator*(const Bits_char&,const Bits_char&);
        friend Bits_char operator/(const Bits_char&,const Bits_char&);
        friend Bits_char operator+(const char&,const Bits_char&);
        friend Bits_char operator-(const char&,const Bits_char&);
        friend Bits_char operator*(const char&,const Bits_char&);
        friend Bits_char operator/(const char&,const Bits_char&);
        friend Bits_char operator+(const Bits_char&,const char&);
        friend Bits_char operator-(const Bits_char&,const char&);
        friend Bits_char operator*(const Bits_char&,const char&);
        friend Bits_char operator/(const Bits_char&,const char&);
        //Sobrecarga operador de asignacion
        Bits_char& operator=(const Bits_char&);
        Bits_char& operator=(const char&);
        //Sobrecarga de operadores de relacion
        friend int operator==(const Bits_char&,const Bits_char&);
        friend int operator!=(const Bits_char&,const Bits_char&);
        //Sobrecarga de los operadores de insercion de flujo
        friend ostream& operator<< (ostream&,const Bits_char&);
        friend istream& operator>> (istream&,Bits_char&);
        //Sobrecarga de operadores ++ y --
        Bits_char& operator++ (int j);
        Bits_char& operator-- (int j);
};

/*int Para 32 Bits, 4 Bytes*/

struct Bits_en_int
{
 unsigned char bit0:1;
 unsigned char bit1:1;
 unsigned char bit2:1;
 unsigned char bit3:1;
 unsigned char bit4:1;
 unsigned char bit5:1;
 unsigned char bit6:1;
 unsigned char bit7:1;
 unsigned char bit8:1;
 unsigned char bit9:1;
 unsigned char bit10:1;
 unsigned char bit11:1;
 unsigned char bit12:1;
 unsigned char bit13:1;
 unsigned char bit14:1;
 unsigned char bit15:1;
 unsigned char bit16:1;
 unsigned char bit17:1;
 unsigned char bit18:1;
 unsigned char bit19:1;
 unsigned char bit20:1;
 unsigned char bit21:1;
 unsigned char bit22:1;
 unsigned char bit23:1;
 unsigned char bit24:1;
 unsigned char bit25:1;
 unsigned char bit26:1;
 unsigned char bit27:1;
 unsigned char bit28:1;
 unsigned char bit29:1;
 unsigned char bit30:1;
 unsigned char bit31:1;
};

struct Nible_en_int
{
 unsigned char nible0:4;
 unsigned char nible1:4;
 unsigned char nible2:4;
 unsigned char nible3:4;
 unsigned char nible4:4;
 unsigned char nible5:4;
 unsigned char nible6:4;
 unsigned char nible7:4;
};

struct Char_en_int
{
 unsigned char char0:8;
 unsigned char char1:8;
 unsigned char char2:8;
 unsigned char char3:8;
};

union Bit_int
{
 Bits_en_int bin;
 Nible_en_int nib;
 Char_en_int cha;
 int Int;
};

class Bits_int
{
        Bit_int bits;
 public:
        Bits_int();//Construtor por defecto
        Bits_int(Bits_int &);//Contructor por copia
        //Funciones Set
        void Set_bit(int,int);
        void Set_nible(int,int);
        void Set_char(char,int);
        void Set_int(int);
        //Funciones Get
        int Get_bit(int);
        int Get_nible(int);
        char Get_char(int);
        int Get_int(void);
        //Funcion en bit
        void neg_bit(int);
        void neg_nib(int);
        void neg_char(int);
        void neg(void);
        //Funciones entre bits
        friend int Hamming(const Bits_int&,const Bits_int&);
        //Sobrecarga de operadores
        friend Bits_int operator+(const Bits_int&,const Bits_int&);
        friend Bits_int operator-(const Bits_int&,const Bits_int&);
        friend Bits_int operator*(const Bits_int&,const Bits_int&);
        friend Bits_int operator/(const Bits_int&,const Bits_int&);
        friend Bits_int operator+(const int&,const Bits_int&);
        friend Bits_int operator-(const int&,const Bits_int&);
        friend Bits_int operator*(const int&,const Bits_int&);
        friend Bits_int operator/(const int&,const Bits_int&);
        friend Bits_int operator+(const Bits_int&,const int&);
        friend Bits_int operator-(const Bits_int&,const int&);
        friend Bits_int operator*(const Bits_int&,const int&);
        friend Bits_int operator/(const Bits_int&,const int&);
        //Sobrecarga operador de asignacion
        Bits_int& operator=(const Bits_int&);
        Bits_int& operator=(const int&);
        //Sobrecarga de operadores de relacion
        friend int operator==(const Bits_int&,const Bits_int&);
        friend int operator!=(const Bits_int&,const Bits_int&);
        //Sobrecarga de los operadores de insercion de flujo
        friend ostream& operator<< (ostream&,const Bits_int&);
        friend istream& operator>> (istream&,Bits_int&);
        //Sobrecarga de operadores ++ y --
        Bits_int& operator++ (int j);
        Bits_int& operator-- (int j);
};

int Hamming(const char&,const char&);
int Hamming(const int&,const int&);

#endif
