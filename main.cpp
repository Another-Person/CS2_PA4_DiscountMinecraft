#include <iostream>
#include <vector>

#include "Blocks.h"

using namespace std;

int main()
{
	vector<Block*> blocks;

	Stone* stonePointer;
	Stone stone;
	stonePointer = &stone;
	blocks.push_back(stonePointer);

	Lamp* lampPointer;
	Lamp lamp;
	lampPointer = &lamp;
	blocks.push_back(lampPointer);

	WoodPlanks* planksPointer;
	WoodPlanks planks;
	planksPointer = &planks;
	blocks.push_back(planksPointer);





	for (Block* block : blocks)
	{
		cout << block->GetBlockName() << endl;
		cout << block->GetHardness() << endl;
		cout << block->GetItemFromBlock()[0] << endl << endl;
	}

	if (is_base_of<LightEmittingBlock, Lamp>::value)
	{
		cout << "Lamp derives from Light Emitting Block" << endl;
		cout << lampPointer->GetLightLevel() << endl << endl;
		cout << lampPointer->IsBlockEmittingLight() << endl;
		lampPointer->OnPlayerClick();
		cout << lampPointer->IsBlockEmittingLight() << endl;
		lampPointer->OnPlayerClick();
		cout << lampPointer->IsBlockEmittingLight() << endl << endl;
	}

	if (is_base_of<BurnableBlock, WoodPlanks>::value)
	{
		cout << "WoodPlanks derives from Burnable Block" << endl;
		cout << planksPointer->GetBurnDuration() << endl;
		planksPointer->Burn();
	}

	return 0;
}