// Definición de pines
#define SER1 11
#define SRCLK1 12
#define RCLK1 8
#define SER2 7
#define SRCLK2 13
#define RCLK2 9

void setup() {
    // Configuración de pines como salidas
    pinMode(SER1, OUTPUT);
    pinMode(SRCLK1, OUTPUT);
    pinMode(RCLK1, OUTPUT);
    pinMode(SER2, OUTPUT);
    pinMode(SRCLK2, OUTPUT);
    pinMode(RCLK2, OUTPUT);

    // Inicializamos los pines por los que vamos a escribir
    digitalWrite(RCLK1, LOW);
    digitalWrite(RCLK2, LOW);

}

void loop() {
    // Encender todos los LEDs

    shiftOut(SER1, SRCLK1, MSBFIRST, 255); //Se cargan los datos en el registro de desplazamiento

    digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz


    delay(1000); // Espera 1 segundo
}
