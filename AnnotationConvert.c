#define _CRT_SECURE_NO_WARNINGS 1
#include"AnnotationConvert.h"

ConverState Convert(FILE *fIn, FILE *fOut)
{
	State ret = SUCCESS;
	char first, second, get;
	ConverState tag = c_close;
	assert(fIn);
	assert(fOut);
	get = fgetc(fIn);
	do{
		first = get;
		switch (first)
		{
			case '/':
				second = fgetc(fIn);
				if (second == '/')
				{
					// 7.C++注释问题
					fputc('/', fOut);
					while (get != '\n')
					{
						fputc(get, fOut);
						get = fgetc(fIn);
					}
					fseek(fIn, -1, SEEK_CUR);
				}
				else if (second == '*')
				{    // 3.匹配问题
					if (tag==c_close)
					{
						fputc('/', fOut);
						fputc('/', fOut);
						tag = c_open;
					}
					else 
					{
						fputc('/', fOut);
						fputc('*', fOut);
					}	
				}
				else 
				{
					fputc(first, fOut);
				}
				break;
			case '*':
				second = fgetc(fIn);
				if (second == '/')
				{    // 2.换行问题
					char next = fgetc(fIn);
					fputc('\n', fOut);
					if (next != '\n'&& next!=EOF)
					{
						// 5.连续注释问题
						fseek(fIn, -1,SEEK_CUR);
					}
					tag = c_close;
				}
				else
				{
					fputc(first, fOut);
					// 6.连续的**/问题
					fseek(fIn, -1, SEEK_CUR);
				}
				break;
			case'\n':// 4.多行注释问题
				fputc('\n', fOut);
				if (tag == c_open)
				{
					fputc('/', fOut);
					fputc('/', fOut);
				}
				break;
			default:
				fputc(first, fOut);
				break;		
		}
		get = fgetc(fIn);
	} while (get != EOF);
	return ret;
}

ConverState AnnotationConvert(const char * inputFile, const char * outputFile)
{
	State ret;
	FILE *fOut, *fIn;
	fIn = fopen(inputFile, "r");
	if (fIn == NULL)
	{
		printf("打开文件%s失败",inputFile);
		return FILE_ERROR;
	}
	fOut = fopen(outputFile, "w");
	if (fOut == NULL)
	{
		fclose(fIn);
		printf("打开文件%s失败", outputFile);
		return FILE_ERROR;
	}
	ret=Convert(fIn, fOut);
	fclose(fIn);
	fclose(fOut);
	return ret;
}



