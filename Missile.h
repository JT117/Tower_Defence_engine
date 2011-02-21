#pragma once
#include <QtGui>
#include "Ennemi.h"

class Missile
{
	public:
	Missile(int degatG, int vitesseG,Ennemi* ennemi,QGraphicsPixmapItem* app,int X,int Y,int type);
	~Missile(void);
	void mouvement(QGraphicsScene* scene,QList<Missile>* listMissile, int i);
	void setApparence(QGraphicsPixmapItem* given);
	QGraphicsPixmapItem* getApparence()const;
	void setCible(Ennemi* given);
	Ennemi* getCible()const;
	int getDegat()const;
	int getVitesse()const;
	int getType()const;

	protected:
	QGraphicsPixmapItem* apparence;
	Ennemi* cible;
	int degat;
	int vitesse;
	int type;
	int sensX;
	int sensY;
	QPoint diff;
};
