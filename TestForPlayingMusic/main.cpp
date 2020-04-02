#include <windows.h>
#include <mmsystem.h>
#include <string>
using namespace std;

int main()
{
    string name = "Blank_space.wav";
    PlaySound(TEXT(name), NULL, SND_SYNC);
    return 0;
}
