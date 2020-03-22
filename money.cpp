#include "mainwindow.h"
#include "money.h"
#include <QtMath>
#include <QString>
int Money::count = 0;
Money::Money()
{
    dolar=0;
    cent=0;
    ++count;
}

Money::Money(long d){
        dolar=d;
        cent=0;
        ++count;
}
Money::Money(long d,long c){
        dolar=d;
        cent=c;
        ++count;
}
Money::~Money()
{
    --count;
}
long Money::GetCount()
{
    return count;
}

void Money::SetDolar(long d){
        dolar=d;
}
void Money::SetCent(long c){
        cent=c;
}


long Money::GetDolar() const{
      return dolar;
}
long Money::GetCent() const{
      return cent;
}

Money Money::operator+ (const Money &m2)
{
    long cent=this->GetCent()+m2.GetCent();
    long dolars=this->GetDolar()+m2.GetDolar();
    while (cent>=100)
    {// це якщо центів введуть багато
        dolars++;
        cent -= 100;
    }
   return Money(dolars, cent);
}

Money Money::operator- (const Money &m2)
{
    double param, fractpart, intpart;
    Money tmp;
    param=(1.0*this->dolar+0.01*this->cent)-(1.0*m2.dolar+0.01*m2.cent);
    fractpart = modf (param , &intpart);
    tmp.SetDolar((long)intpart);
    tmp.SetCent((long)(fractpart*100));
    return tmp;

}

Money Money::operator* (const Money &m2)
{
    double param, fractpart, intpart;
    Money tmp;
    param=(1.0*this->dolar+0.01*this->cent)*(1.0*m2.dolar+0.01*m2.cent);
    fractpart = modf (param , &intpart);
    tmp.SetDolar((long)intpart);
    tmp.SetCent((long)(fractpart*100));
    return tmp;

}
Money Money::operator/ (const Money &m2)
{
    double param, fractpart, intpart;
    Money tmp;
    param=(1.0*this->dolar+0.01*this->cent)/(1.0*m2.dolar+0.01*m2.cent);
    fractpart = modf (param , &intpart);
    tmp.SetDolar((long)intpart);
    tmp.SetCent((long)(fractpart*100));
    return tmp;

}

std::string Money::get_res()
{
    return std::to_string(this->dolar) + "," + std::to_string(this->cent);
}

//тутка

void operator<<(QLineEdit*edit,Money &m1)
{
    edit->setText(QString::number(m1.GetDolar())+","+ QString::number(m1.GetCent()));
}

void operator>>(Editfor * edit, Money &m1)
{
    if(edit->ID)
    {
        m1.SetCent(edit->text().toDouble());
    }
    else
    {
        m1.SetDolar(edit->text().toDouble());
    }
}


