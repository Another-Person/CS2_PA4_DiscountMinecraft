#ifndef BLOCKS_H
#define BLOCKS_H

#include <string>
#include <vector>

class Block
{
public:
	Block(std::string blockName, double blockHardness, std::vector<std::string> blockDrops);
	~Block();

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

Block::~Block()
{
}

#endif // !BLOCKS_H
