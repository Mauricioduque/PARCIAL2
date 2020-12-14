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
    float x=0, y=0;
    float Vxini,Vyini;
    int V0=0;
    int t=0;
    int angle=0;
    for (V0=Vini;V0<=500;V0+=5){
        for (angle=0;angle<90;angle++){
            for (t=0;;t++){
                //Calculo de las velocidades en X y Y de la bala ofensiva
                Vxini=V0*cos(angle*pi/180);
                Vyini=V0*sin(angle*pi/180);
                //Calculo de las posciones en X y Y de la bala ofensiva
                x=Vxini*t;
                y=getYo()+ Vyini*t-(0.5*G*t*t);
                //Se verifica la condicion de impacto sobre el cañon defensivo
                if(sqrt(pow((Xd-x),2)+pow((Yd-y),2))<=getD0()){
                    if(y<0) y=0;
                    //Se guardan los parametros de los disparos efectivos
                    angs[impacto]=angle;
                    vels[impacto]=V0;
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
    if (impacto!=3) cout<<"No impacto sobre el canion Defensivo"<<endl;
}

void canionOfensivo::ImprimirDatos(float angle, float V0, float x, float y, float t)
{
    cout<<endl;
    cout<<"Impacto con un angulo de: "<<angle<<" grados"<<endl;
    cout<<"Impacto con una velocidad incial: "<<V0<<" m/s"<<endl;
    cout<<"Impacto con posicion en X: "<<x <<" m"<<endl;
    cout<<"Impacto con posicion en Y: "<<y <<" m"<<endl;
    cout<<"Con tiempo: "<<t<<" s"<<endl<<endl;
}

void canionOfensivo::contrataque(float Xd, float Yd, float angleD, float Vd)
{
    int impacto=0;
    float C1,C2,L1,L2,R,A,B,C,t1,t,alphaO,Vo,x,y;

    //constantes para determinar el  tiempo en el cual el disparo defensivo,destruye al ofensivo
    C1=Xd+2*Vd*cos(angleD*pi/180);
    L1=Vd*cos(angleD*pi/180)+vels[1]*cos(angs[1]*pi/180);
    C2=Yd-Yo-2*G-2*Vd*sin(angleD*pi/180);
    L2=Vd*sin(angleD*pi/180)+2*G-vels[1]*sin(angs[1]*pi/180);
    R=0.025*Xd;
    A=L1*L1+L2*L2;
    B=2*(C2*L2-C1*L1);
    C=C1*C1+C2*C2-R*R;
    t1=(-B-sqrt(B*B-4*A*C))/(2*A);
    //se definenen los tiempos para qu el contrataque del disparo ofensivo sea efetivo
    if(t1>=3){
        for(impacto=1;impacto<4;impacto++){
            t=3+((t1-3)/(4.0))*impacto;
            alphaO=atan((Yd-Yo+Vd*sin(angleD*pi/180)*(t-2)+G*0.5*(5-2*t))/(Xd-Vd*cos(angleD*pi/180)*(t-2)));
            Vo=(Xd-Vd*cos(angleD*pi/180)*(t-2))/((t-3)*cos(alphaO));
            x=Vo*cos(alphaO)*(t-3);
            y=Yo +Vo*sin(alphaO)*(t-3)-(0.5*G*(t-3)*(t-3));
            ImprimirDatos(alphaO*180/pi,Vo,x,y,t);
         }
    }
    else cout<<"El disparo defensivo no puede destruirse"<<endl;

}
