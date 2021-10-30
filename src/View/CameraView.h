#pragma once

class B_CameraView
{
public:
    B_CameraView(
        float a = 0.0f,
        float b = 0.0f,
        float c = 0.0f,
        float d = 0.0f,
        float e = 0.0f,
        float f = 0.0f
    );
    void UpdateViewPyramid();

    float xCentre;
    float yCentre;
    float width;
    float height;
    float unknown010;
    float z;
    char viewPyramid[772];
};
