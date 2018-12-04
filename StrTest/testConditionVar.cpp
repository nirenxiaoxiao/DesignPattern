#include <windows.h> 
#include <stdio.h>

#define MAX_NUM      100    
#define MAX_THREAD   10   
static int g_array[MAX_NUM];
volatile int g_num_gen = 0;
volatile int g_count = 0;
static int g_stop = 0;
CRITICAL_SECTION g_cs;
CONDITION_VARIABLE g_cv_w;
CONDITION_VARIABLE g_cv_r;

LRESULT WINAPI WriteThread(PVOID arg)
{
	while (!g_stop){
		EnterCriticalSection(&g_cs);
		while (g_count == MAX_NUM && !g_stop){/* 如果缓存区已满，则写线程等待 */
			SleepConditionVariableCS(&g_cv_w, &g_cs, INFINITE);
		}
		if (g_stop){
			break;
		}
		g_array[g_count++] = g_num_gen++;
		printf("write %d count=%d tid=%lu\n", g_array[g_count - 1], g_count, GetCurrentThreadId());
		LeaveCriticalSection(&g_cs);
		WakeConditionVariable(&g_cv_r);
		Sleep(500);
	}

	LeaveCriticalSection(&g_cs);
	WakeAllConditionVariable(&g_cv_r);
	return 0;
}

LRESULT WINAPI ReadThread(PVOID arg)
{
	while (!g_stop){
		EnterCriticalSection(&g_cs);
		while (g_count == 0 && !g_stop){/* 如果缓存区已满，则写线程等待 */
			SleepConditionVariableCS(&g_cv_r, &g_cs, INFINITE);
		}
		if (g_stop){
			break;
		}
		printf("read %d count=%d tid=%lu\n", g_array[g_count - 1], g_count, GetCurrentThreadId());
		g_count--;
		LeaveCriticalSection(&g_cs);
		WakeConditionVariable(&g_cv_w);
		Sleep(500);
	}

	LeaveCriticalSection(&g_cs);
	WakeAllConditionVariable(&g_cv_w);
	return 0;
}

int TestConditionVar()
{

	HANDLE hThreadArray[MAX_THREAD];
	InitializeCriticalSection(&g_cs);
	InitializeConditionVariable(&g_cv_r);
	InitializeConditionVariable(&g_cv_w);

	/* 开启写线程 */
	for (int i = 0; i<2; i++){
		hThreadArray[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WriteThread, NULL, 0, NULL);
	}
	/* 开启读线程 */
	for (int i = 2; i<MAX_THREAD; i++) {
		hThreadArray[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadThread, NULL, 0, NULL);
	}

	getchar();
	g_stop = 1;
	WaitForMultipleObjects(MAX_THREAD, hThreadArray, TRUE, INFINITE);
	for (int i = 0; i<10; i++){
		CloseHandle(hThreadArray[i]);
	}
	DeleteCriticalSection(&g_cs);
	printf("All threads exit!\n");
	return 0;
}

int main2(int argc, const char* argv[])
{
	TestConditionVar();
	return 0;
}
