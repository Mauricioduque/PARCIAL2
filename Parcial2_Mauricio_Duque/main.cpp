#include "caniondefensivo.h"
#include "canionofensivo.h"

int main()
{
    canionOfensivo disOfensivo;
    canionDefensivo disDefensivo;
    float Vini,VinO,angleO;
    int a;
    float d,Yo,Yd;
    cout<<"-------SISTEMA DE SIMULACION DE ATAQUES--------"<<endl<<endl;
    cout<<"Ingrese la condiciones iniciales"<<endl;
    cout<<"Altura del canion Ofensivo (m): ";
    cin>>Yo;
    disOfensivo.setYo(Yo);
    cout<<"Distancia de separacion de los caniones (m): ";
    cin>>d;
    disOfensivo.setD(d);
    disDefensivo.setXd(d);
    disOfensivo.setD0(0.05*d);
    disDefensivo.setDd(0.025*d);
    cout<<"Altura del canion Defensivo (m): ";
    cin>>Yd;
    disDefensivo.setYd(Yd);

    while(true){
        cout<<"1.Para generar disparos ofensivos"<<endl;
        cout<<"2.Para generar disparos defensivos"<<endl;
        cout<<"3.Para generar disparos defensivos, dado un disparo ofensivo"<<endl;
        cout<<"4.Para generar disparos defensivos,dado un disparo ofensivo sin afectar la integridad de los caniones"<<endl;
        cout<<"5.Para realizar un contraataque ofensivo"<<endl;
        cout<<"Ingrese la opcion que desea realizar:";
        cin>>a;
        cout<<endl;

        switch (a) {
         case 1:
            cout<<"Ingrese Velocidad incial de prueba (m/s): ";
            cin>>Vini;
            cout<<"Los diferentes parametros, para que el disparo sea efectivo"<<endl;
            disOfensivo.disparosOfensivos(d,Yd,Vini);
         break;
         case 2:
            cout<<"Ingrese Velocidad incial de prueba (m/s): ";
            cin>>Vini;
            cout<<"Los diferentes parametros, para que el disparo sea efectivo"<<endl;
            disDefensivo.disparosDefensivos(0,Yo,Vini);
         break;
         case 3:
            cout<<"Ingrese los parametros del espia"<<endl;
            cout<<"Velocidad incial de la bala ofensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala ofensiva(grados): ";
            cin>>angleO;
            disDefensivo.disparoDefensa(Yo,angleO,VinO);
         break;
         case 4:
            cout<<"Ingrese los parametros del espia"<<endl;
            cout<<"Velocidad incial de la bala ofensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala ofensiva(grados): ";
            cin>>angleO;
            disDefensivo.disparoSinAfectacion(Yo,angleO,VinO);
         break;
         case 5:
            cout<<"Ingrese los parametros del espia"<<endl;
            cout<<"Velocidad incial de la bala defensiva(m/s):";
            cin>>VinO;
            cout<<"Angulo de la bala defensiva(grados): ";
            cin>>angleO;
            disOfensivo.contrataque(d,Yd,angleO,VinO);
        break;

        }

    }
    return 0;
}
