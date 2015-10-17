#include "PushButton.h"

PushButton::PushButton(int id, const QString &title, QWidget *parent)
    : QPushButton(title, parent)
{
    mId = id;

    setMaximumWidth(100);

    connect(this, &PushButton::clicked, [&]() {
        emit buttonClicked(mId);
    });
}

