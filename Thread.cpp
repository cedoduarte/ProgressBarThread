#include "Thread.h"

Thread::Thread(int miliseconds, QObject *parent)
    : QThread(parent)
{
    mMiliseconds = miliseconds;
}

void Thread::run()
{
    while (true) {
        emit timeOut();
        msleep(mMiliseconds);
    }
}

