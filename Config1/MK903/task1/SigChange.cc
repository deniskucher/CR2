
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  int *pM255;
  int *pM698;
  int *pM701;
  int *pM702;
  int *pM255D;
  int *pM255R;
  int *pM698R;
  int *pM701R;
  int *pM702R;
  int *pMXXXD;
  int *pMXXXR;
  int *pKSK36PERIODR;
  int *pKSK36POROGR;
  int *pKSK36POROGT;
  int *pM255AMX;
  int *pM255DV;
  int *pM255MN;
  int *pM255MX;
  int *pM255PMN;
  int *pM255PMX1;
  int *pM255PMX2;
  int *pM255TF;
  int *pM255UMN;
  int *pM255ZZ;
  int *pM698DV;
  int *pM698MN;
  int *pM698MX;
  int *pM698ZZ;
  int *pM701DV;
  int *pM701MN;
  int *pM701MX;
  int *pM701ZZ;
  int *pM702DV;
  int *pM702MN;
  int *pM702MX;
  int *pM702ZZ;
  int *pMXXX1PR;
  int *pMXXXAMX;
  int *pMXXXDEL;
  int *pMXXXTF;
  int *pMXXXZZ;
  int *pRN17OTKLTV;
  char *pRN17D01B01;
  char *pRN17D01B02;
  char *pRN17D01NCU;
  char *pRN17D02B01;
  char *pRN17D02B02;
  char *pRN17D02NCU;
  char *pRN17D03B01;
  char *pRN17D03B02;
  char *pRN17D03NCU;
  char *pTPN1B02;
  char *pTPN2B02;
  char *pTPNOTKL;
  char *pM255F;
  char *pM255K1N;
  char *pM698F;
  char *pM698K1N;
  char *pM701F;
  char *pM701K1N;
  char *pM702F;
  char *pM702K1N;
  char *pMXXXF;
  char *pP3OTSPPMN;
  char *pP3OTSPPMN12;
  char *pP3OTSPPMX1;
  char *pP3OTSPPMX2;
  char *pPI12AB01TS;
  char *pPI12AB05TS;
  char *pPI12AB09TS;
  char *pPI21AC01TS;
  char *pPI21AD03TS;
  char *pPI21AE05TS;
  char *pRN17D01A01F;
  char *pRN17D01A02F;
  char *pRN17D01AOF;
  char *pRN17D01OTKL;
  char *pRN17D01VKL;
  char *pRN17D01ZBO;
  char *pRN17D01ZBZ;
  char *pRN17D02A01F;
  char *pRN17D02A02F;
  char *pRN17D02AOF;
  char *pRN17D02OTKL;
  char *pRN17D02VKL;
  char *pRN17D02ZBO;
  char *pRN17D02ZBZ;
  char *pRN17D03A01F;
  char *pRN17D03A02F;
  char *pRN17D03AOF;
  char *pRN17D03OTKL;
  char *pRN17D03VKL;
  char *pRN17D03ZBO;
  char *pRN17D03ZBZ;
  char *pRN21S05ZBZ;
  char *pRN21S06ZBZ;
  char *pRQ13S01ZAK;
  char *pRQ13S01ZBO;
  char *pM255KRS;
  char *pM255OKD;
  char *pM698KRS;
  char *pM698OKD;
  char *pM701KRS;
  char *pM701OKD;
  char *pM702KRS;
  char *pM702OKD;
  char *pMXXXKRS;
  char *pMXXXOKD;
  char *pP3OTSPPW;
  char *pPLPVD7AW;
  char *pRN17D01RAB;
  char *pRN17D02RAB;
  char *pRN17D03RAB;
  char *pM255SBRN;
  char *pM698SBRN;
  char *pM701SBRN;
  char *pM702SBRN;
  char *pMXXXSBRN;

  void Init_P()
 {
	////// ������� AI 
  GET_REF(pM255,int,DEF_AI_BY_ID,0);
  GET_REF(pM698,int,DEF_AI_BY_ID,1);
  GET_REF(pM701,int,DEF_AI_BY_ID,2);
  GET_REF(pM702,int,DEF_AI_BY_ID,3);
	////// ������� AO 
	////// ������� PFA 
  GET_REF(pM255D,int,DEF_PFA_BY_ID,0);
  GET_REF(pM255R,int,DEF_PFA_BY_ID,1);
  GET_REF(pM698R,int,DEF_PFA_BY_ID,2);
  GET_REF(pM701R,int,DEF_PFA_BY_ID,3);
  GET_REF(pM702R,int,DEF_PFA_BY_ID,4);
  GET_REF(pMXXXD,int,DEF_PFA_BY_ID,5);
  GET_REF(pMXXXR,int,DEF_PFA_BY_ID,6);
	////// ������� KO 
  GET_REF(pKSK36PERIODR,int,DEF_KO_BY_ID,0);
  GET_REF(pKSK36POROGR,int,DEF_KO_BY_ID,1);
  GET_REF(pKSK36POROGT,int,DEF_KO_BY_ID,2);
  GET_REF(pM255AMX,int,DEF_KO_BY_ID,3);
  GET_REF(pM255DV,int,DEF_KO_BY_ID,4);
  GET_REF(pM255MN,int,DEF_KO_BY_ID,5);
  GET_REF(pM255MX,int,DEF_KO_BY_ID,6);
  GET_REF(pM255PMN,int,DEF_KO_BY_ID,7);
  GET_REF(pM255PMX1,int,DEF_KO_BY_ID,8);
  GET_REF(pM255PMX2,int,DEF_KO_BY_ID,9);
  GET_REF(pM255TF,int,DEF_KO_BY_ID,10);
  GET_REF(pM255UMN,int,DEF_KO_BY_ID,11);
  GET_REF(pM255ZZ,int,DEF_KO_BY_ID,12);
  GET_REF(pM698DV,int,DEF_KO_BY_ID,13);
  GET_REF(pM698MN,int,DEF_KO_BY_ID,14);
  GET_REF(pM698MX,int,DEF_KO_BY_ID,15);
  GET_REF(pM698ZZ,int,DEF_KO_BY_ID,16);
  GET_REF(pM701DV,int,DEF_KO_BY_ID,17);
  GET_REF(pM701MN,int,DEF_KO_BY_ID,18);
  GET_REF(pM701MX,int,DEF_KO_BY_ID,19);
  GET_REF(pM701ZZ,int,DEF_KO_BY_ID,20);
  GET_REF(pM702DV,int,DEF_KO_BY_ID,21);
  GET_REF(pM702MN,int,DEF_KO_BY_ID,22);
  GET_REF(pM702MX,int,DEF_KO_BY_ID,23);
  GET_REF(pM702ZZ,int,DEF_KO_BY_ID,24);
  GET_REF(pMXXX1PR,int,DEF_KO_BY_ID,25);
  GET_REF(pMXXXAMX,int,DEF_KO_BY_ID,26);
  GET_REF(pMXXXDEL,int,DEF_KO_BY_ID,27);
  GET_REF(pMXXXTF,int,DEF_KO_BY_ID,28);
  GET_REF(pMXXXZZ,int,DEF_KO_BY_ID,29);
  GET_REF(pRN17OTKLTV,int,DEF_KO_BY_ID,30);
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  GET_REF(pRN17D01B01,char,DEF_DI_BY_ID,0);
  GET_REF(pRN17D01B02,char,DEF_DI_BY_ID,1);
  GET_REF(pRN17D01NCU,char,DEF_DI_BY_ID,2);
  GET_REF(pRN17D02B01,char,DEF_DI_BY_ID,3);
  GET_REF(pRN17D02B02,char,DEF_DI_BY_ID,4);
  GET_REF(pRN17D02NCU,char,DEF_DI_BY_ID,5);
  GET_REF(pRN17D03B01,char,DEF_DI_BY_ID,6);
  GET_REF(pRN17D03B02,char,DEF_DI_BY_ID,7);
  GET_REF(pRN17D03NCU,char,DEF_DI_BY_ID,8);
  GET_REF(pTPN1B02,char,DEF_DI_BY_ID,9);
  GET_REF(pTPN2B02,char,DEF_DI_BY_ID,10);
  GET_REF(pTPNOTKL,char,DEF_DI_BY_ID,11);
	////// ������� DO 
	////// ������� PFD 
  GET_REF(pM255F,char,DEF_PFD_BY_ID,0);
  GET_REF(pM255K1N,char,DEF_PFD_BY_ID,1);
  GET_REF(pM698F,char,DEF_PFD_BY_ID,2);
  GET_REF(pM698K1N,char,DEF_PFD_BY_ID,3);
  GET_REF(pM701F,char,DEF_PFD_BY_ID,4);
  GET_REF(pM701K1N,char,DEF_PFD_BY_ID,5);
  GET_REF(pM702F,char,DEF_PFD_BY_ID,6);
  GET_REF(pM702K1N,char,DEF_PFD_BY_ID,7);
  GET_REF(pMXXXF,char,DEF_PFD_BY_ID,8);
  GET_REF(pP3OTSPPMN,char,DEF_PFD_BY_ID,9);
  GET_REF(pP3OTSPPMN12,char,DEF_PFD_BY_ID,10);
  GET_REF(pP3OTSPPMX1,char,DEF_PFD_BY_ID,11);
  GET_REF(pP3OTSPPMX2,char,DEF_PFD_BY_ID,12);
  GET_REF(pPI12AB01TS,char,DEF_PFD_BY_ID,13);
  GET_REF(pPI12AB05TS,char,DEF_PFD_BY_ID,14);
  GET_REF(pPI12AB09TS,char,DEF_PFD_BY_ID,15);
  GET_REF(pPI21AC01TS,char,DEF_PFD_BY_ID,16);
  GET_REF(pPI21AD03TS,char,DEF_PFD_BY_ID,17);
  GET_REF(pPI21AE05TS,char,DEF_PFD_BY_ID,18);
  GET_REF(pRN17D01A01F,char,DEF_PFD_BY_ID,19);
  GET_REF(pRN17D01A02F,char,DEF_PFD_BY_ID,20);
  GET_REF(pRN17D01AOF,char,DEF_PFD_BY_ID,21);
  GET_REF(pRN17D01OTKL,char,DEF_PFD_BY_ID,22);
  GET_REF(pRN17D01VKL,char,DEF_PFD_BY_ID,23);
  GET_REF(pRN17D01ZBO,char,DEF_PFD_BY_ID,24);
  GET_REF(pRN17D01ZBZ,char,DEF_PFD_BY_ID,25);
  GET_REF(pRN17D02A01F,char,DEF_PFD_BY_ID,26);
  GET_REF(pRN17D02A02F,char,DEF_PFD_BY_ID,27);
  GET_REF(pRN17D02AOF,char,DEF_PFD_BY_ID,28);
  GET_REF(pRN17D02OTKL,char,DEF_PFD_BY_ID,29);
  GET_REF(pRN17D02VKL,char,DEF_PFD_BY_ID,30);
  GET_REF(pRN17D02ZBO,char,DEF_PFD_BY_ID,31);
  GET_REF(pRN17D02ZBZ,char,DEF_PFD_BY_ID,32);
  GET_REF(pRN17D03A01F,char,DEF_PFD_BY_ID,33);
  GET_REF(pRN17D03A02F,char,DEF_PFD_BY_ID,34);
  GET_REF(pRN17D03AOF,char,DEF_PFD_BY_ID,35);
  GET_REF(pRN17D03OTKL,char,DEF_PFD_BY_ID,36);
  GET_REF(pRN17D03VKL,char,DEF_PFD_BY_ID,37);
  GET_REF(pRN17D03ZBO,char,DEF_PFD_BY_ID,38);
  GET_REF(pRN17D03ZBZ,char,DEF_PFD_BY_ID,39);
  GET_REF(pRN21S05ZBZ,char,DEF_PFD_BY_ID,40);
  GET_REF(pRN21S06ZBZ,char,DEF_PFD_BY_ID,41);
  GET_REF(pRQ13S01ZAK,char,DEF_PFD_BY_ID,42);
  GET_REF(pRQ13S01ZBO,char,DEF_PFD_BY_ID,43);
	////// ������� KL 
  GET_REF(pM255KRS,char,DEF_KL_BY_ID,0);
  GET_REF(pM255OKD,char,DEF_KL_BY_ID,1);
  GET_REF(pM698KRS,char,DEF_KL_BY_ID,2);
  GET_REF(pM698OKD,char,DEF_KL_BY_ID,3);
  GET_REF(pM701KRS,char,DEF_KL_BY_ID,4);
  GET_REF(pM701OKD,char,DEF_KL_BY_ID,5);
  GET_REF(pM702KRS,char,DEF_KL_BY_ID,6);
  GET_REF(pM702OKD,char,DEF_KL_BY_ID,7);
  GET_REF(pMXXXKRS,char,DEF_KL_BY_ID,8);
  GET_REF(pMXXXOKD,char,DEF_KL_BY_ID,9);
  GET_REF(pP3OTSPPW,char,DEF_KL_BY_ID,10);
  GET_REF(pPLPVD7AW,char,DEF_KL_BY_ID,11);
  GET_REF(pRN17D01RAB,char,DEF_KL_BY_ID,12);
  GET_REF(pRN17D02RAB,char,DEF_KL_BY_ID,13);
  GET_REF(pRN17D03RAB,char,DEF_KL_BY_ID,14);
	////// ������� PIN 
  GET_REF(pM255SBRN,char,DEF_PIN_BY_ID,0);
  GET_REF(pM698SBRN,char,DEF_PIN_BY_ID,1);
  GET_REF(pM701SBRN,char,DEF_PIN_BY_ID,2);
  GET_REF(pM702SBRN,char,DEF_PIN_BY_ID,3);
  GET_REF(pMXXXSBRN,char,DEF_PIN_BY_ID,4);
  };

  void Read_Sig()
  {
	////// ������� AI 
  _M255=(short)*pM255;
  _M698=(short)*pM698;
  _M701=(short)*pM701;
  _M702=(short)*pM702;
	////// ������� AO 
	////// ������� PFA 
  _M255D=(short)*pM255D;
  _M255R=(short)*pM255R;
  _M698R=(short)*pM698R;
  _M701R=(short)*pM701R;
  _M702R=(short)*pM702R;
  _MXXXD=(short)*pMXXXD;
  _MXXXR=(short)*pMXXXR;
	////// ������� KO 
  _KSK36PERIODR=(short)*pKSK36PERIODR;
  _KSK36POROGR=(short)*pKSK36POROGR;
  _KSK36POROGT=(short)*pKSK36POROGT;
  _M255AMX=(short)*pM255AMX;
  _M255DV=(short)*pM255DV;
  _M255MN=(short)*pM255MN;
  _M255MX=(short)*pM255MX;
  _M255PMN=(short)*pM255PMN;
  _M255PMX1=(short)*pM255PMX1;
  _M255PMX2=(short)*pM255PMX2;
  _M255TF=(short)*pM255TF;
  _M255UMN=(short)*pM255UMN;
  _M255ZZ=(short)*pM255ZZ;
  _M698DV=(short)*pM698DV;
  _M698MN=(short)*pM698MN;
  _M698MX=(short)*pM698MX;
  _M698ZZ=(short)*pM698ZZ;
  _M701DV=(short)*pM701DV;
  _M701MN=(short)*pM701MN;
  _M701MX=(short)*pM701MX;
  _M701ZZ=(short)*pM701ZZ;
  _M702DV=(short)*pM702DV;
  _M702MN=(short)*pM702MN;
  _M702MX=(short)*pM702MX;
  _M702ZZ=(short)*pM702ZZ;
  _MXXX1PR=(short)*pMXXX1PR;
  _MXXXAMX=(short)*pMXXXAMX;
  _MXXXDEL=(short)*pMXXXDEL;
  _MXXXTF=(short)*pMXXXTF;
  _MXXXZZ=(short)*pMXXXZZ;
  _RN17OTKLTV=(short)*pRN17OTKLTV;
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  _RN17D01B01=(bool)*pRN17D01B01;
  _RN17D01B02=(bool)*pRN17D01B02;
  _RN17D01NCU=(bool)*pRN17D01NCU;
  _RN17D02B01=(bool)*pRN17D02B01;
  _RN17D02B02=(bool)*pRN17D02B02;
  _RN17D02NCU=(bool)*pRN17D02NCU;
  _RN17D03B01=(bool)*pRN17D03B01;
  _RN17D03B02=(bool)*pRN17D03B02;
  _RN17D03NCU=(bool)*pRN17D03NCU;
  _TPN1B02=(bool)*pTPN1B02;
  _TPN2B02=(bool)*pTPN2B02;
  _TPNOTKL=(bool)*pTPNOTKL;
	////// ������� DO 
	////// ������� PFD 
  _M255F=(bool)*pM255F;
  _M255K1N=(bool)*pM255K1N;
  _M698F=(bool)*pM698F;
  _M698K1N=(bool)*pM698K1N;
  _M701F=(bool)*pM701F;
  _M701K1N=(bool)*pM701K1N;
  _M702F=(bool)*pM702F;
  _M702K1N=(bool)*pM702K1N;
  _MXXXF=(bool)*pMXXXF;
  _P3OTSPPMN=(bool)*pP3OTSPPMN;
  _P3OTSPPMN12=(bool)*pP3OTSPPMN12;
  _P3OTSPPMX1=(bool)*pP3OTSPPMX1;
  _P3OTSPPMX2=(bool)*pP3OTSPPMX2;
  _PI12AB01TS=(bool)*pPI12AB01TS;
  _PI12AB05TS=(bool)*pPI12AB05TS;
  _PI12AB09TS=(bool)*pPI12AB09TS;
  _PI21AC01TS=(bool)*pPI21AC01TS;
  _PI21AD03TS=(bool)*pPI21AD03TS;
  _PI21AE05TS=(bool)*pPI21AE05TS;
  _RN17D01A01F=(bool)*pRN17D01A01F;
  _RN17D01A02F=(bool)*pRN17D01A02F;
  _RN17D01AOF=(bool)*pRN17D01AOF;
  _RN17D01OTKL=(bool)*pRN17D01OTKL;
  _RN17D01VKL=(bool)*pRN17D01VKL;
  _RN17D01ZBO=(bool)*pRN17D01ZBO;
  _RN17D01ZBZ=(bool)*pRN17D01ZBZ;
  _RN17D02A01F=(bool)*pRN17D02A01F;
  _RN17D02A02F=(bool)*pRN17D02A02F;
  _RN17D02AOF=(bool)*pRN17D02AOF;
  _RN17D02OTKL=(bool)*pRN17D02OTKL;
  _RN17D02VKL=(bool)*pRN17D02VKL;
  _RN17D02ZBO=(bool)*pRN17D02ZBO;
  _RN17D02ZBZ=(bool)*pRN17D02ZBZ;
  _RN17D03A01F=(bool)*pRN17D03A01F;
  _RN17D03A02F=(bool)*pRN17D03A02F;
  _RN17D03AOF=(bool)*pRN17D03AOF;
  _RN17D03OTKL=(bool)*pRN17D03OTKL;
  _RN17D03VKL=(bool)*pRN17D03VKL;
  _RN17D03ZBO=(bool)*pRN17D03ZBO;
  _RN17D03ZBZ=(bool)*pRN17D03ZBZ;
  _RN21S05ZBZ=(bool)*pRN21S05ZBZ;
  _RN21S06ZBZ=(bool)*pRN21S06ZBZ;
  _RQ13S01ZAK=(bool)*pRQ13S01ZAK;
  _RQ13S01ZBO=(bool)*pRQ13S01ZBO;
	////// ������� KL 
  _M255KRS=(bool)*pM255KRS;
  _M255OKD=(bool)*pM255OKD;
  _M698KRS=(bool)*pM698KRS;
  _M698OKD=(bool)*pM698OKD;
  _M701KRS=(bool)*pM701KRS;
  _M701OKD=(bool)*pM701OKD;
  _M702KRS=(bool)*pM702KRS;
  _M702OKD=(bool)*pM702OKD;
  _MXXXKRS=(bool)*pMXXXKRS;
  _MXXXOKD=(bool)*pMXXXOKD;
  _P3OTSPPW=(bool)*pP3OTSPPW;
  _PLPVD7AW=(bool)*pPLPVD7AW;
  _RN17D01RAB=(bool)*pRN17D01RAB;
  _RN17D02RAB=(bool)*pRN17D02RAB;
  _RN17D03RAB=(bool)*pRN17D03RAB;
	////// ������� PIN 
  _M255SBRN=(bool)*pM255SBRN;
  _M698SBRN=(bool)*pM698SBRN;
  _M701SBRN=(bool)*pM701SBRN;
  _M702SBRN=(bool)*pM702SBRN;
  _MXXXSBRN=(bool)*pMXXXSBRN;
  };
  void Write_Sig()
  {
	////// ������� AI 
  *pM255=(int)_M255;
  *pM698=(int)_M698;
  *pM701=(int)_M701;
  *pM702=(int)_M702;
	////// ������� AO 
	////// ������� PFA 
  *pM255D=(int)_M255D;
  *pM255R=(int)_M255R;
  *pM698R=(int)_M698R;
  *pM701R=(int)_M701R;
  *pM702R=(int)_M702R;
  *pMXXXD=(int)_MXXXD;
  *pMXXXR=(int)_MXXXR;
	////// ������� KO 
  *pKSK36PERIODR=(int)_KSK36PERIODR;
  *pKSK36POROGR=(int)_KSK36POROGR;
  *pKSK36POROGT=(int)_KSK36POROGT;
  *pM255AMX=(int)_M255AMX;
  *pM255DV=(int)_M255DV;
  *pM255MN=(int)_M255MN;
  *pM255MX=(int)_M255MX;
  *pM255PMN=(int)_M255PMN;
  *pM255PMX1=(int)_M255PMX1;
  *pM255PMX2=(int)_M255PMX2;
  *pM255TF=(int)_M255TF;
  *pM255UMN=(int)_M255UMN;
  *pM255ZZ=(int)_M255ZZ;
  *pM698DV=(int)_M698DV;
  *pM698MN=(int)_M698MN;
  *pM698MX=(int)_M698MX;
  *pM698ZZ=(int)_M698ZZ;
  *pM701DV=(int)_M701DV;
  *pM701MN=(int)_M701MN;
  *pM701MX=(int)_M701MX;
  *pM701ZZ=(int)_M701ZZ;
  *pM702DV=(int)_M702DV;
  *pM702MN=(int)_M702MN;
  *pM702MX=(int)_M702MX;
  *pM702ZZ=(int)_M702ZZ;
  *pMXXX1PR=(int)_MXXX1PR;
  *pMXXXAMX=(int)_MXXXAMX;
  *pMXXXDEL=(int)_MXXXDEL;
  *pMXXXTF=(int)_MXXXTF;
  *pMXXXZZ=(int)_MXXXZZ;
  *pRN17OTKLTV=(int)_RN17OTKLTV;
	////// ������� MRI 
	////// ������� MRO 
	////// ������� DI 
  *pRN17D01B01=(char)_RN17D01B01;
  *pRN17D01B02=(char)_RN17D01B02;
  *pRN17D01NCU=(char)_RN17D01NCU;
  *pRN17D02B01=(char)_RN17D02B01;
  *pRN17D02B02=(char)_RN17D02B02;
  *pRN17D02NCU=(char)_RN17D02NCU;
  *pRN17D03B01=(char)_RN17D03B01;
  *pRN17D03B02=(char)_RN17D03B02;
  *pRN17D03NCU=(char)_RN17D03NCU;
  *pTPN1B02=(char)_TPN1B02;
  *pTPN2B02=(char)_TPN2B02;
  *pTPNOTKL=(char)_TPNOTKL;
	////// ������� DO 
	////// ������� PFD 
  *pM255F=(char)_M255F;
  *pM255K1N=(char)_M255K1N;
  *pM698F=(char)_M698F;
  *pM698K1N=(char)_M698K1N;
  *pM701F=(char)_M701F;
  *pM701K1N=(char)_M701K1N;
  *pM702F=(char)_M702F;
  *pM702K1N=(char)_M702K1N;
  *pMXXXF=(char)_MXXXF;
  *pP3OTSPPMN=(char)_P3OTSPPMN;
  *pP3OTSPPMN12=(char)_P3OTSPPMN12;
  *pP3OTSPPMX1=(char)_P3OTSPPMX1;
  *pP3OTSPPMX2=(char)_P3OTSPPMX2;
  *pPI12AB01TS=(char)_PI12AB01TS;
  *pPI12AB05TS=(char)_PI12AB05TS;
  *pPI12AB09TS=(char)_PI12AB09TS;
  *pPI21AC01TS=(char)_PI21AC01TS;
  *pPI21AD03TS=(char)_PI21AD03TS;
  *pPI21AE05TS=(char)_PI21AE05TS;
  *pRN17D01A01F=(char)_RN17D01A01F;
  *pRN17D01A02F=(char)_RN17D01A02F;
  *pRN17D01AOF=(char)_RN17D01AOF;
  *pRN17D01OTKL=(char)_RN17D01OTKL;
  *pRN17D01VKL=(char)_RN17D01VKL;
  *pRN17D01ZBO=(char)_RN17D01ZBO;
  *pRN17D01ZBZ=(char)_RN17D01ZBZ;
  *pRN17D02A01F=(char)_RN17D02A01F;
  *pRN17D02A02F=(char)_RN17D02A02F;
  *pRN17D02AOF=(char)_RN17D02AOF;
  *pRN17D02OTKL=(char)_RN17D02OTKL;
  *pRN17D02VKL=(char)_RN17D02VKL;
  *pRN17D02ZBO=(char)_RN17D02ZBO;
  *pRN17D02ZBZ=(char)_RN17D02ZBZ;
  *pRN17D03A01F=(char)_RN17D03A01F;
  *pRN17D03A02F=(char)_RN17D03A02F;
  *pRN17D03AOF=(char)_RN17D03AOF;
  *pRN17D03OTKL=(char)_RN17D03OTKL;
  *pRN17D03VKL=(char)_RN17D03VKL;
  *pRN17D03ZBO=(char)_RN17D03ZBO;
  *pRN17D03ZBZ=(char)_RN17D03ZBZ;
  *pRN21S05ZBZ=(char)_RN21S05ZBZ;
  *pRN21S06ZBZ=(char)_RN21S06ZBZ;
  *pRQ13S01ZAK=(char)_RQ13S01ZAK;
  *pRQ13S01ZBO=(char)_RQ13S01ZBO;
	////// ������� KL 
  *pM255KRS=(char)_M255KRS;
  *pM255OKD=(char)_M255OKD;
  *pM698KRS=(char)_M698KRS;
  *pM698OKD=(char)_M698OKD;
  *pM701KRS=(char)_M701KRS;
  *pM701OKD=(char)_M701OKD;
  *pM702KRS=(char)_M702KRS;
  *pM702OKD=(char)_M702OKD;
  *pMXXXKRS=(char)_MXXXKRS;
  *pMXXXOKD=(char)_MXXXOKD;
  *pP3OTSPPW=(char)_P3OTSPPW;
  *pPLPVD7AW=(char)_PLPVD7AW;
  *pRN17D01RAB=(char)_RN17D01RAB;
  *pRN17D02RAB=(char)_RN17D02RAB;
  *pRN17D03RAB=(char)_RN17D03RAB;
	////// ������� PIN 
  *pM255SBRN=(char)_M255SBRN;
  *pM698SBRN=(char)_M698SBRN;
  *pM701SBRN=(char)_M701SBRN;
  *pM702SBRN=(char)_M702SBRN;
  *pMXXXSBRN=(char)_MXXXSBRN;
  };
