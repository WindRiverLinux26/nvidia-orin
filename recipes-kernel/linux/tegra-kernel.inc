#
# SoC config lives in the tegra-kernel-cache kmeta, vendored locally into
# this layer at tegra-kmeta/{bsp,cfg,features} (no git fetch, no network
# required). cfg/tegra.cfg provides shared SoC config; cfg/jetson-devkit.cfg
# adds devkit peripherals -- mirrors meta-tegra's linux-yocto-tegra.inc but
# scoped to nvidia-orin without switching KMACHINE.
#

FILESEXTRAPATHS:prepend := "${THISDIR}:"

SRC_URI:append:nvidia-orin = " \
    file://tegra-kmeta;type=kmeta \
"

KERNEL_FEATURES_EXTRA_DEVKIT ?= "features/tegra/jetson-devkit.scc"

KERNEL_FEATURES:append:nvidia-orin = " \
    features/tegra/tegra-board-features.scc \
    features/tegra/tegra-patches.scc \
    features/tegra/tegra-distro.scc \
    ${KERNEL_FEATURES_EXTRA_DEVKIT} \
"
