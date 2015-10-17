#include "MilisecondsDelegate.h"
#include <QSpinBox>

MilisecondsDelegate::MilisecondsDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *MilisecondsDelegate::createEditor(QWidget *parent,
                                           const QStyleOptionViewItem &,
                                           const QModelIndex &) const
{
    auto spinBox = new QSpinBox(parent);
    spinBox->setMinimum(10);
    spinBox->setMaximum(INT_MAX);
    return spinBox;
}

void MilisecondsDelegate::setEditorData(QWidget *editor,
                                        const QModelIndex &index) const
{
    auto spinBox = static_cast<QSpinBox *>(editor);
    const int data = index.data().toInt();
    spinBox->setValue(data == 0 ? 10 : data);
}

void MilisecondsDelegate::setModelData(QWidget *editor,
                                       QAbstractItemModel *model,
                                       const QModelIndex &index) const
{
    auto spinBox = static_cast<QSpinBox *>(editor);
    model->setData(index, spinBox->value());
}

void MilisecondsDelegate::updateEditorGeometry
    (QWidget *editor, const QStyleOptionViewItem &option,
     const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}

