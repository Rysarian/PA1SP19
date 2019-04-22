/*
 * Name        : ScrollThief.h
 * Author      : Justin Collins
 * Description : A text based adventure game.
 * Sources Used: No other sources used this time.
 */

#ifndef SCROLLTHIEF_H
#define SCROLLTHIEF_H

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "ScrollThief.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

class ScrollThief {
public:
  void Start();
private:
  //ScrollThief();
  bool SkillCheck(int threshold, int modifier);
  bool AttackCheck(int enemy_attack, int enemy_dodge, int enemy_curr_hp, int enemy_max_hp, string enemy_name, int xp_value, int gold_value, bool actual_fight);
  void CreateCharacter();
  void Level_Up();
  void CharacterStats();
  void Adventure();
  void Set_Gold_XP(char type, int amount);
  void LocationTravel(int location);
  void TrainingYard();
  void WizardShop();
  void NobleShop();
  void Skip();
  void GameOver();
  void Ambush();
  void KeltiiLibrary();
  void LibraryArchives();
  void Sewers();
  void DragonSwamp();
  void RapidLantern();
  void SythrowPlaza();

  string player_name, weap_name, armor_name, continue_string;

  int attr_points, player_xp, player_attack = 0, player_dodge = 0, player_invest = 0;
  int player_perception = 0, player_max_hp = 2, player_curr_hp, player_charisma = 0;
  int player_gold, weap_att_bonus, weap_dex_bonus, armor_hp_bonus, armor_dex_bonus;
  int total_attack = 0, total_dodge = 0, total_max_hp = player_max_hp, choice;

  //Extra Reward Trackers
  //wolfleaf - 50 + 10
  //cylla - 100 + 25
  //shelves_chest - 50 (Inform Library about the chest and shelves' contents)
  bool convince_wolfleaf = false, convince_cylla = false, fought_vera = false, convince_aria = false;
  bool shelves_chest = false, convince_ellison = false , rythnax_escapes = false, capture_ellison = false;
  //locations
  bool visited_archives = false;
};

struct LocationDesc {
  string name_;
  string description_;
  bool visited_;
  bool unlocked_;
  int number_;
};

struct Items {
  string item_name_;
  int amount_;
  bool carried_;
  string item_description_;
  int item_number_;
};

/*
1 - Rapid Lantern
2 - Keltii's Library
3 - Aria's Shop
4 - Marten's Training Yard
5 - Agin's Shop
6 - Twilight Marsh
*/




#endif
