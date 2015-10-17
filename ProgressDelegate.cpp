#include "ProgressDelegate.h"

ProgressDelegate::ProgressDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *ProgressDelegate::createEditor(QWidget *, const QStyleOptionViewItem &,
                                        const QModelIndex &) const
{
    return nullptr;
}

void ProgressDelegate::setEditorData(QWidget *, const QModelIndex &) const
{
}

void ProgressDelegate::setModelData(QWidget *, QAbstractItemModel *,
                                    const QModelIndex &) const
{
}

void ProgressDelegate::updateEditorGeometry(QWidget *,
                                            const QStyleOptionViewItem &,
                                            const QModelIndex &) const
{
}

