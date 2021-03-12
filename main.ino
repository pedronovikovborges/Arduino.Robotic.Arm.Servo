Projeto: Programa que utiliza 4 servomotores e o teclado do pc para controlar um braço robótico  em arduino.                                */

#include <Servo.h>

//DECLARAÇÃO DOS SERVOS
  Servo servoGarra;
  Servo servoBase;
  Servo servoDir;
  Servo servoEsq;

//DECLARAÇÃO DAS VARIAVEIS USADAS PARA A POSICAO DO SERVO 
  int posBase = 90;
  int posGarra = 150;
  int posDir = 60;
  int posEsq = 60;

  int inicio = 0;
  
void setup(){
  //DEFINIÇÃO DOS PINOS DE CONTROLE DE CADA SERVO NO ARDUINO
  servoBase.attach(8);
  servoGarra.attach(9);
  servoDir.attach(10);
  servoEsq.attach(11);

  //DEFINICAO DA VELOCIDADE DA PORTA SERIAL PARA RECEBER OS DADOS DO TECLADO
  Serial.begin(9600);
}

void loop(){

//CARREGA A POSIÇÃO INICIAL NO BRAÇO
  if(inicio == 0){
    servoGarra.write(posGarra);
    servoBase.write(posBase);
    servoDir.write(posDir);
    servoEsq.write(posEsq);
    inicio++;
  }

  //VERIFICAR SE A SERIAL ESTA ATIVA
  if (Serial.available()) { 
    char caractere = Serial.read(); //RECEBE O CARACTER DIGITADO NO TECLADO

//AO DIGITAR UM CARACTER, A POSICAO DOS SERVOS SAO INCREMENTADAS OU DECREMENTADAS EM 2 GRAUS, DEPENDENDO DO SENTIDO DO MOVIMENTO
//E O NOVO ANGULO É ENVIADO PARA O SERVO
    //ABRE GARRA
    if (caractere == 'o' || caractere == 'O'){
      posGarra += 2;
      servoGarra.write(posGarra);
    }
    //FECHA GARRA
    else if(caractere == 'l' || caractere == 'L'){
      posGarra -= 2;
      servoGarra.write(posGarra);
    }
    
    //RODA BASE PARA A DIREITA
    else if(caractere == 'd' || caractere == 'D'){
      posBase -= 2;
      servoBase.write(posBase);
    }
    //RODA BASE PARA A ESQUERDA
    else if(caractere =='a' || caractere == 'A'){
       posBase += 2;
      servoBase.write(posBase);
    } 
    //BRAÇO SE MOVE PARA A FRENTE
    else if(caractere =='s' || caractere == 'S'){
      posDir -= 2;
      posEsq -= 2;
      servoDir.write(posDir);
      servoEsq.write(posEsq);
    }
    //BRAÇO SE MOVE PARA TRÁS
    else if(caractere =='w' || caractere == 'W'){
      posDir += 2;
      posEsq += 2;
      servoDir.write(posDir);
      servoEsq.write(posEsq);
    } else{
      
    }    
  }
}
