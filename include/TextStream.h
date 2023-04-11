#ifndef TEXTSTREAM_H
#define TEXTSTREAM_H

#include<string>
#include <vector>
#include"Player.h"
#include"LocationList.h"



/**
* Reads dialogue from text files and checks if names
* are present in lists
*/

class TextStream {
 public:
  /**
  * Dialogue for an item interacting on a character
  * @param a string of the name of character to be acted upon
  * @return a bool if successful
  */
  void characterInteract(std::string);

  /**
  * Dialogue for the entrance to a location with descriptions
  * @param a string of the name of the location
  * @return a bool if successful
  */
  void locationEnter(std::string);

  /**
  * Fixes inputted words for use in the code
  * @param a string containg the input to be fixed
  * @return a string of the fixed input
  */
  std::string fixText(std::string);
  /**
  * getter func for file Content
  * @param a string containg the file
  /* @param address of a vector of string type
  * @return bool to check the exictance of the file
  */

  bool getFileContent(std::string, std::vector<std::string>&);
  /**
  * getter func for indices
  * @param a string containg the name of the index
  * @param vector of string type
  * @return a int type
  */
  int getIndex(std::vector<std::string>, std::string);
  /**
  * getter func for the dialogue of the character
  * @param a string to be used to check
  * @return bool to check if the diagolue matches
  */
  bool getDialogue(std::string);
};
#endif // TEXTSTREAM_H
