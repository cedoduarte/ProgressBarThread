#ifndef MILISECONDSDELEGATE_H
#define MILISECONDSDELEGATE_H

#include <QItemDelegate>

class MilisecondsDelegate : public QItemDelegate
{
public:
    MilisecondsDelegate(QObject *parent = nullptr);
protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &,
                          const QModelIndex &) const override;
    void setEditorData(QWidget *, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &) const override;
};

#endif // MILISECONDSDELEGATE_H
