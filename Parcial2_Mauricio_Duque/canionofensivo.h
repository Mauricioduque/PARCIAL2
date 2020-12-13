#ifndef CANIONOFENSIVO_H
#define CANIONOFENSIVO_H
#include "caniondefensivo.h"

class canionOfensivo
{
private:
    float d=0;
    float Xo=0;
    float Yo=0;
    float d0=0.05*d;
    float angs[3]={};
    float vels[3]={};
    float pi=3.1416;
    float G=9.81;

public:
    canionOfensivo();
    void disparosOfensivos(float Xd,float Yd,int Vini);
    void ImprimirDatos(float angle,float V0,float x,float y,float t);
    void contrataque(float Xd,float Yd,float angleD,float Vd);

    float getD() const;
    void setD(float value);

    float getXo() const;
    void setXo(float value);

    float getYo() const;
    void setYo(float value);

    float getD0() const;
    void setD0(float value);


};

#endif // CANIONOFENSIVO_H

