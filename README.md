jfs
===

A simple filesystem intended for use with a bootloader.

The basic data structures involved are inode, directory and dirent. These form a cycle, with directories containing several dirents, each dirent pointing at an inode, and the inode corresponding to a directory points at the directory.





Implementation Notes
====================
I will start by using CHS addressing, but should switch to LBA at a later date.
All metadata will be stored in the first few sectors of the disk. For now, sectors that have been released will not be reusable.
