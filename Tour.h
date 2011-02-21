#pragma once
#include <QtGui>
#include <iostream>
#include "Constante.h"


class Tour : public QWidget, public Constante
{
	Q_OBJECT;

	public:
        Tour( int type, QGraphicsPixmapItem* app, int X, int Y, QGraphicsScene* scene );
	~Tour(void);
	void setApparence(QGraphicsPixmapItem* given);
	QGraphicsPixmapItem* getApparence()const;
	int getPrix()const;
	int getPorte()const;
	int getDegatMissile()const;
	int getVitesseMissile()const;
	bool getPeutTirer()const;
	void viensDeTirer();
	QPixmap getApparenceMissile()const;
        int getType()const;
        void experience();
        void detruire();

	public slots:
	void update();

	protected:
	int vie;
	int porte;
	int prix;
	int degatMissile;
	int vitesseMissile;
	bool  peutTirer;
	QGraphicsPixmapItem* apparence;
        QGraphicsLineItem* barreXp;
	int tempsRecharge;
	QPixmap apparenceMissile;
	int type;

        int exp;
        int seuil;
        float coefSeuil;
        int diviseur;
        int niveau;
        QGraphicsScene* scene1;
        QList<QGraphicsPixmapItem*> listNiveau;
	
};
