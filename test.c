#define _CRT_SECURE_NO_WARNINGS 1


#include"AnnotationConvert.h"

int main()
{
	ConverState ret = AnnotationConvert("input.c", "output.c");
	if (ret == FILE_ERROR)
	{
		printf("���ļ�����\n");
	}
	else if (ret == SUCCESS)
	{
		printf("ת���ɹ���\n");
	}
	else if (ret == NO_MATCH)
	{
		printf("��ƥ�䣡\n");
	}
	system("pause");
	return 0;
}