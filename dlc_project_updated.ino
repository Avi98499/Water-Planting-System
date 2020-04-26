
#define threshold 600 // Defining Thresholds

#define wateringTime 5000 //5 seconds

#define plantpos2 70    // plant 1 position 

int plantSensor1 = A0;    // sensor pins 

int value1 = 0;  //initializing sensor value & variables

int motorPin1 = 6;
int motorPin2 = 7; // water pump control pin
void watering1();

void setup()
{
  Serial.begin(9600);
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, LOW); //pump off at initial
  digitalWrite(7, LOW);
  
}

void loop()
{
  value1= analogRead(plantSensor1);
  //Reading values from sensot
  
  Serial.println(value1);  //Displaying values on serial monitor for debugging
  
   delay(2000); 
  
     if(value1 >= threshold)
     {
       watering1();  //control watering operations
     }
     
}

void watering1()
{

    Serial.println("Watering Plant 1");

    digitalWrite(6, HIGH); //Pump onn
     digitalWrite(7, HIGH);
    delay(wateringTime); //Watering Time
    digitalWrite(6, LOW); //Pump off
     digitalWrite(7, LOW);
    delay(5000); //Wait till extra water flows out
    
    delay(15000); //wait for 15 seconds before reading again, this will let water sets in soil
    
    
  }
