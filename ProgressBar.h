#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QProgressBar>

class Thread;

class ProgressBar : public QProgressBar
{
public:
    ProgressBar(int miliseconds, QWidget *parent);
    void start();
private:
    Thread *mThread;
};

#endif // PROGRESSBAR_H
