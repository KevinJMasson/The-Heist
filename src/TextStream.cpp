#include"TextStream.h"
#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::string TextStream::fixText(std::string s) {
  std::string fixed;
  for (unsigned int i = 0; i < s.length(); i++) {
      fixed += toupper(s[i]);
    }
  return fixed;
}

bool TextStream::getFileContent(std::string fileName,
std::vector<std::string> & vecOfStrs) {
    std::ifstream in(fileName.c_str());
    std::string str;

    if (!in) {
        std::cerr << "Cannot open the File : "<< fileName << std::endl;
        return false;
    }

    while (std::getline(in, str)) {
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }

    in.close();

    return true;
}

int TextStream::getIndex(std::vector<std::string> vecOfStrs, std::string key) {
    auto it = find(vecOfStrs.begin(), vecOfStrs.end(), key);

    // If element was found
    if (it != vecOfStrs.end()) {
        int index = it - vecOfStrs.begin();
        return index;
    } else {
        return -1;
    }
}

bool TextStream::getDialogue(std::string key) {
    int index;
    std::vector<std::string> vecOfStr;
    int i = 1;

    bool result = getFileContent("dialogue.txt", vecOfStr);

    if (result) {
        int index = getIndex(vecOfStr, key);
        if (index == -1) {
            return false;
        }
        while (vecOfStr[index + i] != "END") {
            std::cout << vecOfStr[index + i] << std::endl;
            i++;
        }
    }
    return true;
}

void TextStream::characterInteract(std::string n) {
  if (n.compare("FINN") == 0)
    getDialogue(n);
  if (n.compare("TOILET MAN") == 0)
    getDialogue(n);
  if (n.compare("MASKED MAN") == 0)
    getDialogue(n);
  if (n.compare("CHLOE") == 0)
    getDialogue(n);
  if (n.compare("GUARD") == 0)
    getDialogue(n);
  if (n.compare("NATALIA") == 0)
    getDialogue(n);
}

void TextStream::locationEnter(std::string l) {
  if (l.compare("GALLERY") == 0)
    getDialogue(l);
  if (l.compare("BATHROOM") == 0)
    getDialogue(l);
  if (l.compare("BACK ROOM") == 0)
    getDialogue(l);
  if (l.compare("OUTSIDE") == 0)
    getDialogue(l);
  if (l.compare("ENTRYWAY") == 0)
    getDialogue(l);
  if (l.compare("CORRIDOR") == 0)
    getDialogue(l);
  if (l.compare("SECRET ROOM") == 0)
    getDialogue(l);
  if (l.compare("SECURITY ROOM") == 0)
    getDialogue(l);
  if (l.compare("ADMIN OFFICE") == 0)
    getDialogue(l);
  if (l.compare("SHOWCASE") == 0)
    getDialogue(l);
  if (l.compare("VENT") == 0)
    getDialogue(l);
}
