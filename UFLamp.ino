int relay1 = 12; // UF VD1
int relay2 = 11; // UF VD
int but1 = A0; //3 ButtonGroup№1
int but2 = A1; //3 ButtonGroup№2
int r1=0; // flag state relay1
int r2=0; // flag state relay2
unsigned long timer =0; // primety timer
unsigned long pause1 = 0; // pause  Reley1
unsigned long premillis1 = 0; // secondery timer 1
unsigned long pause2 = 0;// pause  Reley2
unsigned long premillis2 = 0; // secondery timer 2
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
  
  // put your setup code here, to run once:
pinMode(relay1, OUTPUT); // set mode pin in out
pinMode(relay2, OUTPUT); // set mode pin in out
digitalWrite(relay1,HIGH); // OFF Relay1 (invers ON/OFF )
digitalWrite(relay2,HIGH); // OFF Relay2 (invers ON/OFF )
}

void loop() {
  but1State=analogRead(but1); // Read state 3 ButtonGroup№1 
  but2State=analogRead(but2); // Read state 3 ButtonGroup№2
timer=millis(); // initialise timer
if (but1State>500 && but1State<550 && r1==0){
  digitalWrite(relay1,LOW); // ON Relay1
  pause1=30000; // set pause ON Reley1 30 sec. 
  r1=1; // update state flag (no repeat push button) 
  premillis1=millis(); // update (write in) premillis1 this time
  Serial.print("R1_ON : ");
  Serial.print(pause1/1000);
  Serial.print(" || time : ");
  Serial.println(premillis1/1000);
  delay(450); // small pause touch button
}
else{}
if (but1State>660 && but1State<690 && r1==0){
  digitalWrite(relay1,LOW);
  pause1=60000;
  r1=1;
  premillis1=millis();
  Serial.print("R1_ON : ");
  Serial.print(pause1/1000);
  Serial.print(" || time : ");
  Serial.println(premillis1/1000);
  delay(450);
}
else{}
if (but1State>750 && but1State<790 && r1==0){
  digitalWrite(relay1,LOW);
  pause1=120000;
  r1=1;
  premillis1=millis();
  Serial.print("R1_ON : ");
  Serial.print(pause1/1000);
  Serial.print(" || time : ");
  Serial.println(premillis1/1000);
  
  delay(450);
}
else{}
if (but2State>500 && but2State<550 && r2==0){
  digitalWrite(relay2,LOW);
  pause2=30000;
  r2=1;
  premillis2=millis();
    Serial.print("R2_ON : ");
  Serial.print(pause2/1000);
  Serial.print(" || time : ");
  Serial.println(premillis2/1000);
  delay(450);
}
else{}
if (but2State>660 && but2State<690 && r2==0){
  digitalWrite(relay2,LOW);
  pause2=60000;
  r2=1;
  premillis2=millis();
    Serial.print("R2_ON : ");
  Serial.print(pause2/1000);
  Serial.print(" || time : ");
  Serial.println(premillis2/1000);
  delay(450);
}
else{}
if (but2State>750 && but2State<790 && r2==0){
    digitalWrite(relay2,LOW);
    pause2=120000;
    r2=1;
    premillis2=millis();
  Serial.print("R2_ON : ");
  Serial.print(pause2/1000);
  Serial.print(" || time : ");
  Serial.println(premillis2/1000);
    delay(450);
  }
else{}

if(timer- premillis1>pause1&&r1==1){
  digitalWrite(relay1,HIGH); 
  r1=0;
  Serial.print("R1_OFF: ");
  Serial.print(pause1/1000);
  Serial.print(" || time : ");
  Serial.println((timer-pause1)/1000); 
  pause1=0;
  }
else{}
if(timer- premillis2>pause2&&r2==1){
  digitalWrite(relay2,HIGH); 
  r2=0;
  Serial.print("R2_OFF: ");
  Serial.print(pause2/1000);
  Serial.print(" || time : ");
  Serial.println((timer-pause2)/1000);
  pause2=0;
  }
else{}


 

}
