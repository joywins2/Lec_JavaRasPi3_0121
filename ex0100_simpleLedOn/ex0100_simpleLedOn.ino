//...S.example0109_setup.
//   DHT sensor library : https://www.arduinolibraries.info/libraries/dht-sensor-library
//   https://blog.naver.com/lego7407/221331174434 
//   and https://www.brainy-bits.com/dht11-tutorial/
//   and https://cafe.naver.com/gubass/13407
#include <DHT.h>
#define DHT_APIN A0      //...set data pin to A0.
#define DHTTYPE DHT11
DHT dht(DHT_APIN, DHTTYPE);
//...E.example0109_setup.

//...S.example0107_setup, example0107_setup_010.
#include <Servo.h>
Servo servo0107;
int angle = 0;
//...E.example0107_setup, example0107_setup_010.


/*
   ...D:\JoyWins2\Lec_JavaRasPi3_0121\ex0100_simpleLedOn
*/
void setup() {
  //example0101_setup();
  //example0102_setup();
  //example0103_setup();//...'~': PWM.0~255.
  //example0104_setup();//...Photocell(LDR)
  //example0105_setup();//...Rotary Pontentiometer(R2)
  //example0105_setup_010();//...Rotary Pontentiometer(R2)
  //example0106_setup();//...Pushbutton::PullDown
  //example0106_setup_010();//...Pushbutton::PullUp
  //example0106_setup_020(); //...Pushbutton::INPUT_PULLUP(Arduino's inner resistance)
  //example0107_setup(); //...Basic Servo
  //example0107_setup_010(); //...Basic Servo + Rotary Potentiometer(R2)
  //example0108_setup(); //...Serial Tx
  //example0108_setup_010(); //...Serial Rx
  //example0108_setup_020(); //...Serial RxTx
  example0109_setup(); //...DHT11.

}

void loop() {
  //example0101();
  //example0102();
  //example0103();//...'~': PWM.0~255.image : https://drive.google.com/open?id=1lMKPw0NW8UQSAcJfGvQXJMzp5gIr5cf-
  //example0104();//...Photocell(LDR), image : https://drive.google.com/open?id=1Gl51PbBN4QMAn9VRGFkkISgWA_byTd4I
  //example0105();//...Rotary Pontentiometer(R2), image : https://drive.google.com/open?id=1ziFm6_tUdhLQcNUzng-Wi4TDtOUYIhRD
  //example0105_010();//...Rotary Pontentiometer(R2) and LED, image : https://drive.google.com/open?id=1IwLr_-OjT3p-SPYteyf0cBkvppdPwWeF
  //example0106(); //...Pushbutton::PullDown, image : https://drive.google.com/open?id=1AVlkpZPyL5T6S5Nx-UiMIZZq1ANPuJxC
  //example0106_010(); //...Pushbutton::PullUp, image : https://drive.google.com/open?id=1kHwkjc8c1gFvZUTPMHu_W8JQBPlioCzL
  //example0106_020(); //...Pushbutton::INPUT_PULLUP(Arduino's inner resistance), image : https://drive.google.com/open?id=1UmPMS3JBSaVot8TAn4cjw5ynyTuDgU2f
  //example0107(); //...Basic Servo, image : https://drive.google.com/open?id=1lJ3GJl6heZO6r4VjPYXKjiuQrQKxy_hE
  //example0107_010(); //...Basic Servo + Rotary Potentiometer(R2), image : https://drive.google.com/open?id=1g-b48qlIR9j7i5uI83Udqm8WmXt_Iafk
  //example0108(); //...Serial Tx
  //example0108_010(); //...Serial Rx, chooose 'no line ending' at Serial Monitor.
  //example0108_020(); //...Serial RxTx
  example0109(); //...DHT11, image : https://drive.google.com/open?id=1EyLtqQag-9zg0i73ByUD4ZyKPKqS42tM 


}

void example0109() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print((byte)h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print((byte)t);
  Serial.println(" C");
  delay(1000);
  
}

void example0108_020() {
  //...Number(AsciiCode) : 0(48)...,A(65)...,a(97)...\n(10),\r(13,return).
  if (Serial.available()) { //...exclude -1.
    int a = Serial.read();
    if (a == 49) //...a = 1.
      digitalWrite(13, 1);
    if (a == 48) //...a = 0.
      digitalWrite(13, 0);
  }
}

void example0108_010() {
  if (Serial.available()) { //...exclude -1.
    int a = Serial.read();
    //Serial.print("Serial read value : ");
    Serial.println(a);
  }
}

void example0108() {
  //...nothing.
}

void example0107_010() {
  int a0 = analogRead(A0);
  int a0_map = map(a0, 0, 1023, 0, 180); //...convert value range of a0(0~1023) to value of angle(0~180).
  Serial.print("Rotary Pontentiometer(R2) : ");
  Serial.println(a0_map);
  servo0107.write(a0_map);
  delay(100);
}

void example0107() {
  for (angle = 0; angle < 90; angle += 1) {
    servo0107.write(angle);
    delay(100);
  }
}

void example0106_020() {
  example0106();
}

void example0106_010() {
  example0106();
}

void example0106() {
  int d2 = digitalRead(2);
  delay(100);
  Serial.print("Pushbutton : ");
  Serial.println(d2);
}

void example0105_010() {
  example0105();
}

void example0105() {
  int a0 = analogRead(A0);
  //map(a0, 0,1023, 0,255); //...convert value range of a0(0~1023) to value of PWM(0~255).
  //int b0 = map(a0, 0,1023, 0,5); //...convert value range of a0(0~1023) to value of Voltage(0~5).
  int b0 = map(a0, 0, 1023, 0, 50); //...convert value range of a0(0~1023) to value of Voltage(0.0~5.0).
  Serial.print("Rotary Pontentiometer(R2) : ");
  Serial.println(b0 / 10.0f);
  delay(250);
}

void example0104() {
  int a0 = analogRead(A0);
  delay(250);
  Serial.print("Photocell Value : ");
  Serial.println(a0);
}

void example0103() {
  for (int i = 0 ; i < 256; ++i) {
    analogWrite(11, i);
    delay(10);
  }
}

void example0102() {
  for (int i = 13; i >= 11; --i) {
    digitalWrite(i, 1);
    delay(250);
    digitalWrite(i, 0);
    delay(250);
  }
}

void example0101() {
  digitalWrite(13, 1);
  digitalWrite(12, 0);
  digitalWrite(11, 0);
  delay(1000);
  digitalWrite(13, 0);
  digitalWrite(12, 1);
  digitalWrite(11, 0);
  delay(1000);
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(11, 1);
  delay(1000);
}

void example0109_setup() {
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}


void example0108_setup_020() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void example0108_setup_010() {
  Serial.begin(9600);
}

void example0108_setup() {
  /*
     ...Serial.write : number is printed as ascii code, not number.
  */
  Serial.begin(9600);
  Serial.write("\nHi, Serial from Arduino to PC\nJoyWins!\n");
  Serial.println(65); //...print number 65.
  Serial.write(65); //...print AsciiCode, not Number. 0(48)...,A(65)...,a(97)...\n(10),\r(13,return).
}

void example0107_setup_010() {
  Serial.begin(9600);
  example0107_setup();
}

void example0107_setup() {
  /*
     ...Basic Servo : angle range : 0~180degreen
  */
  servo0107.attach(8);
}

void example0106_setup_020() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void example0106_setup_010() {
  example0106_setup();
}

void example0106_setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void example0105_setup_010() {
  example0105_setup();
}

void example0105_setup() {
  /*
     ...Rotary Pontentiometer(R2) : 0 ~ 1023.
        GND, A0, 5V.
        PWM PIN : 3,5,6,9,10,11.
        LED connect with PWM PIN.
  */
  Serial.begin(9600);
}

void example0104_setup() {
  //...AnalogPin : A0~A5 : 0~1023.
  Serial.begin(9600);
}

void example0103_setup() {
  //...'~': PWM.0~255.
  analogWrite(11, 10);
}

void example0102_setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(11, 0);
}

void example0101_setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(11, 0);
}
