#ifndef QCSV_H
#define QCSV_H

#include <QStringList>
#include <QIniFile.h>

typedef QList<QStringList> CSVData;

class QCSV
{
public:
    static CSVData load(const QString &fname, QIniFile::TargetDir targetDir = QIniFile::CurrentDir);

};

#endif // QCSV_H
