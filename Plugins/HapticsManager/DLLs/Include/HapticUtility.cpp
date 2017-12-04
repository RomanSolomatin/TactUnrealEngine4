#pragma once

#include "string.h"
#include "HapticUtility.h"

#using <System.dll>

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;
using namespace Microsoft::Win32;

//Exported method that invertes a given boolean.
bool isPlayerInstalled()
{
	auto path = getExePath();

	return path != "";
}

//Exported method that iterates a given int value.
bool isPlayerRunning()
{
	System::String ^filePath = gcnew String (getExePath());
	auto fileName = Path::GetFileNameWithoutExtension(filePath);

	if (is64BitBuild())
	{
		auto process = Process::GetProcessesByName(fileName);
		if (process->Length >= 1)
		{
			return true;
		}
		return false;
	}
	else
	{
		return true;
	}
}

//Exported method that calculates the are of a circle by a given radius.
bool is64BitBuild()
{
	return IntPtr::Size ==8;
}

//Exported method that adds a parameter text to an additional text and returns them combined.
char *getExePath()
{
	if (isInit)
	{
		return exeFilePath;
	}
	isInit = true;
	String^ fileKey("bhaptics-app");
	auto hklm = RegistryKey::OpenBaseKey(RegistryHive::ClassesRoot, RegistryView::Registry32);
	RegistryKey ^rkey = hklm->OpenSubKey("bhaptics-app\\shell\\open\\command");// Registry::ClassesRoot->OpenSubKey(fileKey);//

	if (rkey == nullptr)
	{
		return "";
	}

	auto val = rkey->GetValue("");

	if (val == nullptr)
	{
		return "";
	}

	auto path = val->ToString();
	exeFilePath = (char*)(void*)Marshal::StringToHGlobalAnsi(path);
	return exeFilePath;
}

//Exported method that adds a vector4 to a given vector4 and returns the sum.
void launchPlayer()
{
	auto myProcess = gcnew Process();
	myProcess->StartInfo->FileName = gcnew String(getExePath());
	myProcess->Start();
}