#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <fstream>
#include <string>
#include <KolibriLib.hpp>
#include "globals.hpp"

const std::string ConfigurationFileName = "config.conf";

int FAILED_LOAD_CONFIGURATION()
{
    KolibriLib::childWindow::ErrorWindow("He удалось открыть файл конфигурации");

    int extCode = 1;

    if(KolibriLib::filesystem::Exist("/sys/etc"))
    {
        KolibriLib::filesystem::mkdir("/sys/etc");
    }

    if (KolibriLib::filesystem::Exist(globals::ProgramConfPath))
    {
        KolibriLib::filesystem::mkdir(globals::ProgramConfPath);
    }

    std::string ConfigPath = globals::ProgramConfPath + ConfigurationFileName;

    std::ofstream config(ConfigPath.c_str());

    if(config.is_open())
    {
        KolibriLib::point size = globals::window.GetSize();
        config << "width" << size.x;
        config << "height" << size.y;
    }
    else
    {
        KolibriLib::childWindow::ErrorWindow("He удалось создать файл конфигурации");
        extCode = 2;
    }

    return extCode;
}

/// @brief Загрузить конфигурацию
/// @return 
int LoadConfiguration()
{
    std::string path = globals::ProgramConfPath + ConfigurationFileName;

    std::ifstream config(path.c_str());

    std::string name;
    int num;

    int extCode = false;

    if(config.is_open())
    {
        extCode = false;
        KolibriLib::point size;
        while(true)
        {
            config >> name >> num;


            if(name == "width")
            {
                size.x = num;
            }
            else if(name == "height")
            {
                size.y = num;
            }
            else
            {
                extCode = FAILED_LOAD_CONFIGURATION();
            }

        }
        globals::window.SetSize(size);
    }
    else
    {
        extCode = FAILED_LOAD_CONFIGURATION();
    }
    
    config.close();
    return extCode;

}


#endif // __CONFIGURATION_H__