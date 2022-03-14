
#include <Wire.h>
#include <LiquidCrystal_I2C.h>//----- Adressage matériel -----
// En cas de non fonctionnement, mettez la ligne 8 en
// commentaire et retirez le commentaire à la ligne 9.
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F,20,4);
//int i =0;



void affichage(){
 lcd.init();
 lcd.backlight();
 // Envoi du message

 if(i==0){
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("    BIENVENUE !"); 
  lcd.setCursor(0,2);
  lcd.print("Veuillez choisir une");
  lcd.setCursor(0,3);
  lcd.print("    musique :)");


 }
 
 if(i==1){
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Never gonna give"); 
  lcd.setCursor(0, 1); 
  lcd.print("you up"); 
  lcd.setCursor(0,3);
  lcd.print("Rick Astley");

 }
 if(i==2){  
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("On va s'aimer"); 
  lcd.setCursor(0,2);
  lcd.print("Gilbert Montagne");

  
 }
 if(i==3){  
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Young Wild & Free"); 
  lcd.setCursor(0,2);
  lcd.print("Wiz Khalifa");
  lcd.setCursor(0,3);
  lcd.print("Snoop Dog");

 }
 if(i==4){
   lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
   lcd.print("Wesh Alors"); 
   lcd.setCursor(0,2);
   lcd.print("JUL");
 }
 if(i==5){  
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Ain't no Mountain "); 
  lcd.setCursor(0, 1); 
  lcd.print("High Enough"); 
  lcd.setCursor(0,3);
  lcd.print("Marvin Gaye"); 

 }
 if(i==6){   
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
   lcd.print("Don't stop the music"); 
   lcd.setCursor(0,2);
   lcd.print("Rihanna");

 }

 if(i==7){   
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Earth, Wind & Fire"); 
  lcd.setCursor(0,2);
  lcd.print("September");

 
 }

 if(i==8){  
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("ABC"); 
  lcd.setCursor(0,2);
  lcd.print("Jackson Five");

 }
 
 if(i==9){  
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Get down on it"); 
  lcd.setCursor(0,2);
  lcd.print("Kool & The Gang");

 }
 if(i==10){ 
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Hit the road Jack"); 
  lcd.setCursor(0,2);
  lcd.print("Ray Charles");
 
 }
 if(i==11){  
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Lady"); 
  lcd.setCursor(0,2);
  lcd.print("Modjo");
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 

 }
 if(i==12){
  lcd.setCursor(0, 0); // positionne le curseur à la colonne 1 et à la ligne 1 
  lcd.print("Beat it"); 
  lcd.setCursor(0,2);
  lcd.print("Michael Jackson");
 }
 


}
