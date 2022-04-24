int led11=11;
int led10=10;
int led5=5;
int led7=7;
int led1=8;
int led2=2;
int led4=4;
int a=6;
int b=HIGH;
int etatpre=LOW;

int i;
char data ;
int d=12;
int blanc =3;
//int roug=13;
int Buzzer=13;

void setup() {
pinMode(led11,OUTPUT);
pinMode(led10,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(blanc,OUTPUT);
//pinMode(roug,OUTPUT);
digitalWrite(led11,LOW);
digitalWrite(led10,LOW);
digitalWrite(led5,HIGH);
digitalWrite(led7,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led4,LOW);
//delay(1000);
pinMode(a,INPUT);
pinMode(d,INPUT);
Serial.begin(9600);

i=0;
}

void loop() {
  etatpre=b;
  b=digitalRead(a);
 
if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
//    digitalWrite(roug,HIGH);
    tone(Buzzer,450); 
    
  
     
      // alumer la lampe 
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
//        digitalWrite(roug,LOW);
         noTone(Buzzer);


        
   
     }   
     }






  
  if(b==HIGH && b!=etatpre){
    i++;
    

if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
   //    digitalWrite(roug,HIGH);
    tone(Buzzer,450); 

  
       
  
     
      // alumer la lampe 
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
      //        digitalWrite(roug,LOW);
         noTone(Buzzer);
   
     }   
     }
         
   afficher();
    delay(1000);
    }
    
    

}

void afficher(){

    if (i==1){
digitalWrite(led11,HIGH);
digitalWrite(led10,HIGH);
digitalWrite(led5,HIGH);
digitalWrite(led7,LOW);
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
noTone(Buzzer);
  Serial.write('0');
    }
      if (i==2){
digitalWrite(led11,LOW);
digitalWrite(led10,HIGH);
digitalWrite(led5,LOW);
digitalWrite(led7,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led4,HIGH);
digitalWrite(blanc,HIGH);
  Serial.write('0');
    }
     if (i==3){
digitalWrite(led11,LOW);
digitalWrite(led10,HIGH);
digitalWrite(led5,LOW);
digitalWrite(led7,LOW);
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
  Serial.write('0');
    }
     if (i==4){
digitalWrite(led11,HIGH);
digitalWrite(led10,LOW);
digitalWrite(led5,LOW);
digitalWrite(led7,LOW);
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
  Serial.write('0');
    }
         if (i==5){
digitalWrite(led11,LOW);
digitalWrite(led10,LOW);
digitalWrite(led5,LOW);
digitalWrite(led7,HIGH);
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
  Serial.write('0');
    }
         if (i==6){
digitalWrite(led11,LOW);
digitalWrite(led10,LOW);
digitalWrite(led5,LOW);
digitalWrite(led7,HIGH);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
 Serial.write('0');
    }
         if (i==7){
digitalWrite(led11,LOW);
digitalWrite(led10,HIGH);
digitalWrite(led5,HIGH);
digitalWrite(led7,LOW);
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
  Serial.write('0');
    }
         if (i==8){
digitalWrite(led11,LOW);
digitalWrite(led10,LOW);
digitalWrite(led5,LOW);
digitalWrite(led7,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led4,LOW);
digitalWrite(blanc,HIGH);
  Serial.write('0');
    }
         if (i==9){
digitalWrite(led11,LOW);
digitalWrite(led10,LOW);
digitalWrite(led5,LOW);
digitalWrite(led7,LOW);
digitalWrite(led1,HIGH);
digitalWrite(led2,LOW);
digitalWrite(blanc,LOW);
//digitalWrite(roug,LOW);
 Serial.write('1');
 tone(Buzzer,450); 
  i=0;

    }
    
    
    
    
    
    
  
  
  }
