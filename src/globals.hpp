#ifndef GLOBALS_H
#define GLOBALS_H


#include <KolibriLib.hpp>
#include <string>

/// @brief Глобальные переменные и кнстанты которые должны быть доступных везде
namespace globals
{

    //Титул
    std::string TITLE = "Kalc";

    //Основное окно
    KolibriLib::window::Window window(globals::TITLE, {800, 480});
}


#endif
