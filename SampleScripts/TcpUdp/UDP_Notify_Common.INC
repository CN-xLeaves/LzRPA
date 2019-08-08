  '---Possible messages
  %UDT_Type_Connect     =  10
  %UDT_Type_Disconnect  =  20
  %UDT_Type_Broadcast   =  99
  %UDT_Type_WinSize     = 100

  %UDT_BroadCastType_AskServer        = 1
  %UDT_BroadCastType_ReplyFromServer  = 2
    
  '---Used for broadcasting initial messages
  type tInfo_Broadcast
    ActionType  as integer
    IP          as long
    Port        as long
    hWnd        as long
    sMessage    as string * 32
  end type

  '---Will hold
  type tInfo_HandShake
    ActionType  as integer
    Slot        as integer
    
  end type
  
  '---Will hold window size and position
  type tInfo_WinSize
    hWnd      as long
    x         as integer
    y         as integer
    w         as integer
    h         as integer
  end type
  
  '---This UNION will be used for all kind of message types
  union uInfo
    iWinSize        as tInfo_WinSize
    iWinHandShake   as tInfo_HandShake
    iBroadcast      as tInfo_Broadcast
  end union

  %Stamp_ID = &B1010101010101010
  
  '---This is the real data exchanged by UDP message pump
  '---This structure can contain any of the above messages
  type tUDPInfo
    '---------------------------Header data
    ID        as integer    '---An identifier we can use to mark data as to be used for our purpose and not coming by mistake. See %Stamp_ID
    InfoType  as integer    '---This will drive the kind of data this structure is transporting
    SlotID    AS integer    '---When client connects to the server this is uniquely assigned by the server to each client
    '---------------------------User Data
    InfoData  as uInfo
  end type
