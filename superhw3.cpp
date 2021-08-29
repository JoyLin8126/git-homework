#define BUTTON1_PIN  7  // 按鈕1的接腳
#define BUTTON2_PIN  8  // 按鈕2的接腳
#define  buzzer 3   // buzzer的接腳
#define Do  523 // Do頻率
#define Re  587 // Re頻率
/*#define Mi  659
#define Fa  698
#define So  784
#define La  880
#define Si  988*/
int buttonState1 = 0;   // 按鈕1的狀態
int buttonState2 = 0;   // 按鈕2的狀態
////////////////////////////////////////
#include <LedControl.h>
#define DIN 12 // din的接腳
#define CLK 11 // clk的接腳
#define CS 10 // cs的接腳
LedControl LC = LedControl(DIN,CLK,CS,1);
void Update(int Map[8][8])
{
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      LC.setLed(0,i,j,Map[i][j]); //更新亮暗
    }
  }
}
int Doled[8][8]={{0,0,0,0,0,0,0,0}, // 顯示圖形
                 {1,1,0,0,0,0,0,0},
                 {1,0,1,0,0,0,0,0},
                 {1,0,0,1,0,0,0,0},
                 {1,0,0,1,0,1,1,1},
                 {1,0,0,1,0,1,0,1},
                 {1,0,0,1,0,1,0,1},
                 {1,1,1,0,0,1,1,1}};
int Reled[8][8]={{0,0,0,0,0,0,0,0}, // 顯示圖形
                 {1,1,1,0,0,0,0,0},
                 {1,0,0,1,0,0,0,0},
                 {1,0,0,1,0,1,1,1},
                 {1,0,1,0,0,1,0,1},
                 {1,1,0,0,0,1,1,1},
                 {1,0,1,0,0,1,0,0},
                 {1,0,0,1,0,1,1,1}};
////////////////////////////////////////////////////
void setup() {
  pinMode(buzzer, OUTPUT);   //設定buzzer的PIN腳
  pinMode(BUTTON1_PIN, INPUT); //設定按鈕1的接腳
  pinMode(BUTTON2_PIN, INPUT); //設定按鈕2的接腳
  pinMode(DIN,OUTPUT); //設定CIN的PIN腳
  pinMode(CS,OUTPUT); //設定CS的PIN腳
  pinMode(CLK,OUTPUT); //設定CLK的PIN腳
  LC.shutdown(0,false); //供不供電
  LC.setIntensity(0,8); //設定亮暗 (0~15)
  LC.clearDisplay(0); //清除顯示
}
////////////////////////////////////////////////////////
void loop() {
  buttonState1 = digitalRead(BUTTON1_PIN);  //讀取按鍵1的狀態
  buttonState2 = digitalRead(BUTTON2_PIN);  //讀取按鍵2的狀態
  if(buttonState1 == HIGH){          //如果按鍵1按了
    tone(buzzer,Do); //發出Do音
    Update(Doled); //顯示Do
  }
  else if(buttonState2 == HIGH){     //如果按鍵2按了
    tone(buzzer,Re); //發出Re音
    Update(Reled); //顯示Re
  }
  else{                           //如果按鍵是未按下
    noTone(buzzer); //不發聲
    LC.clearDisplay(0); //清除顯示
  }    
}
