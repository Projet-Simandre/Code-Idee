void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String chaine1 = "19.0";
  String chaine2 = "90.9";
  String chaine = chaine1 + chaine2;
  String valeur1, valeur2;
  for (int i = 0; i < chaine.length(); i++)
  {

    if(i >= chaine.length()/2)
    {
      valeur2 += chaine[i];
    }
    else
    {
      valeur1 += chaine[i];
    }
  }
  
  Serial.println(valeur2);
  Serial.println(valeur1);
  delay(1000);
}
