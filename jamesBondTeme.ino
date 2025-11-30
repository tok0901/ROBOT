//音声出力関数(JamesBondTheme)
void outputAudioJamesBondTheme(){

  //音符数
  int notesNumJames  = 132;

  //楽譜(25列区切り)
  int james[]        = {SI4  ,SO4  ,NONE ,SO4  ,DO5  ,SO4  ,NONE ,SO4  ,DO5_C,SO4  ,NONE ,SO4  ,DO5_C,SO4  ,NONE ,SO4  ,SI5  ,SO5  ,NONE ,SO5  ,DO6  ,SO5  ,NONE ,SO5  ,DO6_C,
                        SO5  ,NONE ,SO5  ,DO6_C,MI5  ,SO5  ,MI6_F,RE6  ,SO5  ,RA5_C,SI5  ,SO4  ,RA4  ,SO4  ,FA4_C,MI4  ,DO4_C,MI5  ,SO5  ,MI6_F,RE6  ,SO5  ,RA5_C,SI5  ,SO5  ,
                        RA5  ,SO5  ,FA5_C,RE5_C,MI5  ,NONE ,MI5  ,NONE ,MI5  ,NONE ,MI5  ,FA5_C,MI5  ,FA5_C,SO5  ,NONE ,SO5  ,NONE ,SO5  ,FA5_C,MI5  ,FA5_C,MI5  ,NONE ,MI5  ,
                        NONE ,MI5  ,FA5_C,MI5  ,FA5_C,SO5  ,NONE ,SO5  ,SI5  ,SO5  ,FA5_C,NONE ,SI5  ,NONE ,SI5  ,NONE ,SI3  ,NONE ,SI3  ,SI5  ,NONE ,SI5  ,NONE ,SI3  ,NONE ,
                        SI3  ,SI5  ,MI5  ,SI5  ,NONE ,SI5  ,MI5  ,MI4  ,SO4  ,MI5_F,RE5  ,SO3  ,SI3  ,FA4  ,MI4  ,SI4  ,RE5  ,SI5_F,RA5  ,MI5  ,SO5  ,MI6_F,RE6  ,RE4  ,NONE ,
                        RE4  ,NONE ,SO3  ,FA3  ,MI3  ,RE3  ,DO3  ,}; 

  //音符長さ(25列区切り)
  int delaysJames[]  = {420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,
                        60   ,20   ,500  ,1000 ,400  ,450  ,200  ,1000 ,200  ,300  ,2000 ,400  ,100  ,100  ,1000 ,400  ,2000 ,400  ,450  ,200  ,1000 ,200  ,300  ,2000 ,400  ,
                        100  ,100  ,1000 ,400  ,2000 ,20   ,400  ,20   ,100  ,20   ,450  ,400  ,100  ,450  ,400  ,20   ,100  ,20   ,450  ,400  ,100  ,450  ,400  ,20   ,100  ,
                        20   ,450  ,400  ,100  ,450  ,400  ,20   ,100  ,400  ,100  ,500  ,450  ,400  ,20   ,250  ,200  ,100  ,20   ,400  ,400  ,20   ,250  ,200  ,100  ,20   ,
                        400  ,400  ,100  ,100  ,60   ,400  ,200  ,400  ,450  ,200  ,400  ,400  ,450  ,200  ,400  ,400  ,450  ,200  ,400  ,400  ,450  ,200  ,2000 ,400  ,60   ,
                        400  ,200  ,1000 ,60   ,60   ,60   ,2000 ,};
  
  //楽譜再生
  for(int i=0;i<notesNumJames;i++){
    ledcWriteTone(CHANNEL,james[i]);       //周波数(音階)指定
    if(james[i] == 0){
      ledcWrite(CHANNEL,NONE);             //消音
    }
    else{
      ledcWrite(CHANNEL,VOLUME);           //ボリューム指定
    }
    delay(delaysJames[i]);                 //拍数指定
  }
  
  ledcWrite(CHANNEL,0);                    //音声停止
  
}
