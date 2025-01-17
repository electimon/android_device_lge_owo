#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# Platform
TARGET_BOARD_PLATFORM := msm8610

# Common specific options in device_owo.mk
-include device/lge/uwuowo-common/BoardConfigCommon.mk

# Vendor Init
TARGET_INIT_VENDOR_LIB := libinit_owo
TARGET_OTA_ASSERT_DEVICE := w5c

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := owo

# Kernel
BOARD_CUSTOM_BOOTIMG_MK := device/lge/owo/mkbootimg.mk
TARGET_KERNEL_SOURCE := kernel/lge/realm
TARGET_KERNEL_CONFIG := w5c_defconfig

# Filesystem,
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_BOOTIMAGE_PARTITION_SIZE     := 0x00D00000
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 0x00D00000
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 609996800
BOARD_CACHEIMAGE_PARTITION_SIZE    := 314572800
BOARD_PERSISTIMAGE_PARTITION_SIZE  := 33554432
