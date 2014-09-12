# Based on script located at http://wiki.cyanogenmod.org/w/Doc:_dropbear
# relies on busybox (or similar) being installed (with symlinks) and in the path.

# Find the mount point for the /system fs
system_mount_point=$(mount|awk '/system/ {print $1}')
echo ${system_mount_point}

echo "mount -o remount,rw ${system_mount_point} /system"
/system/bin/mount -o remount,rw ${system_mount_point}
echo "root:x:0:0::/data/dropbear:/system/bin/sh" > /etc/passwd
echo "root::14531:0:99999:7:::" > /etc/shadow
echo "root:x:0:" > /etc/group
echo "root:!::" > /etc/gshadow
echo "/system/bin/sh" > /etc/shells
echo "PATH=\"/usr/bin:/usr/sbin:/bin:/sbin:/system/sbin:/system/bin:/system/xbin:/system/xbin/bb:/data/local/bin:/data/busybox\"" > /etc/profile
echo "export PATH" >> /etc/profile
/system/bin/mount -o remount,ro ${system_mount_point}

