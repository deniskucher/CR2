void function ZDMSH
{
  int TT = 100;	    //Период задачи	
  int TM = 500/TT;  //Период мигания
  int SM = 0;	    //Счетчик периода мигания
  bool PM = false;  //Признак мигания
  int n = 99;       //Кол-во задвижек
  bool SG[n];	    //Подсветка зеленым			
  bool SGR[n];	    //Подсветка ровным зеленым			
  bool SGM[n];	    //Подсветка мигающим зеленым			
  bool SY[n];	    //Подсветка желтым			
  bool SYR[n];	    //Подсветка ровным желтым
  bool SYM[n];	    //Подсветка мигающим желтым

  if (SM++ == TM) {
    SM = 0;
    PM = !PM; 
  }

  for (i = 0; i < n; ++i) {
    if (PM) {
      SG[i] = SGM[i];
      SY[i] = SYM[i];
    }
    else {
      SG[i] = SGR[i];
      SY[i] = SYR[i];
    }
  }
};