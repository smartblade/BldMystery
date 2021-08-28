#ifndef CAMERA_ENTITY_H

#define CAMERA_ENTITY_H

#include <App/camera.h>
#include <Entities/Entity.h>


class B_CameraEntity : public B_Entity
{
public:
    B_CameraEntity(int unknown, const B_Name &name);
    void unknown_004EB1AA(void *);
    B_Camera cam;
    char unknownFields3E0[0xC];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};

#endif /*CAMERA_ENTITY_H*/