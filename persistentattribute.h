#ifndef PERSISTENTATTRIBUTE_H
#define PERSISTENTATTRIBUTE_H

#include <QVariant>


class persistentAttribute
{
public:
    QString name;
    QVariant::Type type;
    void *data;
    // void * = A pointer to void is a "generic" pointer type.
    // A void * can be converted to any other pointer type without an explicit cast.
    // You cannot dereference a void * or do pointer arithmetic with it; you must
    // convert it to a pointer to a complete data type first.
    persistentAttribute();
    persistentAttribute(QString nom, QVariant::Type attributType, void *);
};


#endif // PERSISTENTATTRIBUTE_H
