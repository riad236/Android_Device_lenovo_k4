

#ifndef __HUAWEISESSION_H__
#define __HUAWEISESSION_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

typedef struct {
	int16_t width; /** < width in pixels, -1 indicates unknown value*/
	int16_t height; /** < heigt in pixels, -1 indicates unknown value*/
	int16_t ppi; /** < sampling intensity, -1 indicates unknown value*/
	int8_t bits_per_pixels; /** < Greyscale bit depth of the pixels, -1 indicates unknown value */
	int8_t channels; /** < Number of channels */
	int8_t greyscale_polarity; /** < 0 indicates that ridges are black, valleys are white, 1 indicates the inverse situation , -1 indicates unknown value*/
} huawei_frame_format_t;

typedef struct {
	huawei_frame_format_t format;
	uint16_t frame_count;
	uint8_t* buffer;
	uint32_t capacity;
} huawei_image_t;

struct _HuaweiEnrolSession{
	int16_t nMaxNum;	//���ģ����Ŀ
	int16_t nUsedNum;   //��ʹ����Ŀ
	uint8_t* pDataBuf;	//����ռ�
};

struct _huawei_template_t{
	uint8_t feat[1];  //���㷨��������
};

typedef struct _HuaweiEnrolSession enrolment_session_t; //¼��Ự��ʵ�����ݽṹ���㷨���ڲ�����
typedef struct _huawei_template_t huawei_template_t; //ָ��ģ�壬ʵ�����ݽṹ���㷨���ڲ�����

typedef struct huawei_image_quality_t {
	int coverage; //ָ��ͼ�񸲸����򣨵�λΪ��������Ŀ��
	int quality; //ͼƬ����, [0~100]
} huawei_image_quality_t;

typedef struct ialgorithm_t {
	// ��ʼָ��¼�룬���ػỰָ��
	enrolment_session_t* (*enrolStart)(); //��Ҫ���ӿڱ���Ҫʵ��
	// ��¼��Ự���ָ��ͼ��ͼ������ָ�ƴ�������������Ҫ���ָ��ͼ�񣬷���ֵ��־��ǰ���ȣ�0-100��
	int32_t (*enrolAddImage)(enrolment_session_t *session,
		huawei_image_t* image,
		huawei_image_quality_t* image_quality); //��Ҫ���ӿڱ���Ҫʵ��
	// ��¼��Ự�����ָ��ͼ����ȴﵽ100%ʱ���øýӿ���ȡָ��ģ������

	int32_t (*enrolGetTemplate)(enrolment_session_t *session,	//�Ự�ӿ�
								huawei_template_t** tpl);			//ָ��ģ�飬ָ���ָ��
	// ����¼��Ự
	int32_t (*enrolFinish)(enrolment_session_t *session); //��Ҫ���ӿڱ���Ҫʵ��

	// ָ����֤������ֵ<0,ʧ�ܣ�result��ʾ��֤�ɹ��󷵻ص�ָ��ģ���б�candidates����Ԫ�ص�����ֵ��Score��ʾͼƬƥ��ȡ�
	int32_t (*identifyImage)(huawei_image_t* img,
		huawei_template_t** candidates,		//�ⲿ����ָ������
		uint32_t candidate_count,
		int32_t* result,					//result����ȡֵ��Χ [ 0,candidate_count-1 ], -1���޽�����쳣)
		int32_t* score,						//scoreȡֵ��Χ [ 0,100 ]
		huawei_image_quality_t* image_quality,
		int32_t* update); //�㷨�ڲ��Ƿ������ģ�壬>0���и���

	// ָ��ģ�����ݵ�ѹ���ͽ�ѹ�����ڱ��ر��档
	uint32_t (*templateGetPackedSize)(huawei_template_t *tpl);
	int32_t (*templatePack)(huawei_template_t* tpl, uint8_t* dst);
	int32_t (*templateUnPack)(uint8_t* src, uint32_t length, huawei_template_t** tpl);

	// ָ��ģ��������Դɾ��
	void (*templateDelete)(huawei_template_t* tpl); //��Ҫ���ӿڱ���Ҫʵ��
} ialgorithm_t;

// ��ȡָ���㷨����ָ��
extern void getIalgorithm(ialgorithm_t* ialgorithm);

// ��ȡָ���㷨��汾
extern int32_t getIalgorithmVersion(void);  //4�ֽڵ��ַ���������"1062"

extern int32_t enrolSet(int16_t enrolNum,int16_t mt_size);

#ifdef __cplusplus
}
#endif

#endif	// __HUAWEISESSION_H__
