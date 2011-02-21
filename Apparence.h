#ifndef APPARENCE_H
#define APPARENCE_H

#include <QtGui>

class Apparence : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT;

    public:
        Apparence( QGraphicsItem* ellipse );


    protected:


};

#endif // APPARENCE_H
