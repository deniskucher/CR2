
#include <unistd.h>
#include <cdsface.h>
#include <cdshead.h>

#include "globals.h"
#include "SigChange.h"
#include "typeBPO.h"
  char *pRN17D02SA1;
  char *pRN17D02SA2;
  char *pRN17D03SA1;
  char *pRN17D03SA2;
  char *pRQ13S01SA1;
  char *pRQ13S01SA2;
  char *pRQ13S01NN;
  char *pRQ13S01SG;
  char *pRQ13S01SO;
  char *pRQ13S01SY;
  char *pRQ13S01SZ;
  char *pRQ13S01SGM;
  char *pRQ13S01SGR;
  char *pRQ13S01SYM;
  char *pRQ13S01SYR;

  void Init_P()
 {
	////// сигналы AI 
	////// сигналы AO 
	////// сигналы PFA 
	////// сигналы KO 
	////// сигналы MRI 
	////// сигналы MRO 
	////// сигналы DI 
  GET_REF(pRN17D02SA1,char,DEF_DI_BY_ID,0);
  GET_REF(pRN17D02SA2,char,DEF_DI_BY_ID,1);
  GET_REF(pRN17D03SA1,char,DEF_DI_BY_ID,2);
  GET_REF(pRN17D03SA2,char,DEF_DI_BY_ID,3);
  GET_REF(pRQ13S01SA1,char,DEF_DI_BY_ID,4);
  GET_REF(pRQ13S01SA2,char,DEF_DI_BY_ID,5);
	////// сигналы DO 
  GET_REF(pRQ13S01NN,char,DEF_DO_BY_ID,0);
  GET_REF(pRQ13S01SG,char,DEF_DO_BY_ID,1);
  GET_REF(pRQ13S01SO,char,DEF_DO_BY_ID,2);
  GET_REF(pRQ13S01SY,char,DEF_DO_BY_ID,3);
  GET_REF(pRQ13S01SZ,char,DEF_DO_BY_ID,4);
	////// сигналы PFD 
  GET_REF(pRQ13S01SGM,char,DEF_PFD_BY_ID,0);
  GET_REF(pRQ13S01SGR,char,DEF_PFD_BY_ID,1);
  GET_REF(pRQ13S01SYM,char,DEF_PFD_BY_ID,2);
  GET_REF(pRQ13S01SYR,char,DEF_PFD_BY_ID,3);
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
  _RN17D02SA1=(bool)*pRN17D02SA1;
  _RN17D02SA2=(bool)*pRN17D02SA2;
  _RN17D03SA1=(bool)*pRN17D03SA1;
  _RN17D03SA2=(bool)*pRN17D03SA2;
  _RQ13S01SA1=(bool)*pRQ13S01SA1;
  _RQ13S01SA2=(bool)*pRQ13S01SA2;
	////// сигналы DO 
  _RQ13S01NN=(bool)*pRQ13S01NN;
  _RQ13S01SG=(bool)*pRQ13S01SG;
  _RQ13S01SO=(bool)*pRQ13S01SO;
  _RQ13S01SY=(bool)*pRQ13S01SY;
  _RQ13S01SZ=(bool)*pRQ13S01SZ;
	////// сигналы PFD 
  _RQ13S01SGM=(bool)*pRQ13S01SGM;
  _RQ13S01SGR=(bool)*pRQ13S01SGR;
  _RQ13S01SYM=(bool)*pRQ13S01SYM;
  _RQ13S01SYR=(bool)*pRQ13S01SYR;
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
  *pRN17D02SA1=(char)_RN17D02SA1;
  *pRN17D02SA2=(char)_RN17D02SA2;
  *pRN17D03SA1=(char)_RN17D03SA1;
  *pRN17D03SA2=(char)_RN17D03SA2;
  *pRQ13S01SA1=(char)_RQ13S01SA1;
  *pRQ13S01SA2=(char)_RQ13S01SA2;
	////// сигналы DO 
  *pRQ13S01NN=(char)_RQ13S01NN;
  *pRQ13S01SG=(char)_RQ13S01SG;
  *pRQ13S01SO=(char)_RQ13S01SO;
  *pRQ13S01SY=(char)_RQ13S01SY;
  *pRQ13S01SZ=(char)_RQ13S01SZ;
	////// сигналы PFD 
  *pRQ13S01SGM=(char)_RQ13S01SGM;
  *pRQ13S01SGR=(char)_RQ13S01SGR;
  *pRQ13S01SYM=(char)_RQ13S01SYM;
  *pRQ13S01SYR=(char)_RQ13S01SYR;
	////// сигналы KL 
	////// сигналы PIN 
  };
