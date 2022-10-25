#ifndef LOGTHREAD_H
#define LOGTHREAD_H

#include <QList>
#include <QThread>

class QTreeWidgetItem;

class LogThread : public QThread    //QThread 상속
{
    Q_OBJECT
public:
    explicit LogThread(QObject *parent = nullptr); //생성자 초기화

signals:
    void send(int data);        //

public slots:
    void appendData(QTreeWidgetItem*);

    void saveData();

private:
    void run();

    QList<QTreeWidgetItem*> itemList;

};

#endif // LOGTHREAD_H
