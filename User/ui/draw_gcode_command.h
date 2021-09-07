#ifndef _DRAW_GCODE_COMMAND_H_
#define _DRAW_GCODE_COMMAND_H_

//#include "gui.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif
extern void draw_gcodeCommand();
extern void Clear_gcodeCommand();

//extern float key_set_value;
//extern char key_value[11];
/*
typedef struct print_value_option
{
    uint32_t BottomLayer;
    float ExposureOff;
    float BottomExposure;
    float NormalExposure;
}value_option;

extern value_option  para_value;
typedef enum
{
    BottomLayer_edit,
    ExpoOff_edit,
    BottomExpo_edit,
    NormalExpo_edit,
    DetectionExpo_edit
}para_edit;

extern para_edit text_edit; 

#define PLA_EXT_TEMP 0
#define PLA_BED_TEMP 1
#define ABS_EXT_TEMP 2
#define ABS_BED_TEMP 3
#define PRE_HEAT_EXT_TEMP 4
#define PRE_HEAT_BED_TEMP 5

#define SET_FAN_SPEED 6
#define SET_MOVE_SPEED 7
#define SET_EXTRUDE_SPEED 8
*/

#if defined(__cplusplus)
}    /* Make sure we have C-declarations in C++ programs */
#endif
#endif
