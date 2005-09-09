#include "DisplayServer.h"
#include "OVIME.h"

AVDisplayServer *DisplayServer::lockIMC(HIMC h)
{
	hIMC = h;
	lpIMC = ImmLockIMC(hIMC);
	lpCompStr = (LPCOMPOSITIONSTRING)ImmLockIMCC(lpIMC->hCompStr);
	lpMyPrivate = (LPMYPRIVATE)ImmLockIMCC(lpIMC->hPrivate);
	return this;
}
AVDisplayServer *DisplayServer::releaseIMC()
{
	ImmUnlockIMCC(lpIMC->hPrivate);
	ImmUnlockIMCC(lpIMC->hCompStr);
	ImmUnlockIMC(hIMC);
	return this;
}
AVDisplayServer *DisplayServer::setBufString(const char *str)
{
	wchar_t wstr[1024];
	MultiByteToWideChar(CP_UTF8, 0, str, strlen(str)+1, wstr, 1024);
	wcscpy(lpMyPrivate->PreEditStr, wstr);
	MakeCompStr(lpMyPrivate, lpCompStr);
	return this;
}
AVDisplayServer *DisplayServer::sendBuf(const char *str)
{
	wchar_t wstr[1024];
	MultiByteToWideChar(CP_UTF8, 0, str, strlen(str)+1, wstr, 1024);
	wcscpy(GETLPRESULTSTR(lpCompStr), wstr);
	lpCompStr->dwResultStrLen = wcslen(wstr);
	wcscpy(lpMyPrivate->PreEditStr, L"");
	MakeCompStr(lpMyPrivate, lpCompStr);
	
	MyGenerateMessage(hIMC,
		WM_IME_COMPOSITION, 0, GCS_RESULTSTR);
	MyGenerateMessage(hIMC,
		WM_IME_ENDCOMPOSITION, 0, 0);	
	return this;
}
AVDisplayServer *DisplayServer::setCandiString(const char *str)
{
	wchar_t wstr[1024];
	MultiByteToWideChar(CP_UTF8, 0, str, strlen(str)+1, wstr, 1024);
	wcscpy(lpMyPrivate->CandStr, wstr);
	UpdateCandidate(lpIMC, wstr);
//	MyGenerateMessage(hIMC,
//			WM_IME_COMPOSITION, 0, GCS_COMPSTR);
	return this;
}
AVDisplayServer *DisplayServer::showBuf(bool t)
{
	if(t)
		UIShowCompWindow();
	else
		UIHideCompWindow();
	return this;
}
AVDisplayServer *DisplayServer::showCandi(bool t)
{
	if(t)
		UIShowCandWindow();
	else
		UIHideCandWindow();
	return this;
}
AVDisplayServer *DisplayServer::setCursorPos(int i)
{
	lpCompStr->dwCursorPos = i;
	UISetCursorPos(lpCompStr->dwCursorPos);
	return this;
}
AVDisplayServer *DisplayServer::setMarkFrom(int i)
{
	UISetMarkFrom(i);
	return this;
}
AVDisplayServer *DisplayServer::setMarkTo(int i)
{
	UISetMarkTo(i);
	return this;
}