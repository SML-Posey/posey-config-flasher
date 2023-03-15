#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <string.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/storage/flash_map.h>
#include <zephyr/fs/nvs.h>

#include "BoardConfigs.h"

static struct nvs_fs fs;

#define NVS_PARTITION			storage_partition
#define NVS_PARTITION_DEVICE	FIXED_PARTITION_DEVICE(NVS_PARTITION)
#define NVS_PARTITION_OFFSET	FIXED_PARTITION_OFFSET(NVS_PARTITION)

#define NAME_ID 1
#define ROLE_ID 2
#define HW_ID 3
#define SW_ID 4
#define DATETIME_ID 5

void main(void)
{
	int rc = 0;
	char buf[30];
	struct flash_pages_info info;

	struct BoardConfig brd;
	if (!get_board_config(brd_r2_Tulip, &brd))
	{
		printk("Invalid board config");
		return;
	}

	const bool reset = false;

	fs.flash_device = NVS_PARTITION_DEVICE;
	if (!device_is_ready(fs.flash_device)) {
		printk("Flash device %s is not ready\n", fs.flash_device->name);
		return;
	}
	fs.offset = NVS_PARTITION_OFFSET;
	rc = flash_get_page_info_by_offs(fs.flash_device, fs.offset, &info);
	if (rc) {
		printk("Unable to get page info\n");
		return;
	}
	fs.sector_size = info.size;
	fs.sector_count = 3U;

	rc = nvs_mount(&fs);
	if (rc) {
		printk("Flash Init failed\n");
		return;
	}

	bool write;

	if (reset)
	{
		printk("Old flash entries will be deleted.\n");
		(void)nvs_delete(&fs, NAME_ID);
		(void)nvs_delete(&fs, ROLE_ID);
		(void)nvs_delete(&fs, HW_ID);
		(void)nvs_delete(&fs, SW_ID);
		(void)nvs_delete(&fs, DATETIME_ID);
	}

	rc = nvs_read(&fs, NAME_ID, &buf, sizeof(buf));
	if (rc > 0) {
		printk("Name: %s\n", buf);
		write = strcmp(buf, brd.name) != 0;
	} else {
		printk("Name not found.");
		write = true;
	}
	if (write) {
		printk("  -> Writing %s\n", brd.name);
		(void)nvs_write(&fs, NAME_ID, brd.name, strlen(brd.name)+1);
	}

	rc = nvs_read(&fs, ROLE_ID, &buf, sizeof(buf));
	if (rc > 0) {
		printk("Role: %s\n", buf);
		write = strcmp(buf, brd.role) != 0;
	} else {
		printk("Role not found.");
		write = true;
	}
	if (write) {
		printk("  -> Writing %s\n", brd.role);
		(void)nvs_write(&fs, ROLE_ID, brd.role, strlen(brd.role)+1);
	}

	rc = nvs_read(&fs, HW_ID, &buf, sizeof(buf));
	if (rc > 0) {
		printk("HW: %s\n", buf);
		write = strcmp(buf, brd.hw) != 0;
	} else {
		printk("HW not found.");
		write = true;
	}
	if (write) {
		printk("  -> Writing %s\n", brd.hw);
		(void)nvs_write(&fs, HW_ID, brd.hw, strlen(brd.hw)+1);
	}

	rc = nvs_read(&fs, SW_ID, &buf, sizeof(buf));
	if (rc > 0) {
		printk("SW: %s\n", buf);
		write = strcmp(buf, brd.sw) != 0;
	} else {
		printk("SW not found.");
		write = true;
	}
	if (write) {
		printk("  -> Writing %s\n", brd.sw);
		(void)nvs_write(&fs, SW_ID, brd.sw, strlen(brd.sw)+1);
	}

	rc = nvs_read(&fs, DATETIME_ID, &buf, sizeof(buf));
	if (rc > 0) {
		printk("Date/time: %s\n", buf);
		write = strcmp(buf, brd.dt) != 0;
	} else {
		printk("Date/time not found.");
		write = true;
	}
	if (write) {
		printk("  -> Writing %s\n", brd.dt);
		(void)nvs_write(&fs, DATETIME_ID, brd.dt, strlen(brd.dt)+1);
	}
}
