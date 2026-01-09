🔧 Basic System Calls Required for CVFS

The Customised Virtual File System (CVFS) emulates essential Unix/POSIX system calls to demonstrate how an Operating System manages files internally. These system calls form the primary interface between the user and the virtual file system.

📂 1. creat()

Purpose: Create a new file in the virtual file system.

Description:
  Allocates a new Inode, initializes file metadata (file name, size, permissions), reserves directory space, and returns a File Descriptor. If the file already exists, the call fails.

📂 2. open()

Purpose: Open an existing file.

Description:
  Searches the directory structure for the specified file. If found, an entry is created in the Global File Table, initializing access mode and file offset, and a File Descriptor is returned.

📂 3. close()

Purpose: Close an open file.

Description:
  Releases the file descriptor associated with the file. Updates the process-specific File Descriptor Table and decrements the reference count in the Global File Table.

🗑️ 4. unlink()

Purpose: Delete a file.

Description:
  Removes the filename-to-Inode mapping. Decrements the link count of the Inode. If the link count becomes zero and no file descriptors are open, the system deallocates all associated data blocks.

✍️ 5. write()

Purpose: Write data to a file.

Description:
  Copies data from a user buffer into the virtual disk blocks starting at the current file offset. Automatically allocates new blocks if the file size increases.

📖 6. read()

Purpose: Read data from a file.

Description:
  Retrieves data from the virtual disk blocks into a user buffer beginning at the current file offset. Reading beyond End Of File (EOF) is prevented.

🔁 7. lseek()

Purpose: Change the current file offset.

Description:
  Modifies the read/write pointer based on the specified offset and reference point:

  SEEK_SET → Beginning of file
  SEEK_CUR → Current position
  SEEK_END → End of file

📊 8. stat() / fstat()

Purpose: Retrieve file metadata.

Description:
  Returns information such as file size, permissions, type, and link count without modifying file contents.

📋 9. ls()

Purpose: List files in the virtual directory.

Description:
  Displays all existing files along with metadata such as file size and permissions.

❌ 10. truncate()

Purpose: Resize a file.

Description:
  Adjusts the file size. If the size is reduced, extra data blocks are released. If increased, blocks are allocated.

🧠 Why These System Calls Matter

These system calls collectively demonstrate:

  File lifecycle management
  Memory and block allocation
  Metadata handling using Inodes
  File descriptor and reference counting
  Logical-to-physical address translation

🎯 Summary

These basic system calls replicate how a real Unix kernel manages files, making CVFS an excellent project for understanding Operating System internals and system-level programming.

