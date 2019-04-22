/*
 * Name        : codingAssignment_5.cpp
 * Author      : Justin Collins
 * Description : A text based adventure game.
 * Sources Used: No other sources used this time.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "CinReader.h"
#include "ScrollThief.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void ClearScreen();
CinReader reader;
ScrollThief game;

LocationDesc TravelMenu[6] = {
  {
    "Rapid Lantern",
    "From the outside it looks uncomfortable, rough and dirty. Timber\nand carved pillars make up most of the building's outer structure.\nIt's impossible to see through the large, curtained windows,\nbut the awkward silence from within can be felt outside.\n",
    false,
    false,
    1
  },
  {
    "Keltii's Library",
    "Sun-bleached colonnades frame the austere facade of the library.\nA solitary bench sits next to a tranquil pond at the fore of\nthis property in the center of the square.\nThe grounds are well manicured and festooned with blooming flowers\nand other local flora.",
    false,
    false,
    2
  },
  {
    "Aria's Shop",
    "The small building looks quite similar to the other around it,\ngiving no indication that a wizard resides there.\n",
    false,
    false,
    3
  },
  {
    "Marten's Training Yard",
    "Shouts and the clamor of steel on steel are clearly audible even\nbefore reaching the stout doors to the practice yard.",
    false,
    false,
    4
  },
  {
    "Agin's Shop",
    "The small building's front door opens into a small, cramped office.\nLooking within, you can see a number of different heraldic\nbanners from the walls; each hanging above what looks like\na gaudily-decorated family tree set into a frame.",
    false,
    false,
    5
  },
  {
    "Twilight Marsh",
    "The map leads you east along the Phlan Path, and before long, the\nTwilight Marsh lay before you-dark and forboding.\n",
    false,
    false,
    6
  }
};
Items Inventory[12] = {
  {
    "Healing Potions",
    2,
    true,
    "Magical potions used to quickly heal wounds.",
    1
  },
  {
    "Ren's Memoire",
    0,
    false,
    "A collection of stories about Ren O' the Blade.",
    2
  },
  {
    "Blue Ink Letter",
    0,
    false,
    "\"Just get it done, Soares. If they find me, then the last four months have\nbeen a total waste. Ensure that the Whisperer's faith in us\nwas not ill-placed.\n\n---B",
    3
  },
  {
    "Master Opanrael's Note",
    0,
    false,
    "Gives the location of where to find the rest of Ren's Memoires.",
    4
  },
  {
    "The Weave: A Practical Observation of Impractical Occurrences",
    0,
    false,
    "Discusses the theories and hypotheses about the Weave.",
    5
  },
  {
    "Backpack",
    0,
    false,
    "A backpack that held a few other documents.",
    6
  },
  {
    "List of Books",
    0,
    false,
    "A list of titles. Most have been stricken through except for the three\nmissing books you have been sent to find.",
    7
  },
  {
    "Map of Phlan",
    0,
    false,
    "A rough map showing Phlan and its surroundings. A location to the East\nhas been circled and labeled Rythnax. The location is\nat the Twilight Marsh.",
    8
  },
  {
    "Note to Ellison",
    0,
    false,
    "\"Ellison\nOnce you have secured what you can to aid us in our search,\nmeet with Rythnax in the marsh East of the city, along the Phlan\nPath. Slay any that discover your work. Do not fail us again.",
    9
  },
  {
    "Lords and Lineages of Phlan",
    0,
    false,
    "A catalogue of every noble house that has resided in Phlan.",
    10
  },
  {
    "Rythnax's Amulet",
    0,
    false,
    "An amulet with the symbol of the Cult of the Dragon inscribed on it.",
    11
  },
  {
    "Missing Pages",
    0,
    false,
    "Missing pages detailing a Pool of Radiance under Valjevo Keep.",
    12
  }
};

void ScrollThief::Start() {

  cout << "  __                _ _   _____ _     _       __\n"
       << " / _\\ ___ _ __ ___ | | | /__   \\ |__ (_) ___ / _|\n"
       << " \\ \\ / __| '__/ _ \\| | |   / /\\/ '_ \\| |/ _ \\ |_ \n"
       << " _\\ \\ (__| | | (_) | | |  / /  | | | | |  __/  _|\n"
       << " \\__/\\___|_|  \\___/|_|_|  \\/   |_| |_|_|\\___|_|  \n";

  cout << "\n \n 1 - Start\n";
  choice = reader.readInt(1, 1);
  switch (choice) {
    case 1:
      ClearScreen();
      game.CreateCharacter();
      ClearScreen();
      game.Adventure();
      break;
  }
}

void ScrollThief::Adventure() {
  bool temp_bool = false;
  TravelMenu[0].unlocked_ = true;
  cout << "Nearing the walls of Phlan, " << player_name << " notices the wear that is \n" <<
  "affecting them. Many people are walking about the inside of the walls\n" <<
  "but few make their way outside of them. A couple of the town guard, known\n" <<
  "as the Silver Guard, are standing watch outside the gates.\n";
  cout << "\"Hail adventurer!\" one of the guards shouts to you as you near.\n" <<
  "\"If you are able to help out while you are here, stop by the Rapid Lantern\n" <<
  "and meet with Knight Tarra Wolfleaf for a job. She usually arrives at\n" <<
  "sundown.\"\n";
  game.Skip();
  while (temp_bool == false) {
    game.SythrowPlaza();
  }
}

//***CREATE CHARACTER***
void ScrollThief::CreateCharacter() {

  attr_points = 15;
  cout << "Choose your character's name (12 characters max)\n";
  player_name = reader.readString(false, 12);
  ClearScreen();
  game.Level_Up();

  //***ARMOR CHOICE***
  cout << "Choose armor:\n1 - Cloth\n2 - Leather\n3 - Chain\n";
  choice = reader.readInt(1, 3);
  switch (choice) {
    case 1:
      armor_name = "Cloth";
      armor_hp_bonus = 0;
      armor_dex_bonus = 1;
    break;

    case 2:
      armor_name = "Leather";
      armor_hp_bonus = 1;
      armor_dex_bonus = 0;
    break;

    case 3:
      armor_name = "Chain";
      armor_hp_bonus = 3;
      armor_dex_bonus = -2;
    break;
  }
  ClearScreen();

 //***WEAPON CHOICE***
 cout << "Choose weapon:\n1 - Dagger\n2 - Sword\n3 - Mace\n";
 choice = reader.readInt(1, 3);
  switch (choice) {
    case 1:
      weap_name = "Dagger";
      weap_att_bonus = 0;
      weap_dex_bonus = 1;
    break;

    case 2:
      weap_name = "Sword";
      weap_att_bonus = 1;
      weap_dex_bonus = 0;
    break;

    case 3:
      weap_name = "Mace";
      weap_att_bonus = 3;
      weap_dex_bonus = -2;
    break;
  }
  ClearScreen();

  total_attack = player_attack + weap_att_bonus;
  total_dodge = player_dodge + armor_dex_bonus + weap_dex_bonus;
  total_max_hp = player_max_hp + armor_hp_bonus;
  player_curr_hp = total_max_hp;
  game.CharacterStats();
}

//***LEVEL UP***
void ScrollThief::Level_Up() {
  while(attr_points > 0) {
    int attribute_choice, attribute_amt;
    cout << "You have " << attr_points << " Attribute Points. What will you spend them on?\n"
         << "1 - Attack: " << total_attack
         << "\n2 - Dodge: " << total_dodge
         << "\n3 - Investigation: " << player_invest
         << "\n4 - Perception: " << player_perception
         << "\n5 - Hit Points: " << total_max_hp
         << "\n6 - Charisma: " << player_charisma << endl;
    attribute_choice = reader.readInt(1, 6);
    cout << "How many points will you spend out of " << attr_points << "?\n";
    attribute_amt = reader.readInt(1, attr_points);
    switch (attribute_choice) {
      case 1:
        player_attack += attribute_amt;
        total_attack = player_attack + weap_att_bonus;
      break;
      case 2:
        player_dodge += attribute_amt;
        total_dodge = player_dodge + armor_dex_bonus + weap_dex_bonus;
      break;
      case 3:
        player_invest += attribute_amt;
      break;
      case 4:
        player_perception += attribute_amt;
      break;
      case 5:
        player_max_hp += attribute_amt;
        total_max_hp = player_max_hp + armor_hp_bonus;
        player_curr_hp = total_max_hp;
      break;
      case 6:
        player_charisma += attribute_amt;
      break;
    }
    attr_points -= attribute_amt;
    cout << "Points added.\n";
    player_curr_hp = total_max_hp;
    game.Skip();
  }
}

//***CHARACTER STATS***
void ScrollThief::CharacterStats() {
  int max = 1;
  int i = 0;
  bool temp_bool = false;
  cout << "Name: " << player_name
  << "\nXP: " << player_xp
  << "\nGold: " << player_gold
  << "\nWeapon: " << weap_name
  << "\nArmor: " << armor_name
  << "\nHP: " << player_curr_hp << "/" << total_max_hp
  << "\nAttack: " << total_attack
  << "\nDodge: " << total_dodge
  << "\nInvestigation: " << player_invest
  << "\nPerception: " << player_perception
  << "\nCharisma: " << player_charisma << endl;

  game.Skip();
  while (temp_bool == false) {
    cout << "Inventory\n";
    cout << "Enter number for description or 0 to exit.\n";
    for (i = 0; i < 11; i++) {
      if(Inventory[i].carried_ == true) {
        if(Inventory[i].item_number_ > max) {
          max = Inventory[i].item_number_;
        }
        cout << Inventory[i].item_number_ << " - " << Inventory[i].item_name_ << ": " << Inventory[i].amount_ << endl;
      }
    }
    choice = reader.readInt(0, max);
    ClearScreen();
    if(choice > 0 && Inventory[choice-1].carried_ == true) {
      cout << Inventory[choice-1].item_description_ << endl;
      game.Skip();
    } else if(choice > 0 && Inventory[choice-1].carried_ == false) {
      cout << "You don't have that item.\n";
      game.Skip();
    } else {
      temp_bool = true;
    }
  }
}

//***COMBAT CHECK***
bool ScrollThief::AttackCheck(int enemy_attack, int enemy_dodge, int enemy_curr_hp, int enemy_max_hp, string enemy_name, int xp_value, int gold_value, bool actual_fight) {
  bool outcome = false;
  srand(time(0));
  while (enemy_curr_hp != 0 && player_curr_hp != 0) {

    //***Player's Turn***
    cout << player_name << ": " << player_curr_hp << endl;
    cout << enemy_name << ": " << enemy_curr_hp << endl;
    cout << "What will you do?";
    cout << "\n1 - Attack\n2 - Use Healing Potion: " << Inventory[0].amount_ << endl;
    choice = reader.readInt(1, 2);
    ClearScreen();
    switch (choice) {
      case 1: {
        int player_check = rand() % 6 + total_attack;
        int enemy_defense = rand() % 6 + enemy_dodge;
        cout << player_name << " swung their " << weap_name << " at " << enemy_name << endl;
        if(player_check > enemy_defense) {
          cout << "Attack hit.\n";
          enemy_curr_hp--;
          cout << enemy_name << " HP: " << enemy_curr_hp << endl;
        } else {
          cout << "Attack missed.\n";
        }
      }
      break;
      case 2:
        if(Inventory[0].amount_ > 0) {
          cout << player_name << " used a Healing Potion\n";
          Inventory[0].amount_--;
          if(player_curr_hp <= total_max_hp-4) {
            player_curr_hp += 4;
          } else {
            player_curr_hp = total_max_hp;
          }
          cout << player_name << " was healed.\nHP: " << player_curr_hp << "/" << total_max_hp << endl;
        } else {
          cout << player_name << " looked for healing potions that weren't there.\n";
        }
      break;
    }
    game.Skip();

    //***Enemy's Turn***
    if(enemy_curr_hp > 0) {
      int enemy_check = rand() % 6 + enemy_attack;
      int player_defense = rand() % 6 + total_dodge;
      //cout << enemy_check << " " << player_defense << endl;
      cout << enemy_name << " attacked back!\n";
      if(enemy_check > player_defense) {
        cout << "Attack hit.\n";
        player_curr_hp--;
        cout << player_name << " HP: " << player_curr_hp << endl;
      } else {
        cout << "Attack missed.\n";
      }
      game.Skip();
    }
  }

  if(enemy_curr_hp <= 0) {
    cout << player_name << " defeated " << enemy_name << endl;
    outcome = true;
    game.Set_Gold_XP('X', xp_value);
    ClearScreen();
    game.Set_Gold_XP('G', gold_value);
  } else if (actual_fight == false) {
    outcome = false;
  } else {
    game.GameOver();
  }
  return outcome;
}

// ***GOLD OR XP GAIN***
void ScrollThief::Set_Gold_XP(char type, int amount) {
  ClearScreen();
  if(type == 'G') {
    player_gold += amount;
    if(amount >= 0) {
      cout << amount << " gold gained.\n";
    } else {
      cout << amount << " gold lost.\n";
    }
  } else if(type == 'X') {
    player_xp += amount;
    cout << amount << " XP gained.\n";
    while (player_xp >= 100) {
      cout << "You can level up!\n";
      game.Skip();
      attr_points ++;
      game.Level_Up();
      player_xp -= 100;
      cout << "Finished Level Up.\n";
    }
  }
  game.Skip();
}

// ***SKILL CHECK***
bool ScrollThief::SkillCheck(int threshold, int modifier) {
  bool outcome = false;
  int check = rand() % 6 + modifier;
  if(check > threshold) {
    //cout success?
    outcome = true; //Success!!
  } else {
    //cout faiilure?
    outcome = false; //Failure!!
  }
  return outcome;
}

// ***LOCATION TRAVEL***
void ScrollThief::LocationTravel(int location) {
  cout << "You travel to " << TravelMenu[location].name_ << endl
       << TravelMenu[location].description_ << endl;
  game.Skip();
}

void ScrollThief::SythrowPlaza() {
  int max = 1;
  if(TravelMenu[2].visited_ == true && TravelMenu[3].visited_ == true && TravelMenu[4].visited_ == true && Inventory[2].carried_ == false) {
    game.Ambush();
  }
  cout << "You travel out to Sythrow Plaza. Where to next?\n";
  cout << "\n0 - Character Stats\n";
  for (int i = 0; i < 6; i++) {
    if(TravelMenu[i].unlocked_ == true) {
      if(TravelMenu[i].number_ > max) {
        max = TravelMenu[i].number_;
      }
      cout << TravelMenu[i].number_ << " - " << TravelMenu[i].name_ << endl;
    }
  }

  choice = reader.readInt(0, max);
  ClearScreen();
  switch (choice) {
    case 0:
    game.CharacterStats();
    break;
    case 1:
    game.LocationTravel(0);
    game.RapidLantern();
    break;
    case 2:
    game.LocationTravel(1);
    game.KeltiiLibrary();
    break;
    case 3:
    game.LocationTravel(2);
    game.WizardShop();
    break;
    case 4:
    game.LocationTravel(3);
    game.TrainingYard();
    break;
    case 5:
    game.LocationTravel(4);
    game.NobleShop();
    break;
    case 6:
    game.LocationTravel(5);
    game.DragonSwamp();
    break;
  }
}

void ScrollThief::RapidLantern() {
  bool temp_bool = false;
  if(TravelMenu[0].visited_ == false) {
    cout << "The afternoon sun is just beginning to peek out from behind heavy \n" <<
    "clouds, sending down the last shafts of golden light through the dirty windows \n" <<
    "of the Rapid Lantern, an inn on the southern edge of Sythrow Plaza.\n" <<
    "The door opens and a middle-aged female human enters the inn, tall enough \n" <<
    "that she ducks to avoid striking the frame with the top of her enameled, \n" <<
    "black helm. She pulls a vacant chair out from your table and seats herself, \n" <<
    "adjusting the sword at her hip as she does so.\n" <<
    "\"I am Knight Tarra Wolfleaf,\" she says, her helm adding a hollow note \n" <<
    "to her voice, \"and I have a job for you.\"\n";

    cout << "\n1 - What kind of job?\n2 - How much will I get?\n3 - Not interested.\n";
    choice = reader.readInt(1, 3);
    ClearScreen();
    switch (choice) {
      case 1:
        cout << "\"Hopefully nothing to difficult.\"\n";
      break;
      case 2:
        cout << "\"I will provide fifty gold for the job. Will this suffice to help?\"\n";
        cout << "\n1 - Ask for more. [Charisma]\n2 - Agree.\n3 - Decline.\n";
        choice = reader.readInt(1, 3);
        ClearScreen();
        switch (choice) {
          case 1:
            temp_bool = true;
            if(SkillCheck(7,player_charisma)) {
              convince_wolfleaf = true;
              cout << "Persuasion success.\n";
              game.Skip();
              game.Set_Gold_XP('X', 10);
              cout << "\"I can provide additional gold if you really need it.\"\n";
            } else {
              cout << "Persuasion failure.\n";
              cout << "\"Apologies. I can't afford to provide anymore.\"\n";
            }
          break;
          case 2:
            temp_bool = true;
            cout << "\"Perfect! I appreciate your help.\"\n";
          break;
          case 3:
            cout << "\"I will need to turn to other venues then. Thank you for\n" <<
            "your time.\" She walks out the door, just as quickly as she came in.\n";
            game.GameOver();
          break;
        }
      break;
      case 3:
        cout << "\"Very well...\" She sighs and walks away.\n";
        game.GameOver();
      break;
    }
    game.Skip();
    cout << "\"There has been a string of thefts from various shops recently within Scholar's Square.\n" <<
    "Thefts are fairly commonplace but thefts that only end up with one book from \n" <<
    "each location being stolen, I feel it is leading to something much worse.\n" <<
    "The thefts started six nights ago, occuring every two days. The rest of \n" <<
    "the Silver Guard don't see this as much of an issue so there aren't \n" <<
    "resources to help. Cylla Bellren, the Scribe Master at Keltii's \n" <<
    "Library can give you more information on the thefts.\"\n";

    if(temp_bool == false) {
      game.Skip();
      cout << "\"I will provide seventy five gold for the job. Will this suffice\nto help?\"\n";
      cout << "\n1 - Ask for more. [Charisma]\n2 - Agree.\n3 - Decline.\n";
      choice = reader.readInt(1, 3);
      ClearScreen();
      switch (choice) {
        case 1:
          if(SkillCheck(5, player_charisma)) {
            convince_wolfleaf = true;
            cout << "Persuasion success.\n";
            game.Skip();
            game.Set_Gold_XP('X', 10);
            cout << "\"I can provide an additional ten gold if you really need it.\"\n";
          } else {
            cout << "Persuasion failure.\n";
            cout << "\"Apologies. I can't afford to provide anymore.\"\n";
          }
        break;
        case 2:
          cout << "\"Perfect! I appreciate your help.\"\n";
        break;
        case 3:
          cout << "\"I will need to turn to other venues then. Thank you for\n" <<
          "your time.\" She walks out the door, just as quickly as she came in.\n";
          game.GameOver();
        break;
      }
    }
    temp_bool = false;
    game.Skip();

    cout << "\"Your help is appreciated.\" She nods, stands and walks out \n" <<
    "the door and you are left alone.\n";
    game.Skip();
    TravelMenu[0].visited_ = true;
    TravelMenu[1].unlocked_ = true;
  } else {
    cout << "\"Welcome to the Rapid Lantern. Stopping by to rest for the evening?\n" <<
    "If so, it's ten gold.\"\n" <<
    "Current gold: " << player_gold << endl;
    cout << "\n1 - Yes\n2 - No\n";
    choice = reader.readInt(1, 2);
    ClearScreen();
    if(choice == 1) {
      if(player_gold >= 10) {
        player_gold -= 10;
        game.Set_Gold_XP('G', -10);
        player_curr_hp = total_max_hp;
        cout << player_name << " slept for the night.\n" <<
        "Health restored.\n";
      } else {
        cout << "Not enough gold.\n";
      }
    } else {
      cout << "\"Thanks for the visit.\"\n";
    }
    game.Skip();
  }
}

// ***Marten's Training Yard***
void ScrollThief::TrainingYard() {
  bool temp_bool = false;
  if(TravelMenu[3].visited_ == false) {
    cout << "A middle-aged dwarf props one of the double doors open with the stump\n" <<
    "of an arm that has been amputated just above the elbow.  Inside, a wide\n" <<
    "practice yard is surrounded by covered walkways set with chairs and tables.\n" <<
    "A number of people in various stages of exhaustion rest in the shade.\n" <<
    "The dwarf frowns as he bids you enter, \"Come 'bout the book, I suppose?\"\n";
    game.Skip();
    cout << "In the yard, a handful of men square off against a single dwarven\nwoman wielding a pair of handaxes. From the looks on the faces of\nher opponents, she seems to be holding her own quite well.\n";
    game.Skip();
  } else {
    cout << "\"Back again, eh?\" Marten grumbles.\n";
  }

  while (temp_bool == false) {
    cout << "\"So what questions do ya got?\"\n";
    cout << "\n1 - Book's Topic\n2 - Book Ownership\n3 - What Happened\n";
    if(fought_vera == false) {
      cout << "4 - The Girl\n";
    } else {
      cout << "4 - Vera\n";
    }
    cout << "5 - No More Questions\n";
    choice = reader.readInt(1, 5);
    ClearScreen();
    switch (choice) {
      case 1:
      cout << "\"It is a small book 'bout a foot by half with red leather and\n" <<
      "black letters on the edge. It was all bout Ren o' the Blade.\"\n";
        cout << "\n1 - Ren?\n2 - Other Questions\n";
        choice = reader.readInt(1, 2);
        ClearScreen();
        if (choice == 1) {
          cout << "\"O'l Ren nearly single-handedly defeated Tyranthraxus.\n" <<
          "Tyranthraxus was controllin' the body of a bronze dragon at the time\n" <<
          "and took over Phlan. After the dragon's defeat, he fled into a\n" <<
          "Pool of Radiance beneath Valjevo Keep. But no one has been able to\n" <<
          "find it.\"\n";
        }
      break;
      case 2:
      cout << "\"I have owned that book for nearly a decade. The rest of the collection\n" <<
      "is in the library. I'd be grateful if ya can return it but I won't be\n" <<
      "gettin' my hopes up.\"\n";
      break;
      case 3:
      cout << "\"The book was just gone in the mornin'. It sits on the\n" <<
      "shelf normally.\"\n";
      break;
      case 4:
      if(fought_vera == false) {
        cout << "\"That's my daughter, Vera. She's the best I've seen for a long time\n" <<
        "Her mom died when Vera was young so I was left to raise her the best I could.\"\n";
      } else {
        cout << "Vera hefts her handaxes over her shoulder.\n";
      }
      cout << "\n1 - Ask to Fight\n2 - Other Questions\n";
      choice = reader.readInt(1, 2);
      ClearScreen();
      if (choice == 1) {
        cout << "\"Grab a practice weapon and try yer luck.\"\n";
        game.Skip();
        if(game.AttackCheck(3, 3, 5, 5, "Vera", 25, 5, false) == true) {
          cout << "\"Very impressive!\"\n";
        } else {
          cout << "You fall to the ground. Defeated.\n" <<
          "\"That was a good try. Still impressed you did that well,\" Marten applauds\n" <<
          "as he hands you a healing potion to use.\n";
          player_curr_hp += 2;
        }
        if(Inventory[1].carried_ == false) {
          game.Skip();
          cout << "\"I'll let you borrow the only other book I have in Ren's collection.\"\n" <<
          "He goes inside for a couple minutes, then comes back out with a red leather\n" <<
          "book and hands it to you.\n" <<
          "\"Check on the rest of my collection, will ya?.\"\n";
          game.Skip();
          Inventory[1].carried_ = true;
          Inventory[1].amount_ += 1;
          game.Set_Gold_XP('X', 25);
          cout << "\"She'll be up for fightin' anytime.\"\n";
        }
        fought_vera = true;
      }
      break;
      case 5:
      cout << "\"Fair 'nough.\"\n";
      temp_bool = true;
      break;
    }
    game.Skip();
  }
  TravelMenu[3].visited_ = true;
}

// ***Aria's Shop***
void ScrollThief::WizardShop() {
  bool temp_bool = false;
  if(TravelMenu[2].visited_ == false) {
    cout << "The door to this rather unassuming building opens, and a female half-elf\n" <<
    "wearing robes stands in the doorway. The smell of flowers and incense\n" <<
    "flow from within. Perched on the elf's shoulder is a small, grey-furred\n" <<
    "monkey. \"I gather you are here to interrogate me about the missing book?\"\n" <<
    "Aria smiles, \"Master Opanrael is certainly distrustful.\"\n";
  } else {
    cout << "\"Questions or potions this time?\"\n";
  }

    while (temp_bool == false) {
      cout << "\"Begin your interrogation.\"\n";
      cout << "\n1 - Master Opanrael\n2 - The Book\n3 - Where the Book was stored\n4 - What Happened\n5 - No More Questions\n";
      choice = reader.readInt(1, 5);
      ClearScreen();
      switch (choice) {
        case 1:
        cout << "\"Master Opanrael is the Head Curator at Keltii's Library.\"\n";
        break;
        case 2:
        cout << "\"The book belongs to the library but I have had it for two years.\n" <<
        "Its topic was discussing the Weave's history and hypotheses about its nature.\n" <<
        "The book had beautiful, white leather and golden lettering with a white,\n" <<
        "silk ribbon placeholder with the symbol of Mystra on the front cover.\"\n";
        break;
        case 3:
        cout << "\"The book was considered very valuable. For that reason, only a\n" <<
        "few people knew that I had it. So whoever stole it gained access to the\n" <<
        "library's records. I usually kept the book in a glass display.\"\n";
        game.Skip();
        cout << "The case is crafted with breathtaking quality.\n";
        if(game.SkillCheck(5, player_perception)) {
          game.Skip();
          cout << player_name << " notices runes around the edge of each pane of\n" <<
          "glass. One of the runes have been subtly marred.\n";
          if(game.SkillCheck(5, player_invest)) {
            game.Skip();
            cout << "The imperfection was deliberately made and completely defeated\n" <<
            "the case's protective enchantments. It was the work of a professional.\n";
          }
        }
        break;
        case 4:
        if(convince_aria == false){
          cout << "\"The book was the only thing taken.\"\n";
          if(game.SkillCheck(4, player_perception)) {
            game.Skip();
            cout << player_name << " notices that Aria sounds a little off when saying that.\n";
            cout << "\n1 - Ask if that really was the only thing stolen [Charisma]\n2 - Ignore Feeling\n";
            choice = reader.readInt(1, 2);
            ClearScreen();
            if(choice == 1) {
              if(SkillCheck(5, player_charisma)) {
                convince_aria = true;
                cout << "Aria lets out a sigh.\n" <<
                "\"You are right. I lost a couple spell scrolls and a horn of blasting.\n" <<
                "I spent a lot of time setting up magical protections around the book\n" <<
                "and these items to prove to Master Opanrael that the book was safe.\n" <<
                "I don't want to have to return all my other library books because\n" <<
                "one was stolen.\"\n";
                cout << "\n1 - Offer to talk to Master Opanrael\n2 - Continue\n";
                choice = reader.readInt(1, 2);
                ClearScreen();
                if(choice == 1) {
                  cout << "\"I would appreciate that greatly.\" She then writes a note,\n" <<
                  "gives it to her monkey, and it scampers away out the window.\n";
                  game.Skip();
                  game.Set_Gold_XP('X', 25);
                  cout << "\"Master Opanrael will be aware of your upcoming visit.\"\n";
                }
              } else {
                cout << "\"I can assure you that was it.\"\n";
              }
            }
          }
        } else {
          cout << "\"Thanks for offering to talk to Master Opanrael.\"\n";
        }
        break;
        case 5:
        cout << "\"Glad I could help.\"\n";
        temp_bool = true;
        break;
      }
      game.Skip();
    }
    temp_bool = false;
    while (temp_bool == false) {
      cout << "\"Since you are here, would you like to purchase any potions?\n" <<
      "They are twenty five gold each.\"\n" <<
      "Current gold: " << player_gold << endl;
      cout << "\n0 - No\nEnter number to purchase (Up to 10)\n";
      choice = reader.readInt(0, 10);
      ClearScreen();
      if(choice > 0) {
        if(player_gold >= choice*25) {
          Inventory[0].amount_ += choice;
          cout << player_name << " purchased " << choice << " healing potions.\n";
          game.Skip();
          game.Set_Gold_XP('G', choice*-25);
          cout << "\"Purchase more if you run out!\" she smiles.\n";
        } else {
          cout << "Not enough gold.\n";
        }
      } else {
        cout << "\"Thanks for stopping by!\"\n";
        temp_bool = true;
      }
      game.Skip();
    }
  temp_bool = false;
  TravelMenu[2].visited_ = true;
}

// ***Agin's Shop***
void ScrollThief::NobleShop() {
  bool temp_bool = false;
  if(TravelMenu[4].visited_ == false) {
    cout << "\"Oh, hello there,\" Lamarck deadpans; a sarcastic look on his face,\n"
    "\"I'm very excited to be a part of this.\"\n";
  } else {
    cout << "\"Forgot something?\"\n";
  }
  game.Skip();

  while (temp_bool == false) {
    cout << "\"What must you know?\"\n";
    cout << "\n1 - The Book\n2 - Book Storage Location\n3 - Family\n4 - No More Questions\n";
    choice = reader.readInt(1, 4);
    ClearScreen();
    switch (choice) {
      case 1:
      cout << "\"The title of the book is Lords and Lineages of Phlan. All noble\n" <<
      "houses that have resided here have been recorded in that book. It goes back\n" <<
      "seven hundred years. My family had possession of the book for two\n" <<
      "centuries. Despite it having so much history, it has little monetary value.\n" <<
      "It is a very large book, a foot thick, two feet wide and just as long.\"\n";
      break;
      case 2:
      cout << "\"I kept the book locked and protected by powerful spellcraft in\n" <<
      "my desk drawer. But I don't know why anyone would steal it.\"\n";
      cout << "\n1 - Examine Drawer\n2 - Back to Questions\n";
      choice = reader.readInt(1, 2);
      ClearScreen();
      if(choice == 1) {
        if(game.SkillCheck(4, player_invest)) {
          cout << "You find the remnants of a laughably simple trap that did nothing\n" <<
          "more than ring a tiny bell concealed inside of the desk.\n";
        } else {
          cout << "There doesn't seem to be anything special about the drawer.\n";
        }
      }
      break;
      case 3:
      cout << "\"The Lamarck family has long been considered to be well-respected\n" <<
      "scholars in the field of documenting familial lineages.\"\n";
      break;
      case 4:
      cout << "\"Then why are you still here?\"\n";
      temp_bool = true;
      break;
    }
    game.Skip();
  }
  if(TravelMenu[4].visited_ == false) {
    if(game.SkillCheck(4, player_perception)) {
      cout << "Agin avoids eye contact constantly.\n";
      cout << "\n1 - Ask Why He Is Uncomfortable [Charisma]\n2 - Ignore\n";
      choice = reader.readInt(1, 2);
      ClearScreen();
      if(choice == 1){
        if(game.SkillCheck(5, player_charisma)) {
          cout << "\"Fine. I will tell you. Despite my family's long-standing claim\n" <<
          "to nobility, we are of no actual relation to House Lamarck. In truth,\n" <<
          "the last surviving members of the Lamarck line died nearly two hundred\n" <<
          "years ago. My great, great grandfather made a couple clever forgeries\n" <<
          "in Lords and Lineages of Phlan, which allowed his family to claim descent\n" <<
          "from the then-dead Lamarck line. With no one to contest the claim,\n" <<
          "there was no doubt as to its legitimacy. Please do not tell anyone this.\n" <<
          "If you find the book and keep my secret, I will reward you with double\n" <<
          "anyone at the library will give you. Will you accept my offer?\"\n";
          cout << "\n1 - Agree\n2 - Decline\n";
          choice = reader.readInt(1, 2);
          ClearScreen();
          if(choice == 1) {
            cout << "\"Perfect. Here is fifty gold for keeping my secret and you\n" <<
            "shall get double of the library's offer upon returning the book.\"\n";
            game.Skip();
            game.Set_Gold_XP('G', 50);
          } else {
            cout << "\"You will ruin me. Get out!\"\nHe pushes you out the door and slams it closed.\n";
          }
          game.Set_Gold_XP('X', 25);
          cout << "You exit the building as Agin dismisses you.\n";
        } else {
          cout << "\"I am busy, so I am finished with this conversation.\"\n";
        }
      }
    }
    game.Skip();
  }
  TravelMenu[4].visited_ = true;
}

void ScrollThief::Ambush() {
  cout << "As usual, Sythrow Plaza is a hive of activity, with hundreds of\n" <<
  "people milling about.\n" <<
  "As you round a corner, an elf steps from the mouth of a nearby\n" <<
  "alley and stops in the street in front of you.\n" <<
  "\"The Welcomers send their regards and have information that you\n" <<
  "may find useful. Follow me,\" the elf says with a worried look\n" <<
  "before ducking back into the alley.\n";
  game.Skip();
  cout << "\n1 - Follow\n2 - Continue Past\n";
  choice = reader.readInt(1, 2);
  ClearScreen();
  if(choice == 1) {
    cout << "As you turn the corner in the alley, it opens into a cul-de-sac\n" <<
    "about forty feet across. The elf stops in front of you and turns around,\n" <<
    "a wide grin on his face.\n" <<
    "\"You've had your nose where it doesn't belong,\" the elf threatens,\n" <<
    "\"Time for us to bloody it.\"\n";
  } else {
    cout << "You feel a sense of unease, and it is a few moments before you\n" <<
    "realize what it is; the hustle and bustle of the busy street seems to\n" <<
    "be gone.\n" <<
    "People are hurriedly ducking into doors and rushing down the street;\n" <<
    "leading their children by the hand. As the last of the crowd thins,\n" <<
    "you see a familiar face standing in the street.\n" <<
    "\"I don't take kindly to being ignored,\" the elf says, drawing a\n" <<
    "dagger from his belt.\n";
  }
  game.Skip();
  if(game.AttackCheck(3, 1, 6, 6, "Assassin", 50, 30, true)) {
    cout << "After defeating the assassin, you find a note sticking out of\n" <<
    "his pocket.\nYou grab the note and put it in your pouch.\n";
    Inventory[2].carried_ = true;
    Inventory[2].amount_ += 1;
    game.Skip();
  }
}

void ScrollThief::KeltiiLibrary() {
  bool temp_bool = false;
  if(Inventory[2].carried_ == false && TravelMenu[1].visited_ == false) {
    cout << "The Scribe Master's office is small and very cramped - a problem\n" <<
    "made worse by the sheer number of books that are stacked haphazardly\n" <<
    "on every piece of furniture within. A sign on the door reads:" <<
    "\n\nCylla Bellren\nScribe Master\n\n" <<
    "Beneath that, a small piece of wood hangs on a nail with the word 'IN' \n" <<
    "written on it in chalk.\n" <<
    "As you knock on the door, a voice from an unseen source calls out\n" <<
     "\"Just a moment!\"\nThere is the creaking of a wooden chair, a muttered\n" <<
     "curse and then a loud crashing noise as a few stacks of books are\n" <<
     "knocked to the floor, revealing a young-looking halfling with short\n" <<
     "blonde hair; her hands and shirt stained with smudges of blue ink.\n" <<
     "\"How can-can I help you?\" she sheepishly asks.\n";

     cout << "\n1 - Ask about stolen books\n2 - Ask if she is ok\n";
     choice = reader.readInt(1, 2);
     ClearScreen();
     if (choice == 2) {
        cout << "\"Oh that happens a-all the time. I am fine. Thanks for asking.\"\n";
     }
     cout << "\"Did Knight Wolfleaf send you?\"\n";
     cout << "\n1 - Yes\n2 - No\n";
     choice = reader.readInt(1, 2);
     ClearScreen();
     switch (choice) {
       case 1:
        cout << "\"Thank the gods. I need help but she wasn't sure if she could\n" <<
        "find anyone else to help.\"\n";
       break;
       case 2:
       cout << "\"Well if you are here to help, I will accept it.\"\n";
       break;
     }
     cout << "\"Three rare tomes have b-been stolen. The first, which belongs to the\n" <<
     "library, was in the possession of a wizard named Aria Glenmiir. The tome is\n" <<
     "called The Weave: A P-Practical Observation of Impractical Occurrences.\n" <<
     "The second was a personal memoire of an old adventurer. That one belonged\n" <<
     "to Marten Foss. He runs a training y-yard in town.\n" <<
     "The last and most recently taken was a geneology book owned by a local\n" <<
     "noble named Agin Lamarck. He has a small b-building, writing legal documents.\"\n";
     game.Skip();

     cout << "\"If the books are returned safely, I can reward you with a hundred\n" <<
     "gold. I s-should probably let you get to it, unless you have questions.\"\n";

     while (temp_bool == false) {
       cout << "\n1 - Sounds good\n2 - Ask for more [Charisma]\n3 - Blue Ink\n";
       choice = reader.readInt(1, 3);
       ClearScreen();
       switch (choice) {
         case 1:
          cout << "I am so g-grateful. Please be safe.\n";
          temp_bool = true;
         break;
         case 2:
           if(SkillCheck(5, player_charisma)) {
             convince_cylla = true;
             cout << "Persuasion success.\n";
             game.Skip();
             game.Set_Gold_XP('X', 10);
             cout << "\"I might be able to pull some additional funding from the library.\"\n";
           } else {
             cout << "Persuasion failure.\n";
             cout << "\"That's all that is available.\"\n";
           }
           temp_bool = true;
         break;
         case 3:
           cout << "\"This blue ink is used on all official ledgers for the library.\n" <<
           "It's the scribe's curse,\" she chuckles.\n";
         break;
       }
       game.Skip();
     }
     TravelMenu[1].visited_ = true;
     TravelMenu[2].unlocked_ = true;
     TravelMenu[3].unlocked_ = true;
     TravelMenu[4].unlocked_ = true;
  } else if (Inventory[2].carried_ == false && TravelMenu[1].visited_ == true){
    cout << "Cylla is organizing the books in her office when you walk in.\n" <<
    "\"You're back. Have you found anything yet?\"\n";
    game.Skip();
  } else {
    cout << "Cylla's office is a bit more organized at this point.\n" <<
    "\"You have n-news?\"\n";
    cout << "\n1 - Show Note\n2 - Accuse\n3 - Nothing Yet\n";
    choice = reader.readInt(1, 3);
    ClearScreen();
    switch (choice) {
      case 1:
      cout << "You pull out the note from the assassin.\n";
      break;
      case 2:
      cout << "\"I would never do such a t-thing! I am quite offended you would\n" <<
      "even think of such a thing. What would make you think that?\"\n";
      cout << "\n1 - Show Note\n2 - No Reason\n";
      choice = reader.readInt(1, 2);
      ClearScreen();
      if (choice == 1) {
        cout << "\"The blue ink may be a bit of a pointer but I am not the only\n" <<
        "one who works here.\"\n";
      } else {
        cout << "\"Just go find something and stop accusing random people!\"\n";
        game.SythrowPlaza();
      }
      break;
      case 3:
      cout << "Let me know w-when you do.\n";
      game.Skip();
      game.SythrowPlaza();
      break;
    }
    game.Skip();
    cout << "Cylla frowns and rubs her chin thoughtfully, leaving a blue\n" <<
    "smudge. \"If the thief had access to this ink,\" she says quietly,\n" <<
    "\"it doesn't just sound like we're dealing with a thief; it sounds\n" <<
    "like we're dealing with a rat.\"\n";
    game.Skip();

    cout << "\"Let's go talk to Master Opanrael about this. He is busy but this\n" <<
    "is very important.\" She takes you to the upper floor of the library to\n" <<
    "Opanrael's office.\n";
    game.Skip();

    cout << "The smell of paper, glue and ink fills your nose as the door to\n" <<
    "the Master Libraian's office opens. Before you stands a man that appears\n" <<
    "to be as dusty and worn as the books and scrolls that are stacked neatly\n" <<
    "around his office.\n";
    game.Skip();

    if (convince_aria == true) {
      cout << "\"Ah, yes. I trust you are the...\" he pauses as he looks you\n" <<
      "over, \"...people that Madam Glenmiir mentioned in her note. What\n" <<
      "precisely can I do for you?\"\n";
    } else {
      if (game.SkillCheck(6, player_charisma)) {
        cout << "\"Well you don't have an appointment,\" the Curator says\n" <<
        "steepling his fingers, \"but I may be able to spare a moment.\"\n";
        game.Set_Gold_XP('X', 10);
      } else {
        cout << "\"I am busy at the moment so please wait outside my office\n" <<
        "until I am finished.\"\n";
        game.Skip();
        cout << "After waiting outside his office for over an hour, Master\n" <<
        "Opanrael finally shuffles out.\n" <<
        "\"Despite your complete and utter lack of etiquette and more\n" <<
        "importantly, an appointment, I thank you for your patience. What\n" <<
        "can I do for you?\"\n";
      }
    }
    while (temp_bool == false) {
      cout << "\n1 - Show Note\n2 - Stolen Books\n3 - Finished\n";
      choice = reader.readInt(1, 3);
      ClearScreen();
      switch (choice) {
        case 1:
        cout << "\"This ink is used by the scribes of the library. Perhaps his\n" <<
        "disappearance is not a coincidence but you can look for Ellison.\n" <<
        "He was scheduled to work in the Archives today.\"\n";
        if(Inventory[1].carried_ == true) {
          game.Skip();
          cout << "\"I see you have one of Ren O' the Blade's Memoires. This\n" <<
          "will help track down the rest of the collection quickly.\" He thumbs\n" <<
          "through a couple pages and writes down the location of the section\n" <<
          "on a note and hands it to you.\n";
          Inventory[3].carried_ = true;
          Inventory[3].amount_ += 1;
        }
        break;
        case 2:
        cout << "\"I have heard of their disappearance but nothing more. I\n" <<
        "have other things to worry about right now as two of my employees\n" <<
        "are missing. Garda Greenleaf and Ellison Berenger have not shown up,\n" <<
        "which is odd for those two.\"\n";
        while (temp_bool == false) {
          cout << "\n1 - Garda\n2 - Ellison\n3 - Other Questions\n";
          choice = reader.readInt(1, 3);
          ClearScreen();
          switch (choice) {
            case 1:
            cout << "\"Garda Greenleaf is a senior librarian with a flawless\n" <<
            "record of attendance. Superb worker.\"\n";
            break;
            case 2:
            cout << "\"Ellison Berenger has been employed at the library for\n" <<
            "four months and has been a reliable worker.\"\n";
            break;
            case 3:
            cout << "\"Very well.\"\n";
            temp_bool = true;
            break;
          }
          game.Skip();
        }
        temp_bool = false;
        break;
        case 3:
        cout << "\"Good luck in your search.\"\n";
        temp_bool = true;
        break;
      }
      game.Skip();
    }
    cout << "You and Cylla head down to the archives.\n";
    game.Skip();
    game.LibraryArchives();
  }
}

void ScrollThief::LibraryArchives() {
  bool temp_bool = false;
  if(visited_archives == false) {
    cout << "Down hallways and staircases, and through passageways and storage rooms, Cylla\n" <<
    "moves with definite purpose; descends staircase after staircase with a lamp\n" <<
    "held over her head.\n" <<
    "Finally, the scribe stops at a door and pushes it open; the smell of stagnant\n" <<
    "air and ancient dust filling the stairwell.\n" <<
    "\"Inside,\" she says.\n";
    game.Skip();

    if(Inventory[3].carried_ == true) {
      cout << "Using Master Opanrael's note, Cylla takes you straight to section\n" <<
      "where the rest of Ren's Memoires are stored.\n";
    } else {
      cout << "Searching through many different sections of the archive, Cylla finds\n" <<
      "the correct section over an hour later.\n";
    }
    game.Skip();

    cout << "Your search has lead you to a small room tucked away in a distant\n" <<
    "corner of the vast Archives. Despite the room's size, it is no less cramped than\n" <<
    "the rest of the Archives, packed tightly with shelves that are near to\n" <<
    "bursting with books, scrolls and other works.\n" <<
    "Rounding a shelf on the far side of the room, you see a small reading table;\n" <<
    "the dark shape of a body slumped over it.\n" <<
    "\"Gods save us! Garda?\" Cylla gasps as she runs into a corner and retches\n" <<
    "violently.\n";
    game.Skip();

    cout << "The body is that of a middle-aged male human weaing a plain set of grey,\n" <<
    "homespun robes. His left hand loosely holds a quill; the tip stained with\n" <<
    "bright blue ink.\n" <<
    "Thin rivulets of dark blood run from his ears; standing in stark contrast\n" <<
    "to the pale flesh of his lifeless face.\n" <<
    "Books are scattered everywhere.\n";
    game.Skip();

    while (temp_bool == false) {
      cout << "Garda's body is slumped over the table with a few open books around it.\n" <<
      "A scroll lays on the ground next to the table. Many books are scattered about.\n";
      cout << "\n1 - Death\n2 - Body\n3 - Books\n4 - Scroll\n5 - Finished\n";
      choice = reader.readInt(1, 5);
      ClearScreen();
      switch (choice) {
        case 1:
        cout << "Garda died from a single blow to his head.\n";
        if(SkillCheck(5, player_perception)) {
          cout << "He was killed less than two hours ago.\n";
        }
        break;
        case 2:
        cout << "One of the belt loops has been cut. Cylla has a similar belt loop\n" <<
        "to hold keys.\n";
        break;
        case 3:
        if(Inventory[4].carried_ == false) {
          cout << "Three books are on the table. Two small red books, Ren's Memoires,\n" <<
          "and a large white one, The Weave book stolen from Aria.\n";
          if(SkillCheck(5, player_invest)) {
            cout << "Pages are missing from one of Ren's Memoires and the Weave book.\n" <<
            "They both seem to have been on the topic of a Pool of Radiance,\n" <<
            "particularly one below Valjevo Keep.\n";
            game.Skip();
            game.Set_Gold_XP('X', 10);
          }
          cout << "Take the books?\n";
          cout << "\n1 - Yes\n2 - No\n";
          choice = reader.readInt(1, 2);
          ClearScreen();
          if (choice == 1) {
            cout << "You gather the books into your bag.\n";
            Inventory[1].carried_ = true;
            Inventory[1].amount_ += 2;
            Inventory[4].carried_ = true;
            Inventory[4].amount_ += 1;
          } else {
            cout << "You leave the books there.\n";
          }
        } else {
          cout << "There are no more books.\n";
        }
        break;
        case 4:
        cout << "A large scroll lays on the floor.\n";
        if(SkillCheck(5, player_invest)) {
          cout << "It used to be a detect magic scroll.\n";
        }
        break;
        case 5:
        cout << "You exit out of the storage room.\n";
        temp_bool = true;
        break;
      }
      game.Skip();
    }

    cout << "An ear-splitting and groundshaking noise shatters the silence of the archives\n" <<
    "and the sound of collapsing brick, mortar, and bookshelves fills the wake as it\n" <<
    "fades away.\nAll around you, shelves and books begin to fall.\n";
    game.Skip();

    if(SkillCheck(5, total_dodge)) {
      cout << "You narrowly avoid the falling shelves.\n";
      game.Set_Gold_XP('X', 10);
    } else {
      cout << "Shelves come crashing down around you, pinning you. You pull yourself\n" <<
      "out from under the shelves.\n";
      cout << "You take one point of damage.\n";
      player_curr_hp--;
      if(player_curr_hp <= 0) {
        game.GameOver();
      }
    }
    game.Skip();

    cout << "Cylla crawls out from under a book shelf.\n" <<
    "\"I think I broke my arm. The main section of the archives are just down\n" <<
    "this hallway. I need to turn back. Good luck.\"\n";
    game.Skip();

    cout << "At the end of the hallway is a set of large ornate doors, partially\n" <<
    "cracked open.\n";
    game.Skip();

    cout << "This huge room is littered with the ruined remains of bookshelves,\n" <<
    "desks and other furniture. The middle of the room is barren, but is\n" <<
    "blackened with the soot of century-old flames, and charred bones strewn\n" <<
    "about.\n" <<
    "A huge hole appears to have been blasted into the far wall; the ground\n" <<
    "littered with bricks and debris.\n";
    game.Skip();

    cout << "Upon reaching the middle of the room, a shadowy creature appears,\n" <<
    "shrieking and wailing, immediately attacking you.\n";
    game.Skip();

    if(game.AttackCheck(4, 3, 3, 3, "Shadow", 50, 5, true)) {
      cout << "After defeating the Shadow, you reach the hole in the wall.\n";
    }
    game.Skip();

    cout << "This room is approximately 30 feet deep and half as wide. Its walls\n" <<
    "are lined with shelves laden with books and miscellaneous objects. At the\n" <<
    "far end of the room, a silver chest rests on a wooden table.\n" <<
    "A second, similar hole has been blasted on the right wall, beyond\n" <<
    "which the sound of running water can be heard. On the blackened and charred\n" <<
    "floor around this second hole are the remains of a horn; shattered\n" <<
    "nearly beyond recognition.\n";
    game.Skip();

    cout << "The lid on the chest is currently open. The lock on the chest is\n" <<
    "remarkably complex.\n";
    if(SkillCheck(5, player_perception)) {
      cout << "You notice a tiny needle jutting from the keyhole, smudged with\n" <<
      "blood.\n";
    }
    cout << "Inside the chest, a series of racks and boxes on clever, articulated\n" <<
    "hinges unfold and spread out; allowing access to multiple different\n" <<
    "storage spaces simultaneously.\n";
    game.Skip();
    if(SkillCheck(5, player_perception)) {
      cout << "You notice a hidden compartment at the bottom of the chest. It is\n"
      "lined in red satin. Within are two potions. One of healing and the other\n" <<
      "a dark, swirling grey unknown potion.\n";
      game.Set_Gold_XP('X', 25);
      cout << "Drink the other potion? (Only chance to use.)\n";
      Inventory[0].amount_ += 1;
      cout << "\n1 - Yes\n2 - No\n";
      choice = reader.readInt(1, 2);
      ClearScreen();
      if(choice == 1) {
        game.Set_Gold_XP('X', 100);
      } else {
        cout << "The unknown potion bottle begins to melt and the liquid falls\n" <<
        "to the floor, leaving a bitter scent in the air.\n";
      }
    }
    game.Skip();
    cout << "A rope is attached to a bookcase leading down into the dark hole.\n" <<
    "Running water can be heard from below. A stench rises as you draw near to\n" <<
    "the hole. A sewage stench.\n";
  } else {
    cout << "You make your way through the archives to the sewers.\n";
  }
  game.Skip();
  game.Sewers();
}

void ScrollThief::Sewers() {
  if(visited_archives == false) {
    cout << "Climbing down the rope into the sewers reveals two walkways on both\n" <<
    "sides of the flowing channel. As you follow the sound of the water, a roar\n" <<
    "fills the air as the tunnel you are in opens up into a large,\n" <<
    "sixty-foot-wide circular chamber. Water cascades down a steep spillway\n" <<
    "on the far side of the chamber into a pool in the middle of the room.\n" <<
    "A stairway runs alongside the spillway to the daylight above.\n";
    game.Skip();

    cout << "A large, undulating shape moves on the opposite side of the chamber near\n" <<
    "a section of the floor that is blackened and charred-as if by an intense\n" <<
    "flame.\n" <<
    "Quickly, the shape rises up, revealing a large, centipede-like\n" <<
    "creature with many tentacles. It spots you and rushes over.\n";
    game.Skip();

    if(game.AttackCheck(4, 2, 5, 5, "Carrion Crawler", 75, 15, true)) {}
  } else {
    cout << "You follow the same pathway as before to the spillway.\n";
    game.Skip();
  }

  if(Inventory[8].carried_ == false) {
    cout << "A backpack is lying on the ground near the bottom of the spillway.\n" <<
    "Take the backpack?\n" <<
    "\n1 - Yes\n2 - No\n";
    choice = reader.readInt(1, 2);
    ClearScreen();
    if (choice == 1) {
      cout << "You pick up the bag, finding that it contains a few documents.\n" <<
      "One is a map that leads out to Twilight Marsh.\n";
      Inventory[5].carried_ = true;
      Inventory[5].amount_ += 1;
      Inventory[6].carried_ = true;
      Inventory[6].amount_ += 1;
      Inventory[7].carried_ = true;
      Inventory[7].amount_ += 1;
      Inventory[8].carried_ = true;
      Inventory[8].amount_ += 1;
      TravelMenu[5].unlocked_ = true;
    } else {
      cout << "You leave the backpack there.\n";
    }
  } else {
    cout << "Nothing is left by the spillway.\n";
  }
  game.Skip();

  visited_archives = true;
  cout << "You exit out the spillway and make it back to Phlan.\n";
  game.Skip();
}

void ScrollThief::DragonSwamp() {
  int temp_int = 3;
  bool temp_bool = false;
  cout << "On the horizon a large mound rises from the swamp with a gaping\n" <<
  "black hole in the side.\n" <<
  "In front of the hole, a small campfire dances in the gloom. A man sits\n" <<
  "by the fire beside what you assume is a large black dog, curled up at\n" <<
  "his feet. Those assumptions quickly melt away as the form unfurls a pair\n" <<
  "of leathery black wings and cranes its neck towards you before muttering\n" <<
  "something in a strange guttural tongue.\n";
  game.Skip();

  cout << "Ellison looks very tired and sick. His left leg appears freshly\n" <<
  "bandaged but blood is soaking through. He has extensive burns on his\n" <<
  "hands, arms and face as if something he was holding caught fire\n" <<
  "or exploded.\n";
  game.Skip();

  cout << "The dragon begins to talk, and Ellison translates.\n" <<
  "\"You've made it quite far. You won't make it any farther so why\n" <<
  "not ask your questions.\"\n";
  game.Skip();

  while (temp_bool == false && temp_int > 0) {
    cout << "Who do you want to ask questions?\n";
    cout << "\n1 - Ellison\n2 - Dragon\n";
    choice = reader.readInt(1, 2);
    ClearScreen();
    if (choice == 1) {
      cout << "What do you want to ask?\n";
      cout << "\n1 - Stealing Books\n2 - Who For\n";
      choice = reader.readInt(1, 2);
      ClearScreen();
      if (choice == 1) {
        cout << "\"I stole the books to get information on the Pool of Radiance.\n" <<
        "Well the Lineages book was to see if I actually was tied to a royal\n" <<
        "family but there was no connection.\n";
      } else {
        cout << "\"The Cult of the Dragon said I owe one last favor. Once I am\n" <<
        "done with this, I am leaving Phlan and the Cult for good.\"\n";
        cout << "\n1 - Surrender\n2 - Other Questions\n";
        choice = reader.readInt(1, 2);
        if (choice) {
          if (game.SkillCheck(5, player_charisma)) {
            cout << "\"I didn't want to fight in the first place,\" Ellison says\n" <<
            "as he steps away from everyone.\n";
            game.Skip();
            convince_ellison = true;
            temp_bool = true;
            game.Set_Gold_XP('X', 25);
          } else {
            cout << "\"I can't help you.\" Ellison says\n" <<
            "as he steps away from everyone.\n";
          }
        }
      }
    } else {
      cout << "What do you want to ask?\n";
      cout << "\n1 - What Do You Want\n2 - What Part Did You Have\n3 - Who Sent You\n";
      choice = reader.readInt(1, 3);
      ClearScreen();
      switch (choice) {
        case 1:
        cout << "\"I got what I came for. Directions to the Pool of Radiance.\"\n" <<
        "The dragon motions towards a bag strapped to it.\n";
        break;
        case 2:
        cout << "\"I am a courier and enforcer for the Cult. Ellison is nothing.\"\n";
        break;
        case 3:
        cout << "The dragon puffs out its chest, showing off the amulet it wears.\n" <<
        "\"The Cult of the Dragon recognizes my talents.\"\n";
        temp_int++;
        break;
      }
    }
    temp_int--;
    game.Skip();
  }

  cout << "The dragon says something and begins attacking you!\n";
  if(convince_ellison == true) {
    cout << "Ellison ducks into the cave.\n";
  }
  game.Skip();

  if(game.AttackCheck(4, 3, 7, 7, "Rythnax", 100, 0, true)) {
    cout << "Rythnax extends his wings and forces you back. He prepares to fly\n" <<
    "away.\n" <<
    "\n1 - Attack\n2 - Let Go\n";
    choice = reader.readInt(1, 2);
    ClearScreen();
    switch (choice) {
      case 1:
      if(game.AttackCheck(4, 3, 3, 3, "Rythnax", 75, 0, true)) {
        cout << "Rythnax falls to the ground, lifeless. You grab his bag and\n" <<
        "amulet.\n";
        Inventory[10].carried_ = true;
        Inventory[10].amount_ += 1;
        Inventory[11].carried_ = true;
        Inventory[11].amount_ += 1;
      }
      break;
      case 2:
      cout << "You watch as Rythnax flies away into the night.\n";
      break;
    }
  }
  game.Skip();

  if(convince_ellison == true) {
    cout << "Ellison reappears from the cave.\n" <<
    "\"What should I do now?\"\n" <<
    "\n1 - Arrest\n2 - Let Go\n";
    choice = reader.readInt(1, 2);
    ClearScreen();
    if (choice == 1) {
      cout << "You bind Ellison to be taken to the authorities.\n";
      capture_ellison = true;
    } else {
      cout << "You let Ellison go. \"Thank you.\" And he collapses to the ground\n" <<
      "to rest.\n";
    }
  } else {
    cout << "Ellison is nowhere to be found.\n";
  }
  game.Skip();

  cout << "A large cloak is wrapped around the Lords and Lineages book.\n" <<
  "Take the book?\n" <<
  "\n1 - Yes\n2 - No\n";
  choice = reader.readInt(1, 2);
  ClearScreen();
  if (choice == 1) {
    cout << "You pick up the book.\n";
    Inventory[9].carried_ = true;
    Inventory[9].amount_ += 1;
  } else {
    cout << "You leave the book there.\n";
  }
  game.Skip();

  cout << "The dragon left a huge hoard of coins.\n" <<
  "Take them?\n" <<
  "\n1 - Yes\n2 - No\n";
  choice = reader.readInt(1, 2);
  ClearScreen();
  if (choice == 1) {
    cout << "You take the coins.\n";
    game.Set_Gold_XP('G', 300);
  } else {
    cout << "You leave the hoard there.\n";
  }
  game.Skip();

  cout << "You make your way back to Phlan.\n" <<
  "Do you turn in all retrieved items?\n" <<
  "\n1 - Yes\n2 - No\n";
  choice = reader.readInt(1, 2);
  ClearScreen();
  if (choice == 1) {
    int gold_sum = 0;
    int xp_sum = 0;
    if (convince_wolfleaf == true) {
      gold_sum += 100;
    } else {
      gold_sum += 75;
    }
    if (Inventory[1].carried_ == true) {
      gold_sum += 25;
    }
    if (Inventory[4].carried_ == true) {
      gold_sum += 25;
    }
    if (Inventory[9].carried_ == true) {
      gold_sum += 50;
    }
    if (shelves_chest == true) {
      gold_sum += 50;
    }
    game.Set_Gold_XP('G', gold_sum);
  }

  cout << "Both Cylla and Knight Wolfleaf are pleased upon hearing of\n" <<
  player_name << "'s success in tracking down and confronting the Scroll Thief.\n";
  game.Skip();

  if(capture_ellison == true) {
    cout << "Ellison is brought in to stand trial for his crimes, he is convicted\n" <<
    "of the theft and the murder of Garda Greenleaf. However, he escapes\n" <<
    "Stojanow Gate before the Silver Guard is able to mete out his punishment.\n";
    game.Skip();
  }

  if(rythnax_escapes == true) {
    cout << "If Rythnax escapes from the adventurer, Opanrael, Cylla, and the\n" <<
    "adventurer can only guess as to what was contained in the pages that\n" <<
    "he escaped with.\n";
  } else {
    cout << "With the package is intercepted and the wyrmling slain, the adventurer\n" <<
    "and leadership of the library now have a very real-and more terrifying-idea\n" <<
    "of why the Cult is in Phlan.\n";
  }
  game.Skip();
  cout << "Congratulations on finishing the adventure!\n";
  game.Skip();
  game.CharacterStats();
  game.GameOver();
}

// ***Quick Skip Function***
void ScrollThief::Skip() {
  cout << "\n...Press enter to continue...";
  continue_string = reader.readString(true, 0);
  ClearScreen();
}

// ***Game Over***
void ScrollThief::GameOver(){
  cout <<  "   ___                         ___ \n"
       <<  "  / _ \\__ _ _ __ ___   ___    /___\\_   _____ _ __ \n"
       <<  " / /_\\/ _` | '_ ` _ \\ / _ \\  //  /| \\ / / _ \\ '__|\n"
       <<  "/ /_\\\\ (_| | | | | | |  __/ / \\_// \\ V /  __/ |   \n"
       <<  "\\____/\\__,_|_| |_| |_|\\___| \\___/   \\_/ \\___|_|   \n";

  game.Skip();
  game.Start();
}

// DO NOT ALTER
void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}
