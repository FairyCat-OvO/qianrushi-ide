#ifndef __VERSION_H
#define __VERSION_H

/* ==================== 版本信息 ==================== */
#define VERSION         "V1.5.29.0"     // 当前版本号
#define VERSION_DATE    "2026-05-29"    // 版本发布日期

/* ==================== 设备信息 ==================== */
#define DEVICE_ID       "PCT_100_FCs"   // 设备ID，FairyCat

/* ==================== 项目信息 ==================== */
#define PROJECT_NAME    "PCT_100_CTL"   // 项目名称
#define PROJECT_AUTHOR  "FairyCat"      // 项目作者
#define PROJECT_DATE    "2026-05-25"    // 项目创建日期

/* ==================== 功能列表 ==================== */

/* 1. 按键检测功能 */
/* 对应文件夹: class/key jiance/key/ */
/* 功能说明: 检测GPIO21引脚的按键状态，带软件消抖功能 */
#define FEATURE_KEY         1   // 按键检测功能（已实现）

/* 2. LED闪烁功能 */
/* 对应文件夹: class/led blingbling/led/ */
/* 功能说明: 控制GPIO1引脚的LED，实现闪烁效果（亮200ms/灭200ms） */
#define FEATURE_LED         1   // LED控制功能（已实现）

/* 3. 继电器控制功能（阻塞方式） */
/* 对应文件夹: class/jidianqi control/relay/ */
/* 功能说明: 控制GPIO2引脚的继电器，使用delay()实现定时切换（1秒周期） */
#define FEATURE_RELAY       1   // 继电器控制功能（已实现）

/* 4. 继电器控制功能（非阻塞方式） */
/* 对应文件夹: class/jidianqi millis/relay_noblock/ */
/* 功能说明: 使用millis()实现非阻塞延时，继电器每2秒切换一次状态 */
#define FEATURE_NON_BLOCK   1   // 非阻塞延时功能（已实现）

/* 5. 外部中断功能 */
/* 对应文件夹: class/wai bu zhong duan/interrupt_led/ */
/* 功能说明: 通过GPIO21外部中断检测按键，上升沿触发，实现LED状态翻转 */
/*           使用volatile关键字保护共享变量，避免在中断中使用阻塞函数 */
#define FEATURE_INTERRUPT   1   // 外部中断功能（已实现）

/* 6. 按键控制继电器功能 */
/* 对应文件夹: class/key control jidianqi/relay_control/ */
/* 功能说明: 双按键控制继电器开关，KEY1（自锁）为总开关，KEY2（普通）控制继电器 */
/*           KEY1打开后允许KEY2控制继电器，按KEY2一次吸合，再按一次断开 */
/*           KEY1关闭后继电器强制断开，实现安全开关功能 */
#define FEATURE_KEY_RELAY   1   // 按键控制继电器功能（已实现）

/* 7. 双按键控制双继电器功能（中断方式） */
/* 对应文件夹: class/00_11_relay_control/dual_relay_control/ */
/* 功能说明: 双按键控制双继电器四种状态轮流切换，KEY1（GPIO20）为自锁总开关，KEY2（GPIO21）控制状态切换 */
/*           继电器1接GPIO6，继电器2接GPIO7，支持四种状态：00(都断开)、01(断吸)、10(吸断)、11(都吸合) */
/*           使用外部中断检测按键，系统使能标志保护共享变量 */
#define FEATURE_DUAL_RELAY  1   // 双按键控制双继电器功能（已实现）

/* ==================== 版本更新记录 ==================== */
/* V1.0     - 初始版本，基础框架搭建 */
/* V1.5.27  - 新增功能：
   - 按键检测模块（带消抖）
   - LED闪烁模块
   - 继电器控制模块（阻塞方式）
   - 继电器控制模块（非阻塞方式，使用millis）
*/
/* V1.5.280 - 新增功能：
   - 外部中断模块（使用attachInterrupt实现）
   - GPIO21下拉输入，按键按下产生上升沿触发中断
   - 中断服务函数中翻转LED状态，演示外部中断基本用法
*/
/* V1.5.281 - 新增功能：
   - 按键控制继电器模块（KEY1自锁总开关 + KEY2普通按键控制）
   - KEY1（GPIO21）自锁按键作为系统总开关
   - KEY2（GPIO20）普通按键控制继电器吸合/断开
   - 实现安全开关逻辑：总开关关闭时继电器强制断开
*/
/* V1.5.29.0 - 新增功能：
   - 双按键控制双继电器模块（中断方式）
   - KEY1（GPIO20）自锁按键作为系统总开关
   - KEY2（GPIO21）普通按键控制继电器状态切换
   - 继电器1接GPIO6，继电器2接GPIO7，支持四种状态轮流切换
   - 使用外部中断检测按键，系统使能标志保护共享变量
*/

#endif