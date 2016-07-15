
#include "KD.h"
#include "globals.h"

  bool _M255F_1;
  bool _M698F_1;
  bool _M701F_1;
  bool _M702F_1;

_TKD1 *pAI1[KOL_AI1+1]; // +1 worked in case KOL_AI count = 0 
_TKD2 *pAI2[KOL_AI2+1];
_TKD3 *pAI3[KOL_AI3+1];

void Init_KD()
{
 short i;
 for (i=0;i <= KOL_AI1;i++) 
 pAI1[i] = new _TKD1(0,0,0,0,0,0,0,0,0,0,0,0,0); 
 for (i=0;i <= KOL_AI2;i++) 
 pAI2[i] = new _TKD2(0); 
 for (i=0;i <= KOL_AI3;i++) 
 pAI3[i] = new _TKD3(0,0,0,0,0); 

   i=0;
   i=0;
   i=0;
   i=0;
}
void KD_RUN()
{
 short i;
 i=0;
 if (Delay_1m<600) Delay_1m++;
  pAI1[i]->_KD1(_M255, _M255OKD, _M255KRS,
       _M255K1N, _M255K1N, _M255DV, _M255MN,
       _M255MX, _M255SBRN, _M255R, _M255F,
       _M255ZZ, _M255F_1);  i++;
  pAI1[i]->_KD1(_M698, _M698OKD, _M698KRS,
       _M698K1N, _M698K1N, _M698DV, _M698MN,
       _M698MX, _M698SBRN, _M698R, _M698F,
       _M698ZZ, _M698F_1);  i++;
  pAI1[i]->_KD1(_M701, _M701OKD, _M701KRS,
       _M701K1N, _M701K1N, _M701DV, _M701MN,
       _M701MX, _M701SBRN, _M701R, _M701F,
       _M701ZZ, _M701F_1);  i++;
  pAI1[i]->_KD1(_M702, _M702OKD, _M702KRS,
       _M702K1N, _M702K1N, _M702DV, _M702MN,
       _M702MX, _M702SBRN, _M702R, _M702F,
       _M702ZZ, _M702F_1);  i++;
 i=0;
 i=0;
  pAI3[i]->_KD3(_M698R, _M701R, _M702R, _MXXXOKD, _MXXXKRS,
       _MXXXDEL, _MXXXSBRN, _M698F_1, _M701F_1, _M702F_1,
       _MXXXR, _MXXXF, _M698F, _M701F, _M702F, _MXXXZZ,
       _M698KRS, _M701KRS, _M702KRS);  i++;
};
 
