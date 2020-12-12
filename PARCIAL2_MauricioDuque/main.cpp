#include "caninodefensivo.h"
#include "canionofensivo.h"

int main()
{
    canionOfensivo disOfensivo;
    canionDefensivo disDefensivo;
    int Vini,a;
    float d,Xo,Yo,Yd;
    cout<<"Ingrese la condiciones iniciales"<<endl;
    cout<<"Posicion X del canion Ofensivo: ";
    cin>>Xo;
    disOfensivo.setXo(Xo);
    cout<<"Posicion Y del canion Ofensivo: ";
    cin>>Yo;
    disOfensivo.setYo(Yo);
    cout<<"Ingrese la distancia de separacion de los caniones: ";
    cin>>d;
    disOfensivo.setD(d);
    disDefensivo.setXd(d);
    disOfensivo.setD0(0.05*d);
    disDefensivo.setDd(0.025*d);
    cout<<"Posicion Y del canion Defensivo: ";
    cin>>Yd;
    disDefensivo.setYd(Yd);

    while(true){
        cout<<"Ingrese la opcion que desea realizar:";
        cin>>a;
        cout<<"Ingrese Velocidad incial de prueba: ";
        cin>>Vini;
        cout<<endl<<endl;

        switch (a) {
         case 1:
            disOfensivo.disparosOfensivos(d,20,Vini);
         break;
         case 2:
            disDefensivo.disparosDefensivos(0,100,Vini);
         break;
        }

    }



    return 0;
}
