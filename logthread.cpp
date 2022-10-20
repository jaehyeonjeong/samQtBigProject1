#include "logthread.h""

#include <QTreeWidgetItem>
#include <QFile>
#include <QDateTime>

LogThread::LogThread(QObject *parent)
    : QThread{parent}
{

}

void LogThread::run()
{
    Q_FOREVER {
        if(itemList.count() > 0) {
            QString format = "yyyyMMdd_hhmmss";
            QString filename = QString("log_%1.txt").arg(QDateTime::currentDateTime().toString(format));
            QFile file(filename);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

            QTextStream out(&file);
            foreach(auto item, itemList) {
                out << item->text(0) << ", ";
                out << item->text(1) << ", ";
                out << item->text(2) << ", ";
                out << item->text(3) << ", ";
                out << item->text(4) << ", ";
                out << item->text(5) << "\n";
            }
            file.close();
        }
        sleep(60);      // 1분마다 저장
    }
}

void LogThread::appendData(QTreeWidgetItem* item)
{
    itemList.append(item);
}
