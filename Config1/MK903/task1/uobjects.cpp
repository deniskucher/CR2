//���樠������ � 㤠����� ��ꥪ⮢
#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TAF *_MXXX_AF;
_TMaxHyst *_L1PR_MxH;
_TMinHyst *_RQ13_BO;
_TAVR *_RN17_AVR;
void InitObjects()
{
  _MXXX_AF = new(_TAF);
  _L1PR_MxH = new(_TMaxHyst);
  _RQ13_BO = new(_TMinHyst);
  _RN17_AVR = new(_TAVR);
}
void DeleteObjects()
{
  delete(_MXXX_AF);
  delete(_L1PR_MxH);
  delete(_RQ13_BO);
  delete(_RN17_AVR);
}
