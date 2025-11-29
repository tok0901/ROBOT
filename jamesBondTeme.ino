#include <dummy.h>
#include <Arduino.h>

//拍数(周波数)一覧
#define DURANATION_4     1000
#define DURANATION_8     500
#define DURANATION_16    250
#define DURANATION_24    125
#define DURANATION_32    60

//音階一覧
#define NONE    0   //消音

#define DO3     131 //ド    (C3)
#define DO4     262 //      (C4)	  262
#define DO5     523 //      (C5)	  523
#define DO6    1046 //      (C6)    1046
#define DO4_C   277 //ド#   (C#4)	  277
#define DO5_C   554 //      (C#5)   554
#define DO6_C  1108 //      (C#6)   1108

#define RE3     147 //レ    (D3)
#define RE4     294 //      (D4)	  294
#define RE5     588 //　    (D5)    588
#define RE6    1176 //      (D6)    1176
#define RE4_C   311 //レ#   (D#4)	  311
#define RE5_C   622 //      (D#5)
#define RE4_F   277 //レ♭  (Db4)   277

#define MI3     165 //ミ    (E3)
#define MI4     330 //      (E4)	  330
#define MI5     660 //      (E5)    660
#define MI6    1320 //      (E6)    1320 
#define MI4_C   349 //ミ#   (E#4)
#define MI5_C   698 //      (E#5)
#define MI6_C  1396 //      (E#6)
#define MI4_F   311 //ミ♭  (Eb4)   311
#define MI5_F   622 //      (Eb5)
#define MI6_F  1244 //      (Eb6)

#define FA3     175 //ファ  (F3)
#define FA4     349 //      (F4)	  349
#define FA5     698 //      (F5)
#define FA4_C   370 //ファ# (F#4)	  370
#define FA5_C   740 //      (F#5)

#define SO3     196 //ソ    (G3)      
#define SO4     392 //      (G4)	  392
#define SO5     784 //      (G5)    784
#define SO4_C   415 //ソ#   (G#4)	  415
#define SO4_F   370 //ソ♭  (Gb4)   370

#define RA4     440 //ラ    (A4)	  440（基準音）
#define RA5     880 //      (A5)
#define RA4_C   466 //ラ#   (A#4)	  466
#define RA5_C   932 //      (A#5)   932
#define RA4_F   415 //ラ♭  (Ab4)   415

#define SI3     247 //シ    (B3)
#define SI4     494 //      (B4)	  494
#define SI5     988 //      (B5)    988
#define SI4_F   466 //シ♭  (Bb4)   466
#define SI5_F   932 //      (Bb5)

//音符(25列区切り)
int james[]  = {SI4  ,SO4  ,NONE ,SO4  ,DO5  ,SO4  ,NONE ,SO4  ,DO5_C,SO4  ,NONE ,SO4  ,DO5_C,SO4  ,NONE ,SO4  ,SI5  ,SO5  ,NONE ,SO5  ,DO6  ,SO5  ,NONE ,SO5  ,DO6_C,
                SO5  ,NONE ,SO5  ,DO6_C,MI5  ,SO5  ,MI6_F,RE6  ,SO5  ,RA5_C,SI5  ,SO4  ,RA4  ,SO4  ,FA4_C,MI4  ,DO4_C,MI5  ,SO5  ,MI6_F,RE6  ,SO5  ,RA5_C,SI5  ,SO5  ,
                RA5  ,SO5  ,FA5_C,RE5_C,MI5  ,NONE ,MI5  ,NONE ,MI5  ,NONE ,MI5  ,FA5_C,MI5  ,FA5_C,SO5  ,NONE ,SO5  ,NONE ,SO5  ,FA5_C,MI5  ,FA5_C,MI5  ,NONE ,MI5  ,
                NONE ,MI5  ,FA5_C,MI5  ,FA5_C,SO5  ,NONE ,SO5  ,SI5  ,SO5  ,FA5_C,NONE ,SI5  ,NONE ,SI5  ,NONE ,SI3  ,NONE ,SI3  ,SI5  ,NONE ,SI5  ,NONE ,SI3  ,NONE ,
                SI3  ,SI5  ,MI5  ,SI5  ,NONE ,SI5  ,MI5  ,MI4  ,SO4  ,MI5_F,RE5  ,SO3  ,SI3  ,FA4  ,MI4  ,SI4  ,RE5  ,SI5_F,RA5  ,MI5  ,SO5  ,MI6_F,RE6  ,RE4  ,NONE ,
                RE4  ,NONE ,SO3  ,FA3  ,MI3  ,RE3  ,DO3  ,}; 

//音符長さ(25列区切り)
int delays_james[] = {420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,60   ,20   ,500  ,420  ,
                60   ,20   ,500  ,1000 ,400  ,450  ,200  ,1000 ,200  ,300  ,2000 ,400  ,100  ,100  ,1000 ,400  ,2000 ,400  ,450  ,200  ,1000 ,200  ,300  ,2000 ,400  ,
                100  ,100  ,1000 ,400  ,2000 ,20   ,400  ,20   ,100  ,20   ,450  ,400  ,100  ,450  ,400  ,20   ,100  ,20   ,450  ,400  ,100  ,450  ,400  ,20   ,100  ,
                20   ,450  ,400  ,100  ,450  ,400  ,20   ,100  ,400  ,100  ,500  ,450  ,400  ,20   ,250  ,200  ,100  ,20   ,400  ,400  ,20   ,250  ,200  ,100  ,20   ,
                400  ,400  ,100  ,100  ,60   ,400  ,200  ,400  ,450  ,200  ,400  ,400  ,450  ,200  ,400  ,400  ,450  ,200  ,400  ,400  ,450  ,200  ,2000 ,400  ,60   ,
                400  ,200  ,1000 ,60   ,60   ,60   ,2000 ,};

#define BUZZER_PIN 4        //ピン番号(スピーカーへPWM出力)
#define CHANNEL    0        //チャンネル
#define FREQUENCY  1000     //初期周波数
#define RESOLUTION 8        //解像度
#define VOLUME     1        //ボリューム(指定範囲0~255)
#define NON_VOLUME 0        //消音
#define NOTES_NUM  132       //音符数

void setup() {

  ledcSetup(CHANNEL , FREQUENCY,RESOLUTION);
  ledcAttachPin(BUZZER_PIN,0);

  for(int i=0;i<NOTES_NUM;i++){
    ledcWriteTone(CHANNEL,james[i]);       //周波数(音階)指定
    if(james[i] == 0){
      ledcWrite(CHANNEL,NON_VOLUME);       //消音
    }
    else{
      ledcWrite(CHANNEL,VOLUME);           //ボリューム指定
    }
    delay(delays_james[i]);                      //拍数指定
  }
  
  ledcWrite(CHANNEL,0);                    //音声停止
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("test");
  delay(1000);
}
