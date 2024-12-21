int valorx = 0;
int valory = 0;
int valorz = 0;
int pinoledesquerda = 2;
int pinoledsuperior = 3;
int pinoleddireita = 4;
int pinoledinferior = 5;
int pinoledz = 8;
int pinoz = 7;

// int contadorEstavel = 0;             // Contador para verificar estabilidade
// const int LIMIAR_ESTABILIDADE = 20;  // Número de leituras estáveis necessárias

void setup() {
  pinMode(pinoz, INPUT_PULLUP);  //Pino Eixo Z, pullup pelo ruído (acho) que estava causando o Z devolver apenas valores 0
  Serial.begin(9600);
  pinMode(pinoledesquerda, OUTPUT);
  pinMode(pinoledsuperior, OUTPUT);
  pinMode(pinoleddireita, OUTPUT);
  pinMode(pinoledinferior, OUTPUT);
  pinMode(pinoledz, OUTPUT);
}

void loop() {
  //as linhas abaixo apagam todos os leds
  digitalWrite(pinoledesquerda, LOW);
  digitalWrite(pinoledsuperior, LOW);
  digitalWrite(pinoleddireita, LOW);
  digitalWrite(pinoledinferior, LOW);
  digitalWrite(pinoledz, LOW);

  //le o valor do potenciometro ligado à porta analogica A0 - Eixo X
  valorx = analogRead(0);

  //mostra o valor do eixo X no serial monitor
  Serial.print("X:");
  Serial.print(valorx, DEC);

  //testa o valor do eixo X e aciona o led correspondente
  if (valorx > -1 & valorx < 200) {
    digitalWrite(pinoledinferior, HIGH);  //acende o led inferior
  }
  if (valorx > 700 & valorx < 1025) {
    digitalWrite(pinoledsuperior, HIGH);  //acende o led superior
  }

  //le o valor do potenciometro ligado à porta analogica A1 - Eixo Y
  valory = analogRead(1);

  //mostra o valor do eixo Y no serial monitor
  Serial.print(" | Y:");
  Serial.print(valory, DEC);

  //testa o valor do Eixo Y e aciona o led correspondente
  if (valory > -1 & valory < 200) {
    digitalWrite(pinoleddireita, HIGH);  //acende o led da direita
  }
  if (valory > 700 & valory < 1025) {
    digitalWrite(pinoledesquerda, HIGH);  //acende o led da equerda
  }

  //lê o valor da porta Digital 7 - Eixo Z
  valorz = digitalRead(7);

  //mostra o valor do Eixo Z no serial monitor
  Serial.print(" | Z: ");
  Serial.println(valorz, DEC);

  int valorz = digitalRead(pinoz); // lê o estado do botão Z

  if (valorz == LOW) { // se o botão Z estiver pressionado
    digitalWrite(pinoledz, HIGH); // acende o LED
  } else {
    digitalWrite(pinoledz, LOW);  // apaga o LED
  }
}

//   if (valorz == 0) {
//     contadorEstavel++;
//     if (contadorEstavel >= LIMIAR_ESTABILIDADE) {
//       digitalWrite(pinoledz, HIGH);  // acende o LED após leituras consistentes
//     }
//   } else {
//     contadorEstavel = 0;          // reseta o contador se o valor mudar
//     digitalWrite(pinoledz, LOW);  // apaga o LED
//   }
// }
