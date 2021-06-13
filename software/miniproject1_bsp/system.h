/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'niosiisystem'
 * SOPC Builder design path: ../../niosiisystem.sopcinfo
 *
 * Generated: Thu Apr 29 10:28:23 ICT 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x04080820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1b
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x04040020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x04040000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x04080820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1b
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x04040020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x04040000


/*
 * DRAM configuration
 *
 */

#define ALT_MODULE_CLASS_DRAM altera_avalon_new_sdram_controller
#define DRAM_BASE 0x0
#define DRAM_CAS_LATENCY 3
#define DRAM_CONTENTS_INFO
#define DRAM_INIT_NOP_DELAY 0.0
#define DRAM_INIT_REFRESH_COMMANDS 2
#define DRAM_IRQ -1
#define DRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DRAM_IS_INITIALIZED 1
#define DRAM_NAME "/dev/DRAM"
#define DRAM_POWERUP_DELAY 100.0
#define DRAM_REFRESH_PERIOD 15.625
#define DRAM_REGISTER_DATA_IN 1
#define DRAM_SDRAM_ADDR_WIDTH 0x19
#define DRAM_SDRAM_BANK_WIDTH 2
#define DRAM_SDRAM_COL_WIDTH 10
#define DRAM_SDRAM_DATA_WIDTH 16
#define DRAM_SDRAM_NUM_BANKS 4
#define DRAM_SDRAM_NUM_CHIPSELECTS 1
#define DRAM_SDRAM_ROW_WIDTH 13
#define DRAM_SHARED_DATA 0
#define DRAM_SIM_MODEL_BASE 0
#define DRAM_SPAN 67108864
#define DRAM_STARVATION_INDICATOR 0
#define DRAM_TRISTATE_BRIDGE_SLAVE ""
#define DRAM_TYPE "altera_avalon_new_sdram_controller"
#define DRAM_T_AC 5.5
#define DRAM_T_MRD 3
#define DRAM_T_RCD 20.0
#define DRAM_T_RFC 70.0
#define DRAM_T_RP 20.0
#define DRAM_T_WR 14.0


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_UP_AVALON_ADC


/*
 * GPIO configuration
 *
 */

#define ALT_MODULE_CLASS_GPIO altera_avalon_pio
#define GPIO_BASE 0x4081060
#define GPIO_BIT_CLEARING_EDGE_REGISTER 0
#define GPIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GPIO_CAPTURE 0
#define GPIO_DATA_WIDTH 16
#define GPIO_DO_TEST_BENCH_WIRING 0
#define GPIO_DRIVEN_SIM_VALUE 0
#define GPIO_EDGE_TYPE "NONE"
#define GPIO_FREQ 50000000
#define GPIO_HAS_IN 0
#define GPIO_HAS_OUT 1
#define GPIO_HAS_TRI 0
#define GPIO_IRQ -1
#define GPIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GPIO_IRQ_TYPE "NONE"
#define GPIO_NAME "/dev/GPIO"
#define GPIO_RESET_VALUE 0
#define GPIO_SPAN 16
#define GPIO_TYPE "altera_avalon_pio"


/*
 * IMEM configuration
 *
 */

#define ALT_MODULE_CLASS_IMEM altera_avalon_onchip_memory2
#define IMEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define IMEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define IMEM_BASE 0x4040000
#define IMEM_CONTENTS_INFO ""
#define IMEM_DUAL_PORT 0
#define IMEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define IMEM_INIT_CONTENTS_FILE "niosiisystem_IMEM"
#define IMEM_INIT_MEM_CONTENT 1
#define IMEM_INSTANCE_ID "NONE"
#define IMEM_IRQ -1
#define IMEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define IMEM_NAME "/dev/IMEM"
#define IMEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define IMEM_RAM_BLOCK_TYPE "AUTO"
#define IMEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define IMEM_SINGLE_CLOCK_OP 0
#define IMEM_SIZE_MULTIPLE 1
#define IMEM_SIZE_VALUE 204800
#define IMEM_SPAN 204800
#define IMEM_TYPE "altera_avalon_onchip_memory2"
#define IMEM_WRITABLE 1


/*
 * LEDR configuration
 *
 */

#define ALT_MODULE_CLASS_LEDR altera_avalon_pio
#define LEDR_BASE 0x4081070
#define LEDR_BIT_CLEARING_EDGE_REGISTER 0
#define LEDR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDR_CAPTURE 0
#define LEDR_DATA_WIDTH 10
#define LEDR_DO_TEST_BENCH_WIRING 0
#define LEDR_DRIVEN_SIM_VALUE 0
#define LEDR_EDGE_TYPE "NONE"
#define LEDR_FREQ 50000000
#define LEDR_HAS_IN 0
#define LEDR_HAS_OUT 1
#define LEDR_HAS_TRI 0
#define LEDR_IRQ -1
#define LEDR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDR_IRQ_TYPE "NONE"
#define LEDR_NAME "/dev/LEDR"
#define LEDR_RESET_VALUE 0
#define LEDR_SPAN 16
#define LEDR_TYPE "altera_avalon_pio"


/*
 * SW configuration
 *
 */

#define ALT_MODULE_CLASS_SW altera_avalon_pio
#define SW_BASE 0x4081080
#define SW_BIT_CLEARING_EDGE_REGISTER 0
#define SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SW_CAPTURE 0
#define SW_DATA_WIDTH 10
#define SW_DO_TEST_BENCH_WIRING 0
#define SW_DRIVEN_SIM_VALUE 0
#define SW_EDGE_TYPE "NONE"
#define SW_FREQ 50000000
#define SW_HAS_IN 1
#define SW_HAS_OUT 0
#define SW_HAS_TRI 0
#define SW_IRQ -1
#define SW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SW_IRQ_TYPE "NONE"
#define SW_NAME "/dev/SW"
#define SW_RESET_VALUE 0
#define SW_SPAN 16
#define SW_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x4081098
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x4081098
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x4081098
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "niosiisystem"


/*
 * adc_0 configuration
 *
 */

#define ADC_0_BASE 0x4081000
#define ADC_0_IRQ -1
#define ADC_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ADC_0_NAME "/dev/adc_0"
#define ADC_0_SPAN 32
#define ADC_0_TYPE "altera_up_avalon_adc"
#define ALT_MODULE_CLASS_adc_0 altera_up_avalon_adc


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK TIMER_1


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x4081098
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x4081090
#define SYSID_QSYS_0_ID 67637392
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1619064928
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x4081040
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 2
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1 altera_avalon_timer
#define TIMER_1_ALWAYS_RUN 0
#define TIMER_1_BASE 0x4081020
#define TIMER_1_COUNTER_SIZE 32
#define TIMER_1_FIXED_PERIOD 0
#define TIMER_1_FREQ 50000000
#define TIMER_1_IRQ 1
#define TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1_LOAD_VALUE 49999
#define TIMER_1_MULT 0.001
#define TIMER_1_NAME "/dev/timer_1"
#define TIMER_1_PERIOD 1
#define TIMER_1_PERIOD_UNITS "ms"
#define TIMER_1_RESET_OUTPUT 0
#define TIMER_1_SNAPSHOT 1
#define TIMER_1_SPAN 32
#define TIMER_1_TICKS_PER_SEC 1000
#define TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
