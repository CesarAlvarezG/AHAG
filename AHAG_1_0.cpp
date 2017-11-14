//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("AHAG_1_0.res");
USEFORM("PRINCIPAL.cpp", Form1);
USEUNIT("Actores.cpp");
USEUNIT("Gui.cpp");
USEUNIT("AG.cpp");
USEUNIT("MIO.h");
USEUNIT("MIO.cpp");
USEUNIT("Individuo.cpp");
USEUNIT("Bits.cpp");
USE("Bits.h", File);
USEUNIT("Tiempo.cpp");
USE("Tiempo.h", File);
USEUNIT("Espacio.cpp");
USE("Espacio.h", File);
USEUNIT("Imprehor.cpp");
USE("Imprehor.h", File);
USEUNIT("Cadenas.cpp");
USE("Cadenas.h", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "AHAG 1.0";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
