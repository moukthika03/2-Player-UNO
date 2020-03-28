#include <windows.h>
#include <mmsystem.h>
using namespace std;

int main()
{
    PlaySound(TEXT("Blank_space.wav"), NULL, SND_SYNC);

    return 0;
}
