int relay1 = 12; // UF VD1
int relay2 = 11; // UF VD2
int but1 = A0; //3 ButtonGroup№1
int but2 = A1; //3 ButtonGroup№2
int But1Gr1 = 0;
int But2Gr1 = 0;
int But3Gr1 = 0;
int But1Gr2 = 0;
int But2Gr2 = 0;
int But3Gr2 = 0;
int r1=0; // flag state relay1
int r2=0; // flag state relay2
unsigned long timer =0; // primety timer
unsigned long pause1 = 0; // pause  Reley1
unsigned long premillis1 = 0; // secondery timer 1
unsigned long pause2 = 0;// pause  Reley2
unsigned long premillis2 = 0; // secondery timer 2
unsigned long premillisOff = 0;
int but1State = 0; // Value analogread A0
int but2State = 0; // Value analogread A1

void setup() {
  Serial.begin(9600);
  Serial.println("             __________________________________");
  Serial.println("            |*********UF_Lamp V_0.0.3**********|");
  Serial.println("            |Creator of the project @___GHR___@|");
  Serial.println("            |Contact  email  freegenrih@mail.ru|");
  Serial.println("            |__________________________________|");
  Serial.println("//-----------------------debug mode-----------------------------//");
  Serial.println("// (Rx_ON : Xt || time : Xtime) == (Rx_OFF : Xt || time : Xtime)//");
  Serial.println("//-------if(Xtime Rx_ON==Xtime Rx_OFF){GOOD}--Else {BAD}--------//");
  Serial.println("//--------------------------------------------------------------//");
  
  
  pinMode(relay1, OUTPUT); // set mode pin in out
  pinMode(relay2, OUTPUT); // set mode pin in out
  digitalWrite(relay1,HIGH); // OFF Relay1 (invers ON/OFF )
  digitalWrite(relay2,HIGH); // OFF Relay2 (invers ON/OFF )
}

void loop() {
  but1State=analogRead(but1); // Read state 3 ButtonGroup№1 
  but2State=analogRead(but2); // Read state 3 ButtonGroup№2
  timer=millis(); // initialise timer

if (but1State>500 && but1State<550 && r1==0 && But1Gr1==0){
   digitalWrite(relay1,LOW); // ON Relay1
   But1Gr1=1;
   pause1=30000; // set pause ON Reley1 30 sec. 
   r1=1; // update state flag (no repeat push button) 
   premillis1=millis(); // update (write in) premillis1 this time
   Serial.print("R1_ON : ");
   Serial.print(pause1/1000);
   Serial.print(" || time : ");
   Serial.println(premillis1/1000);
   //delay(450); // small pause touch button   
}
else{}

if (but1State>660 && but1State<690 && r1==0 && But2Gr1==0){
   digitalWrite(relay1,LOW);
   But2Gr1=1;
   pause1=60000;
   r1=1;
   premillis1=millis();
   Serial.print("R1_ON : ");
   Serial.print(pause1/1000);
   Serial.print(" || time : ");
   Serial.println(premillis1/1000);
   //   delay(450);
}
else{}
  
if (but1State>750 && but1State<790 && r1==0 && But1Gr1==0){
   digitalWrite(relay1,LOW);
   But3Gr1=1;
   pause1=120000;
   r1=1;
   premillis1=millis();
   Serial.print("R1_ON : ");
   Serial.print(pause1/1000);
   Serial.print(" || time : ");
   Serial.println(premillis1/1000);
      //delay(450);
}
else{}

if (but2State>500 && but2State<550 && r2==0 && But1Gr2==0){
   digitalWrite(relay2,LOW);
   But1Gr2=1;
   pause2=30000;
   r2=1;
   premillis2=millis();
   Serial.print("R2_ON : ");
   Serial.print(pause2/1000);
   Serial.print(" || time : ");
   Serial.println(premillis2/1000);
      //delay(450);
}
else{}

if (but2State>660 && but2State<690 && r2==0 && But2Gr2==0){
   digitalWrite(relay2,LOW);
   But2Gr2=1;
   pause2=60000;
   r2=1;
   premillis2=millis();
   Serial.print("R2_ON : ");
   Serial.print(pause2/1000);
   Serial.print(" || time : ");
   Serial.println(premillis2/1000);
    //  delay(450);
}
else{}

if (but2State>750 && but2State<790 && r2==0 && But3Gr2==0){
   digitalWrite(relay2,LOW);
   But3Gr2=1;
   pause2=120000;
   r2=1;
   premillis2=millis();
   Serial.print("R2_ON : ");
   Serial.print(pause2/1000);
   Serial.print(" || time : ");
   Serial.println(premillis2/1000);
   //   delay(450);
  }
else{}

//----------------------------------------------------Forse OFF Relay1------------------------------------------------------------

if (but1State>500 && but1State<550 && r1==1 && But2Gr1==1||but1State>500 && but1State<550 && r1==1 && But3Gr1==1){
   digitalWrite(relay1,HIGH); 
   r1=0;
   But1Gr1=0;
   But2Gr1=0;
   But3Gr1=0;
   delay(500); // small pause touch button   
}
else{
  if (timer- premillis1>pause1&&r1==1){
     digitalWrite(relay1,HIGH); 
     r1=0;
     But1Gr1=0;
     But2Gr1=0;
     But3Gr1=0;
     Serial.print("R1_OFF: ");
     Serial.print(pause1/1000);
     Serial.print(" || time : ");
     Serial.println((timer-pause1)/1000); 
     pause1=0;
    }
}
//----------------------------------------------------Forse OFF Relay2------------------------------------------------------------
if (but2State>500 && but2State<550 && r2==1 && But2Gr2==1||but2State>500 && but2State<550 && r2==1 && But3Gr2==1){
   digitalWrite(relay2,HIGH); 
   r2=0;
   But1Gr2=0;
   But2Gr2=0;
   But3Gr2=0;
   delay(500); // small pause touch button   
}
else{
  if (timer- premillis2>pause2&&r2==1){
     digitalWrite(relay2,HIGH); 
     r2=0;
     But1Gr2=0;
     But2Gr2=0;
     But3Gr2=0;
     Serial.print("R2_OFF: ");
     Serial.print(pause2/1000);
     Serial.print(" || time : ");
     Serial.println((timer-pause2)/1000);
     pause2=0;
    }
}
// off all relay
if ((but1State>300 && but1State<380 && r1==1)&&(but2State>300 && but2State<380 && r2==1)){
   digitalWrite(relay1,HIGH); 
   digitalWrite(relay2,HIGH); 
   r1=0;
   But1Gr1=0;
   But2Gr1=0;
   But3Gr1=0;
   r2=0;
   But1Gr2=0;
   But2Gr2=0;
   But3Gr2=0;   
}
}

