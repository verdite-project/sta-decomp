typedef struct { char pad[0x40]; float x, y; int x48, x4C; char pad2[0x20]; float v[4]; } Cam;
extern Cam *gGsTextStyle_00201E60;

void GsText_SetScaleVec_0_001E2A48(float *v)
{
    gGsTextStyle_00201E60->x = v[0];
    gGsTextStyle_00201E60->y = v[1];
}
