// Definición de pines
#define SER1   8  
#define RCLK1   9  
#define SRCLK1   10  

unsigned long tiempoInicio = 0;//guarda tiempo de referencia 
int segundos = 500; 
  
void setup() {
    Serial.begin(9600);
  
    // Configuración de pines como salidas
    pinMode(SER1, OUTPUT);
    pinMode(SRCLK1, OUTPUT);
    pinMode(RCLK1, OUTPUT);
    
    // Inicializamos los pines por los que vamos a escribir
    digitalWrite(RCLK1, LOW);     
}

  
void loop() {
  
  // DESCOMENTA LO QUE QUIERAS PROBAR 
  // LO INTENTE PERO NO PUDE, ME QUEDO GRANDE  =( 
  
  //verificacion(); // Llamamos a la función de verificación
  //patron1();
  //patron2(); //llamamos la funcion que muestra el pantron X
  //patron3();
  //patron4();
}

int binarioADecimal(int fila[], int longitud) {
    int decimal = 0;
    int peso = 1; // Inicializar el peso en 2^0
    for (int i = longitud - 1; i >= 0; i--) {
        decimal += fila[i] * peso;
        peso *= 2; // Multiplicar el peso por 2 para el próximo bit
    }
    return decimal;
}
  

void verificacion() {  
    
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, 0);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 254 );  
      digitalWrite(RCLK1, HIGH); 
  
    // Declarar una matriz 8x8 e inicializarla con 1
    int matriz[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = 1;
        }
    }
 	// Declarar un arreglo de variables para almacenar los números decimales
    int numerosDecimales[8];

    // Calcular y almacenar los números decimales
    for (int i = 0; i < 8; i++) {
        numerosDecimales[i] = binarioADecimal(matriz[i], 8);
    }
      
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST,numerosDecimales[0]  );  
      shiftOut(SER1, SRCLK1, LSBFIRST, 254 );  
      digitalWrite(RCLK1, HIGH); 

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST,numerosDecimales[1]);  
      shiftOut(SER1, SRCLK1, LSBFIRST,  253);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[2]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 251 );  
      digitalWrite(RCLK1, HIGH);

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[3]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 247 );  
      digitalWrite(RCLK1, HIGH); 
 
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[4]);  
      shiftOut(SER1, SRCLK1, LSBFIRST,239 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[5]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 223);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[6]);  
      shiftOut(SER1, SRCLK1, LSBFIRST,191 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[7]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 127);  
      digitalWrite(RCLK1, HIGH);
}

void patron2(){
  
    int matriz[8][8];

    // Llenar la matriz con espacios en blanco
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = 0;
        }
    }

    // Colocar la "X" en la matriz
    for (int i = 0; i < 8; i++) {
        matriz[i][i] = 1;
        matriz[i][7 - i] = 1;
    }

    // Declarar un arreglo de variables para almacenar los números decimales
    int numerosDecimales[8];

    // Calcular y almacenar los números decimales
    for (int i = 0; i < 8; i++) {
        numerosDecimales[i] = binarioADecimal(matriz[i], 8);
    }
  	//Mustra en los leds el patron
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST,numerosDecimales[0]  );  
      shiftOut(SER1, SRCLK1, LSBFIRST, 254 );  
      digitalWrite(RCLK1, HIGH); 

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST,numerosDecimales[1]);  
      shiftOut(SER1, SRCLK1, LSBFIRST,  253);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[2]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 251 );  
      digitalWrite(RCLK1, HIGH);

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[3]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 247 );  
      digitalWrite(RCLK1, HIGH); 
 
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[4]);  
      shiftOut(SER1, SRCLK1, LSBFIRST,239 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[5]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 223);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[6]);  
      shiftOut(SER1, SRCLK1, LSBFIRST,191 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, numerosDecimales[7]);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 127);  
      digitalWrite(RCLK1, HIGH); 

}
void patron1(){
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST,  B00011000);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 254 );  
      digitalWrite(RCLK1, HIGH); 

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B00111100);  
      shiftOut(SER1, SRCLK1, LSBFIRST,  253);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B01111110);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 251 );  
      digitalWrite(RCLK1, HIGH);

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B11111111);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 247 );  
      digitalWrite(RCLK1, HIGH); 
 
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B11111111);  
      shiftOut(SER1, SRCLK1, LSBFIRST,239 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B01111110);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 223);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B00111100);  
      shiftOut(SER1, SRCLK1, LSBFIRST,191 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, MSBFIRST, B00011000);  
      shiftOut(SER1, SRCLK1, LSBFIRST, 127);  
      digitalWrite(RCLK1, HIGH); 
}
void patron3(){
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST,  B11011011);  
      shiftOut(SER1, SRCLK1, MSBFIRST,  B01111111);  
      digitalWrite(RCLK1, HIGH); 

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B11011011);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B10111111);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B01101101);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B11011111);  
      digitalWrite(RCLK1, HIGH);

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B01101101);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B11101111);  
      digitalWrite(RCLK1, HIGH); 
 
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B11011011);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B11110111);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B11011011);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B11111011);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B01101101);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B11111101);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B01101101);  
      shiftOut(SER1, SRCLK1, MSBFIRST, B11111110);  
      digitalWrite(RCLK1, HIGH); 
}
void patron4(){
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST,  B11110000);  
      shiftOut(SER1, SRCLK1, MSBFIRST, 254 );  
      digitalWrite(RCLK1, HIGH); 

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B01111000);  
      shiftOut(SER1, SRCLK1, MSBFIRST,  253);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B00111100);  
      shiftOut(SER1, SRCLK1, MSBFIRST, 251 );  
      digitalWrite(RCLK1, HIGH);

      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B00011110);  
      shiftOut(SER1, SRCLK1, MSBFIRST, 247 );  
      digitalWrite(RCLK1, HIGH); 
 
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B00011110);  
      shiftOut(SER1, SRCLK1, MSBFIRST,239 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B00111100);  
      shiftOut(SER1, SRCLK1, MSBFIRST, 223);  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B01111000);  
      shiftOut(SER1, SRCLK1, MSBFIRST,191 );  
      digitalWrite(RCLK1, HIGH); 
  
      digitalWrite(RCLK1, LOW); 
      shiftOut(SER1, SRCLK1, LSBFIRST, B11110000);  
      shiftOut(SER1, SRCLK1, MSBFIRST, 127);  
      digitalWrite(RCLK1, HIGH); 
}

