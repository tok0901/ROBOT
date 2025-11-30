//音声出力関数(MissionImpossibleTheme)
void outputAudioMissionImpossibleTheme(){

  //音符数
  int notesNumMission = 49;

  //楽譜(25列区切り)
  int mission[]       = {MI4  ,NONE ,MI4  ,NONE ,SO4  ,RA4  ,MI4  ,NONE ,MI4  ,NONE ,RE4  ,RE4_C,MI4  ,NONE ,MI4  ,NONE ,SO4  ,RA4  ,MI4  ,NONE ,MI4  ,NONE ,RE4  ,RE4_C,MI4  ,
                         NONE ,MI4  ,NONE ,SO4  ,RA4  ,MI4  ,NONE ,MI4  ,NONE ,RE4  ,RE4_C,SI5  ,SO5  ,RE5  ,SI5  ,SO5  ,RE5_F,SI5  ,SO5  ,DO5  ,SI4  ,DO5  ,NONE ,SI4  ,};

  //音符長さ(25列区切り)
  int delaysMission[] = {400  ,100  ,400  ,100  ,400  ,400  ,400  ,100  ,400  ,100  ,400  ,400  ,400  ,100  ,400  ,100  ,400  ,400  ,400  ,100  ,400  ,100  ,400  ,400  ,400  ,
                         100  ,400  ,100  ,400  ,400  ,400  ,100  ,400  ,100  ,400  ,400  ,200  ,200  ,1500 ,200  ,200  ,1500 ,200  ,200  ,1500 ,200  ,200  ,1300 ,200  ,};

  //楽譜再生
  for(int i=0;i<notesNumMission;i++){
    ledcWriteTone(CHANNEL,mission[i]);       //周波数(音階)指定
    if(mission[i] == 0){
      ledcWrite(CHANNEL,NONE);               //消音
    }
    else{
      ledcWrite(CHANNEL,VOLUME);             //ボリューム指定
    }
    delay(delaysMission[i]);                 //拍数指定
  }
  
  ledcWrite(CHANNEL,0);                      //音声停止

}
