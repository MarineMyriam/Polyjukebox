#include <SoftwareSerial.h>

int i=0;
#define RX2 9 // port Bluetooth
#define TX2 10

SoftwareSerial BlueT(RX2,TX2);
char Data;

#include "lcdProg.h"
#define RX 12
#define TX 13

#define BOUTONG 5
#define BOUTONOK 4
#define BOUTOND 3

int val1=0;
int val2=0;
int val3=0;

//const zero= 0X00000;

SoftwareSerial mySerial(RX,TX);

//////////////////// L C D /////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////// 

//all the commands needed in the datasheet(http://geekmatic.in.ua/pdf/Catalex_MP3_board.pdf) 

static int8_t Send_buf[8] = {0} ;//The MP3 player undestands orders in a 8 int string 

                                 //0X7E FF 06 command 00 00 00 EF;(if command =01 next song order)
#define NEXT_SONG 0X01
#define PREV_SONG 0X02
#define CMD_PLAY_W_INDEX 0X03 //DATA IS REQUIRED (number of song) 
#define VOLUME_UP_ONE 0X04 
#define VOLUME_DOWN_ONE 0X05 
#define CMD_SET_VOLUME 0X06//DATA IS REQUIRED (number of volume from 0 up to 30(0x1E)) 
#define SET_DAC 0X17 
#define CMD_PLAY_WITHVOLUME 0X22 //data is needed  0x7E 06 22 00 xx yy EF;(xx volume)(yy number of song) 
#define CMD_SEL_DEV 0X09 //SELECT STORAGE DEVICE, DATA IS REQUIRED 
#define DEV_TF 0X02 //HELLO,IM THE DATA REQUIRED 
#define SLEEP_MODE_START 0X0A 
#define SLEEP_MODE_WAKEUP 0X0B 
#define CMD_RESET 0X0C//CHIP RESET 
#define CMD_PLAY 0X0D //RESUME PLAYBACK 
#define CMD_PAUSE 0X0E //PLAYBACK IS PAUSED 
#define CMD_PLAY_WITHFOLDER 0X0F//DATA IS NEEDED, 0x7E 06 0F 00 01 02 EF;(play the song with the directory \01\002xxxxxx.mp3 
#define STOP_PLAY 0X16 
#define PLAY_FOLDER 0X17// data is needed 0x7E 06 17 00 01 XX EF;(play the 01 folder)(value xx we dont care) 
#define SET_CYCLEPLAY 0X19//data is needed 00 start; 01 close 
#define SET_DAC 0X17//data is needed 00 start DAC OUTPUT;01 DAC no output 
#define SINGLE_PLAY 0X08//Single play(without folder)

////////////////////////////////////////////////////////////////////////////////////
void setup()
{  
  Serial.begin(9600);
  BlueT.begin(9600);
  mySerial.begin(9600);//Start our Serial coms for our serial monitor! 
      affichage();
      i=1;
  
  delay(500);//Wait chip initialization is complete 
  
  sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card
  
  delay(200);
  BlueT.begin(9600);
  
  
  pinMode(BOUTOND,INPUT_PULLUP); //définit le bouton précedent, en entrée numérique sur la broche 1
  pinMode(BOUTONG,INPUT_PULLUP); //définit le bouton selectionner, en entrée numérique sur la broche 2
  pinMode(BOUTONOK,INPUT_PULLUP); //définit le bouton suivant, en entrée numérique sur la broche 3
  //updateMenu();
}

void sendCommand(int8_t command, int8_t dat) { 
  delay(20); 
  Send_buf[0] = 0x7e; //starting byte 
  Send_buf[1] = 0xff; //version 
  Send_buf[2] = 0x06; //the number of bytes of the command without starting byte and ending byte 
  Send_buf[3] = command; // 
  Send_buf[4] = 0x00;//0x00 = no feedback, 0x01 = feedback 
  Send_buf[5] = 0x00;//datah 
  Send_buf[6] = dat; //datal 
  Send_buf[7] = 0xef; //ending byte 
  for(uint8_t j=0; j<8; j++){ 
    mySerial.write(Send_buf[j]) ; 
  } 
}



void loop() {

  
/////////////////// BLUETOOTH ///////////////////////////////////////////

/* if (BlueT.available()){
    Data = char(BlueT.read());
    bluetooth(Data);
 }*/

 

    
//////////TEST///////////////////////////////////////////////////////////

 if (BlueT.available()){

    Data=BlueT.read();
    affichage();
    if (Data=='1') {
      Serial.println("1");
      sendCommand(0x06, 5);
      
      Serial.println("Volume 1");
      }

      
    if (Data=='2') {
      Serial.println("2");
      sendCommand(0x06, 18);
      
      Serial.println("Volume 2");
      }

    if (Data=='3') {
      Serial.println("3");
      sendCommand(0x06, 30);
      
      Serial.println("Volume 3");
    }

    if (Data=='S'){
      i++;
      affichage();
      Serial.println("S");
      sendCommand(0x01, 0);
      
      Serial.println("musique suivante");
    }

    if (Data=='P'){
      i--;
      affichage();
      Serial.println("P");
      sendCommand(0x02, 0);
      
      Serial.println("musique precedente");
    }

    if (Data=='M'){
      Serial.println("M");
      sendCommand(0x0E, 0);
      
      Serial.println("Pause");
    }

    if (Data=='R') {
      Serial.println("R");
      sendCommand(0x0D, 0);
      
      Serial.println("Reprendre");
      }
    
      

 }

   
 
/////////////////// MENU DEROULANT MUSIQUE ///////////////////////////////////
  if(!digitalRead(BOUTONG) ){
      i--;
      affichage();
      
      Serial.println("G");
       delay(100);
      while(!digitalRead(BOUTONG));
      
    }
     if(!digitalRead(BOUTOND)){
      i++;
      
      affichage();
      Serial.println("D");
      delay(100);
      while(!digitalRead(BOUTOND));
    }
    if(!digitalRead(BOUTONOK)){
      Serial.println(i);
     
      sendCommand(SINGLE_PLAY, i);
      delay(100);
      while(!digitalRead(BOUTONOK));
    }



}// fin loop
/*
void bluetooth(char bluet){
  switch(bluet){

    case '1':
      Serial.println("1");
      sendCommand(0x06, 5);
      Serial.println("Volume 1");
      break;

    case '2':
      Serial.println("2");
      sendCommand(0x06, 18);
      Serial.println("Volume 2");
      break;

    case '3':
      Serial.println("3");
      sendCommand(0x06, 30);
      Serial.println("Volume 3");
      break;

    case 'S': //musique suivante
      Serial.println("S");
      sendCommand(0x01, 0);
      Serial.println("musique suivante");
      break;

    case 'P': //musique precedente
      Serial.println("P");
      sendCommand(0x02, 0);
      Serial.println("musique precedente");
      break;

    case 'M':
      Serial.println("M");
      sendCommand(0x0E, 0);
      Serial.println("Pause");
      break;  
      }}*/
//////////////////TEST2/////////////
/* int k=15;
while (k<30 && k>0){
 if (Serial.available()){
    Data=Serial.read();
    if (Data=='G') {
      //Serial.println("G");
      //k+=1;
      sendCommand(CMD_SET_VOLUME, 30);
      //Serial.println("Augmenter le volume");
      }
    if (Data=='D') {
      //Serial.println("D");
      //k-=1;
      sendCommand(CMD_SET_VOLUME, 10);
      //Serial.println("Baisser le volume");
      }
    }
}
*/
