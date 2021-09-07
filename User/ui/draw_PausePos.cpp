#include "gui.h"
#include "button.h"
#include "draw_ui.h"
#include <math.h>
#include <stdint.h>
#include "stdint.h"
#include "Marlin.h"
#include "mks_reprint.h"

#ifndef GUI_FLASH
#define GUI_FLASH
#endif

static GUI_HWIN hPausePosWnd;
static BUTTON_STRUCT XPOS,YPOS,ZPOS;
static BUTTON_STRUCT XPOS_Text,YPOS_Text,ZPOS_Text;
static BUTTON_STRUCT button_back;

static void cbPausePosWin(WM_MESSAGE * pMsg) {

    struct PressEvt *press_event;
    switch (pMsg->MsgId)
    {
    	case WM_PAINT:
			//GUI_SetColor(gCfgItems.state_background_color);
			//GUI_DrawRect(LCD_WIDTH/4+X_ADD, 0, LCD_WIDTH *3 / 4-X_INTERVAL, imgHeight /2 -15);
			GUI_SetColor(0xff5449);
			GUI_FillRect(10, 90, 470,90);

	              GUI_FillRect(10, 140, 470,140);              
	              GUI_FillRect(10, 190, 470,190);
 
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
    			if(pMsg->hWinSrc == button_back.btnHandle)
    			{
    				last_disp_state = MACHINETYPE_UI;
    				Clear_PausePos();
    				draw_return_ui();
    			}	
    			else if(pMsg->hWinSrc == XPOS.btnHandle)
    			{
                     	value=pause_pos_x;
				last_disp_state = PAUSE_POS_UI;
	                    Clear_PausePos();                    
	                    draw_NumberKey();
                    }
    			else if(pMsg->hWinSrc == YPOS.btnHandle)
    			{
                    		value=pause_pos_y;
				last_disp_state = PAUSE_POS_UI;
	                    Clear_PausePos();                    
	                    draw_NumberKey();
    			}
    			else if(pMsg->hWinSrc == ZPOS.btnHandle)
    			{
    				value=pause_pos_z;
				last_disp_state = PAUSE_POS_UI;
	                    Clear_PausePos();                    
	                    draw_NumberKey();
    			}       			
    		}
    		break;
    		
    	default:
    		WM_DefaultProc(pMsg);
    	}
}


void draw_PausePos()
{   
    int i;
    char buf[30];

    if(disp_state_stack._disp_state[disp_state_stack._disp_index] != PAUSE_POS_UI)
    {
        disp_state_stack._disp_index++;
        disp_state_stack._disp_state[disp_state_stack._disp_index] = PAUSE_POS_UI;
    }
    disp_state = PAUSE_POS_UI;
    
    GUI_SetBkColor(gCfgItems.background_color);
    GUI_SetColor(gCfgItems.title_color);
    GUI_Clear();
    
    GUI_DispStringAt(machine_menu.PausePosText, TITLE_XPOS, TITLE_YPOS);

    hPausePosWnd = WM_CreateWindow(0, 0, LCD_WIDTH, LCD_HEIGHT, WM_CF_SHOW, cbPausePosWin, 0);

    XPOS_Text.btnHandle = BUTTON_CreateEx(10,50,380,40,hPausePosWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
    XPOS.btnHandle = BUTTON_CreateEx(400,50+5,VALUE_DEFAULT_X,VALUE_DEFAULT_Y,hPausePosWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
    
    YPOS_Text.btnHandle = BUTTON_CreateEx(10,100,380,40,hPausePosWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
    YPOS.btnHandle = BUTTON_CreateEx(400,100+5,VALUE_DEFAULT_X,VALUE_DEFAULT_Y,hPausePosWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
    
    ZPOS_Text.btnHandle = BUTTON_CreateEx(10,150,380,40,hPausePosWnd, BUTTON_CF_SHOW, 0, alloc_win_id());
    ZPOS.btnHandle = BUTTON_CreateEx(400,150+5,VALUE_DEFAULT_X,VALUE_DEFAULT_Y,hPausePosWnd, BUTTON_CF_SHOW, 0, alloc_win_id());

   
    BUTTON_SetBmpFileName(XPOS_Text.btnHandle,NULL,1);        
    BUTTON_SetBmpFileName(YPOS_Text.btnHandle,NULL,1);
    BUTTON_SetBmpFileName(ZPOS_Text.btnHandle,NULL,1);
    
    BUTTON_SetTextAlign(XPOS_Text.btnHandle,GUI_TA_LEFT|GUI_TA_VCENTER );
    BUTTON_SetTextAlign(YPOS_Text.btnHandle,GUI_TA_LEFT|GUI_TA_VCENTER );
    BUTTON_SetTextAlign(ZPOS_Text.btnHandle,GUI_TA_LEFT|GUI_TA_VCENTER );

    BUTTON_SetTextAlign(XPOS.btnHandle,GUI_TA_HCENTER|GUI_TA_VCENTER );
    BUTTON_SetTextAlign(YPOS.btnHandle,GUI_TA_HCENTER|GUI_TA_VCENTER );
    BUTTON_SetTextAlign(ZPOS.btnHandle,GUI_TA_HCENTER|GUI_TA_VCENTER );

   BUTTON_SetBkColor(XPOS.btnHandle, BUTTON_CI_PRESSED, gCfgItems.value_bk_color);
        BUTTON_SetBkColor(XPOS.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.value_bk_color); 
        BUTTON_SetTextColor(XPOS.btnHandle, BUTTON_CI_PRESSED, gCfgItems.value_text_color);
        BUTTON_SetTextColor(XPOS.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.value_text_color); 

	BUTTON_SetBkColor(YPOS.btnHandle, BUTTON_CI_PRESSED, gCfgItems.value_bk_color);
        BUTTON_SetBkColor(YPOS.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.value_bk_color); 
        BUTTON_SetTextColor(YPOS.btnHandle, BUTTON_CI_PRESSED, gCfgItems.value_text_color);
        BUTTON_SetTextColor(YPOS.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.value_text_color); 

   BUTTON_SetBkColor(ZPOS.btnHandle, BUTTON_CI_PRESSED, gCfgItems.value_bk_color);
        BUTTON_SetBkColor(ZPOS.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.value_bk_color); 
        BUTTON_SetTextColor(ZPOS.btnHandle, BUTTON_CI_PRESSED, gCfgItems.value_text_color);
        BUTTON_SetTextColor(ZPOS.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.value_text_color); 

    button_back.btnHandle = BUTTON_CreateEx(400,270,70,40,hPausePosWnd,BUTTON_CF_SHOW,0,alloc_win_id());
    
    BUTTON_SetBmpFileName(button_back.btnHandle, "bmp_back70x40.bin",1);        
    BUTTON_SetBitmapEx(button_back.btnHandle, 0, &bmp_struct70X40,0, 0);
    BUTTON_SetTextAlign(button_back.btnHandle,GUI_TA_HCENTER|GUI_TA_VCENTER );
    
    BUTTON_SetBkColor(button_back.btnHandle, BUTTON_CI_PRESSED, gCfgItems.back_btn_color);
    BUTTON_SetBkColor(button_back.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.back_btn_color); 
    BUTTON_SetTextColor(button_back.btnHandle, BUTTON_CI_PRESSED, gCfgItems.back_btn_textcolor);
    BUTTON_SetTextColor(button_back.btnHandle, BUTTON_CI_UNPRESSED, gCfgItems.back_btn_textcolor); 

    BUTTON_SetBmpFileName(XPOS.btnHandle, "bmp_value_blank.bin",1);
    BUTTON_SetBitmapEx(XPOS.btnHandle,0,&bmp_struct70X28,0,0); 

    BUTTON_SetBmpFileName(YPOS.btnHandle, "bmp_value_blank.bin",1);
    BUTTON_SetBitmapEx(YPOS.btnHandle,0,&bmp_struct70X28,0,0);

    BUTTON_SetBmpFileName(ZPOS.btnHandle, "bmp_value_blank.bin",1);
    BUTTON_SetBitmapEx(ZPOS.btnHandle,0,&bmp_struct70X28,0,0);
    
    if(gCfgItems.multiple_language != 0)
    {
    	 memset(buf,0,sizeof(buf));
        sprintf(buf,"%.3f",mksReprint.mks_pausePrint_x);
	 BUTTON_SetText(XPOS.btnHandle, buf);
	 
	 memset(buf,0,sizeof(buf));
        sprintf(buf,"%.3f",mksReprint.mks_pausePrint_y);
        BUTTON_SetText(YPOS.btnHandle, buf);

	 memset(buf,0,sizeof(buf));
        sprintf(buf,"%.3f",mksReprint.mks_pausePrint_z);
        BUTTON_SetText(ZPOS.btnHandle, buf);
    
        BUTTON_SetText(XPOS_Text.btnHandle, machine_menu.xPos);
        BUTTON_SetText(YPOS_Text.btnHandle, machine_menu.yPos);
        BUTTON_SetText(ZPOS_Text.btnHandle, machine_menu.zPos);   

        BUTTON_SetText(button_back.btnHandle,common_menu.text_back); 
    }

}

void Clear_PausePos()
{
	GUI_SetBkColor(gCfgItems.background_color);
	if(WM_IsWindow(hPausePosWnd))
	{
		WM_DeleteWindow(hPausePosWnd);
	}
}





