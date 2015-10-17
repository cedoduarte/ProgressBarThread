#include "Top.h"
#include "Child.h"

Top::Top(const QList<Child *> &children)
{
    mChildren = children;

    const int size = children.size();
    for (int ix = 0; ix < size; ++ix) {
        addChild(children.at(ix));
    }
}
