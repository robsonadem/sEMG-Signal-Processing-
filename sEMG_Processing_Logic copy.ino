    
/********************************************************
  Sketch title:  sEMG Processing Logic

  Reads signal from Mayo Muscle Sensor and Processes signal 
       to decide if a muscle has been contracted or not based 
        on a treshold 

  The circuit:
  
   Mayo Muscle Sensor
            3 outputs- 
                  Signal --> A0
                   +     --> Vs
                   -     -->  GND
   Led
           pin 5

  Author: Robson Adem (ademr@lafayette.edu)

 

***************************************************/
int sensorValueThreshold = 100;// particularly 100 is good but you can run expts and decide
int LED=5;// pick any pin 
// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);//Led setup
}

// the loop routine runs over and over again forever:

void loop() {
  
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  Serial.println(sensorValue);// print the value read
  
  //Logic
  if (sensorValue > sensorValueThreshold){
    //contracted
    Serial.println("---CONTRACTION DETECTED");
    digitalWrite(LED, HIGH);
  }
  else{
    //not contracted
    Serial.println("");
    digitalWrite(LED, LOW);
  }
  delay(100);// how fast you reading it
}




