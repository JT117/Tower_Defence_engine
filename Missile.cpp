#include "Missile.h"

Missile::Missile(int degatG, int vitesseG,Ennemi* ennemi,QGraphicsPixmapItem* app,int X,int Y,int type1) : degat(degatG), vitesse(vitesseG), cible(ennemi), apparence(app), type(type1)
{
	apparence->setPos(X - apparence->pixmap().width()/2, Y - apparence->pixmap().height()/2);
	apparence->setActive(false);
	apparence->setZValue(7);
        QGraphicsBlurEffect* flou = new QGraphicsBlurEffect();
        flou->setBlurHints(QGraphicsBlurEffect::AnimationHint);
        apparence->setGraphicsEffect(flou);
	diff = QPoint(32,32);
}

Missile::~Missile(void)
{
}

QGraphicsPixmapItem* Missile::getApparence()const
{
	return apparence;
}

void Missile::setApparence(QGraphicsPixmapItem* given)
{
	apparence = given ;
}

int Missile::getDegat()const
{
	return degat;
}

int Missile::getVitesse()const
{
	return vitesse;
}

void Missile::setCible(Ennemi* given)
{
	cible = given;
}

Ennemi* Missile::getCible()const
{
	return cible;
}

int Missile::getType()const
{
	return type;
}

void Missile::mouvement(QGraphicsScene* scene,QList<Missile>* listMissile, int i)
{
	//**************************Determination du sens de deplacement par axe********************************************
		if( apparence->x() - cible->getApparence()->x() > 0)
		{
			sensX = -1;
		}
		else
		{
			sensX = 1;
		}

		if( apparence->y() - cible->getApparence()->y() > 0)
		{
			sensY = -1;
		}
		else
		{
			sensY = 1;
		}
	//************************Deplacement en lui meme********************************************************************
		float ecartX = abs(apparence->x() + 8 - (cible->getApparence()->x() + diff.x()) );
		float ecartY = abs(apparence->y() + 8 - (cible->getApparence()->y() + diff.y()) );

		if(! (ecartX <= cible->getApparence()->pixmap().width() / 2 + 15 && ecartY <= cible->getApparence()->pixmap().height() / 2 + 15) )
		{
			float vit = vitesse;

			if(ecartY == 0) //Deplacement si les Y sont bon 
			{
				while( vit > 0)
				{
					apparence->moveBy(1*sensX,0); //on bouge de 1 sur X
					vit --;
				}
			}
			else if(ecartX == 0)//Deplacement si les X sont bon 
			{
				while( vit > 0)
				{
					apparence->moveBy(0,1*sensY); //On bouge de 1 sur Y
					vit --;
				}
			}
			else
			{
				float rapport = ecartY / ecartX; //Sinon calcul du rapport pour deplacement en diagonal
			
				while( vit > 0)
				{
					apparence->moveBy(1*sensX,rapport*sensY); //on se deplace de 1 sur X, et de "rapport" sur Y
					vit -= (rapport+1);				
				}
			}
		}
		else
		{
			cible->prendDegat(degat,type);
			scene->removeItem(apparence);
			listMissile->removeAt(i);      
		}
}
