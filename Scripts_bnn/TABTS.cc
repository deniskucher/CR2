
#include "globals.h" 
#include "TABTS.h" 


  int TT = 100;     //Период задачи	
  int TMC = 500/TT;	 //Период мерцания
  int SMC = 0;		 //Счетчик периода мерцания
  bool PMC = false;	 //Признак мерцания
  int TMG = 500/TT;	 //Период мигания
  int SMG = 0;		 //Счетчик периода мигания
  bool PMG  =false;	 //Признак мигания
  //bool KNMC =false;	 //кнопка мерцания
  //bool KNMG =false;      //кнопка мигания

  int n = 3;        //Кол-во  сообщений ТС 
  bool TS[3] = {    //сообщение ТС
    _PI12AB01TS,
    _PI12AB05TS,
    _PI12AB09TS
  };
  bool DTS[3] = {    //сигнал на табло
    _PI12AB01DTS,
    _PI12AB05DTS,
    _PI12AB09DTS
  };
   bool KNMC = _PI12AG03KNMC;  //кнопка мерцания 
   bool KNMG = _PI12AG05KNMG;  //кнопка мигания 
  bool PTS[3] = {    //Признак i-го сообщения ТС
    false,
    false,
    false
  };
  bool PRMC[3] = {    //Признак мерцания i-го сообщения ТС
    false,
    false,
    false
  };
  bool PRMG[3] = {    //Признак мигания i-го сообщения ТС
    false,
    false,
    false
  };
  bool PRR[3] = {    //Признак ровного свечения i-го сообщения ТС
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
