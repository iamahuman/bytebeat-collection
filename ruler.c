#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

#define step(freq, n) ((freq) * pow(2, (n) / 12.0))
#define note(n)       step(440, n)
#define MIDDLE_C      note(-9)

int count_zeros(unsigned int n)
{
    int count = 0;
    for (; (n & 1) == 0; n >>= 1)
        count++;
    return count;
}

int minor_note(int note)
{
    int octave = note / 7;
    int scale[] = {0, 2, 3, 5, 7, 8, 10};

    note %= 7;
    if (note < 0) {
        note += 7;
        octave--;
    }

    return scale[note] + octave*12;
}

int main(void) {
    double t = 0.0;
    double freq = MIDDLE_C * 2;
    double step = PI * 2 / 8192;
    int n = 0;
    int i = 0;

    for (i = 1;; t += step, i++) {
        if (i == 1024) {
            i = 0;
            n++;
            freq = step(MIDDLE_C, minor_note(count_zeros(n)));
        }

        putchar(sin(t * freq) * 50.0 + 128.0);
    }

    return 0;
}
