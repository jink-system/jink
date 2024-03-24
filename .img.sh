# make img for syslinux

if [ ! -d "img" ]; then
	mkdir -p img
	echo img folder created

	dd if=/dev/zero of=boot.img bs=1M count=20
	mkfs.vfat boot.img
	syslinux boot.img
	mount boot.img img
	cp -rf ./bootloader/syslinux/* ./img/
	umount img
	rmdir img
	echo "img image is finish, try launch it with qemu."
else
	echo "error"
fi
