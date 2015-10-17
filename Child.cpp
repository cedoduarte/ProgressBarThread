#include "Child.h"

Child::Child(QWidget *widget)
{
    mWidget = widget;
}

void Child::pack(QTreeWidget *parent)
{
    parent->setItemWidget(this, 0, mWidget);
}

