#pragma once
const int ROWS = 20;
const int COLUMNS = 10;
const float WINDOW_HEIGHT = 800.f;
const float WINDOW_WIDTH = 1000.f;
const float CELL_SIZE = 2.f * 18; // * 18 'cause one cube from tiles.png have 18.f px size
const float START_Y = (WINDOW_HEIGHT - CELL_SIZE * ROWS) / 2.f;
const float START_X = START_Y;
const float START_TEXT_POS_X = 2 * START_X + CELL_SIZE * COLUMNS;
const float START_TEXT_POS_Y = START_Y;