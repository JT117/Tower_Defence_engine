#include <QtGui>
#include "Constante.h"
#include "Apparence.h"

class Ennemi : public QWidget, public Constante
{
	Q_OBJECT;

	public:
	Ennemi(int num,QGraphicsScene* scene1);
	~Ennemi(void);
        void setApparence(QGraphicsPixmapItem* given);
	QGraphicsPixmapItem* getApparence()const;
	int getVie()const;
	int getNbTrajet()const;
	void setBarreDeVie(QGraphicsLineItem* given);
	QGraphicsLineItem* getBarreDeVie()const;
	void prendDegat(int degat, int type);
	bool getEnVie()const;
	float getRapportVie()const;
	int getDrop()const;
	QPixmap getTypeApparence()const;
        void updateDeplacement();
        QPoint getDistTrajet()const;
        void demarrerAnimation( QList<QPoint>* list );

	public slots:
	void updateFroid();
	void updatePoison();
	void clignotePoison();
        void animationFini();

	protected:
        QGraphicsItemAnimation *animation;
        QGraphicsItemAnimation *animation2;
        QTimeLine *timer;
        QList<QPoint>* listPoint;
        QGraphicsPixmapItem* apparence;
	int type;
	int vie;
        int vitesse;
        QPoint distTrajet;
	int nbTrajet;
        QGraphicsLineItem* barreDeVie;
	bool enVie;
	float rapportVie;
	int drop;
	bool empoisonne;
	bool refroidi;
        QPixmap typeApparence;
	QGraphicsScene* scene;
	float coefFroid;
	int dureFroid;
	int durePoison;
	int intervallePoison;
	int degatPoison;
};
