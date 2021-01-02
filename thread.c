// スレッド

// ヘッダー
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pspthreadman.h>
#include "thread.h"


// グローバル変数
static int first_th[MAX_THREAD];
static int first_count;

static int current_th[MAX_THREAD];
static int current_count;


static bool threadsState = false;// == ture : suspend / == false : resume

static clock_t safelySuspendTime;





void safelySuspendThreadsInit()
{
	safelySuspendTime = sceKernelLibcClock();
}

int safelySuspendThreads( clock_t waitTime )
{
	if( ! threadsState ){
		if( (sceKernelLibcClock() - safelySuspendTime) >= waitTime ){
//			Suspend_Resume_Threads(SUSPEND_MODE);
			suspendThreads();
			return 1;
		}
		return -1;
	}
	
	return 0;
}

void suspendThreads()
{
	if( ! threadsState ){
		Suspend_Resume_Threads(SUSPEND_MODE);
		threadsState = true;
	}	
}

void resumeThreads()
{
	if( threadsState ){
		Suspend_Resume_Threads(RESUME_MODE);
		threadsState = false;
	}
}

bool Get_ThreadModeStatus()
{
	
	return threadsState;
}


int Get_ThreadStatus()
{
	SceKernelThreadInfo thinfo;
	int threads[MAX_THREAD];
	int threads_count;

	sceKernelGetThreadmanIdList(SCE_KERNEL_TMID_Thread, threads, MAX_THREAD, &threads_count);

	memset(&thinfo, 0, sizeof(SceKernelThreadInfo));
	thinfo.size = sizeof(SceKernelThreadInfo);
	sceKernelReferThreadStatus(threads[threads_count-1], &thinfo);
	if( thinfo.status & PSP_THREAD_SUSPEND )return 1;

	return 0;

}


void Get_FirstThreads()
{
	// スレッド一覧を取得
	sceKernelGetThreadmanIdList(SCE_KERNEL_TMID_Thread, first_th, MAX_THREAD, &first_count);
}

void Suspend_Resume_Threads(int mode)
{
	int i, n;
	SceUID my_thid;
	SceUID (*Thread_Func)(SceUID) = NULL;
	SceKernelThreadInfo thinfo;

	my_thid = sceKernelGetThreadId();
	Thread_Func = (mode == RESUME_MODE ? sceKernelResumeThread : sceKernelSuspendThread);

	// スレッド一覧を取得

	if(mode == SUSPEND_MODE)
	{
	sceKernelGetThreadmanIdList(SCE_KERNEL_TMID_Thread, current_th, MAX_THREAD, &current_count);

		for(i = 0; i < current_count; i++)
		{

			memset(&thinfo, 0, sizeof(SceKernelThreadInfo));
			thinfo.size = sizeof(SceKernelThreadInfo);
			sceKernelReferThreadStatus(current_th[i], &thinfo);
			if( thinfo.status & PSP_THREAD_SUSPEND || current_th[i] == my_thid )
			{
				current_th[i] = 0;
				continue;
			}

			for(n = 0; n < first_count; n++)
			{
				if(current_th[i] == first_th[n])
				{
					current_th[i] = 0;
					n = first_count;
				}
			}
		}
	}
	//最終的な現在のスレッドリストにあるスレッドへ停止・再開の操作
	for( i = 0; i < current_count; i++ )
	{
		if( current_th[i] )Thread_Func(current_th[i]);
	}
	return;
}

