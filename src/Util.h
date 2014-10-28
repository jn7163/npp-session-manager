/*
    Util.h
    Copyright 2011-2014 Michael Foster (http://mfoster.com/npp/)

    This file is part of SessionMgr, A Plugin for Notepad++.

    SessionMgr is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NPP_PLUGIN_UTIL_H
#define NPP_PLUGIN_UTIL_H

//------------------------------------------------------------------------------

namespace NppPlugin {

/* Debug log levels:
  0     = no logging
  >=1   = LOG and LOGF
  1-9   = LOGE
  10    = LOGG (verbose)
  11-19 = LOGE
  20    = LOGG (more verbose than 10)
  21-29 = LOGE
  30    = LOGG (more verbose than 20)
  31-39 = LOGE
*/
#define LOG(fmt, ...) dbgLog(__FUNCTION__ ": " fmt, __VA_ARGS__)
#define LOGF(fmt, ...) dbgLog(__FUNCTION__ "(" fmt ")", __VA_ARGS__)
#define LOGG(lvl, fmt, ...) if (gCfg.debug >= lvl) { LOG(fmt, __VA_ARGS__); }
#define LOGE(lvl, fmt, ...) if (gCfg.debug == lvl) { LOG(fmt, __VA_ARGS__); }
#define LOGNN(noti) LOG("%20s\t%8i\t%i", noti, bufferId, _bidBufferActivated)
#define LOGSN(noti) LOG("%20s\t%8s\t%i", noti, "", _bidBufferActivated)
#define SHOW_ERROR errBox(_T(__FUNCTION__))
#define EMPTY_STR _T("")
#define SPACE_STR _T(" ")
// msgBox title/options
#define M_DBG  PLUGIN_FULL_NAME SPACE_STR _T("Debug"), (MB_OK | MB_ICONWARNING)
#define M_ERR  PLUGIN_FULL_NAME SPACE_STR _T("Error"), (MB_OK | MB_ICONERROR)
#define M_WARN PLUGIN_FULL_NAME SPACE_STR _T("Warning"), (MB_OK | MB_ICONWARNING)
#define M_INFO PLUGIN_FULL_NAME, (MB_OK | MB_ICONINFORMATION)

INT msgBox(const TCHAR *m, TCHAR *title = NULL, UINT options = MB_OK);
void errBox(TCHAR *lpszFunction, DWORD errorCode = 0);
void dbgLog(const char* format, ...);
void createIfNotPresent(TCHAR *filename, const char *contents);
inline const TCHAR* boolToStr(const bool b) { return b ? _T("true") : _T("false"); }
inline const bool uintToBool(UINT n) { return n == 0 ? false : true; }

//------------------------------------------------------------------------------

namespace pth {

TCHAR* remExt(TCHAR *p);
TCHAR* remPath(TCHAR *p);
TCHAR* remName(TCHAR *p);
bool addSlash(TCHAR *p);
bool dirExists(TCHAR *p);

} // end namespace pth

//------------------------------------------------------------------------------

namespace dlg {

bool setText(HWND hDlg, UINT idCtrl, const TCHAR* text);
bool getText(HWND hDlg, UINT idCtrl, TCHAR *buf);
bool edtModified(HWND hDlg, UINT idCtrl);
bool setCheck(HWND hDlg, UINT idCtrl, bool bChecked);
bool getCheck(HWND hDlg, UINT idCtrl);
bool focus(HWND hDlg, UINT idCtrl);
INT getLbSelData(HWND hDlg, UINT idCtrl);
INT getLbIdxByData(HWND hDlg, UINT idCtrl, INT data);
void redrawControl(HWND hDlg, HWND hCtrl);
bool centerWnd(HWND hWnd, HWND hParentWnd, INT xOffset = 0, INT yOffset = 0, INT width = 0, INT height = 0, bool bRepaint = FALSE);
void adjToEdge(HWND hDlg, INT idCtrl, INT dlgW, INT dlgH, INT toChange, INT duoRight, INT duoBottom, bool last = false);
//bool setSbText(HWND hDlg, UINT idCtrl, INT nPart, const TCHAR* text);
//bool setSbtText(HWND hDlg, UINT idCtrl, INT nPart, const TCHAR* text);
//HWND createStatusBar(HWND hwndParent, int idStatus, HINSTANCE hinst, int cParts);
//HWND createTooltip(int toolID, HWND hDlg, PTSTR text);

} // end namespace dlg

} // end namespace NppPlugin

#endif // NPP_PLUGIN_UTIL_H
