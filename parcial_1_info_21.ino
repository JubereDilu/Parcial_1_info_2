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


int j = 0;
r
int k;

int row[8] = {1, 0, 0, 0, 0, 0, 0, 0};

int columnH[8] = {1, 0, 0, 0, 0, 0, 0, 0};

int matriz[8][8];

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
  
  verificacion(); // Llamamos a la función de verificación
  
  
}

void verificacion() {  
    
    shiftOut(SER1, SRCLK1, LSBFIRST, columnH[0]);
    shiftOut(SER1, SRCLK1, LSBFIRST, row[0]);
  // Encender todos los LEDs
    //shiftOut(SER1, SRCLK1, MSBFIRST, 255);  //Se cargan los datos en el registro de desplazamiento
    digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
  
   	delay(2000); // Espera 2 segundos (todos los LEDs encendidos)
    
  // Apagar todos los LEDs
   	shiftOut(SER1, SRCLK1, MSBFIRST, 0); // Se apagan los LEDs en el primer registro de desplazamiento     
    digitalWrite(RCLK1, HIGH); // Latch para apagar la matriz (cargar datos al registro de almacenamiento)
    digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz
   
    delay(2000); // Espera 2 segundos (todos los LEDs apagados)
   
}

