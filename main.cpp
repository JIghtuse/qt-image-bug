#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>

QPixmap load_cache(QString path)
{
    QFile file(path);
    if(!file.open(QFile::ReadOnly)) {
        qDebug() << file.errorString();
        throw 1;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_4_7);
    QPixmap pix;
    stream >> pix;
    return pix;
}

bool save_cache(QString path, QPixmap pix)
{
    QFile file(path);
    if(!file.open(QFile::WriteOnly | QFile::Truncate))  {
        qDebug() << file.errorString();
        return false;
    }
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_4_7);
    stream << pix;
    return true;
}

void save_pixmap(QString path, QPixmap pix)
{
    qDebug() << "saving to " << path;
    QFile file(path);
    pix.save(&file, "PNG");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString path = "/tmp/";
    QString cache = path + "cache.cache";

    const int init = 0;
    int i = init;
    QPixmap pix(path + "logo" + QString::number(i) + ".png");
    for (; i < init + 1000; ++i) {
        save_cache(cache, pix);
        pix = load_cache(cache);
    }
    save_pixmap(path + "logo" + QString::number(i) + ".png", pix);

    return a.exec();
}
