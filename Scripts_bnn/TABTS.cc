
#include "globals.h" 
#include "TABTS.h" 


  int TT = 100;     //������ ������	
  int TMC = 500/TT;	 //������ ��������
  int SMC = 0;		 //������� ������� ��������
  bool PMC = false;	 //������� ��������
  int TMG = 500/TT;	 //������ �������
  int SMG = 0;		 //������� ������� �������
  bool PMG  =false;	 //������� �������
  //bool KNMC =false;	 //������ ��������
  //bool KNMG =false;      //������ �������

  int n = 3;        //���-��  ��������� �� 
  bool TS[3] = {    //��������� ��
    _PI12AB01TS,
    _PI12AB05TS,
    _PI12AB09TS
  };
  bool DTS[3] = {    //������ �� �����
    _PI12AB01DTS,
    _PI12AB05DTS,
    _PI12AB09DTS
  };
   bool KNMC = _PI12AG03KNMC;  //������ �������� 
   bool KNMG = _PI12AG05KNMG;  //������ ������� 
  bool PTS[3] = {    //������� i-�� ��������� ��
    false,
    false,
    false
  };
  bool PRMC[3] = {    //������� �������� i-�� ��������� ��
    false,
    false,
    false
  };
  bool PRMG[3] = {    //������� ������� i-�� ��������� ��
    false,
    false,
    false
  };
  bool PRR[3] = {    //������� ������� �������� i-�� ��������� ��
    false,
    false,
    false
  };

  void  _TABTSS()
{
  if (SMC++ == TMC)
  {
    SMC = 0;
    PMC = !PMC; 
  }

  if (SMC++ == TMC)
  {
    SMG = 0;
    PMG = !PMG; 
  }

int i;
  for (i = 0; i < n; ++i) 
  {
     if (KNMC || PRR[i]) 
       { if (TS[i])
            DTS[i]=PRR[i]=PTS[i]=true; 	
          else 
		{
		 if (PTS[i])
			{ PRMG[i]=true; PRR[i]=PRMC[i]=false; DTS[i]=PMG;}
 		  else  PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=false;
		}
       }
     else
     {
      if (!PRMG[i] && (PRMC[i] || TS[i]))
		{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=false; DTS[i]=PMG;}

      if ((!PRMG[i] && !PRMC[i] && !TS[i]) || (PRMG[i] && KNMG))
		PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=false;
      if (TS[i])
	{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=false; DTS[i]=PMG;}
       else
        { PRMG[i]=true; PRR[i]=PRMC[i]=false; DTS[i]=PMG;}

     }

  }
}
