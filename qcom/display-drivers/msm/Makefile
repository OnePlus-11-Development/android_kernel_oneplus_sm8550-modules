# SPDX-License-Identifier: GPL-2.0

DISPLAY_SELECT := CONFIG_DRM_MSM=m

KBUILD_EXTRA_SYMBOLS := \
    $(OUT_DIR)/../sm8550-modules/qcom/mm-drivers/hw_fence/Module.symvers \
    $(OUT_DIR)/../sm8550-modules/qcom/mm-drivers/msm_ext_display/Module.symvers \
    $(OUT_DIR)/../sm8550-modules/qcom/mm-drivers/sync_fence/Module.symvers \
    $(OUT_DIR)/../sm8550-modules/qcom/mmrm-driver/Module.symvers \
    $(OUT_DIR)/../sm8550-modules/qcom/securemsm-kernel/Module.symvers

KBUILD_OPTIONS += DISPLAY_ROOT=$(KERNEL_SRC)/$(M)/../
KBUILD_OPTIONS += BOARD_PLATFORM=$(TARGET_BOARD_PLATFORM)
KBUILD_OPTIONS += $(DISPLAY_SELECT)
KBUILD_OPTIONS += $(KBUILD_EXTRA_SYMBOLS)

all: modules

modules_install:
	$(MAKE) INSTALL_MOD_STRIP=1 -C $(KERNEL_SRC) M=$(M) modules_install

%:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) $@ $(KBUILD_OPTIONS)

clean:
	rm -f *.o *.ko *.mod.c *.mod.o *~ .*.cmd Module.symvers
	rm -rf .tmp_versions

