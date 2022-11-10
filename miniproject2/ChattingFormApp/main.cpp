#include "chattingform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChattingForm w;
    ChattingForm s;
    w.show();
    s.show();
    return a.exec();
}
