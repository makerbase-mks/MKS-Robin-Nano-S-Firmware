#include "stm32f10x.h"
#include "time_tick.h"

unsigned int TimingDelay;


void SysTickInit(unsigned int HzPreSecond)
{
   if (SysTick_Config(SystemCoreClock / HzPreSecond))
    { 
        /* Capture error */ 
        while (1);
    }
}

void SysTickDelay(unsigned int nTime)
{ 
    TimingDelay = nTime;

    while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    { 
        TimingDelay--;
    }
}

/**-------------------------------------------------------
  * @������ SysTick_Handler
  * @����   ϵͳ���Ķ�ʱ��������������
  * @����   ��
  * @����ֵ ��
***------------------------------------------------------*/
    /*
void SysTick_Handler()
{
    _dwTickCount++;
  
    TimingDelay_Decrement();

    SysTick_Handler_User();
}
*/

unsigned int   getTick()
{
	return TimeIncrease;
}

unsigned int  getTickDiff(unsigned int curTick, unsigned int  lastTick)
{
	if(lastTick <= curTick)
	{
		return (curTick - lastTick) * TICK_CYCLE;
	}
	else
	{
		return (0xffffffff - lastTick + curTick) * TICK_CYCLE;
	}
}