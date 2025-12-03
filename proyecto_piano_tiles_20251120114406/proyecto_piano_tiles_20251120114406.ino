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
#define COL_8 10// Pines que controlan las 8 filas

byte rowPins[8] = { ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8 };
byte colPins[8] = { COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8 };
// Ajusta este valor dependiendo del tipo de matriz:
// Para matriz de cátodo en filas: fila = LOW para encender
// Para matriz de ánodo en filas: fila = HIGH para encender
bool ROW_ACTIVE = LOW;
bool COL_ACTIVE = HIGH;

#define SONG_ROWS 20   // Número total de filas de la canción
#define BLOCKS_PER_ROW 4

uint8_t songBuffer[SONG_ROWS][BLOCKS_PER_ROW] = {
  {1,0,0,1},
  {0,1,1,0},
  {0,0,1,0},
  {1,0,0,1},
  {1,0,0,1},
  {0,1,1,0},
  {0,0,1,0},
  {1,0,0,1},
  {1,0,0,1},
  {0,1,0,0},
  {1,0,1,0},
  {1,0,0,1},
  {1,0,0,1},
  {0,1,1,0},
  {0,1,1,0},
  {1,1,0,1},
  {1,0,0,1},
  {0,1,1,0},
  {0,0,1,0},
  {1,0,0,1},
};


void setup() {
  // Configurar pines como salida
  for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(colPins[i], OUTPUT);
  }

  // Apagar todo inicialmente
  clearMatrix();
}

void loop() {

scrollBuffer(songBuffer, SONG_ROWS, 80);
}


// ------------------------------
// Función para apagar todo
// ------------------------------
void clearMatrix() {
  for (int r = 0; r < 8; r++)
    digitalWrite(rowPins[r], !ROW_ACTIVE);

  for (int c = 0; c < 8; c++)
    digitalWrite(colPins[c], !COL_ACTIVE);
}

void scrollBuffer(uint8_t buffer[][BLOCKS_PER_ROW], int numRows, int speedMs) {
  
  int maxOffset = numRows * 2; // cada bloque = 2 filas físicas
  for (int offset = maxOffset; offset > 0; offset--) {

    unsigned long tStart = millis();
    
    while (millis() - tStart < speedMs) {

      for (int col = 0; col < 8; col++) {

        // Calculamos la fila del buffer correspondiente
        int shiftedRow;
        int rowInBuffer;
        int blockRow;
        uint8_t value;
        
        // Para cada fila física 0-7
        // calculamos qué fila de bloque mostrar
        drawColumnFromBuffer(buffer, numRows, col, offset);
      }
    }
  }
}
void drawColumnFromBuffer(uint8_t buffer[][BLOCKS_PER_ROW], int numRows, int col, int offset) {

  // Apagar todo
  for (int r = 0; r < 8; r++) digitalWrite(rowPins[r], !ROW_ACTIVE);
  for (int c = 0; c < 8; c++) digitalWrite(colPins[c], !COL_ACTIVE);

  digitalWrite(colPins[col], COL_ACTIVE);

  int blockCol = col / 2;

  for (int realRow = 0; realRow < 8; realRow++) {

    int bufferRow = (realRow + offset) / 2;

    if (bufferRow >= numRows) continue; // fuera de rango

    if (buffer[bufferRow][blockCol] == 1) {
      digitalWrite(rowPins[realRow], ROW_ACTIVE);
    }
  }
}

