
This project is based of off another GitHub project that can be found here:
  https://github.com/Quarx2k/android_device_lg_w7ds

NOTE:

BoardConfig.mk has been heavily modified.
  
*- All kernel related variables have been removed from BoardConfig.mk and
     are defined in the new LG-4**.mk files.
     
  TARGET_BOARD_MODEL -> ( REQUIRED ) The device model name. If set, this
      value gets appended to the name of the output ROM zip. This value is
      also used to determine which LG-D4XX.mk file to use during the build.
      
  # The following has been moved to the LG-D4**.mk files.
  TARGET_BOARD_USE_DTS -> Is still used but has also been removed from
      BoardConfig.mk. There is no longer a need to set this variable
      as it is set in each LG-D4**.mk file accordingly.


So now to switch builds between devices ::
  - Do some cleanup ( minimal )
      rm -rf $OUT/obj/KERNEL_OBJ
      rm $OUT/system/build.prop
      rm $OUT/*.*
  - Open device/lge/w7/BoardConfig.mk and set the value of TARGET_BOARD_MODEL :=
    to the model you wish to build for. IE; LG-D415, LG-D400n, LG-D410hn.
    Example:
      TARGET_BOARD_MODEL := LG-D410hn
  - Now save the file.
  - Brunch away! 
    
    
