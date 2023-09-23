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

    verificacion(); // Llamamos a la función de verificación

}

void verificacion() {

    // Encender todos los LEDs
    shiftOut(SER1, SRCLK1, MSBFIRST, 255); //Se cargan los datos en el registro de desplazamiento
    digitalWrite(RCLK1, HIGH); // Latch para actualizar la matriz (cargar datos al registro de almacenamiento)
    digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz

    delay(2000); // Espera 2 segundos (todos los LEDs encendidos)

    // Apagar todos los LEDs
    shiftOut(SER1, SRCLK1, MSBFIRST, 0); // Se apagan los LEDs en el primer registro de desplazamiento
    digitalWrite(RCLK1, HIGH); // Latch para apagar la matriz (cargar datos al registro de almacenamiento)
    digitalWrite(RCLK1, LOW); // actualiza y muestra correctamente los datos en la matriz

    delay(2000); // Espera 2 segundos (todos los LEDs apagados)

}
void imagen() {
    byte patrones[8]; // Array para almacenar el patrón de cada fila
    byte fila;

    for (fila = 0; fila < 8; fila++) {
        Serial.print("Ingrese el patrón para la fila ");
        Serial.print(fila);
        Serial.print(": ");

    }


}
