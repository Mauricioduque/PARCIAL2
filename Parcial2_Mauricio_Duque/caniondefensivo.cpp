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
    float G=9.8;
    float x=0, y=0;
    float Vxini,Vyini;
    int V0=0;
    int t=0;
    int angle=0;
    for (V0=Vini;;V0+=5){
        for (angle=0;angle<90;angle++){
            Vxini=V0*cos((angle+90)*pi/180);
            for (t=0;;t++){
                Vyini=V0*sin((angle+90)*pi/180)-G*t;
                x=Vxini*t;
                y=getYd()+ Vyini*t-(0.5*G*t*t);
                if(sqrt(pow((Xo-x),2)+pow((Yo-y),2))<=getDd()){
                    if(y<0) y=0;
                    ImprimirDatos(angle,V0,x,y,t);
                    impacto+=1;
                    V0+=50;
                    break;
                }
                if(y<0)break;
            }
            if (impacto==3) break;
        }
        if (impacto==3) break;
    }
    if (impacto!=3){
        cout<<"No impacto en los disparos esperados"<<endl;
    }
}

void canionDefensivo::ImprimirDatos(int angle, float V0, float x, float y, float t)
{
    cout<<"Impacto con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"Impacto con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Impacto con posicion en X: "<<x <<" m"<<endl;
    cout<<"Impacto con posicion en Y: "<<y <<" m"<<endl;
    cout<<"Con tiempo: "<<t<<" s"<<endl<<endl;
}
