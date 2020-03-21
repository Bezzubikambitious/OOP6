#ifndef EDITFOR_H
#define EDITFOR_H
#include <QLineEdit>

class Editfor : public QLineEdit
{
    Q_OBJECT
public:
    Editfor(QWidget *parent = nullptr);
    int ID;
};

#endif // EDITFOR_H


