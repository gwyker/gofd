#include "building.h"
#include "buildings/generic1.cpp"
#include "buildings/genericOctogon.cpp"

const double Building::sidewalkWidth = 3;
const double Building::maxBuildingWidth = 40;
const double Building::distanceBetweenBuildings = 60;
const double Building::streetWidth = 60 - 40; // distanceBetweenBuildings - maxBuildingWidth;

Building::Building(Point center){
	this->center = center;
	const int numOfBuildings = 2;
	switch(rand() % numOfBuildings){
		case 0:
			createGeneric1Building(model,box);
			break;
		case 1:
			createGenericOctogonBuilding(model,box);
			break;

		// === insert new building before here ===
		default:
			createGeneric1Building(model,box);
			printf("Building selection out of range\n");
			break;
	}
}

void Building::draw(){
	glPushMatrix();
	glTranslated(center.x,center.y,center.z);
	for(int x=0; x<model.size(); x++)
		this->model[x].draw();
	glPopMatrix();
}
void Building::update(){
}
std::vector<Polygon3d> Building::boundingBox(){
	return this->box;
}
float Building::getBuildingHeight()
{
	
	const int minFloors = 5;
	const int maxFloors = 15;
	const double floorHeight = 5;
	const double buildingWidth = Building::maxBuildingWidth;
	const double sidewalkWidth = Building::sidewalkWidth;
	const double streetWidth = Building::streetWidth;
	
	int numFloors = (rand() % (maxFloors - minFloors)) + minFloors;

	return numFloors*floorHeight;
}
