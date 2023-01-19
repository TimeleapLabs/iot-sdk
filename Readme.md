# Kenshi Blockchain IoT SDK

Kenshi Blockchain IoT SDK enables receiving and processing blockchain events
on IoT devices. Visit the
[Kenshi IoT documentation](https://kenshi.io/docs/services/iot) to learn more.

## Supported blockchains

Currently Ethereum, BNB Smart Chain, Avalanche, Fantom, Aurora, and Polygon
chains are supported.

## Supported platforms

The Kenshi IoT SDK supports Arduino and ESP32-compatible boards through
the Arduino IDE and ecosystem. All network-enabled boards supported by
[Zephyr](https://docs.zephyrproject.org/latest/boards/index.html) are supported
by this SDK. Check the official Kenshi Deep Index MQL/GraphQL
[documentation](https://kenshi.io/docs/services/deep-index)
for Linux development boards.

## Examples

- [Blinky](./arduino/examples/blinky/): Blink a LED trigerred by a blockchain event,
  for Arduino MKR WiFi. Example can be easily adapted to other Arduino boards.
- [Blinky32](./arduino/examples/blinky32/): Blinky example for ESP32
- [Zephyr app](./zephyr/src/app/): Zephyr sample project setup

### Supported development boards

The following boards and platforms are supported by this SDK:

#### ESP32 product family

All boards based on the ESP32 SoC and programmable by Arduino IDE, including:

- [ESP32 Devkits](https://www.espressif.com/en/products/devkits)
- [Adafruit HUZZAH32](https://learn.adafruit.com/adafruit-huzzah32-esp32-feather)
- [SparkFun ESP32 Thing Plus](https://www.sparkfun.com/products/15663)
- [Wemos LOLIN D32](https://www.wemos.cc/en/latest/d32/d32.html)
- [Seeed Studio XIAO ESP32C3](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)
- [DFRobot FireBeetle ESP32](<https://wiki.dfrobot.com/FireBeetle_ESP32_IOT_Microcontroller(V3.0)__Supports_Wi-Fi_&_Bluetooth__SKU__DFR0478>)

and others.

#### Arduino product family

Any board with internet connectivity supported by one of the libraries below:

- [WiFiNINA](https://github.com/arduino-libraries/WiFiNINA):
  - [Arduino MKR WiFi 1010](https://docs.arduino.cc/hardware/mkr-wifi-1010)
  - [Arduino MKR VIDOR 4000](https://docs.arduino.cc/hardware/mkr-vidor-4000)
  - [Arduino UNO WiFi Rev.2](https://docs.arduino.cc/hardware/uno-wifi-rev2)
  - [Arduino Nano 33 IoT](https://docs.arduino.cc/hardware/nano-33-iot)
  - [Arduino Nano RP2040 Connect](https://docs.arduino.cc/hardware/nano-rp2040-connect)
- [WiFi101](https://github.com/arduino-libraries/WiFi101):
  - [Arduino MKR1000 WiFi](https://docs.arduino.cc/hardware/mkr-1000-wifi)
  - [Arduino/Genuino Wifi Shield 101](https://docs.arduino.cc/retired/getting-started-guides/ArduinoWiFiShield101)
- [Ethernet](https://github.com/arduino-libraries/Ethernet):
  - [Arduino Ethernet Board](https://docs.arduino.cc/retired/boards/arduino-ethernet-rev3-without-poe)
  - [Arduino Ethernet Shield](https://docs.arduino.cc/retired/getting-started-guides/ArduinoEthernetShield)
- [MKRGSM](https://github.com/arduino-libraries/MKRGSM):
  - [Arduino MKR GSM 1400](https://docs.arduino.cc/hardware/mkr-gsm-1400)
- [MKRNB](https://github.com/arduino-libraries/MKRNB):
  - [Arduino MKR NB 1500](https://docs.arduino.cc/hardware/mkr-nb-1500)
- [WiFi](https://github.com/arduino-libraries/WiFi):
  - [Arduino WiFi Shield](https://docs.arduino.cc/retired/getting-started-guides/ArduinoWiFiShield)
- [GSM](https://github.com/arduino-libraries/GSM):
  - [Arduino GSM Shield](https://docs.arduino.cc/retired/getting-started-guides/ArduinoGSMShield)

#### Zephyr boards

The following boards are supported using the Zephyr RTOS:

- [Elkhart Lake CRB](https://docs.zephyrproject.org/latest/boards/x86/ehl_crb/doc/index.html)
- [X86 Emulation (QEMU)](https://docs.zephyrproject.org/latest/boards/x86/qemu_x86/doc/index.html)
- [Raptor Lake CRB](https://docs.zephyrproject.org/latest/boards/x86/rpl_crb/doc/index.html)
- [UP Squared](https://docs.zephyrproject.org/latest/boards/x86/up_squared/doc/index.html)
- [96Boards Aerocore2](https://docs.zephyrproject.org/latest/boards/arm/96b_aerocore2/doc/index.html)
- [96Boards Avenger96](https://docs.zephyrproject.org/latest/boards/arm/96b_avenger96/doc/index.html)
- [96Boards Carbon](https://docs.zephyrproject.org/latest/boards/arm/96b_carbon/doc/index.html)
- [96Boards Meerkat96](https://docs.zephyrproject.org/latest/boards/arm/96b_meerkat96/doc/index.html)
- [Actinius Icarus](https://docs.zephyrproject.org/latest/boards/arm/actinius_icarus/doc/index.html)
- [Actinius Icarus Bee](https://docs.zephyrproject.org/latest/boards/arm/actinius_icarus_bee/doc/index.html)
- [Actinius Icarus SoM](https://docs.zephyrproject.org/latest/boards/arm/actinius_icarus_som/doc/index.html)
- [Arduino Nano 33 IOT](https://docs.zephyrproject.org/latest/boards/arm/arduino_nano_33_iot/doc/index.html)
- [SAM E54 Xplained Pro Evaluation Kit](https://docs.zephyrproject.org/latest/boards/arm/atsame54_xpro/doc/index.html)
- [ST B-G474E-DPOW1 Discovery](https://docs.zephyrproject.org/latest/boards/arm/b_g474e_dpow1/doc/index.html)
- [ST B_L4S5I_IOT01A Discovery kit](https://docs.zephyrproject.org/latest/boards/arm/b_l4s5i_iot01a/doc/index.html)
- [ST B_U585I_IOT02A Discovery kit](https://docs.zephyrproject.org/latest/boards/arm/b_u585i_iot02a/doc/index.html)
- [Laird Connectivity BL5340 DVK](https://docs.zephyrproject.org/latest/boards/arm/bl5340_dvk/doc/index.html)
- [Black STM32 F407VE Development Board](https://docs.zephyrproject.org/latest/boards/arm/black_f407ve/doc/index.html)
- [Black STM32 F407ZG Pro Development Board](https://docs.zephyrproject.org/latest/boards/arm/black_f407zg_pro/doc/index.html)
- [CC3220SF LaunchXL](https://docs.zephyrproject.org/latest/boards/arm/cc3220sf_launchxl/doc/index.html)
- [CC3235SF LaunchXL](https://docs.zephyrproject.org/latest/boards/arm/cc3235sf_launchxl/doc/index.html)
- [nRF9160 Feather](https://docs.zephyrproject.org/latest/boards/arm/circuitdojo_feather_nrf9160/doc/index.html)
- [NXP i.MX 7 Computer on Module - Colibri iMX7](https://docs.zephyrproject.org/latest/boards/arm/colibri_imx7d_m4/doc/index.html)
- [PSoC6 WiFi-BT Pioneer Kit](https://docs.zephyrproject.org/latest/boards/arm/cy8ckit_062_wifi_bt/doc/index.html)
- [Intel® Cyclone® V SoC Development Kit](https://docs.zephyrproject.org/latest/boards/arm/cyclonev_socdk/doc/index.html)
- [ST Disco L475 IOT01 (B-L475E-IOT01A)](https://docs.zephyrproject.org/latest/boards/arm/disco_l475_iot1/doc/index.html)
- [Dragino NBSN95 NB-IoT Sensor Node](https://docs.zephyrproject.org/latest/boards/arm/dragino_nbsn95/doc/index.html)
- [WGM160P Starter Kit](https://docs.zephyrproject.org/latest/boards/arm/efm32gg_slwstk6121a/doc/index.html)
- [EFM32 Giant Gecko GG11 Starter Kit](https://docs.zephyrproject.org/latest/boards/arm/efm32gg_stk3701a/doc/index.html)
- [EFR32 Radio Boards](https://docs.zephyrproject.org/latest/boards/arm/efr32_radio/doc/index.html)
- [NXP FRDM-K64F](https://docs.zephyrproject.org/latest/boards/arm/frdm_k64f/doc/index.html)
- [GigaDevice GD32E507Z-EVAL](https://docs.zephyrproject.org/latest/boards/arm/gd32e507z_eval/doc/index.html)
- [GigaDevice GD32F450I-EVAL](https://docs.zephyrproject.org/latest/boards/arm/gd32f450i_eval/doc/index.html)
- [GigaDevice GD32F450Z-EVAL](https://docs.zephyrproject.org/latest/boards/arm/gd32f450z_eval/doc/index.html)
- [GigaDevice GD32F470I-EVAL](https://docs.zephyrproject.org/latest/boards/arm/gd32f470i_eval/doc/index.html)
- [Google Kukui EC](https://docs.zephyrproject.org/latest/boards/arm/google_kukui/doc/index.html)
- [Hexiwear](https://docs.zephyrproject.org/latest/boards/arm/hexiwear_k64/doc/index.html)
- [SEGGER IP Switch Board](https://docs.zephyrproject.org/latest/boards/arm/ip_k66f/doc/index.html)
- [Legend](https://docs.zephyrproject.org/latest/boards/arm/legend/doc/index.html)
- [Laird Connectivity Sentrius™ MG100 Gateway](https://docs.zephyrproject.org/latest/boards/arm/mg100/doc/index.html)
- [NXP MIMX8MM EVK](https://docs.zephyrproject.org/latest/boards/arm/mimx8mm_evk/doc/index.html)
- [NXP MIMX8MP EVK](https://docs.zephyrproject.org/latest/boards/arm/mimx8mp_evk/doc/index.html)
- [NXP MIMX8MQ EVK](https://docs.zephyrproject.org/latest/boards/arm/mimx8mq_evk/doc/index.html)
- [NXP MIMXRT1020-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1020_evk/doc/index.html)
- [NXP MIMXRT1024-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1024_evk/doc/index.html)
- [NXP MIMXRT1050-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1050_evk/doc/index.html)
- [NXP MIMXRT1060-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1060_evk/doc/index.html)
- [NXP MIMXRT1064-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1064_evk/doc/index.html)
- [NXP MIMXRT1160-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1160_evk/doc/index.html)
- [NXP MIMXRT1170-EVK](https://docs.zephyrproject.org/latest/boards/arm/mimxrt1170_evk/doc/index.html)
- [ARM MPS2+ AN521](https://docs.zephyrproject.org/latest/boards/arm/mps2_an521/doc/index.html)
- [ARM MPS3 AN547](https://docs.zephyrproject.org/latest/boards/arm/mps3_an547/doc/index.html)
- [nRF52840 MDK USB Dongle](https://docs.zephyrproject.org/latest/boards/arm/nrf52840_mdk_usb_dongle/doc/index.html)
- [nRF5340 DK](https://docs.zephyrproject.org/latest/boards/arm/nrf5340dk_nrf5340/doc/index.html)
- [nRF9160 INNBLUE21](https://docs.zephyrproject.org/latest/boards/arm/nrf9160_innblue21/doc/index.html)
- [nRF9160 INNBLUE22](https://docs.zephyrproject.org/latest/boards/arm/nrf9160_innblue22/doc/index.html)
- [nRF9160 DK](https://docs.zephyrproject.org/latest/boards/arm/nrf9160dk_nrf9160/doc/index.html)
- [ST Nucleo F030R8](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f030r8/doc/index.html)
- [ST Nucleo F031K6](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f031k6/doc/index.html)
- [ST Nucleo F070RB](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f070rb/doc/index.html)
- [ST Nucleo F091RC](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f091rc/doc/index.html)
- [ST Nucleo F103RB](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f103rb/doc/index.html)
- [ST Nucleo F207ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f207zg/doc/index.html)
- [ST Nucleo F334R8](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f334r8/doc/index.html)
- [ST Nucleo F412ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f412zg/doc/index.html)
- [ST Nucleo F429ZI](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f429zi/doc/index.html)
- [ST Nucleo F746ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f746zg/doc/index.html)
- [ST Nucleo F756ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f756zg/doc/index.html)
- [ST Nucleo F767ZI](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f767zi/doc/index.html)
- [ST Nucleo G031K8](https://docs.zephyrproject.org/latest/boards/arm/nucleo_g031k8/doc/index.html)
- [ST Nucleo G071RB](https://docs.zephyrproject.org/latest/boards/arm/nucleo_g071rb/doc/index.html)
- [ST Nucleo G0B1RE](https://docs.zephyrproject.org/latest/boards/arm/nucleo_g0b1re/doc/index.html)
- [ST Nucleo H723ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_h723zg/doc/index.html)
- [ST Nucleo H743ZI](https://docs.zephyrproject.org/latest/boards/arm/nucleo_h743zi/doc/index.html)
- [ST Nucleo H745ZI-Q](https://docs.zephyrproject.org/latest/boards/arm/nucleo_h745zi_q/doc/index.html)
- [ST Nucleo H753ZI](https://docs.zephyrproject.org/latest/boards/arm/nucleo_h753zi/doc/index.html)
- [ST Nucleo L011K4](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l011k4/doc/index.html)
- [ST Nucleo L031K6](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l031k6/doc/index.html)
- [ST Nucleo L053R8](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l053r8/doc/index.html)
- [ST Nucleo L073RZ](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l073rz/doc/index.html)
- [ST Nucleo L152RE](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l152re/doc/index.html)
- [ST Nucleo L476RG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l476rg/doc/index.html)
- [ST Nucleo L496ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l496zg/doc/index.html)
- [ST Nucleo L4A6ZG](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l4a6zg/doc/index.html)
- [ST Nucleo L4R5ZI](https://docs.zephyrproject.org/latest/boards/arm/nucleo_l4r5zi/doc/index.html)
- [NUVOTON NUMAKER PFM M487](https://docs.zephyrproject.org/latest/boards/arm/nuvoton_pfm_m487/doc/index.html)
- [Particle Argon](https://docs.zephyrproject.org/latest/boards/arm/particle_argon/doc/index.html)
- [Particle Boron](https://docs.zephyrproject.org/latest/boards/arm/particle_boron/doc/index.html)
- [Laird Connectivity Pinnacle 100 DVK](https://docs.zephyrproject.org/latest/boards/arm/pinnacle_100_dvk/doc/index.html)
- [ARM Cortex-M3 Emulation (QEMU)](https://docs.zephyrproject.org/latest/boards/arm/qemu_cortex_m3/doc/index.html)
- [RAK5010](https://docs.zephyrproject.org/latest/boards/arm/rak5010_nrf52840/doc/index.html)
- [NXP RDDRONE-FMUK66](https://docs.zephyrproject.org/latest/boards/arm/rddrone_fmuk66/doc/index.html)
- [reel board](https://docs.zephyrproject.org/latest/boards/arm/reel_board/doc/index.html)
- [SAM4E Xplained Pro](https://docs.zephyrproject.org/latest/boards/arm/sam4e_xpro/doc/index.html)
- [SAM E70(B) Xplained](https://docs.zephyrproject.org/latest/boards/arm/sam_e70_xplained/doc/index.html)
- [SAM V71(B) Xplained Ultra](https://docs.zephyrproject.org/latest/boards/arm/sam_v71_xult/doc/index.html)
- [ST SensorTile.box](https://docs.zephyrproject.org/latest/boards/arm/sensortile_box/doc/index.html)
- [nRF9160 Thing Plus](https://docs.zephyrproject.org/latest/boards/arm/sparkfun_thing_plus_nrf9160/doc/index.html)
- [ST STM3210C Evaluation](https://docs.zephyrproject.org/latest/boards/arm/stm3210c_eval/doc/index.html)
- [ST STM32373C Evaluation](https://docs.zephyrproject.org/latest/boards/arm/stm32373c_eval/doc/index.html)
- [ST STM32F0 Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32f0_disco/doc/index.html)
- [STM32F103 Mini](https://docs.zephyrproject.org/latest/boards/arm/stm32f103_mini/doc/index.html)
- [SECO JUNO SBC-D23 (STM32F302)](https://docs.zephyrproject.org/latest/boards/arm/stm32f3_seco_d23/doc/index.html)
- [ST STM32F429I Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32f429i_disc1/doc/index.html)
- [ST STM32F469I Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32f469i_disco/doc/index.html)
- [ST STM32F4 Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32f4_disco/doc/index.html)
- [ST STM32F746G Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32f746g_disco/doc/index.html)
- [ST STM32F7508-DK Discovery Kit](https://docs.zephyrproject.org/latest/boards/arm/stm32f7508_dk/doc/index.html)
- [ST STM32F769I Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32f769i_disco/doc/index.html)
- [ST STM32G071B Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32g071b_disco/doc/index.html)
- [ST STM32G081B Evaluation](https://docs.zephyrproject.org/latest/boards/arm/stm32g081b_eval/doc/index.html)
- [ST STM32H735G Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32h735g_disco/doc/index.html)
- [ST STM32H747I Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32h747i_disco/doc/index.html)
- [ST STM32L1 Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32l1_disco/doc/index.html)
- [ST STM32L476G Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32l476g_disco/doc/index.html)
- [ST STM32L496G Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32l496g_disco/doc/index.html)
- [ST STM32L562E-DK Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32l562e_dk/doc/index.html)
- [ST STM32VL Discovery](https://docs.zephyrproject.org/latest/boards/arm/stm32vl_disco/doc/index.html)
- [PJRC TEENSY 4](https://docs.zephyrproject.org/latest/boards/arm/teensy4/doc/index.html)
- [NXP TWR-KV58F220M](https://docs.zephyrproject.org/latest/boards/arm/twr_kv58f220m/doc/index.html)
- [UDOO Neo Full](https://docs.zephyrproject.org/latest/boards/arm/udoo_neo_full_m4/doc/index.html)
- [ARM V2M Musca-S1](https://docs.zephyrproject.org/latest/boards/arm/v2m_musca_s1/doc/index.html)
- [WaRP7 - Next Generation IoT and Wearable Development Platform](https://docs.zephyrproject.org/latest/boards/arm/warp7_m4/doc/index.html)
- [Intel Agilex SoC Development Kit](https://docs.zephyrproject.org/latest/boards/arm64/intel_socfpga_agilex_socdk/doc/index.html)
- [NXP i.MX8MM EVK (Cortex-A53)](https://docs.zephyrproject.org/latest/boards/arm64/mimx8mm_evk/doc/index.html)
- [NXP i.MX8MN EVK (Cortex-A53)](https://docs.zephyrproject.org/latest/boards/arm64/mimx8mn_evk/doc/index.html)
- [NXP i.MX8MP EVK (Cortex-A53)](https://docs.zephyrproject.org/latest/boards/arm64/mimx8mp_evk/doc/index.html)
- [NXP i.MX93 EVK (Cortex-A55)](https://docs.zephyrproject.org/latest/boards/arm64/mimx93_evk/doc/index.html)
- [NXP LS1046A RDB](https://docs.zephyrproject.org/latest/boards/arm64/nxp_ls1046ardb/doc/index.html)
- [ARMv8 Xen Virtual Machine Example](https://docs.zephyrproject.org/latest/boards/arm64/xenvm/doc/index.html)
- [DesignWare(R) ARC(R) HS Development Kit](https://docs.zephyrproject.org/latest/boards/arc/hsdk/doc/index.html)
- [ARCv2 & ARCv3 Emulation (QEMU)](https://docs.zephyrproject.org/latest/boards/arc/qemu_arc/doc/index.html)
- [Altera MAX10](https://docs.zephyrproject.org/latest/boards/nios2/altera_max10/doc/index.html)
- [Altera Nios-II Emulation (QEMU)](https://docs.zephyrproject.org/latest/boards/nios2/qemu_nios2/doc/index.html)
- [ESP32](https://docs.zephyrproject.org/latest/boards/xtensa/esp32/doc/index.html)
- [ESP32-ETHERNET-KIT](https://docs.zephyrproject.org/latest/boards/xtensa/esp32_ethernet_kit/doc/index.html)
- [ESP32-NET](https://docs.zephyrproject.org/latest/boards/xtensa/esp32_net/doc/index.html)
- [ESP32-S2 Franzininho](https://docs.zephyrproject.org/latest/boards/xtensa/esp32s2_franzininho/doc/index.html)
- [ESP32-S2](https://docs.zephyrproject.org/latest/boards/xtensa/esp32s2_saola/doc/index.html)
- [ESP-WROVER-KIT](https://docs.zephyrproject.org/latest/boards/xtensa/esp_wrover_kit/doc/index.html)
- [Heltec WiFi LoRa 32 (V2)](https://docs.zephyrproject.org/latest/boards/xtensa/heltec_wifi_lora32_v2/doc/index.html)
- [Zephyr Audio DSP Development on Chromebooks](https://docs.zephyrproject.org/latest/boards/xtensa/intel_adsp_cavs25/doc/index.html)
- [M5StickC PLUS](https://docs.zephyrproject.org/latest/boards/xtensa/m5stickc_plus/doc/index.html)
- [ODROID-GO](https://docs.zephyrproject.org/latest/boards/xtensa/odroid_go/doc/index.html)
- [Olimex ESP32-EVB](https://docs.zephyrproject.org/latest/boards/xtensa/olimex_esp32_evb/doc/index.html)
- [Native POSIX execution (native_posix)](https://docs.zephyrproject.org/latest/boards/posix/native_posix/doc/index.html)
- [Andes ADP-XC7K AE350](https://docs.zephyrproject.org/latest/boards/riscv/adp_xc7k_ae350/doc/index.html)
- [ESP32-C3](https://docs.zephyrproject.org/latest/boards/riscv/esp32c3_devkitm/doc/index.html)
- [ICE-V Wireless](https://docs.zephyrproject.org/latest/boards/riscv/icev_wireless/doc/index.html)
- [OpenISA VEGAboard](https://docs.zephyrproject.org/latest/boards/riscv/rv32m1_vega/doc/index.html)
- [M5Stack STAMP-C3](https://docs.zephyrproject.org/latest/boards/riscv/stamp_c3/doc/index.html)
- [XIAO ESP32C3](https://docs.zephyrproject.org/latest/boards/riscv/xiao_esp32c3/doc/index.html)
- [Generic LEON3](https://docs.zephyrproject.org/latest/boards/sparc/generic_leon3/doc/index.html)
- [Adafruit WINC1500 Wifi Shield](https://docs.zephyrproject.org/latest/boards/shields/adafruit_winc1500/doc/index.html)
- [ARCELI W5500 ETH](https://docs.zephyrproject.org/latest/boards/shields/arceli_eth_w5500/doc/index.html)
- [Atmel AT86RF2XX Transceivers](https://docs.zephyrproject.org/latest/boards/shields/atmel_rf2xx/doc/index.html)
- [ESP-8266 Modules](https://docs.zephyrproject.org/latest/boards/shields/esp_8266/doc/index.html)
- [Inventek es-WIFI Shield](https://docs.zephyrproject.org/latest/boards/shields/inventek_eswifi/doc/index.html)
- [PHYTEC link board ETH](https://docs.zephyrproject.org/latest/boards/shields/link_board_eth/doc/index.html)
- [Microchip MCP2515 CAN bus shields](https://docs.zephyrproject.org/latest/boards/shields/mcp2515/doc/index.html)
- [MikroElektronika ETH Click](https://docs.zephyrproject.org/latest/boards/shields/mikroe_eth_click/doc/index.html)
- [MikroElektronika WIFI and BLE Shield](https://docs.zephyrproject.org/latest/boards/shields/mikroe_wifi_bt_click/doc/index.html)
- [X-NUCLEO-IDB05A1: BLE expansion board](https://docs.zephyrproject.org/latest/boards/shields/x_nucleo_idb05a1/doc/index.html)

See more on the [Zephyr documentation](https://docs.zephyrproject.org/latest/boards/index.html).

### Linux/BSD/Windows boards

All boards running a variant of Linux, BSD or Windows are supported:

- [Raspberry Pi](https://www.raspberrypi.org/)
- [Nvidia Jetson](https://www.nvidia.com/en-us/autonomous-machines/embedded-systems/)
- [ASUS Tinker Board](https://www.asus.com/us/networking-iot-servers/aiot-industrial-solutions/tinker-board-series/tinker-board/)
- [BeagleBoard/BeagleBone](https://www.beagleboard.org/)
- [Hardkernel/ODRIOD](https://www.hardkernel.com/)
- [Pine64](https://www.pine64.org/)
- [Banana Pi](https://www.banana-pi.org/)
- [Orange Pi](https://orangepi.com/)
- [Rock Pi](https://rockpi.org/)
- [LattePanda](https://www.lattepanda.com/)
- [Libre Computer/Le Potato](https://libre.computer/)

## License

All libraries are released under Apache-2.0 license. The Zephyr library uses and distributes
[cJSON](https://github.com/DaveGamble/cJSON), which is released under MIT.
