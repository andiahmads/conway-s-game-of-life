#include <raylib.h>
#include <stdio.h>

#define GRID_WIDTH 100
#define GRID_HEIGHT 100
#define CELL_SIZE 10
int currentGrid[GRID_WIDTH][GRID_HEIGHT] = {0};
int nextGrid[GRID_WIDTH][GRID_HEIGHT] = {0};

// Fungsi ini:
//
// Melakukan loop melalui 8 tetangga di sekitar sel (x,y)
//
// Melewati sel itu sendiri (i=0, j=0)
//
// Memeriksa apakah tetangga berada dalam batas grid
//
// Menghitung berapa banyak tetangga yang hidup (nilai 1)
int countNeighbors(int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue; // lewati sell sendiri
      //
      int nx = x + i;
      int ny = y + j;

      // periksa batas grid
      if (nx >= 0 && nx < GRID_WIDTH && ny >= 0 && ny < GRID_HEIGHT) {
        count += currentGrid[nx][ny];
      }
    }
  }
  return count;
}

// Fungsi ini menerapkan aturan Game of Life:
// Untuk setiap sel, hitung jumlah tetangga yang hidup
// Jika sel hidup:
// Tetap hidup jika memiliki 2 atau 3 tetangga hidup
// Mati (underpopulation/overpopulation) jika tidak
// Jika sel mati:
// Menjadi hidup (reproduction) jika memiliki tepat 3 tetangga hidup
// Setelah semua sel dihitung, salin nextGrid ke currentGrid
void updateGrid() {
  for (int x = 0; x < GRID_WIDTH; x++) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
      int neighbors = countNeighbors(x, y);

      // aturan Game
      if (currentGrid[x][y] == 1) {
        // sel hidup: tetap hidup jika memiliki 2 atau 3 tetangga
        nextGrid[x][y] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
      } else {
        // sel mati: menjadi hidup jika memiliki tepat 3 tetangga
        nextGrid[x][y] = (neighbors == 3) ? 1 : 0;
      }
    }
  }

  // salin nextGrid ke currentGrid untuk iterasi berikutnya
  for (int x = 0; x < GRID_WIDTH; x++) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
      currentGrid[x][y] = nextGrid[x][y];
    }
  }
}

void drawGrid() {
  for (int x = 0; x < GRID_WIDTH; x++) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
      Color color = currentGrid[x][y] ? RED : RAYWHITE;
      DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
    }
  }

  // gambar grid line
  for (int i = 0; i <= GRID_WIDTH; i++) {
    DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, GRID_HEIGHT * CELL_SIZE,
             LIGHTGRAY);
  }

  for (int i = 0; i <= GRID_HEIGHT; i++) {
    DrawLine(0, i * CELL_SIZE, GRID_WIDTH * CELL_SIZE, i * CELL_SIZE,
             LIGHTGRAY);
  }
}

void randomizeGrid() {
  for (int x = 0; x < GRID_WIDTH; x++) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
      currentGrid[x][y] = GetRandomValue(0, 1);

      if (currentGrid[x][y] == 1) {
        printf("Sel hidup di (%d, %d)\n", x, y);
      }
    }
  }
}

// Fungsi untuk mengosongkan grid
void clearGrid() {
  for (int x = 0; x < GRID_WIDTH; x++) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
      currentGrid[x][y] = 0;
    }
  }
}

int main() {
  InitWindow(GRID_WIDTH * CELL_SIZE, GRID_HEIGHT * CELL_SIZE,
             "Conway's Game of Life");
  SetTargetFPS(60);

  int paused = 0;

  // acak grid awal
  randomizeGrid();

  while (!WindowShouldClose()) {

    if (IsKeyPressed(KEY_SPACE)) {
      paused = !paused;
    }

    if (IsKeyPressed(KEY_R)) {
      printf("button worthint\n");
      randomizeGrid();
    }

    if (IsKeyPressed(KEY_C)) {
      clearGrid();
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      // tambahkan sel hidup dengan mengklick mouse kiri
      Vector2 mousePos = GetMousePosition();

      int gridX = (int)(mousePos.x / CELL_SIZE);
      int gridY = (int)(mousePos.y / CELL_SIZE);

      if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 &&
          gridY < GRID_HEIGHT) {
        currentGrid[gridX][gridY] = 1;
      }
    }

    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
      // Hapus sel dengan klik kanan
      Vector2 mousePos = GetMousePosition();
      int gridX = mousePos.x / CELL_SIZE;
      int gridY = mousePos.y / CELL_SIZE;

      if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 &&
          gridY < GRID_HEIGHT) {
        currentGrid[gridX][gridY] = 0;
      }
    }

    if (!paused) {
      updateGrid();
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGrid();

    DrawText("R: Randomize | C: Clear | Click: Add/Remove cells", 10,
             GRID_HEIGHT * CELL_SIZE - 25, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
