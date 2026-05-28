#ifndef __VERSION_H
#define __VERSION_H

/* 版本信息 */
#define VERSION         "V1.5.280"      // 当前版本号
#define VERSION_DATE    "2026-05-28"    // 版本发布日期

/* 设备信息 */
#define DEVICE_ID       "PCT_100_FCs"   // 设备ID，FairyCat专属

/* 项目信息 */
#define PROJECT_NAME    "PCT_100_CTL"   // 项目名称
#define PROJECT_AUTHOR  "FairyCat"      // 项目作者
#define PROJECT_DATE    "2026-05-27"    // 项目创建日期

/* ==================== 功能列表 ==================== */
/* 基础功能 */
#define FEATURE_KEY         1   // 按键检测功能（带消抖）
#define FEATURE_LED         1   // LED控制功能（闪烁、翻转）
#define FEATURE_RELAY       1   // 继电器控制功能（吸合/断开）

/* 高级功能 */
#define FEATURE_INTERRUPT   1   // 外部中断功能（上升沿/下降沿触发）
#define FEATURE_NON_BLOCK   1   // 非阻塞延时功能（使用millis）
#define FEATURE_SERIAL      1   // 串口通信功能

/* 版本更新记录 */
/* V1.0    - 初始版本，基础LED和按键功能 */
/* V1.5.280 - 新增功能：外部中断、非阻塞延时、继电器控制、增加了一些注释 */

#endif