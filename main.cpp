#include <QCoreApplication>
#include <QString>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создание имени для папки

    QString format = "yyyyMMdd_HHmm";
    QString datatime = QDateTime::currentDateTimeUtc().toString(format);
    QString path("F:/");
    path.append(datatime);
    qDebug() << datatime << path;
    QString year = QDate::currentDate().toString(QString("yyyy"));
    QString month = QDate::currentDate().toString(QString("MM"));
    QString day = QDate::currentDate().toString(QString("dd"));
    QString newpath("E:/" + year + "/" + month + "/" + day + "/" + datatime);
    qDebug() << newpath;

    // Создание папки

    QDir dir;
    if(dir.mkpath(path))
        qDebug("folder created");
    if(dir.exists(path))
        qDebug("folder exists");
    if(!dir.exists(newpath))
        qDebug("all right");
    if(dir.rename(path,newpath))
        qDebug("folder moved");

    return a.exec();
}
