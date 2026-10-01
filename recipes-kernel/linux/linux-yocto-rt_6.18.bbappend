require linux-yocto-nvidia-orin.inc

KBRANCH:nvidia-orin = "v6.18/standard/preempt-rt/base"

# Replaces the masked meta-tegra -rt bbappend. Reverts the SAUCE realtime
# sysfs patch preempt-rt already has; must stay after the patch queues.
KERNEL_FEATURES:append:nvidia-orin = " features/tegra/rt-compat.scc"
