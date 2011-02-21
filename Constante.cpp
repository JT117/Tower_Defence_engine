#include "Constante.h"

Constante::Constante(void)
{
//**************************************Partie Constantes Tour*****************************************************************
	QSettings settings("systeme/Tour/setting.ini", QSettings::IniFormat);

	settings.beginGroup("Tour1");
		VIE_1 = settings.value("vie").toInt() ;
		PRIX_1 = settings.value("prix").toInt() ; 
		PORTE_1 = settings.value("porte").toInt() ;
		DEGAT_1 = settings.value("degat").toInt() ;
		RECHARGE_1 = settings.value("recharge").toInt() ;
                RECHARGE_CONSTRUCTION_1 = settings.value("rechargeConstruction").toInt() ;
                COEF_SEUIL_1 = settings.value("coefSeuil").toFloat() ;
                SEUIL_1 = settings.value("seuil").toInt() ;
                DIVISEUR_1 = settings.value("diviseur").toInt() ;
	settings.endGroup();

	settings.beginGroup("Tour2");
		VIE_2 = settings.value("vie").toInt() ;
		PRIX_2 = settings.value("prix").toInt() ; 
		PORTE_2 = settings.value("porte").toInt() ;
		DEGAT_2 = settings.value("degat").toInt() ;
		RECHARGE_2 = settings.value("recharge").toInt() ;
                RECHARGE_CONSTRUCTION_2 = settings.value("rechargeConstruction").toInt() ;
                COEF_SEUIL_2 = settings.value("coefSeuil").toFloat() ;
                SEUIL_2 = settings.value("seuil").toInt() ;
                DIVISEUR_2 = settings.value("diviseur").toInt() ;
	settings.endGroup();

	settings.beginGroup("Tour3");
		VIE_3 = settings.value("vie").toInt() ;
		PRIX_3 = settings.value("prix").toInt() ; 
		PORTE_3 = settings.value("porte").toInt() ;
		DEGAT_3 = settings.value("degat").toInt() ;
		RECHARGE_3 = settings.value("recharge").toInt() ;
                RECHARGE_CONSTRUCTION_3 = settings.value("rechargeConstruction").toInt() ;
                COEF_SEUIL_3 = settings.value("coefSeuil").toFloat() ;
                SEUIL_3 = settings.value("seuil").toInt() ;
                DIVISEUR_3 = settings.value("diviseur").toInt() ;
	settings.endGroup();

	settings.beginGroup("Tour4");
		VIE_4 = settings.value("vie").toInt() ;
		PRIX_4 = settings.value("prix").toInt() ; 
		PORTE_4 = settings.value("porte").toInt() ;
		DEGAT_4 = settings.value("degat").toInt() ;
		RECHARGE_4 = settings.value("recharge").toInt() ;
                RECHARGE_CONSTRUCTION_4 = settings.value("rechargeConstruction").toInt() ;
                COEF_SEUIL_4 = settings.value("coefSeuil").toFloat() ;
                SEUIL_4 = settings.value("seuil").toInt() ;
                DIVISEUR_4 = settings.value("diviseur").toInt() ;
	settings.endGroup();

	settings.beginGroup("Tour5");
		VIE_5 = settings.value("vie").toInt() ;
		PRIX_5 = settings.value("prix").toInt() ; 
		PORTE_5 = settings.value("porte").toInt() ;
		DEGAT_5 = settings.value("degat").toInt() ;
		RECHARGE_5 = settings.value("recharge").toInt() ;
                RECHARGE_CONSTRUCTION_5 = settings.value("rechargeConstruction").toInt() ;
                COEF_SEUIL_5 = settings.value("coefSeuil").toFloat() ;
                SEUIL_5 = settings.value("seuil").toInt() ;
                DIVISEUR_5 = settings.value("diviseur").toInt() ;
	settings.endGroup();
//*********************************Partie Constantes Ennemi********************************************************************************
	QSettings settings2("systeme/Ennemi/setting.ini", QSettings::IniFormat);

	settings2.beginGroup("Ennemi1");
		VIE_M_1 = settings2.value("vie").toInt() ;
		DROP_M_1 = settings2.value("drop").toInt() ; 
		VITESSE_M_1 = settings2.value("vitesse").toInt() ;
	settings2.endGroup();

	settings2.beginGroup("Ennemi2");
		VIE_M_2 = settings2.value("vie").toInt() ;
		DROP_M_2 = settings2.value("drop").toInt() ; 
		VITESSE_M_2 = settings2.value("vitesse").toInt() ;
	settings2.endGroup();

	settings2.beginGroup("Ennemi3");
		VIE_M_3 = settings2.value("vie").toInt() ;
		DROP_M_3 = settings2.value("drop").toInt() ; 
		VITESSE_M_3 = settings2.value("vitesse").toInt() ;
		DURE_POISON = settings2.value("durePoison").toInt() ;
		INTER_POISON = settings2.value("interPoison").toInt() ;
		DEGAT_POISON = settings2.value("degatPoison").toInt() ;
	settings2.endGroup();

	settings2.beginGroup("Ennemi4");
		VIE_M_4 = settings2.value("vie").toInt() ;
		DROP_M_4 = settings2.value("drop").toInt() ; 
		VITESSE_M_4 = settings2.value("vitesse").toInt() ;
		DURE_FROID = settings2.value("dureFroid").toInt() ;
		COEF_FROID = settings2.value("coefFroid").toInt() ;
	settings2.endGroup();

	settings2.beginGroup("Ennemi5");
		VIE_M_5 = settings2.value("vie").toInt() ;
		DROP_M_5 = settings2.value("drop").toInt() ; 
		VITESSE_M_5 = settings2.value("vitesse").toInt() ;
	settings2.endGroup();
}

Constante::~Constante(void)
{
}
