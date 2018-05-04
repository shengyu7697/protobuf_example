#include "SocketPoseService.h"
#include "TimeUtil.h"

#include <stdio.h>
#include <stdlib.h>

float pos[3] = {0.0f, 0.0f, 0.0f};
float rot[3] = {0.0f, 0.0f, 0.0f};

SocketPoseService sps;

void printInfo()
{
#if defined(USE_PROTOBUF)
    printf("USE_PROTOBUF: true\n");
#else
    printf("USE_PROTOBUF: false\n");
#endif
}

int main(int argc, const char *argv[])
{
    // print info
    printInfo();

    while (1) {
        sps.getPose(pos, rot);
        sleep_ms(100);
    }

    return 0;
}
