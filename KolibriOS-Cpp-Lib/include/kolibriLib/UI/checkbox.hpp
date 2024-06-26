#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__

#include <sys/ksys.h>

#include <string>

#include <kolibriLib/types.hpp>
#include <kolibriLib/UI/UI.hpp>
#include <kolibriLib/UI/button.hpp>
#include <kolibriLib/graphic/graphic.hpp>
#include <kolibriLib/color.hpp>

namespace KolibriLib
{
    namespace UI
    {
        /// @brief Класс для работы с чекбоксами
        /// @note Это просто чекбокс, ему можно задать различные стили
        class CheckBox : public buttons::Button
        {
        public:
            const std::string ClassName = "CheckBox";

            /// @brief Стиль Чекбокса
            typedef enum
            {
                /// @brief По вид умолчанию, квадрат
                Default,
                /// @brief В виде круга
                Circle,
                /// @brief Квадрат с со сглаженными углами
                /// @warning Не реализованно (пока что)
                Smoth,
            } style;

            CheckBox(const UDim &coord = point(0), const UDim &size = DefaultSize, const style &Style = style::Default, const Colors::Color &CheckBoxBorderColor = OS::GetSystemColors().gui_frame, const Colors::Color &BackgroundColor = OS::GetSystemColors().win_body, const unsigned &Margin = DefaultMargin);

            /// @brief Отрисовать Checkbox
            void Render();

            /// @brief Изменить стиль
            /// @param s 
            void SetStyle(style s);

            /// @brief Обработчик
            bool Handler();

            private:
                style _style;
                bool _status;
        };
    } // namespace UI
    
} // namespace KolibriLib


#endif // __CHECKBOX_H__