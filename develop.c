#include "develop.h"

void TraceLog(char *LogMsg_p, ...)
{
#if OUTLOGTO_FILE_C
	FILE *pOutFile;
#endif
	va_list VarArgList;
	char  LogMsgBuf[BUFSIZ];

	memset(LogMsgBuf, 0x0, BUFSIZ);

	memset(&VarArgList, 0x0, sizeof(VarArgList));
	va_start (VarArgList, LogMsg_p);
	vsprintf (LogMsgBuf, LogMsg_p, VarArgList);
#if OUTLOGTO_FILE_C
	pOutFile = fopen("/tmp/CellularClient/ClientLog","a");
	if(NULL == pOutFile)
	{
		return;
	}
	fputs(LogMsgBuf,pOutFile);
	fputs("\r\n",pOutFile);
	fclose(pOutFile);
#else
	printf("\r\n%s",LogMsgBuf);
	fflush(stdout);
#endif /*OUTLOGTO_FILE_C */

	va_end (VarArgList);
}