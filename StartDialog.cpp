#include "StartDialog.h"
#include "ui_StartDialog.h"
#include "ProgressDelegate.h"
#include "MilisecondsDelegate.h"
#include <QStandardItemModel>

StartDialog::StartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    setWindowTitle("Start");
    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    mModel->setHorizontalHeaderLabels({ "Progress", "Miliseconds" });
    ui->tableView->setItemDelegateForColumn(0, new ProgressDelegate(this));
    ui->tableView->setItemDelegateForColumn(1, new MilisecondsDelegate(this));
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_spinBox_valueChanged(int rowCount)
{
    mModel->setRowCount(rowCount);
    mModel->setItem(rowCount-1, new QStandardItem(QString::number(rowCount)));
}

void StartDialog::on_buttonBox_accepted()
{
    const int size = mModel->rowCount();
    if (size == 0 || mModel->item(0, 1) == nullptr) {
        return;
    }
    for (int ix = 0; ix < size; ++ix) {
        mVectorOfProgresses.append(mModel->item(ix, 1)->text().toInt());
    }
    accept();
}

void StartDialog::on_buttonBox_rejected()
{
    reject();
}
