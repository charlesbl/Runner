#include "score.h"

void createEmptyFile()
{
    std::ifstream f{SCOREFILE, std::ios::out | std::ios::app};
    f.close();
}

void addScore(int score)
{
    std::set<int> bestScores = getScores();

    if(bestScores.size() >= 8){
        if((*bestScores.begin()) < score){
            bestScores.erase(*bestScores.begin());
            bestScores.insert(score);
            std::ofstream f{SCOREFILE, std::ios::out};
            if(f)
            {
                for(int i : bestScores)
                    f << i << std::endl;
            }
        }
    }else{
        std::ofstream f{"score", std::ios::out | std::ios::app};
        if(f)
        {
            f << score << std::endl;
        }
    }
}

std::string getStringScores()
{
    std::set<int> bestScores = getScores();

    if(bestScores.size() == 0)
        return "No High Score";

    std::string result = "     High Score\n\n";
    int cpt = 1;
    for(auto it = bestScores.rbegin(); it != bestScores.rend(); it++){
        result += std::to_string(cpt++) + ": " + std::to_string(*it) + "\n";
    }
    return result;
}


std::set<int> getScores()
{
    std::set<int> bestScores;

    std::ifstream fichier{SCOREFILE, std::ios::in};
    if(fichier){
        std::string ligne;
        while(std::getline(fichier, ligne))
        {
            if(ligne.size() > 0)
                bestScores.insert(std::atoi(ligne.c_str()));
        }
    }else{
        createEmptyFile();
    }
    fichier.close();
    return bestScores;
}
