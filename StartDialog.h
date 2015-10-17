#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui
{
class StartDialog;
}

class QStandardItemModel;

class StartDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();
    QVector<int> vectorOfProgresses() const { return mVectorOfProgresses; }
private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::StartDialog *ui;
    QStandardItemModel *mModel;
    QVector<int> mVectorOfProgresses;
};

#endif // STARTDIALOG_H
