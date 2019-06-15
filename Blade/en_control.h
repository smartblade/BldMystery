#ifndef EN_CONTROL_H

#define EN_CONTROL_H

class EnControl
{
public:
    int StartRecordingDemo();
    int EndRecordingDemo(const char *name);
    int PlayDemo(const char *name);
};

#endif /* EN_CONTROL_H */
