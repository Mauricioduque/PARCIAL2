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
    float pi=3.1416;
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
                Vyini=V0*sin((angle+90)*pi/180);
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
    if (impacto!=3) cout<<"No impacto sobre el canion Ofensivo"<<endl;
}

void canionDefensivo::ImprimirDatos(float angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"Impacto con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"Impacto con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Impacto con posicion en X: "<<x <<" m"<<endl;
    cout<<"Impacto con posicion en Y: "<<y <<" m"<<endl;
    cout<<"Con tiempo: "<<t<<" s"<<endl<<endl;
}

void canionDefensivo::disparoDefensa(float Yo, float Xd, float Yd, int anglei, int V2ini)
{
    float pi=3.1416;
    float G=9.8;
    float x=0, y=0;
    float t=0,thetaD,Vd;
    for(float t2=0.5;t2<1;t2+=0.2){
        t=(Xd-0.05*Xd)*t2/(V2ini*cos((anglei)*pi/180));
        thetaD=atan((Yo-Yd+V2ini*t*sin((anglei)*pi/180)-2*G*t+2*G)/(Xd-V2ini*t*cos((anglei)*pi/180)));
        Vd=((Yo-Yd+V2ini*t*sin((anglei)*pi/180))-2*G*t+2*G)/((t-2)*sin(thetaD));
        x=V2ini*cos((anglei)*pi/180)*t;
        y=Yo +V2ini*sin((anglei)*pi/180)*t-(0.5*G*t*t);
        ImprimirDatos(thetaD*180/pi,Vd,x,y,t);
    }
}

void canionDefensivo::disparoSinAfectacion(float Yo, float Xd, float Yd, int anglei, int V2ini)
{
    float pi=3.1416;
    float G=9.8;
    float x=0, y=0;
    float t=0,thetaD,Vd,tfinal;
    float t2=0.5;
    for(;t2<1;t2+=0.1){
        t=(Xd-0.05*Xd)*t2/(V2ini*cos((anglei)*pi/180));
        thetaD=atan((Yo-Yd+V2ini*t*sin((anglei)*pi/180)-2*G*t+2*G)/(Xd-V2ini*t*cos((anglei)*pi/180)));
        Vd=((Yo-Yd+V2ini*t*sin((anglei)*pi/180))-2*G*t+2*G)/((t-2)*sin(thetaD));
        x=V2ini*cos((anglei)*pi/180)*t;
        y=Yo +V2ini*sin((anglei)*pi/180)*t-(0.5*G*t*t);
        tfinal=2+(Vd*sin(thetaD)+sqrt(Vd*sin(thetaD)*Vd*sin(thetaD)+2*G*Yd))/G;
        if(tfinal>=(2+(Xd-Xd*0.025)/(Vd*cos(thetaD)))){
            t2-=0.05;
        }
        else ImprimirDatos(thetaD*180/pi,Vd,x,y,t);
    }
}
