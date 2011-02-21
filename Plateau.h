#include <QtGui>
#include <iostream>
#include <vector>
#include <cmath>
//#include <Phonon>

#include "Tour.h"
//#include "Ennemi.h"
#include "Missile.h"
#include "constante.h"
#include "Apparence.h"

class Plateau : public QDialog, public Constante
{
	Q_OBJECT;

	public:
	Plateau(void);
	~Plateau(void);
	void mousePressEvent(QMouseEvent *event);
	void timerEvent(QTimerEvent* timerEvent);
        void rechargementConstructionTour();
        void tropCher();

        public slots:
	void update();
	void forbid();
	void gainArgent();
	void vagueSuivante();
	void interet();
        void constructionTourEnable1();
        void constructionTourEnable2();
        void constructionTourEnable3();
        void constructionTourEnable4();
        void constructionTourEnable5();

	protected:
	bool eventFilter(QObject *obj, QEvent *event);
	void obtentionSetting(int lvl);
	void updateDeplacementEnnemi();
	void updateTour();
	void updateMissile();
	void updateEnnemiVivant();
	void triEnnemi();
	void victoire();
	QGraphicsScene scene;
	QGraphicsView vue;
	QGraphicsPixmapItem* fond;
	QGraphicsPixmapItem* tour1;
	QGraphicsPixmapItem* tour2;
	QGraphicsPixmapItem* tour3;
	QGraphicsPixmapItem* tour4;
	QGraphicsPixmapItem* tour5;
        QGraphicsEllipseItem* recharge1;
        bool rechargeT1;
        bool rechargeT2;
        bool rechargeT3;
        bool rechargeT4;
        bool rechargeT5;
	QGraphicsPixmapItem* destrc;
	QGraphicsEllipseItem* porte;
	QGraphicsPixmapItem* bandeauInteret;
	QGraphicsPixmapItem* maison;
	QBasicTimer* timer;
	int type;
        int dernierTypeConstruit;
	int argent;
	int vie;
	QString image;
	QGraphicsTextItem* textArgent;
	QGraphicsTextItem* textVague;
	QGraphicsTextItem* textInteret;
	QList< QList<bool> > ZC;
	QList<Tour*> listTour; 
	QList<QPoint> listPoint;
	QList<Ennemi*> listEnnemi;
	QList<Missile> listMissile;
	QList< QList<Ennemi*> > listVague;
	int numVague;
	QPoint diff;
	QCursor souris;
	bool peutConstruire;
	bool peutDetruire ;
	int tempsEntreVague;
	QPainter* painter;

};
