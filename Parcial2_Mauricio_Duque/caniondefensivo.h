#ifndef CANIONDEFENSIVO_H
#define CANIONDEFENSIVO_H
#include <math.h>
#include <iostream>
#include "canionofensivo.h"

using namespace std;

class canionDefensivo
{

private:
    float d=0;
    float Xd=d;
    float Yd=0;
    float dd=0.025*d;




public:
    canionDefensivo();
    void disparosDefensivos(float Xo,float Yo,int Vini);
    void ImprimirDatos(float angle,float V0,float x,float y,float t);
    void disparoDefensa(float Yo,float Xd,float Yd,int anglei, int V2ini);
    void disparoSinAfectacion(float Yo,float Xd,float Yd,int anglei, int V2ini);



    float getD() const;
    void setD(float value);
    float getXd() const;
    void setXd(float value);
    float getYd() const;
    void setYd(float value);
    float getDd() const;
    void setDd(float value);
};

#endif // CANIONDEFENSIVO_H
