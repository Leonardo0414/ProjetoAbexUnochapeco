#include <SoftwareSerial.h>
// Este código possibilita a troca de dados entre o aplicativo e o módulo bluetooth

//Variável que recebe os dados recebidos do aplicativo
char dadoBT = '0';
//Constantes com pinos rx e tx
const int pinoRX = 10;
const int pinoTX = 11;

const int IN1  = 3;
const int IN2  = 2;
const int IN3  = 6;
const int IN4  = 7;

//Configura o módulo bluetooth(portas utilizadas pelo módulo)
SoftwareSerial bluetooth(pinoRX, pinoTX);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  Serial.println("bluetoof inicializado ");
  //Inicializar a comunicação serial com o Bluetooth
  bluetooth.begin(9600);
  delay(1000);
  Serial.print("Configurando");
}

void loop() {
  

  if (bluetooth.available()) {                     //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
    dadoBT = bluetooth.read();                  //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
    Serial.print("Dado recebido via Bluetooth: ' ");
    Serial.print(dadoBT);
    Serial.println("'");

    if (dadoBT == '1')
    {

     // Liga os motores (anda)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  bluetooth.println("andando");
  Serial.println("andando");

  delay(1000);  // Anda por 1 segundos (1000 milissegundos)

  // Para os motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  bluetooth.println("parou");
  Serial.println("parou"); 
    }

    
      if (dadoBT == '2')
{
  // Liga os motores para ré
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  bluetooth.println("re");
  Serial.println("re");

  delay(1000);  // Ré por 1 segundos

  // Para os motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  bluetooth.println("parou");
  Serial.println("parou");
}

    

 if (dadoBT == '3')  // Girar para esquerda 90°
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(250);  // gira 90°

  // Para motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  bluetooth.println("parou");
  Serial.println("parou");
}

if (dadoBT == '4')  // Girar para direita 90°
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(250);  // gira 90°

  // Para motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  bluetooth.println("parou");
  Serial.println("parou");
}

if (dadoBT == '5'){
  Serial.println("press");
}
    delay(200);
  }
}
