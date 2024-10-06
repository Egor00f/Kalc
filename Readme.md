Kalc
===

Kalc - это калькулятор для KolibriOS

Функции:
+ Обычный калькулятор
+ Построение графиков

Просто калькулятор ничего необычного

Сборка
---

Зависимости что нужно установить для сборки:
+ cmake
+ kolibrios c++ toolchain


Склонируйте репозиторий:
```
git clone https://github.com/Egor00f/Kalc.git
cd Kalc
git submodule update --init
```

Ну тут всё просто:
```
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../KolibriOS-Cpp-Lib/cmake/toolchain.cmake
make
```
