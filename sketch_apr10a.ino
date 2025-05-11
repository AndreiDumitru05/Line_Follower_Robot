double ___eroare;
double ___senzori;
double ___SA0;
double ___SA1;
double ___SA2;
double ___SA3;
double ___SA4;
int _output_PD5 = 5;
int _output_PD4 = 4;
int _input_SA1 = A1;
int _output_PD7 = 7;
int _input_SA0 = A0;
int _output_PD6 = 6;
int _input_SA3 = A3;
int _input_SA2 = A2;
int _output_PWM10 = 10;
int _output_PWM9 = 9;
int _input_SA4 = A4;
int _led_L = 13;

void citesteSenzoriAnalogi() {
    ___SA0 = analogRead(_input_SA0);
    ___SA1 = analogRead(_input_SA1);
    ___SA2 = analogRead(_input_SA2);
    ___SA3 = analogRead(_input_SA3);
    ___SA4 = analogRead(_input_SA4);
}

void calculEroare() {
  if ( ___SA2 < 250 )
    ___eroare = 0;
        if ( ___SA1 < 250 ) {
            ___eroare = 1;
        }
      
         if ( ___SA3 < 250 ) {
                ___eroare = -1;}
      
        if ( ___SA0 < 250 )
           ___eroare = 1;
        
           // delay(5); nu imbunatateste
            if( ___SA4 < 250 )
              ___eroare = -1;
        
        if ( ___SA0 < 250 && ___SA1 < 250 && ___SA2 < 250 && ___SA3 < 250 && ___SA4 < 250)
           ___eroare = 2;
    
}

void controlMotoare() {
   
    if ( ___eroare == 2 ) {
      digitalWrite(_output_PD4, 0); //stanga inapoi
    digitalWrite(_output_PD5, 1);//stanga fata
    digitalWrite(_output_PD6, 1);// dreapta fata
    digitalWrite(_output_PD7, 0);//dreapta inapoi
        analogWrite(_output_PWM9, 0); //dreapta
        analogWrite(_output_PWM10, 0); //stanga
    }

    if ( ___eroare == 0 ) {
      digitalWrite(_output_PD4, 0); //stanga inapoi
    digitalWrite(_output_PD5, 1);//stanga fata
    digitalWrite(_output_PD6, 1);// dreapta fata
    digitalWrite(_output_PD7, 0);//dreapta inapoi
        analogWrite(_output_PWM9, 100); //dreapta
        analogWrite(_output_PWM10, 90); //stanga
    } 
    
        if ( ___eroare == -1) {//v dreapta
          digitalWrite(_output_PD4, 0);// s i
    digitalWrite(_output_PD5, 1);// s f
    digitalWrite(_output_PD6, 0);// d f
    digitalWrite(_output_PD7, 1);// d i
            analogWrite(_output_PWM9, 12);//inapoi
            analogWrite(_output_PWM10, 85);
           
            
        }
      //  delay(5);
        
       if( ___eroare == 1) {//v stanga
          digitalWrite(_output_PD4, 1);
    digitalWrite(_output_PD5, 0);
    digitalWrite(_output_PD6, 1);
    digitalWrite(_output_PD7, 0);
            analogWrite(_output_PWM9, 95);
            analogWrite(_output_PWM10, 12);//inapoi
              
        }
        
}


void setup()
{
    Serial.begin(9600); 
    pinMode(_output_PD5, OUTPUT);
    pinMode(_output_PD4, OUTPUT);
    pinMode(_input_SA1, INPUT);
    pinMode(_output_PD7, OUTPUT);
    pinMode(_input_SA0, INPUT);
    pinMode(_output_PD6, OUTPUT);
    pinMode(_input_SA3, INPUT);
    pinMode(_input_SA2, INPUT);
    pinMode(_output_PWM10, OUTPUT);
    pinMode(_output_PWM9, OUTPUT);
    pinMode(_input_SA4, INPUT);
    pinMode(_led_L, OUTPUT);
    ___eroare = 0;
    ___senzori = 5;
    ___SA0 = 0;
    ___SA1 = 0;
    ___SA2 = 0;
    ___SA3 = 0;
    ___SA4 = 0;
}

void loop()
{
    citesteSenzoriAnalogi();
    calculEroare();
    controlMotoare();
    Serial.print(___SA0);
    Serial.print(" ");
    Serial.print(___SA1);
    Serial.print(" ");
    Serial.print(___SA2);
    Serial.print(" ");
    Serial.print(___SA3);
    Serial.print(" ");
    Serial.print(___SA4);
    Serial.println();
    delay(10);
}  