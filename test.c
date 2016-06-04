#define _CRT_SECURE_NO_WARNINGS 1


#include"AnnotationConvert.h"

int main()
{
	ConverState ret = AnnotationConvert("input.c", "output.c");
	if (ret == FILE_ERROR)
	{
		printf("打开文件错误！\n");
	}
	else if (ret == SUCCESS)
	{
		printf("转换成功！\n");
	}
	else if (ret == NO_MATCH)
	{
		printf("不匹配！\n");
	}
	system("pause");
	return 0;
}