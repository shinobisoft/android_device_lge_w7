# Generic w7 device. No NFC. No FM radio

TARGET_BOARD_USE_DTS := msm8226-w7_open_cis
TARGET_KERNEL_CONFIG := w7_open_cis_defconfig
TARGET_KERNEL_SOURCE := kernel/lge/msm8226

BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.console=ttyHSL0 user_debug=31 msm_rtb.filter=0x37 androidboot.hardware=w7
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x01000000 --tags_offset 0x00000100

# D4XX Audio
AUDIO_FEATURE_DISABLED_FM := true
BOARD_HAVE_QCOM_FM := false

# D4XX NFC
# Some other custom variables
TARGET_USE_NFC := false

