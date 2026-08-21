# Readboy C13 firmware

Extracted from the Readboy C13 system and Bluetooth partitions through recovery ADB.

## Layout

- gpu/: Adreno A530 firmware
- wifi-bluetooth/: QCA6174/Rome Bluetooth and WLAN firmware
- audio/: AW881xx/AW8898 amplifier and DBMD8 voice firmware
- camera/: Qualcomm camera CPP firmware
- config/: WCNSS WLAN configuration

## Runtime paths

These files normally belong under /system/etc/firmware, /system/etc/wifi, or the Bluetooth firmware partition image, depending on the vendor init scripts and driver version. They are device firmware blobs, not kernel source, and should only be redistributed with the device vendor permission.
