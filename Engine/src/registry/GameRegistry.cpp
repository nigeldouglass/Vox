#include "GameRegistry.h"

std::vector<IBlock> GameRegistry::blockID;
std::vector<std::string> GameRegistry::blockName;

void GameRegistry::registerBlock(IBlock block)
{
	if (std::find(GameRegistry::blockName.begin(), GameRegistry::blockName.end(), block.getName()) != GameRegistry::blockName.end()) {
		//Block with same name already in regisrty
		std::cout << "Unable to add " << block.getName() << " as already in registry under ID["
			<< getBlockID(block.getName()) << "], suggest changing name." << std::endl;
	}
	else {
		//Block is the first instancy
		GameRegistry::blockID.push_back(block);
		GameRegistry::blockName.push_back(block.getName());
		std::cout << "Registered " << block.getName() << " with ID["
			<< getBlockID(block.getName()) << "]" << std::endl;

		/* TODO
			Check to see why ID is being assigned to various other blocks as well.

		*/
	}
}

IBlock* GameRegistry::getBlock(int id)
{
	if (GameRegistry::blockID.size() < id || GameRegistry::blockID.size() == 0)
		return NULL;
	return &GameRegistry::blockID.at(id);
}

IBlock* GameRegistry::getBlock(std::string blockName)
{
	int id = std::distance(GameRegistry::blockName.begin(), find(GameRegistry::blockName.begin(), GameRegistry::blockName.end(), blockName));
	return getBlock(id);
}

int GameRegistry::getBlockID(std::string blockName)
{
	int id = std::distance(GameRegistry::blockName.begin(), find(GameRegistry::blockName.begin(), GameRegistry::blockName.end(), blockName));
	return id;
}

int GameRegistry::getBlockRegistrySize()
{
	int size = GameRegistry::blockID.size();
	return size;
}

