#ifndef CHILD_H
#define CHILD_H

#include <QTreeWidgetItem>

class Child : public QTreeWidgetItem
{
public:
    Child(QWidget *widget);
    void pack(QTreeWidget *parent);
    QWidget *widget() const { return mWidget; }
private:
    QWidget *mWidget;
};

#endif // CHILD_H
