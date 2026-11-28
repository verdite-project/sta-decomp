typedef struct { char pad[0x40]; float x, y; int x48, x4C; char pad2[0x20]; float v[4]; } Cam;
extern Cam *gGsTextStyle_00201E60;

void GsText_SetColor_0_001E2B60(float a, float b, float c, float d)
{
    gGsTextStyle_00201E60->v[0] = a;
    gGsTextStyle_00201E60->v[1] = c;
    gGsTextStyle_00201E60->v[2] = b;
    gGsTextStyle_00201E60->v[3] = d;
}
