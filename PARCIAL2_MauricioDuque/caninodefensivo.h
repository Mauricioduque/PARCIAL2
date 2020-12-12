#ifndef CANINODEFENSIVO_H
#define CANINODEFENSIVO_H
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
    void ImprimirDatos(int angle,float V0,float x,float y,float t);



    float getD() const;
    void setD(float value);
    float getXd() const;
    void setXd(float value);
    float getYd() const;
    void setYd(float value);
    float getDd() const;
    void setDd(float value);
};

#endif // CANINODEFENSIVO_H
