#include <Math/BLights.h>

#include <BBLibc.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004943A0
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_LightSource@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_LightSource &light)
{
    file >> light.color >> light.intensity >> light.precision;
    float max_intensity = max(
        light.color.r,
        max(light.color.g, light.color.b));
    light.color = light.color * (255.0 / max_intensity);
    return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004947F4
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_DirectedLightSource@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_DirectedLightSource &light)
{
    file
        >> static_cast<B_LightSource &>(light)
        >> light.plane
        >> light.fUnknown;
    return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00494866
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_AmbientLight@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_AmbientLight &ambient)
{
    file >> static_cast<B_DirectedLightSource &>(ambient);
    return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00494BB8
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_FlatLight@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_FlatLight &flat)
{
    file >> static_cast<B_DirectedLightSource &>(flat) >> flat.direction;
    return file;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
