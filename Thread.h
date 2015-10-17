#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(int miliseconds, QObject *parent = nullptr);
signals:
    void timeOut();
protected:
    void run() override;
private:
    int mMiliseconds;
};

#endif // THREAD_H
