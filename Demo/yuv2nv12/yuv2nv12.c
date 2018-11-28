/*************************************************************************
	> File Name: yuv2nv12.c
	> Author: sjm
	> Mail: 251362318@qq.com
	> Created Time: 2018年11月27日 星期二 19时56分27秒
    > Fun: 将yuv数据转换为nv12数据,(yuv 4:2:0 yyyyyyyuuuuvvvv) nv12(yyyyuvuvuvuv)
 ************************************************************************/

#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *pfd = fopen(argv[1], "rb");
    FILE *fd = fopen(argv[2],"w");
    int ret = -1;
    if (!pfd || !fd) {
        printf("open file error\n");
        return 0;
        
    }
    int height = 960;
    int width = 540;
    int size=width*height;
    char * Src = (char *)malloc(width*height*1.5);
    char * Dst = (char *)malloc(width*height*1.5);
    fread(Src,1,size*1.5,pfd);
    memcpy(Dst,Src,size);//Y分量赋值
    char* SrcU = Src + width * height;
    char* SrcV = SrcU + width * height / 4 ;
    char* DstU = Dst + width * height;
    int i = 0;
    for( i = 0 ; i < width * height / 4 ; i++ ){
        *(DstU++) = *(SrcU++);
        *(DstU++) = *(SrcV++);    
    }

    fwrite(Dst,1,size*1.5,fd);
    fclose(pfd);
    fclose(fd);
    return 0;
}
