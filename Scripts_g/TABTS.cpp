void function TABTS
{
  int TT = 100;     //������ ������	
  int TMC = 500/TT;	 //������ ��������
  int SMC = 0;		 //������� ������� ��������
  bool PMC = false;	 //������� ��������
  int TMG = 500/TT;	 //������ �������
  int SMG = 0;		 //������� ������� �������
  bool PMG = false;	 //������� �������

  int n = 3;        //���-��  ��������� �� 
  bool TS[n] = {    //��������� ������������
    _PI12AB01TS,
    _PI12AB05TS,
    _PI12AB09TS
  };
  bool DTS[n] = {    //������ �� �����
    _PI12AB01DTS,
    _PI12AB05DTS,
    _PI12AB09DTS
  };
  bool KNMC = _PI12AG03KNMC;  //������ �������� 
  bool KNMG = _PI12AG05KNMG;  //������ ������� 
 bool PTS3; 	//������� i-�� ��������� �� 
 bool PRMC3;	//������� �������� i-�� ��������� ��
 bool PRMG3;	//������� ������� i-�� ��������� ��
 bool PRR3;	//������� ������� �������� i-�� ��������� ��
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


  for (i = 0; i < n; ++i) 
  {
     if (KNMC || PRR[i]) 
       { if(TS[i])
            DTS[i]=PRR[i]=PTS[i]=true; 	
          else 
		{
		 if (PTS[i])
			{ PRMG[i]=true; PRR[i]=PRMC[i]=falce; DTS[i]=PMG;}
 		  else  PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=falce;
		}
       }
     else
     {
      if (!PRMG[i] && (PRMC[i] || TS[i]))
		{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=falce; DTS[i]=PMG;}

      if ((!PRMG[i] && !PRMC[i] && !TS[i]) || (PRMG[i] && KNMG))
		PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=falce;
      if (TS[i])
	{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=falce; DTS[i]=PMG;}
       else
        { PRMG[i]=true; PRR[i]=PRMC[i]=falce; DTS[i]=PMG;}

     }

  }
};