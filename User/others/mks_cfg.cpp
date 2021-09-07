#include "mks_cfg.h"
#include "draw_ui.h"
#include "Extruder.h"
#include "Repetier.h"
#include "HAL.h"
#include "pic_manager.h"
#include "spi_flash.h"

CFG_ITMES gCfgItems;

CFG_PRINTER_ITMES CfgPrinterItems;

PRINTER_DEFINE Change_Repetier_Define;

#define  BAK_INF_VALID_FLAG			0x76313032//acsii --> V104   //0xaa558761

volatile u32 ugbksize;//flash中Unicode转GBK转换表大小值。

void recover_cfg_inf()
{
	volatile uint32_t  valid_flag;
	valid_flag = HAL::eprGetInt32(EPR_VALID_FLAG_CFG); 
	if(valid_flag == BAK_INF_VALID_FLAG)
	{
		gCfgItems.background_color = HAL::eprGetInt32(EPR_BACKGROUND_COLOR_CFG);
		gCfgItems.title_color = HAL::eprGetInt32(EPR_TITLE_COLOR_CFG);	
		gCfgItems.state_background_color = HAL::eprGetInt32(EPR_STATE_BACKGROUND_COLOR_CFG);
		gCfgItems.state_text_color = HAL::eprGetInt32(EPR_STATE_TEXT_COLOR_CFG);
		gCfgItems.filename_background_color = HAL::eprGetInt32(EPR_FILENAME_BACKGROUND_COLOE_CFG);
		gCfgItems.filename_color = HAL::eprGetInt32(EPR_FILENAME_COLOR_CFG);
		gCfgItems.printingstate_word_background_color = HAL::eprGetInt32(EPR_PRINTINGSTATE_TEXT_BACKGROUND_COLOR_CFG);
		gCfgItems.printingstate_word_color = HAL::eprGetInt32(EPR_PRINTINGSTATE_TEXT_COLOR_CFG);
		gCfgItems.button_3d_effect_flag = HAL::eprGetInt32(EPR_BUTTON_3D_EFFECTS_CFG);
		gCfgItems.language = HAL::eprGetInt32(EPR_LANGUAGE_TYPE_CFG);
        //gCfgItems.have_ups = HAL::eprGetByte(EPR_HAVE_UPS_CFG);
		CfgPrinterItems.cfg_ui_set_maxtemp = HAL::eprGetFloat(EPR_UI_SET_MAX_TEMPERATURE_CFG);
		CfgPrinterItems.cfg_ui_set_heated_bed_maxtemp = HAL::eprGetFloat(EPR_UI_SET_HEAT_BED_TEMPERATURE_CFG);
		gCfgItems.MoreItem_pic_cnt = HAL::eprGetByte(EPR_MOREITEM_PIC_CNT_CFG);	
		gCfgItems.func_btn1_display_flag = HAL::eprGetByte(EPR_SETMENU_FUNC1_DISPLAY_FLAG_CFG);
		gCfgItems.func_btn2_display_flag = HAL::eprGetByte(EPR_SETMENU_FUNC2_DISPLAY_FLAG_CFG);

		CfgPrinterItems.cfg_drive_system = HAL::eprGetByte(EPR_DRIVE_SYSTEM_CFG);
		CfgPrinterItems.cfg_ext0_tempsensor_type = HAL::eprGetByte(EPR_EXT0_TEMPSENSOR_TYPE_CFG);
		CfgPrinterItems.cfg_ext1_tempsensor_type = HAL::eprGetByte(EPR_EXT1_TEMPSENSOR_TYPE_CFG);
		CfgPrinterItems.cfg_heated_bed_sensor_type = HAL::eprGetByte(EPR_HEATED_BED_SENSOR_TYPE_CFG);
		CfgPrinterItems.cfg_delta_max_radius = HAL::eprGetFloat(EPR_DELTA_MAX_RADIUS_CFG);
		CfgPrinterItems.cfg_printer_radius = HAL::eprGetFloat(EPR_PRINTER_RADIUS_CFG);
		CfgPrinterItems.cfg_delta_diagonal_rod = HAL::eprGetFloat(EPR_DELTA_DIAGONAL_ROD_CFG);
		CfgPrinterItems.cfg_delta_floor_safety_margin_mm = HAL::eprGetFloat(EPR_DELTA_FLOOR_SAFETY_MARGIN_MM_CFG);
		CfgPrinterItems.cfg_feature_z_probe = HAL::eprGetByte(EPR_FEATURE_Z_PROBE_CFG);
		CfgPrinterItems.cfg_bed_leveling_method = HAL::eprGetByte(EPR_BED_LEVELING_METHOD_CFG);
		CfgPrinterItems.cfg_z_probe_height = HAL::eprGetFloat(EPR_Z_PROBE_HEIGHT_CFG);
		CfgPrinterItems.cfg_z_probe_x1 = HAL::eprGetFloat(EPR_Z_PROBE_X1_CFG);
		CfgPrinterItems.cfg_z_probe_y1 = HAL::eprGetFloat(EPR_Z_PROBE_Y1_CFG);
		CfgPrinterItems.cfg_z_probe_x2 = HAL::eprGetFloat(EPR_Z_PROBE_X2_CFG);
		CfgPrinterItems.cfg_z_probe_y2 = HAL::eprGetFloat(EPR_Z_PROBE_Y2_CFG);
		CfgPrinterItems.cfg_z_probe_x3 = HAL::eprGetFloat(EPR_Z_PROBE_X3_CFG);
		CfgPrinterItems.cfg_z_probe_y3 = HAL::eprGetFloat(EPR_Z_PROBE_Y3_CFG);
		CfgPrinterItems.cfg_xaxis_steps_per_mm = HAL::eprGetFloat(EPR_XAXIS_STEPS_PER_MM_CFG);
		CfgPrinterItems.cfg_yaxis_steps_per_mm = HAL::eprGetFloat(EPR_YAXIS_STEPS_PER_MM_CFG);
		CfgPrinterItems.cfg_zaxis_steps_per_mm = HAL::eprGetFloat(EPR_ZAXIS_STEPS_PER_MM_CFG);
		CfgPrinterItems.cfg_ext0_steps_per_mm = HAL::eprGetFloat(EPR_EXT0_STEPS_PER_MM_CFG);
		CfgPrinterItems.cfg_max_feedrate_x = HAL::eprGetFloat(EPR_MAX_FEEDRATE_X_CFG);
		CfgPrinterItems.cfg_max_feedrate_y = HAL::eprGetFloat(EPR_MAX_FEEDRATE_Y_CFG);
		CfgPrinterItems.cfg_max_feedrate_z = HAL::eprGetFloat(EPR_MAX_FEEDRATE_Z_CFG);
		CfgPrinterItems.cfg_max_feedrate_e0 = HAL::eprGetFloat(EPR_MAX_FEEDRATE_EXT0_CFG);
		CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_x = HAL::eprGetFloat(EPR_MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X_CFG);
		CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_y = HAL::eprGetFloat(EPR_MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y_CFG);
		CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_z = HAL::eprGetFloat(EPR_MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z_CFG);
		CfgPrinterItems.cfg_max_acceleration_e0 = HAL::eprGetFloat(EPR_MAX_ACCELERATION_EXT0_CFG);
		CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_x = HAL::eprGetFloat(EPR_MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X_CFG);
		CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_y = HAL::eprGetFloat(EPR_MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y_CFG);
		CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_z = HAL::eprGetFloat(EPR_MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z_CFG);
		CfgPrinterItems.cfg_homing_feedrate_x = HAL::eprGetFloat(EPR_HOMING_FEEDRATE_X_CFG);
		CfgPrinterItems.cfg_homing_feedrate_y = HAL::eprGetFloat(EPR_HOMING_FEEDRATE_Y_CFG);
		CfgPrinterItems.cfg_homing_feedrate_z = HAL::eprGetFloat(EPR_HOMING_FEEDRATE_Z_CFG);
		CfgPrinterItems.cfg_ext_mintemp = HAL::eprGetFloat(EPR_MIN_EXTRUDER_TEMP_CFG);
		CfgPrinterItems.cfg_ext_maxtemp = HAL::eprGetFloat(EPR_MAX_EXTRUDER_TEMP_CFG);
		CfgPrinterItems.cfg_heated_bed_maxtemp = HAL::eprGetFloat(EPR_MAX_HEATED_BED_TEMP_CFG);
		CfgPrinterItems.cfg_num_extruder = HAL::eprGetByte(EPR_NUM_EXTRUDER_CFG);
		CfgPrinterItems.cfg_have_heated_bed = HAL::eprGetByte(EPR_HAVE_HEATED_BED_CFG);
		CfgPrinterItems.cfg_invert_x_dir = HAL::eprGetByte(EPR_INVERT_X_DIR_CFG);
		CfgPrinterItems.cfg_invert_y_dir = HAL::eprGetByte(EPR_INVERT_Y_DIR_CFG);
		CfgPrinterItems.cfg_invert_z_dir = HAL::eprGetByte(EPR_INVERT_Z_DIR_CFG);
		CfgPrinterItems.cfg_invert_e0_dir = HAL::eprGetByte(EPR_EXT0_INVERSE_CFG);
		CfgPrinterItems.cfg_x_home_dir = HAL::eprGetByte(EPR_X_HOME_DIR_CFG);
		CfgPrinterItems.cfg_y_home_dir = HAL::eprGetByte(EPR_Y_HOME_DIR_CFG);
		CfgPrinterItems.cfg_z_home_dir = HAL::eprGetByte(EPR_Z_HOME_DIR_CFG);
		CfgPrinterItems.cfg_x_max_length = HAL::eprGetFloat(EPR_X_MAX_LENGTH_CFG);
		CfgPrinterItems.cfg_y_max_length = HAL::eprGetFloat(EPR_Y_MAX_LENGTH_CFG);
		CfgPrinterItems.cfg_z_max_length = HAL::eprGetFloat(EPR_Z_MAX_LENGTH_CFG);
		CfgPrinterItems.cfg_x_min_pos = HAL::eprGetFloat(EPR_X_MIN_POS_CFG);
		CfgPrinterItems.cfg_y_min_pos = HAL::eprGetFloat(EPR_Y_MIN_POS_CFG);
		CfgPrinterItems.cfg_z_min_pos = HAL::eprGetFloat(EPR_Z_MIN_POS_CFG);
		CfgPrinterItems.cfg_endstop_x_min_inverting = HAL::eprGetByte(EPR_ENDSTOP_X_MIN_INVERTING_CFG);
		CfgPrinterItems.cfg_endstop_y_min_inverting = HAL::eprGetByte(EPR_ENDSTOP_Y_MIN_INVERTING_CFG);
		CfgPrinterItems.cfg_endstop_z_min_inverting = HAL::eprGetByte(EPR_ENDSTOP_Z_MIN_INVERTING_CFG);
		CfgPrinterItems.cfg_endstop_x_max_inverting = HAL::eprGetByte(EPR_ENDSTOP_X_MAX_INVERTING_CFG);
		CfgPrinterItems.cfg_endstop_y_max_inverting = HAL::eprGetByte(EPR_ENDSTOP_Y_MAX_INVERTING_CFG);
		CfgPrinterItems.cfg_endstop_z_max_inverting = HAL::eprGetByte(EPR_ENDSTOP_Z_MAX_INVERTING_CFG);		
		CfgPrinterItems.cfg_min_hardware_endstop_x = HAL::eprGetByte(EPR_MIN_HARDWARE_ENDSTOP_X_CFG);	
		CfgPrinterItems.cfg_min_hardware_endstop_y = HAL::eprGetByte(EPR_MIN_HARDWARE_ENDSTOP_Y_CFG);	
		CfgPrinterItems.cfg_min_hardware_endstop_z = HAL::eprGetByte(EPR_MIN_HARDWARE_ENDSTOP_Z_CFG);	
		CfgPrinterItems.cfg_max_hardware_endstop_x = HAL::eprGetByte(EPR_MAX_HARDWARE_ENDSTOP_X_CFG);	
		CfgPrinterItems.cfg_max_hardware_endstop_y = HAL::eprGetByte(EPR_MAX_HARDWARE_ENDSTOP_Y_CFG);	
		CfgPrinterItems.cfg_max_hardware_endstop_z = HAL::eprGetByte(EPR_MAX_HARDWARE_ENDSTOP_Z_CFG);	
		CfgPrinterItems.cfg_min_software_endstop_x = HAL::eprGetByte(EPR_MIN_SOFTWARE_ENDSTOP_X_CFG);	
		CfgPrinterItems.cfg_min_software_endstop_y = HAL::eprGetByte(EPR_MIN_SOFTWARE_ENDSTOP_Y_CFG);	
		CfgPrinterItems.cfg_min_software_endstop_z = HAL::eprGetByte(EPR_MIN_SOFTWARE_ENDSTOP_Z_CFG);	
		CfgPrinterItems.cfg_max_software_endstop_x = HAL::eprGetByte(EPR_MAX_SOFTWARE_ENDSTOP_X_CFG);	
		CfgPrinterItems.cfg_max_software_endstop_y = HAL::eprGetByte(EPR_MAX_SOFTWARE_ENDSTOP_Y_CFG);	
		CfgPrinterItems.cfg_max_software_endstop_z = HAL::eprGetByte(EPR_MAX_SOFTWARE_ENDSTOP_Z_CFG);	
		CfgPrinterItems.cfg_end_effector_horizontal_offset = HAL::eprGetFloat(EPR_END_EFFECTOR_HORIZONTAL_OFFSET_CFG);
		CfgPrinterItems.cfg_carriage_horizontal_offset = HAL::eprGetFloat(EPR_CARRIAGE_HORIZONTAL_OFFSET_CFG);
		CfgPrinterItems.cfg_rod_radius = HAL::eprGetFloat(EPR_ROD_RADIUS_CFG);
		CfgPrinterItems.cfg_bed_leveling_grid_size = HAL::eprGetFloat(EPR_BED_LEVELING_GRID_SIZE_CFG);
		CfgPrinterItems.cfg_z_probe_speed = HAL::eprGetFloat(EPR_Z_PROBE_SPEED_CFG);
		CfgPrinterItems.cfg_z_probe_xy_speed = HAL::eprGetFloat(EPR_Z_PROBE_XY_SPEED_CFG);
		CfgPrinterItems.cfg_stepper_high_delay = HAL::eprGetInt32(EPR_STEPPER_HIGH_DELAY_CFG);
	}
	else
	{
		HAL::eprSetInt32(EPR_BACKGROUND_COLOR_CFG, gCfgItems.background_color);
		HAL::eprSetInt32(EPR_TITLE_COLOR_CFG, gCfgItems.title_color);	
		HAL::eprSetInt32(EPR_STATE_BACKGROUND_COLOR_CFG,gCfgItems.state_background_color);
		HAL::eprSetInt32(EPR_STATE_TEXT_COLOR_CFG, gCfgItems.state_text_color);
		HAL::eprSetInt32(EPR_FILENAME_BACKGROUND_COLOE_CFG, gCfgItems.filename_background_color);
		HAL::eprSetInt32(EPR_FILENAME_COLOR_CFG, gCfgItems.filename_color);
		HAL::eprSetInt32(EPR_PRINTINGSTATE_TEXT_BACKGROUND_COLOR_CFG, gCfgItems.printingstate_word_background_color);
		HAL::eprSetInt32(EPR_PRINTINGSTATE_TEXT_COLOR_CFG, gCfgItems.printingstate_word_color);
		HAL::eprSetInt32(EPR_BUTTON_3D_EFFECTS_CFG, gCfgItems.button_3d_effect_flag);
       // HAL::eprSetByte(EPR_HAVE_UPS_CFG,gCfgItems.have_ups);
		HAL::eprSetInt32(EPR_LANGUAGE_TYPE_CFG, gCfgItems.language);
		HAL::eprSetInt32(EPR_UI_SET_MAX_TEMPERATURE_CFG, CfgPrinterItems.cfg_ui_set_maxtemp);
		HAL::eprSetInt32(EPR_UI_SET_HEAT_BED_TEMPERATURE_CFG, CfgPrinterItems.cfg_ui_set_heated_bed_maxtemp);
		HAL::eprSetByte(EPR_MOREITEM_PIC_CNT_CFG,gCfgItems.MoreItem_pic_cnt);	
		HAL::eprSetByte(EPR_SETMENU_FUNC1_DISPLAY_FLAG_CFG,gCfgItems.func_btn1_display_flag);	
		HAL::eprSetByte(EPR_SETMENU_FUNC2_DISPLAY_FLAG_CFG,gCfgItems.func_btn2_display_flag);	

		HAL::eprSetByte(EPR_DRIVE_SYSTEM_CFG, CfgPrinterItems.cfg_drive_system);
		HAL::eprSetByte(EPR_EXT0_TEMPSENSOR_TYPE_CFG,CfgPrinterItems.cfg_ext0_tempsensor_type);
		HAL::eprSetByte(EPR_EXT1_TEMPSENSOR_TYPE_CFG,CfgPrinterItems.cfg_ext1_tempsensor_type);
		HAL::eprSetByte(EPR_HEATED_BED_SENSOR_TYPE_CFG,CfgPrinterItems.cfg_heated_bed_sensor_type);
		HAL::eprSetFloat(EPR_DELTA_MAX_RADIUS_CFG,CfgPrinterItems.cfg_delta_max_radius);
		HAL::eprSetFloat(EPR_PRINTER_RADIUS_CFG,CfgPrinterItems.cfg_printer_radius);
		HAL::eprSetFloat(EPR_DELTA_DIAGONAL_ROD_CFG,CfgPrinterItems.cfg_delta_diagonal_rod);
		HAL::eprSetFloat(EPR_DELTA_FLOOR_SAFETY_MARGIN_MM_CFG,CfgPrinterItems.cfg_delta_floor_safety_margin_mm);
		 HAL::eprSetByte(EPR_FEATURE_Z_PROBE_CFG,CfgPrinterItems.cfg_feature_z_probe);
		 HAL::eprSetByte(EPR_BED_LEVELING_METHOD_CFG,CfgPrinterItems.cfg_bed_leveling_method);
		 HAL::eprSetFloat(EPR_Z_PROBE_HEIGHT_CFG,CfgPrinterItems.cfg_z_probe_height);
		 HAL::eprSetFloat(EPR_Z_PROBE_X1_CFG,CfgPrinterItems.cfg_z_probe_x1);
		 HAL::eprSetFloat(EPR_Z_PROBE_Y1_CFG,CfgPrinterItems.cfg_z_probe_y1);
		 HAL::eprSetFloat(EPR_Z_PROBE_X2_CFG,CfgPrinterItems.cfg_z_probe_x2);
		 HAL::eprSetFloat(EPR_Z_PROBE_Y2_CFG,CfgPrinterItems.cfg_z_probe_y2);
		 HAL::eprSetFloat(EPR_Z_PROBE_X3_CFG,CfgPrinterItems.cfg_z_probe_x3);
		 HAL::eprSetFloat(EPR_Z_PROBE_Y3_CFG,CfgPrinterItems.cfg_z_probe_y3);
		 HAL::eprSetFloat(EPR_XAXIS_STEPS_PER_MM_CFG,CfgPrinterItems.cfg_xaxis_steps_per_mm);
		 HAL::eprSetFloat(EPR_YAXIS_STEPS_PER_MM_CFG,CfgPrinterItems.cfg_yaxis_steps_per_mm);
		 HAL::eprSetFloat(EPR_ZAXIS_STEPS_PER_MM_CFG,CfgPrinterItems.cfg_zaxis_steps_per_mm);
		 HAL::eprSetFloat(EPR_EXT0_STEPS_PER_MM_CFG,CfgPrinterItems.cfg_ext0_steps_per_mm);
		 HAL::eprSetFloat(EPR_MAX_FEEDRATE_X_CFG,CfgPrinterItems.cfg_max_feedrate_x);
		 HAL::eprSetFloat(EPR_MAX_FEEDRATE_Y_CFG,CfgPrinterItems.cfg_max_feedrate_y);
		 HAL::eprSetFloat(EPR_MAX_FEEDRATE_Z_CFG,CfgPrinterItems.cfg_max_feedrate_z);
		 HAL::eprSetFloat(EPR_MAX_FEEDRATE_EXT0_CFG,CfgPrinterItems.cfg_max_feedrate_e0);
		 HAL::eprSetFloat(EPR_MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X_CFG,CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_x);
		 HAL::eprSetFloat(EPR_MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y_CFG,CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_y);
		 HAL::eprSetFloat(EPR_MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z_CFG,CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_z);
		 HAL::eprSetFloat(EPR_MAX_ACCELERATION_EXT0_CFG,CfgPrinterItems.cfg_max_acceleration_e0);
		 HAL::eprSetFloat(EPR_MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X_CFG,CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_x);
		 HAL::eprSetFloat(EPR_MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y_CFG,CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_y);
		 HAL::eprSetFloat(EPR_MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z_CFG,CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_z);
		 HAL::eprSetFloat(EPR_HOMING_FEEDRATE_X_CFG,CfgPrinterItems.cfg_homing_feedrate_x);
		 HAL::eprSetFloat(EPR_HOMING_FEEDRATE_Y_CFG,CfgPrinterItems.cfg_homing_feedrate_y);
		 HAL::eprSetFloat(EPR_HOMING_FEEDRATE_Z_CFG,CfgPrinterItems.cfg_homing_feedrate_z);
		 HAL::eprSetFloat(EPR_MIN_EXTRUDER_TEMP_CFG,CfgPrinterItems.cfg_ext_mintemp);
		 HAL::eprSetFloat(EPR_MAX_EXTRUDER_TEMP_CFG,CfgPrinterItems.cfg_ext_maxtemp);
		 HAL::eprSetFloat(EPR_MAX_HEATED_BED_TEMP_CFG,CfgPrinterItems.cfg_heated_bed_maxtemp);
		 HAL::eprSetByte(EPR_NUM_EXTRUDER_CFG,CfgPrinterItems.cfg_num_extruder);
		 HAL::eprSetByte(EPR_HAVE_HEATED_BED_CFG,CfgPrinterItems.cfg_have_heated_bed);
		 HAL::eprSetByte(EPR_INVERT_X_DIR_CFG,CfgPrinterItems.cfg_invert_x_dir);
		 HAL::eprSetByte(EPR_INVERT_Y_DIR_CFG,CfgPrinterItems.cfg_invert_y_dir);
		 HAL::eprSetByte(EPR_INVERT_Z_DIR_CFG,CfgPrinterItems.cfg_invert_z_dir);
		 HAL::eprSetByte(EPR_EXT0_INVERSE_CFG,CfgPrinterItems.cfg_invert_e0_dir);
		 HAL::eprSetByte(EPR_X_HOME_DIR_CFG,CfgPrinterItems.cfg_x_home_dir);
		 HAL::eprSetByte(EPR_Y_HOME_DIR_CFG,CfgPrinterItems.cfg_y_home_dir);
		 HAL::eprSetByte(EPR_Z_HOME_DIR_CFG,CfgPrinterItems.cfg_z_home_dir);
		 HAL::eprSetFloat(EPR_X_MAX_LENGTH_CFG,CfgPrinterItems.cfg_x_max_length);
		 HAL::eprSetFloat(EPR_Y_MAX_LENGTH_CFG,CfgPrinterItems.cfg_y_max_length);
		 HAL::eprSetFloat(EPR_Z_MAX_LENGTH_CFG,CfgPrinterItems.cfg_z_max_length);
		 HAL::eprSetFloat(EPR_X_MIN_POS_CFG,CfgPrinterItems.cfg_x_min_pos);
		 HAL::eprSetFloat(EPR_Y_MIN_POS_CFG,CfgPrinterItems.cfg_y_min_pos);
		 HAL::eprSetFloat(EPR_Z_MIN_POS_CFG,CfgPrinterItems.cfg_z_min_pos);
		 HAL::eprSetByte(EPR_ENDSTOP_X_MIN_INVERTING_CFG,CfgPrinterItems.cfg_endstop_x_min_inverting);
		 HAL::eprSetByte(EPR_ENDSTOP_Y_MIN_INVERTING_CFG,CfgPrinterItems.cfg_endstop_y_min_inverting);
		 HAL::eprSetByte(EPR_ENDSTOP_Z_MIN_INVERTING_CFG,CfgPrinterItems.cfg_endstop_z_min_inverting);
		 HAL::eprSetByte(EPR_ENDSTOP_X_MAX_INVERTING_CFG,CfgPrinterItems.cfg_endstop_x_max_inverting);
		 HAL::eprSetByte(EPR_ENDSTOP_Y_MAX_INVERTING_CFG,CfgPrinterItems.cfg_endstop_y_max_inverting);
		 HAL::eprSetByte(EPR_ENDSTOP_Z_MAX_INVERTING_CFG,CfgPrinterItems.cfg_endstop_z_max_inverting);		
		 HAL::eprSetByte(EPR_MIN_HARDWARE_ENDSTOP_X_CFG,CfgPrinterItems.cfg_min_hardware_endstop_x);	
		 HAL::eprSetByte(EPR_MIN_HARDWARE_ENDSTOP_Y_CFG,CfgPrinterItems.cfg_min_hardware_endstop_y);	
		 HAL::eprSetByte(EPR_MIN_HARDWARE_ENDSTOP_Z_CFG,CfgPrinterItems.cfg_min_hardware_endstop_z);	
		 HAL::eprSetByte(EPR_MAX_HARDWARE_ENDSTOP_X_CFG,CfgPrinterItems.cfg_max_hardware_endstop_x);	
		 HAL::eprSetByte(EPR_MAX_HARDWARE_ENDSTOP_Y_CFG,CfgPrinterItems.cfg_max_hardware_endstop_y);	
		 HAL::eprSetByte(EPR_MAX_HARDWARE_ENDSTOP_Z_CFG,CfgPrinterItems.cfg_max_hardware_endstop_z);	
		 HAL::eprSetByte(EPR_MIN_SOFTWARE_ENDSTOP_X_CFG,CfgPrinterItems.cfg_min_software_endstop_x);	
		 HAL::eprSetByte(EPR_MIN_SOFTWARE_ENDSTOP_Y_CFG,CfgPrinterItems.cfg_min_software_endstop_y);	
		 HAL::eprSetByte(EPR_MIN_SOFTWARE_ENDSTOP_Z_CFG,CfgPrinterItems.cfg_min_software_endstop_z);	
		 HAL::eprSetByte(EPR_MAX_SOFTWARE_ENDSTOP_X_CFG,CfgPrinterItems.cfg_max_software_endstop_x);	
		 HAL::eprSetByte(EPR_MAX_SOFTWARE_ENDSTOP_Y_CFG,CfgPrinterItems.cfg_max_software_endstop_y);	
		 HAL::eprSetByte(EPR_MAX_SOFTWARE_ENDSTOP_Z_CFG,CfgPrinterItems.cfg_max_software_endstop_z);	
		 HAL::eprSetFloat(EPR_END_EFFECTOR_HORIZONTAL_OFFSET_CFG,CfgPrinterItems.cfg_end_effector_horizontal_offset);
		 HAL::eprSetFloat(EPR_CARRIAGE_HORIZONTAL_OFFSET_CFG,CfgPrinterItems.cfg_carriage_horizontal_offset);
		 HAL::eprSetFloat(EPR_ROD_RADIUS_CFG,CfgPrinterItems.cfg_rod_radius);
		 HAL::eprSetFloat(EPR_BED_LEVELING_GRID_SIZE_CFG,CfgPrinterItems.cfg_bed_leveling_grid_size);
		 HAL::eprSetFloat(EPR_Z_PROBE_SPEED_CFG,CfgPrinterItems.cfg_z_probe_speed);
		 HAL::eprSetFloat(EPR_Z_PROBE_XY_SPEED_CFG,CfgPrinterItems.cfg_z_probe_xy_speed);
		 HAL::eprSetInt32(EPR_STEPPER_HIGH_DELAY_CFG,CfgPrinterItems.cfg_stepper_high_delay);

		
		valid_flag = BAK_INF_VALID_FLAG;
		HAL::eprSetInt32(EPR_VALID_FLAG_CFG,valid_flag); 
		HAL::AT24CXX_Read(EPR_VALID_FLAG_CFG,(u8*)&valid_flag,4);
		
	}
}

void cfg_init()
{
	uint32_t sdcard_info_update = 0;
	
	//--------------------------------------------------//
	gCfgItems.preheat_desireSprayerTemp[0]=gCfgItems.preheat_desireSprayerTemp[1] = 180;
	gCfgItems.preheat_desireBedTemp = 50;
	
	gCfgItems.move_dist = 1;
	gCfgItems.printSpeed = 100;
	gCfgItems.printExtSpeed0= 100;
	gCfgItems.printExtSpeed1 = 100;
	gCfgItems.stepPrintSpeed = 1;
	gCfgItems.extruSpeed = 1;
	gCfgItems.extruStep = 5;
	gCfgItems.stepHeat = 1;
	gCfgItems.moveSpeed = 3000;
	
	gCfgItems.custom_pic_flag = 1;
	gCfgItems.language = LANG_ENGLISH;
    gCfgItems.button_3d_effect_flag = 0;
    //gCfgItems.have_ups = 0;
	gCfgItems.background_color = GUI_BK_CLOLOR;
	gCfgItems.title_color = GUI_TITLE_TEXT_COLOR;
	gCfgItems.state_background_color = GUI_STATE_COLOR;
	gCfgItems.state_text_color = GUI_STATE_TEXT_COLOR;
	gCfgItems.filename_color = GUI_FILE_NAME_TEXT_COLOR;
	gCfgItems.filename_background_color = GUI_FILE_NAME_BK_COLOR;
	gCfgItems.printingstate_word_background_color = GUI_PRINTING_STATE_BK_COLOR;
	gCfgItems.printingstate_word_color = GUI_PRINTING_STATE_TEXT_COLOR;
	//gCfgItems.language = 3;
	gCfgItems.pause_zpos = 10;
	gCfgItems.MoreItem_pic_cnt = 0;
	gCfgItems.func_btn1_display_flag = 1;
	gCfgItems.func_btn2_display_flag = 0;
	//-------------------------------------------------//

	CfgPrinterItems.cfg_baudrate = 115200;
	
	CfgPrinterItems.cfg_drive_system = 0;
	
	CfgPrinterItems.cfg_num_extruder = 1;
	CfgPrinterItems.cfg_have_heated_bed = 1;
	
	CfgPrinterItems.cfg_ext0_tempsensor_type = 1;
	CfgPrinterItems.cfg_ext1_tempsensor_type = 1;
	CfgPrinterItems.cfg_heated_bed_sensor_type = 1;
	

	CfgPrinterItems.cfg_xaxis_steps_per_mm = 78.74;
	CfgPrinterItems.cfg_yaxis_steps_per_mm = 78.74;
	CfgPrinterItems.cfg_zaxis_steps_per_mm = 400;
	CfgPrinterItems.cfg_ext0_steps_per_mm = 90;

	CfgPrinterItems.cfg_max_feedrate_x = 	200;
	CfgPrinterItems.cfg_max_feedrate_y = 	200;
	CfgPrinterItems.cfg_max_feedrate_z = 	20;
	CfgPrinterItems.cfg_max_feedrate_e0 = 50;

	CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_x = 1000;
	CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_y = 1000;
	CfgPrinterItems.cfg_max_acceleration_units_per_sq_second_z = 100;
	CfgPrinterItems.cfg_max_acceleration_e0 = 1000;

	CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_x = 1000;
	CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_y = 1000;
	CfgPrinterItems.cfg_max_travel_acceleration_units_per_sq_second_z = 100;

	CfgPrinterItems.cfg_homing_feedrate_x = 40;
	CfgPrinterItems.cfg_homing_feedrate_y = 40;
	CfgPrinterItems.cfg_homing_feedrate_z = 2;


	CfgPrinterItems.cfg_ext_mintemp = 150;
	CfgPrinterItems.cfg_ext_maxtemp = 275;
	CfgPrinterItems.cfg_heated_bed_maxtemp = 150;

	CfgPrinterItems.cfg_ui_set_maxtemp = 260;
	CfgPrinterItems.cfg_ui_set_heated_bed_maxtemp = 120;	
	
	CfgPrinterItems.cfg_invert_x_dir = true;
	CfgPrinterItems.cfg_invert_y_dir = false;
	CfgPrinterItems.cfg_invert_z_dir = true;
	CfgPrinterItems.cfg_invert_e0_dir = true;
	CfgPrinterItems.cfg_invert_e1_dir = true;

	CfgPrinterItems.cfg_x_home_dir = -1;
	CfgPrinterItems.cfg_y_home_dir = -1;
	CfgPrinterItems.cfg_z_home_dir = -1;


	CfgPrinterItems.cfg_x_max_length = 230;
	CfgPrinterItems.cfg_y_max_length = 230;
	CfgPrinterItems.cfg_z_max_length = 230;
	
	CfgPrinterItems.cfg_x_min_pos = 0;
	CfgPrinterItems.cfg_y_min_pos = 0;
	CfgPrinterItems.cfg_z_min_pos = 0;


	CfgPrinterItems.cfg_endstop_x_min_inverting = 1;
	CfgPrinterItems.cfg_endstop_y_min_inverting = 1;
	CfgPrinterItems.cfg_endstop_z_min_inverting = 1;
	CfgPrinterItems.cfg_endstop_x_max_inverting = 0;
	CfgPrinterItems.cfg_endstop_y_max_inverting = 0;
	CfgPrinterItems.cfg_endstop_z_max_inverting = 0;

	CfgPrinterItems.cfg_min_hardware_endstop_x = 1;
	CfgPrinterItems.cfg_min_hardware_endstop_y = 1;
	CfgPrinterItems.cfg_min_hardware_endstop_z = 1;
	CfgPrinterItems.cfg_max_hardware_endstop_x = 0;
	CfgPrinterItems.cfg_max_hardware_endstop_y = 0;
	CfgPrinterItems.cfg_max_hardware_endstop_z = 0;

	CfgPrinterItems.cfg_min_software_endstop_x = 0;
	CfgPrinterItems.cfg_min_software_endstop_y = 0;
	CfgPrinterItems.cfg_min_software_endstop_z = 0;
	CfgPrinterItems.cfg_max_software_endstop_x = 1;
	CfgPrinterItems.cfg_max_software_endstop_y = 1;
	CfgPrinterItems.cfg_max_software_endstop_z = 1;

	CfgPrinterItems.cfg_delta_max_radius = 115;
	CfgPrinterItems.cfg_printer_radius = 180;
	CfgPrinterItems.cfg_delta_diagonal_rod = 300;

	CfgPrinterItems.cfg_feature_z_probe = 0;
	CfgPrinterItems.cfg_bed_leveling_method = 0;
	CfgPrinterItems.cfg_z_probe_height = 39.91;
	CfgPrinterItems.cfg_end_effector_horizontal_offset = 28.5;
	CfgPrinterItems.cfg_carriage_horizontal_offset = 25.5;
	CfgPrinterItems.cfg_rod_radius = 157.6;
	CfgPrinterItems.cfg_bed_leveling_grid_size = 5;
	CfgPrinterItems.cfg_z_probe_speed = 80;
	CfgPrinterItems.cfg_z_probe_xy_speed =200;
	CfgPrinterItems.cfg_stepper_high_delay = 0;
	recover_cfg_inf();
    //用于cc936编码转换表计算
    SPI_FLASH_BufferRead((u8*)&ugbksize,FONTINFOADDR,sizeof(ugbksize));

	SPI_FLASH_BufferRead((uint8_t *)&sdcard_info_update,FlASH_INF_VALID_ADDR,4);
	if(sdcard_info_update != FLASH_INF_VALID_FLAG)
	{
		char sdcard_info_buf1[5] = "M84;";
		char sdcard_info_buf2[11] = "G28;G32 S2";
		char sdcard_info_buf3[5] = "G28;";
		//功能按钮
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf1, BUTTON_FUNCTION1_ADDR, strlen(sdcard_info_buf1)+1);
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf2, BUTTON_FUNCTION2_ADDR, strlen(sdcard_info_buf2)+1);		
		//more按钮
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD1_ADDR, strlen(sdcard_info_buf3)+1);	
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD2_ADDR, strlen(sdcard_info_buf3)+1);	
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD3_ADDR, strlen(sdcard_info_buf3)+1);	
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD4_ADDR, strlen(sdcard_info_buf3)+1);	
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD5_ADDR, strlen(sdcard_info_buf3)+1);	
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD6_ADDR, strlen(sdcard_info_buf3)+1);	
		SPI_FLASH_BufferWrite((uint8_t *)sdcard_info_buf3, BUTTON_CMD7_ADDR, strlen(sdcard_info_buf3)+1);	
	}
}

void define_value_init()
{
if(CfgPrinterItems.cfg_drive_system == DELTA 
	|| CfgPrinterItems.cfg_drive_system==TUGA 
	|| CfgPrinterItems.cfg_drive_system==BIPOD)
	Change_Repetier_Define.def_NONLINEAR_SYSTEM = 1;
else
	Change_Repetier_Define.def_NONLINEAR_SYSTEM = 0;


	Change_Repetier_Define.def_ENDSTOP_X_MIN_INVERTING = CfgPrinterItems.cfg_endstop_x_min_inverting;
	Change_Repetier_Define.def_ENDSTOP_Y_MIN_INVERTING = CfgPrinterItems.cfg_endstop_y_min_inverting;
	Change_Repetier_Define.def_ENDSTOP_Z_MIN_INVERTING = CfgPrinterItems.cfg_endstop_z_min_inverting;
	Change_Repetier_Define.def_ENDSTOP_X_MAX_INVERTING = CfgPrinterItems.cfg_endstop_x_max_inverting;
	Change_Repetier_Define.def_ENDSTOP_Y_MAX_INVERTING = CfgPrinterItems.cfg_endstop_y_max_inverting;
	Change_Repetier_Define.def_ENDSTOP_Z_MAX_INVERTING = CfgPrinterItems.cfg_endstop_z_max_inverting;

	Change_Repetier_Define.def_MIN_HARDWARE_ENDSTOP_X = CfgPrinterItems.cfg_min_hardware_endstop_x;
	Change_Repetier_Define.def_MIN_HARDWARE_ENDSTOP_Y = CfgPrinterItems.cfg_min_hardware_endstop_y;
	Change_Repetier_Define.def_MIN_HARDWARE_ENDSTOP_Z = CfgPrinterItems.cfg_min_hardware_endstop_z;
	Change_Repetier_Define.def_MAX_HARDWARE_ENDSTOP_X = CfgPrinterItems.cfg_max_hardware_endstop_x;
	Change_Repetier_Define.def_MAX_HARDWARE_ENDSTOP_Y = CfgPrinterItems.cfg_max_hardware_endstop_y;
	Change_Repetier_Define.def_MAX_HARDWARE_ENDSTOP_Z = CfgPrinterItems.cfg_max_hardware_endstop_z;

	Change_Repetier_Define.def_min_software_endstop_x = CfgPrinterItems.cfg_min_software_endstop_x;
	Change_Repetier_Define.def_min_software_endstop_y = CfgPrinterItems.cfg_min_software_endstop_y;
	Change_Repetier_Define.def_min_software_endstop_z = CfgPrinterItems.cfg_min_software_endstop_z;
	Change_Repetier_Define.def_max_software_endstop_x = CfgPrinterItems.cfg_max_software_endstop_x;
	Change_Repetier_Define.def_max_software_endstop_y = CfgPrinterItems.cfg_max_software_endstop_y;
	Change_Repetier_Define.def_max_software_endstop_z = CfgPrinterItems.cfg_max_software_endstop_z;

	if(CfgPrinterItems.cfg_num_extruder>0)
	{
	if(CfgPrinterItems.cfg_ext0_tempsensor_type == 101)
	{
		Change_Repetier_Define.def_SUPPORT_MAX6675 = 1;
	}
	if(CfgPrinterItems.cfg_ext0_tempsensor_type == 102)
	{
		Change_Repetier_Define.def_SUPPORT_MAX31855 = 1;
	}
	}

	if(Change_Repetier_Define.def_SUPPORT_MAX6675 == 1)
	{
		#if !defined SCK_PIN || !defined MOSI_PIN || !defined MISO_PIN
			#error For MAX6675 support, you need to define SCK_PIN, MISO_PIN and MOSI_PIN in pins.h
		#endif
	}

	#if X_STEP_PIN < 0 || Y_STEP_PIN < 0 || Z_STEP_PIN < 0
		#error One of the following pins is not assigned: X_STEP_PIN,Y_STEP_PIN,Z_STEP_PIN
	#endif
	#if EXT0_STEP_PIN < 0 
	if(CfgPrinterItems.cfg_num_extruder > 0)
		#error EXT0_STEP_PIN not set to a pin number.
	#endif
	#if EXT0_DIR_PIN < 0 
	if(CfgPrinterItems.cfg_num_extruder > 0)
		#error EXT0_DIR_PIN not set to a pin number.
	#endif
	#if PRINTLINE_CACHE_SIZE < 4
		#error PRINTLINE_CACHE_SIZE must be at least 5
	#endif

	Change_Repetier_Define.def_PWM_BOARD_FAN = CfgPrinterItems.cfg_num_extruder + 1;
	Change_Repetier_Define.def_PWM_FAN1 = Change_Repetier_Define.def_PWM_BOARD_FAN+1;
	Change_Repetier_Define.def_PWM_FAN2 = Change_Repetier_Define.def_PWM_FAN1 + 1;
	Change_Repetier_Define.def_PWM_FAN_THERMO = Change_Repetier_Define.def_PWM_FAN2 + 1;


	if(CfgPrinterItems.cfg_have_heated_bed == 1)
	{
		#if FAN_THERMO_PIN > -1
			Change_Repetier_Define.def_NUM_TEMPERATURE_LOOPS = CfgPrinterItems.cfg_num_extruder+2;
		#else
			Change_Repetier_Define.def_NUM_TEMPERATURE_LOOPS = CfgPrinterItems.cfg_num_extruder+1;
		#endif
	}
	else
	{
		#if FAN_THERMO_PIN > -1
			Change_Repetier_Define.def_NUM_TEMPERATURE_LOOPS = CfgPrinterItems.cfg_num_extruder+1;
		#else
			Change_Repetier_Define.def_NUM_TEMPERATURE_LOOPS = CfgPrinterItems.cfg_num_extruder;
		#endif
	}

/*
	if(CfgPrinterItems.cfg_drive_system == DELTA)
	{
		CfgPrinterItems.cfg_xaxis_steps_per_mm = CfgPrinterItems.cfg_axis_steps_per_mm;
		CfgPrinterItems.cfg_yaxis_steps_per_mm = CfgPrinterItems.cfg_axis_steps_per_mm;
		CfgPrinterItems.cfg_zaxis_steps_per_mm = CfgPrinterItems.cfg_axis_steps_per_mm;
	}
*/

if (CfgPrinterItems.cfg_drive_system == DELTA)
{
/** \brief Delta rod length (mm)*/
Change_Repetier_Define.def_DELTA_DIAGONAL_ROD = CfgPrinterItems.cfg_delta_diagonal_rod;	//345 // mm	delta 9
/** \brief column positions - change only to correct build imperfections! */
Change_Repetier_Define.def_DELTA_ALPHA_A = 210;
Change_Repetier_Define.def_DELTA_ALPHA_B = 330;
Change_Repetier_Define.def_DELTA_ALPHA_C = 90;

/** Correct radius by this value for each column. Perfect builds have 0 everywhere. */
Change_Repetier_Define.def_DELTA_RADIUS_CORRECTION_A = 0;
Change_Repetier_Define.def_DELTA_RADIUS_CORRECTION_B = 0;
Change_Repetier_Define.def_DELTA_RADIUS_CORRECTION_C = 0;

/** Correction of the default diagonal size. Value gets added.*/
Change_Repetier_Define.def_DELTA_DIAGONAL_CORRECTION_A = 0;
Change_Repetier_Define.def_DELTA_DIAGONAL_CORRECTION_B = 0;
Change_Repetier_Define.def_DELTA_DIAGONAL_CORRECTION_C = 0;

/** Max. radius (mm) the printer should be able to reach. */
Change_Repetier_Define.def_DELTA_MAX_RADIUS = CfgPrinterItems.cfg_delta_max_radius;//115;//*200

// Margin (mm) to avoid above tower minimum (xMin xMinsteps)
Change_Repetier_Define.def_DELTA_FLOOR_SAFETY_MARGIN_MM = CfgPrinterItems.cfg_delta_floor_safety_margin_mm;

/** \brief Horizontal offset of the universal joints on the end effector (moving platform).
*/
Change_Repetier_Define.def_END_EFFECTOR_HORIZONTAL_OFFSET = CfgPrinterItems.cfg_end_effector_horizontal_offset;

/** \brief Horizontal offset of the universal joints on the vertical carriages.
*/
Change_Repetier_Define.def_CARRIAGE_HORIZONTAL_OFFSET = CfgPrinterItems.cfg_carriage_horizontal_offset;

/** \brief Printer radius in mm,
*/
Change_Repetier_Define.def_PRINTER_RADIUS = CfgPrinterItems.cfg_printer_radius;//*115//	265.25	//delta 10

/* ========== END Delta calibration data ==============*/
Change_Repetier_Define.def_DELTA_HOME_ON_POWER = 0;

Change_Repetier_Define.def_DELTA_X_ENDSTOP_OFFSET_STEPS = 0;
Change_Repetier_Define.def_DELTA_Y_ENDSTOP_OFFSET_STEPS = 0;
Change_Repetier_Define.def_DELTA_Z_ENDSTOP_OFFSET_STEPS = 0;

}
if(CfgPrinterItems.cfg_drive_system == DELTA)
{
	Change_Repetier_Define.def_ENDSTOP_X_BACK_MOVE = 5;		//5	//modify 8
	Change_Repetier_Define.def_ENDSTOP_Y_BACK_MOVE = 5;		//5	//modify 9
	Change_Repetier_Define.def_ENDSTOP_Z_BACK_MOVE = 2;		// 2//modify 10
	
	Change_Repetier_Define.def_ENDSTOP_X_BACK_ON_HOME = 1;
	Change_Repetier_Define.def_ENDSTOP_Y_BACK_ON_HOME = 1;
	Change_Repetier_Define.def_ENDSTOP_Z_BACK_ON_HOME = 0;	

}
else
{
	Change_Repetier_Define.def_ENDSTOP_X_BACK_MOVE = 5;		//5	//modify 8
	Change_Repetier_Define.def_ENDSTOP_Y_BACK_MOVE = 5;		//5	//modify 9
	Change_Repetier_Define.def_ENDSTOP_Z_BACK_MOVE = 2;		// 2 //modify 10
	
	Change_Repetier_Define.def_ENDSTOP_X_BACK_ON_HOME = 1;
	Change_Repetier_Define.def_ENDSTOP_Y_BACK_ON_HOME = 1;
	Change_Repetier_Define.def_ENDSTOP_Z_BACK_ON_HOME = 0;	

}




}

