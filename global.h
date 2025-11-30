#include <dummy.h>
#include <Arduino.h>

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
#define RE5_F   554 //      (Db5)

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

//グローバル変数宣言
#define CHANNEL    0        //チャンネル
#define VOLUME     1        //ボリューム
