#include <Wire.h>
int val11;
float val2;
float sensitifitas = 0.66;

void setup()
{
  Serial.begin(9600);
  Serial.println("------------------");
}
void loop()
{
    float temp;
    val11=analogRead(1);
    temp=val11/4.562;
    val2=(temp/10);
    Serial.print(" Tegangan: ");
    Serial.print(val2);
    Serial.println(" V");
    delay(1000);

    //Sensor Arus max 5A
    float average = 0;
    for(int i = 0; i < 1000; i++) {
      //average = average + (0.0264 * analogRead(A0) - 13.51);
      average = average + ((0.0048828125 * analogRead(A0) - 2.5) / sensitifitas);
      delay(1);
    }
    Serial.print(average + 31,3);
    Serial.println(" mA");
    Serial.print("Nilai RAW = ");
    Serial.println(analogRead(A0));
    Serial.println("------------------------");
    delay(1000);



    
}
