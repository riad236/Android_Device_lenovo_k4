#ifndef _FILESAVE_H_
#define _FILESAVE_H_

#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define MODE_F					1       	//fopen fwrite fread
#define MODE_O					0       	//open write read


//��������ֵ
#define ERR_OK					0		//�����ɹ�
#define ERR_INIT_NODEVICE		-1		//�豸��ʼ��ʧ��/���豸
#define ERR_OVERTIME			-2		//������ʱ
#define ERR_MATCH				-3		//�ȶ�ʧ��
#define ERR_OPEN_FILE			-5		//���ļ�ʧ��
#define ERR_WRITE_FILE			-6		//д�ļ�ʧ��
#define ERR_READ_FILE			-7		//���ļ�ʧ��
#define	ERR_NULL				-8		//��ָ��
#define ERR_PARAMETER			-9		//��������
#define ERR_NODEFINE			-255	//δ�������

#define FPALG_IMG_SIZE			(256*256)		//��ָͼ���С
#define FPALG_MB_SIZE			(1600000)	//ÿ����ָ��Ӧ������
#define FPALG_MAX_MB_NUM		5				//���¼��5����ָ			
#define FPALG_MAX_TZ_NUM		8				//ÿ����ָ���3������
#define FPALG_FP_NUM  			30				//������ָ���ɼ��Ĵ���
#define CONFIG_INFO				"/data/local/tmp/config.dat"//��Ӧ��ģ������
#define FP_WIDTH 				118				//ָ��ͼ������W
#define FP_HEIGHT				110				//ָ��ͼ������H
#define FP_MATCH_TMEOUT			5				//�ȶԳ�ʱʱ��


#define FP_THRESHOLD_TIMES		15


#pragma pack(push) //�������״̬
#pragma pack(1)

//��öָ�����ݽṹ��
typedef struct{
	int flag;	//��ʾ�Ƿ�����
	int num;	//��ʾ��Ӧ��ģ����
	unsigned char cpFpImg[FPALG_MAX_TZ_NUM][FPALG_IMG_SIZE];//ָ��ͼ������
	unsigned char cpFpTemp[FPALG_MB_SIZE];//ָ����������
}StuFpInfo; 

#pragma pack(pop)

int Sys_fWrite(int imode, char *fpath, int ioffset, char *fpDatas, int ilen);
int Sys_fRead(int imode, char *cpath, int ioffset, char *cpDatas, int ilen);
int Sys_fLenth(int iMode, char * cpath);

//int SF_WriteFpInfo(int index,int num,unsigned char **cpImage,unsigned char *cpTemp);
//int SF_ReadFpInfo(int mode);

#endif 


