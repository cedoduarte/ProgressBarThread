#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "StartDialog.h"
#include "ProgressBar.h"
#include "PushButton.h"
#include "Child.h"
#include "Top.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mStarted = false;

    setWindowTitle("Progresses");
    ui->treeWidget->setHeaderLabel("Threads");
    setCentralWidget(ui->treeWidget);
    resize(width(), height()*4/3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createChildren(const QVector<int> &miliseconds)
{
    QList<Child *> progressChildren;
    QList<Child *> activateChildren;
    const int size = miliseconds.size();
    for (int ix = 0; ix < size; ++ix) {
        progressChildren.append(new Child(new ProgressBar
                                          (miliseconds[ix], this)));
        activateChildren.append(new Child(new PushButton
                                          (ix, "Activate", this)));
    }
    mProgressTop = new Top(progressChildren);
    mActivateTop = new Top(activateChildren);
}

void MainWindow::packChildren()
{
    ui->treeWidget->addTopLevelItem(mProgressTop);
    ui->treeWidget->addTopLevelItem(mActivateTop);
    const int size = mProgressTop->childCount();
    for (int ix = 0; ix < size; ++ix) {
        mProgressTop->childByIndex(ix)->pack(ui->treeWidget);
        mActivateTop->childByIndex(ix)->pack(ui->treeWidget);
        connectButton(static_cast<PushButton *>
                      (mActivateTop->childByIndex(ix)->widget()));
    }
}

void MainWindow::connectButton(PushButton *button) const
{
    connect(button, &PushButton::buttonClicked, [&](int id) {
        auto progress = static_cast<ProgressBar *>
                (mProgressTop->childByIndex(id)->widget());
        progress->start();
    });
}

void MainWindow::on_actionStart_triggered()
{
    if (mStarted) {
        return;
    }
    StartDialog d(this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    mStarted = true;
    createChildren(d.vectorOfProgresses());
    packChildren();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
