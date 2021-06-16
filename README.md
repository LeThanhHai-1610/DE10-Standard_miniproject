# DE10-Standard_miniproject
A system using Nios II in kit DE10 to connect LCD 16x2 and potentialmeter. This system can do following tasks: When SW0 is ON, LCD blink the sentence “Hello World !!!” in the middle of row 1 of LCD 16x2 with frequency 1Hz. (Using timer). When SW1 is ON, system read Voltage on channel of ADC and display on LCD with format: “Voltage: xx.xV”. When the voltage >3V, all LEDs turn on. When SW0 and SW1 are on, all LEDs blinks from left to right in 0.5s. When SW0 and SW1 are off, turn off

![](RackMultipart20210616-4-8yw3gy_html_c1e65d10cb0b7e87.gif)


![](RackMultipart20210616-4-8yw3gy_html_e613a5c020d72408.png)




Project 1: Build a system using Nios II in kit DE10 to connect LCD 16x2. This system can do following tasks:

- When SW0 is ON, LCD blink the sentence &quot;Hello World !!!&quot; in the middle of row 1 of LCD 16x2 with frequency 1Hz. (Using timer) .

- When SW1 is ON, system read Voltage on channel of ADC and display on LCD with format: &quot;Voltage: xx.xV&quot;. When the voltage \&gt;3V, all LEDs turn on.

- When SW0 and SW1 are on, all LEDs blinks from left to right.

- When SW0 and SW1 are off, turn off.

**LIST OF CONTENTS**

1. Platform design………………………………………………………………......3
2. Quartus…………………………………………………………………………...4
3. Code in Eclipse…………………………………………………………………..5
4. Hardware…………………………………………………………………………9
5. References………………………………………………………………………11

1. **Platform Designer**

We add NIOS II processor, JTAG UART, SystemID, On Chip Memory(IMEM), SDRAM controller, System and SDRAM Clocks for DE-series Board, ADC Controller for DE-series Board, 2 Interval Timer Intel FPGA IP and 3 PIO (for 10 leds, 10 Switch and 16 GPIO to work with LCD).

![](RackMultipart20210616-4-8yw3gy_html_c21a09e26fc51c17.png)

![](RackMultipart20210616-4-8yw3gy_html_f1467704e2b603fc.png)

1. **Q ![](RackMultipart20210616-4-8yw3gy_html_c2b900d71afb1654.png)
 uartus**

In this mini project, we build a microcontroller with Havard architecture which means data and program are stored in separate memory. SDRAM peripheral is used to store data memory. On-Chip Memory is used to store program memory.

- Parallel ports (GPIO): used as output pins to interface with LCD.
- Timers: hardware block that counts clock sequence (0 - 232 ticks) and generate interrupt requests (alarm).
- Ports: A/D Converter available on DE10 Standard board to read value that had been passed through a potentiometer

1. **Eclipse:**

1. **LCD component:**

![](RackMultipart20210616-4-8yw3gy_html_971c7a7d73d1dd6c.png)

![](RackMultipart20210616-4-8yw3gy_html_31e3fcdfea5d081e.png)

We include necessary library and define ADC and SW address.

Based on table 4 of LCD datasheet, from line 13 to 15, we create table[10] contains character code of &quot;HELLOWORLD&quot;, num[12] contains character code of integer number from 0 to 9, floating point symbol(0x2e) and V (it means Voltage unit, 0x56), v[] contains character code of &quot;Voltage: V&quot;.

To achieve LCD display, we not only need to send data but also need to send command to clear display, set the position of the cursor, set entry mode and so on. In general, data or command is read on the falling edge of the enable bit. We can control LCD following these 3 steps:

1. Set Enable to HIGH
2. Set RS and D0 – D7 desired value
3. Set Enable to Low

As a result, we create void SendCommand(), in this function, we enable LCD (bit 8 Enable from 1 to 0 to create falling edge). GPIO\_BASE is the address of LCD.

In SendData function, from line 25 to 28 we enable LCD. Then we set RS to 1, R/W to 0 so that the data is sent over DB0-DB7 will be put in the Data register.

1. **Alarm function**

![](RackMultipart20210616-4-8yw3gy_html_2338e6b72517b004.png)

![](RackMultipart20210616-4-8yw3gy_html_3bb58e8e1fc7f7b7.png)

In this function, we use alarm to blink LCD and led with frequency 1Hz. Variable b at line 41 is declared at line 12, b = 0x0c. Based on table 6 of datasheet, at line &quot;Display on/off control&quot;, we know that SendCommand(0x08)is a function to display off cursor off (clearing display without clearing DDRAM content) and SendCommand(0x08)is a function to display off cursor on. We need to reverse bit D (DB2) to blink LCD. As a result, we use b xor 0x04 to reverse DB2. In case all SW are 0, turn off led and LCD at line 45,46.

This function returns every 0.5 second.

1. **ADC component:**

![](RackMultipart20210616-4-8yw3gy_html_2e74fa254afb6f74.png)

![](RackMultipart20210616-4-8yw3gy_html_c886928d172a4823.png)

![](RackMultipart20210616-4-8yw3gy_html_618b0496a8f39ff7.png)

This function is to read the value of rheostat at channel 2 of ADC block available in DE10 standard board when only SW1 is on. The division function is to classify the value received into units, tens, hundreds, thousands. This helps us display number on LCD more conveniently. We also write delay\_ms function, which delay the program more exactly than using usleep.

We would like to display the value of rheostat at row 2, column 10 of LCD. At this position, its DDRAM is 49 in hexadecimal. To do that, we use SendCommand(0xc9). After putting the position, we display the value on LCD (line 65 to 69). num[c], num[d], num[e], num[f] correspond with the number displayed. num[10] represents floating point symbol.

1. **T ![](RackMultipart20210616-4-8yw3gy_html_557f129543d06785.png)
 he main program**

![](RackMultipart20210616-4-8yw3gy_html_f7319866cc747e16.png)

In main function of this program,

0x38: Function Set: 8-bit, 2 Line, 5x7 Dots. We format LCD display.

0x0F: Display on Cursor blinking. We can see cursor blinks on LCD afetr this code.

0x01: Clear Display (also clear DDRAM content) before working with LCD.

0x83: at row 1, begin at position 3, because we want &quot;HELLOWORLD&quot; appears in the middle of row 1.

Next, we use _for_ loop to send 10 characters of &quot;HELLOWORLD&quot;. Also, the data will be put in the Data register. sendData v[i] to display Voltage: V

SendCommand(0xce): move cursor to row 2, position 16.

SendData(num[11]) display the voltage unit (V)

Finally, we call 2 function explained above to do required task.

1. **Hardware**

**Equipment:**

- Terasic DE10 – Standard FPGA Development Kit
- Potentiometer
- 16x2 LCD Display Module
- Connection wires

![](RackMultipart20210616-4-8yw3gy_html_98b681f65f867146.png)
 ![](RackMultipart20210616-4-8yw3gy_html_3d14399b73a66545.gif) ![](RackMultipart20210616-4-8yw3gy_html_ad448076eac9d382.gif) ![](RackMultipart20210616-4-8yw3gy_html_895e625a34623f5d.gif) ![](RackMultipart20210616-4-8yw3gy_html_2ac16621f083f784.gif) ![](RackMultipart20210616-4-8yw3gy_html_d28bfd595d92eb39.gif) ![](RackMultipart20210616-4-8yw3gy_html_ac38d827f7157d17.gif) ![](RackMultipart20210616-4-8yw3gy_html_891fb18a224940fa.gif) ![](RackMultipart20210616-4-8yw3gy_html_f99a243f1e7aee81.gif) ![](RackMultipart20210616-4-8yw3gy_html_bb851dc2a9775bfc.gif) ![](RackMultipart20210616-4-8yw3gy_html_34dce6f0a59555bf.gif) ![](RackMultipart20210616-4-8yw3gy_html_450d69ae0c38b535.gif) ![](RackMultipart20210616-4-8yw3gy_html_8cce730bc84c1518.gif) ![](RackMultipart20210616-4-8yw3gy_html_835f8e8e858eb55e.gif) ![](RackMultipart20210616-4-8yw3gy_html_d7fa9c3990e96a38.gif) ![](RackMultipart20210616-4-8yw3gy_html_2e12364ec9c00f2.gif) ![](RackMultipart20210616-4-8yw3gy_html_729e0b9fcb1bb4ae.gif) ![](RackMultipart20210616-4-8yw3gy_html_44da60a2181ec9d8.gif) ![](RackMultipart20210616-4-8yw3gy_html_e9a54e4b8feb160a.gif) ![](RackMultipart20210616-4-8yw3gy_html_699272f2c6da0531.gif) ![](RackMultipart20210616-4-8yw3gy_html_59956eb6e18ca8d2.gif) ![](RackMultipart20210616-4-8yw3gy_html_87b38462a1bf2bbb.gif) ![](RackMultipart20210616-4-8yw3gy_html_5a9bb50061b200aa.gif) ![](RackMultipart20210616-4-8yw3gy_html_6b8709ce87af2b90.gif) ![](RackMultipart20210616-4-8yw3gy_html_7300939dba09d0f0.gif) ![](RackMultipart20210616-4-8yw3gy_html_4bd9746ab7f9336b.gif) ![](RackMultipart20210616-4-8yw3gy_html_56fe4827a5ed908.gif) ![](RackMultipart20210616-4-8yw3gy_html_b228b80b23a2e051.gif) ![](RackMultipart20210616-4-8yw3gy_html_1549876dd3e0c712.gif) ![](RackMultipart20210616-4-8yw3gy_html_f9b8e73e3c9e3b27.gif) ![](RackMultipart20210616-4-8yw3gy_html_692a43a31cf59358.gif) ![](RackMultipart20210616-4-8yw3gy_html_ff9d41766a39ea70.gif) ![](RackMultipart20210616-4-8yw3gy_html_58bd4682f02bfa1f.gif) ![](RackMultipart20210616-4-8yw3gy_html_f48474037702c2b5.gif) ![](RackMultipart20210616-4-8yw3gy_html_bae832ec86a3af14.gif) ![](RackMultipart20210616-4-8yw3gy_html_660842c9d78abc69.gif) ![](RackMultipart20210616-4-8yw3gy_html_8feddd7fb45070ed.gif) ![](RackMultipart20210616-4-8yw3gy_html_d233f4f9256455a0.gif) ![](RackMultipart20210616-4-8yw3gy_html_82d96c1e543100f4.gif) ![](RackMultipart20210616-4-8yw3gy_html_f50ba87f812ca713.gif) ![](RackMultipart20210616-4-8yw3gy_html_698415e0675f6e95.gif) ![](RackMultipart20210616-4-8yw3gy_html_826fca6a956f4413.gif) ![](RackMultipart20210616-4-8yw3gy_html_d957f4f26ba6ddf6.gif) ![](RackMultipart20210616-4-8yw3gy_html_8ba3ac51272d653e.gif) ![](RackMultipart20210616-4-8yw3gy_html_a7ce49cbed26b579.gif) ![](RackMultipart20210616-4-8yw3gy_html_105db705a851631c.gif)

![](RackMultipart20210616-4-8yw3gy_html_2edbf4d15d6ee56d.jpg)
 ![](RackMultipart20210616-4-8yw3gy_html_adf0c64de759ac6b.png)
 ![](RackMultipart20210616-4-8yw3gy_html_d42c8dd538bfdd6e.gif) ![](RackMultipart20210616-4-8yw3gy_html_a3e7daae9b30b592.gif) ![](RackMultipart20210616-4-8yw3gy_html_3c3f7da50fa97749.gif) ![](RackMultipart20210616-4-8yw3gy_html_618adfaf45f920f3.gif) ![](RackMultipart20210616-4-8yw3gy_html_2d7bdfe534c2856c.gif) ![](RackMultipart20210616-4-8yw3gy_html_e59b1d47a87a1239.gif) ![](RackMultipart20210616-4-8yw3gy_html_719e9886a84abcf1.gif) ![](RackMultipart20210616-4-8yw3gy_html_e173e144adfd0571.gif) ![](RackMultipart20210616-4-8yw3gy_html_f24d87a69dd36e2a.gif) ![](RackMultipart20210616-4-8yw3gy_html_9d42f468d7632b49.gif) ![](RackMultipart20210616-4-8yw3gy_html_bd11663901181075.gif) ![](RackMultipart20210616-4-8yw3gy_html_1b66761d6205196a.gif)

**REFERENCE**

[1] HD44780U (LCD-II) (Dot Matrix Liquid Crystal Display Controller/Driver)

[2] Experiment 9 Parallel Interfacing: Interfacing LCD Display

[3] Cyclone V Nios II Embedded &quot;Hello World&quot; Lab: Cyclone V E FPGA Development Kit

ii
