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
    float x=0, y=0;
    float Vxini,Vyini;
    int V0=0;
    int t=0;
    int angle=0;
    for (V0=Vini;V0<=500;V0+=5){
        for (angle=0;angle<90;angle++){
            for (t=0;;t++){
                //Calculo de las velocidades en X y Y de la bala defensiva
                Vxini=V0*cos((angle)*pi/180);
                Vyini=V0*sin((angle)*pi/180);
                //Calculo de las posiciones en X y Y de la bala defensiva
                x=Xd-Vxini*t;
                y=Yd+ Vyini*t-(0.5*G*t*t);
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
    int impacto;
    float x=0, y=0,t2;
    float t=0,thetaD,Vd;
    float t1=(2*V2ini*cos((anglei)*pi/180))/(Xd-0.05*Xd);
    x=V2ini*cos((anglei)*pi/180)*2;
    y=Yo +V2ini*sin((anglei)*pi/180)*2-(0.5*G*2*2);
    //se comprueba si en t=2 la bala ya tiene el radio de explosion cerca del objetivo
    if(distanciaEuclidiana(Xd,x,Yd,y)>Xd*0.05){
        for(impacto=1;impacto<4;impacto++){
            t2=t1+((1-t1)/4.0)*impacto;
            t=(Xd-0.05*Xd)*t2/(V2ini*cos((anglei)*pi/180));
            thetaD=atan((Yo-Yd+V2ini*t*sin((anglei)*pi/180)-2*G*t+2*G)/(Xd-V2ini*t*cos((anglei)*pi/180)));
            Vd=((Yo-Yd+V2ini*t*sin((anglei)*pi/180))-2*G*t+2*G)/((t-2)*sin(thetaD));
            x=V2ini*cos((anglei)*pi/180)*t;
            y=Yo +V2ini*sin((anglei)*pi/180)*t-(0.5*G*t*t);
            ImprimirDatos(thetaD*180/pi,Vd,x,y,t);
            }
    }
}

void canionDefensivo::disparoSinAfectacion(float Yo, float Xd, float Yd, int anglei, int V2ini)
{
    int impacto;
    float x=0, y=0,t2;
    float t=0,thetaD,Vd,tfinal;
    //tamaño del intervalo donde se puede disparar
    float t1=(2*V2ini*cos((anglei)*pi/180))/(Xd-0.05*Xd);
    x=V2ini*cos((anglei)*pi/180)*2;
    y=Yo +V2ini*sin((anglei)*pi/180)*2-(0.5*G*2*2);
    //se comprueba si en t=2 la bala ya tiene el radio de explosion cerca del objetivo
    if(distanciaEuclidiana(Xd,x,Yd,y)>Xd*0.05){
        for(impacto=1;impacto<4;impacto++){
            //se particiona los tiempos para disparar simetricamente
            t2=t1+((1-t1)/4.0)*impacto;
            //se calcula el tiempo cuando chocan las balas teniendo el cuendo el radio de destruccion
            t=(Xd-0.05*Xd)*t2/(V2ini*cos((anglei)*pi/180));
            //se calcula la velocidad y el angulo para el cual se impacta en la bala ofensiva
            //a partir de las ec, cinematicas xo=xd y yd=yo
            thetaD=atan((Yo-Yd+V2ini*t*sin((anglei)*pi/180)-2*G*t+2*G)/(Xd-V2ini*t*cos((anglei)*pi/180)));
            Vd=((Yo-Yd+V2ini*t*sin((anglei)*pi/180))-2*G*t+2*G)/((t-2)*sin(thetaD));
            x=V2ini*cos((anglei)*pi/180)*t;
            y=Yo +V2ini*sin((anglei)*pi/180)*t-(0.5*G*t*t);
            //tiempo (con el retraso) al cual la posicion en y de la bala defensiva es cero
            tfinal=2+(Vd*sin(thetaD)+sqrt(Vd*sin(thetaD)*Vd*sin(thetaD)+2*G*Yd))/G;
            if(tfinal>=(2+(Xd-Xd*0.025)/(Vd*cos(thetaD)))){
                t1=t1*1.5;
                impacto--;
            }
            else {
                t1=t1=(2*V2ini*cos((anglei)*pi/180))/(Xd-0.05*Xd);
                ImprimirDatos(thetaD*180/pi,Vd,x,y,t);
            }
        }
    }
    else cout<<"No es posible destruir la bala ofensiva"<<endl;

}

float canionDefensivo::distanciaEuclidiana(float x1, float x2, float y1, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


