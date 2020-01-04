#ifndef EN_CONTROL_H

#define EN_CONTROL_H

class EnControl
{
public:
    int SetTurnSpeed(const char *race_name, double new_speed);
    int StartRecordingDemo();
    int EndRecordingDemo(const char *name);
    int PlayDemo(const char *name);
};

#endif /* EN_CONTROL_H */
