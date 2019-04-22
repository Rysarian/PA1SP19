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


int main() {
  ScrollThief game;

  game.Start();

  // This ends our program
  return 0;
}
