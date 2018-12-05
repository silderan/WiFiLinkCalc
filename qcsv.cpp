#include "qcsv.h"

#include <QFile>

CSVData QCSV::load(const QString &fname, QIniFile::TargetDir targetDir)
{
    QFile f(QIniFile::fullPath(fname, targetDir));
    CSVData data;
    if( f.open(QIODevice::ReadOnly) )
    {
        QByteArray linea;
        QList<QByteArray> bits;
        while( !f.atEnd() )
            if( (linea = f.readLine().replace("\n", "")).count() )
                data.append( QString::fromLatin1(linea).replace(", ", ",").split(',') );

        f.close();
    }
    return data;
}
