# Common settings for BSP machine.conf

DEFAULTTUNE ?= "armv8a-crc"
require ${@bb.utils.contains('BUILD_NVIDIA_PROPRIETARY_PACKAGE', '1', \
			     '', 'conf/machine/include/arm/arch-armv8-2a.inc', d)}

MACHINE_FEATURES ??= "alsa usbhost pci rtc ext2 wifi bluetooth"

KERNEL_IMAGETYPE ?= "Image"

SERIAL_CONSOLES ??= "115200;ttyTCU0"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-yocto"
PREFERRED_VERSION_linux-yocto ?= "6.18%"
PREFERRED_VERSION_linux-yocto-rt ?= "6.18%"

MACHINE_EXTRA_RRECOMMENDS:append = " kernel-modules linux-firmware-rtl8822 kernel-module-rtw88-8822ce kernel-module-rtk-btusb kernel-module-snd-soc-rl6231 kernel-module-snd-soc-rt5640"
IMAGE_FSTYPES += "tar.bz2 ext4"
IMAGE_INSTALL:append = " kernel-image-image"

MACHINEOVERRIDES:append = ":nvidia-orin"

# If enable reduntant flash layout, L4TConfiguration-RootfsRedundancyLevelABEnable.dtbo will be installed
USE_REDUNDANT_FLASH_LAYOUT_DEFAULT ?= "1"

ASSUME_PROVIDED += "${@bb.utils.contains('BUILD_NVIDIA_PROPRIETARY_PACKAGE', '1', \
	'', 'virtual/bootloader', d)}"
OSTREE_SD_UBOOT_WIC1 = ""
