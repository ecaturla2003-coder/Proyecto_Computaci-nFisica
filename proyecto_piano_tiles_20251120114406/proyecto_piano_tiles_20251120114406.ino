// ---------- (mantén tus defines y pines como estaban) ----------
#include <Arduino.h>
#include <stdint.h>

#define ROW_1 A0
#define ROW_2 4
#define ROW_3 5
#define ROW_4 11
#define ROW_5 7
#define ROW_6 12
#define ROW_7 A2
#define ROW_8 A3

#define COL_1 6
#define COL_2 3
#define COL_3 8
#define COL_4 2
#define COL_5 13
#define COL_6 9
#define COL_7 A1
#define COL_8 10

#define BUTTON_PIN A4
#define BUZZER A5

int melody[] = {

  587, 622, 587, 622, 587, 622, 587, 622, 523, 587, 523, 587, 523, 587, 466, 523, 466, 523, 466, 523, 440, 392, 370, 370, 370, 370, 0, 0,
  293, 293, 293, 293, 0, 0, 0, 0,

  293, 293, 392, 392, 466, 466, 587, 587, 587, 587, 0, 0, 587, 587, 523, 523, 466, 466, 440, 440, 466, 466, 466, 466, 0, 0,

  392, 392, 466, 466, 587, 587, 784, 784, 784, 784, 0, 0, 784, 784, 784, 784, 698, 698, 622, 622, 698, 698, 698, 698, 698, 698, 0, 0,

  440, 440, 587, 587, 698, 698, 880, 880, 880, 880, 784, 784, 698, 698, 659, 659, 698, 698, 784, 784, 784, 784, 698, 698, 659, 659, 659, 659, 587, 587, 523, 523, 466, 466,
  523, 523, 587, 587, 523, 523, 392, 392, 440, 440, 440, 440, 440, 440, 440, 440, 0, 0, 0, 0,

  1046, 932, 932, 932, 880, 880, 880, 0, 0, 1046, 932, 932, 880, 784, 740, 622, 587, 587, 587, 587, 0,

  98, 98, 293, 293, 293, 293, 73, 73, 293, 293, 293, 293, 98, 98, 293, 293, 293, 293,

  293, 293, 392, 392, 466, 466, 587, 587, 587, 587, 587, 587, 523, 523, 466, 466, 440, 440, 466, 466, 466, 466,
  392, 392, 466, 466, 587, 587, 784, 784, 784, 784, 784, 784, 784, 784, 698, 698, 622, 622, 698, 698, 698, 698, 698, 698,
  440, 440, 587, 587, 698, 698, 880, 880, 880, 880, 784, 784, 698, 698, 659, 659, 698, 698, 784, 784, 784, 784, 698, 698, 659, 659,
  659, 587, 554, 587, 587, 523, 523, 466, 466, 440, 440, 494, 494, 554, 554, 587, 587, 587, 587, 587,
};


int baseDuration = 350;
int currentNote = 0;

byte rowPins[8] = { ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8 };
byte colPins[8] = { COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8 };

bool ROW_ACTIVE = LOW;
bool COL_ACTIVE = HIGH;

#define SONG_ROWS 160
#define BLOCKS_PER_ROW 4

uint8_t songBuffer[SONG_ROWS][BLOCKS_PER_ROW] = {
  {0,0,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,0,0,1},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {1,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,0},
  {0,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,1,0,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,1,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,0,1},
  {0,0,1,0},
};

// ----- estado botones -----
int ultimoBoton = -1;
unsigned long tiempoBoton = 0;
const unsigned long VENTANA_MS = 150; // ventana de tiempo para aceptar la pulsación

// ----- filas ya procesadas (para no contar doble) -----
bool consumed[SONG_ROWS];

// -------------------------
void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT); // analog pin read, ladder con pull-down externo
  Serial.begin(9600);

  // apaga todo y resetea consumed
  for (int i = 0; i < SONG_ROWS; i++) consumed[i] = false;
  clearMatrix();
}

// -------------------------
void clearMatrix() {
  for (int r = 0; r < 8; r++) digitalWrite(rowPins[r], !ROW_ACTIVE);
  for (int c = 0; c < 8; c++) digitalWrite(colPins[c], !COL_ACTIVE);
}

// -------------------------
// lee el ladder y devuelve 0..3 o -1
int leerBoton() {
  int v = analogRead(BUTTON_PIN);

  if (v < 1) return -1;        // Nada
  else if (v < 600) return 0; // 220Ω
  else if (v < 900) return 1; // 330Ω
  else if (v < 1000) return 2; // 2kΩ
  else if (v < 1200) return 3; // 10kΩ

  return -1;
}

// -------------------------
// Dibuja UNA columna (multiplexado) para el offset dado
void drawColumnFromBuffer(uint8_t buffer[][BLOCKS_PER_ROW], int numRows, int col, int offset) {

  // Apagamos todas las filas (estado base para esta columna)
  for (int r = 0; r < 8; r++) digitalWrite(rowPins[r], !ROW_ACTIVE);
  // Apagamos todas las columnas por seguridad
  for (int c = 0; c < 8; c++) digitalWrite(colPins[c], !COL_ACTIVE);

  // Activamos solo la columna actual
  digitalWrite(colPins[col], COL_ACTIVE);

  int blockCol = col / 2;

  for (int realRow = 0; realRow < 8; realRow++) {
    int bufferRow = (realRow + offset) / 2;

    // Si fuera de rango, apagamos esa fila
    if (bufferRow < 0 || bufferRow >= numRows) {
      digitalWrite(rowPins[realRow], !ROW_ACTIVE);
      continue;
    }

    // Si la celda está a 1 -> ON, sino OFF (esto evita arrastres)
    if (buffer[bufferRow][blockCol] == 1) digitalWrite(rowPins[realRow], ROW_ACTIVE);
    else digitalWrite(rowPins[realRow], !ROW_ACTIVE);
  }
}

// -------------------------
// Detecta aciertos/misses para la fila que está EN LA PARTE INFERIOR en este offset
void detectarAciertos_porOffset(uint8_t buffer[][BLOCKS_PER_ROW], int numRows, int offset) {

  // Calculamos qué fila del buffer está en la fila física 7 (la inferior)
  int bufferRowBottom = (7 + offset) / 2;

  // Validez
  if (bufferRowBottom < 0 || bufferRowBottom >= numRows) return;

  // Si ya procesamos esa fila antes, saltamos
  if (consumed[bufferRowBottom]) return;

    int note = melody[currentNote];
    if (note == 0) noTone(BUZZER);
    else
    {
      tone(BUZZER, note, baseDuration);
      
    }
    currentNote++;

  // Leemos si hubo pulsación reciente
  bool huboPulsacionReciente = (millis() - tiempoBoton <= VENTANA_MS);
  int boton = -1;
  if (huboPulsacionReciente) {
    boton = ultimoBoton;
  }

  // Para cada bloque de columna (0..3)
  for (int blockCol = 0; blockCol < BLOCKS_PER_ROW; blockCol++) {
    if (buffer[bufferRowBottom][blockCol] == 1) {
      // nota presente en esta columna de bloques
      if (huboPulsacionReciente && boton == blockCol) {
        Serial.print("✔ ACIERTO en columna ");
        Serial.println(blockCol);
        // Consumir pulsación para evitar múltiples hits con la misma pulsación
        ultimoBoton = -1;
        tiempoBoton = 0;
      } else {
        // Si no hubo pulsación reciente o la pulsación no coincide
        Serial.print("✘ FALLO en columna ");
        Serial.println(blockCol);
      }
    }
  }

  // Marcamos la fila del buffer como procesada (no volverá a contarse)
  consumed[bufferRowBottom] = true;
}

// -------------------------
// Scroll principal: offset sube 0..maxOffset-1
void scrollBuffer(uint8_t buffer[][BLOCKS_PER_ROW], int numRows, int speedMs) {
  int maxOffset = numRows * 2;

  for (int offset = maxOffset; offset > 0; offset--) {

    unsigned long tStart = millis();

    // Durante speedMs mostramos el mismo offset, escaneando columnas
    while (millis() - tStart < speedMs) {

      for (int col = 0; col < 8; col++) {

        drawColumnFromBuffer(buffer, numRows, col, offset);

        // Leer botón continuamente durante el multiplexado
        int b = leerBoton();
        if (b != -1) {
          ultimoBoton = b;
          tiempoBoton = millis();
        }

        // breve tiempo por columna para control de refresco (ajusta si quieres)
        delayMicroseconds(800);
      }
    }

    // Después de mostrar este offset, procesamos la fila que está abajo
    detectarAciertos_porOffset(buffer, numRows, offset);
  }
}

// -------------------------
void loop() {
  scrollBuffer(songBuffer, SONG_ROWS, 200);
}
