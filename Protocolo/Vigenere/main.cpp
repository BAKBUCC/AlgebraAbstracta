#include <Vigenere.h>
#include <fstream>

string leer_archivo()
{
    string concatenacion;
    string p;
    ifstream archivo;
    archivo.open("texto.txt", ios::in);
    if(archivo.fail())
    {
        cout<<"no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof())
    {
        archivo>>p;
        concatenacion+=p;
        concatenacion+=" ";
    }
    archivo.close();
    return concatenacion;
}

void aqui_cada_10(string &refString)
{
    for(int unsigned i=1; i<=refString.length()/10; i++)
    {
        refString.insert( 10*i, "AQUI" );
    }
    cout<<"el tama�o es: "<<refString.length()<<endl;
    if (refString.length()%4>0)
    {
        string Ws(4-refString.length()%4,'W');//a 4 - resto =cantidad de espacios que le falta para que el tama�o sea multiplo de 4
        refString+=Ws;
    }
}

int main()
{
    //ingreso de texto plano por archivo
//    string frase=leer_archivo();

    //ingreso de texto plano por interfaz
    string frase("Puedo escribir los versos mas tristes esta noche. "
"Escribir, por ejemplo: La noche esta estrellada, "
"y tiritan, azules, los astros, a lo lejos. "
"El viento de la noche gira en el cielo y canta. "
"Puedo escribir los versos mas tristes esta noche. "
"Yo la quise, y a veces ella tambien me quiso.");

    //para agregar a la frase los "AQUI" descomente la sgte. linea
    //aqui_cada_10(frase);
    string c,d;

    Vigenere emisor(frase);

    cout<<"\nmensaje original: "<<frase<<endl;

    cout<<"\n\n�Qu� alfabeto quiere utilizar?: \n(1)Alf. Numerico \n(2)Codico ASCII\n(3)utilizar de CODIGO: codigo m�s mensaje\n\n";
    int num;
    cin>>num;

    if(num==1)
    {
        c = emisor.codificacion_con_alfNum();
        cout<<"\n\nmensaje codificado con alfabeto numerico: "<<c<<endl;

        Vigenere receptor(c);
        d = receptor.decodificacion_con_alfNum();
        cout<<"\n\nmensaje decodificado con alfabeto numerico: "<<d<<endl;
    }
    if(num==2)
    {
        c = emisor.codificacion_con_alfASCII();
        cout<<"\n\nmensaje codificado con ASCII: "<<c<<endl;

        Vigenere receptor(c);
        d = receptor.decodificacion_con_alfASCII();
        cout<<"\n\nmensaje decodificado con ASCII: "<<d<<endl;
    }
    if(num==3)
    {
        c = emisor.codificacion_Codigo_Mensaje();
        cout<<"\n\nmensaje codificado con codigo m�s mensaje: "<<c<<endl;

        Vigenere receptor(c);
        d = receptor.decodificacion_Codigo_Mensaje();
        cout<<"\n\nmensaje decodificado con codigo m�s mensaje: "<<d<<endl;
    }

    return 0;
}
