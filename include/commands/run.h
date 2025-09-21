#pragma once
// This command executes a non-command executable
#include <windows.h>
#include "BuiltInCommands.h"

LPWSTR stringToLPWSTR(const std::string& str) {
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(),
		(int)str.size(), NULL, 0);
	LPWSTR wstr = new wchar_t[size_needed + 1];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(),
		(int)str.size(), wstr, size_needed);
	wstr[size_needed] = L'\0';
	return wstr;
}

void run(const PARAMETERS& param) {
	if (param.empty()) {
		std::cout << "run: Parameters are empty!\n\n";
		return;
	}
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(NULL,
		stringToLPWSTR(param[0]),
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		std::cout << "run: CreateProcess failed! " << GetLastError() << "\n";
		return;
	}
	//WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles. 
	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);
}