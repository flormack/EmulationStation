#ifndef _SYSTEMDATA_H_
#define _SYSTEMDATA_H_

#include <vector>
#include <string>
#include "FolderData.h"
#include "Window.h"
#include "MetaData.h"
#include "PlatformId.h"

class GameData;

class SystemData
{
public:
	SystemData(const std::string& name, const std::string& fullName, const std::string& startPath, const std::string& extension, 
		const std::string& command, PlatformIds::PlatformId platformId = PlatformIds::PLATFORM_UNKNOWN);
	~SystemData();

	FolderData* getRootFolder();
	std::string getName();
	std::string getFullName();
	std::string getStartPath();
	std::string getExtension();
	std::string getGamelistPath();
	PlatformIds::PlatformId getPlatformId();
	bool hasGamelist();
	std::vector<MetaDataDecl> getGameMDD();

	void launchGame(Window* window, GameData* game);

	static void deleteSystems();
	static bool loadConfig(const std::string& path, bool writeExampleIfNonexistant = true); //Load the system config file at getConfigPath(). Returns true if no errors were encountered. An example can be written if the file doesn't exist.
	static void writeExampleConfig(const std::string& path);
	static std::string getConfigPath();

	static std::vector<SystemData*> sSystemVector;
private:
	std::string mName;
	std::string mFullName;
	std::string mStartPath;
	std::string mSearchExtension;
	std::string mLaunchCommand;
	PlatformIds::PlatformId mPlatformId;

	void populateFolder(FolderData* folder);

	FolderData* mRootFolder;
};

#endif

