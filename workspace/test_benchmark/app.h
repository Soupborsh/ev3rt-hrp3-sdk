#include "target_test.h"

/*
 *  ターゲットに依存する可能性のある定数の定義
 */

#define	STACK_SIZE		0x1000		/* タスクのスタックサイズ */

/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern void	main_task(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */
