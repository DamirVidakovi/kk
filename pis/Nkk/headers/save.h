#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <vector>

#include "headers/structs.h"

typedef struct {
    std::string name;
    std::string path;
    std::string date;
    std::string time;
} Save;

class SaveManager {
    public:
        SaveManager();
        ~SaveManager();

        void loadSaves();
        void saveGame(std::string name, std::string path);
        void deleteSave(std::string name);
        void deleteSave(int index);
        void deleteAllSaves();

        std::vector<Save> getSaves();
        Save getSave(int index);

    private:
        std::vector<Save> saves;
};

#endif // SAVE_H