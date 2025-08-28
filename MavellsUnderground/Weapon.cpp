#include "Weapon.h"
#include <fstream>
#include "json.hpp"
#include "Player.h"



Weapon::Weapon(std::string weaponName)
{
	std::ifstream fWeaponData("ItemData.json");
	auto weaponJson = nlohmann::json::parse(fWeaponData);

	name = weaponName;
	description = weaponJson["Weapons"][weaponName]["Description"];
	type = weaponJson["Weapons"][weaponName]["Element"];
	itemValue = weaponJson["Weapons"][weaponName]["Value"];
	for (int i = 0; i < weaponJson["Weapons"][weaponName]["AttackList"].size(); i++) {
		atkData attackData;
		attackData.damage = weaponJson["Weapons"][weaponName]["AttackList"][i]["Damage"];
		attackData.description = weaponJson["Weapons"][weaponName]["AttackList"][i]["Description"];
		attackData.name = weaponJson["Weapons"][weaponName]["AttackList"][i]["Name"];
		weaponAtk.push_back(attackData);
	}

}


int Weapon::move1(Enemy* enemy)
{
	int dmg = weaponAtk[0].damage;
	std::string description = weaponAtk[0].description;
	return dmg;
}

int Weapon::move2(Enemy* enemy)
{
	int dmg = weaponAtk[1].damage;
	std::string description = weaponAtk[1].description;
	return dmg;
}

int Weapon::move3(Enemy* enemy)
{
	int dmg = weaponAtk[2].damage;
	std::string description = weaponAtk[2].description;
	return dmg;
}

int Weapon::move4(Enemy* enemy)
{
	int dmg = weaponAtk[3].damage;
	std::string description = weaponAtk[3].description;
	return dmg;
}

void Weapon::setPlayerAttacks()
{
	Player::atkList.clear();
	for (int i = 0; i < weaponAtk.size(); i++) {
		Player::atkList.push_back(weaponAtk[i].name);
	}

}

