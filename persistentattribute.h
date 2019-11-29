#ifndef PERSISTENTATTRIBUTE_H
#define PERSISTENTATTRIBUTE_H

#include <QVariant>


class persistentAttribute
{
public:
    QString name;
    QVariant::Type type;
    void *data;
    persistentAttribute(QString nom, QVariant::Type type, void *data);
};


#endif // PERSISTENTATTRIBUTE_H
