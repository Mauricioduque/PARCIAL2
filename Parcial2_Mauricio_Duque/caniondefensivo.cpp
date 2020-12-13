#include "caniondefensivo.h"

float canionDefensivo::getD() const
{
    return d;
}

void canionDefensivo::setD(float value)
{
    d = value;
}

float canionDefensivo::getXd() const
{
    return Xd;
}

void canionDefensivo::setXd(float value)
{
    Xd = value;
}

float canionDefensivo::getYd() const
{
    return Yd;
}

void canionDefensivo::setYd(float value)
{
    Yd = value;
}

float canionDefensivo::getDd() const
{
    return dd;
}

void canionDefensivo::setDd(float value)
{
    dd = value;
}

canionDefensivo::canionDefensivo()
{

}

void canionDefensivo::disparosDefensivos(float Xo, float Yo, int Vini)
{
    int impacto=0;
    double pi=3.1416;
    float G=9.81;
    float x=0, y=0;
    float Vxini,Vyini;
    int V0=0;
    int t=0;
    int angle=0;
    for (V0=Vini;V0<=500;V0+=5){
        for (angle=0;angle<90;angle++){
            for (t=0;;t++){
                //Calculo de las velocidades en X y Y de la bala defensiva
                Vxini=V0*cos((angle+90)*pi/180);
                Vyini=V0*sin((angle+90)*pi/180)-G*t;
                //Calculo de las posiciones en X y Y de la bala defensiva
                x=Vxini*t;
                y=getYd()+ Vyini*t-(0.5*G*t*t);
                //Se verifica la condicion de impacto sobre el cañon ofensivo
                if(sqrt(pow((Xo-x),2)+pow((Yo-y),2))<=getDd()){
                    if(y<0) y=0;
                    ImprimirDatos(angle,V0,x,y,t);
                    impacto+=1;
                    V0+=30;
                    break;
                }
                if(y<0)break;
            }
            if (impacto==3) break;
        }
        if (impacto==3) break;
    }
    if (impacto!=3){
        cout<<"No impacto sobre el canion Ofensivo"<<endl;
    }
}

void canionDefensivo::ImprimirDatos(int angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"Impacto con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"Impacto con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Impacto con posicion en X: "<<x <<" m"<<endl;
    cout<<"Impacto con posicion en Y: "<<y <<" m"<<endl;
    cout<<"Con tiempo: "<<t<<" s"<<endl<<endl;
}

void canionDefensivo::disparoDefensa(float Yo, float Xd, float Yd, int Vini, int anglei, int V2ini)
{
    int impacto=0;
    double pi=3.1416;
    float G=9.8;
    float x=0, y=0,x2=0,y2=0;
    float Vxini,Vyini,Vxini2,Vyini2;
    int V0=0;
    float t=0;
    int angle=0;
    //Velocidad X con los datos del espia del disparo ofensivo
    Vxini2=V2ini*cos((anglei)*pi/180);
    for (V0=Vini;V0<=500;V0+=5){
        for (angle=0;angle<90;angle++){
            for (t=0;;t++){
                //Velocidad Y con los datos del espia del disparo ofensivo
                Vyini2=V2ini*sin((anglei)*pi/180)-G*t;
                //Velocidades para generar disparos defensivos
                Vxini=V0*cos((angle+90)*pi/180);
                Vyini=V0*sin((angle+90)*pi/180)-G*t;
                //Coordenadas disparo ofensivo
                x2=Vxini2*(t+2.5);
                y2=Yo+ Vyini2*(t+2.5)-(0.5*G*(t+2.5)*(t+2.5));
                //coordenandas disparo defensivo
                x=Xd+Vxini*t;
                y=Yd+ Vyini*t-(0.5*G*t*t);
                if(sqrt(pow((x2-x),2)+pow((y2-y),2))<=getDd()){
                    if(y<0) y=0;
                    cout<<"la bala ofensiva, segun los parametros dados por el espia fue destruida con:"<<endl;
                    ImprimirDatos(anglei,V2ini,x2,y2,t+2.5);
                    cout<<"-------------------------"<<endl<<endl;
                    ImprimirDatos(angle,V0,x,y,t);
                    impacto+=1;
                    V0+=30;
                    break;
                }
                if(y<0)break;
            }
            if (impacto==3) break;
        }
        if (impacto==3) break;
    }
    if (impacto!=3){
        cout<<"Con los parametros dados, no se impacto en la bala ofensiva"<<endl;
    }
}
