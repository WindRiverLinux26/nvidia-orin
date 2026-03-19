#
# Copyright (C) 2026 Wind River Systems, Inc.
#

COMPATIBLE_MACHINE:nvidia-orin = "nvidia-orin"

TARGET_SUPPORTED_KTYPES:nvidia-orin = "standard preempt-rt"

KMACHINE:nvidia-orin-agx = "nvidia-orin"
KMACHINE:nvidia-orin-nano = "nvidia-orin"
KMACHINE:nvidia-orin-nx = "nvidia-orin"

KERNEL_DTC_FLAGS:append:nvidia-orin = " -@"

require ${@'recipes-kernel/linux/tegra-kernel.inc' if 'tegra' in d.getVar('MACHINEOVERRIDES').split(':') else ''}

# All of our device trees are out-of-tree
KERNEL_DEVICETREE:forcevariable = ""

SRCREV_machine:nvidia-orin = "${AUTOREV}"
SRCREV_meta:nvidia-orin = "${AUTOREV}"
