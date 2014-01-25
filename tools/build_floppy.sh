#!/bin/bash

# Create the actual disk image - 20MB
dd if=/dev/zero of=floppy.img count=20 bs=1048576
 
# Make the partition table, partition and set it bootable.
parted --script floppy.img mklabel msdos mkpart p ext2 1 20 set 1 boot on
 
# Map the partitions from the image file
kpartx -a floppy.img
 
# sleep a sec, wait for kpartx to create the device nodes
sleep 1
 
# Make an ext2 filesystem on the first partition.
mkfs.ext2 -L krnl4_boot /dev/mapper/loop1p1
 
# Make the mount-point
mkdir -p tmp/p1
 
# Mount the filesystem via loopback
mount /dev/mapper/loop1p1 tmp/p1

# Create a device map for grub
echo "(hd0) /dev/loop1" > tmp/device.map

# Use grub2-install to actually install Grub. The options are:
#   * No floppy polling.
#   * Use the device map we generated in the previous step.
#   * Include the basic set of modules we need in the Grub image.
#   * Install grub into the filesystem at our loopback mountpoint.
#   * Install the MBR to the loopback device itself.
grub2-install --no-floppy \
              --grub-mkdevicemap=tmp/device.map \
              --modules="biosdisk part_msdos ext2 configfile normal multiboot" \
              --root-directory=tmp/p1 \
              /dev/loop1
 
# Copy grub.cfg
cp `dirname $0`/grub.cfg tmp/p1/boot/grub2/

# Copy in the files from the staging directory
cp -r kernel/krnl4 tmp/p1/boot/

# Unmount the loopback
umount tmp/p1
 
# Unmap the image
kpartx -d floppy.img
 
# hack to make everything owned by the original user, since it will currently be
# owned by root...
LOGNAME=`who am i | awk '{print $1}'`
LOGGROUP=`groups $LOGNAME | awk '{print $3}'`
chown $LOGNAME:$LOGGROUP -R floppy.img

rm -rf tmp

