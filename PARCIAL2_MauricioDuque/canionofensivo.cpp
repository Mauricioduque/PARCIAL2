#include "canionofensivo.h"

float canionOfensivo::getD() const
{
    return d;
}

void canionOfensivo::setD(float value)
{
    d = value;
}


float canionOfensivo::getXo() const
{
    return Xo;
}

void canionOfensivo::setXo(float value)
{
    Xo = value;
}

float canionOfensivo::getYo() const
{
    return Yo;
}

void canionOfensivo::setYo(float value)
{
    Yo = value;
}

float canionOfensivo::getD0() const
{
    return d0;
}

void canionOfensivo::setD0(float value)
{
    d0 = value;
}

canionOfensivo::canionOfensivo()
{

}

void canionOfensivo::disparosOfensivos(float Xd, float Yd, int Vini)
{
    int impacto=0;
    double pi=3.1416;
    float G=9.81;
    float x=0, y=0;
    float Vxini,Vyini;
    int V0=0;
    int t=0;
    int angle=0;
    for (V0=Vini;;V0+=5){
        for (angle=0;angle<90;angle++){
            Vxini=V0*cos(angle*pi/180);
            for (t=0;;t++){
                Vyini=V0*sin(angle*pi/180)-G*t;
                x=Vxini*t;
                y=getYo()+ Vyini*t-(0.5*G*t*t);
                if(sqrt(pow((Xd-x),2)+pow((Yd-y),2))<=getD0()){
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
        cout<<"No impacto en los disparos esperados"<<endl;
    }
}

void canionOfensivo::ImprimirDatos(int angle, float V0, float x, float y, float t)
{
    cout<<"Impacto con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"Impacto con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Impacto con posicion en X: "<<x <<" m"<<endl;
    cout<<"Impacto con posicion en Y: "<<y <<" m"<<endl;
    cout<<"Con tiempo: "<<t<<" s"<<endl<<endl;
}






