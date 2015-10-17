#ifndef TOP_H
#define TOP_H

#include <QTreeWidgetItem>

class Child;

class Top : public QTreeWidgetItem
{
public:
    Top(const QList<Child *> &children);
    Child *childByIndex(int idx) const { return mChildren.at(idx); }
private:
    QList<Child *> mChildren;
};

#endif // TOP_H
