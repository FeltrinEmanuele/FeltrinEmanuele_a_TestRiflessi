int ledVerde;
int ledRosso;
int ledDiPausa;
int buzzer;
int bottone;
int bottoneHIGH_o_LOW;
int risultatoRiflessiLed;
int risultatoRiflessiBuzzer;
void setup() {
  ledVerde = 6;
  ledRosso = 7;
  ledDiPausa = 8;
  buzzer = 9;
  bottone = 10;
  pinMode(ledVerde,OUTPUT);
  pinMode(ledRosso,OUTPUT);
  pinMode(ledDiPausa,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(bottone,INPUT);
  Serial.begin(9600);
}
int ProvaRiflessi(String testo, int led_o_buzzer)
{
  delay(random(1000,5000));
  digitalWrite(led_o_buzzer,HIGH);
  int TempoInizioProva = millis();
  bottoneHIGH_o_LOW = digitalRead(bottone);
  bool premuto = false;
  while(!premuto){
    if(bottoneHIGH_o_LOW == HIGH){
      premuto = true;
    }
  }
  digitalWrite(led_o_buzzer,LOW);
  int TempoFineProva = millis();
  int TempoFinale = TempoFineProva - TempoInizioProva;
  Serial.println(testo + String (TempoFinale));
  return TempoFinale;  
}
void loop() {
  // Vedo Se il pulsante è premuto
  bottoneHIGH_o_LOW = digitalRead(bottone);
  bool premuto = false;
  while(!premuto){
    if(bottoneHIGH_o_LOW == HIGH){
      premuto = true;
    }
  }
  risultatoRiflessiLed = ProvaRiflessi("Il tuo tempo di risposta col led è", ledDiPausa);
  risultatoRiflessiBuzzer = ProvaRiflessi("Il tuo tempo di risposta col buzzer è", buzzer);
  //guardo i risultati
  if(risultatoRiflessiLed < 400 && risultatoRiflessiBuzzer < 400){
    digitalWrite(ledVerde,HIGH);
  }else{
    digitalWrite(ledRosso,HIGH);
  }
  //metto un tempo per far vedere all'utente se ha vinto
  delay(10000);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRosso,LOW);              
}
