#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    PushButton(int id, const QString &title, QWidget *parent);
signals:
    void buttonClicked(int);
private:
    int mId;
};

#endif // PUSHBUTTON_H
