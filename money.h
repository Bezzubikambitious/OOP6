#ifndef MONEY_H
#define MONEY_H
#include <fstream>
#include <QTextEdit>
#include <QLabel>
#include <string>
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
    friend void operator<<(QLabel* label, Money &m1);
    friend void operator>>(MyLineEdit* edit, Money &m1);
        Money operator+ (const Money &m2);
        Money operator- (const Money &m2);
        Money operator* (const long num);
        Money operator/ (const long num);

        bool operator== (const Money& m2);
        bool operator> (const Money& m2);
        bool operator< (const Money& m2);

   static int count;
   private:
   long dolar, cent;






};
//---------------------------------------------------------------------------

#endif // MONEY_H

