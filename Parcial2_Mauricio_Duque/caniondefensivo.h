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
    float pi=3.1416;
    float G=9.81;
    float angs[3]={};
    float vels[3]={};




public:
    canionDefensivo();
    void disparosDefensivos(float Xo,float Yo,int Vini);
    void ImprimirDatos(float angle,float V0,float x,float y,float t);
    void disparoDefensa(float Yo,int anglei, int V2ini);
    void disparoSinAfectacion(float Yo,int anglei, int V2ini);
    float distanciaEuclidiana(float x1,float x2,float y1,float y2);



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
