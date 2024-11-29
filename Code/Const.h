#pragma once
const int ROWS = 20;
const int COLUMNS = 10;
const float WINDOW_HEIGHT = 800.f;
const float WINDOW_WIDTH = 1000.f;
const float START_DELAY = 0.6f;
const float CELL_SIZE = 2.f * 18; // * 18 'cause one cube from tiles.png have 18.f px size
const float START_Y = (WINDOW_HEIGHT - CELL_SIZE * ROWS) / 2.f;
const float START_X = START_Y;