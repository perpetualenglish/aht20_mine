/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_aht20_interface_template.c
 * @brief     driver aht20 interface template source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2022-10-31
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2022/10/31  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_aht20_interface.h"

#include "main.h"
#include "i2c.h"
#include <stdarg.h>

/**
 * @brief  interface iic bus init
 * @return status code
 *         - 0 success
 *         - 1 iic init failed
 * @note   none
 */
uint8_t aht20_interface_iic_init(void)
{
    uint8_t retval = 0;
    return retval;
}

/**
 * @brief  interface iic bus deinit
 * @return status code
 *         - 0 success
 *         - 1 iic deinit failed
 * @note   none
 */
uint8_t aht20_interface_iic_deinit(void)
{
    uint8_t retval = 0;
    return retval;
}

/**
 * @brief      interface iic bus read
 * @param[in]  addr iic device write address
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len length of the data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t aht20_interface_iic_read_cmd(uint8_t addr, uint8_t *buf, uint16_t len)
{
    uint8_t retval = 0;
    retval = HAL_I2C_Master_Receive(&hi2c2, (uint16_t) addr, buf, len, 0xffff);
    return retval;
}

/**
 * @brief     interface iic bus write
 * @param[in] addr iic device write address
 * @param[in] *buf pointer to a data buffer
 * @param[in] len length of the data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t aht20_interface_iic_write_cmd(uint8_t addr, uint8_t *buf, uint16_t len)
{
    uint8_t retval = 0;
    retval = HAL_I2C_Master_Transmit(&hi2c2, (uint16_t) addr, (uint8_t *)buf, (uint16_t) len, 0xffff);
    return retval;
}

/**
 * @brief     interface delay ms
 * @param[in] ms time
 * @note      none
 */
void aht20_interface_delay_ms(uint32_t ms)
{
  HAL_Delay(ms);
}

/**
 * @brief     interface print format data
 * @param[in] fmt format data
 * @note      none
 */
/**
 * @brief AHT20传感器接口调试打印函数
 * 
 * 本函数用于根据给定的格式字符串和参数列表生成调试信息，并将其打印出来。
 * 它主要用于AHT20传感器接口的调试过程中，提供灵活的打印功能。
 * 
 * @param fmt 格式字符串，描述了期望的输出格式
 * @param ... 可变参数列表，包含格式字符串中格式说明符的具体值
 */
void aht20_interface_debug_print(const char *const fmt, ...)
{
    // 定义一个字符数组用于存储格式化后的字符串
    char str[256];
    // 定义一个整型变量用于存储字符串长度
    uint16_t len;
    // 定义一个va_list类型变量用于处理可变参数列表
    va_list args;
    
    // 清除字符串数组的内容，确保初始化
    memset((char *)str, 0, sizeof(char) * 256); 
    // 初始化va_list变量，使其指向可变参数列表的开始
    va_start(args, fmt);
    // 根据格式字符串和可变参数列表，将格式化的字符串写入str数组中
    vsnprintf((char *)str, 255, (char const *)fmt, args);
    // 解除va_list变量的初始化，表示可变参数列表处理结束
    va_end(args);
    
    // 计算格式化字符串的长度
    len = strlen((char *)str);
    // 使用printf函数打印格式化后的字符串
    (void)printf("%s", (uint8_t *)str);
}
