int led_verde = 5;
int led_azul = 4;
int led_amarelo = 7; 
int led_vermelho = 6;
int botao1 = 1;
int botao2 = 2;
int vetor_armazem[100];
int i = 0;

void setup() {
  Serial.begin(115200);
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(8, INPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void armazena(int conversao){
  vetor_armazem[i] = conversao;
  i++; 
}

void play(){
  int y = 0;
  while (y <= (i - 1)) {
    tone(10, vetor_armazem[i] * 30 + 30);
    int binario[4] = {0,0,0,0};
    if(vetor_armazem[i] == 0) {
      binario[1] = 0;
      binario[2] = 0;
      binario[3] = 0;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 1) {
      binario[1] = 0;
      binario[2] = 0;
      binario[3] = 0;
      binario[4] = 1;
    }
    if(vetor_armazem[i] == 2) {
      binario[1] = 0;
      binario[2] = 0;
      binario[3] = 1;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 3) {
      binario[1] = 0;
      binario[2] = 0;
      binario[3] = 1;
      binario[4] = 1;
    }
    if(vetor_armazem[i] == 4) {
      binario[1] = 0;
      binario[2] = 1;
      binario[3] = 0;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 5) {
      binario[1] = 0;
      binario[2] = 1;
      binario[3] = 0;
      binario[4] = 1; 
    }
    if(vetor_armazem[i] == 6) {
      binario[1] = 0;
      binario[2] = 1;
      binario[3] = 1;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 7) {
      binario[1] = 1;
      binario[2] = 0;
      binario[3] = 1;
      binario[4] = 1;
    }
    if(vetor_armazem[i] == 8) {
      binario[1] = 0;
      binario[2] = 1;
      binario[3] = 1;
      binario[4] = 1;
    }
    if(vetor_armazem[i] == 9) {
      binario[1] = 1;
      binario[2] = 0;
      binario[3] = 0;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 10) {
      binario[1] = 1;
      binario[2] = 0;
      binario[3] = 1;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 11) {
      binario[1] = 1;
      binario[2] = 0;
      binario[3] = 1;
      binario[4] = 1;
    }
    if(vetor_armazem[i] == 12) {
      binario[1] = 1;
      binario[2] = 1;
      binario[3] = 0;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 13) {
      binario[1] = 1;
      binario[2] = 1;
      binario[3] = 0;
      binario[4] = 1;
    }
    if(vetor_armazem[i] == 14) {
      binario[1] = 1;
      binario[2] = 1;
      binario[3] = 1;
      binario[4] = 0;
    }
    if(vetor_armazem[i] == 15) {
      binario[1] = 1;
      binario[2] = 1;
      binario[3] = 1;
      binario[4] = 1;
    }
    int st_led_azul =  binario[1];
    digitalWrite(led_azul, st_led_azul);
    int st_led_verde =  binario[2];
    digitalWrite(led_verde, st_led_verde);
    int st_led_vermelho =  binario[3];
    digitalWrite(led_vermelho, st_led_vermelho);
    int st_led_amarelo =  binario[4];
    digitalWrite(led_amarelo, st_led_amarelo);
    i += 1;
  }
}

void loop() {
  int leitura = analogRead(8);
  if(leitura >= 600){
    leitura = 600;
  }
  int conversao = leitura/40;
  delay(100);
  
  int binario[4] = {0,0,0,0};
  if(conversao == 0) {
    binario[1] = 0;
    binario[2] = 0;
    binario[3] = 0;
    binario[4] = 0;
  }
  if(conversao == 1) {
    binario[1] = 0;
    binario[2] = 0;
    binario[3] = 0;
    binario[4] = 1;
  }
  if(conversao == 2) {
    binario[1] = 0;
    binario[2] = 0;
    binario[3] = 1;
    binario[4] = 0;
  }
  if(conversao == 3) {
    binario[1] = 0;
    binario[2] = 0;
    binario[3] = 1;
    binario[4] = 1;
  }
  if(conversao == 4) {
    binario[1] = 0;
    binario[2] = 1;
    binario[3] = 0;
    binario[4] = 0;
  }
  if(conversao == 5) {
    binario[1] = 0;
    binario[2] = 1;
    binario[3] = 0;
    binario[4] = 1; 
  }
  if(conversao == 6) {
    binario[1] = 0;
    binario[2] = 1;
    binario[3] = 1;
    binario[4] = 0;
  }
  if(conversao == 7) {
    binario[1] = 1;
    binario[2] = 0;
    binario[3] = 1;
    binario[4] = 1;
  }
  if(conversao == 8) {
    binario[1] = 0;
    binario[2] = 1;
    binario[3] = 1;
    binario[4] = 1;
  }
  if(conversao == 9) {
    binario[1] = 1;
    binario[2] = 0;
    binario[3] = 0;
    binario[4] = 0;
  }
  if(conversao == 10) {
    binario[1] = 1;
    binario[2] = 0;
    binario[3] = 1;
    binario[4] = 0;
  }
  if(conversao == 11) {
    binario[1] = 1;
    binario[2] = 0;
    binario[3] = 1;
    binario[4] = 1;
  }
  if(conversao == 12) {
    binario[1] = 1;
    binario[2] = 1;
    binario[3] = 0;
    binario[4] = 0;
  }
  if(conversao == 13) {
    binario[1] = 1;
    binario[2] = 1;
    binario[3] = 0;
    binario[4] = 1;
  }
  if(conversao == 14) {
    binario[1] = 1;
    binario[2] = 1;
    binario[3] = 1;
    binario[4] = 0;
  }
  if(conversao == 15) {
    binario[1] = 1;
    binario[2] = 1;
    binario[3] = 1;
    binario[4] = 1;
  }
  
  int frequencia = conversao * 30 + 30;
  tone(10, frequencia);
  int st_led_azul =  binario[1];
  digitalWrite(led_azul, st_led_azul);
  int st_led_verde =  binario[2];
  digitalWrite(led_verde, st_led_verde);
  int st_led_vermelho =  binario[3];
  digitalWrite(led_vermelho, st_led_vermelho);
  int st_led_amarelo =  binario[4];
  digitalWrite(led_amarelo, st_led_amarelo);

  if (digitalRead(botao1) == LOW) {
    armazena(conversao);
  }

  if (digitalRead(botao2) == LOW) {
    play();
  }
}