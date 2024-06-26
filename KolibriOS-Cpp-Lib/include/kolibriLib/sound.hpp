#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <sys/ksys.h>
#include <sound.h>

namespace KolibriLib
{
    namespace Sound
    {
        typedef int Error;

        typedef enum
        {
            PCM__2_16_48 = PCM_2_16_48,
            PCM__1_16_48 = PCM_1_16_48,
            PCM__2_16_44 = PCM_2_16_44,
            PCM__1_16_44 = PCM_1_16_44,
            PCM__2_16_32 = PCM_2_16_32,
            PCM__1_16_32 = PCM_1_16_32,
            PCM__2_16_24 = PCM_2_16_24,
            PCM__1_16_24 = PCM_1_16_24

        } SoundFormat;

        Error initSound()
        {
            Error err;
            int version = -1;

            if ((err = InitSound(&version)) != 0)
            {
                goto epic_fail;
            };

            if ((SOUND_VERSION > (version & 0xFFFF)) ||
                (SOUND_VERSION < (version >> 16)))
            {
                goto epic_fail;
            }

            epic_fail:
            return err;
        }

        Error PlaySound(void *buffer, int buffer_size, SoundFormat snd_format)
        {
            SNDBUF hBuff;

            Error err;

            if ((err = CreateBuffer(snd_format | PCM_OUT, 0, &hBuff)) != 0)
            {
                goto epic_fail;
            };
            WaveOut(hBuff, buffer, buffer_size);

            epic_fail:
            return err;
        }
    }
} // namespace KolibriLib

#endif // __SOUND_HPP__