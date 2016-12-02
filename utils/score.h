#ifndef SCORE_H
#define SCORE_H

#include "set"
#include "string"
#include "fstream"

const std::string SCOREFILE = "score";

void createEmptyFile();
void addScore(int score);
std::string getStringScores();
std::set<int> getScores();

#endif // SCORE_H
