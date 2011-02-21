#include "Tour.h"

Tour::Tour(int type1,QGraphicsPixmapItem* app,int X,int Y, QGraphicsScene* scene) : QWidget(), Constante(), apparence(app)
{
	type = type1;
	apparence->setPos(X,Y);
	apparence->setZValue(1);
	apparence->setActive(false);
        scene1 = scene;

	if(type == 1)
	{
		vie = VIE_1;
		porte = PORTE_1;
		prix = PRIX_1;
		degatMissile = DEGAT_1;
		tempsRecharge = RECHARGE_1;
		apparenceMissile = QPixmap("systeme/Tour/Missile/normal.png");
                seuil = SEUIL_1;
                coefSeuil = COEF_SEUIL_1;
                diviseur = DIVISEUR_1;
	}
	else if(type == 2)
	{
		vie = VIE_2;
		porte = PORTE_2;
		prix = PRIX_2;
		degatMissile = DEGAT_2;
		tempsRecharge = RECHARGE_2;
		apparenceMissile = QPixmap("systeme/Tour/Missile/electrique.png");
                seuil = SEUIL_2;
                coefSeuil = COEF_SEUIL_2;
                diviseur = DIVISEUR_2;
	}
	else if(type == 3)
	{
		vie = VIE_3;
		porte = PORTE_3;
		prix = PRIX_3;
		degatMissile = DEGAT_3;
		tempsRecharge = RECHARGE_3;
		apparenceMissile = QPixmap("systeme/Tour/Missile/poison.png");
                seuil = SEUIL_3;
                coefSeuil = COEF_SEUIL_3;
                diviseur = DIVISEUR_3;
	}
	else if(type == 4)
	{
		vie = VIE_4;
		porte = PORTE_4;
		prix = PRIX_4;
		degatMissile = DEGAT_4;
		tempsRecharge = RECHARGE_4;
		apparenceMissile = QPixmap("systeme/Tour/Missile/froid.png");
                seuil = SEUIL_4;
                coefSeuil = COEF_SEUIL_4;
                diviseur = DIVISEUR_4;
	}
	else if(type == 5)
	{
		vie = VIE_5;
		porte = PORTE_5;
		prix = PRIX_5;
		degatMissile = DEGAT_5;
		tempsRecharge = RECHARGE_5;
		apparenceMissile = QPixmap("systeme/Tour/Missile/acier.png");
                seuil = SEUIL_5;
                coefSeuil = COEF_SEUIL_5;
                diviseur = DIVISEUR_5;
	}

	vitesseMissile = 32;
        exp = 0;
	peutTirer = true;
        niveau = 0;

        barreXp = scene1->addLine( QLineF( apparence->pos().x()+2, apparence->pos().y() + 62, apparence->pos().x()+2, apparence->pos().y() +62 ), QPen(Qt::white));
        barreXp->setZValue(100);
}

Tour::~Tour(void)
{
}

void Tour::setApparence(QGraphicsPixmapItem* given)
{
	apparence = given;
}

QGraphicsPixmapItem* Tour::getApparence()const
{
	return apparence;
}

int Tour::getPrix()const
{
	return prix;
}

int Tour::getPorte()const
{
	return porte;
}

int Tour::getDegatMissile()const
{
	return degatMissile;
}

int Tour::getVitesseMissile()const
{
	return vitesseMissile;
}

bool Tour::getPeutTirer()const
{
	return peutTirer;
}

void Tour::viensDeTirer()
{
    this->experience();
    peutTirer = false;
    QTimer::singleShot(tempsRecharge, this, SLOT(update())); // Penser à mettre le temps de recharge dans une variable de la tour pour modification etc...
}

void Tour::experience()
{
    exp++;

    float pourcentage = (float)exp/(float)seuil * 100;
    barreXp->setLine( apparence->pos().x()+2, apparence->pos().y()+62, apparence->pos().x()+2+ 60*pourcentage/100, apparence->pos().y() +62 );

    if( exp == seuil && niveau < 5)
    {
        seuil *= coefSeuil;
        seuil -= exp;
        exp = 0;
        niveau++;

        degatMissile += degatMissile  * ( niveau / diviseur ); //Au niveau 5 degat*2
        tempsRecharge -= tempsRecharge * ( niveau / diviseur ); //Au niveau 5 temps de recharge/2
        barreXp->setLine( apparence->pos().x()+2, apparence->pos().y()+62, apparence->pos().x()+2, apparence->pos().y() +62 );


        for( int i = 0; i < niveau; i++ )
        {
            QGraphicsPixmapItem* niveau = scene1->addPixmap( QPixmap( "systeme/Ennemi/niveau.png" ) );
            niveau->setZValue(117);
            niveau->setPos( apparence->pos().x() + i*12, apparence->pos().y() );
            listNiveau.append( niveau );
        }
    }
}

void Tour::update()
{   
	peutTirer = true;
}

QPixmap Tour::getApparenceMissile()const
{	
	return apparenceMissile;
}

int Tour::getType()const
{
	return type;
}

void Tour::detruire()
{
    for( int i = 0; i< listNiveau.size(); i++ )
    {
        scene1->removeItem(listNiveau[i]);
    }
}
