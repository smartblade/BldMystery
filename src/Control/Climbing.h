#ifndef CLIMBING_H

#define CLIMBING_H

#include <BBLibc/NamedObj.h>
#include <AnalyticGeometry/Vector.h>


class B_BipedAction;
class B_Entity;
class B_PersonEntity;

class B_ClimbingData : public B_NamedObj
{
public:
    B_Vector leftPos;
    B_Vector rightPos;
    double height;
};

#ifdef __cplusplus
extern "C" {
#endif

int FindClimbingTopPosition(
    const B_Vector &bottomPos, double maxHeight, B_Vector *topFloorPos,
    double step);
int FindLeanPos(
    const B_Vector &startPos, const B_Vector &topFloorPos,
    double leftHandDist, double rightHandDist,
    B_Vector *leftHandPos, B_Vector *rightHandPos);
int FindLowClimbingTopPos(
    const B_Vector &startPos, const B_Vector &topFloorPos,
    B_Vector *lowClmbTopFloorPos);
int ClimbingImpulse(B_Entity *entity, unsigned int eventIndex);
int LowClimbingImpulse(B_Entity *entity, unsigned int eventIndex);
int FindEndPos(
    B_PersonEntity *personEntity, B_BipedAction *action,
    const B_Vector &leftHandPos, const B_Vector &rightHandPos,
    B_Vector *topPersonPos);
int TestClimb(B_Entity *entity, unsigned int eventIndex);

/*
* Module:                 Blade.exe
* Data address:           0x007072C8
*/
extern B_PtrArray<B_ClimbingData> climbing_data_list;

#ifdef __cplusplus
}
#endif

#endif /* CLIMBING_H */
