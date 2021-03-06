#ifndef BLOCKS_H
#define BLOCKS_H

#include <string>
#include <vector>
#include <iostream>

class Block
{
public:
	Block(std::string blockName, double blockHardness, std::vector<std::string> blockDrops);

	std::string GetBlockName() { return name; }
	double GetHardness() { return hardness; }
	std::vector<std::string> GetItemFromBlock() { return itemDrops; }

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
	LightEmittingBlock(double newLightLevel, bool startLit, std::string blockName, double blockHardness, std::vector<std::string> blockDrops);
	
	double GetLightLevel() { return lightLevel; }
	bool IsBlockEmittingLight() { return isLit; }
	virtual void OnPlayerClick() = 0;

protected:
	double lightLevel;
	bool isLit;
};

LightEmittingBlock::LightEmittingBlock(double newLightLevel, bool startLit, std::string blockName, double blockHardness, std::vector<std::string> blockDrops) : Block(blockName, blockHardness, blockDrops), lightLevel(newLightLevel), isLit(startLit)
{
}





class Lamp : public LightEmittingBlock
{
public:
	Lamp();

	void OnPlayerClick() { isLit = !isLit; }

};

Lamp::Lamp() : LightEmittingBlock(1, false, "Lamp", .5, { "glowstone" })
{
}





class BurnableBlock : public Block
{
public:
	BurnableBlock(double startingBurnDuration, std::string blockName, double blockHardness, std::vector<std::string> blockDrops);

	double GetBurnDuration() { return burnDuration; }
	virtual void Burn() = 0;

private:
	double burnDuration;
};

BurnableBlock::BurnableBlock(double startingBurnDuration, std::string blockName, double blockHardness, std::vector<std::string> blockDrops) : Block(blockName, blockHardness, blockDrops), burnDuration(startingBurnDuration)
{
}





class WoodPlanks : public BurnableBlock
{
public:
	WoodPlanks();

	void Burn() { std::cout << "It's burning!\n"; }
};

WoodPlanks::WoodPlanks() : BurnableBlock(32.5, "Wood Planks", 1.5, { "Wood Planks" })
{
}
#endif // !BLOCKS_H
