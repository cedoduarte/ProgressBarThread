#include "ProgressBar.h"
#include "Thread.h"

ProgressBar::ProgressBar(int miliseconds, QWidget *parent)
    : QProgressBar(parent)
{
    mThread = new Thread(miliseconds, this);

    setMaximumWidth(300);

    connect(mThread, &Thread::timeOut, this, [&]() {
        setValue(value() + 1);
        if (value() == 99) {
            setValue(0);
        }
    });
}

void ProgressBar::start()
{
    mThread->start();
}
