#include <Control/Climbing.h>

#include <AnalyticGeometry/Vector.h>
#include <BWorld/BWorld.h>
#include <Entities/BipedEntity.h>
#include <Entities/PersonEntity.h>
#include <enemies/CharType.h>
#include "bld_misc_funcs.h"
#include <math.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00477CC6
*/
#ifndef BLD_NATIVE
int FindClimbingTopPosition(
    const B_Vector &bottomPos, double maxHeight, B_Vector *topFloorPos,
    double step)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00477D6E
*/
#ifndef BLD_NATIVE
int FindLeanPos(
    const B_Vector &startPos, const B_Vector &topFloorPos,
    double leftHandDist, double rightHandDist,
    B_Vector *leftHandPos, B_Vector *rightHandPos)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00478385
*/
#ifndef BLD_NATIVE
int FindLowClimbingTopPos(
    const B_Vector &startPos, const B_Vector &topFloorPos,
    B_Vector *lowClmbTopFloorPos)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00478561
*/
#ifndef BLD_NATIVE
int ClimbingImpulse(B_Entity *entity, unsigned int eventIndex)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00478D62
*/
#ifndef BLD_NATIVE
int LowClimbingImpulse(B_Entity *entity, unsigned int eventIndex)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0047920C
*/
#ifndef BLD_NATIVE
int FindEndPos(
    B_PersonEntity *personEntity, B_BipedAction *action,
    const B_Vector &leftHandPos, const B_Vector &rightHandPos,
    B_Vector *topPersonPos)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004798DC
*/

int TestClimb(B_Entity *entity, unsigned int eventIndex)
{
    B_PersonEntity *personEntity = static_cast<B_PersonEntity*>(entity);
    B_Vector position = personEntity->GetPose().TranslationVector();
    B_Vector direction;
    direction.SetAngle(personEntity->GetAngle());
    B_Vector topFloorPos;
    if (
        !FindClimbingTopPosition(
            position + 1200.0 * direction + 1000.0 * yDirection,
            5000.0, &topFloorPos, 750.0) &&
        !FindClimbingTopPosition(
            position + 1400.0 * direction + 1000.0 * yDirection,
            5000.0, &topFloorPos, 750.0) &&
        !FindClimbingTopPosition(
            position + 1650.0 * direction + 1000.0 * yDirection,
            5000.0, &topFloorPos, 750.0)
    )
        return false;
    double climbH = personEntity->GetFloorHeight(NULL, NULL) - topFloorPos.y;
    B_Vector leftHandPos, rightHandPos, topPersonPos;
    if (
        climbH >= personEntity->per.charType->GetMedGrabDist() &&
        climbH <= personEntity->per.charType->GetMaxGrabDist())
    {
        B_BipedAction *highClmbAction = personEntity->data->actions.Find(
            "clmb_high_1h");
        if (highClmbAction == NULL)
            return false;
        double leanTime = highClmbAction->GetEventTime("Lean_Clmb");
        if (leanTime == -1.0)
        {
            leanTime = 1.0;
        }
        B_BipedData *bipedData = personEntity->data;
        B_Vector leftHandLeanPos = bipedData->GetNodePose(
            highClmbAction,
            leanTime,
            personEntity->GetNodeIndex("L_Hand")).TranslationVector();
        B_Vector rightHandLeanPos = bipedData->GetNodePose(
            highClmbAction,
            leanTime,
            personEntity->GetNodeIndex("R_Hand")).TranslationVector();
        B_Vector leanPos = bipedData->GetPose(
            highClmbAction, leanTime).TranslationVector();
        double leftHandDist = sqrt(
            (leftHandLeanPos.x - leanPos.x) * (leftHandLeanPos.x - leanPos.x) +
            (leftHandLeanPos.y - leanPos.y) * (leftHandLeanPos.y - leanPos.y));
        double rightHandDist = sqrt(
            (rightHandLeanPos.x - leanPos.x) * (rightHandLeanPos.x - leanPos.x) +
            (rightHandLeanPos.y - leanPos.y) * (rightHandLeanPos.y - leanPos.y));
        if (
            FindLeanPos(
                position, topFloorPos, leftHandDist, rightHandDist,
                &leftHandPos, &rightHandPos) &&
            !FindEndPos(personEntity, highClmbAction, leftHandPos, rightHandPos, &topPersonPos))
        {
            B_Vector startPoint;
            B_Vector endPoint;
            B_Vector intersectionPoint;
            startPoint = endPoint = (position + leftHandPos) * 0.5;
            startPoint.y = leftHandPos.y - 350.0;
            endPoint.y = position.y;
            if (
                !B_world.IntersectSegment(
                    startPoint, endPoint, intersectionPoint, 2, true, NULL))
            {
                startPoint = endPoint = (position + rightHandPos) * 0.5;
                startPoint.y = leftHandPos.y - 350.0;
                endPoint.y = position.y;
                if (
                    !B_world.IntersectSegment(
                        startPoint, endPoint, intersectionPoint, 2, true,
                        NULL))
                {
                    B_ClimbingData *climbingData = new B_ClimbingData();
                    climbingData->name = personEntity->name;
                    climbingData->leftPos = leftHandPos;
                    climbingData->rightPos = rightHandPos;
                    climbingData->height = climbH;
                    climbing_data_list.Append(climbingData);
                    if (!stricmp(personEntity->per.animName.String(), "Rlx"))
                    {
                        personEntity->per.LaunchAnimation(
                            "clmb_high_1h", B_world.GetTime());
                        unsigned int eventIndex = gbl_events.GetEventIndex(
                            "Impulse_Clmb");
                        personEntity->eventTable.AddFunc(
                            eventIndex, ClimbingImpulse, "ClimbingImpulse");
                    }
                    else
                    {
                        personEntity->per.LaunchAnimation(
                            "clmb_high_1h", B_world.GetTime());
                        unsigned int eventIndex = gbl_events.GetEventIndex(
                            "Impulse_Clmb");
                        ClimbingImpulse(personEntity, eventIndex);
                    }
                    personEntity->unknown004E5798(topPersonPos);
                    return true;
                }
            }
        }
    }
    else if (
        climbH >= personEntity->per.charType->GetMinGrabDist() &&
        climbH <= personEntity->per.charType->GetMedGrabDist())
    {
        B_BipedAction *medClmbAction = personEntity->data->actions.Find(
            "clmb_medium_1h");
        if (medClmbAction == NULL)
            return false;
        double leanTime = medClmbAction->GetEventTime("Lean_Clmb");
        if (leanTime == -1.0)
        {
            leanTime = 1.0;
        }
        B_BipedData *bipedData = personEntity->data;
        B_Vector leftHandLeanPos = bipedData->GetNodePose(
            medClmbAction,
            leanTime,
            personEntity->GetNodeIndex("L_Hand")).TranslationVector();
        B_Vector rightHandLeanPos = bipedData->GetNodePose(
            medClmbAction,
            leanTime,
            personEntity->GetNodeIndex("R_Hand")).TranslationVector();
        B_Vector leanPos = bipedData->GetPose(
            medClmbAction, leanTime).TranslationVector();
        double leftHandDist = sqrt(
            (leftHandLeanPos.x - leanPos.x) * (leftHandLeanPos.x - leanPos.x) +
            (leftHandLeanPos.y - leanPos.y) * (leftHandLeanPos.y - leanPos.y));
        double rightHandDist = sqrt(
            (rightHandLeanPos.x - leanPos.x) * (rightHandLeanPos.x - leanPos.x) +
            (rightHandLeanPos.y - leanPos.y) * (rightHandLeanPos.y - leanPos.y));
        if (
            FindLeanPos(
                position, topFloorPos, leftHandDist, rightHandDist,
                &leftHandPos, &rightHandPos) &&
            !FindEndPos(
                personEntity, medClmbAction, leftHandPos, rightHandPos,
                &topPersonPos))
        {
            B_ClimbingData *climbingData = new B_ClimbingData();
            climbingData->name = personEntity->name;
            climbingData->leftPos = leftHandPos;
            climbingData->rightPos = rightHandPos;
            climbingData->height = climbH;
            climbing_data_list.Append(climbingData);
            if (!stricmp(personEntity->per.animName.String(), "Rlx"))
            {
                personEntity->per.LaunchAnimation(
                    "clmb_medium_1h", B_world.GetTime());
                unsigned int eventIndex = gbl_events.GetEventIndex(
                    "Impulse_Clmb");
                personEntity->eventTable.AddFunc(
                    eventIndex, ClimbingImpulse, "ClimbingImpulse");
            }
            else
            {
                personEntity->per.LaunchAnimation(
                    "clmb_medium_1h", B_world.GetTime());
                unsigned int eventIndex = gbl_events.GetEventIndex(
                    "Impulse_Clmb");
                ClimbingImpulse(personEntity, eventIndex);
            }
            personEntity->unknown004E5798(topPersonPos);
            return true;
        }
    }
    else if (
        climbH >= personEntity->per.charType->maxStairDist &&
        climbH <= personEntity->per.charType->GetMinGrabDist())
    {
        B_BipedAction *medLowClmbAction = personEntity->data->actions.Find(
            "clmb_medlow_1h");
        if (medLowClmbAction == NULL)
            return false;
        B_BipedData *bipedData = personEntity->data;
        double leanTime = medLowClmbAction->GetEventTime("Lean_Clmb");
        B_Vector footRelPos, lFootRelPos, rFootRelPos, leanRelPos, endRelPos;
        bipedData->GetLeftFootPose(
            medLowClmbAction, leanTime, &footRelPos, &lFootRelPos);
        bipedData->GetRightFootPose(
            medLowClmbAction, leanTime, &footRelPos, &rFootRelPos);
        leanRelPos = bipedData->GetPose(
            medLowClmbAction, leanTime).TranslationVector();
        endRelPos = bipedData->GetPose(
            medLowClmbAction, 1.0f).TranslationVector();
        lFootRelPos = Rotate(lFootRelPos, personEntity->GetPose());
        rFootRelPos = Rotate(rFootRelPos, personEntity->GetPose());
        leanRelPos = Rotate(leanRelPos, personEntity->GetPose());
        endRelPos = Rotate(endRelPos, personEntity->GetPose());
        if (rFootRelPos.y < lFootRelPos.y)
        {
            footRelPos = rFootRelPos;
        }
        else
        {
            footRelPos = lFootRelPos;
        }
        leanRelPos -= footRelPos;
        endRelPos -= footRelPos;
        B_Vector lowClmbTopFloorPos;
        if (!FindLowClimbingTopPos(position, topFloorPos, &lowClmbTopFloorPos))
            return false;
        topFloorPos = lowClmbTopFloorPos;
        climbH = personEntity->GetFloorHeight(NULL, NULL) - topFloorPos.y;
        if (
            climbH > personEntity->per.charType->maxStairDist &&
            climbH < personEntity->per.charType->GetMinGrabDist() &&
            !personEntity->IsIncorrectPosition(topFloorPos + endRelPos))
        {
            B_ClimbingData *climbingData = new B_ClimbingData();
            climbingData->name = personEntity->name;
            climbingData->rightPos = topFloorPos + leanRelPos;
            climbingData->leftPos = climbingData->rightPos;
            climbingData->height = climbH;
            climbing_data_list.Append(climbingData);
            if (!stricmp(personEntity->per.animName.String(), "Rlx"))
            {
                personEntity->per.LaunchAnimation(
                    "clmb_medlow_1h", B_world.GetTime());
                unsigned int eventIndex = gbl_events.GetEventIndex(
                    "Impulse_Clmb");
                personEntity->eventTable.AddFunc(
                    eventIndex, LowClimbingImpulse, "LowClimbingImpulse");
            }
            else
            {
                personEntity->per.LaunchAnimation(
                    "clmb_medlow_1h", B_world.GetTime());
                unsigned int eventIndex = gbl_events.GetEventIndex(
                    "Impulse_Clmb");
                LowClimbingImpulse(personEntity, eventIndex);
            }
            return true;
        }
    }
    return false;
}
