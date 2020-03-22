#ifndef MONEY_H
#define MONEY_H
#include <fstream>
#include <QTextEdit>
#include <QLabel>
#include <string>
#include "editfor.h"
class Money{
    public:
    Money();
    Money(long d);
    Money(long d,long c);
    ~Money();
    void SetDolar(long d);
    long GetDolar() const ;
    void SetCent(long c);
    long GetCent() const;//coment
    friend void operator<<(QLineEdit* edit, Money &m1);
    friend void operator>>(Editfor* edit, Money &m1);
        Money operator+ (const Money &m2);
        Money operator- (const Money &m2);
        Money operator* (const Money &m2);
        Money operator/ (const Money &m2);

        bool operator== (const Money& m2);
        bool operator> (const Money& m2);
        bool operator< (const Money& m2);
        static long GetCount();
    std::string get_res();
   static int count;
   private:
   long dolar, cent;






};
//---------------------------------------------------------------------------

#endif // MONEY_H

