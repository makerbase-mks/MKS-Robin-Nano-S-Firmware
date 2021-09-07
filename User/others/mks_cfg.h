#ifndef _MKS_CFG_H_
#define _MKS_CFG_H_

#include "stdint.h"


#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

typedef struct
{
	volatile int8_t custom_pic_flag;
	
	volatile int32_t background_color; //鑳屾櫙棰滆壊
	volatile int32_t title_color; //鏍囬棰滆壊
	volatile int32_t state_background_color; //鐘舵�佹樉绀鸿儗鏅鑹?
	volatile int32_t state_text_color; //鐘舵�佹樉绀烘枃瀛楅鑹查鑹?
	volatile int32_t filename_color; //鏂囦欢鍚嶆枃瀛楅鑹?
	volatile int32_t filename_background_color; //鏂囦欢鍚嶈儗鏅鑹?
	volatile int32_t printingstate_word_background_color;
	volatile int32_t printingstate_word_color;
	volatile int32_t btn_color;

	volatile float curPos[3];
	volatile float curSprayerTemp[2];	// 2个喷头温度
	volatile float curBedTemp;	//热床温度
	volatile float desireSprayerTemp[2];// 2个喷头目标温度
	volatile float desireBedTemp;// 热床目标温度

	volatile float preheat_desireSprayerTemp[2];// 2个喷头目标温度
	volatile float preheat_desireBedTemp;// 热床目标温度


	volatile int8_t curSprayerChoose;	//当前选择的喷头
	volatile int8_t curTempType;		//喷头1、喷头2、热床
	volatile int8_t stepHeat;	//?¤èè2???
	volatile int8_t fanOnoff; //风扇开关
	volatile uint8_t fanSpeed;	//风扇速度
	volatile int8_t sprayerNum; // 喷头数
	volatile int8_t machineType; //机型
	volatile uint16_t printSpeed;		//打印速度
	volatile uint16_t printExtSpeed0;		//打印期间挤出速度
	volatile uint16_t printExtSpeed1;		//打印期间挤出速度
	volatile uint8_t stepPrintSpeed;	//打印速度调整步进
	volatile int8_t extruStep;	//?·3??ù?è
	volatile int8_t extruSpeed;	//挤出速度
	volatile int16_t moveSpeed;	//移动速度
	volatile float move_dist;		//移动距离
	volatile int8_t language;	//语言
	volatile int8_t baud;		//波特率
	
	volatile int8_t fileSysType; //文件系统类型
	volatile uint8_t touch_adj_flag; //触摸屏校正标志位
	volatile int32_t touch_adj_xMin;
	volatile int32_t touch_adj_xMax;
	volatile int32_t touch_adj_yMin;
	volatile int32_t touch_adj_yMax;

	volatile uint8_t button_3d_effect_flag;
	volatile uint8_t have_ups;
	
	volatile int16_t	pause_xpos;
	volatile int16_t pause_ypos;
	volatile int16_t pause_zpos;

	volatile uint8_t MoreItem_pic_cnt;

	volatile uint8_t func_btn1_display_flag;
	volatile uint8_t func_btn2_display_flag;
	volatile uint8_t func_btn3_display_flag;

	volatile uint8_t extern_chinese_flg;//外部字库。

	volatile uint8_t print_finish_close_machine_flg;	

	volatile uint32_t filamentchange_speed;//换料速度
	volatile uint8_t filamentchange_step;//换料步进	
	volatile uint32_t filament_limit_temper;
	
	volatile uint8_t morefunc_cnt;

	volatile uint8_t leveling_mode;//调平模式0:手动调平，1:自动调平
	volatile uint8_t leveling_point_number;//手动调平设置坐标数(可设3/4/5三个值)
	
	volatile int32_t leveling_point1_x;
	volatile int32_t leveling_point1_y;
	volatile int32_t leveling_point2_x;
	volatile int32_t leveling_point2_y;
	volatile int32_t leveling_point3_x;
	volatile int32_t leveling_point3_y;
	volatile int32_t leveling_point4_x;
	volatile int32_t leveling_point4_y;
	volatile int32_t leveling_point5_x;
	volatile int32_t leveling_point5_y;		
	
	volatile int32_t leveling_z_speed;
	volatile int32_t leveling_xy_speed;

	//tan 
	volatile uint8_t temperature_ctrl_err;

} CFG_ITMES;


extern CFG_ITMES gCfgItems;

typedef struct
{
	volatile uint32_t cfg_baudrate;
	volatile uint8_t  cfg_drive_system;
	volatile uint8_t  cfg_ext0_tempsensor_type;
	volatile uint8_t  cfg_ext1_tempsensor_type;
	volatile uint8_t  cfg_heated_bed_sensor_type;

	volatile float cfg_axis_steps_per_mm;
	volatile float cfg_xaxis_steps_per_mm;
	volatile float cfg_yaxis_steps_per_mm;
	volatile float cfg_zaxis_steps_per_mm;
	volatile float cfg_ext0_steps_per_mm;
	volatile float cfg_ext1_steps_per_mm;

	volatile float cfg_max_feedrate_x;
	volatile float cfg_max_feedrate_y;
	volatile float cfg_max_feedrate_z;
	volatile float cfg_max_feedrate_e0;
	volatile float cfg_max_feedrate_e1;
	
	volatile float cfg_max_acceleration_units_per_sq_second_x;
	volatile float cfg_max_acceleration_units_per_sq_second_y;
	volatile float cfg_max_acceleration_units_per_sq_second_z;
	volatile float cfg_max_acceleration_e0;
	volatile float cfg_max_acceleration_e1;

	volatile float cfg_max_travel_acceleration_units_per_sq_second_x;
	volatile float cfg_max_travel_acceleration_units_per_sq_second_y;
	volatile float cfg_max_travel_acceleration_units_per_sq_second_z;

	volatile float cfg_homing_feedrate_x;
	volatile float cfg_homing_feedrate_y;
	volatile float cfg_homing_feedrate_z;
	
	volatile float cfg_ext_mintemp;	
	volatile float cfg_ext_maxtemp;
	volatile float cfg_heated_bed_maxtemp;
	
	volatile float cfg_ui_set_maxtemp;
	volatile float cfg_ui_set_heated_bed_maxtemp;

	volatile int8_t cfg_num_extruder;
	volatile int8_t cfg_have_heated_bed;

	volatile int8_t cfg_invert_x_dir;
	volatile int8_t cfg_invert_y_dir;
	volatile int8_t cfg_invert_z_dir;
	volatile int8_t cfg_invert_e0_dir;
	volatile int8_t cfg_invert_e1_dir;

	volatile int8_t cfg_homing_order;
	volatile int8_t cfg_x_home_dir;
	volatile int8_t cfg_y_home_dir;
	volatile int8_t cfg_z_home_dir;
				
	volatile float	cfg_x_max_length;
	volatile float	cfg_y_max_length;
	volatile float	cfg_z_max_length;
	volatile float	cfg_x_min_pos;
	volatile float	cfg_y_min_pos;
	volatile float	cfg_z_min_pos;	

	volatile uint8_t cfg_endstop_x_min_inverting;
	volatile uint8_t cfg_endstop_y_min_inverting;
	volatile uint8_t cfg_endstop_z_min_inverting;
	volatile uint8_t cfg_endstop_x_max_inverting;
	volatile uint8_t cfg_endstop_y_max_inverting;
	volatile uint8_t cfg_endstop_z_max_inverting;

	volatile uint8_t cfg_min_hardware_endstop_x;
	volatile uint8_t cfg_min_hardware_endstop_y;
	volatile uint8_t cfg_min_hardware_endstop_z;
	volatile uint8_t cfg_max_hardware_endstop_x;
	volatile uint8_t cfg_max_hardware_endstop_y;
	volatile uint8_t cfg_max_hardware_endstop_z;

	volatile uint8_t cfg_min_software_endstop_x;
	volatile uint8_t cfg_min_software_endstop_y;
	volatile uint8_t cfg_min_software_endstop_z;
	volatile uint8_t cfg_max_software_endstop_x;
	volatile uint8_t cfg_max_software_endstop_y;
	volatile uint8_t cfg_max_software_endstop_z;

	volatile float cfg_delta_max_radius;
	volatile float cfg_printer_radius;
	volatile float cfg_delta_diagonal_rod;
	volatile float cfg_delta_floor_safety_margin_mm;
	
	volatile uint8_t cfg_feature_z_probe;
	volatile uint8_t cfg_bed_leveling_method;
	volatile float cfg_z_probe_height;
	volatile float cfg_z_probe_x1;
	volatile float cfg_z_probe_y1;
	volatile float cfg_z_probe_x2;
	volatile float cfg_z_probe_y2;
	volatile float cfg_z_probe_x3;
	volatile float cfg_z_probe_y3;
	volatile float cfg_end_effector_horizontal_offset;
	volatile float cfg_carriage_horizontal_offset;
	volatile float cfg_rod_radius;
	volatile float cfg_bed_leveling_grid_size;
	volatile float cfg_z_probe_speed;
	volatile float cfg_z_probe_xy_speed;

	volatile uint32_t cfg_stepper_high_delay;
	volatile uint8_t cfg_print_auto_close;

	volatile uint8_t cfg_x_enable_on;
	volatile uint8_t cfg_y_enable_on;
	volatile uint8_t cfg_z_enable_on;
	volatile uint8_t cfg_e0_enable_on;
	volatile uint8_t cfg_e1_enable_on;
}CFG_PRINTER_ITMES;

extern CFG_PRINTER_ITMES CfgPrinterItems;

typedef struct 
{
	volatile uint8_t def_ENDSTOP_X_MIN_INVERTING;
	volatile uint8_t def_ENDSTOP_Y_MIN_INVERTING;
	volatile uint8_t def_ENDSTOP_Z_MIN_INVERTING;
	volatile uint8_t def_ENDSTOP_X_MAX_INVERTING;
	volatile uint8_t def_ENDSTOP_Y_MAX_INVERTING;
	volatile uint8_t def_ENDSTOP_Z_MAX_INVERTING;

	volatile uint8_t def_MIN_HARDWARE_ENDSTOP_X;
	volatile uint8_t def_MIN_HARDWARE_ENDSTOP_Y;
	volatile uint8_t def_MIN_HARDWARE_ENDSTOP_Z;
	volatile uint8_t def_MAX_HARDWARE_ENDSTOP_X;
	volatile uint8_t def_MAX_HARDWARE_ENDSTOP_Y;
	volatile uint8_t def_MAX_HARDWARE_ENDSTOP_Z;

	volatile uint8_t def_min_software_endstop_x;
	volatile uint8_t def_min_software_endstop_y;
	volatile uint8_t def_min_software_endstop_z;
	volatile uint8_t def_max_software_endstop_x;
	volatile uint8_t def_max_software_endstop_y;
	volatile uint8_t def_max_software_endstop_z;	

	volatile uint8_t def_SUPPORT_MAX6675;
	volatile uint8_t def_SUPPORT_MAX31855;


	volatile uint8_t def_ANALOG_INPUTS;
	volatile uint8_t def_EXT0_ANALOG_INPUTS;
	volatile uint8_t def_EXT0_SENSOR_INDEX;
	volatile uint8_t def_EXT0_ANALOG_CHANNEL;
	
	volatile uint8_t def_EXT1_ANALOG_INPUTS;
	volatile uint8_t def_EXT1_SENSOR_INDEX;
	volatile uint8_t def_EXT1_ANALOG_CHANNEL;
	
	volatile uint8_t def_EXT2_ANALOG_INPUTS;
	volatile uint8_t def_EXT2_SENSOR_INDEX;
	volatile uint8_t def_EXT2_ANALOG_CHANNEL;
	
	volatile uint8_t def_EXT3_ANALOG_INPUTS;
	volatile uint8_t def_EXT3_SENSOR_INDEX;
	volatile uint8_t def_EXT3_ANALOG_CHANNEL;
	
	volatile uint8_t def_EXT4_ANALOG_INPUTS;
	volatile uint8_t def_EXT4_SENSOR_INDEX;
	volatile uint8_t def_EXT4_ANALOG_CHANNEL;
	
	volatile uint8_t def_EXT5_ANALOG_INPUTS;
	volatile uint8_t def_EXT5_SENSOR_INDEX;
	volatile uint8_t def_EXT5_ANALOG_CHANNEL;	
	
	volatile uint8_t def_BED_ANALOG_INPUTS;
	volatile uint8_t def_BED_SENSOR_INDEX;
	volatile uint8_t def_BED_ANALOG_CHANNEL;
	
	volatile uint8_t def_THERMO_ANALOG_INDEX;
	volatile uint8_t def_THERMO_ANALOG_INPUTS;
	volatile uint8_t def_THERMO_ANALOG_CHANNEL;
	
	volatile uint8_t def_KEYPAD_ANALOG_INPUTS;
	volatile uint8_t def_KEYPAD_ANALOG_INDEX;
	volatile uint8_t def_KEYPAD_ANALOG_CHANNEL;

	volatile uint8_t def_PWM_BOARD_FAN;
	volatile uint8_t def_PWM_FAN1;
	volatile uint8_t def_PWM_FAN2;
	volatile uint8_t def_PWM_FAN_THERMO;

	volatile uint8_t def_NUM_TEMPERATURE_LOOPS;

	
	volatile float def_DELTA_DIAGONAL_ROD;
	volatile float	def_DELTA_ALPHA_A;
	volatile float	def_DELTA_ALPHA_B;
	volatile float	def_DELTA_ALPHA_C;
	volatile float	def_DELTA_RADIUS_CORRECTION_A;
	volatile float	def_DELTA_RADIUS_CORRECTION_B;
	volatile float	def_DELTA_RADIUS_CORRECTION_C;
	volatile float	def_DELTA_DIAGONAL_CORRECTION_A;
	volatile float	def_DELTA_DIAGONAL_CORRECTION_B;
	volatile float	def_DELTA_DIAGONAL_CORRECTION_C;
	volatile float	def_DELTA_MAX_RADIUS;
	volatile float	def_DELTA_FLOOR_SAFETY_MARGIN_MM;
	volatile float	def_END_EFFECTOR_HORIZONTAL_OFFSET;
	volatile float	def_CARRIAGE_HORIZONTAL_OFFSET;
	volatile float	def_PRINTER_RADIUS;
	volatile float	def_DELTA_HOME_ON_POWER;
	volatile float	def_DELTA_X_ENDSTOP_OFFSET_STEPS;
	volatile float	def_DELTA_Y_ENDSTOP_OFFSET_STEPS;
	volatile float	def_DELTA_Z_ENDSTOP_OFFSET_STEPS;

	volatile uint8_t def_NONLINEAR_SYSTEM;

	volatile float def_ENDSTOP_X_BACK_MOVE;
	volatile float def_ENDSTOP_Y_BACK_MOVE;
	volatile float def_ENDSTOP_Z_BACK_MOVE;
	volatile float def_ENDSTOP_X_BACK_ON_HOME;
	volatile float def_ENDSTOP_Y_BACK_ON_HOME;
	volatile float def_ENDSTOP_Z_BACK_ON_HOME;
	
}PRINTER_DEFINE;

extern PRINTER_DEFINE Change_Repetier_Define;

extern void cfg_init();
extern void define_value_init();

#if defined(__cplusplus)
}
#endif

#endif

