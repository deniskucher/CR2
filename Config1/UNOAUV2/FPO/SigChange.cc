
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  char *pPI21AJ03KNMC;
  char *pPI21AJ05KNMG;
  char *pPI21AC01DTS;
  char *pPI21AD03DTS;
  char *pPI21AE05DTS;
  char *pRN17D02NN;
  char *pRN17D02SGMN;
  char *pRN17D02SGP;
  char *pRN17D02SYMN;
  char *pRN17D02SYP;
  char *pRN17D03NN;
  char *pRN17D03SGMN;
  char *pRN17D03SGP;
  char *pRN17D03SYMN;
  char *pRN17D03SYP;
  char *pPI21AC01TS;
  char *pPI21AD03TS;
  char *pPI21AE05TS;

  void Init_P()
 {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  GET_REF(pPI21AJ03KNMC,char,DEF_DI_BY_ID,0);
  GET_REF(pPI21AJ05KNMG,char,DEF_DI_BY_ID,1);
	////// сигналы DO 
  GET_REF(pPI21AC01DTS,char,DEF_DO_BY_ID,0);
  GET_REF(pPI21AD03DTS,char,DEF_DO_BY_ID,1);
  GET_REF(pPI21AE05DTS,char,DEF_DO_BY_ID,2);
  GET_REF(pRN17D02NN,char,DEF_DO_BY_ID,3);
  GET_REF(pRN17D02SGMN,char,DEF_DO_BY_ID,4);
  GET_REF(pRN17D02SGP,char,DEF_DO_BY_ID,5);
  GET_REF(pRN17D02SYMN,char,DEF_DO_BY_ID,6);
  GET_REF(pRN17D02SYP,char,DEF_DO_BY_ID,7);
  GET_REF(pRN17D03NN,char,DEF_DO_BY_ID,8);
  GET_REF(pRN17D03SGMN,char,DEF_DO_BY_ID,9);
  GET_REF(pRN17D03SGP,char,DEF_DO_BY_ID,10);
  GET_REF(pRN17D03SYMN,char,DEF_DO_BY_ID,11);
  GET_REF(pRN17D03SYP,char,DEF_DO_BY_ID,12);
	////// сигналы PFD 
  GET_REF(pPI21AC01TS,char,DEF_PFD_BY_ID,0);
  GET_REF(pPI21AD03TS,char,DEF_PFD_BY_ID,1);
  GET_REF(pPI21AE05TS,char,DEF_PFD_BY_ID,2);
	////// сигналы KL 
	////// сигналы PIN 
  };

  void Read_Sig()
  {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  _PI21AJ03KNMC=(bool)*pPI21AJ03KNMC;
  _PI21AJ05KNMG=(bool)*pPI21AJ05KNMG;
	////// сигналы DO 
  _PI21AC01DTS=(bool)*pPI21AC01DTS;
  _PI21AD03DTS=(bool)*pPI21AD03DTS;
  _PI21AE05DTS=(bool)*pPI21AE05DTS;
  _RN17D02NN=(bool)*pRN17D02NN;
  _RN17D02SGMN=(bool)*pRN17D02SGMN;
  _RN17D02SGP=(bool)*pRN17D02SGP;
  _RN17D02SYMN=(bool)*pRN17D02SYMN;
  _RN17D02SYP=(bool)*pRN17D02SYP;
  _RN17D03NN=(bool)*pRN17D03NN;
  _RN17D03SGMN=(bool)*pRN17D03SGMN;
  _RN17D03SGP=(bool)*pRN17D03SGP;
  _RN17D03SYMN=(bool)*pRN17D03SYMN;
  _RN17D03SYP=(bool)*pRN17D03SYP;
	////// сигналы PFD 
  _PI21AC01TS=(bool)*pPI21AC01TS;
  _PI21AD03TS=(bool)*pPI21AD03TS;
  _PI21AE05TS=(bool)*pPI21AE05TS;
	////// сигналы KL 
	////// сигналы PIN 
  };
  void Write_Sig()
  {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  *pPI21AJ03KNMC=(char)_PI21AJ03KNMC;
  *pPI21AJ05KNMG=(char)_PI21AJ05KNMG;
	////// сигналы DO 
  *pPI21AC01DTS=(char)_PI21AC01DTS;
  *pPI21AD03DTS=(char)_PI21AD03DTS;
  *pPI21AE05DTS=(char)_PI21AE05DTS;
  *pRN17D02NN=(char)_RN17D02NN;
  *pRN17D02SGMN=(char)_RN17D02SGMN;
  *pRN17D02SGP=(char)_RN17D02SGP;
  *pRN17D02SYMN=(char)_RN17D02SYMN;
  *pRN17D02SYP=(char)_RN17D02SYP;
  *pRN17D03NN=(char)_RN17D03NN;
  *pRN17D03SGMN=(char)_RN17D03SGMN;
  *pRN17D03SGP=(char)_RN17D03SGP;
  *pRN17D03SYMN=(char)_RN17D03SYMN;
  *pRN17D03SYP=(char)_RN17D03SYP;
	////// сигналы PFD 
  *pPI21AC01TS=(char)_PI21AC01TS;
  *pPI21AD03TS=(char)_PI21AD03TS;
  *pPI21AE05TS=(char)_PI21AE05TS;
	////// сигналы KL 
	////// сигналы PIN 
  };
