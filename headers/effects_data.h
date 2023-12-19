#ifndef EFFECTS_DATA_H
#define EFFECTS_DATA_H

#define WACOM   0
#define TOUCH   1

//[DOCTYPE]
#define NOTEBOOK 0
#define PDF      1

enum effects {
  NULL_EFFECT,              // Null effect
  TOOLBAR,                  // action: toolbar
  WRITING,                  // action: writing
  TEXT,                     // action: text button
  ERASER_PANEL,             // tap on eraser panel, not useful on it's own
  SELECT,                   // action: select
  UNDO,                     // action: undo button
  REDO,                     // action: redo button
  ERASER_ERASE,             // action: eraser
  ERASER_SELECTION,         // action: eraser-selection
  ERASER_ERASE_ALL,         // action: eraser-eraser-all
  WRITING_FINELINER,        // action: writing-fineliner
  WRITING_CALLIGRAPHY,      // action: writing-calligraphy
  WRITING_BLACK,            // action: writing-black
  WRITING_GREY,             // action: writing-grey
  WRITING_HL,               // action: writing-hl
  NUM_EFFECTS,              // Total number of effects
};

// extra effects that do not exactly correspond to a screen position
#define ONE_OFF_ERASER_SELECTION (NUM_EFFECTS + 0) // action: one-off-eraser-selection
#define ONE_OFF_HL (NUM_EFFECTS + 1) // action: one-off-hl-selection

#define NUM_EXTRA_EFFECTS 2 // remember to update this if adding new effects above!

// internal effects
#define PEN_UP_EFFECT        (NUM_EFFECTS + NUM_EXTRA_EFFECTS + 0)

//define offsets for the effect functions
#define HOLD_OFF_OFFSET      0x0ff
#define TOGGLE_OFFSET        0xfff

//effects that require a deactivate/toggle function
#define ERASER_ERASE_OFF     (ERASER_ERASE     + HOLD_OFF_OFFSET)
#define ERASER_SELECTION_OFF (ERASER_SELECTION + HOLD_OFF_OFFSET)
#define SELECT_OFF           (SELECT           + HOLD_OFF_OFFSET)

#define ERASER_ERASE_TOGGLE  (ERASER_ERASE     + TOGGLE_OFFSET)
#define ERASER_SELECT_TOGGLE (ERASER_SELECTION + TOGGLE_OFFSET)
#define SELECT_TOGGLE        (SELECT           + TOGGLE_OFFSET)
#define HL_TOGGLE            (WRITING_HL       + TOGGLE_OFFSET)

#define NUM_TOTAL_EFFECTS NUM_EFFECTS + NUM_EXTRA_EFFECTS

//recognized words in config file
static const char* EFFECTS[NUM_TOTAL_EFFECTS] = {
  "null-effect",              //null effect               0
  "toolbar",                  //TOOLBAR                   1
  "writing",                  //WRITING                   2
  "text",                     //TEXT                      3
  "eraser-panel",             //ERASER                    4
  "select",                   //SELECT                    5
  "undo",                     //UNDO                      6
  "redo",                     //REDO                      7
  "eraser-erase",             //ERASER_ERASE              8
  "eraser-selection",         //ERASER_SELECT             9
  "eraser-erase-all",         //ERASER_ERASE_ALL         10
  "writing-fineliner",        //WRITING_FINELINER        11
  "writing-calligraphy",      //WRITING_CALLIGRAPHY      12
  "writing-black",            //WRITING_BLACK            13
  "writing-grey",             //WRITING_GREY             14
  "writing-hl",               //WRITING_HL               15
  "one-off-eraser-selection", //ONE_OFF_ERASER_SELECTION 16
  "one-off-hl",               //ONE_OFF_HL               17
};

#define T_RM2_RHX 60  // Define RM2 toolbar column touchscreen location
#define T_RM2_RHY 50
#define T_RM2_LHX 1360
#define T_RM2_LHY 1820

static const int LOCATION_LOOKUP_TOUCH[2][NUM_EFFECTS][4][2] = {
  {//NOTEBOOK
   // RHP                RHL                LHP                LHL
    { {        0,    0}, {   0,         0}, {        0,    0}, {   0,         0} }, //NULL_EFFECT          0
    { {T_RM2_RHX, 1850}, {  60, T_RM2_RHY}, {T_RM2_LHX, 1810}, {  80, T_RM2_LHY} }, //TOOLBAR              1
    { {T_RM2_RHX, 1720}, { 150, T_RM2_RHY}, {T_RM2_LHX, 1700}, { 160, T_RM2_LHY} }, //WRITING              2
    { {T_RM2_RHX, 1620}, { 240, T_RM2_RHY}, {T_RM2_LHX, 1600}, { 270, T_RM2_LHY} }, //TEXT                 3
    { {T_RM2_RHX, 1510}, { 350, T_RM2_RHY}, {T_RM2_LHX, 1510}, { 360, T_RM2_LHY} }, //ERASER_PANEL         4
    { {T_RM2_RHX, 1410}, { 470, T_RM2_RHY}, {T_RM2_LHX, 1410}, { 440, T_RM2_LHY} }, //SELECT               5
    { {T_RM2_RHX, 1300}, { 560, T_RM2_RHY}, {T_RM2_LHX, 1300}, { 550, T_RM2_LHY} }, //UNDO                 6
    { {T_RM2_RHX, 1190}, { 650, T_RM2_RHY}, {T_RM2_LHX, 1190}, { 670, T_RM2_LHY} }, //REDO                 7
    { {      180, 1440}, { 420,       160}, {     1000, 1440}, { 430,      1450} }, //ERASER_ERASE         8
    { {      250, 1580}, { 430,       300}, {     1140, 1440}, { 430,      1580} }, //ERASER_SELECTION     9
    { {      200, 1280}, { 560,       160}, {     1050, 1280}, { 670,      1480} }, //ERASER_ERASE_ALL    10
    { {      300, 1630}, { 230,       280}, {     1010, 1640}, { 230,      1480} }, //WRITING_FINELINER   11
    { {      520, 1540}, { 330,       490}, {     1220, 1530}, { 330,      1680} }, //WRITING_CALLIGRAPHY 12
    { {      200, 1150}, { 720,       180}, {      900, 1120}, { 730,      1380} }, //WRITING_BLACK       13
    { {      300, 1150}, { 720,       280}, {     1020, 1140}, { 730,      1480} }, //WRITING_GREY        14
    { {      190, 1540}, { 330,       170}, {      900, 1530}, { 330,      1370} }, //WRITING_HL          15
  },
  {//PDF
   // RHP                RHL                LHP                LHL
    { {        0,    0}, {   0,         0}, {        0,    0}, {   0,         0} }, //NULL_EFFECT          0
    { {T_RM2_RHX, 1850}, {  60, T_RM2_RHY}, {T_RM2_LHX, 1810}, {  80, T_RM2_LHY} }, //TOOLBAR              1
    { {T_RM2_RHX, 1720}, { 150, T_RM2_RHY}, {T_RM2_LHX, 1700}, { 160, T_RM2_LHY} }, //WRITING              2
    { {        0,    0}, {   0,         0}, {        0,    0}, {   0,         0} }, //TEXT                 3
    { {T_RM2_RHX, 1620}, { 240, T_RM2_RHY}, {T_RM2_LHX, 1600}, { 270, T_RM2_LHY} }, //ERASER_PANEL         4
    { {T_RM2_RHX, 1510}, { 350, T_RM2_RHY}, {T_RM2_LHX, 1510}, { 360, T_RM2_LHY} }, //SELECT               5
    { {T_RM2_RHX, 1410}, { 470, T_RM2_RHY}, {T_RM2_LHX, 1410}, { 470, T_RM2_LHY} }, //UNDO                 6
    { {T_RM2_RHX, 1300}, { 560, T_RM2_RHY}, {T_RM2_LHX, 1300}, { 580, T_RM2_LHY} }, //REDO                 7
    { {      180, 1550}, { 300,       160}, {     1000, 1530}, { 340,      1450} }, //ERASER_ERASE         8
    { {      250, 1580}, { 300,       300}, {     1140, 1530}, { 340,      1580} }, //ERASER_SELECTION     9
    { {      200, 1400}, { 470,       160}, {     1050, 1400}, { 580,      1480} }, //ERASER_ERASE_ALL    10
    { {      300, 1630}, { 230,       280}, {     1010, 1640}, { 230,      1480} }, //WRITING_FINELINER   11
    { {      520, 1540}, { 330,       490}, {     1220, 1530}, { 330,      1680} }, //WRITING_CALLIGRAPHY 12
    { {      200, 1150}, { 720,       180}, {      900, 1120}, { 730,      1380} }, //WRITING_BLACK       13
    { {      300, 1150}, { 720,       280}, {     1020, 1140}, { 730,      1480} }, //WRITING_GREY        14
    { {      200, 1510}, { 330,       170}, {      900, 1530}, { 330,      1370} }, //WRITING_HL          15
  }
};

#endif //EFFECTS_DATA_H
