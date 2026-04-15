//
// Created by gorod on 15.04.2026.
//

#ifndef CMAKESFMLPROJECT_DIRECTORIESVALIDATOR_H
#define CMAKESFMLPROJECT_DIRECTORIESVALIDATOR_H

#include <filesystem>

#include "Logger.h"

class DirectoriesValidator
{
public:
    DirectoriesValidator()
    {

    }
    ~DirectoriesValidator()
    {

    }

    bool validate()
    {
        std::string path = "data";
        if (std::filesystem::is_directory(path))
        {
            log("dir exists");
            return true;
        }
        else
        {
            log("Dir doesn't exists");
            return false;
        }
    }

private:
    void log(std::string message)
    {
        Logger::custom("VALIDATION: ", message);
    }
};


#endif //CMAKESFMLPROJECT_DIRECTORIESVALIDATOR_H