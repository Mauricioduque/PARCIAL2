#include "caniondefensivo.h"
#include "canionofensivo.h"

int main()
{
    canionOfensivo disOfensivo;
    canionDefensivo disDefensivo;
    int Vini,VinO,angleO,a;
    float d,Yo,Yd;
    cout<<"Ingrese la condiciones iniciales"<<endl;
    cout<<"Altura del canion Ofensivo (m): ";
    cin>>Yo;
    disOfensivo.setYo(Yo);
    cout<<"Ingrese la distancia de separacion de los caniones (m): ";
    cin>>d;
    disOfensivo.setD(d);
    disDefensivo.setXd(d);
    disOfensivo.setD0(0.05*d);
    disDefensivo.setDd(0.025*d);
    cout<<"Altura del canion Defensivo (m): ";
    cin>>Yd;
    disDefensivo.setYd(Yd);

    while(true){
        cout<<"Ingrese la opcion que desea realizar:";
        cin>>a;
        cout<<"Ingrese Velocidad incial de prueba (m/s): ";
        cin>>Vini;
        cout<<endl<<endl;

        switch (a) {
         case 1:
            cout<<"Los diferentes parametros, para que el disparo sea efectivo"<<endl;
            disOfensivo.disparosOfensivos(d,Yd,Vini);
         break;
         case 2:
            cout<<"Los diferentes parametros, para que el disparo sea efectivo"<<endl;
            disDefensivo.disparosDefensivos(0,Yo,Vini);
         break;
         case 3:
            cout<<"Ingrese los parametros del espia"<<endl;
            cout<<"Velocidad incial de la bala ofensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala ofensiva(grados): ";
            cin>>angleO;
            disDefensivo.disparoDefensa(Yo,d,Yd,Vini,angleO,VinO);
         break;
        case 4:
            break;
        }

    }



    return 0;
}
