#ifndef PROGRESSDELEGATE_H
#define PROGRESSDELEGATE_H

#include <QItemDelegate>

class ProgressDelegate : public QItemDelegate
{
public:
    ProgressDelegate(QObject *parent = nullptr);
protected:
    QWidget *createEditor(QWidget *, const QStyleOptionViewItem &,
                          const QModelIndex &) const override;
    void setEditorData(QWidget *, const QModelIndex &) const override;
    void setModelData(QWidget *, QAbstractItemModel *,
                      const QModelIndex &) const override;
    void updateEditorGeometry(QWidget *, const QStyleOptionViewItem &,
                              const QModelIndex &) const override;
};

#endif // PROGRESSDELEGATE_H
