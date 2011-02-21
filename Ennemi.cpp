#include "Ennemi.h"

Ennemi::Ennemi(int num, QGraphicsScene* scene1) : QWidget(), Constante()
{
	if(num == 1)
	{
		vie = VIE_M_1;
		drop = DROP_M_1;
		vitesse = VITESSE_M_1;
		typeApparence = QPixmap("systeme/Ennemi/ennemi1.png");
	}
	else if( num == 2)
	{
		vie = VIE_M_2;
		drop = DROP_M_2;
		vitesse = VITESSE_M_2;
		typeApparence = QPixmap("systeme/Ennemi/ennemi2.png");
	}
	else if( num == 3)
	{
		vie = VIE_M_3;
		drop = DROP_M_3;
		vitesse = VITESSE_M_3;
		typeApparence = QPixmap("systeme/Ennemi/ennemi3.png");
	}
	else if( num == 4)
	{
		vie = VIE_M_4;
		drop = DROP_M_4;
		vitesse = VITESSE_M_4;
		typeApparence = QPixmap("systeme/Ennemi/ennemi4.png");
	}
	else if( num == 5)
	{
		vie = VIE_M_5;
		drop = DROP_M_5;
		vitesse = VITESSE_M_5;
		typeApparence = QPixmap("systeme/Ennemi/ennemi5.png");
	}
	
	scene = scene1;
	rapportVie = vie;
	enVie = true;


	nbTrajet = 0;
	empoisonne = false;
	refroidi = false;
	type = num;
	coefFroid = COEF_FROID;
	dureFroid = DURE_FROID; 
	durePoison = DURE_POISON;
	intervallePoison = INTER_POISON;
	degatPoison = DEGAT_POISON;

        animation2 = new QGraphicsItemAnimation(this);
        animation = new QGraphicsItemAnimation(this);
        timer = new QTimeLine(10000,this);
        timer->setFrameRange(0,100);
        timer->setUpdateInterval(25);
        timer->setEasingCurve(QEasingCurve::Linear);

        animation->setTimeLine( timer );
        animation2->setTimeLine(timer);
        connect( timer, SIGNAL(finished()), this, SLOT(animationFini()));
}

Ennemi::~Ennemi(void)
{
}

int Ennemi::getNbTrajet()const
{
	return nbTrajet;
}

int Ennemi::getVie()const
{
	return vie;
}

QGraphicsPixmapItem* Ennemi::getApparence()const
{
        return apparence;
}

void Ennemi::setApparence(QGraphicsPixmapItem* given)
{
        apparence = given ;

        animation->setItem( apparence );
        apparence->setActive(false);
        apparence->setZValue(1);
}

void Ennemi::setBarreDeVie(QGraphicsLineItem* given)
{
	barreDeVie = given;
	barreDeVie->setActive(false);
	barreDeVie->setZValue(1);
}

QGraphicsLineItem* Ennemi::getBarreDeVie()const
{
	return barreDeVie;
}

void Ennemi::prendDegat(int degat,int typeMissile)
{
	if(enVie)
	{
		vie -= degat;
		barreDeVie->setLine(QLine(QPoint(barreDeVie->line().p1().x(), barreDeVie->line().p1().y()), QPoint(barreDeVie->line().p2().x() - (60 / rapportVie * degat) , barreDeVie->line().p2().y())) );
		
		if( typeMissile == 3 && !empoisonne) 
		{
			empoisonne = true;
                        QGraphicsColorizeEffect* effetPoison = new QGraphicsColorizeEffect();
                        effetPoison->setColor(Qt::green);
                        effetPoison->setStrength(0.3);
                        apparence->setGraphicsEffect(effetPoison);
			QTimer::singleShot(750, this, SLOT(updatePoison()));
		}
	    if( typeMissile == 4 && !refroidi) 
                {
			refroidi = true;
                        QGraphicsColorizeEffect* effetFroid = new QGraphicsColorizeEffect();
                        effetFroid->setColor(Qt::blue);
                        effetFroid->setStrength(0.5);
                        apparence->setGraphicsEffect(effetFroid);
			QTimer::singleShot(dureFroid, this, SLOT(updateFroid()));
		}

		if(vie <=0)
		{
			enVie = false;

		}
		else if(barreDeVie->line().dx() <= 20)
		{
			barreDeVie->setPen(QPen(Qt::red,4));
		}
		else if(barreDeVie->line().dx() <= 35)
		{
			barreDeVie->setPen(QPen(Qt::yellow,4));
		}
	}
}
bool Ennemi::getEnVie()const
{
	return enVie;
}

float Ennemi::getRapportVie()const
{
	return rapportVie;

}

int Ennemi::getDrop()const
{
	return drop;
}

QPixmap Ennemi::getTypeApparence()const
{
	return typeApparence;
}
void Ennemi::updateFroid()
{
	refroidi = false;
        QGraphicsEffect* effetFroid = apparence->graphicsEffect();
        effetFroid->setEnabled(false);
        apparence->setZValue(1);
	barreDeVie->setZValue(1);
}
void Ennemi::clignotePoison()
{
    QGraphicsColorizeEffect* effetPoison = new QGraphicsColorizeEffect();
    effetPoison->setColor(Qt::green);
    effetPoison->setStrength(0.3);
    apparence->setGraphicsEffect(effetPoison);
}

void Ennemi::updatePoison()
{
	if(durePoison - intervallePoison >= 0)
	{

		QTimer::singleShot(500, this, SLOT(clignotePoison()));
                QGraphicsColorizeEffect* effetPoison = new QGraphicsColorizeEffect();
                effetPoison->setColor(Qt::green);
                effetPoison->setStrength(0.6);
                apparence->setGraphicsEffect(effetPoison);
		Ennemi::prendDegat(degatPoison,0); //poison 10 de degats
		QTimer::singleShot(intervallePoison, this, SLOT(updatePoison()));
		durePoison -= intervallePoison;
	}
	else
	{
		empoisonne = false;
                QGraphicsEffect* effetPoison = apparence->graphicsEffect();
                effetPoison->setEnabled(false);
		durePoison = DURE_POISON ;
	}
}
QPoint Ennemi::getDistTrajet()const
{
    int x = apparence->scenePos().x();
    int y = apparence->scenePos().y();

    int longueurTrajetSurX = listPoint->at( nbTrajet + 1 ).x() - x-32;
    int longueurTrajetSurY = listPoint->at( nbTrajet + 1 ).y() - y-32;

    return QPoint( sqrt(pow(longueurTrajetSurX,2)),sqrt(pow( longueurTrajetSurY,2)));
}
void Ennemi::updateDeplacement()
{
    int x = apparence->scenePos().x();
    int y = apparence->scenePos().y();

    int longueurTrajetSurX = listPoint->at( nbTrajet + 1 ).x() - x-32;
    int longueurTrajetSurY = listPoint->at( nbTrajet + 1 ).y() - y-32;

    if( longueurTrajetSurX != 0 )
    {
        int tempsDeplacement = sqrt(pow(longueurTrajetSurX,2)) / vitesse;

        timer->setDuration( tempsDeplacement * 1000 );

        animation->setPosAt( (double) 0, QPointF(x, y));
        animation->setPosAt( (double) 1, QPointF(x+longueurTrajetSurX, y));

        animation2->setPosAt( (double) 0, QPointF(barreDeVie->pos().x(), barreDeVie->pos().y()));
        animation2->setPosAt( (double) 1, QPointF(barreDeVie->pos().x()+longueurTrajetSurX, barreDeVie->pos().y()));

    }
    else if( longueurTrajetSurY != 0 )
    {
        unsigned int tempsDeplacement = sqrt(pow(longueurTrajetSurY,2)) / vitesse;

        timer->setDuration( tempsDeplacement * 1000 );

        animation->setPosAt( (double) 0, QPointF(x, y));
        animation->setPosAt( (double) 1, QPointF(x, y+longueurTrajetSurY));

        animation2->setPosAt( (double) 0, QPointF(barreDeVie->pos().x(), barreDeVie->pos().y()));
        animation2->setPosAt( (double) 1, QPointF(barreDeVie->pos().x(), barreDeVie->pos().y()+longueurTrajetSurY));
    }

    timer->start();
}

void Ennemi::demarrerAnimation(QList<QPoint> *list)
{
    barreDeVie = scene->addLine( apparence->scenePos().x(), apparence->pos().y() - 6, apparence->pos().x() + 64,apparence->pos().y() - 6, QPen(Qt::green,4));
    barreDeVie->setActive(false);
    barreDeVie->setZValue(1);
    animation2->setItem(barreDeVie);

    nbTrajet = 0;
    listPoint = list;
    this->updateDeplacement();
}

void Ennemi::animationFini()
{
    animation->clear();
    nbTrajet++;
    this->updateDeplacement();
}
