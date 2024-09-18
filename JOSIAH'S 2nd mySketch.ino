#define IMPOSSIBLE 3.125
#define COMPUTER 6.25
#define EXPERT 12.5
#define PRO 25
#define BEGINNER 50

#define NUMBERWIN 1
#define NUMBERLOSE 5


int LEDPINPIN;
int TIMEVARIABLE;
int PRESSTRACK;
int WINCOUNT;
int LEVELUPCOUNT;

void allOff() {
  int counter=2;
  while(counter<14){
    LEDPINPIN = counter;
    digitalWrite(LEDPINPIN, LOW);
    counter=counter+1;
  }   
}



// Describe this function...
void Light_Switch() {
  digitalWrite(LEDPINPIN, HIGH);
  delay(TIMEVARIABLE);
  digitalWrite(LEDPINPIN, LOW);
  delay(TIMEVARIABLE);
}

void setup()
{
    pinMode(1, INPUT_PULLUP);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
    
    TIMEVARIABLE=BEGINNER;
    WINCOUNT=0;
    PRESSTRACK=0;
    LEVELUPCOUNT=1;
    
    Serial.begin(9600);
    pinMode(1, INPUT_PULLUP);
    Serial.println("******************");
    delay(500 * 1);
    Serial.println("HI!");
    delay(500 * 1);
    Serial.println("Welcome to the Cyclone Game!");
    delay(500 * 1);
    Serial.println("Let's Go!");
    delay(500 * 1);
    Serial.print("Press the button to start.");
    Serial.print(" Dots forever!");
    delay(500 * 1);
    while (digitalRead(1) == HIGH) {
        Serial.print(".");
        delay (50);
        digitalWrite(random(2,14),HIGH);
        delay(50);
        digitalWrite(random(2,14),LOW);
    }   
    delay (500);
    Serial.println();
    delay(500 * 1);
    Serial.println("THE GAME BEGINS");
}

void goAround()
{
  int counter=2;
  while(counter<14){
    LEDPINPIN = counter;
    Light_Switch();
    
    if (digitalRead(1) == LOW) {
        digitalWrite(LEDPINPIN,HIGH);
        PRESSTRACK=PRESSTRACK +1;
      
        if (LEDPINPIN == 13){
            WINCOUNT++;
            if (WINCOUNT>=NUMBERWIN) {
                TIMEVARIABLE=TIMEVARIABLE/2;
                PRESSTRACK=0;
                WINCOUNT=0;
                LEVELUPCOUNT++;
                delay (500);
                Serial.println("You leveled up!");
                Serial.print("You are on level ");
                Serial.println(LEVELUPCOUNT);
                // you win
                delay(500);
            }
                
        }
        else {
            delay (500);
            Serial.println("You missed!");
            Serial.print("You have ");
            Serial.print(5-PRESSTRACK);
            Serial.println(" tries left.");
            delay (500);
            
        }
        
        break;
    }
    
    counter=counter+1;
  }
}

void loop()
{
    if (digitalRead(1) == LOW) {

    }
    else {
        
        if (PRESSTRACK==NUMBERLOSE){
            allOff();
            Serial.println("You lost.");
            Serial.println("Press the red button to restart.");
            while (1==1) {
                // you lose
            }
        }
        

        allOff();
        goAround();
    }
    
    
    
    
    
}

/***** OUTSIDE BLOCKS *****
{

}
** END OUTSIDE BLOCKS *****/