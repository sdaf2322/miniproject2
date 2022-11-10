#include "logthread.h"

#include <QTreeWidgetItem>
#include <QFile>
#include <QDateTime>

LogThread::LogThread(QObject *parent)                                                       /*스레드 생성자*/
    : QThread{parent}
{
    QString format = "yyyyMMdd_hhmmss";                                                     // 날짜 표시할 양식
    filename = QString("log_%1.txt").arg(QDateTime::currentDateTime().toString(format));    // 양식에 맞춰 현재 시간을 저장
}

void LogThread::run()                                                                       /*run 함수*/
{
    Q_FOREVER {
        saveData();
        sleep(60);                                                                          // 1분마다 저장
    }
}

void LogThread::appendData(QTreeWidgetItem* item)                                           /*appendData 슬롯*/
{
    itemList.append(item);                                                                  // 받은 정보를 treeWidget 리스트에 추가
}

void LogThread::saveData()                                                                  /*saveData 슬롯*/
{
    if(itemList.count() > 0) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;                                                                         // 파일이 쓰기모드나 텍스트 파일이 아니면 리턴

        QTextStream out(&file);
        foreach(auto item, itemList) {
            out << item->text(0) << ", ";
            out << item->text(1) << ", ";
            out << item->text(2) << ", ";
            out << item->text(3) << ", ";
            out << item->text(4) << ", ";
            out << item->text(5) << "\n";
        }                                                                                   // 텍스트 파일에 로그에 대한 정보 저장
        file.close();                                                                       // 파일 닫기
    }
}
