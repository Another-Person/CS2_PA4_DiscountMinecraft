#ifndef BLOCKS_H
#define BLOCKS_H

#include <string>
#include <vector>

class Block
{
public:
	Block(std::string blockName, double blockHardness, std::vector<std::string> blockDrops);

	std::string GetBlockName() { return name; }
	double GetHardness() { return hardness; }
	std::vector<std::string> GetItemFromDrops() { return itemDrops; }

private:
	std::string name;
	double hardness;
	std::vector<std::string> itemDrops;

};

Block::Block(std::string blockName, double blockHardness, std::vector<std::string> blockDrops) : name(blockName), hardness(blockHardness), itemDrops(blockDrops)
{
}





class Stone : public Block
{
public:
	Stone();

};

Stone::Stone() : Block("Stone", 1.5, { "Cobblestone" })
{
}





class LightEmittingBlock : public Block
{
public:
	LightEmittingBlock(double newLightLevel, bool startLit);
	
	double GetLightLevel() { return lightLevel; }
	bool IsBlockEmittingLight() { return isLit; }
	virtual void OnPlayerClick() = 0;

private:
	double lightLevel;
	bool isLit;
};

LightEmittingBlock::LightEmittingBlock(double newLightLevel, bool startLit) : lightLevel(newLightLevel), isLit(startLit)
{
}

#endif // !BLOCKS_H
