#include <QCoreApplication>
#include <iostream>
#include <QCryptographicHash>
#include <QString>
#include <QFile>
#include <QDebug>
#include <string>

int main(int argc, char *argv[])
{

    QString fileName;// ="test_file";
    std::string fileNameStr;

    QCoreApplication a(argc, argv);
    std::cout << "MD5 checker!"<<std::endl;
    std::cout << "Give filename to generate checksum from: ";
    std::cin >> fileNameStr;
    fileName = QString::fromStdString(fileNameStr);
    QFile* file = new QFile(fileName);
        if(file->open(QIODevice::ReadOnly))
        {
            QCryptographicHash* hash;

            QByteArray result = hash->hash(file->readAll(), QCryptographicHash::Md5);

            qDebug() << "MD5 Hash of " << fileName << " is: " << endl;
            QString output = result.toHex();
            qDebug() << output << endl;
            file->close();
        }
    return a.exec();
}
