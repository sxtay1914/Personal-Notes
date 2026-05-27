Chapter 15 Storage media
## Commands
1. mount 
2. umount: unmount
3. fsck: file system check, test & repair 
4. fdisk: manipulate disk partition
5. genisoimage: generate ISO image
6. md5sum 

￼
* /dev/sda1 is device file associated with physical device, however one physical device can have different device file depending on hardware detection order, thus need UUID to correctly identify. 

## Linux Storage Device Names
* /dev/hda1 refers to 1st partition on first hard drive
* /dev/hda refers to entire drive

￼
## How to view log message?
* linux: tail -f /var/log/messages 
* mac: log stream

## How to see disk storage space?
* df -h 

## Creating filesys
* sudo mkfs -t ext4 /dev/sdb1
    * -t specifies the type

## Moving data between devices:
* dd (data definition)
    * cannot dd dir because dd works on raw byte stream not filesys dir structure

## Create CD-ROM image
What is ISO: snapshot of filesys

## Mounting iso directly from hard disk
* mount -o loop 
    * tells linux to treat the file as a virtual block device

## Erase disk 
* wodim dev= blank=fast
****
