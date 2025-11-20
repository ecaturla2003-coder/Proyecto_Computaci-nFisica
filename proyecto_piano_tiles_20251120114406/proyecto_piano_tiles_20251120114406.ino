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

uint8_t notePattern[4][4] = {
  {1, 0, 0, 1},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {1, 0, 0, 1}
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

  // --- PRUEBA DE FILAS ---
  /*for (int r = 0; r < 8; r++) {
    clearMatrix();
    digitalWrite(rowPins[r], ROW_ACTIVE);  // Enciendo la fila completa
    for (int c = 0; c < 8; c++) {
      digitalWrite(colPins[c], COL_ACTIVE);
    }
    delay(500);
  }*/

  drawBlockMatrix(notePattern);

  delay(1000);

  // --- PRUEBA DE COLUMNAS ---
  /*for (int c = 0; c < 8; c++) {
    clearMatrix();
    digitalWrite(colPins[c], COL_ACTIVE);  // Enciendo la columna completa
    for (int r = 0; r < 8; r++) {
      digitalWrite(rowPins[r], ROW_ACTIVE);
    }
    delay(500);
  }*/

  delay(1000);
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

// Dibuja una nota representada como matriz de 4x4 bloques
void drawBlockMatrix(uint8_t matrix[4][4]) {

  for (int br = 0; br < 4; br++) {        // block row (0–3)
    for (int bc = 0; bc < 4; bc++) {      // block column (0–3)

      bool blockOn = matrix[br][bc];      // 0 = off, 1 = on

      // Determina el rango real de LEDs (8x8)
      int startRow = br * 2;              // 0,2,4,6   → 2 LEDs por bloque
      int startCol = bc * 2;

      for (int r = 0; r < 2; r++) {       // Cada bloque usa 2x2 LEDs
        for (int c = 0; c < 2; c++) {

          int realR = startRow + r;
          int realC = startCol + c;

          // Enciende o apaga el LED
          digitalWrite(rowPins[realR], blockOn ? ROW_ACTIVE : !ROW_ACTIVE);
          digitalWrite(colPins[realC], blockOn ? COL_ACTIVE : !COL_ACTIVE);
        }
      }

    }
  }
}
