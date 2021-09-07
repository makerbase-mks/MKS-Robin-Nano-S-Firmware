#include "gui.h"
#include "button.h"
#include "draw_ui.h"
#include "draw_gcode_command.h"
#include "draw_operate.h"
#include "draw_zero.h"
#include "stdio.h"
#include  <string.h>
#include <stdlib.h>
#include "temperature.h"
#include "Marlin.h"
#include "tim.h"
#include "planner.h"
#include "mks_cfg.h"
#include "draw_tool.h"
#include "mks_reprint.h"
#include "draw_keyboard.h"

static GUI_HWIN hKeyBoardWnd;

static BUTTON_STRUCT buttonkeyRet,textKeyNumb,buttonkeyconfirm;//,buttonkeynegative,buttonkeyAC

static TEXT_Handle testTitleBack;

//float key_set_value=3;	//skyblue modify 2018-10
extern GUI_BITMAP bmp_struct_key;
extern uint8_t num_keyboard_set_type;

extern uint8_t from_flash_pic;
extern uint8_t flash_preview_begin;
extern uint8_t default_preview_flg;

extern char gcode_command[25];

//uint8_t disp_command_line=0;

static void cbKeyBoardWin(WM_MESSAGE * pMsg) {
    char *temp;
    int key_int_value;
    
    struct PressEvt *press_event;

	switch (pMsg->MsgId) {
	case WM_PAINT:
		// 1  //114
		break;
	case WM_TOUCH:
	 	press_event = (struct PressEvt *)pMsg->Data.p;
		
		break;
	case WM_TOUCH_CHILD:
	  press_event = (struct PressEvt *)pMsg->Data.p;
		
	  break;

	case WM_NOTIFY_PARENT:
		if(pMsg->Data.v == WM_NOTIFICATION_RELEASED)
		{
		
			press_event = (struct PressEvt *)pMsg->Data.p;

		      
			if(pMsg->hWinSrc == buttonkeyconfirm.btnHandle)
			{
				//disp_command_line=0;
				keyboard_type = GCODE_COMMAND_CONFIG;
				last_disp_state = GCODE_COMMAND_UI;
			    	Clear_gcodeCommand();
				draw_Keyboard();
			}            
			else if(pMsg->hWinSrc == buttonkeyRet.btnHandle)
			{
				//disp_command_line=0;
				//disp_state_stack._disp_state[disp_state_stack._disp_index] = (DISP_STATE)0;
				//disp_state_stack._disp_index--;
			    	last_disp_state = GCODE_COMMAND_UI;
			    	Clear_gcodeCommand();
				draw_MachineSettings();			
			}	
			else if(pMsg->hWinSrc == textKeyNumb.btnHandle)
			{
				//disp_command_line=0;
				keyboard_type = GCODE_COMMAND_CONFIG;
			    	last_disp_state = GCODE_COMMAND_UI;
			    	Clear_gcodeCommand();
				draw_Keyboard();
			}
			
		}
		break;
	default:
	WM_DefaultProc(pMsg);
	}
}
//extern GUI_BITMAP bmp_struct_74x31;
//extern GUI_BITMAP bmp_struct_51x30;
//extern GUI_BITMAP bmp_struct_70x66;
extern GUI_BITMAP bmp_struct_32x21;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontHelvetica36;


void draw_gcodeCommand()
{
    //char *temp_buf[11];
    
	if(disp_state_stack._disp_state[disp_state_stack._disp_index] != GCODE_COMMAND_UI)
	{
		disp_state_stack._disp_index++;
		disp_state_stack._disp_state[disp_state_stack._disp_index] = GCODE_COMMAND_UI;
	}
	disp_state = GCODE_COMMAND_UI;
	
	GUI_SetBkColor(0x000000);
	GUI_SetColor(gCfgItems.title_color);
	GUI_Clear(); 

    
	hKeyBoardWnd = WM_CreateWindow(0, 0, LCD_WIDTH, titleHeight, WM_CF_SHOW, cbKeyBoardWin, 0);

	testTitleBack=TEXT_CreateEx(0, 0, LCD_WIDTH, titleHeight, hKeyBoardWnd, WM_CF_SHOW, TEXT_CF_LEFT,	GUI_ID_TEXT1, " ");
	TEXT_SetBkColor(testTitleBack, 0xf78541);
	buttonkeyconfirm.btnHandle = BUTTON_CreateEx(406,0,74,titleHeight+1,hKeyBoardWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
	buttonkeyRet.btnHandle = BUTTON_CreateEx(0,  0,74, titleHeight+1, hKeyBoardWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
	textKeyNumb.btnHandle= BUTTON_CreateEx(85, 8, LCD_WIDTH-148-23, titleHeight-16, hKeyBoardWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
	BUTTON_SetBmpFileName(buttonkeyRet.btnHandle, NULL,1);
	//BUTTON_SetBitmapEx(buttonkeyRet.btnHandle, 0, &bmp_struct_32x21, 5, 8);
	BUTTON_SetBkColor(buttonkeyRet.btnHandle, BUTTON_CI_PRESSED, 0x3131e6);
	BUTTON_SetBkColor(buttonkeyRet.btnHandle, BUTTON_CI_UNPRESSED, 0x3131e6);
	//BUTTON_SetTextColor(buttonkeyRet.btnHandle, BUTTON_CI_PRESSED,0xffffff);
	//BUTTON_SetTextColor(buttonkeyRet.btnHandle, BUTTON_CI_UNPRESSED, 0xffffff);
	BUTTON_SetTextAlign(buttonkeyRet.btnHandle, GUI_TA_VCENTER|GUI_TA_HCENTER);
	BUTTON_SetText(buttonkeyRet.btnHandle, "Back");
	

    BUTTON_SetBmpFileName(buttonkeyconfirm.btnHandle, NULL,1);

   // BUTTON_SetBitmapEx(buttonkeyconfirm.btnHandle, 0, &bmp_struct_74x31, BMP_PIC_X, BMP_PIC_Y);    

    BUTTON_SetBkColor(textKeyNumb.btnHandle, BUTTON_CI_PRESSED, GUI_BLACK);
	BUTTON_SetTextColor(textKeyNumb.btnHandle, BUTTON_CI_UNPRESSED, GUI_WHITE);

	
	BUTTON_SetBkColor(buttonkeyconfirm.btnHandle, BUTTON_CI_PRESSED, 0x3131e6);
	BUTTON_SetBkColor(buttonkeyconfirm.btnHandle, BUTTON_CI_UNPRESSED, 0x3131e6);


   BUTTON_SetTextAlign(textKeyNumb.btnHandle,  GUI_TA_VCENTER | GUI_TA_LEFT);


    BUTTON_SetTextAlign(buttonkeyconfirm.btnHandle, GUI_TA_VCENTER | GUI_TA_HCENTER);
	BUTTON_SetText(buttonkeyconfirm.btnHandle, "Gcode");



   //memset(key_value,0,sizeof(key_value));
    //cnt=0;
    //key_value[cnt]=0;
   BUTTON_SetText(textKeyNumb.btnHandle, "");


   //disp_command_line=0;
   init_UART_TX(&uart_tx);
   initFIFO(&gcodeCmdRxFIFO);
   
   GUI_SetColor(0x00ffff);
   GUI_DispStringAt(">>>", 10, titleHeight+8);
   GUI_DispStringAt((char *)key_value_calc.password_value, 50, titleHeight+8);

   //GUI_SetBkColor(gCfgItems.background_color);
   GUI_SetColor(gCfgItems.title_color);
	
}

void Clear_gcodeCommand()
{
	GUI_SetBkColor(gCfgItems.background_color);
	if(WM_IsWindow(hKeyBoardWnd))
	{
		WM_DeleteWindow(hKeyBoardWnd);
		//GUI_Exec();
	}
	
	//GUI_Clear();
}

