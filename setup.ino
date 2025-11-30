void setup() {
  
  //設定値定義
  int frequency  = 1000;    //初期周波数
  int resolution = 8;       //解像度
  int buzzerPin  = 4;       //ピン番号(スピーカーへPWM出力)

  ledcSetup(CHANNEL,frequency,resolution);
  ledcAttachPin(buzzerPin,0);

  //outputAudioJamesBondTheme();
  outputAudioMissionImpossibleTheme();
}
