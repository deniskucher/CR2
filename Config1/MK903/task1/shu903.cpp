#include "uobjects.h"
#include "globals.h"
#include "shu903.h"

void _FILTR()
{
  smallint _0D = 0;

  _0D = _MXXX_AF->_AF(_MXXXSBRN,_MXXXR,_MXXXTF,_MXXXAMX);
  _MXXXD = _0D;
}

void _BLOK_ZD()
{
  bool _0B = false;
  bool _1B = false;
  bool _15_R = false;
  bool _17_R = false;
  bool _16_R = false;
  bool _18_R = false;

  _0B = _L1PR_MxH->_MaxHyst(_MXXXD,_MXXX1PR,52);
  _PI12AB01TS = _0B;
  _1B = _RQ13_BO->_MinHyst(_M255D,_M255UMN,409);
  _P3OTSPPMN = _1B;
  _15_R = ! _P3OTSPPW;
  _17_R = _1B && _15_R;
  _RQ13S01ZBO = _17_R;
  _16_R = ! _PLPVD7AW;
  _18_R = _0B && _16_R;
  _RN21S06ZBZ = _18_R;
  _RN21S05ZBZ = _18_R;
}

void _AVR()
{
  bool _0N1A01 = false;
  bool _0N1A02 = false;
  bool _0N2A01 = false;
  bool _0N2A02 = false;
  bool _0N3A01 = false;
  bool _0N3A02 = false;

  _RN17_AVR->_AVR(_M255D,_M255F,_M255PMX1,_M255PMX2,_M255PMN,_RN17D01RAB,_RN17D02RAB,_RN17D03RAB,_RN17D01B01,
    _RN17D01B02,_RN17D02B01,_RN17D02B02,_RN17D03B01,_RN17D03B02,_RQ13S01ZAK,_RN17OTKLTV,_RN17D01AOF,_RN17D02AOF,
    _RN17D03AOF,_0N1A01,_0N1A02,_0N2A01,_0N2A02,_0N3A01,_0N3A02);
  _RN17D01ZBO = _0N1A01;
  _RN17D01ZBZ = _0N1A02;
  _RN17D02ZBO = _0N2A01;
  _RN17D02ZBZ = _0N2A02;
  _RN17D03ZBO = _0N3A01;
  _RN17D03ZBZ = _0N3A02;
}

void _TC()
{
  bool _17_R = false;
  bool _18_R = false;
  bool _19_R = false;
  bool _20_R = false;
  bool _21_R = false;

  _17_R = _TPN1B02;
  _PI21AC01TS = _17_R;
  _18_R = _TPN2B02;
  _PI21AD03TS = _18_R;
  _19_R = _TPNOTKL;
  _PI21AE05TS = _19_R;
  _20_R = _RN17D01NCU || _RN17D02NCU || _RN17D03NCU;
  _PI12AB09TS = _20_R;
  _21_R = _RN17D01A01F || _RN17D01A02F || _RN17D02A01F || _RN17D02A02F || _RN17D03A01F || _RN17D03A02F;
  _PI12AB05TS = _21_R;
}

void _shu903()
{

  _FILTR();
  _BLOK_ZD();
  _AVR();
  _TC();
}

