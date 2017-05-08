int rows[] = {8, 11};
int rowCount = 2;
int cols[] = {3, 4, 2};
int colCount = 3;
bool hold[2][3]; // equal to [rowCount][colCount]

void setup() {
  //start serial connection
  Serial.begin(9600);

  // all rows OUTPUT : HIGH
  for (int i = 0; i < sizeof(rows); i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
  }
  // all columns INPUT_PULLUP
  for (int i = 0; i < sizeof(cols); i++) {
    pinMode(cols[i], INPUT_PULLUP);
  }
}
void loop() {
  scan();
  printHold();
  Serial.println();
  delay(5);
}

//-----defined functions-----
void scan() {
  for (int r = 0; r < rowCount; r++) {
    pinMode(rows[r], LOW);
    for (int c = 0; c < colCount; c++) {
      hold[r][c] = !digitalRead(cols[c]);
      delay(1);
    }
    pinMode(rows[r], HIGH);
  }
}

void printHold() {
  for (int r = 0; r < rowCount; r++) {
    Serial.println();
    for (int c = 0; c < colCount; c++) {
      Serial.print(hold[r][c]);
    }  
  }
}


