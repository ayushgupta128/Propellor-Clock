  byte d1[5]={0B00000000,0B00000000,0B01111111,0B00000000,0B00000000};
  byte d2[5]={0B01111001,0B01001001,0B01001001,0B01001001,0B01001111};
  byte d3[5]={0B01111111,0B01001001,0B01001001,0B01001001,0B01001001};
  byte d4[5]={0B01111111,0B00001000,0B00001000,0B00001000,0B01111000};
  byte d5[5]={0B01001111,0B01001001,0B01001001,0B01001001,0B01111001};
  byte d6[5]={0B01001111,0B01001001,0B01001001,0B01001001,0B01111111};
  byte d7[5]={0B01111111,0B01000000,0B01000000,0B01000000,0B01000000};
  byte d8[5]={0B01111111,0B01001001,0B01001001,0B01001001,0B01111111};
  byte d9[5]={0B01111111,0B01001001,0B01001001,0B01001001,0B01111001};
  byte d0[5]={0B01111111,0B01000001,0B01000001,0B01000001,0B01111111};
  byte colon[5]={0B000000000,0B000000000,0B00100010,0B000000000,0B000000000};
  int previnttime=0;
  int inttime=0;
  int T=0;
  int flag=0;
  int [2]HH={2,1};
  int [2]MM={1,5};
  int [2]SS={0,9};
  int finsec;
  int finmin;
  int finhour;
 // int timeelapsed=0;
  int c=0;
  int datapin=6;
  int shiftpin=7;
  int latchpin=8;
 void setup(){
   // pinMode(9,OP);//SHIFT REG1
    pinMode(5,ip);//sensor
    digitalWrite(5,LOW);
    attachInterrupt(5,x,RISING);
    digitalWrite(6,LOW);//cathode
    pinMode(datapin,OUTPUT);
    pinMode(shiftpin,OUTPUT);
    pinMode(latchpin,OUTPUT);
  }
  void x(){flag=1;}
  void loop(){
    //int internaltime=micros();
    if(flag==1){
      inttime=micros();
      c++;
      T=inttime-previnttime;
       previnttime=inttime;
       //timeelapsed+=T;
       if(c>=2){
       calctime(T);}
       flag=0;
    }
    delay(((T/1000000)/360)*12);
    for(int i=0;i<6;i+=2){
      switch(i){
        case 0:writeon(SS[1]);
        delay(((T/1000000)/360*2));
        writeon(SS[0]);
        delay(((T/1000000)/360*2));
        break;
        case 2:writeon(MM[1]);
        delay(((T/1000000)/360));
        writeon(MM[0]);
        delay(((T/1000000)/360*3));
        break;
        case 4:writeon(HH[1]);
        delay(((T/1000000)/360));
        writeon(HH[0]);
        delay(((T/1000000)/360*3));
        break;
      }
    }
      for(int j=0;j<=4;j++)
      shreganode(colon[j]);
    }
    void writeon(int data){
 // byte x;
if(data==0){
for(int k=0;k<5;k++){    
  shreganode(d0[k]);
  delay(((T/1000000)/360));
}}
if(data==1){
for(int k=0;k<5;k++){    
  shreganode(d1[k]);
  delay(((T/1000000)/360));
}}
if(data==2){
for(int k=0;k<5;k++){    
  shreganode(d2[k]);
  delay(((T/1000000)/360));
}}
if(data==3){
for(int k=0;k<5;k++){    
  shreganode(d3[k]);
  delay(((T/1000000)/360));
}}
if(data==4){
for(int k=0;k<5;k++){    
  shreganode(d4[k]);
  delay(((T/1000000)/360));
}}
if(data==5){
for(int k=0;k<5;k++){    
  shreganode(d5[k]);
  delay(((T/1000000)/360));
}}
if(data==6){
for(int k=0;k<5;k++){    
  shreganode(d6[k]);
  delay(((T/1000000)/360));
}}
if(data==7){
for(int k=0;k<5;k++){    
  shreganode(d7[k]);
  delay(((T/1000000)/360));
}}
if(data==8){
for(int k=0;k<5;k++){    
  shreganode(d8[k]);
  delay(((T/1000000)/360));
}}
if(data==9){
for(int k=0;k<5;k++){    
  shreganode(d9[k]);
  delay(((T/1000000)/360));
}}
void shreganode(byte x){
  digitalWrite(latchpin,LOW);
  shiftOut(datapin,latchpin,x);
  digitalWrite(latchpin,HIGH);
}

    
  }
void calctime(int T){
    int initsec=SS[0]*10+SS[1];
    finsec=initsec+T/1000000;
    finmin+=finsec/60;
    finsec%=60;
    finhour+=finmin/60;
    finmin=finmin%60;
    SS[0]=finsec/10;//hour min sec will be put into their respective array
    SS[1]=finsec%10;
    MM[0]=finmin%10;
    MM[1]=finmin/10;
    HH[0]=finhour%10;
    HH[1]=finhour/10;
}
