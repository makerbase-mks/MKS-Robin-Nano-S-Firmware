#ifndef _PIC_MANAGER_H_
#define _PIC_MANAGER_H_

#define Bank1_NOR2_ADDR       ((uint32_t)0x64000000)

#define PIC_MAX_CN		100				//����ͼƬ��
#define PIC_NAME_MAX_LEN		50	//ͼƬ������󳤶�

#define LOGO_MAX_SIZE			(150*1024) //logo���ֵ
//ͼƬ
/*
#define PIC_LOGO_ADDR			0x000000	//ͼƬlogo�洢��ַ
#define PIC_DATA_ADDR			0x026000	//0x030000 // //ͼƬ���ݴ洢��ַ
#define PIC_NAME_ADDR			0x1f0000	//0x200000 // //ͼƬ��Ϣ�洢��ַ��ͼƬ����
#define PIC_SIZE_ADDR			0x1f7000	//0x210000 // //ͼƬ��Ϣ�洢��ַ��ͼƬ��Сֵ
#define PIC_COUNTER_ADDR		0x1f8000	//0x220000 // //ͼƬ������ֵ�洢��ַ
*/
	//Robin Gen�洢��ַ
#define PIC_NAME_ADDR			0x003000	//ͼƬ��Ϣ�洢��ַ��ͼƬ����
#define PIC_SIZE_ADDR			0x007000	//ͼƬ��Ϣ�洢��ַ��ͼƬ��Сֵ
#define PIC_COUNTER_ADDR	0x008000	//ͼƬ������ֵ�洢��ַ
#define PIC_LOGO_ADDR			0x009000	//ͼƬlogo�洢��ַ
#define PIC_DATA_ADDR			0x02f000	//ͼƬ���ݴ洢��ַ


//�ֿ�
#define FONTINFOADDR	0x600000//6M�Ժ��ַΪ�ֿ�
#define UNIGBK_FLASH_ADDR		(FONTINFOADDR+4096)//4*1024
#define GBK_FLASH_ADDR	(UNIGBK_FLASH_ADDR+180224)//176*1024



//flash��Ϣ��Ч�ı�־
#define FLASH_INF_VALID_FLAG			0xaa558761
//SD����flash�д洢����׵�ַ
#define	SD_INF_ADDR		0x000000//0x1f9000
//SD����flash����Ϣ��Ч��־�洢��ַ
#define FlASH_INF_VALID_ADDR	SD_INF_ADDR
//����˵�flash��ַ
#define BUTTON_CMD1_ADDR	FlASH_INF_VALID_ADDR+4
#define BUTTON_CMD2_ADDR	BUTTON_CMD1_ADDR+204
#define BUTTON_CMD3_ADDR	BUTTON_CMD2_ADDR+204
#define BUTTON_CMD4_ADDR	BUTTON_CMD3_ADDR+204
#define BUTTON_CMD5_ADDR	BUTTON_CMD4_ADDR+204
#define BUTTON_CMD6_ADDR	BUTTON_CMD5_ADDR+204
#define BUTTON_CMD7_ADDR	BUTTON_CMD6_ADDR+204
//wifi��flash��ַ
#define WIFI_NAME_ADDR		BUTTON_CMD7_ADDR+204
#define WIFI_KEYCODE_ADDR	WIFI_NAME_ADDR+204
#define WIFI_IP_ADDR		WIFI_KEYCODE_ADDR+204
#define WIFI_MASK_ADDR		WIFI_IP_ADDR+16
#define	WIFI_GATE_ADDR		WIFI_MASK_ADDR+16
#define	WIFI_DHCP_FLAG_ADDR	WIFI_GATE_ADDR+16
#define WIFI_MODE_SEL_ADDR	WIFI_DHCP_FLAG_ADDR+4
#define WIFI_AP_START_IP_ADDR	WIFI_MODE_SEL_ADDR+4
#define WIFI_AP_END_IP_ADDR		WIFI_AP_START_IP_ADDR+16
#define WIFI_DNS_ADDR			WIFI_AP_END_IP_ADDR+16
//���ܼ�flash��ַ
#define BUTTON_FUNCTION1_ADDR	WIFI_DNS_ADDR+204
#define BUTTON_FUNCTION2_ADDR	BUTTON_FUNCTION1_ADDR+204
#define BUTTON_FUNCTION3_ADDR	BUTTON_FUNCTION1_ADDR+204
//��ӡ�������˵�flash��ַ
#define BUTTON_MOREFUNC1_ADDR		BUTTON_FUNCTION2_ADDR+204
#define BUTTON_MOREFUNC2_ADDR		BUTTON_MOREFUNC1_ADDR+204
#define BUTTON_MOREFUNC3_ADDR		BUTTON_MOREFUNC2_ADDR+204
#define BUTTON_MOREFUNC4_ADDR		BUTTON_MOREFUNC3_ADDR+204
#define BUTTON_MOREFUNC5_ADDR		BUTTON_MOREFUNC4_ADDR+204
#define BUTTON_MOREFUNC6_ADDR		BUTTON_MOREFUNC5_ADDR+204


#define PER_PIC_MAX_SPACE		(16*1024)	//Ϊ�˷�ֹ����Խ������⣬ÿ��СͼƬ�����仮��Ӧ��ȡ�ܹ�����4K��ֵ

//
union union32
{
	uint8_t bytes[4];
	uint32_t dwords;
};
//ͼƬ��Ϣ�ṹ��
struct pic_msg
{
	uint8_t name[PIC_NAME_MAX_LEN];
	union union32 size;
};

typedef struct pic_msg PIC_MSG;


#if defined(__cplusplus)
extern "C" { 
#endif

extern void PicMsg_Init(void);
extern void Pic_Read(uint8_t *Pname,uint8_t *P_Rbuff);
extern void bindBmpFileData(const uint8_t **pBuf, uint8_t *pName);
extern void Pic_Logo_Read(uint8_t *LogoName,uint8_t *Logo_Rbuff,uint32_t LogoReadsize);

#if defined(__cplusplus)
}
#endif


#endif

