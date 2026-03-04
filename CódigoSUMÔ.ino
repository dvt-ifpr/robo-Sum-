#include <Servo.h>

Servo myservo;
int pos = 0;
// Pinos do sensor ultrassônico
const int trigPin = 2;
const int echoPin = 3;

// Pinos da ponte H
//const int ena = 3;    // Motor A (esquerdo)
const int in1 = 8;
const int in2 = 7;

//const int enb = 5;    // Motor B (direito)
const int in3 = 5;
const int in4 = 4;

// Distância para detectar o inimigo (em cm)
const int distanciaLimite = 70;

void setup() {
   myservo.attach(9);
  // Inicialização do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicialização dos motores
  //pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  //pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Inicia serial para debug (opcional)
  Serial.begin(9600);
}

void loop() {
  long duracao, distancia;

  // Emite pulso ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê a duração do pulso
  duracao = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distancia);

  if (distancia > 0 && distancia <= distanciaLimite) {
    // Inimigo detectado: Avança
    moverFrente(200);
     if(distancia > 0 && distancia <=2){
       delay(2000);
       for (pos = 0; pos <= 90; pos += 1) {    
    myservo.write(pos);             
    delay(150000000);
    
 }} } else {
    // Nenhum inimigo: Gira para procurar
    girarDireita(500);
  }

  delay(100);
}

// Funções de movimento
void moverFrente(int velocidade) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(ena, velocidade);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enb, velocidade);
}

void girarDireita(int velocidade) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(ena, velocidade);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 // analogWrite(enb, velocidade);
}

void parar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //analogWrite(ena, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //analogWrite(enb, 0);
}
