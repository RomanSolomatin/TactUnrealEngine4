#pragma once  

#define DLL_EXPORT __declspec(dllexport)	//shortens __declspec(dllexport) to DLL_EXPORT

#ifdef __cplusplus		//if C++ is used convert it to C to prevent C++'s name mangling of method names
extern "C"
{
#endif

	bool DLL_EXPORT isPlayerInstalled();
	bool DLL_EXPORT isPlayerRunning();
	bool DLL_EXPORT is64BitBuild();
	char DLL_EXPORT *getExePath();
	void DLL_EXPORT launchPlayer();

	static bool isInit = false;
	static char* exeFilePath = "";

#ifdef __cplusplus
}
#endif