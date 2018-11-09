#include<stdio.h>

int test(const char* szsrc)
{
	char chararr[4]={0};
	int iparr[4]={0};

	char outstr[200]={0};
	int success=0;
	unsigned int outresult = 0;
	int i = 0;
	success=sscanf(szsrc, "%3d%c%3d%c%3d%c%3d%c", &iparr[0], &chararr[0], &iparr[1],&chararr[1],&iparr[2],&chararr[2], &iparr[3], &chararr[3]);

	if(success==7 && chararr[0]==chararr[1] && chararr[2]=='.' && chararr[0]=='.')
	{

		for( i =0; i < 4 ; i++)
		{
			if(iparr[i]<0 ||iparr[i] >255)
				goto ERROR;
		}
		outresult= (iparr[0]<<24) + (iparr[1]<<16) + (iparr[2]<<8) + iparr[3];

		sprintf(outstr,"%u\n",outresult);
		printf(outstr);
		return 0;
	}
ERROR:
	printf("ERROR\n");
}

int main()
{
	char instr[200];
	int res =0;
	freopen("in.txt","r",stdin);
	while((res=scanf("%s", instr)) >0)
	{
		printf("%s:", instr);
		test(instr);
	}
	fclose(stdin);
}