# LG-D400hn dual sim. With NFC and FM radio

TARGET_BOARD_USE_DTS := msm8226-w7dsn_global_sca
TARGET_KERNEL_CONFIG := w7dsn_global_sca_defconfig
TARGET_KERNEL_SOURCE := kernel/lge/msm8226

BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.console=ttyHSL0 user_debug=31 msm_rtb.filter=0x37 androidboot.hardware=w7
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x01000000 --tags_offset 0x00000100

# D400hn Audio
AUDIO_FEATURE_DISABLED_FM := false
BOARD_HAVE_QCOM_FM := true

# D400hn NFC
# Some other custom variables
TARGET_USE_NFC := true

