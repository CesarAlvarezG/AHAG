#include "Bits.h"

/*----------------------------------------------------------------------------*/

Bits_char::Bits_char()
{
 int i;
 bits.cha=0;
}

/*----------------------------------------------------------------------------*/

Bits_char::Bits_char(Bits_char &a)
{
 int i;
 bits.cha=a.bits.cha;
}

/*----------------------------------------------------------------------------*/

void Bits_char::Set_bit(char a,int n)
{
 switch(n){
           case 0:
                  bits.bin.bit0=a;
           break;
           case 1:
                  bits.bin.bit1=a;
           break;
           case 2:
                  bits.bin.bit2=a;
           break;
           case 3:
                  bits.bin.bit3=a;
           break;
           case 4:
                  bits.bin.bit4=a;
           break;
           case 5:
                  bits.bin.bit5=a;
           break;
           case 6:
                  bits.bin.bit6=a;
           break;
           case 7:
                  bits.bin.bit7=a;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_char::Set_nible(char a,int n)
{
 switch(n){
           case 0:
                  bits.nib.nible0=a;
           break;
           case 1:
                  bits.nib.nible1=a;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_char::Set_char(char a)
{
 bits.cha=a;
}

/*----------------------------------------------------------------------------*/

char Bits_char::Get_bit(int n)
{
 switch(n){
           case 0:
                  return bits.bin.bit0;
           case 1:
                  return bits.bin.bit1;
           case 2:
                  return bits.bin.bit2;
           case 3:
                  return bits.bin.bit3;
           case 4:
                  return bits.bin.bit4;
           case 5:
                  return bits.bin.bit5;
           case 6:
                  return bits.bin.bit6;
           case 7:
                  return bits.bin.bit7;
           default:
                   return 0;
          }
}

/*----------------------------------------------------------------------------*/

char Bits_char::Get_nible(int n)
{
 switch(n){
           case 0:
                  return bits.nib.nible0;
           case 1:
                  return bits.nib.nible1;
           default:
                   return 0;
          }
}

/*----------------------------------------------------------------------------*/

char Bits_char::Get_char(void)
{
 return bits.cha;
}

/*----------------------------------------------------------------------------*/

void Bits_char::neg_bit(int n)
{
 switch(n){
           case 0:
                  bits.bin.bit0=~bits.bin.bit0;
           break;
           case 1:
                  bits.bin.bit1=~bits.bin.bit1;
           break;
           case 2:
                  bits.bin.bit2=~bits.bin.bit2;
           break;
           case 3:
                  bits.bin.bit3=~bits.bin.bit3;
           break;
           case 4:
                  bits.bin.bit4=~bits.bin.bit4;
           break;
           case 5:
                  bits.bin.bit5=~bits.bin.bit5;
           break;
           case 6:
                  bits.bin.bit6=~bits.bin.bit6;
           break;
           case 7:
                  bits.bin.bit7=~bits.bin.bit7;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_char::neg_nib(int n)
{
 switch(n){
           case 0:
                  bits.nib.nible0=~bits.nib.nible0;
           break;
           case 1:
                  bits.nib.nible1=~bits.nib.nible1;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_char::neg(void)
{
 bits.cha=~bits.cha;
}

/*----------------------------------------------------------------------------*/

int Hamming(const Bits_char &a,const Bits_char &b)
{
 int i;
 char acc;
 Bits_char Ham;
 Ham.bits.cha=a.bits.cha^b.bits.cha;//Xor
 for(i=0,acc=0;i<8;i++)
    {
     acc+=Ham.Get_bit(i);
    }
 return (int)acc;
}

/*----------------------------------------------------------------------------*/

Bits_char operator+(const Bits_char &a,const Bits_char &b)
{
 Bits_char suma;
 suma.bits.cha=a.bits.cha+b.bits.cha;
 return suma;
}

/*----------------------------------------------------------------------------*/

Bits_char operator-(const Bits_char &a,const Bits_char &b)
{
 Bits_char resta;
 resta.bits.cha=a.bits.cha-b.bits.cha;
 return resta;
}

/*----------------------------------------------------------------------------*/

Bits_char operator*(const Bits_char &a,const Bits_char &b)
{
 Bits_char producto;
 producto.bits.cha=a.bits.cha*b.bits.cha;
 return producto;
}

/*----------------------------------------------------------------------------*/

Bits_char operator/(const Bits_char &a,const Bits_char &b)
{
 Bits_char cociente;
 cociente.bits.cha=a.bits.cha/b.bits.cha;
 return cociente;
}

/*----------------------------------------------------------------------------*/


Bits_char operator+(const char &a,const Bits_char &b)
{
 Bits_char suma;
 suma.bits.cha=a+b.bits.cha;
 return suma;
}

/*----------------------------------------------------------------------------*/

Bits_char operator-(const char &a,const Bits_char &b)
{
 Bits_char resta;
 resta.bits.cha=a-b.bits.cha;
 return resta;
}

/*----------------------------------------------------------------------------*/

Bits_char operator*(const char &a,const Bits_char &b)
{
 Bits_char producto;
 producto.bits.cha=a*b.bits.cha;
 return producto;
}

/*----------------------------------------------------------------------------*/

Bits_char operator/(const char &a,const Bits_char &b)
{
 Bits_char cociente;
 cociente.bits.cha=a/b.bits.cha;
 return cociente;
}

/*----------------------------------------------------------------------------*/

Bits_char operator+(const Bits_char &a,const char &b)
{
 Bits_char suma;
 suma.bits.cha=a.bits.cha+b;
 return suma;
}

/*----------------------------------------------------------------------------*/

Bits_char operator-(const Bits_char &a,const char &b)
{
 Bits_char resta;
 resta.bits.cha=a.bits.cha-b;
 return resta;
}

/*----------------------------------------------------------------------------*/

Bits_char operator*(const Bits_char &a,const char &b)
{
 Bits_char producto;
 producto.bits.cha=a.bits.cha*b;
 return producto;
}

/*----------------------------------------------------------------------------*/

Bits_char operator/(const Bits_char &a,const char &b)
{
 Bits_char cociente;
 cociente.bits.cha=a.bits.cha/b;
 return cociente;
}

/*----------------------------------------------------------------------------*/

Bits_char& Bits_char::operator=(const Bits_char &a)
{
 bits.cha=a.bits.cha;
 return (*this);
}

/*----------------------------------------------------------------------------*/

Bits_char& Bits_char::operator=(const char &a)
{
 bits.cha=a;
 return (*this);
}


/*----------------------------------------------------------------------------*/

int operator==(const Bits_char &a,const Bits_char &b)
{
 return a.bits.cha==b.bits.cha;
}

/*----------------------------------------------------------------------------*/

int operator!=(const Bits_char &a,const Bits_char &b)
{
 return a.bits.cha!=b.bits.cha;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const Bits_char &a)
{
 co<<a.bits.cha;
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &co,Bits_char &a)
{
 co >>a.bits.cha;
 return co;
}

/*----------------------------------------------------------------------------*/

Bits_char& Bits_char::operator++ (int j)
{
 bits.cha++;
 return (*this);
}

/*----------------------------------------------------------------------------*/

Bits_char& Bits_char::operator-- (int j)
{
 bits.cha--;
 return (*this);
}

/*----------------------------------------------------------------------------*/

Bits_int::Bits_int()
{
 int i;
 bits.Int=0;
}

/*----------------------------------------------------------------------------*/

Bits_int::Bits_int(Bits_int &a)
{
 int i;
 bits.Int=a.bits.Int;
}

/*----------------------------------------------------------------------------*/

void Bits_int::Set_bit(int a,int n)
{
 switch(n){
           case 0:
                  bits.bin.bit0=a;
           break;
           case 1:
                  bits.bin.bit1=a;
           break;
           case 2:
                  bits.bin.bit2=a;
           break;
           case 3:
                  bits.bin.bit3=a;
           break;
           case 4:
                  bits.bin.bit4=a;
           break;
           case 5:
                  bits.bin.bit5=a;
           break;
           case 6:
                  bits.bin.bit6=a;
           break;
           case 7:
                  bits.bin.bit7=a;
           break;
           case 8:
                  bits.bin.bit8=a;
           break;
           case 9:
                  bits.bin.bit9=a;
           break;
           case 10:
                   bits.bin.bit10=a;
           break;
           case 11:
                   bits.bin.bit11=a;
           break;
           case 12:
                   bits.bin.bit12=a;
           break;
           case 13:
                   bits.bin.bit13=a;
           break;
           case 14:
                   bits.bin.bit14=a;
           break;
           case 15:
                   bits.bin.bit15=a;
           break;
           case 16:
                   bits.bin.bit16=a;
           break;
           case 17:
                   bits.bin.bit17=a;
           break;
           case 18:
                   bits.bin.bit18=a;
           break;
           case 19:
                   bits.bin.bit19=a;
           break;
           case 20:
                   bits.bin.bit20=a;
           break;
           case 21:
                   bits.bin.bit21=a;
           break;
           case 22:
                   bits.bin.bit22=a;
           break;
           case 23:
                   bits.bin.bit23=a;
           break;
           case 24:
                   bits.bin.bit24=a;
           break;
           case 25:
                   bits.bin.bit25=a;
           break;
           case 26:
                   bits.bin.bit26=a;
           break;
           case 27:
                   bits.bin.bit27=a;
           break;
           case 28:
                   bits.bin.bit28=a;
           break;
           case 29:
                   bits.bin.bit29=a;
           break;
           case 30:
                   bits.bin.bit30=a;
           break;
           case 31:
                   bits.bin.bit31=a;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_int::Set_nible(int a,int n)
{
 switch(n){
           case 0:
                  bits.nib.nible0=a;
           break;
           case 1:
                  bits.nib.nible1=a;
           break;
           case 2:
                  bits.nib.nible2=a;
           break;
           case 3:
                  bits.nib.nible3=a;
           break;
           case 4:
                  bits.nib.nible4=a;
           break;
           case 5:
                  bits.nib.nible5=a;
           break;
           case 6:
                  bits.nib.nible6=a;
           break;
           case 7:
                  bits.nib.nible7=a;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_int::Set_char(char a,int n)
{
 switch(n){
           case 0:
                  bits.cha.char0=a;
           break;
           case 1:
                  bits.cha.char1=a;
           break;
           case 2:
                  bits.cha.char2=a;
           break;
           case 3:
                  bits.cha.char3=a;
           break;
          }
}


/*----------------------------------------------------------------------------*/

void Bits_int::Set_int(int a)
{
 bits.Int=a;
}

/*----------------------------------------------------------------------------*/

int Bits_int::Get_bit(int n)
{
 switch(n){
           case 0:
                  return bits.bin.bit0;
           case 1:
                  return bits.bin.bit1;
           case 2:
                  return bits.bin.bit2;
           case 3:
                  return bits.bin.bit3;
           case 4:
                  return bits.bin.bit4;
           case 5:
                  return bits.bin.bit5;
           case 6:
                  return bits.bin.bit6;
           case 7:
                  return bits.bin.bit7;
           case 8:
                  return bits.bin.bit8;
           case 9:
                  return bits.bin.bit9;
           case 10:
                   return bits.bin.bit10;
           case 11:
                   return bits.bin.bit11;
           case 12:
                   return bits.bin.bit12;
           case 13:
                   return bits.bin.bit13;
           case 14:
                   return bits.bin.bit14;
           case 15:
                   return bits.bin.bit15;
           case 16:
                   return bits.bin.bit16;
           case 17:
                   return bits.bin.bit17;
           case 18:
                   return bits.bin.bit18;
           case 19:
                   return bits.bin.bit19;
           case 20:
                   return bits.bin.bit20;
           case 21:
                   return bits.bin.bit21;
           case 22:
                   return bits.bin.bit22;
           case 23:
                   return bits.bin.bit23;
           case 24:
                   return bits.bin.bit24;
           case 25:
                   return bits.bin.bit25;
           case 26:
                   return bits.bin.bit26;
           case 27:
                   return bits.bin.bit26;
           case 28:
                   return bits.bin.bit28;
           case 29:
                   return bits.bin.bit29;
           case 30:
                   return bits.bin.bit30;
           case 31:
                   return bits.bin.bit31;
           default:
                   return 0;
          }
}

/*----------------------------------------------------------------------------*/

int Bits_int::Get_nible(int n)
{
 switch(n){
           case 0:
                  return bits.nib.nible0;
           case 1:
                  return bits.nib.nible1;
           case 2:
                  return bits.nib.nible2;
           case 3:
                  return bits.nib.nible3;
           case 4:
                  return bits.nib.nible4;
           case 5:
                  return bits.nib.nible5;
           case 6:
                  return bits.nib.nible6;
           case 7:
                  return bits.nib.nible7;
           default:
                   return 0;
          }
}

/*----------------------------------------------------------------------------*/

char Bits_int::Get_char(int n)
{
 switch(n){
           case 0:
                  return bits.cha.char0;
           case 1:
                  return bits.cha.char1;
           case 2:
                  return bits.cha.char2;
           case 3:
                  return bits.cha.char3;
           default:
                   return 0;
          }
}

/*----------------------------------------------------------------------------*/

int Bits_int::Get_int(void)
{
 return bits.Int;
}

/*----------------------------------------------------------------------------*/

void Bits_int::neg_bit(int n)
{
 switch(n){
           case 0:
                  bits.bin.bit0=~bits.bin.bit0;
           break;
           case 1:
                  bits.bin.bit1=~bits.bin.bit1;
           break;
           case 2:
                  bits.bin.bit2=~bits.bin.bit2;
           break;
           case 3:
                  bits.bin.bit3=~bits.bin.bit3;
           break;
           case 4:
                  bits.bin.bit4=~bits.bin.bit4;
           break;
           case 5:
                  bits.bin.bit5=~bits.bin.bit5;
           break;
           case 6:
                  bits.bin.bit6=~bits.bin.bit6;
           break;
           case 7:
                  bits.bin.bit7=~bits.bin.bit7;
           break;
           case 8:
                  bits.bin.bit8=~bits.bin.bit8;
           break;
           case 9:
                  bits.bin.bit9=~bits.bin.bit9;
           break;
           case 10:
                   bits.bin.bit10=~bits.bin.bit10;
           break;
           case 11:
                   bits.bin.bit11=~bits.bin.bit11;
           break;
           case 12:
                   bits.bin.bit12=~bits.bin.bit12;
           break;
           case 13:
                   bits.bin.bit13=~bits.bin.bit13;
           break;
           case 14:
                   bits.bin.bit6=~bits.bin.bit14;
           break;
           case 15:
                   bits.bin.bit7=~bits.bin.bit15;
           break;
           case 16:
                   bits.bin.bit0=~bits.bin.bit16;
           break;
           case 17:
                   bits.bin.bit17=~bits.bin.bit17;
           break;
           case 18:
                   bits.bin.bit18=~bits.bin.bit18;
           break;
           case 19:
                   bits.bin.bit19=~bits.bin.bit19;
           break;
           case 20:
                   bits.bin.bit20=~bits.bin.bit20;
           break;
           case 21:
                   bits.bin.bit21=~bits.bin.bit21;
           break;
           case 22:
                   bits.bin.bit22=~bits.bin.bit22;
           break;
           case 23:
                   bits.bin.bit23=~bits.bin.bit23;
           break;
           case 24:
                   bits.bin.bit24=~bits.bin.bit24;
           break;
           case 25:
                   bits.bin.bit25=~bits.bin.bit25;
           break;
           case 26:
                   bits.bin.bit26=~bits.bin.bit26;
           break;
           case 27:
                   bits.bin.bit27=~bits.bin.bit27;
           break;
           case 28:
                   bits.bin.bit28=~bits.bin.bit28;
           break;
           case 29:
                   bits.bin.bit29=~bits.bin.bit29;
           break;
           case 30:
                   bits.bin.bit30=~bits.bin.bit30;
           break;
           case 31:
                   bits.bin.bit31=~bits.bin.bit31;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_int::neg_nib(int n)
{
 switch(n){
           case 0:
                  bits.nib.nible0=~bits.nib.nible0;
           break;
           case 1:
                  bits.nib.nible1=~bits.nib.nible1;
           break;
           case 2:
                  bits.nib.nible2=~bits.nib.nible2;
           break;
           case 3:
                  bits.nib.nible3=~bits.nib.nible3;
           break;
           case 4:
                  bits.nib.nible4=~bits.nib.nible4;
           break;
           case 5:
                  bits.nib.nible5=~bits.nib.nible5;
           break;
           case 6:
                  bits.nib.nible6=~bits.nib.nible6;
           break;
           case 7:
                  bits.nib.nible7=~bits.nib.nible7;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_int::neg_char(int n)
{
 switch(n){
           case 0:
                  bits.cha.char0=~bits.cha.char0;
           break;
           case 1:
                  bits.cha.char1=~bits.cha.char1;
           break;
           case 2:
                  bits.cha.char2=~bits.cha.char2;
           break;
           case 3:
                  bits.cha.char3=~bits.cha.char3;
           break;
          }
}

/*----------------------------------------------------------------------------*/

void Bits_int::neg(void)
{
 bits.Int=~bits.Int;
}

/*----------------------------------------------------------------------------*/

int Hamming(const Bits_int &a,const Bits_int &b)
{
 int i;
 char acc;
 Bits_int Ham;
 Ham.bits.Int=a.bits.Int^b.bits.Int;//Xor
 for(i=0,acc=0;i<32;i++)
    {
     acc+=Ham.Get_bit(i);
    }
 return (int)acc;
}

/*----------------------------------------------------------------------------*/

Bits_int operator+(const Bits_int &a,const Bits_int &b)
{
 Bits_int suma;
 suma.bits.Int=a.bits.Int+b.bits.Int;
 return suma;
}

/*----------------------------------------------------------------------------*/

Bits_int operator-(const Bits_int &a,const Bits_int &b)
{
 Bits_int resta;
 resta.bits.Int=a.bits.Int-b.bits.Int;
 return resta;
}

/*----------------------------------------------------------------------------*/

Bits_int operator*(const Bits_int &a,const Bits_int &b)
{
 Bits_int producto;
 producto.bits.Int=a.bits.Int*b.bits.Int;
 return producto;
}

/*----------------------------------------------------------------------------*/

Bits_int operator/(const Bits_int &a,const Bits_int &b)
{
 Bits_int cociente;
 cociente.bits.Int=a.bits.Int/b.bits.Int;
 return cociente;
}

/*----------------------------------------------------------------------------*/


Bits_int operator+(const int &a,const Bits_int &b)
{
 Bits_int suma;
 suma.bits.Int=a+b.bits.Int;
 return suma;
}

/*----------------------------------------------------------------------------*/

Bits_int operator-(const int &a,const Bits_int &b)
{
 Bits_int resta;
 resta.bits.Int=a-b.bits.Int;
 return resta;
}

/*----------------------------------------------------------------------------*/

Bits_int operator*(const int &a,const Bits_int &b)
{
 Bits_int producto;
 producto.bits.Int=a*b.bits.Int;
 return producto;
}

/*----------------------------------------------------------------------------*/

Bits_int operator/(const int &a,const Bits_int &b)
{
 Bits_int cociente;
 cociente.bits.Int=a/b.bits.Int;
 return cociente;
}

/*----------------------------------------------------------------------------*/

Bits_int operator+(const Bits_int &a,const int &b)
{
 Bits_int suma;
 suma.bits.Int=a.bits.Int+b;
 return suma;
}

/*----------------------------------------------------------------------------*/

Bits_int operator-(const Bits_int &a,const int &b)
{
 Bits_int resta;
 resta.bits.Int=a.bits.Int-b;
 return resta;
}

/*----------------------------------------------------------------------------*/

Bits_int operator*(const Bits_int &a,const int &b)
{
 Bits_int producto;
 producto.bits.Int=a.bits.Int*b;
 return producto;
}

/*----------------------------------------------------------------------------*/

Bits_int operator/(const Bits_int &a,const int &b)
{
 Bits_int cociente;
 cociente.bits.Int=a.bits.Int/b;
 return cociente;
}

/*----------------------------------------------------------------------------*/

Bits_int& Bits_int::operator=(const Bits_int &a)
{
 bits.Int=a.bits.Int;
 return (*this);
}

/*----------------------------------------------------------------------------*/

Bits_int& Bits_int::operator=(const int &a)
{
 bits.Int=a;
 return (*this);
}

/*----------------------------------------------------------------------------*/

int operator==(const Bits_int &a,const Bits_int &b)
{
 return a.bits.Int==b.bits.Int;
}

/*----------------------------------------------------------------------------*/

int operator!=(const Bits_int &a,const Bits_int &b)
{
 return a.bits.Int!=b.bits.Int;
}

/*----------------------------------------------------------------------------*/

ostream& operator<< (ostream &co,const Bits_int &a)
{
 co<<a.bits.Int;
 return co;
}

/*----------------------------------------------------------------------------*/

istream& operator>> (istream &co,Bits_int &a)
{
 co >>a.bits.Int;
 return co;
}

/*----------------------------------------------------------------------------*/

Bits_int& Bits_int::operator++ (int j)
{
 bits.Int++;
 return (*this);
}

/*----------------------------------------------------------------------------*/

Bits_int& Bits_int::operator-- (int j)
{
 bits.Int--;
 return (*this);
}

/*----------------------------------------------------------------------------*/

int Hamming(const char &a,const char &b)
{
 Bits_char tem_a,tem_b;
 tem_a=a;
 tem_b=b;
 return Hamming(tem_a,tem_b);
}

/*----------------------------------------------------------------------------*/

int Hamming(const int &a,const int &b)
{
 Bits_int tem_a,tem_b;
 tem_a=a;
 tem_b=b;
 return Hamming(tem_a,tem_b);
}
