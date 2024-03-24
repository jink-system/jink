# Script to make sysroot folder.

### Drivers ###

# VGA Driver
mkdir -p sysroot/include/drivers/video/vga/

# PCSpeaker Driver (not implemented)
mkdir -p sysroot/include/drivers/audio/pcspeaker/

### Library ###

# Basics
mkdir -p sysroot/lib

# Kernel Library (not implemented)
mkdir -p sysroot/include/kernel/

# C Standard Libary
# not needed

### Kernel ###

# Kernel image
mkdir -p sysroot/boot

