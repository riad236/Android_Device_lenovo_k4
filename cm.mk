# Release name
PRODUCT_RELEASE_NAME := a7010a48

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/lenovo/a7010a48/device_a7010a48.mk)

# Configure dalvik heap
$(call inherit-product, frameworks/native/build/phone-xxxhdpi-3072-dalvik-heap.mk)

# Configure hwui memory
$(call inherit-product, frameworks/native/build/phone-xxxhdpi-3072-hwui-memory.mk)

TARGET_SCREEN_HEIGHT := 1920
TARGET_SCREEN_WIDTH := 1080

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := a7010a48
PRODUCT_NAME := cm_a7010a48
PRODUCT_BRAND := lenovo
PRODUCT_MODEL := a7010a48
PRODUCT_MANUFACTURER := lenovo
