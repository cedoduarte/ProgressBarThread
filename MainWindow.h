#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class Top;
class PushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionStart_triggered();
    void on_actionQuit_triggered();
private:
    void createChildren(const QVector<int> &miliseconds);
    void packChildren();
    void connectButton(PushButton *button) const;

    Ui::MainWindow *ui;
    Top *mProgressTop;
    Top *mActivateTop;
    bool mStarted;
};

#endif // MAINWINDOW_H
