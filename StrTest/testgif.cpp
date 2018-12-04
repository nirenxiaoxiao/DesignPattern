#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef long long INT64;
typedef int BOOL;
typedef int DWORD;
#define TRUE 1
#define FALSE 0

#define MACRO_ISDIGIT(a) ((a)>=48 && (a<=57))
static void RemoveAvatarChar(std::string& strMsg)
{
	// E 或者 e 为表情开始字符 example: e001.gif, e后面有7个字符
	size_t findPos =std::string::npos;
	static size_t patternAllLen = strlen("e001.gif");
	static size_t patternBackLen = strlen(".gif");
	static size_t patternFrontLen = strlen("e001");
	while( (findPos = strMsg.rfind(".gif", findPos)) != std::string::npos )
	{
		if (findPos >= patternFrontLen)
		{
			if(strMsg[findPos - 4] == 'e' || strMsg[findPos - 4] == 'E')
			{
				if ( isdigit(strMsg[findPos - 3])  && isdigit(strMsg[findPos - 2]) && isdigit(strMsg[findPos - 1]))

				//if ( MACRO_ISDIGIT(strMsg[findPos - 3])  && MACRO_ISDIGIT(strMsg[findPos - 2]) && MACRO_ISDIGIT(strMsg[findPos - 1]))
				{
					//匹配成功
					strMsg.erase(findPos - patternFrontLen, patternAllLen );
					findPos -= patternFrontLen;
				}
				else
					findPos--;
			}
			else
				findPos--;
		}
		else
		{
			break;
		}
		
	}
}

BOOL SepWord2Characters(std::string &astrRaw, std::vector<INT64> &aoSeparateStringVec)
{
	DWORD dwLen = astrRaw.size();
	if (0 == dwLen)
	{
		return TRUE;
	}

	char *pStart = (char *)astrRaw.c_str();
	INT64 i64CharacterVal;
	for (DWORD i=0; i<dwLen; )
	{
		unsigned char uc = *(pStart+i);
		unsigned char len = 0;
		i64CharacterVal = 0;
		if ( ! (uc & 0x80) )  // 1个byte长度
			len = 1;
		else if ( uc <= 0xdf ) // 2个byte长度
			len = 2;
		else if ( uc <= 0xef ) // 3个byte长度
			len = 3;
		else if ( uc <= 0xf7 ) // 4个byte长度
			len = 4;
		else if ( uc <= 0xfb ) // 5个byte长度
			len = 5;
		else if ( uc <= 0xfc ) // 5个byte长度
			len = 6;
		else // 编码错误
			return FALSE;
		
		if ((i + len) <= dwLen)
		{
			char *p = pStart + i;
			memcpy((char*)&i64CharacterVal, p, len);
			aoSeparateStringVec.push_back(i64CharacterVal);
			i += len;
		}
		else
		{
			return FALSE;
		}
	}

	return TRUE;
}


void RemoveAvatarChar(std::vector<INT64> &aoCharsArray)
{
	int iSize = aoCharsArray.size();
	
	// E 或者 e 为表情开始字符 example: e001.gif, e后面有7个字符
	for (int i=0; i<iSize-7; )
	{
		INT64 i64CharVal = aoCharsArray[i];

		// 匹配 E 或者 e
		if (69 != i64CharVal && 101 != i64CharVal)
		{
			i++;
			continue;
		}

		// 匹配3个数字
		i++;
		i64CharVal = aoCharsArray[i];
		if (i64CharVal < 48 || i64CharVal > 57)
		{
			continue;
		}
		i++;
		i64CharVal = aoCharsArray[i];
		if (i64CharVal < 48 || i64CharVal > 57)
		{
			continue;
		}
		i++;
		i64CharVal = aoCharsArray[i];
		if (i64CharVal < 48 || i64CharVal > 57)
		{
			continue;
		}		

		// 继续匹配 .gif
		i++;
		if (46 != aoCharsArray[i])
		{
			continue;
		}
		i++;
		if (103 != aoCharsArray[i])
		{
			continue;
		}
		i++;
		if (105 != aoCharsArray[i])
		{
			continue;
		}
		i++;
		if (102 != aoCharsArray[i])
		{
			continue;
		}

		// 找到了，删除表情符，将后面的字符串前移
		aoCharsArray.erase(aoCharsArray.begin()+i-7, aoCharsArray.begin()+i+1);
		// 字符前移之后重新设置匹配的i位置
		i -= 7;
		iSize -= 8; // 字符大小减少

	}
}



#define TEST_COUNT 1000000
#if 0
int main()
{
    std::string  test1;
    const char* testChars[] ={
        "akdfkjslkdfe0001.gifkdafjlkE001.gif.gif",
        "e002.gifdkfjalskdfj.gif",
        "dfkajsldfe333.gifkdafjslk",
        "eabc.gifskdfjalsdkf.gif",
        "e001.gife002.gife003.gif"
		 "akdfkjslkdfe0001.gifkdafjlkE001.gif.gifakdfkjslkdfe0001.gifkdafjlkE001.gif.gifakdfk",
    };

    int b = sizeof(testChars);
    printf("%d\n", b);
	
	clock_t start1,end1;
	start1 = clock();
	for (int j = 0 ; j <TEST_COUNT ; j++)
		for(int i = 0; i < sizeof(testChars)/ sizeof(testChars[0]); i++)
		{
			std::vector<INT64> aoSeparateStringVec;
			test1 = testChars[i];
			SepWord2Characters(test1, aoSeparateStringVec);
			RemoveAvatarChar(aoSeparateStringVec);
		}
	
	end1 =  clock();
	printf("%d, %d, %d\n", start1, end1, end1 - start1);


	clock_t start,end;
	start = clock();
	for (int j = 0 ; j <TEST_COUNT ; j++)
		for(int i = 0; i < sizeof(testChars)/ sizeof(testChars[0]); i++)
		{
			std::vector<INT64> aoSeparateStringVec;
			test1 = testChars[i];
			RemoveAvatarChar(test1);
			SepWord2Characters(test1, aoSeparateStringVec);
			if(j== 1)
				printf("%s\n%s\n",testChars[i], test1.c_str());
		}
	end = clock();
	printf("%d, %d, %d\n", start, end, end-start);


	start1 = clock();
	for (int j = 0 ; j <TEST_COUNT ; j++)
		for(int i = 0; i < sizeof(testChars)/ sizeof(testChars[0]); i++)
		{
			std::vector<INT64> aoSeparateStringVec;
			test1 = testChars[i];
			SepWord2Characters(test1, aoSeparateStringVec);
			RemoveAvatarChar(aoSeparateStringVec);
		}

		end1 =  clock();
		printf("%d, %d, %d\n", start1, end1, end1 - start1);


}
#else

#include "TestFatherChild.h"
int TestFatherChild()
{
	Base b1;
	Child1 c1;
	Child2 c2;

	b1.CallPack();
	c1.CallPack();
	c2.CallPack();
	return 0;

}
#ifdef __cplusplus
extern "C"{
#include "adlist.h"
};
#endif 
int mainTestAdList()
{
	list* pList = listCreate();

	for (int i = 0; i < 10 ; ++i)
	{
		listAddNodeHead(pList, (void*) i);
	}

	int listLen = listLength(pList);
	
	listIter* iter = listGetIterator(pList,AL_START_HEAD);
	listNode* pNode;
	while ((pNode = listNext(iter)) != NULL) {
	     printf("%d\n",listNodeValue(pNode));
	}
	listReleaseIterator(iter);

	listRotate(pList);

	iter = listGetIterator(pList,AL_START_HEAD);
	while ((pNode = listNext(iter)) != NULL) {
		printf("%d\n",listNodeValue(pNode));
	}
	listReleaseIterator(iter);
	return 0;
}


#endif

