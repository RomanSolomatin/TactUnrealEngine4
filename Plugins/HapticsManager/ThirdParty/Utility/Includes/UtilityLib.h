#pragma once
namespace HapticUtilities
{

	class HapticUtils
	{
	public :
		HapticUtils();
		static bool isPlayerInstalled();
		static bool isPlayerRunning();
		static bool is64BitBuild();
		static char *getExePath();
		static void launchPlayer();

		static bool isInit;
		static char* exeFilePath;
	};
}