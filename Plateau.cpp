#include "Plateau.h"

Plateau::Plateau(void) : Constante()
{
	int lvl = 1;

	this->setWindowTitle("Poly'Tours");
        this->setWindowIcon(QPixmap("icon.png"));
        this->setStyleSheet("QToolTip{font-family : Lucida Sans Unicode; color : black; font-size : 12px; min-height : 68px; min-width: 85px;} QDialog{background-color : black}");


	this->setWindowState(Qt::WindowFullScreen);
	this->setCursor(souris);

	Plateau::obtentionSetting(1); //1 pour le lvl 1 ici

	argent = ARGENT_P;
	tempsEntreVague = TPS_VG;     //5s
	vie = VIE_P;                  //nombre d'ennemi qui peut passer au travers de la defense

	peutConstruire = false;
	peutDetruire = false;
	numVague = -1;

	porte = scene.addEllipse(QRectF(1,1,1,1),QPen(Qt::black,3,Qt::DashLine));
	porte->setActive(false);
	porte->hide();
	porte->setZValue(5);

	QGraphicsPixmapItem* banniere = scene.addPixmap(QPixmap("systeme/Plateau/banniere.png"));
                banniere->setY(1024 - banniere->pixmap().height());
		banniere->setActive(false);
		banniere->setZValue(6);

	QGraphicsPixmapItem* coinG = scene.addPixmap(QPixmap("systeme/Plateau/coin.png"));
                coinG->setY(1024 - coinG->pixmap().height());
		coinG->setActive(false);
		coinG->setZValue(6);
	QGraphicsPixmapItem* coinD = scene.addPixmap(QPixmap("systeme/Plateau/coin.png"));
                coinD->setPos(1280 - coinD->pixmap().width(),1024 - coinD->pixmap().height());
		coinD->setActive(false);
		coinD->setZValue(6);

	textArgent = scene.addText("Argent : "+QString::number(argent),QFont("Lucida Sans Unicode",15));
		textArgent->setPos(15,1023 - (coinG->pixmap().height()/2) - 16);
		textArgent->setActive(false);
		textArgent->setZValue(6);
	textVague = scene.addText("Ready ? ",QFont("Lucida Sans Unicode",16));
		textVague->setPos(1080,965);
		textVague->setActive(false);
		textVague->setZValue(6);

        tour1 = scene.addPixmap(QPixmap("systeme/Plateau/tour1.png"));
		tour1->setPos(coinG->pixmap().width() + 5,959);
		tour1->setActive(false);
		tour1->setZValue(6);
		tour1->setToolTip("Prix : "+QString::number(PRIX_1)+"\nDégats : "+QString::number(DEGAT_1)+"\nPortée : "+QString::number(PORTE_1));
                recharge1 = scene.addEllipse( tour1->pos().x(), tour1->pos().y(), 15, 15, QPen(Qt::blue),QBrush(Qt::blue));
                recharge1->setZValue(7);
                recharge1->setVisible( false );

	tour2 = scene.addPixmap(QPixmap("systeme/Plateau/tour2.png"));
		tour2->setPos(coinG->pixmap().width() + 5*2 + 64,959);
		tour2->setActive(false);
		tour2->setZValue(6);
		tour2->setToolTip("Prix : "+QString::number(PRIX_2)+"\nDégats : "+QString::number(DEGAT_2)+"\nPortée : "+QString::number(PORTE_2));

	tour3 = scene.addPixmap(QPixmap("systeme/Plateau/tour3.png"));
		tour3->setPos(coinG->pixmap().width() + 5*3 + 64*2,959);
		tour3->setActive(false);
		tour3->setZValue(6);
		tour3->setToolTip("Prix : "+QString::number(PRIX_3)+"\nDégats : "+QString::number(DEGAT_3)+"\nPortée : "+QString::number(PORTE_3)+"\nPoison");

	tour4 = scene.addPixmap(QPixmap("systeme/Plateau/tour4.png"));
		tour4->setPos(coinG->pixmap().width() + 5*4 + 64*3,959);
		tour4->setActive(false);
		tour4->setZValue(6);
		tour4->setToolTip("Prix : "+QString::number(PRIX_4)+"\nDégats : "+QString::number(DEGAT_4)+"\nPortée : "+QString::number(PORTE_4)+"\nFroid");

	tour5 = scene.addPixmap(QPixmap("systeme/Plateau/tour5.png"));
		tour5->setPos(coinG->pixmap().width() + 5*5 + 64*4,959);
		tour5->setActive(false);
		tour5->setZValue(6);
		tour5->setToolTip("Prix : "+QString::number(PRIX_5)+"\nDégats : "+QString::number(DEGAT_5)+"\nPortée : "+QString::number(PORTE_5));

	destrc = scene.addPixmap(QPixmap("systeme/Plateau/destrc.png"));
		destrc->setPos(coinG->pixmap().width() + 5*6 + 64*5,959);
		destrc->setZValue(6);
		destrc->setActive(false);

	bandeauInteret = scene.addPixmap(QPixmap("systeme/Plateau/interet.png"));
		bandeauInteret->setY(1024 / 2 - bandeauInteret->pixmap().height() / 2 );
		bandeauInteret->setActive(false);
                bandeauInteret->setZValue(118);
		bandeauInteret->hide();
		bandeauInteret->setActive(false);

	textInteret = scene.addText("Interet : ",QFont("Lucida Sans Unicode",20));
		textInteret->setPos(600,1024 / 2 - 15);
                textInteret->setZValue(119);
		textInteret->hide();
		textInteret->setActive(false);

	maison = scene.addPixmap(QPixmap("systeme/Plateau/maison5.png"));
		maison->setPos(listPoint.at(listPoint.size()-1).x() - maison->pixmap().width() / 2 - 2,listPoint.at(listPoint.size()-1).y() - maison->pixmap().height() / 2 - 2);
		maison->setZValue(7);
		maison->setActive(false);


	vue.setParent(this);
	vue.setScene(&scene);
	vue.setBackgroundBrush(QPixmap("systeme/Niveau/Niveau"+QString::number(lvl)+"/fond.png"));
	vue.setCacheMode(QGraphicsView::CacheBackground);
	vue.setFixedSize(1282, 1026);
	vue.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	vue.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vue.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	vue.setRenderHints(QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform | QPainter::Antialiasing);
        vue.move((QApplication::desktop()->width()- 1280) /2, (QApplication::desktop()->height()- 1024) /2 );


	diff = QPoint(32,32);

        rechargeT1 = false;
        rechargeT2 = false;
        rechargeT3 = false;
        rechargeT4 = false;
        rechargeT5 = false;

        this->vagueSuivante();

	timer = new QBasicTimer();
	timer->start(25,this);

	this->installEventFilter(this);

}

Plateau::~Plateau(void)
{
}
void Plateau::interet()
{
	if(numVague >= 0)
	{
		int interet = argent * 5 / 100;
		argent += interet;
		textArgent->setPlainText("Argent :  "+QString::number(argent)); 
		textArgent->setDefaultTextColor(Qt::yellow);
		QTimer::singleShot(500, this, SLOT(gainArgent()));
		bandeauInteret->show();
		textInteret->setPlainText("Interet : "+QString::number(interet));
		textInteret->show();
	}
}
void Plateau::gainArgent()
{
	textArgent->setDefaultTextColor(Qt::black);
}
void Plateau::forbid()
{
	vue.setCursor(Qt::ArrowCursor);
	textArgent->setDefaultTextColor(Qt::black);
}
void Plateau::mousePressEvent(QMouseEvent *event)
{
	//********************************Bouton Gauche**************************************************************
     if(event->button() == Qt::LeftButton) 
	 {
		 int X = souris.pos().x();                 
		 int Y = souris.pos().y();

                 if( tour1->isUnderMouse() && !rechargeT1 )
		 {
			 if( !(argent - PRIX_1 < 0) )
			 {
				peutConstruire = true;
				type = 1;
				image = "systeme/Tour/tour1.png";
				vue.setCursor(QCursor(QPixmap(image)));
			 }
			 else
			 {
				 vue.setCursor(Qt::ForbiddenCursor);
				 textArgent->setDefaultTextColor(Qt::red);
				 QTimer::singleShot(500, this, SLOT(forbid()));
			 }
		 }
                 else if( tour2->isUnderMouse() && !rechargeT2 )
		 {
			 if( !(argent - PRIX_2 < 0) )
			 {
				 peutConstruire = true;
				 type = 2;
				 image = "systeme/Tour/tour2.png";
				 vue.setCursor(QCursor(QPixmap(image)));
			 }
			 else
			 {
				 vue.setCursor(Qt::ForbiddenCursor);
				 textArgent->setDefaultTextColor(Qt::red);
				 QTimer::singleShot(500, this, SLOT(forbid()));
			 }
		 }
                 else if( tour3->isUnderMouse() && !rechargeT3  )
		 {
			 if( !(argent - PRIX_3 < 0) )
			 {
				 peutConstruire = true;
				 type = 3;
				 image = "systeme/Tour/tour3.png";
				 vue.setCursor(QCursor(QPixmap(image)));
			 }
			 else
			 {
				 vue.setCursor(Qt::ForbiddenCursor);
				 textArgent->setDefaultTextColor(Qt::red);
				 QTimer::singleShot(500, this, SLOT(forbid()));
			 }
		 }
                 else if( tour4->isUnderMouse() && !rechargeT4 )
		 {
			 if( !(argent - PRIX_4 < 0) )
			 {
				 peutConstruire = true;
				 type = 4;
				 image = "systeme/Tour/tour4.png";
				 vue.setCursor(QCursor(QPixmap(image)));
			 }
			 else
			 {
				 vue.setCursor(Qt::ForbiddenCursor);
				 textArgent->setDefaultTextColor(Qt::red);
				 QTimer::singleShot(500, this, SLOT(forbid()));
			 }
		 }
                 else if(tour5->isUnderMouse() && !rechargeT5 )
		 {
			 if( !(argent - PRIX_5 < 0) )
			 {
				 peutConstruire = true;
				 type = 5;
				 image = "systeme/Tour/tour5.png";
				 vue.setCursor(QCursor(QPixmap(image)));
			 }
			 else
			 {
				 vue.setCursor(Qt::ForbiddenCursor);
				 textArgent->setDefaultTextColor(Qt::red);
				 QTimer::singleShot(500, this, SLOT(forbid()));
			 }
		 }
		 else if(destrc->isUnderMouse() )
		 {
			 if(listTour.size() >= 1)
			 {
				 peutDetruire = true;
				 image = "systeme/Plateau/destrc.png";
				 vue.setCursor(QCursor(QPixmap(image)));
			 }
			 else
			 {
				 vue.setCursor(Qt::ForbiddenCursor);
				 QTimer::singleShot(500, this, SLOT(forbid()));
			 }
		 }

		 if( peutConstruire )
		 {
			for(int j=0;j<ZC[0].size();j++)        //On test par rapport au tableau des zones interdites/bords ecran
			{
				int CaseX = X/64;          //On place par rapport a un grille de carre de 64
				int CaseY = Y/64;

				if(ZC[CaseY][CaseX] && X>0 && X<1280 && Y>0 && Y<960)
				{
					int compt = 0;
					
					for(int i=0;i<listTour.size();i++) //Test si on veut superposer 2 tours
					{
						if(!(listTour[i]->getApparence()->x()/64 == CaseX && listTour[i]->getApparence()->y()/64 == CaseY))
						{
							compt++;
						}
					}
				
					if( compt == listTour.size() )
					{
                                                Tour* g = new Tour( type, scene.addPixmap( QPixmap( image ) ), CaseX*64, CaseY*64, &scene );
						listTour.append(g);

                                                //QtConcurrent::run(this, &Plateau::rechargementConstructionTour );
	
						argent -= g->getPrix();
						textArgent->setPlainText("Argent : "+QString::number(argent));
						
						vue.setCursor(Qt::ArrowCursor);
						j = ZC[0].size();		
						peutConstruire = false;   //Solution trouvée arret du for 
					}
				}
			}
		 }
		 else if ( peutDetruire )
		 {
			 int CaseX = X/64;          
			 int CaseY = Y/64;
			 	
		 	 for(int i=0;i<listTour.size();i++) 
			 {
				 if(listTour[i]->getApparence()->x() / 64 == CaseX && listTour[i]->getApparence()->y() / 64 == CaseY)
				 {
                                         listTour[i]->detruire();
					 scene.removeItem(listTour[i]->getApparence());
					 argent += (listTour[i]->getPrix() * 80 / 100);
					 textArgent->setPlainText("Argent :  "+QString::number(argent)); 
					 textArgent->setDefaultTextColor(Qt::green);
					 QTimer::singleShot(500, this, SLOT(gainArgent()));
					 listTour[i]->~Tour();
					 listTour.removeAt(i);	
						
					 vue.setCursor(Qt::ArrowCursor);
					 peutDetruire = false;
			     }
			 }
		 }
		 event->accept();
	 }
	 //*********************************Bouton droit******************************************************************
	 else if(event->button() == Qt::RightButton)
	 {
		vue.setCursor(Qt::ArrowCursor);
		peutDetruire = false;
		peutConstruire = false;
		porte->hide();
	 }
	 //*********************************Bouton de la molette*****************************************************************
	 else if(event->button() == Qt::MidButton)
	 {
		int sourisX = souris.pos().x() / 64;
		int sourisY = souris.pos().y() / 64;

		for(int i=0;i<listTour.size();i++) 
		{
			QGraphicsPixmapItem* tour = listTour[i]->getApparence();
			int porteTour = listTour[i]->getPorte();

			if(tour->x() / 64 == sourisX && tour->y() / 64 == sourisY)
			{
				porte->setRect(QRectF( sourisX * 64 - porteTour/2 + diff.x(), sourisY * 64 - porteTour/2 + diff.y(), porteTour, porteTour));
				porte->show();
			}
			else
			{
				//porte->hide();
			}
		}
	 }
}
extern void Plateau::rechargementConstructionTour()
{

  /*  dernierTypeConstruit = type;

    QGraphicsColorizeEffect* disable = new QGraphicsColorizeEffect();
    disable->setColor(Qt::red);
    disable->setStrength(0.7);

    if( type == 1)
    {
        rechargeT1 = true;
        tour1->setGraphicsEffect( disable );
        QTimer::singleShot( RECHARGE_CONSTRUCTION_1, this, SLOT( constructionTourEnable1() ) );
    }
    else if( type == 2)
    {
        rechargeT2 = true;
        tour2->setGraphicsEffect( disable );
        QTimer::singleShot( RECHARGE_CONSTRUCTION_2, this, SLOT( constructionTourEnable2() ) );
    }
    else if( type == 3)
    {
        rechargeT3 = true;
        tour3->setGraphicsEffect( disable );
        QTimer::singleShot( RECHARGE_CONSTRUCTION_3, this, SLOT( constructionTourEnable3() ) );
    }
    else if( type == 4)
    {
        rechargeT4 = true;
        tour4->setGraphicsEffect( disable );
        QTimer::singleShot( RECHARGE_CONSTRUCTION_4, this, SLOT( constructionTourEnable4() ) );
    }
    else if( type == 5)
    {
        rechargeT5 = true;
        tour5->setGraphicsEffect( disable );
        QTimer::singleShot( RECHARGE_CONSTRUCTION_5, this, SLOT( constructionTourEnable5() ) );
    }*/
}
void Plateau::constructionTourEnable1()
{
    if( argent >= PRIX_1 && tour1->graphicsEffect() != 0 )
    {
        rechargeT1 = false;
        QGraphicsEffect* disable = tour1->graphicsEffect();
        disable->setEnabled(false);
    }
}
void Plateau::constructionTourEnable2()
{
    if( argent >= PRIX_2 && tour2->graphicsEffect() != 0 )
    {
        rechargeT2 = false;
        QGraphicsEffect* disable = tour2->graphicsEffect();
        disable->setEnabled(false);
    }
}
void Plateau::constructionTourEnable3()
{
    if( argent >= PRIX_3 && tour3->graphicsEffect() != 0 )
    {
        rechargeT3 = false;
        QGraphicsEffect* disable = tour3->graphicsEffect();
        disable->setEnabled(false);
    }
}
void Plateau::constructionTourEnable4()
{
    if( argent >= PRIX_4 && tour4->graphicsEffect() != 0 )
    {
        rechargeT4 = false;
        QGraphicsEffect* disable = tour4->graphicsEffect();
        disable->setEnabled(false);
    }
}
void Plateau::constructionTourEnable5()
{
    if( argent >= PRIX_5 && tour5->graphicsEffect() != 0 )
    {
        rechargeT5 = false;
        QGraphicsEffect* disable = tour5->graphicsEffect();
        disable->setEnabled(false);
    }
}
void Plateau::update()
{
	Plateau::updateDeplacementEnnemi(); //Deplace les ennemis
	Plateau::updateTour();              //Check si des ennemis sont à porter de la tour
	Plateau::updateMissile();           //Bouge les missiles tirés
	Plateau::triEnnemi();               //Tri la liste des ennemis pour que les tours tirent sur l'ennemi le plus proche de la fin
	Plateau::updateEnnemiVivant();
        Plateau::tropCher();
}

void Plateau::updateDeplacementEnnemi()
{
	for(int i=0;i<listEnnemi.size();i++)
	{
                //listEnnemi[i]->updateDeplacement(&listPoint);
           // qDebug() << listEnnemi[i]->getApparence()->pos().x()  << listEnnemi[i]->getApparence()->pos().y();

//****************************************Ennemi a atteint la limite*****************************************************************************
		if(listEnnemi[i]->getNbTrajet() == listPoint.size()-1)
		{
			for(int j=0;j<listMissile.size();j++)
			{
				if( listMissile[j].getCible() == listEnnemi[i] )
				{
					listMissile[j].getCible()->prendDegat(listMissile[j].getDegat(),listMissile[j].getType());
					scene.removeItem(listMissile[j].getApparence());
					listMissile[j].~Missile();
					listMissile.removeAt(j);
				}
			}

			scene.removeItem(listEnnemi[i]->getBarreDeVie());
			scene.removeItem(listEnnemi[i]->getApparence());
			listEnnemi[i]->~Ennemi();
			listEnnemi.removeAt(i);
			textVague->setPlainText("Vague : "+QString::number(numVague+1)+"/"+QString::number(listVague.size())+"\nMonstre : "+QString::number(listEnnemi.size()));
			
			Plateau::victoire();

			if(listEnnemi.size() == 0) // si tous les ennemis sont morts
			{
				QTimer::singleShot(1000, this, SLOT(interet()));
				QTimer::singleShot(tempsEntreVague, this, SLOT(vagueSuivante()));
			}
		}
	}
}

void Plateau::updateTour()
{
	for(int i=0;i<listTour.size();i++)
	{
		QGraphicsPixmapItem* tour = listTour[i]->getApparence();
		int porte = listTour[i]->getPorte();

		QPoint centreTour = QPoint(tour->x() + diff.x(),tour->y() + diff.y());

		for(int j=0;j<listEnnemi.size();j++)
		{
			QGraphicsPixmapItem* ennemi = listEnnemi[j]->getApparence();
			QPoint centreEnnemi = QPoint(ennemi->x() + diff.x(),ennemi->y() + diff.y());
			
			if( abs(centreEnnemi.x() - centreTour.x()) <= porte/2 && abs(centreEnnemi.y() - centreTour.y()) <= porte/2 )
			{
				if(listTour[i]->getPeutTirer())
				{
					int degatTot = 0;
					for(int k=0;k<listMissile.size();k++)
					{
						if(listMissile[k].getCible() == listEnnemi[j] )
						{
							degatTot += listMissile[k].getDegat();
						}
					}

					if(degatTot < listEnnemi[j]->getVie())
					{
						Missile missile(listTour[i]->getDegatMissile(),listTour[i]->getVitesseMissile(),listEnnemi[j],scene.addPixmap(listTour[i]->getApparenceMissile()),centreTour.x(),centreTour.y(),listTour[i]->getType());
						listMissile.append(missile);
						listTour[i]->viensDeTirer();
					}
				}
			}
		}
	}
}
void Plateau::updateMissile()
{
	for(int i=0; i<listMissile.size();i++)
	{
		listMissile[i].mouvement(&scene, &listMissile, i);
	}
}
void Plateau::updateEnnemiVivant()
{
	for(int i=0;i<listEnnemi.size();i++)
	{
		if(!listEnnemi[i]->getEnVie())
		{
			argent += listEnnemi[i]->getDrop();
			scene.removeItem(listEnnemi[i]->getBarreDeVie());
			scene.removeItem(listEnnemi[i]->getApparence());
			listEnnemi[i]->~Ennemi();
			listEnnemi.removeAt(i);
			textArgent->setDefaultTextColor(Qt::green);
			QTimer::singleShot(500, this, SLOT(gainArgent()));
                        textArgent->setPlainText("Argent :  "+QString::number(argent));
			textVague->setPlainText("Vague : "+QString::number(numVague+1)+"/"+QString::number(listVague.size())+"\nMonstre : "+QString::number(listEnnemi.size()));

			if(listEnnemi.size() == 0) // si tous les ennemis sont morts
			{
				QTimer::singleShot(1000, this, SLOT(interet()));
				QTimer::singleShot(tempsEntreVague, this, SLOT(vagueSuivante()));
			}
		}
	}
}
void Plateau::vagueSuivante()
{
	if(numVague < listVague.size()-1)
	{
		numVague ++;
		listEnnemi = listVague[numVague];

		for(int i=0;i<listEnnemi.size();i++)
                {
                    listEnnemi[i]->setApparence(scene.addPixmap(listEnnemi[i]->getTypeApparence()));
                    //listEnnemi[i]->setBarreDeVie(scene.addLine(QLineF(listPoint[0].x()-diff.x()-100*i+1,listPoint[0].y()-diff.y()-6,listPoint[0].x()-diff.x()-100*i +60+2 ,listPoint[0].y()-diff.y()-6),QPen(Qt::green,4)));
                    listEnnemi[i]->getApparence()->setPos(listPoint[0].x()-diff.x()-100*i,listPoint[0].y()-diff.y());
                    listEnnemi[i]->demarrerAnimation(&listPoint);
		}
		textVague->setPlainText("Vague : "+QString::number(numVague+1)+"/"+QString::number(listVague.size())+"\nMonstre :"+QString::number(listEnnemi.size()));

		textInteret->hide();
		bandeauInteret->hide();
	}
	else
	{
		QMessageBox::information(this,"Debug","Vous avez gagné !!!");
	}
}

void Plateau::timerEvent(QTimerEvent* timerEvent)
{
	if(timerEvent->timerId() == timer->timerId() )
	{
		timer->stop();
		if(vie > 0)
		{
			Plateau::update();
			timer->start(25,this);
		}
	}
}

void Plateau::triEnnemi()
{
	if(listEnnemi.size() > 0)
	{
		int trajetParcouru = listEnnemi[0]->getNbTrajet();
		QPoint distance = listEnnemi[0]->getDistTrajet();
		bool changement = true;
		int antecedent = 0;

		while(changement)
		{
			changement = false;
			for(int i=1;i<listEnnemi.size();i++)
			{
				if(listEnnemi[i]->getNbTrajet() == trajetParcouru)
				{
					if(listEnnemi[i]->getDistTrajet().x() < distance.x() || listEnnemi[i]->getDistTrajet().y() < distance.y())
					{
						trajetParcouru = listEnnemi[i]->getNbTrajet();
						distance = listEnnemi[i]->getDistTrajet();
	
						listEnnemi.swap(i,antecedent);
						antecedent = i;
                                                changement = true;
					}
				}
			}
		}
	}
}

void Plateau::victoire()
{
	vie--;

	maison->setPixmap(QPixmap("systeme/Plateau/maison"+QString::number(vie)+".png"));

	if( vie <= 0)
	{
		QMessageBox::critical(this,"Game Debug","VOUS AVEZ PERDU !!!!!");
	}
}


void Plateau::obtentionSetting(int lvl)
{
        QSettings settings("systeme/Niveau/Niveau"+QString::number(lvl)+"/setting.ini", QSettings::IniFormat);
//**********************************************Partie Zone Constructible*******************************************************
	settings.beginGroup("ZC");
		
	QStringList listLigne = settings.childKeys();

	for(int i=0;i<listLigne.size();i++)
	{
		QString textLigne = settings.value(listLigne[i]).toString();
		QList<bool> ligne;

		for(int j=0;j<textLigne.size();j++)
		{
			if(textLigne[j] == '0')
			{
				ligne.append(false);
			}
			else
			{
				ligne.append(true);
			}
		}
		ZC.append(ligne);
	}

	settings.endGroup();
//********************************************Partie Liste des points de passages***************************************************
	settings.beginGroup("listPoint");
	listLigne = settings.childKeys();

	for(int i=0;i<listLigne.size();i++)
	{
		listPoint.append(settings.value(listLigne[i]).value<QPoint>()); //@ au lieu du Q et pas de virgule
	}
	settings.endGroup();
//*******************************************Partie vagues des ennemies**************************************************************
	settings.beginGroup("Vague");

	listLigne = settings.childKeys();

	for(int i=0;i<listLigne.size();i++)
	{
		QString textLigne = settings.value(listLigne[i]).toString();
		QList<Ennemi*> ligne;

		for(int j=0;j<textLigne.size();j++)
		{
			if(textLigne[j] == '1')
			{
				Ennemi* ennemi = new Ennemi(1, &scene);
				ligne.append(ennemi);
			}
			else if(textLigne[j] == '2')
			{
				Ennemi* ennemi = new Ennemi(2, &scene);
				ligne.append(ennemi);
			}
			else if(textLigne[j] == '3')
			{
				Ennemi* ennemi = new Ennemi(3, &scene);
				ligne.append(ennemi);
			}
			else if(textLigne[j] == '4')
			{
				Ennemi* ennemi = new Ennemi(4, &scene);
				ligne.append(ennemi);
			}
			else if(textLigne[j] == '5')
			{
				Ennemi* ennemi = new Ennemi(5, &scene);
				ligne.append(ennemi);
			}
		}
		listVague.append(ligne);
	}
	settings.endGroup();

	VIE_P =  settings.value("vie").toInt() ;
	ARGENT_P = settings.value("argent").toInt() ;
	TPS_VG =  settings.value("tempsEntreVague").toInt() ;
}



bool Plateau::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::ChildAdded || event->type() == QEvent::Close || event->type() == QEvent::CursorChange
		|| event->type() == QEvent::EnabledChange || event->type() == QEvent::GraphicsSceneHoverEnter
		|| event->type() == QEvent::GraphicsSceneHoverLeave || event->type() == QEvent::GraphicsSceneMousePress 
		|| event->type() == QEvent::Hide || event->type() == QEvent::Paint || event->type() == QEvent::Show
		|| event->type() == QEvent::Timer || event->type() == QEvent::ToolTip
	    || event->type() == QEvent::UpdateRequest  || event->type() == QEvent::ZOrderChange
		|| event->type() == QEvent::MouseButtonPress)
	{
          return QObject::eventFilter(obj, event);
    } 
	else
	{
		return true;     
    }
 }

void Plateau::tropCher()
{
    if( argent < PRIX_1 )
    {
        QGraphicsColorizeEffect* disable = new QGraphicsColorizeEffect();
        disable->setColor(Qt::red);
        disable->setStrength(0.7);

        tour1->setGraphicsEffect( disable );

    }
    else if( rechargeT1 == false )
    {
        this->constructionTourEnable1();
    }

    if( argent < PRIX_2 )
    {
        QGraphicsColorizeEffect* disable = new QGraphicsColorizeEffect();
        disable->setColor(Qt::red);
        disable->setStrength(0.7);

        tour2->setGraphicsEffect( disable );
    }
    else if( rechargeT2 == false )
    {
        this->constructionTourEnable2();
    }

    if( argent < PRIX_3 )
    {
        QGraphicsColorizeEffect* disable = new QGraphicsColorizeEffect();
        disable->setColor(Qt::red);
        disable->setStrength(0.7);

        tour3->setGraphicsEffect( disable );
    }
    else if( rechargeT3 == false )
    {
        this->constructionTourEnable3();
    }

    if( argent < PRIX_4 )
    {
        QGraphicsColorizeEffect* disable = new QGraphicsColorizeEffect();
        disable->setColor(Qt::red);
        disable->setStrength(0.7);

        tour4->setGraphicsEffect( disable );
    }
    else if( rechargeT4 == false )
    {
        this->constructionTourEnable4();
    }

    if( argent < PRIX_5 )
    {
        QGraphicsColorizeEffect* disable = new QGraphicsColorizeEffect();
        disable->setColor(Qt::red);
        disable->setStrength(0.7);

        tour5->setGraphicsEffect( disable );
    }
    else if( rechargeT5 == false )
    {
        this->constructionTourEnable5();
    }

}

