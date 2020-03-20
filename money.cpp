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
    return Money(this->dolar+m2.dolar,
                   this->cent+m2.cent);
}

Money Money::operator- (const Money &m2)
{
    return Money(this->dolar - m2.dolar,
                   this->cent - m2.cent);
}

Money Money::operator* (const Money &m2)
{
    return Money(this->dolar * m2.dolar - this->cent * m2.cent,
                   this->dolar * m2.cent + this->cent * m2.dolar);
}
Money Money::operator/ (const Money &m2)
{
    return Money((this->dolar * m2.dolar + this->cent * m2.cent)/
                   (m2.dolar*m2.dolar + m2.cent * m2.cent),
                   (this->cent * m2.dolar - this->dolar * m2.cent)/
                   (m2.dolar * m2.dolar + m2.cent * m2.cent));
}



void operator<<(QLabel*label,Money &m1)
{
    label->setText(QString::number(m1.dolar)+"+("+ QString::number(op.imagine) + ")i");
}

void operator>>(MyLineEdit * edit, Money &m1)
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


std::string Money::get_res()
{
    return std::to_string(this->dolar) + "," + std::to_string(this->cent);
}

