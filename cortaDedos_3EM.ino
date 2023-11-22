#define motor 7
#define piston 6
#define botonOn 5
#define botonOff 4

#define tCambioGiro 500
#define tAvancePiston 500
#define tPausarPiston 500

#define tCG tCambioGiro/100
#define tAP tAvancePiston/100
#define tPP tPausarPiston/100

int w = 0;
long tiempoInicial, tiempoActual;

void setup() {
  pinMode(motor, OUTPUT);
  pinMode(piston, OUTPUT);
  pinMode(botonOn, INPUT);
  pinMode(botonOff, INPUT);
}

void loop (){
  if (digitalRead(botonOn) == 1 || w == 1){
    w = 1;
    girar1();
    girar2();
  } else apagar();
}

void apagar(){
  digitalWrite(motor, LOW);
  digitalWrite(piston, LOW);
  w = 0;
}

void girar1(){
  tiempoInicial = millis();
  
  while(tiempoActual - tiempoInicial <= tCG){
    digitalWrite(motor, HIGH);
    tiempoActual = millis();

    if (digitalRead(botonOff) == 1){
      apagar();
    }

    avanzarPiston();
    pausarPiston();

  }
}

void girar2(){
  tiempoInicial = millis();
  
  while(tiempoActual - tiempoInicial <= tCG){
    digitalWrite(motor, LOW);
    tiempoActual = millis();

    if (digitalRead(botonOff) == 1){
      apagar();
    }
    
    avanzarPiston();
    pausarPiston();
  }
}

void avanzarPiston(){
  digitalWrite(piston, HIGH);
  for (int i = 0; i < tAP; i++){
    delay(100);
    if (digitalRead(botonOff) == 1){
      apagar();
    }
  }
}

void pausarPiston(){
  digitalWrite(piston, LOW);
    for (int i = 0; i < tPP; i++){
    delay(100);
    if (digitalRead(botonOff) == 1){
      apagar();
    }
  }
}





