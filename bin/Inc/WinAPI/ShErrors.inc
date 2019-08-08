'------------------------------------------------------------------------------
'
'  ShErrors.inc -- error codes specific to shell APIs
'
'  Copyright (c) 2011 PowerBASIC, Inc.
'  Portions Copyright (c) Microsoft Corporation
'  All Rights Reserved.
'
'  Last updated 18 Feb 2011
'
'------------------------------------------------------------------------------
'  from ShErrors.h of 14 Jul 2009
'------------------------------------------------------------------------------

#INCLUDE THIS ONCE

%SHERROR = 1

#INCLUDE ONCE "WinError.inc"

'  COPYENGINE codes use FACILITY_SHELL and 0 in the second lowest byte
' Success/Informational codes
%COPYENGINE_S_YES                         = &H00270001
%COPYENGINE_S_NOT_HANDLED                 = &H00270003
%COPYENGINE_S_USER_RETRY                  = &H00270004
%COPYENGINE_S_USER_IGNORED                = &H00270005
%COPYENGINE_S_MERGE                       = &H00270006
%COPYENGINE_S_DONT_PROCESS_CHILDREN       = &H00270008
%COPYENGINE_S_ALREADY_DONE                = &H0027000A
%COPYENGINE_S_PENDING                     = &H0027000B
%COPYENGINE_S_KEEP_BOTH                   = &H0027000C
%COPYENGINE_S_CLOSE_PROGRAM               = &H0027000D  ' Close the program using the current file
%COPYENGINE_S_COLLISIONRESOLVED           = &H0027000E  ' Returned by a transfer source when a collision occurs
                                                                                ' during a file operation but the source resolved the collision
                                                                                ' on the users behalf

' Failure/Error codes
%COPYENGINE_E_USER_CANCELLED      = &H80270000   ' User wants to canceled entire job
%COPYENGINE_E_CANCELLED           = &H80270001   ' Engine wants to canceled entire job, don't set the CANCELLED bit
%COPYENGINE_E_REQUIRES_ELEVATION  = &H80270002   ' Need to elevate the process to complete the operation

%COPYENGINE_E_SAME_FILE           = &H80270003   ' Source and destination file are the same
%COPYENGINE_E_DIFF_DIR            = &H80270004   ' Trying to rename a file into a different location, use move instead
%COPYENGINE_E_MANY_SRC_1_DEST     = &H80270005   ' One source specified, multiple destinations

%COPYENGINE_E_DEST_SUBTREE        = &H80270009   ' The destination is a sub-tree of the source
%COPYENGINE_E_DEST_SAME_TREE      = &H8027000A   ' The destination is the same folder as the source

%COPYENGINE_E_FLD_IS_FILE_DEST    = &H8027000B   ' Existing destination file with same name as folder
%COPYENGINE_E_FILE_IS_FLD_DEST    = &H8027000C   ' Existing destination folder with same name as file

%COPYENGINE_E_FILE_TOO_LARGE      = &H8027000D   ' File too large for destination file system
%COPYENGINE_E_REMOVABLE_FULL      = &H8027000E   ' Destination device is full and happens to be removable

%COPYENGINE_E_DEST_IS_RO_CD       = &H8027000F   ' Destination is a Read-Only CDRom, possibly unformatted
%COPYENGINE_E_DEST_IS_RW_CD       = &H80270010   ' Destination is a Read/Write CDRom, possibly unformatted
%COPYENGINE_E_DEST_IS_R_CD        = &H80270011   ' Destination is a Recordable (Audio  CDRom, possibly unformatted

%COPYENGINE_E_DEST_IS_RO_DVD      = &H80270012   ' Destination is a Read-Only DVD, possibly unformatted
%COPYENGINE_E_DEST_IS_RW_DVD      = &H80270013   ' Destination is a Read/Wrote DVD, possibly unformatted
%COPYENGINE_E_DEST_IS_R_DVD       = &H80270014   ' Destination is a Recordable (Audio  DVD, possibly unformatted

%COPYENGINE_E_SRC_IS_RO_CD        = &H80270015   ' Source is a Read-Only CDRom, possibly unformatted
%COPYENGINE_E_SRC_IS_RW_CD        = &H80270016   ' Source is a Read/Write CDRom, possibly unformatted
%COPYENGINE_E_SRC_IS_R_CD         = &H80270017   ' Source is a Recordable (Audio  CDRom, possibly unformatted

%COPYENGINE_E_SRC_IS_RO_DVD       = &H80270018   ' Source is a Read-Only DVD, possibly unformatted
%COPYENGINE_E_SRC_IS_RW_DVD       = &H80270019   ' Source is a Read/Wrote DVD, possibly unformatted
%COPYENGINE_E_SRC_IS_R_DVD        = &H8027001A   ' Source is a Recordable (Audio  DVD, possibly unformatted

%COPYENGINE_E_INVALID_FILES_SRC   = &H8027001B   ' Invalid source path
%COPYENGINE_E_INVALID_FILES_DEST  = &H8027001C   ' Invalid destination path
%COPYENGINE_E_PATH_TOO_DEEP_SRC   = &H8027001D   ' Source Files within folders where the overall path is longer than MAX_PATH
%COPYENGINE_E_PATH_TOO_DEEP_DEST  = &H8027001E   ' Destination files would be within folders where the overall path is longer than MAX_PATH
%COPYENGINE_E_ROOT_DIR_SRC        = &H8027001F   ' Source is a root directory, cannot be moved or renamed
%COPYENGINE_E_ROOT_DIR_DEST       = &H80270020   ' Destination is a root directory, cannot be renamed
%COPYENGINE_E_ACCESS_DENIED_SRC   = &H80270021   ' Security problem on source
%COPYENGINE_E_ACCESS_DENIED_DEST  = &H80270022   ' Security problem on destination
%COPYENGINE_E_PATH_NOT_FOUND_SRC  = &H80270023   ' Source file does not exist, or is unavailable
%COPYENGINE_E_PATH_NOT_FOUND_DEST = &H80270024   ' Destination file does not exist, or is unavailable
%COPYENGINE_E_NET_DISCONNECT_SRC  = &H80270025   ' Source file is on a disconnected network location
%COPYENGINE_E_NET_DISCONNECT_DEST        = &H80270026   ' Destination file is on a disconnected network location
%COPYENGINE_E_SHARING_VIOLATION_SRC      = &H80270027   ' Sharing Violation on source
%COPYENGINE_E_SHARING_VIOLATION_DEST     = &H80270028   ' Sharing Violation on destination

%COPYENGINE_E_ALREADY_EXISTS_NORMAL      = &H80270029  ' Destination exists, cannot replace
%COPYENGINE_E_ALREADY_EXISTS_READONLY    = &H8027002A  ' Destination with read-only attribute exists, cannot replace
%COPYENGINE_E_ALREADY_EXISTS_SYSTEM      = &H8027002B  ' Destination with system attribute exists, cannot replace
%COPYENGINE_E_ALREADY_EXISTS_FOLDER      = &H8027002C  ' Destination folder exists, cannot replace
%COPYENGINE_E_STREAM_LOSS                = &H8027002D  ' Secondary Stream information would be lost
%COPYENGINE_E_EA_LOSS                    = &H8027002E  ' Extended Attributes would be lost
%COPYENGINE_E_PROPERTY_LOSS              = &H8027002F  ' Property would be lost
%COPYENGINE_E_PROPERTIES_LOSS            = &H80270030  ' Properties would be lost
%COPYENGINE_E_ENCRYPTION_LOSS            = &H80270031  ' Encryption would be lost
%COPYENGINE_E_DISK_FULL                  = &H80270032  ' Entire operation likely won't fit
%COPYENGINE_E_DISK_FULL_CLEAN            = &H80270033  ' Entire operation likely won't fit, clean-up wizard available
%COPYENGINE_E_EA_NOT_SUPPORTED           = &H80270034  ' Volume does not support Extended Attributes
%COPYENGINE_E_CANT_REACH_SOURCE          = &H80270035  ' Can't reach source folder

%COPYENGINE_E_RECYCLE_UNKNOWN_ERROR      = &H80270035  ' ???
%COPYENGINE_E_RECYCLE_FORCE_NUKE         = &H80270036  ' Recycling not available (usually turned off
%COPYENGINE_E_RECYCLE_SIZE_TOO_BIG       = &H80270037  ' Item is too large for the recycle-bin
%COPYENGINE_E_RECYCLE_PATH_TOO_LONG      = &H80270038  ' Folder is too deep to fit in the recycle-bin
%COPYENGINE_E_RECYCLE_BIN_NOT_FOUND      = &H8027003A  ' Recycle bin could not be found or is unavailable
%COPYENGINE_E_NEWFILE_NAME_TOO_LONG      = &H8027003B  ' Name of the new file being created is too long
%COPYENGINE_E_NEWFOLDER_NAME_TOO_LONG    = &H8027003C  ' Name of the new folder being created is too long
%COPYENGINE_E_DIR_NOT_EMPTY              = &H8027003D  ' The directory being processed is not empty
%COPYENGINE_E_FAT_MAX_IN_ROOT            = &H8027003E  ' A Fat drive cannot only store and rename a limited number of items on the root.
%COPYENGINE_E_ACCESSDENIED_READONLY      = &H8027003F  ' The item cannot be modified because it is set to readonly.

%COPYENGINE_E_REDIRECTED_TO_WEBPAGE      = &H80270040  ' The server redirected the download request to a web page.
%COPYENGINE_E_SERVER_BAD_FILE_TYPE       = &H80270041  ' The server returned data with an unexpected MIME type or extension.

'  error codes without a more specific group use %FACILITY_SHELL and &H01 in the second lowest byte.
%NETCACHE_E_NEGATIVE_CACHE           = &H80270100  ' The item requested is in the negative net parsing cache
%EXECUTE_E_LAUNCH_APPLICATION        = &H80270101  ' for returned by command delegates to indicate that they did no work
%SHELL_E_WRONG_BITDEPTH              = &H80270102  ' returned when trying to create a thumbnail extractor at too low a bitdepth for high fidelity
%LINK_E_DELETE                       = &H80270103  ' returned from IShellLink::Resolve when SLR_OFFER_DELETE_WITHOUT_FILE is passed and the user requested to delete the item

' Library error/failure code
%LIBRARY_E_NO_SAVE_LOCATION          = &H80270200
%LIBRARY_E_NO_ACCESSIBLE_LOCATION    = &H80270201
