#ifndef B_IMAGECORRECT_H_
#define B_IMAGECORRECT_H_

#define  IMAGE_H    110
#define  IMAGE_W    118

// src: input and output
//s=1
// input need image-insert or cut the white lines

void b_imageCorrect(unsigned char* src);

void b_imageInsert(unsigned char* src, int s);


#endif
