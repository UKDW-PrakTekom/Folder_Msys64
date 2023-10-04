/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _MCIAPI_H_
#define _MCIAPI_H_

#include <apiset.h>
#include <apisetcconv.h>

#include <mmsyscom.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifndef _MCIERROR_
#define _MCIERROR_
typedef DWORD MCIERROR;
#endif

#ifndef _MCIDEVICEID_
#define _MCIDEVICEID_
typedef UINT  MCIDEVICEID;
#endif

typedef UINT (CALLBACK *YIELDPROC)(MCIDEVICEID mciId, DWORD dwYieldData);

WINMMAPI MCIERROR WINAPI mciSendCommandA(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
WINMMAPI MCIERROR WINAPI mciSendCommandW(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
#define mciSendCommand __MINGW_NAME_AW(mciSendCommand)

WINMMAPI MCIERROR WINAPI mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
WINMMAPI MCIERROR WINAPI mciSendStringW(LPCWSTR lpstrCommand, LPWSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback);
#define mciSendString __MINGW_NAME_AW(mciSendString)

WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDA(LPCSTR pszDevice);
WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDW(LPCWSTR pszDevice);
#define mciGetDeviceID __MINGW_NAME_AW(mciGetDeviceID)

WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDA(DWORD dwElementID, LPCSTR lpstrType);
WINMMAPI MCIDEVICEID WINAPI mciGetDeviceIDFromElementIDW(DWORD dwElementID, LPCWSTR lpstrType);
#define mciGetDeviceIDFromElementID __MINGW_NAME_AW(mciGetDeviceIDFromElementID)

WINMMAPI WINBOOL WINAPI mciGetErrorStringA(MCIERROR mcierr, LPSTR pszText, UINT cchText);
WINMMAPI WINBOOL WINAPI mciGetErrorStringW(MCIERROR mcierr, LPWSTR pszText, UINT cchText);
#define mciGetErrorString __MINGW_NAME_AW(mciGetErrorString)

WINMMAPI WINBOOL WINAPI mciSetYieldProc(MCIDEVICEID mciId, YIELDPROC fpYieldProc, DWORD dwYieldData);

WINMMAPI HTASK WINAPI mciGetCreatorTask(MCIDEVICEID mciId);
WINMMAPI YIELDPROC WINAPI mciGetYieldProc(MCIDEVICEID mciId, LPDWORD pdwYieldData);

WINMMAPI WINBOOL WINAPI mciExecute(LPCSTR pszCommand);

#define MCIERR_INVALID_DEVICE_ID (MCIERR_BASE + 1)
#define MCIERR_UNRECOGNIZED_KEYWORD (MCIERR_BASE + 3)
#define MCIERR_UNRECOGNIZED_COMMAND (MCIERR_BASE + 5)
#define MCIERR_HARDWARE (MCIERR_BASE + 6)
#define MCIERR_INVALID_DEVICE_NAME (MCIERR_BASE + 7)
#define MCIERR_OUT_OF_MEMORY (MCIERR_BASE + 8)
#define MCIERR_DEVICE_OPEN (MCIERR_BASE + 9)
#define MCIERR_CANNOT_LOAD_DRIVER (MCIERR_BASE + 10)
#define MCIERR_MISSING_COMMAND_STRING (MCIERR_BASE + 11)
#define MCIERR_PARAM_OVERFLOW (MCIERR_BASE + 12)
#define MCIERR_MISSING_STRING_ARGUMENT (MCIERR_BASE + 13)
#define MCIERR_BAD_INTEGER (MCIERR_BASE + 14)
#define MCIERR_PARSER_INTERNAL (MCIERR_BASE + 15)
#define MCIERR_DRIVER_INTERNAL (MCIERR_BASE + 16)
#define MCIERR_MISSING_PARAMETER (MCIERR_BASE + 17)
#define MCIERR_UNSUPPORTED_FUNCTION (MCIERR_BASE + 18)
#define MCIERR_FILE_NOT_FOUND (MCIERR_BASE + 19)
#define MCIERR_DEVICE_NOT_READY (MCIERR_BASE + 20)
#define MCIERR_INTERNAL (MCIERR_BASE + 21)
#define MCIERR_DRIVER (MCIERR_BASE + 22)
#define MCIERR_CANNOT_USE_ALL (MCIERR_BASE + 23)
#define MCIERR_MULTIPLE (MCIERR_BASE + 24)
#define MCIERR_EXTENSION_NOT_FOUND (MCIERR_BASE + 25)
#define MCIERR_OUTOFRANGE (MCIERR_BASE + 26)
#define MCIERR_FLAGS_NOT_COMPATIBLE (MCIERR_BASE + 28)
#define MCIERR_FILE_NOT_SAVED (MCIERR_BASE + 30)
#define MCIERR_DEVICE_TYPE_REQUIRED (MCIERR_BASE + 31)
#define MCIERR_DEVICE_LOCKED (MCIERR_BASE + 32)
#define MCIERR_DUPLICATE_ALIAS (MCIERR_BASE + 33)
#define MCIERR_BAD_CONSTANT (MCIERR_BASE + 34)
#define MCIERR_MUST_USE_SHAREABLE (MCIERR_BASE + 35)
#define MCIERR_MISSING_DEVICE_NAME (MCIERR_BASE + 36)
#define MCIERR_BAD_TIME_FORMAT (MCIERR_BASE + 37)
#define MCIERR_NO_CLOSING_QUOTE (MCIERR_BASE + 38)
#define MCIERR_DUPLICATE_FLAGS (MCIERR_BASE + 39)
#define MCIERR_INVALID_FILE (MCIERR_BASE + 40)
#define MCIERR_NULL_PARAMETER_BLOCK (MCIERR_BASE + 41)
#define MCIERR_UNNAMED_RESOURCE (MCIERR_BASE + 42)
#define MCIERR_NEW_REQUIRES_ALIAS (MCIERR_BASE + 43)
#define MCIERR_NOTIFY_ON_AUTO_OPEN (MCIERR_BASE + 44)
#define MCIERR_NO_ELEMENT_ALLOWED (MCIERR_BASE + 45)
#define MCIERR_NONAPPLICABLE_FUNCTION (MCIERR_BASE + 46)
#define MCIERR_ILLEGAL_FOR_AUTO_OPEN (MCIERR_BASE + 47)
#define MCIERR_FILENAME_REQUIRED (MCIERR_BASE + 48)
#define MCIERR_EXTRA_CHARACTERS (MCIERR_BASE + 49)
#define MCIERR_DEVICE_NOT_INSTALLED (MCIERR_BASE + 50)
#define MCIERR_GET_CD (MCIERR_BASE + 51)
#define MCIERR_SET_CD (MCIERR_BASE + 52)
#define MCIERR_SET_DRIVE (MCIERR_BASE + 53)
#define MCIERR_DEVICE_LENGTH (MCIERR_BASE + 54)
#define MCIERR_DEVICE_ORD_LENGTH (MCIERR_BASE + 55)
#define MCIERR_NO_INTEGER (MCIERR_BASE + 56)

#define MCIERR_WAVE_OUTPUTSINUSE (MCIERR_BASE + 64)
#define MCIERR_WAVE_SETOUTPUTINUSE (MCIERR_BASE + 65)
#define MCIERR_WAVE_INPUTSINUSE (MCIERR_BASE + 66)
#define MCIERR_WAVE_SETINPUTINUSE (MCIERR_BASE + 67)
#define MCIERR_WAVE_OUTPUTUNSPECIFIED (MCIERR_BASE + 68)
#define MCIERR_WAVE_INPUTUNSPECIFIED (MCIERR_BASE + 69)
#define MCIERR_WAVE_OUTPUTSUNSUITABLE (MCIERR_BASE + 70)
#define MCIERR_WAVE_SETOUTPUTUNSUITABLE (MCIERR_BASE + 71)
#define MCIERR_WAVE_INPUTSUNSUITABLE (MCIERR_BASE + 72)
#define MCIERR_WAVE_SETINPUTUNSUITABLE (MCIERR_BASE + 73)

#define MCIERR_SEQ_DIV_INCOMPATIBLE (MCIERR_BASE + 80)
#define MCIERR_SEQ_PORT_INUSE (MCIERR_BASE + 81)
#define MCIERR_SEQ_PORT_NONEXISTENT (MCIERR_BASE + 82)
#define MCIERR_SEQ_PORT_MAPNODEVICE (MCIERR_BASE + 83)
#define MCIERR_SEQ_PORT_MISCERROR (MCIERR_BASE + 84)
#define MCIERR_SEQ_TIMER (MCIERR_BASE + 85)
#define MCIERR_SEQ_PORTUNSPECIFIED (MCIERR_BASE + 86)
#define MCIERR_SEQ_NOMIDIPRESENT (MCIERR_BASE + 87)

#define MCIERR_NO_WINDOW (MCIERR_BASE + 90)
#define MCIERR_CREATEWINDOW (MCIERR_BASE + 91)
#define MCIERR_FILE_READ (MCIERR_BASE + 92)
#define MCIERR_FILE_WRITE (MCIERR_BASE + 93)

#define MCIERR_NO_IDENTITY (MCIERR_BASE + 94)

#define MCIERR_CUSTOM_DRIVER_BASE (MCIERR_BASE + 256)

#define MCI_FIRST DRV_MCI_FIRST

#define MCI_OPEN 0x0803
#define MCI_CLOSE 0x0804
#define MCI_ESCAPE 0x0805
#define MCI_PLAY 0x0806
#define MCI_SEEK 0x0807
#define MCI_STOP 0x0808
#define MCI_PAUSE 0x0809
#define MCI_INFO 0x080A
#define MCI_GETDEVCAPS 0x080B
#define MCI_SPIN 0x080C
#define MCI_SET 0x080D
#define MCI_STEP 0x080E
#define MCI_RECORD 0x080F
#define MCI_SYSINFO 0x0810
#define MCI_BREAK 0x0811
#define MCI_SAVE 0x0813
#define MCI_STATUS 0x0814
#define MCI_CUE 0x0830
#define MCI_REALIZE 0x0840
#define MCI_WINDOW 0x0841
#define MCI_PUT 0x0842
#define MCI_WHERE 0x0843
#define MCI_FREEZE 0x0844
#define MCI_UNFREEZE 0x0845
#define MCI_LOAD 0x0850
#define MCI_CUT 0x0851
#define MCI_COPY 0x0852
#define MCI_PASTE 0x0853
#define MCI_UPDATE 0x0854
#define MCI_RESUME 0x0855
#define MCI_DELETE 0x0856

#define MCI_USER_MESSAGES (DRV_MCI_FIRST + 0x400)
#define MCI_LAST 0x0FFF

#define MCI_ALL_DEVICE_ID ((MCIDEVICEID)-1)

#define MCI_DEVTYPE_VCR 513
#define MCI_DEVTYPE_VIDEODISC 514
#define MCI_DEVTYPE_OVERLAY 515
#define MCI_DEVTYPE_CD_AUDIO 516
#define MCI_DEVTYPE_DAT 517
#define MCI_DEVTYPE_SCANNER 518
#define MCI_DEVTYPE_ANIMATION 519
#define MCI_DEVTYPE_DIGITAL_VIDEO 520
#define MCI_DEVTYPE_OTHER 521
#define MCI_DEVTYPE_WAVEFORM_AUDIO 522
#define MCI_DEVTYPE_SEQUENCER 523

#define MCI_DEVTYPE_FIRST MCI_DEVTYPE_VCR
#define MCI_DEVTYPE_LAST MCI_DEVTYPE_SEQUENCER

#define MCI_DEVTYPE_FIRST_USER 0x1000

#define MCI_MODE_NOT_READY (MCI_STRING_OFFSET + 12)
#define MCI_MODE_STOP (MCI_STRING_OFFSET + 13)
#define MCI_MODE_PLAY (MCI_STRING_OFFSET + 14)
#define MCI_MODE_RECORD (MCI_STRING_OFFSET + 15)
#define MCI_MODE_SEEK (MCI_STRING_OFFSET + 16)
#define MCI_MODE_PAUSE (MCI_STRING_OFFSET + 17)
#define MCI_MODE_OPEN (MCI_STRING_OFFSET + 18)

#define MCI_FORMAT_MILLISECONDS 0
#define MCI_FORMAT_HMS 1
#define MCI_FORMAT_MSF 2
#define MCI_FORMAT_FRAMES 3
#define MCI_FORMAT_SMPTE_24 4
#define MCI_FORMAT_SMPTE_25 5
#define MCI_FORMAT_SMPTE_30 6
#define MCI_FORMAT_SMPTE_30DROP 7
#define MCI_FORMAT_BYTES 8
#define MCI_FORMAT_SAMPLES 9
#define MCI_FORMAT_TMSF 10

#define MCI_MSF_MINUTE(msf) ((BYTE)(msf))
#define MCI_MSF_SECOND(msf) ((BYTE)(((WORD)(msf)) >> 8))
#define MCI_MSF_FRAME(msf) ((BYTE)((msf)>>16))

#define MCI_MAKE_MSF(m, s, f) ((DWORD)(((BYTE)(m) | ((WORD)(s)<<8)) | (((DWORD)(BYTE)(f))<<16)))

#define MCI_TMSF_TRACK(tmsf) ((BYTE)(tmsf))
#define MCI_TMSF_MINUTE(tmsf) ((BYTE)(((WORD)(tmsf)) >> 8))
#define MCI_TMSF_SECOND(tmsf) ((BYTE)((tmsf)>>16))
#define MCI_TMSF_FRAME(tmsf) ((BYTE)((tmsf)>>24))

#define MCI_MAKE_TMSF(t, m, s, f) ((DWORD)(((BYTE)(t) | ((WORD)(m)<<8)) | (((DWORD)(BYTE)(s) | ((WORD)(f)<<8))<<16)))

#define MCI_HMS_HOUR(hms) ((BYTE)(hms))
#define MCI_HMS_MINUTE(hms) ((BYTE)(((WORD)(hms)) >> 8))
#define MCI_HMS_SECOND(hms) ((BYTE)((hms)>>16))

#define MCI_MAKE_HMS(h, m, s) ((DWORD)(((BYTE)(h) | ((WORD)(m)<<8)) | (((DWORD)(BYTE)(s))<<16)))

#define MCI_NOTIFY_SUCCESSFUL 0x0001
#define MCI_NOTIFY_SUPERSEDED 0x0002
#define MCI_NOTIFY_ABORTED 0x0004
#define MCI_NOTIFY_FAILURE 0x0008

#define MCI_NOTIFY __MSABI_LONG(0x00000001)
#define MCI_WAIT __MSABI_LONG(0x00000002)
#define MCI_FROM __MSABI_LONG(0x00000004)
#define MCI_TO __MSABI_LONG(0x00000008)
#define MCI_TRACK __MSABI_LONG(0x00000010)

#define MCI_OPEN_SHAREABLE __MSABI_LONG(0x00000100)
#define MCI_OPEN_ELEMENT __MSABI_LONG(0x00000200)
#define MCI_OPEN_ALIAS __MSABI_LONG(0x00000400)
#define MCI_OPEN_ELEMENT_ID __MSABI_LONG(0x00000800)
#define MCI_OPEN_TYPE_ID __MSABI_LONG(0x00001000)
#define MCI_OPEN_TYPE __MSABI_LONG(0x00002000)

#define MCI_SEEK_TO_START __MSABI_LONG(0x00000100)
#define MCI_SEEK_TO_END __MSABI_LONG(0x00000200)

#define MCI_STATUS_ITEM __MSABI_LONG(0x00000100)
#define MCI_STATUS_START __MSABI_LONG(0x00000200)

#define MCI_STATUS_LENGTH __MSABI_LONG(0x00000001)
#define MCI_STATUS_POSITION __MSABI_LONG(0x00000002)
#define MCI_STATUS_NUMBER_OF_TRACKS __MSABI_LONG(0x00000003)
#define MCI_STATUS_MODE __MSABI_LONG(0x00000004)
#define MCI_STATUS_MEDIA_PRESENT __MSABI_LONG(0x00000005)
#define MCI_STATUS_TIME_FORMAT __MSABI_LONG(0x00000006)
#define MCI_STATUS_READY __MSABI_LONG(0x00000007)
#define MCI_STATUS_CURRENT_TRACK __MSABI_LONG(0x00000008)

#define MCI_INFO_PRODUCT __MSABI_LONG(0x00000100)
#define MCI_INFO_FILE __MSABI_LONG(0x00000200)
#define MCI_INFO_MEDIA_UPC __MSABI_LONG(0x00000400)
#define MCI_INFO_MEDIA_IDENTITY __MSABI_LONG(0x00000800)
#define MCI_INFO_NAME __MSABI_LONG(0x00001000)
#define MCI_INFO_COPYRIGHT __MSABI_LONG(0x00002000)

#define MCI_GETDEVCAPS_ITEM __MSABI_LONG(0x00000100)

#define MCI_GETDEVCAPS_CAN_RECORD __MSABI_LONG(0x00000001)
#define MCI_GETDEVCAPS_HAS_AUDIO __MSABI_LONG(0x00000002)
#define MCI_GETDEVCAPS_HAS_VIDEO __MSABI_LONG(0x00000003)
#define MCI_GETDEVCAPS_DEVICE_TYPE __MSABI_LONG(0x00000004)
#define MCI_GETDEVCAPS_USES_FILES __MSABI_LONG(0x00000005)
#define MCI_GETDEVCAPS_COMPOUND_DEVICE __MSABI_LONG(0x00000006)
#define MCI_GETDEVCAPS_CAN_EJECT __MSABI_LONG(0x00000007)
#define MCI_GETDEVCAPS_CAN_PLAY __MSABI_LONG(0x00000008)
#define MCI_GETDEVCAPS_CAN_SAVE __MSABI_LONG(0x00000009)

#define MCI_SYSINFO_QUANTITY __MSABI_LONG(0x00000100)
#define MCI_SYSINFO_OPEN __MSABI_LONG(0x00000200)
#define MCI_SYSINFO_NAME __MSABI_LONG(0x00000400)
#define MCI_SYSINFO_INSTALLNAME __MSABI_LONG(0x00000800)

#define MCI_SET_DOOR_OPEN __MSABI_LONG(0x00000100)
#define MCI_SET_DOOR_CLOSED __MSABI_LONG(0x00000200)
#define MCI_SET_TIME_FORMAT __MSABI_LONG(0x00000400)
#define MCI_SET_AUDIO __MSABI_LONG(0x00000800)
#define MCI_SET_VIDEO __MSABI_LONG(0x00001000)
#define MCI_SET_ON __MSABI_LONG(0x00002000)
#define MCI_SET_OFF __MSABI_LONG(0x00004000)

#define MCI_SET_AUDIO_ALL __MSABI_LONG(0x00000000)
#define MCI_SET_AUDIO_LEFT __MSABI_LONG(0x00000001)
#define MCI_SET_AUDIO_RIGHT __MSABI_LONG(0x00000002)

#define MCI_BREAK_KEY __MSABI_LONG(0x00000100)
#define MCI_BREAK_HWND __MSABI_LONG(0x00000200)
#define MCI_BREAK_OFF __MSABI_LONG(0x00000400)

#define MCI_RECORD_INSERT __MSABI_LONG(0x00000100)
#define MCI_RECORD_OVERWRITE __MSABI_LONG(0x00000200)

#define MCI_SAVE_FILE __MSABI_LONG(0x00000100)

#define MCI_LOAD_FILE __MSABI_LONG(0x00000100)

typedef struct tagMCI_GENERIC_PARMS {
  DWORD_PTR dwCallback;
} MCI_GENERIC_PARMS, *PMCI_GENERIC_PARMS, *LPMCI_GENERIC_PARMS;

typedef struct tagMCI_OPEN_PARMSA {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCSTR lpstrDeviceType;
  LPCSTR lpstrElementName;
  LPCSTR lpstrAlias;
} MCI_OPEN_PARMSA, *PMCI_OPEN_PARMSA, *LPMCI_OPEN_PARMSA;

typedef struct tagMCI_OPEN_PARMSW {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCWSTR lpstrDeviceType;
  LPCWSTR lpstrElementName;
  LPCWSTR lpstrAlias;
} MCI_OPEN_PARMSW, *PMCI_OPEN_PARMSW, *LPMCI_OPEN_PARMSW;

__MINGW_TYPEDEF_AW(MCI_OPEN_PARMS)
__MINGW_TYPEDEF_AW(PMCI_OPEN_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_OPEN_PARMS)

typedef struct tagMCI_PLAY_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrom;
  DWORD dwTo;
} MCI_PLAY_PARMS, *PMCI_PLAY_PARMS, *LPMCI_PLAY_PARMS;

typedef struct tagMCI_SEEK_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwTo;
} MCI_SEEK_PARMS, *PMCI_SEEK_PARMS, *LPMCI_SEEK_PARMS;

typedef struct tagMCI_STATUS_PARMS {
  DWORD_PTR dwCallback;
  DWORD_PTR dwReturn;
  DWORD dwItem;
  DWORD dwTrack;
} MCI_STATUS_PARMS, *PMCI_STATUS_PARMS, *LPMCI_STATUS_PARMS;

typedef struct tagMCI_INFO_PARMSA {
  DWORD_PTR dwCallback;
  LPSTR lpstrReturn;
  DWORD dwRetSize;
} MCI_INFO_PARMSA, *LPMCI_INFO_PARMSA;

typedef struct tagMCI_INFO_PARMSW {
  DWORD_PTR dwCallback;
  LPWSTR  lpstrReturn;
  DWORD   dwRetSize;
} MCI_INFO_PARMSW, *LPMCI_INFO_PARMSW;

__MINGW_TYPEDEF_AW(MCI_INFO_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_INFO_PARMS)

typedef struct tagMCI_GETDEVCAPS_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwReturn;
  DWORD dwItem;
} MCI_GETDEVCAPS_PARMS, *PMCI_GETDEVCAPS_PARMS, *LPMCI_GETDEVCAPS_PARMS;

typedef struct tagMCI_SYSINFO_PARMSA {
  DWORD_PTR dwCallback;
  LPSTR lpstrReturn;
  DWORD dwRetSize;
  DWORD dwNumber;
  UINT wDeviceType;
} MCI_SYSINFO_PARMSA, *PMCI_SYSINFO_PARMSA, *LPMCI_SYSINFO_PARMSA;

typedef struct tagMCI_SYSINFO_PARMSW {
  DWORD_PTR dwCallback;
  LPWSTR lpstrReturn;
  DWORD dwRetSize;
  DWORD dwNumber;
  UINT wDeviceType;
} MCI_SYSINFO_PARMSW, *PMCI_SYSINFO_PARMSW, *LPMCI_SYSINFO_PARMSW;

__MINGW_TYPEDEF_AW(MCI_SYSINFO_PARMS)
__MINGW_TYPEDEF_AW(PMCI_SYSINFO_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_SYSINFO_PARMS)

typedef struct tagMCI_SET_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwTimeFormat;
  DWORD dwAudio;
} MCI_SET_PARMS, *PMCI_SET_PARMS, *LPMCI_SET_PARMS;

typedef struct tagMCI_BREAK_PARMS {
  DWORD_PTR dwCallback;
  int nVirtKey;
  HWND hwndBreak;
} MCI_BREAK_PARMS, *PMCI_BREAK_PARMS, *LPMCI_BREAK_PARMS;

typedef struct tagMCI_SAVE_PARMSA {
  DWORD_PTR dwCallback;
  LPCSTR lpfilename;
} MCI_SAVE_PARMSA, *PMCI_SAVE_PARMSA, *LPMCI_SAVE_PARMSA;

typedef struct tagMCI_SAVE_PARMSW {
  DWORD_PTR dwCallback;
  LPCWSTR lpfilename;
} MCI_SAVE_PARMSW, *PMCI_SAVE_PARMSW, *LPMCI_SAVE_PARMSW;

__MINGW_TYPEDEF_AW(MCI_SAVE_PARMS)
__MINGW_TYPEDEF_AW(PMCI_SAVE_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_SAVE_PARMS)

typedef struct tagMCI_LOAD_PARMSA {
  DWORD_PTR dwCallback;
  LPCSTR lpfilename;
} MCI_LOAD_PARMSA, *PMCI_LOAD_PARMSA, *LPMCI_LOAD_PARMSA;

typedef struct tagMCI_LOAD_PARMSW {
  DWORD_PTR dwCallback;
  LPCWSTR lpfilename;
} MCI_LOAD_PARMSW, *PMCI_LOAD_PARMSW, *LPMCI_LOAD_PARMSW;

__MINGW_TYPEDEF_AW(MCI_LOAD_PARMS)
__MINGW_TYPEDEF_AW(PMCI_LOAD_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_LOAD_PARMS)

typedef struct tagMCI_RECORD_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrom;
  DWORD dwTo;
} MCI_RECORD_PARMS, *LPMCI_RECORD_PARMS;

#define MCI_VD_MODE_PARK (MCI_VD_OFFSET + 1)

#define MCI_VD_MEDIA_CLV (MCI_VD_OFFSET + 2)
#define MCI_VD_MEDIA_CAV (MCI_VD_OFFSET + 3)
#define MCI_VD_MEDIA_OTHER (MCI_VD_OFFSET + 4)

#define MCI_VD_FORMAT_TRACK 0x4001

#define MCI_VD_PLAY_REVERSE __MSABI_LONG(0x00010000)
#define MCI_VD_PLAY_FAST __MSABI_LONG(0x00020000)
#define MCI_VD_PLAY_SPEED __MSABI_LONG(0x00040000)
#define MCI_VD_PLAY_SCAN __MSABI_LONG(0x00080000)
#define MCI_VD_PLAY_SLOW __MSABI_LONG(0x00100000)

#define MCI_VD_SEEK_REVERSE __MSABI_LONG(0x00010000)

#define MCI_VD_STATUS_SPEED __MSABI_LONG(0x00004002)
#define MCI_VD_STATUS_FORWARD __MSABI_LONG(0x00004003)
#define MCI_VD_STATUS_MEDIA_TYPE __MSABI_LONG(0x00004004)
#define MCI_VD_STATUS_SIDE __MSABI_LONG(0x00004005)
#define MCI_VD_STATUS_DISC_SIZE __MSABI_LONG(0x00004006)

#define MCI_VD_GETDEVCAPS_CLV __MSABI_LONG(0x00010000)
#define MCI_VD_GETDEVCAPS_CAV __MSABI_LONG(0x00020000)

#define MCI_VD_SPIN_UP __MSABI_LONG(0x00010000)
#define MCI_VD_SPIN_DOWN __MSABI_LONG(0x00020000)

#define MCI_VD_GETDEVCAPS_CAN_REVERSE __MSABI_LONG(0x00004002)
#define MCI_VD_GETDEVCAPS_FAST_RATE __MSABI_LONG(0x00004003)
#define MCI_VD_GETDEVCAPS_SLOW_RATE __MSABI_LONG(0x00004004)
#define MCI_VD_GETDEVCAPS_NORMAL_RATE __MSABI_LONG(0x00004005)

#define MCI_VD_STEP_FRAMES __MSABI_LONG(0x00010000)
#define MCI_VD_STEP_REVERSE __MSABI_LONG(0x00020000)

#define MCI_VD_ESCAPE_STRING __MSABI_LONG(0x00000100)

typedef struct tagMCI_VD_PLAY_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrom;
  DWORD dwTo;
  DWORD dwSpeed;
} MCI_VD_PLAY_PARMS, *PMCI_VD_PLAY_PARMS, *LPMCI_VD_PLAY_PARMS;

typedef struct tagMCI_VD_STEP_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrames;
} MCI_VD_STEP_PARMS, *PMCI_VD_STEP_PARMS, *LPMCI_VD_STEP_PARMS;

typedef struct tagMCI_VD_ESCAPE_PARMSA {
  DWORD_PTR dwCallback;
  LPCSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMSA, *PMCI_VD_ESCAPE_PARMSA, *LPMCI_VD_ESCAPE_PARMSA;

typedef struct tagMCI_VD_ESCAPE_PARMSW {
  DWORD_PTR dwCallback;
  LPCWSTR lpstrCommand;
} MCI_VD_ESCAPE_PARMSW, *PMCI_VD_ESCAPE_PARMSW, *LPMCI_VD_ESCAPE_PARMSW;

__MINGW_TYPEDEF_AW(MCI_VD_ESCAPE_PARMS)
__MINGW_TYPEDEF_AW(PMCI_VD_ESCAPE_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_VD_ESCAPE_PARMS)

#define MCI_CDA_STATUS_TYPE_TRACK __MSABI_LONG(0x00004001)

#define MCI_CDA_TRACK_AUDIO (MCI_CD_OFFSET + 0)
#define MCI_CDA_TRACK_OTHER (MCI_CD_OFFSET + 1)

#define MCI_WAVE_PCM (MCI_WAVE_OFFSET + 0)
#define MCI_WAVE_MAPPER (MCI_WAVE_OFFSET + 1)

#define MCI_WAVE_OPEN_BUFFER __MSABI_LONG(0x00010000)

#define MCI_WAVE_SET_FORMATTAG __MSABI_LONG(0x00010000)
#define MCI_WAVE_SET_CHANNELS __MSABI_LONG(0x00020000)
#define MCI_WAVE_SET_SAMPLESPERSEC __MSABI_LONG(0x00040000)
#define MCI_WAVE_SET_AVGBYTESPERSEC __MSABI_LONG(0x00080000)
#define MCI_WAVE_SET_BLOCKALIGN __MSABI_LONG(0x00100000)
#define MCI_WAVE_SET_BITSPERSAMPLE __MSABI_LONG(0x00200000)

#define MCI_WAVE_INPUT __MSABI_LONG(0x00400000)
#define MCI_WAVE_OUTPUT __MSABI_LONG(0x00800000)

#define MCI_WAVE_STATUS_FORMATTAG __MSABI_LONG(0x00004001)
#define MCI_WAVE_STATUS_CHANNELS __MSABI_LONG(0x00004002)
#define MCI_WAVE_STATUS_SAMPLESPERSEC __MSABI_LONG(0x00004003)
#define MCI_WAVE_STATUS_AVGBYTESPERSEC __MSABI_LONG(0x00004004)
#define MCI_WAVE_STATUS_BLOCKALIGN __MSABI_LONG(0x00004005)
#define MCI_WAVE_STATUS_BITSPERSAMPLE __MSABI_LONG(0x00004006)
#define MCI_WAVE_STATUS_LEVEL __MSABI_LONG(0x00004007)

#define MCI_WAVE_SET_ANYINPUT __MSABI_LONG(0x04000000)
#define MCI_WAVE_SET_ANYOUTPUT __MSABI_LONG(0x08000000)

#define MCI_WAVE_GETDEVCAPS_INPUTS __MSABI_LONG(0x00004001)
#define MCI_WAVE_GETDEVCAPS_OUTPUTS __MSABI_LONG(0x00004002)

typedef struct tagMCI_WAVE_OPEN_PARMSA {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCSTR lpstrDeviceType;
  LPCSTR lpstrElementName;
  LPCSTR lpstrAlias;
  DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSA, *PMCI_WAVE_OPEN_PARMSA, *LPMCI_WAVE_OPEN_PARMSA;

typedef struct tagMCI_WAVE_OPEN_PARMSW {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCWSTR lpstrDeviceType;
  LPCWSTR lpstrElementName;
  LPCWSTR lpstrAlias;
  DWORD dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSW, *PMCI_WAVE_OPEN_PARMSW, *LPMCI_WAVE_OPEN_PARMSW;

__MINGW_TYPEDEF_AW(MCI_WAVE_OPEN_PARMS)
__MINGW_TYPEDEF_AW(PMCI_WAVE_OPEN_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_WAVE_OPEN_PARMS)

typedef struct tagMCI_WAVE_DELETE_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrom;
  DWORD dwTo;
} MCI_WAVE_DELETE_PARMS, *PMCI_WAVE_DELETE_PARMS, *LPMCI_WAVE_DELETE_PARMS;

typedef struct tagMCI_WAVE_SET_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwTimeFormat;
  DWORD dwAudio;
  UINT wInput;
  UINT wOutput;
  WORD wFormatTag;
  WORD wReserved2;
  WORD nChannels;
  WORD wReserved3;
  DWORD nSamplesPerSec;
  DWORD nAvgBytesPerSec;
  WORD nBlockAlign;
  WORD wReserved4;
  WORD wBitsPerSample;
  WORD wReserved5;
} MCI_WAVE_SET_PARMS, *PMCI_WAVE_SET_PARMS, *LPMCI_WAVE_SET_PARMS;

#define MCI_SEQ_DIV_PPQN (0 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_24 (1 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_25 (2 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_30DROP (3 + MCI_SEQ_OFFSET)
#define MCI_SEQ_DIV_SMPTE_30 (4 + MCI_SEQ_OFFSET)

#define MCI_SEQ_FORMAT_SONGPTR 0x4001
#define MCI_SEQ_FILE 0x4002
#define MCI_SEQ_MIDI 0x4003
#define MCI_SEQ_SMPTE 0x4004
#define MCI_SEQ_NONE 65533
#define MCI_SEQ_MAPPER 65535

#define MCI_SEQ_STATUS_TEMPO __MSABI_LONG(0x00004002)
#define MCI_SEQ_STATUS_PORT __MSABI_LONG(0x00004003)
#define MCI_SEQ_STATUS_SLAVE __MSABI_LONG(0x00004007)
#define MCI_SEQ_STATUS_MASTER __MSABI_LONG(0x00004008)
#define MCI_SEQ_STATUS_OFFSET __MSABI_LONG(0x00004009)
#define MCI_SEQ_STATUS_DIVTYPE __MSABI_LONG(0x0000400A)
#define MCI_SEQ_STATUS_NAME __MSABI_LONG(0x0000400B)
#define MCI_SEQ_STATUS_COPYRIGHT __MSABI_LONG(0x0000400C)

#define MCI_SEQ_SET_TEMPO __MSABI_LONG(0x00010000)
#define MCI_SEQ_SET_PORT __MSABI_LONG(0x00020000)
#define MCI_SEQ_SET_SLAVE __MSABI_LONG(0x00040000)
#define MCI_SEQ_SET_MASTER __MSABI_LONG(0x00080000)
#define MCI_SEQ_SET_OFFSET __MSABI_LONG(0x01000000)

typedef struct tagMCI_SEQ_SET_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwTimeFormat;
  DWORD dwAudio;
  DWORD dwTempo;
  DWORD dwPort;
  DWORD dwSlave;
  DWORD dwMaster;
  DWORD dwOffset;
} MCI_SEQ_SET_PARMS, *PMCI_SEQ_SET_PARMS, *LPMCI_SEQ_SET_PARMS;

#define MCI_ANIM_OPEN_WS __MSABI_LONG(0x00010000)
#define MCI_ANIM_OPEN_PARENT __MSABI_LONG(0x00020000)
#define MCI_ANIM_OPEN_NOSTATIC __MSABI_LONG(0x00040000)

#define MCI_ANIM_PLAY_SPEED __MSABI_LONG(0x00010000)
#define MCI_ANIM_PLAY_REVERSE __MSABI_LONG(0x00020000)
#define MCI_ANIM_PLAY_FAST __MSABI_LONG(0x00040000)
#define MCI_ANIM_PLAY_SLOW __MSABI_LONG(0x00080000)
#define MCI_ANIM_PLAY_SCAN __MSABI_LONG(0x00100000)

#define MCI_ANIM_STEP_REVERSE __MSABI_LONG(0x00010000)
#define MCI_ANIM_STEP_FRAMES __MSABI_LONG(0x00020000)

#define MCI_ANIM_STATUS_SPEED __MSABI_LONG(0x00004001)
#define MCI_ANIM_STATUS_FORWARD __MSABI_LONG(0x00004002)
#define MCI_ANIM_STATUS_HWND __MSABI_LONG(0x00004003)
#define MCI_ANIM_STATUS_HPAL __MSABI_LONG(0x00004004)
#define MCI_ANIM_STATUS_STRETCH __MSABI_LONG(0x00004005)

#define MCI_ANIM_INFO_TEXT __MSABI_LONG(0x00010000)

#define MCI_ANIM_GETDEVCAPS_CAN_REVERSE __MSABI_LONG(0x00004001)
#define MCI_ANIM_GETDEVCAPS_FAST_RATE __MSABI_LONG(0x00004002)
#define MCI_ANIM_GETDEVCAPS_SLOW_RATE __MSABI_LONG(0x00004003)
#define MCI_ANIM_GETDEVCAPS_NORMAL_RATE __MSABI_LONG(0x00004004)
#define MCI_ANIM_GETDEVCAPS_PALETTES __MSABI_LONG(0x00004006)
#define MCI_ANIM_GETDEVCAPS_CAN_STRETCH __MSABI_LONG(0x00004007)
#define MCI_ANIM_GETDEVCAPS_MAX_WINDOWS __MSABI_LONG(0x00004008)

#define MCI_ANIM_REALIZE_NORM __MSABI_LONG(0x00010000)
#define MCI_ANIM_REALIZE_BKGD __MSABI_LONG(0x00020000)

#define MCI_ANIM_WINDOW_HWND __MSABI_LONG(0x00010000)
#define MCI_ANIM_WINDOW_STATE __MSABI_LONG(0x00040000)
#define MCI_ANIM_WINDOW_TEXT __MSABI_LONG(0x00080000)
#define MCI_ANIM_WINDOW_ENABLE_STRETCH __MSABI_LONG(0x00100000)
#define MCI_ANIM_WINDOW_DISABLE_STRETCH __MSABI_LONG(0x00200000)

#define MCI_ANIM_WINDOW_DEFAULT __MSABI_LONG(0x00000000)

#define MCI_ANIM_RECT __MSABI_LONG(0x00010000)
#define MCI_ANIM_PUT_SOURCE __MSABI_LONG(0x00020000)
#define MCI_ANIM_PUT_DESTINATION __MSABI_LONG(0x00040000)

#define MCI_ANIM_WHERE_SOURCE __MSABI_LONG(0x00020000)
#define MCI_ANIM_WHERE_DESTINATION __MSABI_LONG(0x00040000)

#define MCI_ANIM_UPDATE_HDC __MSABI_LONG(0x00020000)

typedef struct tagMCI_ANIM_OPEN_PARMSA {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCSTR lpstrDeviceType;
  LPCSTR lpstrElementName;
  LPCSTR lpstrAlias;
  DWORD dwStyle;
  HWND hWndParent;
} MCI_ANIM_OPEN_PARMSA, *PMCI_ANIM_OPEN_PARMSA, *LPMCI_ANIM_OPEN_PARMSA;

typedef struct tagMCI_ANIM_OPEN_PARMSW {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCWSTR lpstrDeviceType;
  LPCWSTR lpstrElementName;
  LPCWSTR lpstrAlias;
  DWORD dwStyle;
  HWND hWndParent;
} MCI_ANIM_OPEN_PARMSW, *PMCI_ANIM_OPEN_PARMSW, *LPMCI_ANIM_OPEN_PARMSW;

__MINGW_TYPEDEF_AW(MCI_ANIM_OPEN_PARMS)
__MINGW_TYPEDEF_AW(PMCI_ANIM_OPEN_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_ANIM_OPEN_PARMS)

typedef struct tagMCI_ANIM_PLAY_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrom;
  DWORD dwTo;
  DWORD dwSpeed;
} MCI_ANIM_PLAY_PARMS, *PMCI_ANIM_PLAY_PARMS, *LPMCI_ANIM_PLAY_PARMS;

typedef struct tagMCI_ANIM_STEP_PARMS {
  DWORD_PTR dwCallback;
  DWORD dwFrames;
} MCI_ANIM_STEP_PARMS, *PMCI_ANIM_STEP_PARMS, *LPMCI_ANIM_STEP_PARMS;

typedef struct tagMCI_ANIM_WINDOW_PARMSA {
  DWORD_PTR dwCallback;
  HWND hWnd;
  UINT nCmdShow;
  LPCSTR lpstrText;
} MCI_ANIM_WINDOW_PARMSA, *PMCI_ANIM_WINDOW_PARMSA, *LPMCI_ANIM_WINDOW_PARMSA;

typedef struct tagMCI_ANIM_WINDOW_PARMSW {
  DWORD_PTR dwCallback;
  HWND hWnd;
  UINT nCmdShow;
  LPCWSTR lpstrText;
} MCI_ANIM_WINDOW_PARMSW, *PMCI_ANIM_WINDOW_PARMSW, *LPMCI_ANIM_WINDOW_PARMSW;

__MINGW_TYPEDEF_AW(MCI_ANIM_WINDOW_PARMS)
__MINGW_TYPEDEF_AW(PMCI_ANIM_WINDOW_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_ANIM_WINDOW_PARMS)

typedef struct tagMCI_ANIM_RECT_PARMS {
  DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
  POINT ptOffset;
  POINT ptExtent;
#else
  RECT rc;
#endif
} MCI_ANIM_RECT_PARMS, *PMCI_ANIM_RECT_PARMS, *LPMCI_ANIM_RECT_PARMS;

typedef struct tagMCI_ANIM_UPDATE_PARMS {
  DWORD_PTR dwCallback;
  RECT rc;
  HDC hDC;
} MCI_ANIM_UPDATE_PARMS, *PMCI_ANIM_UPDATE_PARMS, *LPMCI_ANIM_UPDATE_PARMS;

#define MCI_OVLY_OPEN_WS __MSABI_LONG(0x00010000)
#define MCI_OVLY_OPEN_PARENT __MSABI_LONG(0x00020000)

#define MCI_OVLY_STATUS_HWND __MSABI_LONG(0x00004001)
#define MCI_OVLY_STATUS_STRETCH __MSABI_LONG(0x00004002)

#define MCI_OVLY_INFO_TEXT __MSABI_LONG(0x00010000)

#define MCI_OVLY_GETDEVCAPS_CAN_STRETCH __MSABI_LONG(0x00004001)
#define MCI_OVLY_GETDEVCAPS_CAN_FREEZE __MSABI_LONG(0x00004002)
#define MCI_OVLY_GETDEVCAPS_MAX_WINDOWS __MSABI_LONG(0x00004003)

#define MCI_OVLY_WINDOW_HWND __MSABI_LONG(0x00010000)
#define MCI_OVLY_WINDOW_STATE __MSABI_LONG(0x00040000)
#define MCI_OVLY_WINDOW_TEXT __MSABI_LONG(0x00080000)
#define MCI_OVLY_WINDOW_ENABLE_STRETCH __MSABI_LONG(0x00100000)
#define MCI_OVLY_WINDOW_DISABLE_STRETCH __MSABI_LONG(0x00200000)

#define MCI_OVLY_WINDOW_DEFAULT __MSABI_LONG(0x00000000)

#define MCI_OVLY_RECT __MSABI_LONG(0x00010000)
#define MCI_OVLY_PUT_SOURCE __MSABI_LONG(0x00020000)
#define MCI_OVLY_PUT_DESTINATION __MSABI_LONG(0x00040000)
#define MCI_OVLY_PUT_FRAME __MSABI_LONG(0x00080000)
#define MCI_OVLY_PUT_VIDEO __MSABI_LONG(0x00100000)

#define MCI_OVLY_WHERE_SOURCE __MSABI_LONG(0x00020000)
#define MCI_OVLY_WHERE_DESTINATION __MSABI_LONG(0x00040000)
#define MCI_OVLY_WHERE_FRAME __MSABI_LONG(0x00080000)
#define MCI_OVLY_WHERE_VIDEO __MSABI_LONG(0x00100000)

typedef struct tagMCI_OVLY_OPEN_PARMSA {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCSTR lpstrDeviceType;
  LPCSTR lpstrElementName;
  LPCSTR lpstrAlias;
  DWORD dwStyle;
  HWND hWndParent;
} MCI_OVLY_OPEN_PARMSA, *PMCI_OVLY_OPEN_PARMSA, *LPMCI_OVLY_OPEN_PARMSA;

typedef struct tagMCI_OVLY_OPEN_PARMSW {
  DWORD_PTR dwCallback;
  MCIDEVICEID wDeviceID;
  LPCWSTR lpstrDeviceType;
  LPCWSTR lpstrElementName;
  LPCWSTR lpstrAlias;
  DWORD dwStyle;
  HWND hWndParent;
} MCI_OVLY_OPEN_PARMSW, *PMCI_OVLY_OPEN_PARMSW, *LPMCI_OVLY_OPEN_PARMSW;

__MINGW_TYPEDEF_AW(MCI_OVLY_OPEN_PARMS)
__MINGW_TYPEDEF_AW(PMCI_OVLY_OPEN_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_OVLY_OPEN_PARMS)

typedef struct tagMCI_OVLY_WINDOW_PARMSA {
  DWORD_PTR dwCallback;
  HWND hWnd;
  UINT nCmdShow;
  LPCSTR lpstrText;
} MCI_OVLY_WINDOW_PARMSA, *PMCI_OVLY_WINDOW_PARMSA, *LPMCI_OVLY_WINDOW_PARMSA;

typedef struct tagMCI_OVLY_WINDOW_PARMSW {
  DWORD_PTR dwCallback;
  HWND hWnd;
  UINT nCmdShow;
  LPCWSTR lpstrText;
} MCI_OVLY_WINDOW_PARMSW, *PMCI_OVLY_WINDOW_PARMSW, *LPMCI_OVLY_WINDOW_PARMSW;

__MINGW_TYPEDEF_AW(MCI_OVLY_WINDOW_PARMS)
__MINGW_TYPEDEF_AW(PMCI_OVLY_WINDOW_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_OVLY_WINDOW_PARMS)

typedef struct tagMCI_OVLY_RECT_PARMS {
  DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
  POINT ptOffset;
  POINT ptExtent;
#else
  RECT rc;
#endif
} MCI_OVLY_RECT_PARMS, *PMCI_OVLY_RECT_PARMS, *LPMCI_OVLY_RECT_PARMS;

typedef struct tagMCI_OVLY_SAVE_PARMSA {
  DWORD_PTR dwCallback;
  LPCSTR lpfilename;
  RECT rc;
} MCI_OVLY_SAVE_PARMSA, *PMCI_OVLY_SAVE_PARMSA, *LPMCI_OVLY_SAVE_PARMSA;

typedef struct tagMCI_OVLY_SAVE_PARMSW {
  DWORD_PTR dwCallback;
  LPCWSTR lpfilename;
  RECT rc;
} MCI_OVLY_SAVE_PARMSW, *PMCI_OVLY_SAVE_PARMSW, *LPMCI_OVLY_SAVE_PARMSW;

__MINGW_TYPEDEF_AW(MCI_OVLY_SAVE_PARMS)
__MINGW_TYPEDEF_AW(PMCI_OVLY_SAVE_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_OVLY_SAVE_PARMS)

typedef struct tagMCI_OVLY_LOAD_PARMSA {
  DWORD_PTR dwCallback;
  LPCSTR lpfilename;
  RECT rc;
} MCI_OVLY_LOAD_PARMSA, *PMCI_OVLY_LOAD_PARMSA, *LPMCI_OVLY_LOAD_PARMSA;

typedef struct tagMCI_OVLY_LOAD_PARMSW {
  DWORD_PTR dwCallback;
  LPCWSTR lpfilename;
  RECT rc;
} MCI_OVLY_LOAD_PARMSW, *PMCI_OVLY_LOAD_PARMSW, *LPMCI_OVLY_LOAD_PARMSW;

__MINGW_TYPEDEF_AW(MCI_OVLY_LOAD_PARMS)
__MINGW_TYPEDEF_AW(PMCI_OVLY_LOAD_PARMS)
__MINGW_TYPEDEF_AW(LPMCI_OVLY_LOAD_PARMS)

DWORD_PTR APIENTRY mciGetDriverData(MCIDEVICEID wDeviceID);
UINT APIENTRY mciLoadCommandResource(HANDLE hInstance, LPCWSTR lpResName, UINT wType);
WINBOOL APIENTRY mciSetDriverData(MCIDEVICEID wDeviceID, DWORD_PTR dwData);
UINT APIENTRY mciDriverYield(MCIDEVICEID wDeviceID);
WINBOOL APIENTRY mciDriverNotify(HANDLE hwndCallback, MCIDEVICEID wDeviceID, UINT uStatus);
WINBOOL APIENTRY mciFreeCommandResource(UINT wTable);

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif /* _MCIAPI_H_ */
