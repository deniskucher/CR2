void function ZDMSH
{
  int TT = 100;	    //������ ������	
  int TM = 500/TT;  //������ �������
  int SM = 0;	    //������� ������� �������
  bool PM = false;  //������� �������
  int n = 99;       //���-�� ��������
  bool SG[n];	    //��������� �������			
  bool SGR[n];	    //��������� ������ �������			
  bool SGM[n];	    //��������� �������� �������			
  bool SY[n];	    //��������� ������			
  bool SYR[n];	    //��������� ������ ������
  bool SYM[n];	    //��������� �������� ������

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