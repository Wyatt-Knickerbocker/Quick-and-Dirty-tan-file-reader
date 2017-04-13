#include <QCoreApplication>
#include <QFile>
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("C:\\Users\\WYatt\\Desktop\\Code\\test.tan2");
    if (file.open(QIODevice::ReadOnly))
    {
        cout << "Success!" << endl;
        QTextStream fout(&file);
        QString tmp;
        tmp = fout.readLine();
        cout << "Version number: " << tmp.toStdString() << endl;
        tmp = fout.readLine();
        cout << "wmv file: " << tmp.toStdString() << endl;
        QString preparse(fout.readAll());
        QStringList parsed;
        parsed = preparse.split(QRegularExpression("\\s+"));
        cout << "There are " << parsed.length() << " distinct tokens in the file." << endl;
        cout << "First entry is: " << parsed.first().toStdString() << endl;
    }
    else
    {
        cout << "Failure opening file!" << endl;
    }

    return a.exec();
}
