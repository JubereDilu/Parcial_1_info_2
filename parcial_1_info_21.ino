// Definición de pines
#define SER1   8  
#define RCLK1   9  
#define SRCLK1   10  

//#define SER2 8    4
//#define RCLK2 9    5
//#define SRCLK2 10   6

// data 8
//store 9 
//shift 10




void setup() {
    Serial.begin(9600);
  
    // Configuración de pines como salidas
    pinMode(SER1, OUTPUT);
    pinMode(SRCLK1, OUTPUT);
    pinMode(RCLK1, OUTPUT);
   // pinMode(SER2, OUTPUT);
   //pinMode(SRCLK2, OUTPUT);
   // pinMode(RCLK2, OUTPUT);
    
    // Inicializamos los pines por los que vamos a escribir
    digitalWrite(RCLK1, LOW);
    //digitalWrite(RCLK2, LOW);
     
}

void loop() {
  
 //verificacion(); // Llamamos a la función de verificación
  //patron2();
  patronx();

}

void verificacion() {  
    
	digitalWrite(RCLK1, LOW);
    shiftOut(SER1, SRCLK1, MSBFIRST, 255);  //Se cargan los datos en el registro de desplazamiento
    //digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    //digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
  
   	delay(2000); // Espera 2 segundos (todos los LEDs encendidos)
    
  // Apagar todos los LEDs
 	//digitalWrite(RCLK1, LOW);
   	shiftOut(SER1, SRCLK1, MSBFIRST, 0); // Se apagan los LEDs en el primer registro de desplazamiento     
    digitalWrite(RCLK1, HIGH); // Latch para apagar la matriz (cargar datos al registro de almacenamiento)
    //digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
   
    delay(2000); // Espera 2 segundos (todos los LEDs apagados)
   
}
void patron2() {
  
  int matriz[8][8];
  
   // Llenar la matriz con espacios en blanco
   for (int i = 0; i < 8; i++) {
       for (int j = 0; j < 8; j++) {
           matriz[i][j] = 0 ;
        }
    }
   // Colocar la "X" en la matriz
   for (int i = 0; i < 8; i++) {
       matriz[i][i] = 1 ;
       matriz[i][7 - i] = 1;
    }
  	
  	// Imprimir la matriz
    
    for (int i = 0; i < 8; i++) {
        
        for (int j = 0; j < 8; j++) {
          	shiftOut(SER1, SRCLK1, MSBFIRST,matriz[i][j] );  //Se cargan los datos en el registro de desplazamiento
    		//digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    		//digitalWrite(RCLK1, LOW)
             //cout << matriz[i][j];
        }
      	digitalWrite(RCLK1, HIGH);
      	digitalWrite(RCLK1, LOW);
      	delay(2000); // Espera 2 segundos (todos los LEDs encendidos)
	}
}
void patronx() {  
    
	digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
    shiftOut(SER1, SRCLK1, LSBFIRST, B10000001);  //Se cargan los datos en el registro de desplazamiento
  	shiftOut(SER1, SRCLK1, MSBFIRST, B01111110);  
    digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
  
 	digitalWrite(RCLK1, LOW);// actualiza y muestra correctamente los datos en la matriz
   	shiftOut(SER1, SRCLK1, LSBFIRST, B01000010); // Se apagan los LEDs en el primer registro de desplazamiento 
  	shiftOut(SER1, SRCLK1, MSBFIRST, B10111101);
    digitalWrite(RCLK1, HIGH); // Latch para apagar la matriz (cargar datos al registro de almacenamiento)
     
    digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
    shiftOut(SER1, SRCLK1, LSBFIRST, B00100100);  //Se cargan los datos en el registro de desplazamiento
  	shiftOut(SER1, SRCLK1, MSBFIRST, B11011011);  
    digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    
   digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
    shiftOut(SER1, SRCLK1, LSBFIRST, B00011000);  //Se cargan los datos en el registro de desplazamiento
  	shiftOut(SER1, SRCLK1, MSBFIRST, B11100111);  
    digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    
    
   
}



